#include <iostream>

using namespace std;
const int mapHeight = 6;
const int mapWidth = 6;
int chesBoard[mapHeight][mapWidth] = { { 0,1,0,1,0,1 },
{ 1,0,1,0,1,0 },
{ 0,1,0,1,0,1 },
{ 1,0,1,0,1,0 },
{ 0,1,0,1,0,1 },
{ 1,0,1,0,1,0 }
};
int chessCords[mapHeight][mapWidth];

int hourseX = 3;
int hourseY = 3;
static int score = 0;
void setHourse(int y, int x) {
	  // "-" + "-" = "+"
	if (hourseX + x < 0) x = 0;
	if (hourseY + y < 0) y = 0;

	if (hourseX + x > mapHeight) x = 0;
	if (hourseY + y > mapWidth) y = 0;

	if (x != 0 && y != 0) {
		hourseY = hourseY - y;
		hourseX = hourseX - x;
		chessCords[hourseY - y][hourseX - x] = 1;
	}
}
int move() {
	if (chessCords[hourseY - 2][hourseX - 1] == 0) { //top left
		setHourse(2, 1);
	}
	else if (chessCords[hourseY - 2][hourseX + 1] == 0) { //top right
		setHourse(2, -1);
	}
	else if (chessCords[hourseY - 1][hourseX + 2] == 0) { //right top
		setHourse(1, -2);
	}
	else if (chessCords[hourseY + 1][hourseX + 2] == 0) { //right bottom
		setHourse(-1, -2);
	}
	else if (chessCords[hourseY + 2][hourseX + 1] == 0) { //lower right
		setHourse(-2, -1);
	}
	else if (chessCords[hourseY + 2][hourseX - 1] == 0) { //lower left
		setHourse(-2, 1);
	}
	else if (chessCords[hourseY - 1][hourseX - 2] == 0) { //left top
		setHourse(1, 2);
	}
	else if (chessCords[hourseY + 1][hourseX - 2] == 0) { //left bottom
		setHourse(-1, 2);
	}
	else{
		cout << endl << score << endl;
		return 0;
	}
	score++;
	move();
}
void draw() {
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < 6; j++) {
			if (chesBoard[i][j] == 0) {
				cout << "#";
			}
			else if (chesBoard[i][j] == 1) {
				cout << "0";
			}
		}
		cout << endl;
	}
}
void main()
{
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			chessCords[i][j] = 0;
		}
	}
	draw();
	while (true) {
		move();
	}
	system("pause");
}
