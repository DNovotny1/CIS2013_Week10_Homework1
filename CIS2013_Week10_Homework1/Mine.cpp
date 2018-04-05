#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void drawStart(int x, int y, int bomb) {


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

	//creates dynamically allocated multidimensional array for board
	char** key = new char*[y];
	for (int i = 0; i < y; ++i)
		key[i] = new char[x];

	//assigns same char to every address in array
	for (int a = 0; a < y; a++) {
		for (int b = 0; b < x; b++) {
			board[b][a] = '.';
		}
	}

	//writes array to board- or breaks everything
	cout << "    ";
	for (int i = 1; i <= y;i++) {
		if (i > 9) {
			cout << i << " ";
		}
		else { cout << i << "  "; }
	}
	cout << endl;

	for (int a = 0; a < x; a++) {
		if (a < 9) {
			cout << " ";
		}
		cout << a + 1;

		for (int b = 0; b < y; b++) {
			//writes board array
			cout << "  " << board[a][b];
		}
		cout << endl;
	}

	//generates key 
	for (int a = 0; a < y; a++) {
		for (int b = 0; b < x; b++) {
			key[b][a] = '0';
		}
	}
	//adds random bombs
	for (int i = 0; i < bomb; i++) {
		int num1 = rand() % x;
		int num2 = rand() % y;
		key[num1][num2] = '1';

	}

	//gets user selection 
	char userIn = '-';
	int xin, yin;
	while (userIn != 'x') {
		cout << "\nPress 's' to flag a location with no bomb, 'd' to dig up a square, or 'x' to exit.";
		cin >> userIn;
		if (userIn == 'x') {
			exit;
		}
		else if (userIn == 's') {
			cout << "\nEnter coordinates ";
			cin >> xin >> yin;
			board[xin-1][yin-1] = '@';
		}

		else if (userIn == 'd') {
			cout << "\nEnter coordinates ";
			cin >> xin >> yin;
			if (key[xin-1][yin-1] == 0) {
				
				board[xin-1][yin-1] = '-';
			}
			else if (key[xin - 1][yin - 1] == 1) {

				board[xin - 1][yin - 1] = '*';
				cout << "You died!";
				exit;
			}
		}

		//writes board again
		cout << "\n    ";
		for (int i = 1; i <= y; i++) {
			if (i > 9) {
				cout << i << " ";
			}
			else { cout << i << "  "; }
		}
		cout << endl;

		for (int a = 0; a < x; a++) {
			if (a < 9) {
				cout << " ";
			}
			cout << a + 1;

			for (int b = 0; b < y; b++) {
				//writes board array
				cout << "  " << board[a][b];
			}
			cout << endl;
		}

	}


	////clean up
	//for (int a = 0; a < y; a++) {
	//	for (int b = 0; b < x; b++) {
	//		delete[] board[a][b];
	//	}
	//	//delete[] board[a];
	//}


}

int main() {
	char keepGoing = 'y';
	int gridX, gridY, bombs;
	bool ingo = true;

	while (keepGoing == 'y') {
		//gets grid size from user
		cout << "How big of a grid would you like to play on?";
		cin >> gridX >> gridY;
		/*gridX = gridX - 1;
		gridY = gridY - 1;*/
		cout << "\nHow many bombs should there be?";
		cin >> bombs;
		drawStart(gridX, gridY, bombs);



	}
	return 0;
}
