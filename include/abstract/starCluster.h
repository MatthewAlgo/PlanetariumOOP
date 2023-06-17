#ifndef STAR_CLUSTER_H
#define STAR_CLUSTER_H

#include "star.h"
#include <vector>
#include <ostream>

template <typename T>
std::enable_if_t<!std::is_convertible_v<T, std::string>, std::ostream&>
operator<<(std::ostream& os, const T& obj)
{
    os << "[";
    int nr = 0;
    for(auto iter = obj.begin(); iter != obj.end(); ++iter) {
        os << *iter;
        ++nr;
        if(iter == obj.end())
            break;
        os << ", ";
        if(nr >= 5) {
            os << "...";
            break;
        }
    }
    os << "]";
    return os;
}

class StarCluster
{
private:
    double distanceFromCenterOfGalaxy;
    double rotationSpeed;
    double mass;
    double radius;
    double luminosity;

    std::vector<Star> stars;

public:
    friend std::ostream &operator<<(std::ostream &os, const StarCluster &cluster);

    // Constructor, copy constructor and assignment operator
    StarCluster(double distanceFromCenterOfGalaxy, double radius);
    StarCluster(const StarCluster& starCluster);
    StarCluster& operator=(const StarCluster& starCluster);
};

#endif // !STAR_CLUSTER_H  