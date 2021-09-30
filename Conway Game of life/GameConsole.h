#pragma once
#include "Game.h"

class GameConsole
{
public:
	/// <summary>
	/// The constructor of the GameConsole class.
	/// </summary>
	GameConsole();

	/// <summary>
	/// This method writes out the game's main menu and check if the user chosen a valid menu point.
	/// </summary>
	void MainMenu();
	/// <summary>
	/// This method writes out the actual position of the game.
	/// </summary>
	void Write();

private:
	int mChoice = 0;
	Game mGame;
	int mCounter = 0;
	int mLivingCells = 0;
	/// <summary>
	/// This method will create the game field matching the menu point that the user chosen.
	/// </summary>
	/// <param name="menu">The chosen menu point.</param>
	void GameSettingsInputs(const int& menu);
	/// <summary>
	/// This method will split into a string vector the string which was given by the user.
	/// </summary>
	/// <param name="str">The string which represents the game field.</param>
	/// <returns>String vector which matches the string but in a vector from.</returns>
	std::vector<std::vector<std::string>> VectorSplitter(const std::string& str);
};