#include "Util.h"

#include <memory>
#include <regex>

using std::shared_ptr;

using std::cin;
using std::cout;
using std::endl;

using std::regex;
using std::regex_match;

string userInput(action action)
{
    string playerInput = "";

    playerInput = recursiveInput(action, playerInput);

    return playerInput;
}

string recursiveInput(action action, string playerInput)
{
    bool returnValue = false;

    std::getline(cin, playerInput);

    // If input is still valid
    if (action == ADD_PLAYER)
    {
        // Check for symbols
        if (regex_match(playerInput, regex("^[A-Z]+$")))
        {
            returnValue = true;
        }
        else
        {
            cout << "Names should have uppercase letters only." << endl;
        }
    }
    else if (action == MENU_INPUT)
    {
        // Between 1-4 only 1 character
        if (regex_match(playerInput, regex("^[1-4]{1}$")) || playerInput == "help")
        {
            returnValue = true;
        }
        else
        {
            cout << "Please insert a number between 1 and 4 or enter help." << endl;
        }
    }
    else if (action == PLAYER_TURN)
    {
        // Condition: If 1st word matches ["place"] and input does not match case ["place ## at ##"]
        if (regex_match(playerInput, regex("^place [ROYGBP]{1}[1-6]{1} at [A-Z]{1}[0-9]{1,2}$")))
        {
            returnValue = true;
        }
        // Condition: If 1st word matches ["replace"] and 2nd input is not tile string ["##"]
        else if (regex_match(playerInput, regex("^replace [ROYGBP]{1}[1-6]{1}$")))
        {
            returnValue = true;
        }
        // Condition: If 1st word matches ["save"] and no filename is specified
        else if (regex_match(playerInput, regex("^save [a-zA-Z0-9]+$")))
        {
            returnValue = true;
        }
        else if (playerInput == "help")
        {
            returnValue = true;
        }
        else if(!cin.eof())
        {
            cout << "Invalid command. Enter help for command usage." << endl;
        }
    }
    else if (action == LOAD)
    {
        if (regex_match(playerInput, regex("^[a-zA-Z0-9]+|^[a-zA-Z0-9]+.save$")) || regex_match(playerInput, regex("^./(.*)/[a-zA-Z0-9]+|^./(.*)/[a-zA-Z0-9]+.save$")))
        {
            if (!regex_match(playerInput, regex(".save$")))
            {
                playerInput += ".save";
            }
            returnValue = true;
        }
    }

    if (!returnValue)
    {
        if (!cin.eof())
        {
            cout << endl;
            cout << "> ";
            playerInput = recursiveInput(action, playerInput);
        }
        else
        {
            cout << endl
                 << endl;
            cout << "Goodbye!" << endl;
        }
    }

    return playerInput;
}