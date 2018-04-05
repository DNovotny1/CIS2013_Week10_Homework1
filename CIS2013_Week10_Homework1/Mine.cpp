#include <iostream>
using namespace std;

void drawStart(int x, int y) {


	/*for (int x = 0; x < 10; x++) {
	for (int y = 0; y < 10; y++) {
	char *boardPoint;
	boardPoint = new char[xgrid][ygrid];
	}
	}*/

	//creates dynamically allocated multidimensional array for board
	char** board = new char*[y];
	for (int i = 0; i < y; ++i)
		board[i] = new char[x];

	//assigns same char to every address in array
	for (int a = 0; a < y; a++) {
		for (int b = 0; b < x; b++) {
			board[a][b] = '^';
		}
	}

	//writes array to board- or breaks everything
	cout << "   1 2 3 4 5 6 7 8 9 10\n";
	for (int a = 0; a < x; a++) {
		if (a < 9) {
			cout << " ";
		}
		cout << a + 1;

		for (int b = 0; b < y; b++) {
			//writes board array
			cout << " " << board[a][b];
		}
		cout << endl;
	}

	//clean up
	for (int i = 0; i < y; ++i) {
		delete[] board[i];
	}
	delete[] board;
	
}

int main() {
	char keepGoing = 'y';
	int gridX, gridY;
	bool ingo = true;

	while (keepGoing == 'y') {
		//gets grid size from user
		cout << "How big of a grid would you like to play on?";
		cin >> gridX >> gridY;
		/*gridX = gridX - 1;
		gridY = gridY - 1;*/
		drawStart(gridX, gridY);



	}
	return 0;
}
