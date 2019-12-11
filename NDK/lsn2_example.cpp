// lsn2_example.cpp: 定义应用程序的入口点。
//

#include "lsn2_example.h"

using namespace std;

void change1(int i) {
	i = 10;
}

void change2(int* i) {
	*i = 10;
}

void change3(int** i) {
	int j = 100;
	*i = &j;
}

#include <stdarg.h>

//可变参数
void add(char* buf,...) {
	// 表示 ... 的参数列表
	va_list list;
	va_start(list, buf);
	
	char c = va_arg(list, char);
	printf("可变参数有:%c\n", c);
	va_end(list);
}

//void(*p)(char*) 函数
// void 返回值
// (*p) p变量用来表示这个函数
// (char*) 函数的参数列表

void say(int (*m)(char*,char*),char *msg) {
	m(msg, NULL);
}

int println(char* msg, char* msg1) {
	printf("println:%s\n",msg);
	return 1;
}
//创建别名  Func = 昵称
// Func =  int xxx(char*,char*)
typedef int(*Func)(char*,char*);

typedef void(*Success)(char*);
typedef void(*Failure)(char*);
void http(int i ,Success success, Failure f) {
	if (i == 1) {
		success("成功");
	}
	else {
		f("失败");
	}
	
}
void httpOk(char* msg) {
	printf("请求成功了:%s\n", msg);
}
void httpFailure(char* msg) {
	printf("请求失败了:%s\n", msg);
}



int main()
{


	int i1 = 10;
	//& 取地址符
	int *p1 = &i1;
	
	// %#x 0xxxxx
	printf("i1 地址:%#x\n", &i1);
	printf("p1 值:%#x\n", p1);
	printf("p1 地址:%#x\n", &p1);
	//解引用 ： 解析 地址 的值
	printf("p1指向地址的值:%d\n",*p1);
	// 32=4 64=8
	printf("p1占用了几个字节:%d\n", sizeof(p1));


	*p1 = 100;
	printf("通过指针操作内存,修改值:%d\n", i1);


	//++ + - --
	p1++;
	printf("p1指向地址的值:%d\n", *p1);


	int array1[] = {11,22,33,44};
	int *array_p1 = array1;
	for (size_t i = 0; i < 4; i++)
	{
	
		printf("数组中的元素:%d\n", *(array1 + i));
	}
	//1、数组 一块内存连续的数据
	//2、指针 指向内存的变量

	// 直接输出数组名 输出的数组首元素的地址
	printf("array1输出数组名:%#x\n", array1);
	

	// 数组 的 指针
	// 0x0000 0x0004 0x0008
	int array2[2][3] = { {11,22,33},{44,55,66} };
	//数组指针  int[3] *
	int (*array_p2)[3] = array2;
	//array_p2 + 1 == array_p2[1]
	// *( array_p2 + 1) = int[3]
	// *( array_p2 + 1) + 1 获得 int[3] 中第二个数据 地址
	// *( *( array_p2 + 1) + 1) = 55
	printf("array_p2 + 1: %#x\n", array_p2 + 1);
	printf("取出55：%d\n", *(*(array_p2 + 0) + 1));

	// 指针 的 数组
	int *p_array[3] = { &i1,&i1,&i1 };

	//从右往左看 const 修饰谁 谁就不可变
	//const  final
	char tmp[] = "hello";
	//不能修改char对应地址的值  指针p2的值是可以变的
	const char *p2 = tmp;
	p2 = "DONGNAO";
	//和p2是一样的
	char const  *p3 = tmp;
		
	char * const p4 = tmp;
	p4[0] = 'a';
	//不能修改指针的值  p4是不可变的
	//p4 = "11"


	const char * const p5 = tmp;
	char const * const p6 = tmp;

	//多级指针
	int i2 = 10;
	//p7存 i2的地址
	int *p7 = &i2;
	//p7这个变量自己的地址给 p8
	int **p8 = &p7;

	printf("p8的值：%d\n", **p8);


	//========================================================================
	//函数 必须在使用之前声明
	

	//函数形参
	//1、传值	
			//把参数的值给函数
	int i3 = 1;
	change1(i3);
	printf("change1 i3=%d\n", i3);
	//2、传引用
	//不修改指针的值 修改的是指针指向内存的数据
	int *p9 = &i3;
	//修改i3的值
	change2(p9);
	printf("change2 i3=%d\n",i3);

	
	//p9这个变量的地址给 p10
	int **p10 = &p9;
	//修改指针的值 p9的值 0xXXXXX 地址
	change3(&p9);

	//add(NULL,1,2,3,4,5,'a');

	//函数指针
	//指向函数的指针
	//类似回调函数
	Func func = println;
	say(func,"hello");
	http(1, httpOk, httpFailure);
	http(0, httpOk, httpFailure);



	//=====================================================
	//宏
	int d = I;
	TEST(100);

	//希望获得 11 * 20
	//实际获得 1 + 10 * 10 + 10  = 11+100
	int add = ADD(1 + 10, 10 + 10);

	//如果为 true  编译并执行块内的代码
#ifdef DEBUG
	Func fun = println;
	say(fun, "hello");
	say(println, "hello");
	//模拟  举例子 执行http请求
	http(1, httpOk, httpFailure);
	http(0, httpOk, httpFailure);
#else


#endif 





	/*p5 = "11";
	p5[0] = 'a';*/
	system("pause");
	return 0;
}


