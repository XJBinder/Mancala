#pragma once
#include <cstdlib>
#include <ctime>
#include "EasyCPU.h"

class MediumCPU :
    public EasyCPU
{
public:
    // Constructor
    MediumCPU(Board& board);

    // Method
    int CPUMove();

    // Destructor
    ~MediumCPU();
};