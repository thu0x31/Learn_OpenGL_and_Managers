#pragma once

#include <algorithm>
#include <array>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <list>
#include <memory>
#include <ostream>
#include <type_traits>
#include <utility>
#include <vector>
#include <concepts>

namespace thuw {
    template<typename ReturnType, typename ...Args>
    class Signal;

    template<typename ReturnType, typename ...Args>
    class Connection;
}

template<typename ReturnType, typename ...Args>
class thuw::Signal<ReturnType(Args...)> {
public:
    using Slot = std::function<ReturnType(Args...)>;
    std::list<Slot> slotList;

    Signal() = default;
    
    [[nodiscard]] thuw::Connection<ReturnType(Args...)> connect(const Slot&& slot) {
        auto&& itr = this->slotList.insert(this->slotList.end(), slot);
        return thuw::Connection<ReturnType(Args...)>(this->slotList, itr);
    }

    void operator()(Args& ...args) const
    requires std::same_as<ReturnType, void>
    {
        for(auto& slot : this->slotList) {
            slot(std::forward<Args>(args)...);
        }
    }

    void operator()(Args&& ...args) const 
    requires std::same_as<ReturnType, void>
    {
        for(auto& slot : this->slotList) {
            slot(std::forward<Args>(args)...);
        }
    }

    std::vector<ReturnType> operator()(Args& ...args) const 
    {
        std::vector<ReturnType> conteinrer(this->slotList.size());
        
        auto&& itr = conteinrer.begin();

        for (const auto& slot : this->slotList) {
            *itr = slot(std::forward<Args>(args)...);
            ++itr;
        }
        
        return conteinrer;
    }

    std::vector<ReturnType> operator()(Args&& ...args) const 
    {
        std::vector<ReturnType> conteinrer(this->slotList.size());
        
        auto&& itr = conteinrer.begin();

        for (const auto& slot : this->slotList) {
            *itr = slot(std::forward<Args>(args)...);
            ++itr;
        }
        
        return conteinrer;
    }

    template<template<class, class Allocator=std::allocator<ReturnType>> class Conteiner>
    Conteiner<ReturnType> execute(Args&& ... args) const {
        Conteiner<ReturnType> conteinrer(this->slotList.size());
        
        auto&& itr = conteinrer.begin();

        for (const auto& slot : this->slotList) {
            *itr = slot(std::forward<Args>(args)...);
            ++itr;
        }
        
        return conteinrer;
    }

    template<template<class, class Allocator=std::allocator<ReturnType>> class Conteiner>
    Conteiner<ReturnType> execute(Args& ... args) const {
        Conteiner<ReturnType> conteinrer(this->slotList.size());
        
        auto&& itr = conteinrer.begin();

        for (const auto& slot : this->slotList) {
            *itr = slot(std::forward<Args>(args)...);
            ++itr;
        }
        
        return conteinrer;
    }

    //TODO: map
};

template<typename ReturnType, typename ...Args>
class thuw::Connection<ReturnType(Args...)> {
private:
    using Slot = std::function<ReturnType(Args...)>;
    std::list<Slot>* slotList = nullptr;

    using Iterator = typename std::list<Slot>::iterator;
    Iterator iterator;

public:
    Connection() = default;

    Connection(std::list<Slot>& slots, Iterator iterator)
     : slotList(&slots)
     , iterator(iterator){}

    Connection(Connection<ReturnType(Args...)>& connection)
     : iterator(connection.iterator)
    {
        std::swap(this->slotList, connection.slotList);
    }

    Connection(Connection<ReturnType(Args...)>&& connection)
     : iterator(connection.iterator)
    {
        std::swap(this->slotList, connection.slotList);
    }

    auto& operator=(Connection<ReturnType(Args...)>&& connection) {
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

};