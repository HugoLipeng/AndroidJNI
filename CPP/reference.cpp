#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int j = 20;
    int &refj = j; //声明引用必须使用&符号，并且同时设置初值j
    int *ptr = &j; //声明指针，并且同时指向初值j

    cout << "refj=" << refj << " ＊ptr=" << *ptr << endl; //打印出refj与＊ptr的内容
    *ptr = *ptr + 5;                                     //指针运算
    cout << "refj=" << refj << " ＊ptr=" << *ptr << endl;
    refj = refj + 5; //引用运算
    cout << "refj=" << refj << " ＊ptr=" << *ptr << endl;

    system("pause");
    return 0;
}
