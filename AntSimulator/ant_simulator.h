#pragma once

#include <array>

#include "cell.h"

// Provides a tool to simulate ant steps
class AntSimulator {
public:
    explicit AntSimulator(const Cell& startCell);

    // Returns the visited cells number
    int visitedCellsNumber() const;

private:
    /// Checks if the ant can visit the cell
    bool isCellEnable(const Cell& cell) const;

    // Runs cells traversal
    void getAround(const Cell& startCell);

private:
    const std::array<Step, 4> m_steps{ Step{0, -1},
                                       Step{0, 1},
                                       Step{1, 0},
                                       Step{-1, 0} };

    CellHashSet m_visitedCells;
    CellQueue m_order;

    int m_cellsCounter = 0;
};
