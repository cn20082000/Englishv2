#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

/*----------PRIVATE---------*/
void EX::_Read_Codemap() {
	fstream f;
	nUseQues = 0;
	f.open("Codemap.txt", ios::in | ios::binary);
	f.read(reinterpret_cast <char*> (&nQuestion), 4);
	for (int i = 0; i < nQuestion; ++i) {
		f.read(reinterpret_cast <char*> (&cm[i].nMeans), 4);
		f.read(reinterpret_cast <char*> (&cm[i].nWord), 4);
		f.read(reinterpret_cast <char*> (&cm[i].nLog), 4);
		f.read(reinterpret_cast <char*> (&cm[i].bCheck), 1);
		cm[i].bCheckNow = false;
		if (cm[i].bCheck) ++nUseQues;
	}
	f.close();
}
void EX::_Write_Codemap() {
	fstream f;
	f.open("Codemap.txt", ios::out | ios::binary);
	f.write(reinterpret_cast <char*> (&nQuestion), 4);
	for (int i = 0; i < nQuestion; ++i) {
		f.write(reinterpret_cast <char*> (&cm[i].nMeans), 4);
		f.write(reinterpret_cast <char*> (&cm[i].nWord), 4);
		f.write(reinterpret_cast <char*> (&cm[i].nLog), 4);
		f.write(reinterpret_cast <char*> (&cm[i].bCheck), 1);
	}
	f.close();
}
void EX::_Question(int nCount) {
	nSerial = _Random(nQuestion - nCount - nUseQues + 1);
	for (int i = 0; i <= nSerial; ++i) {
		if (cm[i].bCheck || cm[i].bCheckNow) ++nSerial;
	}

	fstream f;
	f.open("Words.txt", ios::in | ios::binary);
	f.seekg(sizeof(q.sWord) * cm[nSerial].nWord, ios::beg);
	f.read(reinterpret_cast <char*> (q.sWord), sizeof(q.sWord));
	f.close();

	f.open("Means.txt", ios::in | ios::binary);
	f.seekg(sizeof(q.sMeansCorrect) * cm[nSerial].nMeans, ios::beg);
	f.read(reinterpret_cast <char*> (q.sMeansCorrect), sizeof(q.sMeansCorrect));
	for (int i = 0, nMeansIncorrect = 0; i < 3; ++i) {
		int nTemp = _Random(nMeansIncorrect + 1, nQuestion - 2 + i);
		if (nMeansIncorrect < nSerial && nTemp >= nSerial) nMeansIncorrect = nTemp + 1;
		else nMeansIncorrect = nTemp;
		f.seekg(sizeof(q.sMeansCorrect) * cm[nMeansIncorrect].nMeans, ios::beg);
		f.read(reinterpret_cast <char*> (q.sMeansIncorrect[i]), sizeof(q.sMeansCorrect));
	}
	f.close();

	q.nCorrect = _Random(4);
	cm[nSerial].bCheckNow = true;
}
void EX::_WriteLog() {
	for (int i = 0; i < nQuestion; ++i) {
		if (cm[i].nLog > 0) --cm[i].nLog;
		if (cm[i].nLog == 10) cm[i].bCheck = true;
		if (cm[i].nLog == 0) cm[i].bCheck = false;
	}
}
/*----------PUBLIC----------*/
bool EX::_Main() {
	_Read_Codemap();

	int nCount = 1;
	int nCorrect = 0;
	time_t tStart = _GetSecond();
	for (char cChoice = 'y'; (cChoice != 'x' && cChoice != 'X') && nCount <= nQuestion; ++nCount) {
		_Clrscr();
		_Question(nCount);

		gotoxy(100, 0);
		cout << "EXIT[x]";
		gotoxy(0, 1);
		cout << "Question " << nCount << ": ";
		cout << "Meaning of \"" << q.sWord << "\" is?\n";
		char i = 0;
		for (i = 'A'; i < 65 + q.nCorrect; ++i)
			cout << "\t" << i << ". " << q.sMeansIncorrect[i - 65] << ".\n";
		cout << "\t" << i++ << ". " << q.sMeansCorrect << ".\n";
		for (; i < 69; ++i)
			cout << "\t" << i << ". " << q.sMeansIncorrect[i - 66] << ".\n";

		cChoice = 5;
		int nQuaTamBaBan = 0;
		while (!((cChoice >= 'A' && cChoice <= 'D') || (cChoice >= 'a' && cChoice <= 'd') || (cChoice == 'x' || cChoice == 'X'))) {
			cout << "Your choice is: ";
			cin >> cChoice;
			++nQuaTamBaBan;
			if (nQuaTamBaBan == 3) {
				cout << "Den gio di ngu roi thang loz!!!\n";
				_Delay(100);
				cout << "Ket qua cua may se deo duoc luu!!!\n";
				_Delay(100);
				cout << "Tu dong exit sau 3s...";
				_Delay(3000);
				return 0;
			}
		}

		if (cChoice == 'x' || cChoice == 'X') break;
		if (cChoice == 65 + q.nCorrect || cChoice == 97 + q.nCorrect) {
			cout << "Correct!!!\n";
			++nCorrect;
			// cộng 2 vì ở hàm WriteLog sẽ trừ tất cả đi 1
			cm[nSerial].nLog += 2;
			_Delay(1000);
		}
		else {
			cout << "Incorrect!!! The correct answer is " << static_cast<char>(65 + q.nCorrect) << "\n";
			_Delay(3000);
		}
	}
	_Clrscr();
	gotoxy(24, 1);
	cout << "SUMMARY RECORD\n";
	cout << "\tYour correct answers:\t\t" << nCorrect << "\n";
	_Delay(200);
	cout << "\tYour wrong answers:\t\t" << nCount - nCorrect - 1 << "\n";
	_Delay(200);
	cout << "\tTotal:\t\t\t\t" << nCount - 1 << "\n";
	_Delay(200);
	cout << "\tYour performace:\t\t" << static_cast<int> (nCorrect / (static_cast<float>(_GetSecond() - tStart) / 60)) << " corrects/min\n";
	_Delay(200);
	cout << "\tKeep on trying! Nah!\n\t";
	_WriteLog();
	_Write_Codemap();
	_Pause();
	return 0;
}