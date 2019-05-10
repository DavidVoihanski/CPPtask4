#include "SmartGuesser.hpp"
using namespace bullpgia;

SmartGuesser::SmartGuesser(){
    this->length = -1;
}
SmartGuesser::~SmartGuesser(){
    this->allCharMessy.clear();
    this->allComs.clear();
}
std::string SmartGuesser::guess() {
    std::string guess = "";
    if(numOfGuesses < 10 && !this->allDigitsFound){
        this->lastGuess = guess = this->nextSimpleGuess();
        this->numOfGuesses++;
        return guess;
    }
    if(firstGuessingRound){
        guess = this->assembleFirstGuess();
        this->lastGuess = guess;
        this->firstGuessingRound = false;
        char str[this->length+1];
        for(int i = 0; i < this->length; i++)
            str[i] = guess[i];
        str[this->length] = '\0';
        this->permute(str, 0, this->length - 1);
        return guess;
    }
    else{
        guess = this->lastGuess = this->allComs[0];
        this->numOfGuesses++;
        return guess;
    }
}

void SmartGuesser::startNewGame(uint length) {
    this->length = length;
    this->lastGuess = "";
    this->numOfGuesses = 0;
    this->totalCharsFound = 0;
    this->allCharMessy.clear();
    this->allComs.clear();
    this->allDigitsFound = false;
    this->firstGuessingRound = true;
}

void SmartGuesser::learn(AnswerObj &ans) {
    int pgia = ans.getPgia();
    int bull = ans.getBull();
    if(!allDigitsFound){ //here  we find what chars appear and how many times
        uint total = bull + pgia;
        this->totalCharsFound = this->totalCharsFound + total;
        for(int i = 0; i < total; i++){ //insert found char the number of times it appears
            this->allCharMessy.push_back(this->lastGuess[0]);
        }
        if(this->totalCharsFound == this->length) //found all of the chars
            this->allDigitsFound = true;
    }//if
    else{   //"allComs" holds every possible combination of the char we found earlier, if one of them is the same as the last one we guessed, delete it
        uint len = this->allComs.size();
        for(uint i = 0; i < len; i++){
            if(this->allComs[i] == this->lastGuess)
                this->allComs.erase(this->allComs.begin() + i);
        }
    }//else
}

//Gueesses "0000...."-"9999...." untill we find every char and the number of times it appears
std::string SmartGuesser::nextSimpleGuess(){ 
    std::string guess = "";
    std::string nextChar = std::to_string(this->numOfGuesses);
    for(int i =0; i < this->length; i++){
        guess.append(nextChar);
    }
    return guess;
}

//Takes the chars we found and assembles our first guess with said chars
std::string SmartGuesser::assembleFirstGuess(){
    std::string guess = "";
    for(int i =0; i < this->length; i++){
        guess+=this->allCharMessy[i];
    }
    return guess;
}

void SmartGuesser::swap(char *x, char *y)  
{  
    char temp;  
    temp = *x;  
    *x = *y;  
    *y = temp;  
}  

/* Function to find permutations of string  
This function takes three parameters:  
1. String  
2. Starting index of the string  
3. Ending index of the string. 
adds each permutation to allCombs*/
void SmartGuesser::permute(char *a, int l, int r)  
{  
    int i;  
    if (l == r) {
        std::string b = a;
        this->allComs.push_back(b);
    }    
    else
    {  
        for (i = l; i <= r; i++)  
        {  
            swap((a+l), (a+i));  
            permute(a, l+1, r);  
            swap((a+l), (a+i)); //backtrack  
        }  
    }  
}  
  