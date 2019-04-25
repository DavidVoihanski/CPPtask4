#pragma once
#include "Guesser.hpp"
namespace bullpgia{
    class SmartGuesser: public bullpgia::Guesser{
        public:
            std::string guess() override;
    };
}