#ifndef HYPER_GIANT_STAR_H
#define HYPER_GIANT_STAR_H

#include "star.h"

class HyperGiantStar : public Star
{   
protected:
    double yearsToLive;
    double expansionScale;
    double expansionSpeed;
public:
    HyperGiantStar();
    void draw() override;
    HyperGiantStar(std::string name, double mass, double radius, double distanceFromSun, double orbitSpeed);
    ~HyperGiantStar();
    HyperGiantStar(const HyperGiantStar& hyperGiantStar);
    HyperGiantStar& operator=(const HyperGiantStar& hyperGiantStar);

    double getYearsToLive() const;
    void setYearsToLive(double yearsToLive);
    double getExpansionScale() const;
    void setExpansionScale(double expansionScale);
    double getExpansionSpeed() const;
    void setExpansionSpeed(double expansionSpeed);

    friend std::ostream& operator<<(std::ostream& os, const HyperGiantStar& hyperGiantStar);
};

#endif // !HYPER_GIANT_STAR_H