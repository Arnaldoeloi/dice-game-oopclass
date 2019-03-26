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

        const int MIN_SCORE_GOAL=10;

    public:
        Game();
        Game(int score_goal);
        ~Game(){};

        void printMenu();

        void addNewPlayer();
        void addNewDie();
        
        void run();

        void inputAnswer();

        void startGame();

        int playersPlaying();

        void announceWinnerAfterEveryoneLose();
};

#endif