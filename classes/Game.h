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

        int score_goal_;


    public:
        Game(int score_goal);
        ~Game(){};

        void printMenu();

        void addNewPlayer();
        void addNewDie();
        
        void run();

        void inputAnswer();

        void startGame();

        int Game::playersPlaying();
};

#endif