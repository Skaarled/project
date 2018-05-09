#ifndef MODELS_H
#define MODELS_H
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <conio.h>
using namespace std;

string getKeyWord (int level);
void getSuggetion (string keyWord, string suggetWord[10]);
void findType (string keyWord, string *typeOfKeyWord);
void getWord(string keyWord, string *word);
int getPoint(int level);
string toUpperAnswer(string s);
void gotoXY(int x,int y);
void getRecomendationPoint (int level,int guessPoint[10]);
void setTextColor (int colorNumber);
void ShowCur(bool CursorVisibility);

#endif // MODELS_H
