//============================================================================
// Name        : Snake.cpp
// Author      : Kristiyan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ncurses.h>
#include <unistd.h>

bool gameOver;

const int width = 20;
const int height = 20;

int x, y, fruitX, fruitY, score;

int tailX[100], tailY[100];
int nTail = 0;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Drow() {
	system("clear");

	for (int i = 0; i < width + 2; i++) {
		std::cout << "#";
	}

	std::cout << "\n";

	for (int i = 0; i < height; i++) {
		std::cout << "#";
			for (int j = 1; j <= width; j++) {
				if (i == y && j == x) {
					std::cout << "O";

				}

				else if (i == fruitY && j == fruitX) {
					std::cout << "F";
				} else {
					bool print = false;

					for (int k = 0; k < nTail; k++) {
						if (tailX[k] == j && tailY[k] == i) {
							std::cout << "o";
							print = true;
						}
					}
					if (!print) {
					std::cout << " ";
					}
				}
			}

			std::cout << "#" << "\n";
	}

	for (int i = 0; i < width + 2; i++) {
		std::cout << "#";
	}

	std::cout << "\n" << "Score: " << score << "\n";

}

void Input() {
	switch(getchar()) {
	case 'a':
			dir = LEFT;
			break;
	case 's':
			dir = DOWN;
			break;
	case 'd':
			dir = RIGHT;
			break;
	case 'w':
			dir = UP;
			break;
	case 'x':
			gameOver = true;
			break;
	}
}

void Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prevX2 = 0;
	int prevY2 = 0;

	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++) {
		prevX2 = tailX[i];
		prevY2 = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX =  prevX2;
		prevY = prevY2;
	}

	switch(dir) {
	case STOP:
			break;
	case LEFT:
		x--;
			break;
	case RIGHT:
		x++;
			break;
	case UP:
		y--;
			break;
	case DOWN:
		y++;
			break;
	}

	if (x > width || x < 1 || y > height || y < 1) {
		system("clear");
		std::cout << "Game Over!!!";
		gameOver = true;
	}

	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y) {
			system("clear");
			std::cout << "Game Over!!!";
			gameOver = true;
		}
	}

	if (x == fruitX && y == fruitY) {
		score += 10;

		fruitX = rand() % width;
		fruitY = rand() % height;

		nTail++;
	}
}

int main() {
	Setup();

	while(!gameOver) {
		Drow();
		Input();
		Logic();

		usleep(1000);
	}

	return 0;
}
