#include "pch.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class GameOfLife {
	
	// Access specifier 
	public:	
		int rows;
		int cols;
		vector<vector<int>> Board;

		// Parametrized constructor
		// Build board at time of object creation
		GameOfLife(int rows, int cols) {
			
			// Resize vector based on constructor paramaters
			Board.resize(rows, vector<int>(cols)); 
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					
					// Random 0 or 1 to populate board
					Board[i][j] = rand() % 2; 

				}
			}

		}

		// Class methods 

		void Display() {
			
			for (int i = 0; i < Board.size(); i++) {
				for (int j = 0; j < Board[i].size(); j++)
					cout << Board[i][j] << " ";
				cout << endl;
			}

		}

		// Helper method to obtain cell value
		int getCell(int row, int col) {
			
			for (int i = 0; i < Board.size(); i++) {
				if (i == row) {
					for (int j = 0; j < Board[i].size(); j++) {
						if (j == col) {
							return Board[i][j];
						}
					}
				}
			}
			
			// If not found assume dead
			return 0;
		}


		// Find all living neighbors of given cell
		int livingNeighbors(int row, int col) {
			
			int numNeighbors = 0;

			// Sum living neighbors of surrounding cell
			numNeighbors += getCell(row - 1, col - 1);
			numNeighbors += getCell(row - 1, col);
			numNeighbors += getCell(row - 1, col + 1);
			numNeighbors += getCell(row, col + 1);
			numNeighbors += getCell(row + 1, col + 1);
			numNeighbors += getCell(row + 1, col);
			numNeighbors += getCell(row + 1, col - 1);
			numNeighbors += getCell(row, col - 1);

			return numNeighbors;
		}

		// Apply cell survival rules to given cell, returns 1 or 0
		int applyRules(int row, int col) {
			
			int neighbors = livingNeighbors(row, col);

			// Living cell
			if (getCell(row, col) == 1) {
				if (neighbors == 2 || neighbors == 3) {
					return 1;
				}
			} 
			
			// Dead cell
			else {
				if (neighbors == 3) {
					return 1;
				}
			}
			
			// Cell must be dead next tick
			return 0;
		}

		void update() {
			for (int i = 0; i < Board.size(); i++) {
				for (int j = 0; j < Board[i].size(); j++)
					Board[i][j] = applyRules(i, j);	
			}
		}
 };




int main()
{
	// Set seed
	srand(time(NULL));

	// Initialize variables
	int rows;
	int cols;


	// User input
	cout << "Welcome to game of life " << endl;
	cout << "Please enter the number of rows (above 10 is a good start): ";
	cin >> rows;
	cout << "Please enter the number of columns (above 10 is a good start): ";
	cin >> cols;
	
	GameOfLife game(rows,cols);

	// Game loop
	while (true) {
		game.Display();
		game.update();
		system("cls"); // clear console
	}
	
	return 0;
}

