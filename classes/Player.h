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
        //Player constructor
        Player();

        //Player constructor with name
        Player(std::string name);
        ~Player();

        //Set player name
        void setName(std::string name);
        std::string getName();

        //Get player score
        int getScore();

        //Roll a die given by Game
        void rollTheDie(Die& die);

        //Add n points into score
        void addToScore(int n); 

        //return False if won`t play at the current turn or True if will
        bool willPlayNow(); 
};

#endif