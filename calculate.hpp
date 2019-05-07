#pragma once
#include <string>
#include "AnswerObj.hpp"
using namespace bullpgia;

namespace bullpgia{
    AnswerObj calculateBullAndPgia(std::string choice, std::string guess);
    uint calcBull(std::string& choice, std::string& guess);
    uint calcPgia(std::string choice, std::string guess);
}
