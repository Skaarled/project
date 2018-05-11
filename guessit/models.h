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
const int NUMBERGAME=9;
const int NORMALTEXT=15;
const int OPTIONTEXT=63;
const int GREENTEXT=10;
const int REDTEXT=12;
const int YELLOWTEXT=14;

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

