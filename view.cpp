#include "view.h"
void view (string typeOfWord, string word, int pointForGuess[10], bool boolPointForGuess[10], string suggetWord[10], bool boolSuggetWord[10],int pointLevel, bool boolPoint[10])
{
    HANDLE color;
    color= GetStdHandle(STD_OUTPUT_HANDLE);
    gotoXY(0,1);
    SetConsoleTextAttribute(color,15);
    cout<<typeOfWord;
    gotoXY(23-(word.size())/2,1);
    SetConsoleTextAttribute(color,43);
    cout<<"   "<<word<<"   ";
    SetConsoleTextAttribute(color,15);
    gotoXY(48,1);
    cout<<"Diem con lai: ";
    SetConsoleTextAttribute(color,12);
    cout<<pointLevel;
    SetConsoleTextAttribute(color,15);
    cout<<endl;
    gotoXY(24,3);
    cout<<"GOI Y";
    SetConsoleTextAttribute(color,43);
    for (int i=0;i<=9;i++)
        {
            gotoXY(27-(suggetWord[i].size())/2,3+i);
            if (boolSuggetWord[i]==true)
                cout<<suggetWord[i]<<endl;
            else
                cout<<endl;
        }
    SetConsoleTextAttribute(color,15);
    cout<<endl;
    int pointForGuessTEM[10];
    for (int i=1;i<=9;i++)
    {
        pointForGuessTEM[i]=pointForGuess[i];
        gotoXY(6,i+3);
        cout<<"|";
        gotoXY(47,i+3);
        cout<<"|";
        gotoXY(50,3+i);
        cout<<"So "<<i;
        if (boolPointForGuess[i]==true)
            cout<<": "<<pointForGuess[i]<<endl;
        else
            cout<<endl;
    }
    sort(pointForGuessTEM+1,pointForGuessTEM+10);
    for (int i=1;i<=9;i++)
    {
        gotoXY(2,i+3);
        if (boolPoint[pointForGuessTEM[i]]==false)
        {
            SetConsoleTextAttribute(color,10);
            cout<<pointForGuessTEM[i]<<endl;
        }
        else
        {
            SetConsoleTextAttribute(color,12);
            cout<<pointForGuessTEM[i]<<endl;
        }
    }
    SetConsoleTextAttribute(color,15);
    cout<<endl;
}

