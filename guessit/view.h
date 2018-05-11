#ifndef VIEW_H
#define VIEW_H
#include "models.h"

void printBackground ();
void printDetails (int level,string typeOfKeyWord, string word, int guessPoint[NUMBERGAME+1], bool boolGuessPoint[NUMBERGAME+1],
                string suggetWord[NUMBERGAME+1], bool boolSuggetWord[NUMBERGAME+1],int pointLevel, bool boolPoint[NUMBERGAME+1]);
void printStartScreen ();
void printGuessIt(bool isChar219, int amount);

#endif // VIEW_H


