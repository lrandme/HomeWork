#include <iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
bool compare(int a, int b);
void guess();    
void result();
int guessNumber();
int guessNumberUpdate();
int guessedNumber = 0;
int guessTimes = 0;


int main() 
{   
    int chooseGame = -1 ;
    cout << "1.猜数游戏         2.猜数游戏改进版\n0.退出\n请选择游戏：";
    cin >> chooseGame;
    while (true)
    {
        if(0 == chooseGame)
        {
            return 0;
        }
        if (1 == chooseGame)
        {
            guessNumber();
            return 0;
        }
        if (2 ==chooseGame)
        {
            guessNumberUpdate();
            return 0;

        }
        cout << "请输入<0>,<1>,<2>";
        cin >> chooseGame;
    }
    
}
int guessNumber()
{
    guessTimes = 0;
    int pointNumber = rand() % 1000;
    cout << "I have a number between 1 and 1000.\nCan you guess my number?\nPlease type your first guess.\n";
    guess();
    while (!(pointNumber == guessedNumber))
    {
        if (compare(pointNumber, guessedNumber))
        {
            cout << "Too High. Try Again.";
        }
        else
        {
            cout << "Too low. Try Again.";
        }
        guess();
    }
    cout << "Excellent! You guessed the number?\nWould you like to play again(y or n)\n";
    string playAgain;
    cin >> playAgain;
    while (true)
    {
        if (("y" == playAgain || "n" == playAgain))
        {
            break;
        }
        cout << "Please input <y> or <n>";
        cin >> playAgain;
    }
    if ("y" == playAgain)
    {
        guessNumber();
    }
    else
    {
        return 0;
    }
    return 0;

}
int guessNumberUpdate()
{
    guessTimes = 0; 
    srand(time(NULL));
    int pointNumber = rand() % 1000;
    cout << "I have a number between 1 and 1000.\nCan you guess my number?\nPlease type your first guess.\n";
    guess();
    while (!(pointNumber == guessedNumber) )
    {
        if (compare(pointNumber,guessedNumber)) 
        {
            cout << "Too High. Try Again.";
        }
        else
        {
            cout << "Too low. Try Again.";
        }
        guess();
    }
    result();
    cout << "Excellent! You guessed the number?\nWould you like to play again(y or n)\n";
    string playAgain;
    cin >> playAgain;
    while (true)
    {
        if (("y" == playAgain || "n" == playAgain))
        {
            break;
        }
        cout << "Please input <y> or <n>";
        cin >> playAgain;
    }
    if ("y" == playAgain)
    {
        guessNumberUpdate();
    }
    else
    {
        return 0;
    }
    return 0;
}

bool compare(int a, int b) 
{
    if (a < b) 
    {
        return true;
    }
    else
    {
        return false;
    }
}
void guess() 
{
    cin >> guessedNumber;
    guessTimes++;
}
void result()
{
    if (guessTimes < 10 && guessTimes > 0)
    {
        cout << "Either you know the secret or you got lucky!"; 

    }
    if (guessTimes == 10)
    {
        cout << "Ahah! You know the secret! ";   
    }
    if (guessTimes > 10)
    {
        cout << "You should be able to do better! "; 

    }
}






// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
