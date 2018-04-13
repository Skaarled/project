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
string makeKeyWord (int level);
void makeSuggetion (string keyWord, string suggetWord[10]);
void findType (string keyWord, string *typeOfKeyWord);
void makeWord(string keyWord, string *word);
int makePoint(int level);
string toUpperAnswer(string s);
void gotoXY(int x,int y);
void makePointOfRecomendation (int level,int pointForGuess[10]);


#endif // MODELS_H
