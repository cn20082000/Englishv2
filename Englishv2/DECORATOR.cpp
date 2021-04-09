#include <iostream>
#include "Header.h"

#define cast_time 16

using namespace std;

/*
186 thanh doc
205 thanh ngang
187 goc tren phai
188 goc duoi phai
200 goc duoi trai
201 goc tren trai
196 vach ngang
174 dau sieu nho
175 dau sieu lon
*/

void DECORATOR::_Welcome() {
	// Vẽ khung 100x20
	gotoxy(2, 1);
	cout << static_cast<char> (201);
	_Delay(cast_time);
	for (int i = 2; i < 20; ++i, _Delay(cast_time)) {
		gotoxy(2, i);
		cout << static_cast<char> (186);
		gotoxy(i + 1, 1);
		cout << static_cast<char> (205);
		if (i > 17) {
			gotoxy(i - 15, 17);
			cout << static_cast<char> (196);
		}
	}
	gotoxy(2, 20);
	cout << static_cast<char> (200);
	gotoxy(21, 1);
	cout << static_cast<char> (205);
	gotoxy(5, 17);
	cout << static_cast<char> (196);
	_Delay(cast_time);
	for (int i = 22; i < 101; ++i, _Delay(cast_time)) {
		gotoxy(i - 19, 20);
		cout << static_cast<char> (205);
		gotoxy(i, 1);
		cout << static_cast<char> (205);
		gotoxy(i - 16, 17);
		cout << static_cast<char> (196);
	}
	gotoxy(82, 20);
	cout << static_cast<char> (205);
	gotoxy(101, 1);
	cout << static_cast<char> (187);
	gotoxy(85, 17);
	cout << static_cast<char> (196);
	_Delay(cast_time);
	for (int i = 2; i < 20; ++i, _Delay(cast_time)) {
		gotoxy(81 + i, 20);
		cout << static_cast<char> (205);
		gotoxy(101, i);
		cout << static_cast<char> (186);
		if (i < 17) {
			gotoxy(84 + i, 17);
			cout << static_cast<char> (196);
		}
	}
	gotoxy(101, 20);
	cout << static_cast<char> (188);
	_Delay(cast_time);

	//	Vẽ lời chào
		//	Vẽ mấy cái râu ria
	for (int i = 0; i < 7; ++i, _Delay(cast_time)) {
		gotoxy(4 + 2 * i, 2 + i);
		cout << static_cast<char> (175) << static_cast<char> (175);
		gotoxy(99 - 2 * i, 2 + i);
		cout << static_cast<char> (174) << static_cast<char> (174);
		gotoxy(4 + 2 * i, 16 - i);
		cout << static_cast<char> (175) << static_cast<char> (175);
		gotoxy(99 - 2 * i, 16 - i);
		cout << static_cast<char> (174) << static_cast<char> (174);
	}
	gotoxy(18, 9);
	cout << static_cast<char> (175) << static_cast<char> (175);
	gotoxy(85, 9);
	cout << static_cast<char> (174) << static_cast<char> (174);
	_Delay(cast_time);
	//	Vẽ chữ Welcome
	{
		const char sWel[11] = "WELCOME TO";
		const char sName[19] = "ENGLISH CONTEST V2";
		gotoxy(47, 8);
		for (int i = 0; i < 10; ++i, _Delay(cast_time))
			cout << sWel[i];
		gotoxy(43, 9);
		for (int i = 0; i < 18; ++i, _Delay(cast_time))
			cout << sName[i];
	}
	// Vẽ credit
	{
		const char sAuthor[22] = "Written by Cong Chinh";
		const char sDate[25] = "Release date: 09/10/2019";
		gotoxy(3, 18);
		for (int i = 0; i < 21; ++i) {
			if (sAuthor[i] >= 65 && sAuthor[i] <= 90) {
				for (int j = 0; j < _Random(5, 15); ++j) {
					cout << static_cast<char> (_Random(65, 91));
					_Delay(cast_time / 2);
					cout << '\b';
				}
			}
			if (sAuthor[i] >= 97 && sAuthor[i] <= 122) {
				for (int j = 0; j < _Random(5, 15); ++j) {
					cout << static_cast<char> (_Random(97, 123));
					_Delay(cast_time / 2);
					cout << '\b';
				}
			}
			cout << sAuthor[i];
		}
		gotoxy(3, 19);
		for (int i = 0; i < 24; ++i) {
			if (sDate[i] >= 65 && sDate[i] <= 90) {
				for (int j = 0; j < _Random(5, 15); ++j) {
					cout << static_cast<char> (_Random(65, 91));
					_Delay(cast_time / 2);
					cout << '\b';
				}
			}
			if (sDate[i] >= 97 && sDate[i] <= 122) {
				for (int j = 0; j < _Random(5, 15); ++j) {
					cout << static_cast<char> (_Random(97, 123));
					_Delay(cast_time / 2);
					cout << '\b';
				}
			}
			if (sDate[i] >= 48 && sDate[i] <= 57) {
				for (int j = 0; j < _Random(5, 15); ++j) {
					cout << static_cast<char> (_Random(48, 58));
					_Delay(cast_time / 2);
					cout << '\b';
				}
			}
			if (sDate[i] >= 58 && sDate[i] <= 64) {
				for (int j = 0; j < _Random(5, 15); ++j) {
					cout << static_cast<char> (_Random(58, 65));
					_Delay(cast_time / 2);
					cout << '\b';
				}
			}
			if (sDate[i] >= 33 && sDate[i] <= 47) {
				for (int j = 0; j < _Random(5, 15); ++j) {
					cout << static_cast<char> (_Random(33, 48));
					_Delay(cast_time / 2);
					cout << '\b';
				}
			}
			cout << sDate[i];
		}
	}
	// Vẽ Press
	_Delay(500);
	gotoxy(35, 10);
	_Pause();
	_Clrscr();
}