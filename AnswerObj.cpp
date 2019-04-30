#include "AnswerObj.hpp"
using namespace bullpgia;

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
    return (os << bull << "," << pgia << std::endl);
}