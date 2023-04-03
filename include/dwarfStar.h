#ifndef DWARF_STAR_H
#define DWARF_STAR_H
#include "star.h"

class DwarfStar : public Star
{
private:
    double magnetismLevel;
    double temperature;
    double luminosity;
public:
    DwarfStar();
    void draw() override;
    DwarfStar(std::string name, double mass, double radius, double distanceFromCenterOfGalaxy, double rotationSpeed, double magnetismLevel, double temperature, double luminosity);
    ~DwarfStar();
    DwarfStar(const DwarfStar& dwarfStar);
    DwarfStar& operator=(const DwarfStar& dwarfStar);
    

    double getMagnetismLevel() const;
    void setMagnetismLevel(double magnetismLevel);
    double getTemperature() const;
    void setTemperature(double temperature);
    double getLuminosity() const;
    void setLuminosity(double luminosity);

    friend std::ostream& operator<<(std::ostream& os, const DwarfStar& dwarfStar);
};

#endif // !DWARF_STAR_H