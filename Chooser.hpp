#pragma once
#include <string>
#include "calculate.hpp"

namespace bullpgia{
    class Chooser{
        public:
            virtual std::string choose(uint length) = 0;  
    };
}