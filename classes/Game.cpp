#include "Game.h"

Game::Game(){
    score_goal_ = -1;
}

Game::Game(int score_goal){
    score_goal_ = score_goal;
}

void Game::addNewPlayer(){
    std::cout<<"What is the name of this player? Press enter to confirm."<<std::endl;
    std::string name;
     std::cin>>name;

    
    Player* p = new Player(name);
    players_.push_front(p); 
}

void Game::addNewDie(){
    std::cout<<"What is the number of sides of this die?"<<std::endl;
    std::string number;
    std::cin>>number;

    int n;
    
    try {
        n = stoi(number);
    } catch( const std::invalid_argument& e1 ) {
        std::cout<<"Invalid number, did you type an integer greater than 4?"<<std::endl;
        return;
    }

    Die* die = new Die(n);
    dice_.push_front(die); 

}

void Game::inputAnswer(){
    std::string answer;
    std::cin>>answer;
    int n;
    
    try{
        n = stoi(answer);
    }catch( const std::invalid_argument& e1 ){
        std::cout<<"Invalid number, did you type an integer equivalent to an option?"<<std::endl;
        printMenu();
        return;
    }
    if(n==0){
        std::string new_score;
        std::cout<<"Type the new score goal:"<<std::endl;
        std::cin>>new_score; 
        
        try{
            score_goal_ = stoi(new_score);
        }catch( const std::invalid_argument& e1 ){
            std::cout<<"Invalid number, did you type an integer equivalent to an option?"<<std::endl;
            printMenu();
            return;
        }
        printMenu();
    }
    else if(n==1){
        if(players_.size() < 2){
            std::cout<<"You need at least 2 players to start the game! Press #2 to add a new one."<<std::endl;
            Game::printMenu();
            return;
        }
        if(dice_.size() < 1){
            std::cout<<"You need at least 1 die to start the game! Press #3 to add a new one."<<std::endl<<std::endl;
            Game::printMenu();
            return;
        }
        if(score_goal_ < MIN_SCORE_GOAL){
            std::cout<<"You need as score goal at least "<<MIN_SCORE_GOAL<<"."<<std::endl;
            Game::printMenu();
            return;
        }
        if(dice_.size() >= 1 && players_.size() >= 2){
            Game::startGame();
        }
    }else if(n==2){
        addNewPlayer();
        printMenu();
    }
    else if(n==3){
        addNewDie();
        printMenu();
    }
    else if(n==4){
        std::cout<<"Quitting...";
        return;

    }
    else{
        std::cout<<"Invalid number, did you type an integer equivalent to an option?"<<std::endl;
        printMenu();
        return;
    }
}

void Game::printMenu(){
    if(players_.size() < 2){
        std::cout<<"You need at least 2 players to start the game! Press #2 to add a new one."<<std::endl;
    }
    if(dice_.size() < 1){
        std::cout<<"You need at least 1 die to start the game! Press #3 to add a new one."<<std::endl<<std::endl;
    }
    std::cout<<"#0: Set a new score goal"<<std::endl;
    std::cout<<"#1: Start a new game"<<std::endl;
    std::cout<<"#2: Add a new player"<<std::endl;
    std::cout<<"#3: Add a new die"<<std::endl;
    std::cout<<"#4: Quit game."<<std::endl;

    Game::inputAnswer();
}

void Game::run(){
    Game::printMenu();
}

int Game::playersPlaying(){
    int n_players=0;
    for(std::list<Player*>::iterator player = players_.begin();  player != players_.end(); player++){
        if( (*(*player)).getScore() < score_goal_){
            n_players++;
        }
    }
    return n_players;
}

void Game::announceWinnerAfterEveryoneLose(){
    for(std::list<Player*>::iterator player = players_.begin();  player != players_.end(); player++){
        if( (*(*player)).getScore() < score_goal_){
            std::cout<<"The winner is "<<(*(*player)).getName()<<"! Congratulations to him/her!"<<std::endl;
        }
    }
}

void Game::startGame(){
    while(playersPlaying() > 1){
        for(std::list<Player*>::iterator turn = players_.begin();  turn != players_.end(); turn++){
            //if the player score is lesser than the score_goal
            if( (*(*turn)).getScore() < score_goal_){

                //politelly ask if the player will skip or not the turn
                std::cout<<"Will you, Mr(s) "<<(*(*turn)).getName()<<", roll the dice or skip the current turn?"<<std::endl;
                std::cout<<"#1: Roll the dice."<<std::endl;
                std::cout<<"#2: Skip turn."<<std::endl;

                if((*(*turn)).willPlayNow()){
                    std::cout<<(*(*turn)).getName()<<" throwed the dice and got the numbers: "<<std::endl;
                    for(std::list<Die*>::iterator dieToPlay = dice_.begin();  dieToPlay != dice_.end(); dieToPlay++){
                        (*(*turn)).rollTheDie( (*(*dieToPlay)) ); //each player will roll a die of the game at a time
                        std::cout<<std::endl;
                    }
                    std::cout<<"."<<std::endl;
                    if((*(*turn)).getScore() == score_goal_){
                        std::cout<<(*(*turn)).getName()<<" is the winner! He has a score of "<<(*(*turn)).getScore()<<std::endl;
                        break;
                    }else if((*(*turn)).getScore() < score_goal_){
                        std::cout<<(*(*turn)).getName()<<" has a score of "<<(*(*turn)).getScore()<<std::endl;
                    
                    }else if((*(*turn)).getScore() > score_goal_){
                            std::cout<<(*(*turn)).getName()<<" has a score of "<<(*(*turn)).getScore()<<", which is greater than "<<score_goal_<<", the score goal. He lost and won`t play again in the next turn."<<std::endl;

                            if(playersPlaying()==1){
                                std::cout<<"End of turns.";
                                break;
                            }
                            
                    }
                }else{
                    std::cout<<(*(*turn)).getName()<<" skipped this turn."<<std::endl;
                }
            }
        }
    }
    announceWinnerAfterEveryoneLose();
}