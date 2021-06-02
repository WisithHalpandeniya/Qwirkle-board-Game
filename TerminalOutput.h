#include <map>

#include "TileCodes.h"

class TerminalOutput
{
private:
    std::map<char, std::string> colour_codes{
        {RED, "\u001b[41m"},
        {ORANGE, "\u001b[48;5;166m"},
        {YELLOW, "\u001b[43m"},
        {GREEN, "\u001b[42m"},
        {BLUE, "\u001b[44m"},
        {PURPLE, "\u001b[45m"}};
    std::map<int, std::string> symbols{
        {CIRCLE, "⚪"},
        {STAR_4, " ✦"},
        {DIAMOND, "💠"},
        {SQUARE, " ■"},
        {STAR_6, " ✶"},
        {CLOVER, "🍀"}};

public:
    inline std::string getCode(char colour)
    {
        return colour_codes[colour];
    }
    inline std::string getSymbol(int shape)
    {
        return symbols[shape];
    }
    const char *reset = "\u001b[0m";
};
