#ifndef HYPER_GIANT_STAR_H
#define HYPER_GIANT_STAR_H

#include "star.h"

class HyperGiantStar : public Star
{   
protected:
    double expansionScale;
    double expansionSpeed;
public:
    HyperGiantStar();
    void draw(std::shared_ptr<sf::RenderWindow> window) override;
    HyperGiantStar(const std::string& name, double mass, double radius, double distanceFromSun, double orbitSpeed, double gal_X, double gal_Y, double gal_R);
    ~HyperGiantStar();
    HyperGiantStar(const HyperGiantStar& hyperGiantStar);
    HyperGiantStar& operator=(const HyperGiantStar& hyperGiantStar);

//    double getExpansionScale() const;
//    void setExpansionScale(double expansionScale);
//    double getExpansionSpeed() const;
//    void setExpansionSpeed(double expansionSpeed);

    friend std::ostream& operator<<(std::ostream& os, const HyperGiantStar& hyperGiantStar);
};

#endif // !HYPER_GIANT_STAR_H