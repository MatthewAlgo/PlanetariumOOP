#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "abstract/galaxy.h"
#include "constants.h"
#include <chrono>
#include <vector>

class Universe
{
private:
    std::vector<Galaxy> galaxies;
    int numberOfGalaxies;
    std::chrono::time_point<std::chrono::steady_clock> begin;
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

    // Add an object to the universe
    void addGalaxy(const Galaxy& galaxy);
    void createBigBang();
    void startTime();
    void checkTime();
};


#endif // !UNIVERSE_H