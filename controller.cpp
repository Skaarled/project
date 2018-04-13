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
    int pointLevel=makePoint(level);
    int pointOfGuess[10];
    bool boolPointOfGuess[10];
    bool boolSuggetWord[10];
    bool boolPoint[10];
    string suggetWord[10], typeOfWord, word,key;
    key=makeKeyWord(level);
    makeWord(key, &word);
    findType(key, &typeOfWord);
    makePointOfRecomendation(level, pointOfGuess);
    makeSuggetion(key,suggetWord);
    for (int i=1;i<=9;i++)
    {
        boolPointOfGuess[i]=false;
        boolSuggetWord[i]=false;
        boolPoint[pointOfGuess[i]]=false;
    }
        for (int choise=1;choise<=10;choise++)
        {
            cout<<"Vong: "<<level<<endl;
            printScreen(typeOfWord, "?", pointOfGuess, boolPointOfGuess, suggetWord, boolSuggetWord, pointLevel, boolPoint);
            cout<<"-----------------------------------------------------------------\n\n"<<"Chon so 0 de tra loi tu khoa!\n";
            int num;
            string temAnswer;
            if (choise!=10)
                {
                    cout<<"Ban muon chon so: ";
                    cin>>temAnswer;
                    while ( (int)temAnswer[0]<48|| (int)temAnswer[0]>57)
                    {
                        cout<<"Ban muon chon so: ";
                        cin>>temAnswer;
                    }
                    num= (int)temAnswer[0]-48;
                }
            if (num==0||choise==10)
            {
                cout<<"Cau tra loi cua ban la: ";
                SetConsoleTextAttribute(color,10);
                string answer;
                cin.ignore();
                getline(cin,answer);
                SetConsoleTextAttribute(color,15);
                if (toUpperAnswer(word)==toUpperAnswer(answer))
                {
                    totalPoint+=pointLevel;
                    system("cls");
                    for (int i=1;i<=9;i++)
                        boolSuggetWord[i]=true;
                    printScreen(typeOfWord, word, pointOfGuess, boolPointOfGuess, suggetWord, boolSuggetWord, pointLevel, boolPoint);
                    cout<<"\nCHINH XAC!\a";
                    break;
                }
                else
                {
                    system("cls");
                    for (int i=1;i<=9;i++)
                        boolSuggetWord[i]=true;
                    printScreen(typeOfWord, word, pointOfGuess, boolPointOfGuess, suggetWord, boolSuggetWord, pointLevel, boolPoint);
                    cout<<"\nBan da tra loi sai!\a";
                    level--;
                    round--;
                    break;
                }
            }
            else
            {
                while (boolPointOfGuess[num]==true||num<1||num>9)
                {
                    cout<<"Hay chon lai!\nBan muon chon so: ";
                    cin>>num;
                }
                boolPoint[pointOfGuess[num]]=true;
                boolPointOfGuess[num]=true;
                boolSuggetWord[choise]=true;
                cout<<"Ban vua chon goi y so "<<num<<" voi "<<pointOfGuess[num]<<" diem!\n";
                pointLevel-=pointOfGuess[num];
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
