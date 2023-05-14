#pragma once
#include "star.h"

class HyperGiantStar : public Star
{
public:
    HyperGiantStar(const std::string& name, double distance, double gx, double gy, double gz);
    ~HyperGiantStar();
};