#include "Game.h"

Game::Game(const int& aEdge)
{
	GenerateGame(aEdge, 0, 0);
}

Game::Game(const int& aEdge, const int& bEdge)
{
	GenerateGame(aEdge, bEdge, 0);
}

Game::Game(const int& aEdge, const float& probabilityOfALivingCell)
{
	GenerateGame(aEdge, 0, probabilityOfALivingCell);
}

Game::Game(const int& aEdge, const int& bEdge, const float& probabilityOfALivingCell)
{
	GenerateGame(aEdge, bEdge, probabilityOfALivingCell);
}

Game::Game(const int& height, const int& width, const int& top, const int& left, const std::vector<std::vector<std::string>>& fieldVector)
{
	int topCounter = -1;
	for (int i = 0; i < width; i++)
	{
		int leftCounter = -1;
		std::vector<Cell> actualCell;
		if (i >= top - 1)
			topCounter++; //This will determine which vector we are looking in the big vector.

		for (int j = 0; j < height; j++)
		{
			Cell tempCell = Cell();
			if (j >= left - 1)
				leftCounter++;

			int longest = LongestDimension(fieldVector);
			if ((topCounter >= 0) && (leftCounter >= 0) && (topCounter < fieldVector.size()) && (leftCounter < longest))
			{
				if (fieldVector[topCounter][leftCounter] == "X" || fieldVector[topCounter][leftCounter] == "x") // If we are int he top left space we check the state of the cell.
				{
					tempCell.SetIsAlive(true);
				}
			}
			actualCell.push_back(tempCell);
		}
		mGame.push_back(actualCell);
	}
}

int Game::LongestDimension(const std::vector<std::vector<std::string>>& fieldVector)
{

}

void Game::NextStage()
{

}

std::vector<std::vector<Cell>> Game::getGame() const
{
	return mGame;
}

Game& Game::setGame(std::vector<std::vector<Cell>>& game)
{
	mGame = game;
	return *this;
}

void Game::GenerateGame(const int& aEdge, int bEdge, const float& probabilityOfALivingCell)
{
	std::random_device rD;
	std::default_random_engine rE(rD());
	int maxChance = 0;

	if (bEdge == 0)
		bEdge = aEdge;
	for (int i = 0; i < aEdge; i++)
	{
		std::vector<Cell> gameField;
		for (int j = 0; j < bEdge; j++)
		{
			Cell actualCell = Cell();
			int chanceAlive = 0;
			if ((probabilityOfALivingCell == 0))
			{
				maxChance = 100;
				chanceAlive = 10;
			}
			else
			{
				std::string str = std::to_string(probabilityOfALivingCell);
				size_t idx = str.find('.');
				std::string right = "";
				if (idx != std::string::npos)
					right = str.substr(idx + 1, str.size());

				std::string myNum = "1";
				for (size_t i = 0; i < right.length(); i++)
					myNum += "0";

				chanceAlive = stoi(myNum) * probabilityOfALivingCell;
				maxChance = stoi(myNum);
			}
			std::uniform_int_distribution<int> unif_distr(1, maxChance);
			int rnd = unif_distr(rE);
			if (rnd <= chanceAlive)
			{
				actualCell.SetIsAlive(true);
			}
			gameField.push_back(actualCell);
		}
		mGame.push_back(gameField);
	}
}

std::ostream& operator<<(std::ostream& os, const Game& rhs)
{

	return os;
}