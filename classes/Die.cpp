#include "Die.h"

Die::Die(int n_sides):rd(),gen(rd()),dis(1, n_sides){}

int Die::roll(){
    int n = dis(gen);
    std::cout<<n;
    return n;
}

