#pragma once
#include <string>
#include "calculate.hpp"

namespace bullpgia{
    class Guesser{
        private:
           
        public:
            int length;
            Guesser(){

            }
            virtual std::string guess(){}
            virtual void startNewGame(uint lenght){}
            virtual void learn(int reply){}
    };
}