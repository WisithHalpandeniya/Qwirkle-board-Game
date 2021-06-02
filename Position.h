#ifndef POSITION_H
#define POSITION_H

#include <cstddef>
#include <string>

class Position
{
  public:
    size_t row, col;
    Position(int row, int col);
    Position(std::string str);
    std::string str();
};

#endif
