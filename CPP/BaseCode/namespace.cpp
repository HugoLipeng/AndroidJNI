#include <iostream>
using namespace std;

// 第一个命名空间
namespace first_space
{
void func()
{
    cout << "Inside first_space" << endl;
}
} // namespace first_space
// 第二个命名空间
namespace second_space
{
void func()
{
    cout << "Inside second_space" << endl;
}
} // namespace second_space
int main()
{

    // 调用第一个命名空间中的函数
    first_space::func();

    // 调用第二个命名空间中的函数
    second_space::func();

    return 0;
}