#include <stdio.h>
#include <stdlib.h>

/**
 函数指针 
 https://www.cnblogs.com/windlaughing/archive/2013/04/10/3012012.html
*/

//定义一个函数
int add(int x, int y)
{
    return x + y;
}

int main()
{
    //定义函数指针
    int (*android)(int x, int y);//声明一个指向同样参数、返回值的函数指针变量。
    //函数指针赋值
    android = add;
    //使用函数指针
    int result = add(99, 1);
    printf("result==%d\n", result);

    return 0;
}