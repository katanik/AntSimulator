#include "cell.h"

Cell::Cell(int x, int y) : m_x(x), m_y(y) {}

int Cell::x() const
{
    return m_x;
}

int Cell::y() const
{
    return m_y;
}

Cell Cell::next(const Step& step) const
{
    return Cell(x() + step.x, y() + step.y);
}

bool operator==(const Cell& cell1, const Cell& cell2) {
    return cell1.x() == cell2.x() && cell1.y() == cell2.y();
}

std::size_t std::hash<Cell>::operator()(const Cell& cell) const
{
    // Calculates hash of a cell as XOR of coordinates hashes
    const auto xHash = hash<int>{}(cell.x());
    const auto yHash = hash<int>{}(cell.y());

    if (xHash != yHash) {
        return xHash ^ yHash;
    }

    // If the hashes are equal, XOR will be zero, so we will return just x hash
    return xHash;
}
