#pragma once
#include <iostream>

namespace bullpgia{
    class AnswerObj{
        private:
            uint bull;
            uint pgia;
        public:
            AnswerObj();
            AnswerObj(uint bull, uint pgia);
            virtual void setBull(uint bull);
            virtual void setPgia(uint pgia);
            virtual void setBullAndPgia(uint bull, uint pgia);
            virtual uint getBull() const;
            virtual uint getPgia() const;
            friend std::ostream &operator<<(std::ostream &os, AnswerObj const &obj);
    };
}