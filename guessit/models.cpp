#include "models.h"

string getKeyWord (int level)
{
    char data[1000];
    string word;
    srand(time(NULL));
    int x=3+3*(level-1);
    int y=1+3*(level-1);
    int random=y+rand()%(x-y+1);
    ifstream infile;
    infile.open("keyWord.txt");
    while (random!=0)
        {
            infile.getline(data,1000);
            random--;
        }
    int i=0;
    while (data[i]!='$')
        {
            word=word+data[i];
            i++;
        }
    infile.close();
    return word;
}
void getRecomendationPoint (int level,int guessPoint[NUMBERGAME+1])
{
    int randomPoint,t=0;
    bool i[NUMBERGAME+1]; for (int tem=1;tem<=NUMBERGAME;tem++) i[tem]=false;
    srand(time(NULL));
    randomPoint=rand()%NUMBERGAME+1;
    for (int point=NUMBERGAME+1;;point=point+NUMBERGAME+1+(level-1)*5)
    {
        t++;
        if (t==NUMBERGAME+1)
            break;
        while (i[randomPoint]==true)
            randomPoint=rand()%NUMBERGAME+1;
        guessPoint[randomPoint]=point;
        i[randomPoint]=true;
    }
}
void getSuggetion (string keyWord, string suggetWord[NUMBERGAME+1])
{
    int test=0,i=1;
    for (int tem=0;tem<keyWord.size();tem++)
    {
        if (keyWord[tem]==':')
            test++;
        if (test==2&&keyWord[tem]!=':')
        {
            if (keyWord[tem]!=',')
                suggetWord[i]=suggetWord[i]+keyWord[tem];
            if (keyWord[tem]==',')
                i++;
        }
    }
}
void findType (string keyWord, string *typeOfKeyWord)
{
    int tem=0;
    while (keyWord[tem]!=':')
    {
        *typeOfKeyWord=*typeOfKeyWord+keyWord[tem];
        tem++;
    }
}
void getWord(string keyWord, string *word)
{
    int tem=0;
    while (keyWord[tem]!=':')
        tem++;
    tem++;
    while (keyWord[tem]!=':')
        {
            *word=*word+keyWord[tem];
            tem++;
        }
}
int getPoint(int level)
{
    if (level==1)
        return 450;
    if (level==2)
        return 630;
    if (level==3)
        return 810;
    if (level==4)
        return 990;
    if (level==5)
        return 1170;
    return 0;
}
string toUpperAnswer(string s)
{
    string str;
    for (int i=0;i<s.size();i++)
        if (s[i]!=' ')
                {
                    s[i]=toupper(s[i]);
                    str=str+s[i];
                }
    return str;
}
void gotoXY(int x,int y)
{
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
COORD position = {x,y} ;
SetConsoleCursorPosition(hStdout,position ) ;
}
void setTextColor(int colorNumber)
{
    HANDLE color;
    color= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color,colorNumber);
}
void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}


