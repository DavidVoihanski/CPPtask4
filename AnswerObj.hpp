#pragma once
#include <iostream>

namespace bullpgia{
    class AnswerObj{
        private:
            uint bull;
            uint pgia;
        public:
            AnswerObj(uint bull, uint pgia);
            void setBullAndPgia(uint bull, uint pgia);
            virtual uint getBull() const;
            virtual uint getPgia() const;
            friend std::ostream &operator<<(std::ostream &os, AnswerObj const &obj);
    };
}