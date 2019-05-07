#include "calculate.hpp"

AnswerObj bullpgia::calculateBullAndPgia(std::string choice, std::string guess){
    uint length = choice.length();
    uint bull = 0;
    std::string choiceCopy = "";
    std::string guessCopy = "";
    choiceCopy.append(choice);
    guessCopy.append(guess);
    for(uint i = 0; i < length; i++){
        if(choice[i] == guess[i]){
            choiceCopy.erase(choiceCopy.begin()+i - bull);
            guessCopy.erase(guessCopy.begin()+i-bull);
            bull++;
        }
    }
    uint pgia = calcPgia(choiceCopy, guessCopy);
    AnswerObj answer(bull, pgia);
    return answer;
}   


uint bullpgia::calcPgia(std::string choice, std::string guess){
    uint length = choice.length();
    // std::string choiceCopy = "";
    // std::string guessCopy = "";
    // choiceCopy.append(choice);
    // guessCopy.append(guess);
    uint ans = 0;
    for(int i = 0; i < length; i++){
        for(int j =0; j < length; j++){
            if(choice[i] == guess[j]){
                choice[i] = 'b';
                guess[j] = 'a';
                ans++;
                break;
            }
        }
    }
    return ans;
}

AnswerObj::AnswerObj(){
    this->setBull(-1);
    this->setPgia(-1);
}

AnswerObj::AnswerObj(uint bull, uint pgia){
    this->setBullAndPgia(bull, pgia);
}

void AnswerObj::setBull(uint bull){
    this->bull = bull;
}

void AnswerObj::setPgia(uint pgia){
    this->pgia = pgia;
}

void AnswerObj::setBullAndPgia(uint bull, uint pgia){
    this->bull = bull;
    this->pgia = pgia;
}

uint AnswerObj::getBull() const{
    return this->bull;
}

uint AnswerObj::getPgia() const{
    return this->pgia;
}

std::ostream& bullpgia::operator<<(std::ostream &os, AnswerObj const &obj){
    uint bull = obj.getBull();
    uint pgia = obj.getPgia();
    return (os << bull << "," << pgia);
}