#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "abstract/galaxy.h"
#include "constants.h"
#include "window/window.h"
#include <chrono>
#include <vector>

class Universe
{
public:
    static int numberOfUniverseObjects;

private:
    std::vector<Galaxy> galaxies;
    int numberOfGalaxies;
    std::chrono::time_point<std::chrono::steady_clock> begin;

public:
    explicit Universe(int numberOfGalaxies);

    friend std::ostream& operator<<(std::ostream& os, const Universe& universe);
    ~Universe();
    Universe(const Universe& universe);
    Universe& operator=(const Universe& universe);

    // Add an object to the universe
    void addGalaxy(const Galaxy& galaxy);
    void createBigBang(MainWindowClass* window);
    void startTime();
    int checkTime();
};


#endif // !UNIVERSE_H