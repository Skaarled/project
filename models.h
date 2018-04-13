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
string keyWord (int level);
void suggetion (string keyWord, string suggetWord[10]);
void type (string keyWord, string *typeOfKeyWord);
void toWord(string keyWord, string *word);
int point(int level);
string toupperAnswer(string s);
void gotoXY(int x,int y);
void pointForRecomendation (int level,int pointForGuess[10]);


#endif // MODELS_H
