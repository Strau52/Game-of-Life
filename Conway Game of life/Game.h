#pragma once
#include "Cell.h"
#include <vector>
#include <iostream>
#include <random>
#include <string>

class Game
{
public:
	/// <summary>
	/// This is the default constructor of the Game.
	/// </summary>
	Game() = default;
	/// <summary>
	/// This is the one integer parameter constructor of the Game. This will create a square with sides are aEdge long. The probability of a living cell is 10% here.
	/// </summary>
	/// <param name="aEdge">The length of the side of the square.</param>
	Game(const int& aEdge);
	/// <summary>
	/// This is the two integer parameter constructor of the Game. This will create a rectangle with side A agege side B side bedge length. The probability of a living cell is 10% here.
	/// </summary>
	/// <param name="aEdge">The length of the side A of the rectangle.</param>
	/// <param name="bEdge">The length of the side B of the rectangle.</param>
	Game(const int& aEdge, const int& bEdge);
	/// <summary>
	/// This is the one integer and one floating parameter constructor of the Game. This will create a square with sides are aEdge long. The probability of a living cell is is decided by the user here.
	/// </summary>
	/// <param name="aEdge">The length of the side of the square.</param>
	/// <param name="probabilityOfALivingCell">The chance of generating a living cell.</param>
	Game(const int& aEdge, const float& probabilityOfALivingCell);
	/// <summary>
	/// This is the two integer and one floating parameter constructor of the Game. This will create a rectangle with side A agege side B side bedge length. The probability of a living cell is is decided by the user here.
	/// </summary>
	/// <param name="aEdge">The length of the side A of the rectangle.</param>
	/// <param name="bEdge">The length of the side B of the rectangle.</param>
	/// <param name="probabilityOfALivingCell">The chance of generating a living cell.</param>
	Game(const int& aEdge, const int& bEdge, const float& probabilityOfALivingCell);
	/// <summary>
	/// This is the four integer and one vector of vectors parameter constructor of the Game.
	/// </summary>
	/// <param name="height">The height of the playing field.</param>
	/// <param name="width">The width of the playing field.</param>
	/// <param name="top">Paste top starting position.</param>
	/// <param name="left">Paste left starting position.</param>
	/// <param name="fieldVector">The vector to be inserted.</param>
	Game(const int& height, const int& width, const int& top, const int& left, const std::vector<std::vector<std::string>>& fieldVector);

	/// <summary>
	/// This method will advance the simulation to the next stage.
	/// </summary>
	void NextStage();
	/// <summary>
	/// This method will return the actual state of the game.
	/// </summary>
	/// <returns>The game vectors.</returns>
	std::vector<std::vector<Cell>> getGame() const;
	/// <summary>
	/// This method will set the game to a certain state.
	/// </summary>
	/// <param name="game">The state we want to set for the game.</param>
	/// <returns>The game reference itself.</returns>
	Game& setGame(std::vector<std::vector<Cell>>& game);

private:
	std::vector<std::vector<Cell>> mGame;

	/// <summary>
	/// This method will create the game field with the matching edges and probabilities.
	/// </summary>
	/// <param name="aEdge">The A edge lenght.</param>
	/// <param name="bEdge">The B edge lenght.</param>
	/// <param name="probabilityOfALivingCell">The probability of a living cell in one cell.</param>
	void GenerateGame(const int& aEdge, int bEdge, const float& probabilityOfALivingCell);

	/// <summary>
	/// This method will decide the longest dimension of a vector which was given by the user.
	/// </summary>
	/// <param name="fieldVector">The questionable vector.</param>
	/// <returns>The longest dimension.</returns>
	int LongestDimension(const std::vector<std::vector<std::string>>& fieldVector);
};

std::ostream& operator<<(std::ostream& os, const Game& rhs);