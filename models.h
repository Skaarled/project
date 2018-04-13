#ifndef MODELS_H
#define MODELS_H
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;
string getKeyWord (int level);
void getSuggetion (string keyWord, string suggetWord[10]);
void findType (string keyWord, string *typeOfKeyWord);
void getWord(string keyWord, string *word);
int getPoint(int level);
string toUpperAnswer(string s);
void gotoXY(int x,int y);
void getPointOfRecomendation (int level,int pointForGuess[10]);


#endif // MODELS_H
