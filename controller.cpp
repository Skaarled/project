#include "models.h"
#include "view.h"
int main ()
{
    setTextColor(15);
    int level,totalPoint=0,round=5,turn=5;
    printStartScreen();
    //bat dau vong lap 5 vong choi
    for (level=1;level<=round;level++)
    {
    //khoi tao du lieu cua vong choi
    int guessPoint[10];
    bool boolGuessPoint[10];
    bool boolSuggetWord[10];
    bool boolPoint[10];
    string suggetWord[10], typeOfKeyWord, word,key;


    int pointLevel=getPoint(level);
    key=getKeyWord(level);
    getWord(key, &word);
    findType(key, &typeOfKeyWord);
    getRecomendationPoint(level, guessPoint);
    getSuggetion(key,suggetWord);
    ShowCur(false);
    for (int i=1;i<=9;i++)
    {
        boolGuessPoint[i]=false;
        boolSuggetWord[i]=false;
        boolPoint[guessPoint[i]]=false;
    }
        //bat dau vong lap mua goi y
    for (int choise=1;choise<=10;choise++)
    {
        printDetails(level,typeOfKeyWord, "?", guessPoint, boolGuessPoint, suggetWord, boolSuggetWord, pointLevel, boolPoint);
        label:int num;
        int temp=90;
        bool isGetNumber = false;
        while (!isGetNumber)
        {
        if (kbhit())
        {
            char c=getch();
            if (c==13)
                {
                    isGetNumber=true;
                }
            if (c==-32)
            {
                c=getch();
                if (c==80)
                    temp++;
                if (c==72)
                    temp--;
            }
        }
        if (temp%10==0)
            {
            gotoXY(27,3);
            setTextColor(58);
            cout<<"   ?   ";
            setTextColor(15);
            gotoXY(58,7);
            cout<<"So 1";
            if (boolGuessPoint[1]==true)
                cout<<": "<<guessPoint[1]<<endl;
            gotoXY(58,15);
            cout<<"So 9";
            if (boolGuessPoint[9]==true)
                cout<<": "<<guessPoint[9]<<endl;
            }
            else
                {
                    if (temp%10==1||temp%10==9)
                    {
                        gotoXY(27,3);
                        setTextColor(10);
                        cout<<"   ?   ";
                    }
                    setTextColor(63);
                    gotoXY(58,6+temp%10);
                    cout<<"So "<<temp%10;
                    if (boolGuessPoint[temp%10]==true)
                        cout<<": "<<guessPoint[temp%10]<<endl;
                    setTextColor(15);
                    if (temp%10!=1)
                    {
                        gotoXY(58,5+temp%10);
                        cout<<"So "<<temp%10-1;
                        if (boolGuessPoint[temp%10-1]==true)
                            cout<<": "<<guessPoint[temp%10-1]<<endl;
                    }
                    if (temp%10+1!=10)
                    {
                        gotoXY(58,7+temp%10);
                        cout<<"So "<<temp%10+1;
                        if (boolGuessPoint[temp%10+1]==true)
                            cout<<": "<<guessPoint[temp%10+1]<<endl;
                    }
                }
        }
            num=temp%10;
            if (num==0||choise==10)
            {
                ShowCur(true);
                gotoXY(25,3); cout<<"           ";
                gotoXY(25,3);
                setTextColor(10);
                string answer;
                getline(cin,answer);
                setTextColor(15);
                if (toUpperAnswer(word)==toUpperAnswer(answer))
                {
                    totalPoint+=pointLevel;
                    for (int i=1;i<=9;i++)
                        boolSuggetWord[i]=true;
                    printDetails(level,typeOfKeyWord, word, guessPoint, boolGuessPoint, suggetWord, boolSuggetWord, pointLevel, boolPoint);
                    gotoXY(20,20);
                    setTextColor(10);
                    cout<<"DAP AN DUNG!!";
                    setTextColor(15);
                    break;
                }
                else
                {
                    printDetails(level,typeOfKeyWord, "   ?   ", guessPoint, boolGuessPoint, suggetWord, boolSuggetWord, pointLevel, boolPoint);
                    gotoXY(20,20);
                    setTextColor(12);
                    cout<<"DAP AN SAI!!";
                    setTextColor(15);
                    level--;
                    round--;
                    break;
                }
            }
            else
            {
                while (boolGuessPoint[num]==true||num<1||num>9)
                {
                    goto label;
                }
                boolPoint[guessPoint[num]]=true;
                boolGuessPoint[num]=true;
                boolSuggetWord[choise]=true;
                pointLevel-=guessPoint[num];
            }
            Sleep(500);
        }
        cin.get();
        cout<<"Tong diem sau vong "<<level<<" : "<<totalPoint;
        cout<<"\nEnter de tiep tuc!";
        cin.get();
        system("cls");
        turn--;
        if (turn==0)
        {
            cout<<"Tong diem: "<<totalPoint;
            return 0;
        }
    }
}
