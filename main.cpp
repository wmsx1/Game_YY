#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;
const int MaxNum=5;

class StackGame
{
private:
    int sizes=0;
    int inner[7];

public:
    void init();
    bool isFull();
    bool push(int num);
    bool deleteNum(int num);
    int sumAll();
    int printSingle(int position);
    void test();
    int test_sizes();
    void test_all();
};

class GameObject
{
private:
    
public:
    
};

class Game_YY
{
private:
    StackGame player[MaxNum],computer[MaxNum];

public:
    void displayGameboard();
    void gameStart();
    void Play();
    bool isGameOver();
    void gameEnd();
};

int main()
{
    srand(time(NULL));
    /*
    stack_g a;
    a.init();
    a.Test();
    */

    Game_YY a;
    a.gameStart();
    system("cls");
    a.displayGameboard();
    while(1)
    {
        a.Play();
        if(!a.isGameOver())
        {
            a.gameEnd();
            break;
        }
    }

    return 0;
}

void Game_YY::gameEnd()
{
    cout<<"end"<<endl;
    int sum1=0,sum2=0;
    for(int i=1;i<=3;i++)
    {
        sum1+=this->player[i].sumAll();
        sum2+=this->computer[i].sumAll();
    }
    if(sum1>sum2)
    {
        cout<<"you win"<<endl;
    }
    if(sum1==sum2)
    {
        cout<<"none win"<<endl;
    }
    if(sum1<sum2)
    {
        cout<<"you lost"<<endl;
    }

}
bool Game_YY::isGameOver()
{
    bool flag1=true,flag2=true;
    for(int i=1;i<=3;i++)
    {
        if(!this->player[i].isFull())flag1=false;
        if(!this->computer[i].isFull())flag2=false;
    }

    if(flag1==true || flag2==true)
    {
        return false;
    }
    return true;
}
void Game_YY::gameStart()
{
    for(int i=1;i<=5;i++)
    {
        this->player[i].init();
        this->computer[i].init();
    }

    cout<<"Hello"<<endl;
    cout<<"Press any key to continue___"<<endl;
    int c=getch();

    while(1)
    {
        system("cls");
        cout<<"1. Start\n"
              "2. Help\n"
              "3. Author\n"
              "4. Exit"<<endl;


    }
}
void Game_YY::displayGameboard()
{
    int p=3;
    for(int p=3;p>=1;p--)
    {
        for(int i=1;i<=3;i++)
        {
            this->computer[i].printSingle(p);
            cout<<" ";
        }
        cout<<endl;
    }

    for(int i=1;i<=10;i++)
    {
        cout<<"---";
    }
    cout<<endl;

    for(int p=1;p<=3;p++)
    {
        for(int i=1;i<=3;i++)
        {
            this->player[i].printSingle(p);
            cout<<" ";
        }
        cout<<endl;
    }

}
void Game_YY::Play()
{
    cout<<""<<endl;
    cout<<"roll 点"<<endl;
    int c=getch();

    int roll=rand()%6+1;
    printf("%d 点\n",roll);
    cout<<"放在哪里(1-3)"<<endl;
    while(1)
    {
        int x=getch()-'0';
        if(!(1<=x<=3))
        {
            cout<<"错误"<<endl;
            continue;
        }
        else
        {
            if(this->player[x].push(roll))
            {
                this->computer[x].deleteNum(roll);
                system("cls");
                this->displayGameboard();
                break;
            }
            else
            {
                cout<<"错误"<<endl;
                continue;
            }
        }
    }

    roll=rand()%6+1;
    while(1)
    {
        int x=rand()%3+1;
        if(this->computer[x].push(roll))
        {
            this->player[x].deleteNum(roll);
            system("cls");
            this->displayGameboard();
            break;
        }
        else
        {
            continue;
        }
    }
}

bool StackGame::isFull()
{
    if(this->sizes==3)return true;
    return false;
}
bool StackGame::push(int num)
{
    if(this->isFull())return false;
    this->inner[++this->sizes]=num;
    return true;
}
bool StackGame::deleteNum(int num)
{
    int position=1;
    while(position<=this->sizes)
    {
        if(this->inner[position]==num)
        {
            this->inner[position]=0;
            for(int i=position+1;i<=this->sizes;i++)
            {
                //this->inner[i-1]=this->inner[i];
                swap(this->inner[i-1],this->inner[i]);
            }
            this->sizes-=1;
            continue;
        }
        position++;
    }
}
void StackGame::init()
{
    for(int i=0;i<=MaxNum;i++)
    {
        this->inner[i]=0;
    }
}
int StackGame::sumAll()
{
    int ans=0;
    for(int i=1;i<=this->sizes;i++)
    {
        ans+=this->inner[i];
    }
    return ans;
}
void StackGame::test()
{
    string operation;
    int x;
    while(1)
    {
        this->test_all();
        cin>>operation;
        if(operation=="push")
        {
            cin>>x;
            this->push(x);
        }
        if(operation=="delete")
        {
            cin>>x;
            this->deleteNum(x);
        }
        if(operation=="ask")
        {
            this->test_sizes();
        }
    }
}
void StackGame::test_all()
{
    for(int i=1;i<=MaxNum;i++)
    {
        cout<<this->inner[i]<<" ";
    }cout<<endl;
}
int StackGame::printSingle(int position)
{
    cout<<this->inner[position];
}
int StackGame::test_sizes()
{
    return this->sizes;
}
