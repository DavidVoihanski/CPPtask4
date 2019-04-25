#pragma once
#include <string>
#include "calculate.hpp"

namespace bullpgia{
    class Guesser{
        protected:
            int length;
        public:
            virtual std::string guess() = 0;
            virtual void startNewGame(uint lenght){};
            virtual void learn(int reply){};
    };
}