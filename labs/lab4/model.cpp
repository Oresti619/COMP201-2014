#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
    state = INIT;
    grid = new char*[height];
    visible = new char*[height];
    // For every row, create the array for that row
    for (int i = 0; i < height; i++) {
        grid[i] = new char[width];
        visible[i] = new char[width];
    }
    char letter = 'A';
    // Guarantee pairs of characters in the grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = letter;
            // Everything's invisible at first
            visible[i][j] = '_';
            // Every other iteration...
            if (j % 2 == 1) {
                letter++;
                if (letter > 'Z') {
                    letter = 'A';
                }
            }
        }
    }
    // Seed random number generator with time
    srand(time(0));
    // Randomize
    int otheri, otherj;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Pick a random spot in the grid
            otheri = rand() % height;
            otherj = rand() % width;
            // Swap grid[i][j] with grid[otheri][otherj]
            letter = grid[i][j];
            grid[i][j] = grid[otheri][otherj];
            grid[otheri][otherj] = letter;
        }
    }
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
    for (int i = 0; i < height; i++) {
        delete grid[i];
        delete visible[i];
    }
    delete grid;
    delete visible;
}
// TODO: Is the row/column valid?
// That is, is the row within the height, and is the column within the width?
// Return whether it is or isn't.
bool Model::valid(int row, int column) {
    return true;
}
bool Model::matched(int row, int column) {
    return true;
}
// TODO: Flip a cell
void Model::flip(int row, int col) {
	// If the row and column are not valid, break out and don't do anything
	if (!valid(row, col)) { return; }
	if ((row == lastrow) && (col == lastcolumn)) { return; }
	if ((row == prevrow) && (col == prevcol)) { return; }
	switch (state)
	{
	case NO_MATCH:
		visible[lastrow][lastcolumn] = '_';
		visible[prevrow][prevcol] = '_';
		lastrow = -1;
		lastcolumn = -1;
		prevrow = -1;
		prevcol = -1;
	case INIT:
		visible[row][col] = grid[row][col];
		lastrow = row;
		lastcolumn = col;
		state = FIRST;
		break;
	case FIRST:
		visible[row][col] = grid[row][col];
		prevrow = row;
		prevcol = col;
		if (grid[lastrow][lastcolumn] != grid[prevrow][prevcol])
		{
			state = NO_MATCH;
		}
		else
		{
			state = INIT;
		}
		break;
	}
}
    
    if (isOver) {
        // Set a nice game over message
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                visible[i][j] = '_';
            }
        }
        visible[2][3] = 'Y';
        visible[2][4] = 'O';
        visible[2][5] = 'U';
        visible[4][3] = 'W';
        visible[4][4] = 'I';
        visible[4][5] = 'N';
    }
    return isOver;
}
int Model::getWidth() {
    return width;
}
int Model::getHeight() {
    return height;
}
char Model::get(int row, int col) {
    return visible[row][col];
}
