#pragma once

#include "abstract/universe.h"

class UniverseFactory {
public:
    static Universe createSmallUniverse();
    static Universe createMediumUniverse();
    static Universe createLargeUniverse();
};