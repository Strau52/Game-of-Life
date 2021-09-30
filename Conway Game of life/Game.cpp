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

}

std::ostream& operator<<(std::ostream& os, const Game& rhs)
{

	return os;
}