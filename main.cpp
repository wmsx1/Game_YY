#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;
const int max_num=5,Row=3,Line=3;

class StackGame
{
private:
    int sizes=0;
    int inner[max_num+5];

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
    StackGame row[max_num];

public:
    void init();
    bool isFull();
    int sumAll();
    void displayGameBoard(bool upsidedown=false);
    bool push(int position,int num);
    void deleteNum(int position,int num);
};

class Game_YY
{
private:
    //StackGame player[max_num],computer[max_num];
    GameObject player,computer;
    int sum_palyer=0,sum_computer=0;

public:
    void displayGameBoard();
    void init();
    bool isPlayerWin();
    int randomNum(int left=1,int right=6);
    void gameStart();
    void play();
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
    a.displayGameBoard();
    while(1)
    {
        a.play();
        if(a.isGameOver())
        {
            a.gameEnd();
            break;
        }
    }

    return 0;
}

void Game_YY::gameEnd()
{
    cout<<"Game Over"<<endl;
    sum_palyer=0,sum_computer=0;
    for(int i=1;i<=3;i++)
    {
        sum_palyer+=this->player.sumAll();
        sum_computer+=this->computer.sumAll();
    }
    if(this->isPlayerWin())
    {
        cout<<"you win"<<endl;
        return ;
    }
    if(this->sum_computer==this->sum_palyer)
    {
        cout<<"none win"<<endl;
    }
    else
    {
        cout<<"you lost"<<endl;
    }
}
int Game_YY::randomNum(int l,int r)
{
    int roll=rand()%r+l;
    return roll;
}
bool Game_YY::isGameOver()
{
    if(this->player.isFull() || this->computer.isFull())
        return true;
    return false;
}
void Game_YY::init()
{
    this->computer.init();
    this->player.init();
}
void Game_YY::gameStart()
{
    this->init();

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
        char operation=getch();
        if(operation=='1')
        {
            return;
        }
        if(operation=='4')
        {
            exit(0);
        }

    }
}
void Game_YY::displayGameBoard()
{
    int sumComputer=this->computer.sumAll(),sumPlayer=this->player.sumAll();
    this->computer.displayGameBoard(true);

    for(int i=1;i<=10;i++)
    {
        cout<<"---";
    }
    cout<<endl;

    this->player.displayGameBoard();
}
bool Game_YY::isPlayerWin()
{

}
void Game_YY::play()
{

    cout<<"roll 点"<<endl;
    int c=getch();

    int roll=this->randomNum();
    printf("%d 点\n",roll);

    cout<<"放在哪里(1-3)"<<endl;
    while(1)
    {
        int position=getch()-'0';
        if(!(1<=position<=3))
        {
            cout<<"错误"<<endl;
            continue;
        }
        if(this->player.push(position,roll))
        {
            //this->computer.deleteNum(position,roll);

            system("cls");
            this->displayGameBoard();
            break;
        }
        else
        {
            cout<<"错误"<<endl;
            continue;
        }
    }

    roll=this->randomNum();
    while(1)
    {
        int position=this->randomNum(1,3);
        if(this->computer.push(position,roll))
        {
            //this->player.deleteNum(position,roll);

            system("cls");
            this->displayGameBoard();
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
    for(int i=0;i<=max_num;i++)
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
    for(int i=1;i<=max_num;i++)
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

void GameObject::init()
{
    for(int i=1;i<=Row;i++)
    {
        this->row[i].init();
    }
}

bool GameObject::push(int position,int num)
{
    return this->row[position].push(num);
}
bool GameObject::isFull()
{
    for(int i=1;i<=Row;i++)
    {
        if(!this->row[i].isFull())
        {
            return false;
        }
    }
    return true;
}
void GameObject::displayGameBoard(bool upsidedown)
{
    if(!upsidedown)
    {
        for(int i=1;i<=Line;i++)
        {
            for(int j=1;j<=Row;j++)
            {
                this->row[j].printSingle(i);
                cout<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int i=Line;i>=1;i--)
    {
        for(int j=1;j<=Row;j++)
        {
            this->row[j].printSingle(i);
            cout<<" ";
        }
        cout<<endl;
    }
}
void GameObject::deleteNum(int position,int num)
{
    this->row[position].deleteNum(num);
}
int GameObject::sumAll()
{
    int sum=0;
    for(int i=1;i<=Row;i++)
    {
        sum+=this->row[i].sumAll();
    }
    return sum;
}
