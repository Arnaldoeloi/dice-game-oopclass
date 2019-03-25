#ifndef _GAME_H_
#define _GAME_H_

#include <list> 
#include <iterator> 
#include <iostream>

#include "Player.h"
#include "Die.h"

class Game{
    private:
        std::list <Player*> players_;
        std::list <Die*> dice_;

    public:
        Game();
        ~Game();

        void run();
        void printMenu();
        void addNewPlayer();
        
};

#endif