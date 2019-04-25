#pragma once
#include <string>
#include "calculate.hpp"

namespace bullpgia{
    class Chooser{
        public:
            Chooser(){
                
            }
            virtual std::string choose(uint length){}
            
    };
}