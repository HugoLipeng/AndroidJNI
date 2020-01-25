#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//extern int a = 10; 默认外部链接
int a = 10; //全局区
//静态全局变量是内部链接
static int b = 20; //静态区

//内部链接和外部链接有什么区别？
//1. 如果变量是内部链接的话，那么此变量只能在当前文件内访问
//2. 如果是变量是外部链接的话，那么此变量可以被其他文件使用


//1. 全局静态变量和局部静态变量都存储在静态区，都是在程序运行期间都是合法有效
//2. 局部静态变量符号的可见范围仅限于当前函数内部，全局静态变量可见范围从定义到文件结尾

//头文件不要放定义，只能放声明

void test01()
{
	static int c = 30; //静态区
}

//头文件不参与编译，每一个.c文件，我们叫做一个编译单元
//编译器独立编译每一个.c文件
void test02()
{
	//声明，表示告诉编译器这个符号是存在的，你让我先编译通过，让连接器去找到底这个符号在那
	extern int g_a;

	printf("g_a = %d\n", g_a);
}



int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}