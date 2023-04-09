#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "abstract/galaxy.h"
#include <vector>

class Universe
{
private:
    std::vector<Galaxy> galaxies;
    int numberOfGalaxies;
public:
    explicit Universe(int numberOfGalaxies);
    void draw();
//    void addGalaxy(Galaxy galaxy);
//    void removeGalaxy(Galaxy galaxy);
//    void removeGalaxy(int index);
//    void removeAllGalaxies();
//    void setNumberOfGalaxies(int numberOfGalaxies);
//    int getNumberOfGalaxies();
//    std::vector<Galaxy> getGalaxies();
    friend std::ostream& operator<<(std::ostream& os, const Universe& universe);
    ~Universe();
    Universe(const Universe& universe);
    Universe& operator=(const Universe& universe);
};


#endif // !UNIVERSE_H