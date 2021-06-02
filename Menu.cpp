#include <fstream>

#include "Menu.h"
#include "Game.h"
#include "Util.h"

using std::cout;
using std::endl;
using std::make_shared;

void runMenu()
{
    bool quitMenu = false;
    std::string input = "";

    do
    {
        printMenu();

        cout << endl
             << "> ";

        // convert string to integer (stoi)
        input = userInput(MENU_INPUT);
        cout << endl;

        if (input == "1")
        {
            shared_ptr<Game> game = make_shared<Game>();
            game->startGame();

            quitMenu = true;
        }
        else if (input == "2")
        {
            loadGame();
            quitMenu = true;
        }
        else if (input == "3")
        {
            printCredits();
            cout << endl;
        }
        else if (input == "4")
        {
            cout << "Goodbye!" << endl;
            quitMenu = true;
        }
        else if (input == "help")
        {
            displayHelp();
        }
        else if (std::cin.eof())
        {
            quitMenu = true;
        }

    } while (!quitMenu);
}

void printCredits()
{
    cout << "---------------------------------------------" << endl
         << "Name: Ahnaf Rahman Samin" << endl
         << "Student ID: s3815024" << endl
         << "Email: s3815024@student.rmit.edu.au" << endl
         << " " << endl
         << "Name: Emanuel Le" << endl
         << "Student ID: s3844780" << endl
         << "Email: s3844780@student.rmit.edu.au" << endl
         << " " << endl
         << "Name: Aaron Schmid" << endl
         << "Student ID: s3784832" << endl
         << "Email: s3784832@student.rmit.edu.au" << endl
         << " " << endl
         << "Name: Wisith Halpandeniya Hevage" << endl
         << "Student ID: s3728665" << endl
         << "Email: s3728665@student.rmit.edu.au" << endl
         << "---------------------------------------------" << endl
         << endl;
}

void printMenu()
{
    cout << "MENU" << endl
         << "----" << endl
         << "1. New Game" << endl
         << "2. Load Game" << endl
         << "3. Credits (Show student information)" << endl
         << "4. Quit" << endl;
}

void loadGame()
{
    cout << "Enter the filename from which load a game " << endl;
    cout << "> ";
    std::string fileName;

    std::ifstream inputFile;
    do
    {
        fileName = userInput(LOAD);
        inputFile.open(fileName);

        if (!inputFile.good() && !std::cin.eof())
        {
            cout << "Invalid Input" << endl;
            cout << "> ";
        }

    } while (!inputFile.good() && !std::cin.eof());

    if (!std::cin.eof())
        shared_ptr<Game> game = make_shared<Game>(inputFile);
}

void displayHelp()
{
    std::cout << "Help" << endl
              << "----" << endl
              << "1 - Starts a new game of qwirkle" << endl
              << "2 - Loads a game" << endl
              << "3 - Shows the credits" << endl
              << "4 – Quits qwirkle" << endl
              << "Rules:" << endl
              << "A new game always begins with player 1 and an empty board." << endl
              << "Tiles are placed one at a time and players can only replace one tile at a time." << endl
              << "All tiles played mush share one attribute, be it colour or shape and must be placed in the same line." << endl
              << endl
              << "To Save the game: save <name of save file>" << endl
              << "To Load a game: select option 2 then enter the filename of the saved game." << endl
              << endl;
}