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
    float probabilityOfLivingCell;
    int aEdge;
    int bEdge;
    int top;
    int left;
    std::vector<std::vector<std::string>> inputVector = std::vector<std::vector<std::string>>();
    std::string str = "";

    std::cout << "Enter the length of the Aedge!\n";
    std::cin >> aEdge;
    switch (menu)
    {
    case 1:
    {
        Game tempGame(aEdge);
        mGame = tempGame;
        break;
    }
    case 2:
    {
        std::cout << "Enter the probability!\n";
        std::cin >> probabilityOfLivingCell;
        while (std::cin.fail())
        {
            std::cout << "Error" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> probabilityOfLivingCell;
        }
        Game tempGame(aEdge, probabilityOfLivingCell);
        mGame = tempGame;
        break;
    }
    case 3:
    {
        std::cout << "Enter the length of the Bedge!\n";
        std::cin >> bEdge;
        Game tempGame(aEdge, bEdge);
        mGame = tempGame;
        break;
    }
    case 4:
    {
        std::cout << "Enter the length of the Bedge!\n";
        std::cin >> bEdge;
        std::cout << "Enter the probability!\n";
        std::cin >> probabilityOfLivingCell;
        while (std::cin.fail())
        {
            std::cout << "Error" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> probabilityOfLivingCell;
        }
        Game tempGame(aEdge, bEdge, probabilityOfLivingCell);
        mGame = tempGame;
        break;
    }
    case 5:
    {
        std::cout << "Enter the top value!\n";
        std::cin >> top;
        std::cout << "Enter the left value!\n";
        std::cin >> left;
        std::cout << "Enter the vector in the following format: x,x,x,;x,x,x,;\n";
        std::cout << "(The inner vectors should be separated with a semicolon, while the characters with a comma! \nPlace an 'X' where you want a living cell and a '-' where you want a dead one! )\n";
        std::cin >> str;
        inputVector = VectorSplitter(str);
        Game tempGame(aEdge, bEdge, top, left, inputVector);
        mGame = tempGame;
        break;
    }
    default:
    { break; }
    }
}

std::vector<std::vector<std::string>> GameConsole::VectorSplitter(const std::string& str)
{
    size_t idx = str.find(';');
    std::string strTemp = str;
    std::vector<std::vector<std::string>> outerVector;
    while (idx != std::string::npos) {
        std::vector<std::string> innerVector;
        std::string left = strTemp.substr(0, idx);
        size_t idxInner = left.find(',');
        while (idxInner != std::string::npos)
        {
            innerVector.push_back(left.substr(0, idxInner)); // push into vector
            std::string right = left.substr(idxInner + 1, left.size()); // Copying to the right side the leftovers 'til I find a ';'
            left = right; // New left side
            idxInner = left.find(','); // looking for the new index
        }
        outerVector.push_back(innerVector);
        std::string rightOuter = strTemp.substr(idx + 1, strTemp.size());
        strTemp = rightOuter;
        idx = strTemp.find(';');
    }
    return outerVector;
}