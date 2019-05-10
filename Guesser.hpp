#pragma once
#include <string>
#include "calculate.hpp"
#include "AnswerObj.hpp"
namespace bullpgia{
    class Guesser{
        public:
            uint length;
            virtual std::string guess() = 0;
            virtual void startNewGame(const uint lenght){
                this->length = lenght;
            };
            virtual void learn(AnswerObj& reply){};
    };
}