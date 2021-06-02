#include "Position.h"
#include <sstream>

Position::Position(std::string str) : row(str[0] - 'A'), col(std::stoi(str.substr(1)) - 1)
{
}

Position::Position(int row, int col) : row(row), col(col)
{
}

std::string Position::str()
{
    std::stringstream out;
    out << static_cast<char>('A' + row) << col + 1;
    return out.str();
}
