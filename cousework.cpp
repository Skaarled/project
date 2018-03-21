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
    int random=rand()%(3+3*(level-1))+(1+3*(level-1));
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
    SetConsoleTextAttribute(color,15);
    cout<<typeofword<<"        ";
    SetConsoleTextAttribute(color,43);
    cout<<"   "<<word<<"   ";
    SetConsoleTextAttribute(color,15);
    cout<<"        Diem con lai: ";
    SetConsoleTextAttribute(color,12);
    cout<<pointlevel;
    SetConsoleTextAttribute(color,15);
    cout<<endl;
    gotoxy(39,3);
    cout<<"GOI Y";
    SetConsoleTextAttribute(color,43);
    for (int i=0;i<=9;i++)
        {
            gotoxy(41-(suggetword[i].size())/2,3+i);
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
        gotoxy(77,i+3);
        cout<<"|";
        gotoxy(80,3+i);
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
    int level=1,totalpoint=0,round=5;
    while (level<=round)
    {
    bool gameend=false;
    int pointlevel=point(level);
    int pointforguess[10];
    bool boolpointforguess[10];
    bool boolsuggetword[10];
    bool boolpoint[10];
    string suggetword[10], typeofword, word;
    toword(keyword(level), &word);
    type(keyword(level), &typeofword);
    pointforrecomendation(level, pointforguess);
    suggetion(keyword(level),suggetword);
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
            cout<<"----------------------------------------------------------------------------------------\n\n"<<"Chon so 0 de tra loi tu khoa!\n";
            int num;
            if (chose!=10)
                {
                    cout<<"Ban muon chon so: ";
                    cin>>num;
                }
            if (num==0||chose==10)
            {
                gameend=true;
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
        system("cls");
        cout<<"Tong diem sau vong "<<level<<" : "<<totalpoint;
        if (level==round)
            return 0;
        cout<<"\nEnter de tiep tuc!";
        cin.get();
        system("cls");
        cout<<"Loading.";Sleep(500);system("cls");cout<<"Loading..";Sleep(500);system("cls");cout<<"Loading...";Sleep(500);system("cls");
        level++;
    }
}
