#include <iostream>
#include <Windows.h>
#include <time.h>
#include "Header.h"

using namespace std;

void _Clrscr() {
	system("cls");
}
void _Pause() {
	system("pause");
}
int _Random(int a) {
	//0 <= random < a
	srand(time(NULL));
	return rand() % a;
}
int _Random(int a, int b) {
	// a <= random < b;
	srand(time(NULL));
	return rand() % (b - a) + a;
}
void _Delay(int a) {
	Sleep(a);
}
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
time_t _GetSecond() {
	return time(NULL);
}