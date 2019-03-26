#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Die.h"
#include <string>
#include <iostream>

class Player{
    private:
        std::string name_;
        int score_;
    public:
        Player();
        Player(std::string name);
        ~Player();

        void setName(std::string name);
        std::string getName();

        int getScore();

        void rollTheDie(Die& die);
        void addToScore(int n); 

        //return False if won`t play at the current turn or True if will
        bool willPlayNow(); 
};

#endif