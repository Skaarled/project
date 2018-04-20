#include "view.h"

void printBackground ()
{
    gotoXY(0,2);
    cout<<(char) 201;
    for (int tem=1;tem<70;tem++)
    {
        gotoXY(tem,2);
        cout<<(char) 205;
        gotoXY(tem,4);
        cout<<(char) 205;
        gotoXY(tem,6);
        cout<<(char) 205;
        gotoXY(tem,16);
        cout<<(char) 205;
    }
    gotoXY(70,2);
    cout<<(char) 187;
    for (int tem=1;tem<14;tem++)
    {
        gotoXY(0,tem+2);
        cout<<(char) 186;
        if (tem>2)
        {
            gotoXY(55,tem+2);
            cout<<(char) 186;
            gotoXY(8,tem+2);
            cout<<(char) 186;
        }
        gotoXY(70,tem+2);
        cout<<(char) 186;
    }
    gotoXY(70,16);
    cout<<(char) 188;
    gotoXY(0,16);
    cout<<(char) 200;
    gotoXY(8,4);
    cout<<(char) 203;
    gotoXY(8,6);
    cout<<(char) 206;
    gotoXY(55,4);
    cout<<(char) 203;
    gotoXY(55,6);
    cout<<(char) 206;

    gotoXY(0,4);
    cout<<(char) 204;
    gotoXY(0,6);
    cout<<(char) 204;

    gotoXY(70,4);
    cout<<(char) 185;
    gotoXY(70,6);
    cout<<(char) 185;


    gotoXY(8,16);
    cout<<(char) 202;
    gotoXY(55,16);
    cout<<(char) 202;
}
void printDetails (int level,string typeOfWord, string word, int pointForGuess[10], bool boolPointForGuess[10], string suggetWord[10], bool boolSuggetWord[10],int pointLevel, bool boolPoint[10])
{
    printBackground();
    HANDLE color;
    color= GetStdHandle(STD_OUTPUT_HANDLE);
    gotoXY(32,0);
    cout<<"VONG: "<<level<<endl;
    gotoXY(4-(typeOfWord.size())/2,5);
    SetConsoleTextAttribute(color,15);
    cout<<typeOfWord;
    gotoXY(27-(word.size())/2,3);
    SetConsoleTextAttribute(color,11);
    cout<<"   "<<word<<"   ";
    SetConsoleTextAttribute(color,15);
    gotoXY(58,5);
    cout<<"Diem: ";
    SetConsoleTextAttribute(color,12);
    cout<<pointLevel;
    SetConsoleTextAttribute(color,15);
    cout<<endl;
    gotoXY(28,5);
    cout<<"GOI Y";
    SetConsoleTextAttribute(color,14);
    for (int i=0;i<=9;i++)
        {
            gotoXY(30-(suggetWord[i].size())/2,6+i);
            if (boolSuggetWord[i]==true)
                cout<<suggetWord[i]<<endl;
            else
                cout<<endl;
        }
    SetConsoleTextAttribute(color,15);
    cout<<endl;
    int pointForGuessTem[10];
    for (int i=1;i<=9;i++)
    {
        pointForGuessTem[i]=pointForGuess[i];
        gotoXY(58,6+i);
        cout<<"So "<<i;
        if (boolPointForGuess[i]==true)
            cout<<": "<<pointForGuess[i]<<endl;
        else
            cout<<endl;
    }
    sort(pointForGuessTem+1,pointForGuessTem+10);
    for (int i=1;i<=9;i++)
    {
        gotoXY(3,i+6);
        if (boolPoint[pointForGuessTem[i]]==false)
        {
            SetConsoleTextAttribute(color,10);
            cout<<pointForGuessTem[i]<<endl;
        }
        else
        {
            SetConsoleTextAttribute(color,12);
            cout<<pointForGuessTem[i]<<endl;
        }
    }
    SetConsoleTextAttribute(color,15);
    cout<<endl;
}

