#pragma once

#include <unordered_set>
#include <queue>

// Represents a step to move to the next cell
struct Step {
    int x{ 0 };
    int y{ 0 };
};

// Represens a cell
class Cell {
public:
    Cell(int x, int y);

    int x() const;
    int y() const;

    // Returns the cell by the particular step
    Cell next(const Step& step) const;

private:
    int m_x{ 0 };
    int m_y{ 0 };
};

using CellHashSet = std::unordered_set<Cell>;
using CellQueue = std::queue<Cell>;

// Сomparison operator to use unordered set of cells
bool operator==(const Cell& cell1, const Cell& cell2);

// Hash functor specialization for Cell class
template<>
struct std::hash<Cell>
{
    std::size_t operator()(const Cell& cell) const;
};
