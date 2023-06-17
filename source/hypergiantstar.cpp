#include "hypergiantstar.h"

HyperGiantStar::HyperGiantStar(const std::string& name, double distance, double gx, double gy, double gz) : Star(name, 1, 1, 1, distance, gx, gy, gz)
{
    std::cout<<"HyperGiantStar constructor called"<<std::endl;
}


HyperGiantStar::~HyperGiantStar()
{
    std::cout<<"HyperGiantStar destructor called"<<std::endl;
}

