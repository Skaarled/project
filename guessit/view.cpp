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
void printDetails (int level,string typeOfKeyWord, string word, int guessPoint[NUMBERGAME+1], bool boolGuessPoint[NUMBERGAME+1],
                string suggetWord[NUMBERGAME+1], bool boolSuggetWord[NUMBERGAME+1],int pointLevel, bool boolPoint[NUMBERGAME+1])
{
    gotoXY(28,0);
    cout<<"VONG: "<<level<<endl;
    gotoXY(4-(typeOfKeyWord.size())/2,5);
    setTextColor(NORMALTEXT);
    cout<<typeOfKeyWord;
    gotoXY(25-(word.size())/2,3);
    setTextColor(11);
    cout<<"   "<<word<<"   ";
    setTextColor(NORMALTEXT);
    gotoXY(58,5);
    cout<<"Diem: ";
    setTextColor(REDTEXT);
    cout<<pointLevel;
    setTextColor(NORMALTEXT);
    cout<<endl;
    gotoXY(28,5);
    cout<<"GOI Y";
    setTextColor(YELLOWTEXT);
    for (int i=0;i<=NUMBERGAME;i++)
        {
            gotoXY(30-(suggetWord[i].size())/2,6+i);
            if (boolSuggetWord[i]==true)
                cout<<suggetWord[i]<<endl;
            else
                cout<<endl;
        }
    setTextColor(NORMALTEXT);
    cout<<endl;
    int guessPointTem[NUMBERGAME+1];
    for (int i=1;i<=NUMBERGAME;i++)
    {
        guessPointTem[i]=guessPoint[i];
        gotoXY(58,6+i);
        cout<<"So "<<i;
        if (boolGuessPoint[i]==true)
            cout<<": "<<guessPoint[i]<<endl;
        else
            cout<<endl;
    }
    sort(guessPointTem+1,guessPointTem+NUMBERGAME+1);
    for (int i=1;i<=NUMBERGAME;i++)
    {
        gotoXY(3,i+6);
        if (boolPoint[guessPointTem[i]]==false)
        {
            setTextColor(GREENTEXT);
            cout<<guessPointTem[i]<<endl;
        }
        else
        {
            setTextColor(REDTEXT);
            cout<<guessPointTem[i]<<endl;
        }
    }
    setTextColor(NORMALTEXT);
    cout<<endl;
}
void printGuessIt(bool isChar219, int amount)
{
    if (isChar219==true)
        for (int temp=1;temp<=amount;temp++)
            cout<<(char)219;
    else
        for (int temp=1;temp<=amount;temp++)
            cout<<" ";
}
void printStartScreen ()
{
    bool isLoop=false;
    label:ShowCur(false);
    cout<<" "; printGuessIt(true,9);
    cout<<endl; printGuessIt(true,2); printGuessIt(false,7); printGuessIt(true,2);
    cout<<endl; printGuessIt(true,2); printGuessIt(false,12);printGuessIt(true,2);printGuessIt(false,5);
                printGuessIt(true,2);printGuessIt(false,3);printGuessIt(true,8);printGuessIt(false,4);
                printGuessIt(true,7);printGuessIt(false,4);printGuessIt(true,7);
    cout<<endl; printGuessIt(true,2); printGuessIt(false,12); printGuessIt(true,2); printGuessIt(false,5);
                printGuessIt(true,2); printGuessIt(false,2); printGuessIt(true,2); printGuessIt(false,6);
                printGuessIt(true,2); printGuessIt(false,2); printGuessIt(true,2); printGuessIt(false,9); printGuessIt(true,2);
    cout<<endl; printGuessIt(true,2); printGuessIt(false,6); printGuessIt(true,4); printGuessIt(false,2);
                printGuessIt(true,2); printGuessIt(false,5); printGuessIt(true,2); printGuessIt(false,2);
                printGuessIt(true,9); printGuessIt(false,4); printGuessIt(true,6); printGuessIt(false,5); printGuessIt(true,6);
    cout<<endl; printGuessIt(true,2); printGuessIt(false,7); printGuessIt(true,2); printGuessIt(false,3);
                printGuessIt(true,2); printGuessIt(false,5); printGuessIt(true,2); printGuessIt(false,2);
                printGuessIt(true,2); printGuessIt(false,16); printGuessIt(true,2); printGuessIt(false,9); printGuessIt(true,2);
    cout<<endl; printGuessIt(false,1); printGuessIt(true,9); printGuessIt(false,5); printGuessIt(true,7);
                printGuessIt(false,4); printGuessIt(true,8); printGuessIt(false,3); printGuessIt(true,7);
                printGuessIt(false,4); printGuessIt(true,7);
    cout<<endl<<endl;
    if (isLoop==false)
    {
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        Sleep(200);
        printGuessIt(false,17);
        Sleep(200);
        printGuessIt(true,3);
        Sleep(200);
        printGuessIt(false,3);
        Sleep(200);
        printGuessIt(true,3);
        Sleep(200);
        printGuessIt(false,3);
        Sleep(200);
        printGuessIt(true,3);
        Sleep(200);
        printGuessIt(false,3);
        Sleep(200);
        printGuessIt(true,3);
        Sleep(1500);
        gotoXY(0,15);
        printGuessIt(false,40);
        gotoXY(0,8);
    }
    cout<<endl; printGuessIt(false,17); printGuessIt(true,12);
    cout<<endl; printGuessIt(false,22); printGuessIt(true,2);
    cout<<endl; printGuessIt(false,22); printGuessIt(true,2);printGuessIt(false,10); printGuessIt(true,2);
    cout<<endl; printGuessIt(false,22); printGuessIt(true,2);printGuessIt(false,8); printGuessIt(true,6);
    cout<<endl; printGuessIt(false,22); printGuessIt(true,2);printGuessIt(false,10); printGuessIt(true,2);
    cout<<endl; printGuessIt(false,22); printGuessIt(true,2);printGuessIt(false,10); printGuessIt(true,2);
    cout<<endl; printGuessIt(false,17); printGuessIt(true,12);printGuessIt(false,5); printGuessIt(true,2);

    string startScreenOptions[3]={"New game","Help","Exit"};
    bool isRunning = true, isGetOption=false;
    int getOption=99;
    if (isRunning)
        {
            setTextColor(OPTIONTEXT);
            gotoXY(27,18);
            cout<<startScreenOptions[0];
            setTextColor(NORMALTEXT);
            gotoXY(27,19);
            cout<<startScreenOptions[1];
            gotoXY(27,20);
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
                                cout<<"Game co 5 vong choi. Trong moi vong choi, nguoi choi se phai doan mot tu khoa "<<endl
                                    <<"thong qua cac goi y. Co tat ca 9 goi y, nguoi choi se dung diem de doi lay goi"<<endl
                                    <<"y, cang mua nhieu goi y, diem se cang it di. Dung cac phim mui ten de chon goi"<<endl
                                    <<"y hoac tra loi tu khoa.";
                                cin.get();
                                system("cls");
                                isLoop=true;
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
                                setTextColor(NORMALTEXT);
                                gotoXY(27,18+getOption%3);
                                cout<<startScreenOptions[getOption%3];
                                getOption++;
                                setTextColor(OPTIONTEXT);
                                gotoXY(27,18+getOption%3);
                                cout<<startScreenOptions[getOption%3];
                                setTextColor(NORMALTEXT);
                            }
                        else
                            if (c==72)
                                {
                                    setTextColor(NORMALTEXT);
                                    gotoXY(27,18+getOption%3);
                                    cout<<startScreenOptions[getOption%3];
                                    getOption--;
                                    setTextColor(OPTIONTEXT);
                                    gotoXY(27,18+getOption%3);
                                    cout<<startScreenOptions[getOption%3];
                                    setTextColor(NORMALTEXT);
                                }
                    }
                }
            }
        }
        system("cls");
        setTextColor(NORMALTEXT);
}
