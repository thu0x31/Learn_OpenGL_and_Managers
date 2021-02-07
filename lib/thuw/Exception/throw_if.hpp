#pragma once
#include <stdexcept>
#include <string>

namespace thuw {
    inline void throw_if(const bool& condition, const std::string& message) noexcept(false) {
        if(condition){
            throw std::runtime_error(message);
        }
    }

    inline void throw_if(const bool& condition, const std::exception exception) noexcept(false) {
        if(condition){
            throw exception;
        }
    }
}