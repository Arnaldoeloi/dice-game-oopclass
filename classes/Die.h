#ifndef _DIE_H_
#define _DIE_H_

#include<iostream>
#include<random>

class Die{
    private:
        int n_sides_;

        std::random_device rd;
        std::default_random_engine gen;
        std::uniform_int_distribution<> dis;

    public:
        Die(int n_sides);
        ~Die(){};

        //Return the result of rolling one die at time
        int roll();
            
};

#endif