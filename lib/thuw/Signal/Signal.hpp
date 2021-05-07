#pragma once

#include <algorithm>
#include <array>
#include <functional>
#include <initializer_list>
#include <list>
#include <memory>
#include <tuple>

namespace thuw {
    template<typename ...Args>
    class Signal;

    template<typename ...Args>
    class Connection;

    template<typename ...Args>
    using Slot = std::function<void(Args...)>;
}

template<typename ...Args>
class thuw::Signal {
public:
    std::list<Slot<Args...>> slotList;

    Signal() = default;
    
    [[nodiscard]] auto connect(const Slot<Args...>&& slot)-> thuw::Connection<Args...> {
        auto&& itr = this->slotList.insert(this->slotList.end(), slot);
        return thuw::Connection<Args...>(this->slotList, itr);
    }

    void operator()(Args& ...args) const {
        for(auto& slot : this->slotList) {
            slot(std::forward<Args>(args)...);
        }
    }

    void operator()(Args&& ...args) const {
        for(auto& slot : this->slotList) {
            slot(std::forward<Args>(args)...);
        }
    }
};

template<typename ...Args>
class thuw::Connection {
private:
    using Slot = Slot<Args...>;
    std::list<Slot>* slotList = nullptr;// TODO: shared_ptr

    using Iterator = typename std::list<Slot>::iterator;
    Iterator iterator;

public:
    Connection() = default;

    Connection(Connection<Args...>& connection)
     : iterator(connection.iterator)
    {
        std::swap(this->slotList, connection.slotList);
    }

    Connection(Connection<Args...>&& connection)
     : iterator(connection.iterator)
    {
        std::swap(this->slotList, connection.slotList);
    }

    Connection(std::list<Slot>& slots, Iterator iterator)
     : slotList(&slots)
     , iterator(iterator){}

    Connection& operator=(Connection<Args...>&& connection) {
        this->iterator = connection.iterator;
        std::swap(this->slotList, connection.slotList);

        return *this;
    }

    ~Connection() {
        this->disconnect();
    }

    void disconnect() {
        if(this->slotList == nullptr)
            return;

        this->slotList->erase(this->iterator);
    }
};

// prototype
namespace StaticSignal {
    template<typename ...Args>
    struct Connect {
        std::array<std::function<void(Args...)>, sizeof...(Args)> slot;

        constexpr Connect(std::initializer_list<std::function<void(Args...)>> f) : slot(f) {

        }
    };
};