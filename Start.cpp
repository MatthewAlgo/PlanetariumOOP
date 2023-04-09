#include <iostream>
#include "abstract/universe.h"
#include "star.h"
#include "blackHole.h"

int main() {

    Universe universe(1);
    std::cout<<universe<<std::endl;

    BlackHole blackHole("M87", 100, 200, 300, 400);
    blackHole.draw();

    Star star("Alpha Centauri", 200, 300, 100, 10);
    star.draw();

    return 0;
}
