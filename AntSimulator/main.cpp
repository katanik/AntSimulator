#include <iostream>

#include "ant_simulator.h"

int main()
{
    const Cell startCell{ 1000, 1000 };
    AntSimulator ant{ startCell };
    std::cout << ant.visitedCellsNumber();
}
