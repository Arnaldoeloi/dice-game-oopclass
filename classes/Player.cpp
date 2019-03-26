#include "Player.h"

Player::Player(){
    name_= "The man with no name";
    score_=0;
};

Player::Player(std::string name){
    name_= name;
    score_=0;
};

int Player::getScore(){
    return score_;
};

std::string Player::getName(){
    return name_;
};

void Player::addToScore(int n){
    score_+=n;
};

void Player::rollTheDie(Die& die){
    int aux_score=die.roll();
    addToScore(aux_score);
};

bool Player::willPlayNow(){
    bool willPlay=false;
    
    std::string answer="";
    
    while(true){
        std::cin>>answer;
        int n;
        try{
            n = stoi(answer);
        }catch(const std::invalid_argument& e1){
            std::cout<<"Be clear! Skip(1) or play(2)?"<<std::endl;
            continue;
        }
        if(n==1){
            return willPlay=true;
        }else if(n==2){
            return willPlay=false;
        }else{
            std::cout<<"Be clear! Skip(1) or play(2)?"<<std::endl;
            continue;
        }
        
    }
    return willPlay;
}


