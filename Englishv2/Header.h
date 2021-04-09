#pragma once
/*----------STRUCT---------*/
class CODEMAP {
public:
	int nMeans;
	int nWord;
	int nLog;
	bool bCheck;
	bool bCheckNow;
};
class QUESTION {
public:
	char sWord[20];
	char sMeansCorrect[200];
	char sMeansIncorrect[3][200];
	char nCorrect;
};
/*----------CLASS----------*/
class EX {
private:
	CODEMAP cm[1000];
	QUESTION q;
	int nQuestion;
	int nSerial;
	int nUseQues;

	void _Read_Codemap();
	void _Write_Codemap();
	void _Question(int nCount);
	void _WriteLog();
public:
	bool _Main();
};
class DECORATOR {
public:
	void _Welcome();
};
/*---------SUPPORT---------*/
void _Clrscr();
void _Pause();
int _Random(int a);
int _Random(int a, int b);
void _Delay(int a);
void gotoxy(int x, int y);
time_t _GetSecond();