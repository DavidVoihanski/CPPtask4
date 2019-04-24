#pragma once
#include <string>

namespace bullpgia{
    class Chooser{
        public:
            Chooser(){
                
            }
            virtual std::string choose(uint length){}
            
    };
}