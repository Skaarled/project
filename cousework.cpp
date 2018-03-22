#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;
string keyword (int level)
{
    char data[200];
    string word;
    srand(time(NULL));
    int x=3+3*(level-1);
    int y=1+3*(level-1);
    int random=y+rand()%(x-y+1);
    ifstream infile;
    infile.open("keyword.txt");
    while (random--!=0)
        infile.getline(data,200);
    int i=0;
    while (data[i]!='$')
        {
            word=word+data[i];
            i++;
        }
    infile.close();
    return word;
}
void pointforrecomendation (int level,int pointforguess[10])
{
    int randompoint,t=0;
    bool i[10]; for (int tem=1;tem<=9;tem++) i[tem]=false;
    srand(time(NULL));
    randompoint=rand()%9+1;
    for (int point=10;;point=point+10+(level-1)*5)
    {
        t++;
        if (t==10)
            break;
        while (i[randompoint]==true)
            randompoint=rand()%9+1;
        pointforguess[randompoint]=point;
        i[randompoint]=true;
    }
}
void suggetion (string keyword, string suggetword[10])
{
    int test=0,i=1;
    for (int tem=0;tem<keyword.size();tem++)
    {
        if (keyword[tem]==':')
            test++;
        if (test==2&&keyword[tem]!=':')
        {
            if (keyword[tem]!=',')
                suggetword[i]=suggetword[i]+keyword[tem];
            if (keyword[tem]==',')
                i++;
        }
    }
}
void type (string keyword, string *typeofkeyword)
{
    int tem=0;
    while (keyword[tem]!=':')
    {
        *typeofkeyword=*typeofkeyword+keyword[tem];
        tem++;
    }
}
void toword(string keyword, string *word)
{
    int tem=0;
    while (keyword[tem]!=':')
        tem++;
    tem++;
    while (keyword[tem]!=':')
        {
            *word=*word+keyword[tem];
            tem++;
        }
}
int point(int level)
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
string toupperstr(string s)
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
void gotoxy(int x,int y)
{
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
COORD position = {x,y} ;
SetConsoleCursorPosition(hStdout,position ) ;
}
void view (string typeofword, string word, int pointforguess[10], bool boolpointforguess[10], string suggetword[10], bool boolsuggetword[10],int pointlevel, bool boolpoint[10])
{
    HANDLE color;
    color= GetStdHandle(STD_OUTPUT_HANDLE);
    gotoxy(0,1);
    SetConsoleTextAttribute(color,15);
    cout<<typeofword;
    gotoxy(23-(word.size())/2,1);
    SetConsoleTextAttribute(color,43);
    cout<<"   "<<word<<"   ";
    SetConsoleTextAttribute(color,15);
    gotoxy(48,1);
    cout<<"Diem con lai: ";
    SetConsoleTextAttribute(color,12);
    cout<<pointlevel;
    SetConsoleTextAttribute(color,15);
    cout<<endl;
    gotoxy(24,3);
    cout<<"GOI Y";
    SetConsoleTextAttribute(color,43);
    for (int i=0;i<=9;i++)
        {
            gotoxy(21-(suggetword[i].size())/2,3+i);
            if (boolsuggetword[i]==true)
                cout<<suggetword[i]<<endl;
            else
                cout<<endl;
        }
    SetConsoleTextAttribute(color,15);
    cout<<endl;
    int pointforguesstem[10];
    for (int i=1;i<=9;i++)
    {
        pointforguesstem[i]=pointforguess[i];
        gotoxy(6,i+3);
        cout<<"|";
        gotoxy(47,i+3);
        cout<<"|";
        gotoxy(50,3+i);
        cout<<"So "<<i;
        if (boolpointforguess[i]==true)
            cout<<": "<<pointforguess[i]<<endl;
        else
            cout<<endl;
    }
    sort(pointforguesstem+1,pointforguesstem+10);
    for (int i=1;i<=9;i++)
    {
        gotoxy(2,i+3);
        if (boolpoint[pointforguesstem[i]]==false)
        {
            SetConsoleTextAttribute(color,10);
            cout<<pointforguesstem[i]<<endl;
        }
        else
        {
            SetConsoleTextAttribute(color,12);
            cout<<pointforguesstem[i]<<endl;
        }
    }
    SetConsoleTextAttribute(color,15);
    cout<<endl;
}
int main ()
{
    HANDLE color;
    color= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color,15);
    int level,totalpoint=0,round=5,turn=5;
    for (level=1;level<=round;level++)
    {
    int pointlevel=point(level);
    int pointforguess[10];
    bool boolpointforguess[10];
    bool boolsuggetword[10];
    bool boolpoint[10];
    string suggetword[10], typeofword, word,key;
    key=keyword(level);
    toword(key, &word);
    type(key, &typeofword);
    pointforrecomendation(level, pointforguess);
    suggetion(key,suggetword);
    for (int i=1;i<=9;i++)
    {
        boolpointforguess[i]=false;
        boolsuggetword[i]=false;
        boolpoint[pointforguess[i]]=false;
    }
        for (int chose=1;chose<=10;chose++)
        {
            cout<<"Vong: "<<level<<endl;
            view(typeofword, "?", pointforguess, boolpointforguess, suggetword, boolsuggetword, pointlevel, boolpoint);
            cout<<"-----------------------------------------------------------------\n\n"<<"Chon so 0 de tra loi tu khoa!\n";
            int num;
            if (chose!=10)
                {
                    cout<<"Ban muon chon so: ";
                    cin>>num;
                }
            if (num==0||chose==10)
            {
                cout<<"Cau tra loi cua ban la: ";
                SetConsoleTextAttribute(color,10);
                string answer;
                cin.ignore();
                getline(cin,answer);
                SetConsoleTextAttribute(color,15);
                if (toupperstr(word)==toupperstr(answer))
                {
                    totalpoint+=pointlevel;
                    system("cls");
                    for (int i=1;i<=9;i++)
                        boolsuggetword[i]=true;
                    view(typeofword, word, pointforguess, boolpointforguess, suggetword, boolsuggetword, pointlevel, boolpoint);
                    cout<<"\nCHINH XAC!\a";
                    break;
                }
                else
                {
                    system("cls");
                    for (int i=1;i<=9;i++)
                        boolsuggetword[i]=true;
                    view(typeofword, word, pointforguess, boolpointforguess, suggetword, boolsuggetword, pointlevel, boolpoint);
                    cout<<"\nBan da tra loi sai!\a";
                    level--;
                    round--;
                    break;
                }
            }
            else
            {
                while (boolpointforguess[num]==true||num<1||num>9)
                {
                    cout<<"Hay chon lai!\nBan muon chon so: ";
                    cin>>num;
                }
                boolpoint[pointforguess[num]]=true;
                boolpointforguess[num]=true;
                boolsuggetword[chose]=true;
                cout<<"Ban vua chon goi y so "<<num<<" voi "<<pointforguess[num]<<" diem!\n";
                pointlevel-=pointforguess[num];
            }
            Sleep(2000);
            system("cls");
        }
        cin.get();
        cout<<"Tong diem sau vong "<<level<<" : "<<totalpoint;
        cout<<"\nEnter de tiep tuc!";
        cin.get();
        system("cls");
        turn--;
        if (turn==0)
        {
            cout<<"Tong diem: "<<totalpoint;
            return 0;
        }
    }
}
