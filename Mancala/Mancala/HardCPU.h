#pragma once
#include <cstdlib>
#include <ctime>
#include "EasyCPU.h"

class HardCPU :
    public EasyCPU
{
public:
    // Constructor
    HardCPU(Board& board);

    // Method
    int CPUMove();

    // Destructor
    ~HardCPU();
};