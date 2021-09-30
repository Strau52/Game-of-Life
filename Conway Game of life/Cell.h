#pragma once

class Cell {
public:
	/// <summary>
	/// The constructor of the Cell class.
	/// </summary>
	Cell();

	/// <summary>
	/// This method will return if the cell is alive or not.
	/// </summary>
	/// <returns>The condition of the cell.</returns>
	bool GetIsAlive() const;
	/// <summary>
	/// This method will set the condition of the cell.
	/// </summary>
	/// <param name="isAlive">The condition of the cell.</param>
	/// <returns>The cell reference</returns>
	Cell& SetIsAlive(const bool& isAlive);

private:
	bool mIsAlive = false;
};