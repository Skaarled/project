#include "models.h"
#include "view.h"
int main ()
{
    HANDLE color;
    color= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color,15);
    int level,totalPoint=0,round=5,turn=5;
    for (level=1;level<=round;level++)
    {
    int pointLevel=point(level);
    int pointForGuess[10];
    bool boolPointForGuess[10];
    bool boolSuggetWord[10];
    bool boolPoint[10];
    string suggetWord[10], typeOfWord, word,key;
    key=keyWord(level);
    toWord(key, &word);
    type(key, &typeOfWord);
    pointForRecomendation(level, pointForGuess);
    suggetion(key,suggetWord);
    for (int i=1;i<=9;i++)
    {
        boolPointForGuess[i]=false;
        boolSuggetWord[i]=false;
        boolPoint[pointForGuess[i]]=false;
    }
        for (int chose=1;chose<=10;chose++)
        {
            printDetails(level,typeOfWord, "????????", pointForGuess, boolPointForGuess, suggetWord, boolSuggetWord, pointLevel, boolPoint);
            cout<<"Chon so 0 de tra loi tu khoa!\n";
            int num;
            string strNum;
            if (chose!=10)
                {
                    cout<<"\nBAN MUON CHON SO: ";
                    cin>>strNum;
                    while (((int)strNum[0]-48)<0||((int)strNum[0]-48)>9)
                    {
                        cout<<"\nBAN MUON CHON SO: ";
                        cin.ignore();
                        cin>>strNum;
                    }
                    num=(int)strNum[0]-48;
                }
            if (num==0||chose==10)
            {
                cout<<"CAU TRA LOI CUA BAN LA: ";
                SetConsoleTextAttribute(color,10);
                string answer;
                cin.ignore();
                getline(cin,answer);
                SetConsoleTextAttribute(color,15);
                if (toupperStr(word)==toupperStr(answer))
                {
                    totalPoint+=pointLevel;
                    system("cls");
                    for (int i=1;i<=9;i++)
                        boolSuggetWord[i]=true;
                    printDetails(level,typeOfWord, word, pointForGuess, boolPointForGuess, suggetWord, boolSuggetWord, pointLevel, boolPoint);
                    cout<<"\nCHINH XAC!\a";
                    break;
                }
                else
                {
                    system("cls");
                    for (int i=1;i<=9;i++)
                        boolSuggetWord[i]=true;
                    printDetails(level,typeOfWord, word, pointForGuess, boolPointForGuess, suggetWord, boolSuggetWord, pointLevel, boolPoint);
                    cout<<"\nDAP AN SAI!\a";
                    level--;
                    round--;
                    break;
                }
            }
            else
            {
                while (boolPointForGuess[num]==true||num<1||num>9)
                {
                    cout<<"HAY CHON LAI!\nBAN MUON CHON SO: ";
                    cin>>num;
                }
                boolPoint[pointForGuess[num]]=true;
                boolPointForGuess[num]=true;
                boolSuggetWord[chose]=true;
                cout<<"Ban vua chon goi y so "<<num<<" voi "<<pointForGuess[num]<<" diem!\n";
                pointLevel-=pointForGuess[num];
            }
            Sleep(2000);
            system("cls");
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

