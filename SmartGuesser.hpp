#pragma once
#include "Guesser.hpp"
#include <bits/stdc++.h> 

namespace bullpgia{
    class SmartGuesser: public bullpgia::Guesser{
        private:
            std::string lastGuess;
            uint numOfGuesses;
            uint totalCharsFound;
            bool allDigitsFound;
            bool firstGuessingRound;
            std::vector<char> allCharMessy;
            std::vector<std::string>allComs;
            virtual std::string nextSimpleGuess();
            virtual std::string assembleFirstGuess();
            void permute(char *a, int l, int r);
            void swap(char *x, char *y);
        public:
            std::string guess() override;
            void startNewGame(uint length) override;
            void learn(AnswerObj &ans) override;
            SmartGuesser();
            ~SmartGuesser();
    };
}