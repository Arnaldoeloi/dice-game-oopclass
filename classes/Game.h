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
        //Game construct 
        Game();

        //Game construct with decided score_goal 
        Game(int score_goal);
        ~Game(){};

        //Print game menu 
        void printMenu();

        //Add new player menu, to create players inside class
        void addNewPlayer();

        //Add new die menu, to create dice inside class
        void addNewDie();
        
        //Run game, calling methods in the correct order
        void run();

        //Interprets the answer from menu
        void inputAnswer();

        //Starts the game if every variable is set
        void startGame();

        //Returns the current number of player playing, sice some will stop playing mid game if they lost
        int playersPlaying();

        //AnnounceWinner if there`s no one playing
        void announceWinnerAfterEveryoneLose();
};

#endif