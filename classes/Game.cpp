#include "Game.h"

Game::Game(int score_goal){
    score_goal_ = score_goal;
}

void Game::addNewPlayer(){
    std::cout<<"What is the name of this player? Press enter to confirm."<<std::endl;
    std::string name;
    getline(std::cin, name);

    Player* p = new Player(name);
    players_.push_front(p); 
}

void Game::addNewDie(){
    std::cout<<"What is the number of sides of this die?"<<std::endl;
    std::string number;
    getline(std::cin, number);

    int n;
    
    try {
        n = stoi(number);
    } catch( const std::invalid_argument& e1 ) {
        std::cout<<"Invalid number, did you type an integer greater than 4?"<<std::endl;
        printMenu();
        return;
    }

    Die* die = new Die(n);
    dice_.push_front(die); 

}

void Game::inputAnswer(){
    std::string answer;
    std::cin>>answer;

    int n = stoi(answer);
    if(n==1){
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

        if(dice_.size() >= 1 && players_.size() >= 2){
            Game::startGame();
        }
    }else if(n==2){
        addNewPlayer();
    }
}

void Game::printMenu(){
    if(players_.size() < 2){
        std::cout<<"You need at least 2 players to start the game! Press #2 to add a new one."<<std::endl;
    }
    if(dice_.size() < 1){
        std::cout<<"You need at least 1 die to start the game! Press #3 to add a new one."<<std::endl<<std::endl;
    }
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
                    if((*(*turn)).getScore == score_goal_){
                        std::cout<<(*(*turn)).getName()<<" is the winner! He has a score of "<<(*(*turn)).getScore()<<std::endl;
                        break;
                    }else if((*(*turn)).getScore < score_goal_){
                        std::cout<<(*(*turn)).getName()<<"He/She has a score of "<<(*(*turn)).getScore()<<std::endl;
                    }
                }else{

                }
            }
        }
    }
}