#include "GameConsole.h"

GameConsole::GameConsole()
{
    Game mGame;
}

void GameConsole::Write()
{

}

void GameConsole::MainMenu()
{
    do {
        system("CLS");
        std::cout << "Choose a field creation mode!!\n";
        std::cout << "1 - Square field, automatic probability\n";
        std::cout << "2 - Square field, manual probability\n";
        std::cout << "3 - Rectangle field, automatic probability\n";
        std::cout << "4 - Rectangle field, manual probability\n";
        std::cout << "5 - Rectangle field, cell pattern with vector\n";
        std::cout << "6 - Quit\n";
        std::cout << "My choice:";
        std::cin >> mChoice;
    } while (!((mChoice > 0) && (mChoice < 6)));

    GameSettingsInputs(mChoice);
}

void GameConsole::GameSettingsInputs(const int& menu) 
{

}

std::vector<std::vector<std::string>> GameConsole::VectorSplitter(const std::string& str)
{
    std::vector<std::vector<std::string>> outerVector;

    return outerVector;
}