#ifndef MENU_H
#define MENU_H

#include <iostream>

using std::string;

void runMenu();

void printCredits();
void loadGame();
void printMenu();
bool checkExistingFile(std::string& fileName);
void displayHelp();


#endif // MENU_H