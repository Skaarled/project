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
    gotoXY(28,0);
    cout<<"VONG: "<<level<<endl;
    gotoXY(4-(typeOfWord.size())/2,5);
    setTextColor(15);
    cout<<typeOfWord;
    gotoXY(27-(word.size())/2,3);
    setTextColor(10);
    cout<<"   "<<word<<"   ";
    setTextColor(15);
    gotoXY(58,5);
    cout<<"Diem: ";
    setTextColor(12);
    cout<<pointLevel;
    setTextColor(15);
    cout<<endl;
    gotoXY(28,5);
    cout<<"GOI Y";
    setTextColor(14);
    for (int i=0;i<=9;i++)
        {
            gotoXY(30-(suggetWord[i].size())/2,6+i);
            if (boolSuggetWord[i]==true)
                cout<<suggetWord[i]<<endl;
            else
                cout<<endl;
        }
    setTextColor(15);
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
            setTextColor(10);
            cout<<pointForGuessTem[i]<<endl;
        }
        else
        {
            setTextColor(12);
            cout<<pointForGuessTem[i]<<endl;
        }
    }
    setTextColor(15);
    cout<<endl;
}

void printStartScreen ()
{
    label:ShowCur(false);
    string startScreenOptions[3]={"New game","Help","Exit"};
    bool isRunning = true, isGetOption=false;
    int getOption=99;
    if (isRunning)
        {
            setTextColor(63);
            gotoXY(20,10);
            cout<<startScreenOptions[0];
            setTextColor(15);
            gotoXY(20,11);
            cout<<startScreenOptions[1];
            gotoXY(20,12);
            cout<<startScreenOptions[2];
            while (!isGetOption)
            {
                if (kbhit())
                {
                    char c=getch();
                    if (c==13)
                        {
                            if (getOption%3==0)
                                isGetOption=true;
                            if (getOption%3==1)
                            {
                                system("cls");
                                cout<<"hihi";
                                cin.get();
                                system("cls");
                                goto label;
                            }
                            if (getOption%3==2)
                                exit(0);
                        }
                    if (c==-32)
                    {
                        c=getch();
                        if (c==80)
                            {
                                setTextColor(15);
                                gotoXY(20,10+getOption%3);
                                cout<<startScreenOptions[getOption%3];
                                getOption++;
                                setTextColor(63);
                                gotoXY(20,10+getOption%3);
                                cout<<startScreenOptions[getOption%3];
                                setTextColor(15);
                            }
                        else
                            if (c==72)
                                {
                                    setTextColor(15);
                                    gotoXY(20,10+getOption%3);
                                    cout<<startScreenOptions[getOption%3];
                                    getOption--;
                                    setTextColor(63);
                                    gotoXY(20,10+getOption%3);
                                    cout<<startScreenOptions[getOption%3];
                                    setTextColor(15);
                                }
                    }
                }
            }
        }
        system("cls");
        setTextColor(15);
}
