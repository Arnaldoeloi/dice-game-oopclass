#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Die.h"
#include<string>
#include<iostream>

class Player{
    private:
        std::string name_;
        int score_;
    public:
        Player();
        Player(std::string name);
        ~Player();
};

#endif