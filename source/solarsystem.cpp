#include "solarsystem.h"


SolarSystem::SolarSystem(const std::vector<Planet> &planets, const std::shared_ptr<Star> &mainStar,
                         int asteroidBelts, int ageSinceStarFormation) : planets(planets), mainStar(mainStar),
                                                                         asteroidBelts(asteroidBelts),
                                                                         ageSinceStarFormation(ageSinceStarFormation) {}

const std::vector<Planet> &SolarSystem::getPlanets() const {
    return planets;
}

void SolarSystem::setPlanets(const std::vector<Planet> &p) {
    SolarSystem::planets = p;
}

const std::shared_ptr<Star> &SolarSystem::getMainStar() const {
    return mainStar;
}

void SolarSystem::setMainStar(const std::shared_ptr<Star> &mS) {
    SolarSystem::mainStar = mS;
}

int SolarSystem::getAsteroidBelts() const {
    return asteroidBelts;
}

void SolarSystem::setAsteroidBelts(int aB) {
    SolarSystem::asteroidBelts = aB;
}

int SolarSystem::getAgeSinceStarFormation() const {
    return ageSinceStarFormation;
}

void SolarSystem::setAgeSinceStarFormation(int aSStarForm) {
    SolarSystem::ageSinceStarFormation = aSStarForm;
}

SolarSystem::SolarSystem() {
    // No default implementation
}

bool SolarSystem::operator==(const SolarSystem &rhs) const {
    return planets.size() == rhs.planets.size() &&
           mainStar == rhs.mainStar &&
           asteroidBelts == rhs.asteroidBelts &&
           ageSinceStarFormation == rhs.ageSinceStarFormation;
}

bool SolarSystem::operator!=(const SolarSystem &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const SolarSystem &solarSystem) {
    os << "planets: " << solarSystem.planets << " mainStar: " << *solarSystem.mainStar << " asteroidBelts: "
       << solarSystem.asteroidBelts << " ageSinceStarFormation: " << solarSystem.ageSinceStarFormation;
    return os;
}


SolarSystemBuilder& SolarSystemBuilder::noAsteroidBelts(int nr) {
    ssystem.asteroidBelts = nr;
    return *this;
}
SolarSystemBuilder& SolarSystemBuilder::ageOfSSystem(int age){
    ssystem.ageSinceStarFormation = age;
    return *this;
}
SolarSystemBuilder& SolarSystemBuilder::addPlanet(Planet planet){
    ssystem.planets.push_back(planet);
    return *this;
}
SolarSystemBuilder& SolarSystemBuilder::setMainStar(Star mStar){
    ssystem.mainStar = std::make_shared<Star>(mStar);
    return *this;
}
SolarSystem SolarSystemBuilder::build() {
    return ssystem;
}