#include "ant_simulator.h"

namespace Limits {
    constexpr int g_digitSumLimit = 25;
    constexpr int g_stepsNumberMax = std::numeric_limits<int>::max();
}

AntSimulator::AntSimulator(const Cell& startCell) {
    getAround(startCell);
}

int AntSimulator::visitedCellsNumber() const {
    return m_cellsCounter;
}

bool AntSimulator::isCellEnable(const Cell& cell) const
{
    // Calculated digits sum (for absolute values)
    int sum = 0;
    auto countDigits = [&sum](int value) {
        for (auto val = std::abs(value); val > 0; val /= 10) {
            sum += val % 10;
        }
    };
    countDigits(cell.x());
    countDigits(cell.y());
    return sum <= Limits::g_digitSumLimit;
}

void AntSimulator::getAround(const Cell& startCell)
{
    m_order.push(startCell);

    // We try to move to the next unvisited cells if the counter limit has not been reached
    while (!m_order.empty() && m_cellsCounter < Limits::g_stepsNumberMax) {
        // Takes the first value from the queue
        Cell currentCell = m_order.front();
        m_order.pop();

        // Interrupts if the cell is not valid or if it has already been visited
        if (m_visitedCells.find(currentCell) != m_visitedCells.end() || !isCellEnable(currentCell))
        {
            continue;
        }

        // Increases the result if the current cell is valid and if it has not been visited before
        m_cellsCounter++;

        // Marks the cell as visited
        m_visitedCells.emplace(currentCell);

        // Pushes all the cells reached from the current one to the BFS queue
        for (const auto& step : m_steps)
        {
            m_order.push(currentCell.next(step));
        }
    }
}
