#include "models.h"
#include "view.h"
int main ()
{
    setTextColor(NORMALTEXT);
    int level=1;
    int totalPoint=0;
    printStartScreen();
    int guessPoint[NUMBERGAME+1];
    bool boolGuessPoint[NUMBERGAME+1];
    bool boolSuggetWord[NUMBERGAME+1];
    //bat dau vong lap 5 vong choi
    while (level<=5)
    {
    ShowCur(false);
    //khoi tao du lieu cua vong choi
    string suggetWord[NUMBERGAME+1], typeOfKeyWord, word,key;
    int pointLevel=getPoint(level);
    key=getKeyWord(level);
    getWord(key, &word);
    findType(key, &typeOfKeyWord);
    getRecomendationPoint(level, guessPoint);
    getSuggetion(key,suggetWord);
    bool boolPoint[251];
    ShowCur(false);
    //bat dau 9 lan chon
    for (int i=1;i<=NUMBERGAME;i++)
    {
        boolGuessPoint[i]=false;
        boolSuggetWord[i]=false;
        boolPoint[guessPoint[i]]=false;
    }
    printBackground();
        //bat dau vong lap mua goi y
    for (int choise=1;choise<=NUMBERGAME+1;choise++)
    {
        label:printDetails(level,typeOfKeyWord, "?", guessPoint, boolGuessPoint,
                           suggetWord, boolSuggetWord, pointLevel, boolPoint);
        int num;
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
            setTextColor(NORMALTEXT);
            gotoXY(58,7);
            cout<<"So 1";
            if (boolGuessPoint[1]==true)
                cout<<": "<<guessPoint[1]<<endl;
            gotoXY(58,15);
            cout<<"So 9";
            if (boolGuessPoint[NUMBERGAME]==true)
                cout<<": "<<guessPoint[NUMBERGAME]<<endl;
            }
            else
                {
                    if (temp%10==1||temp%10==NUMBERGAME)
                    {
                        gotoXY(27,3);
                        setTextColor(GREENTEXT);
                        cout<<"   ?   ";
                    }
                    setTextColor(OPTIONTEXT);
                    gotoXY(58,6+temp%10);
                    cout<<"So "<<temp%10;
                    if (boolGuessPoint[temp%10]==true)
                        cout<<": "<<guessPoint[temp%10]<<endl;
                    setTextColor(NORMALTEXT);
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
            if (num==0||choise==NUMBERGAME+1)
            {
                ShowCur(true);
                gotoXY(23,3); cout<<"               ";
                gotoXY(25,3);
                setTextColor(GREENTEXT);
                string answer;
                getline(cin,answer);
                setTextColor(NORMALTEXT);
                if (toUpperAnswer(word)==toUpperAnswer(answer))
                {
                    totalPoint+=pointLevel;
                    for (int i=1;i<=NUMBERGAME;i++)
                        boolSuggetWord[i]=true;
                    printDetails(level,typeOfKeyWord, word, guessPoint, boolGuessPoint,
                                suggetWord, boolSuggetWord, pointLevel, boolPoint);
                    gotoXY(20,19);
                    setTextColor(GREENTEXT);
                    cout<<"DAP AN DUNG!!\n";
                    setTextColor(NORMALTEXT);
                    break;
                }
                else
                {
                    printDetails(level,typeOfKeyWord, "   ?   ", guessPoint, boolGuessPoint,
                                 suggetWord, boolSuggetWord, pointLevel, boolPoint);
                    gotoXY(20,19);
                    setTextColor(REDTEXT);
                    cout<<"DAP AN SAI!!\n";
                    setTextColor(NORMALTEXT);
                    break;
                }
            }
            else
            {
                if (boolGuessPoint[num]==true)
                    {
                        setTextColor(NORMALTEXT);
                        gotoXY(58,6+num);
                        cout<<"So "<<num;
                        cout<<": "<<guessPoint[num]<<endl;
                        goto label;
                    }
                boolPoint[guessPoint[num]]=true;
                boolGuessPoint[num]=true;
                boolSuggetWord[choise]=true;
                pointLevel-=guessPoint[num];
            }
            Sleep(500);
        }
        getch();
        cout<<"Tong diem sau vong "<<level<<" : "<<totalPoint;
        cout<<"\nEnter de tiep tuc!";
        getch();
        level++;
        system("cls");
        if (level==6)
            cout<<"Ban da dat duoc "<<totalPoint<<" diem sau 5 luot choi, so diem se duoc quy doi ra $ va chuyen toi tai khoan cua ban sau 24h.";
    }
}
