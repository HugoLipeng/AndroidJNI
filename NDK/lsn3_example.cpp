// lsn3_example.cpp: 定义应用程序的入口点。
//

#include "lsn3_example.h"
#include "mysprintf.h"
using namespace std;

// struct 结构体 java class
//s1 s2 可以不定义 ， 表示 Student的变量
struct Student
{
	// public
	int i;
	short j;

}s1,s2;

//typedef 创建一个别名 
typedef struct {
	int i;
	short j;
} Student1;


struct MyStruct1
{
	short i;
	short j;
	int k;
};
// short i; 0 1 
// short j; 2 3
// int k 4 5 6 7
// 默认是 4字节对齐
#pragma pack(2)  //指定以2 字节对齐
struct MyStruct2
{
	// 0 1  2 3 
	short i; //dc dd 保存i数据  de df
	//4
	int j;		//e0
	short k;
};
#pragma pack() //还原
// 4 8 12 16
//short i  0 1 2 3
// int j  4 5 6 7 
// short k 8 9 10 11



//在相同的内存位置 存储不同的数据
//共用体 最大成员的字节大小
union MyUnion
{
	short i;
	int j;
};


int main()
{
	//================================================================
	//结构体  类似 javabean
	struct Student student;
	student.i = 10;
	student.j = 20;
	
	//使用s1变量
	s1.i = 10;
	s1.j = 20;

	struct MyStruct2 ms1;
	printf("i:%#x  j:%#x  k:%#x\n",&ms1.i, &ms1.j, &ms1.k);

	printf("%d\n",sizeof(struct MyStruct1)); //8字节
	printf("%d\n", sizeof(struct MyStruct2));//12字节
	printf("=======================================================\n");
	//=======================================================
	//共用体
	union MyUnion mu;
	mu.i = 10;
	printf("i地址：%#x\n", &mu.i);
	printf("i地址：%#x\n", &mu.j);
	printf("%d\n", mu.i);
	printf("%d\n",mu.i);
	
	mu.j = 11;
	printf("%d\n", mu.i);
	printf("%d\n", mu.j);
	
	//占用内存
	int i = 0;
	int j = 0;
	
	i = 10;
	//一直使用i
	// i不使用 使用j
	j = 10;

	system("pause");
	return 0;
}
