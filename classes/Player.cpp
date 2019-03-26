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
    
    while(answer!="1" || answer!="2" || answer!="roll" || answer!="skip" || answer!="play"){
        std::cin>>answer;
        if(answer!="1"){
            willPlay=true;
        
        }else if(answer=="2"){
            willPlay=false;
        
        }else if(answer=="roll"){
            willPlay=true;
        
        }else if(answer=="skip"){
            willPlay=false;
        
        }else if(answer=="play"){
            willPlay=true;
        }
        else{
            std::cout<<"Be clear! Skip(1) or play(2)?"<<std::endl;
        }
    }
    return willPlay;
}


