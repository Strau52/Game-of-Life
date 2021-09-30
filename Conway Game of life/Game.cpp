#include "Game.h"

Game::Game(const int& aEdge)
{

}

Game::Game(const int& aEdge, const int& bEdge)
{

}

Game::Game(const int& aEdge, const float& probabilityOfALivingCell)
{

}

Game::Game(const int& aEdge, const int& bEdge, const float& probabilityOfALivingCell)
{

}

Game::Game(const int& height, const int& width, const int& top, const int& left, const std::vector<std::vector<std::string>>& fieldVector)
{

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
			}

				actualCell.SetIsAlive(true);
}

std::ostream& operator<<(std::ostream& os, const Game& rhs)
{

	return os;
}