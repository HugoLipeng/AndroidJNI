#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//结构体是一种构造数据类型
//把不同的数据类型整合起来成为一个自定义的数据类型
/*
struct Man{
	//成员
	char name[20];
	int age;
	//int(*func)();
};

void main(){
	//初始化结构体的变量
	//1.
	//struct Man m1 = {"Jack", 21};
	//2.
	struct Man m1;
	m1.age = 23;
	//m1.name = "Rose";
	strcpy(m1.name,"rose");
	sprintf(m1.name,"Jason");

	//类似JavaScript字面量赋值，只能在变量声明时赋值
	//m1 = {};
	struct Man m2 = m1;

	printf("%s,%d\n",m1.name,m1.age);

	getchar();
}
*/

//结构体的几种写法
/*
struct Man{
	char name[20];
	int age;
} m1, m2 = {"jack",20}; //m1结构体变量名

//typedef int Age;

void main(){
	
	strcpy(m1.name,"Jack");
	m1.age = 10;

	printf("%s,%d\n", m2.name, m2.age);

	getchar();
}
*/

//匿名结构体
//控制结构体变量的个数（限量版），相当于单例
/*
struct{
	char name[20];
	int age;
}m1;
*/

//结构体嵌套
/*
struct Teacher{
	char name[20];
};

struct Student{
	char name[20];
	int age;
	struct Teacher t;
};

void main(){
	//字面量的方式
	//struct Student s1 = { "jack", 21, {"Jason"} };
	struct Student s1;
	s1.age = 10;
	strcpy(s1.t.name, "Jason");
	system("pause");
}
*/

//结构体嵌套2
/*
struct Student{
	char name[20];
	int age;
	struct Teacher{
		char name[20];
	} t;
};

void main(){
	struct Student s1;
	strcpy(s1.t.name, "Jason");
	//struct Teacher t;
	

	system("pause");
}
*/

//结构体与指针
/*
struct Man{
	char name[20];
	int age;
};
void main(){
	struct Man m1 = {"Jack",30};
	//结构体指针
	struct Man *p = &m1;
	printf("%s,%d\n", m1.name, m1.age);
	printf("%s,%d\n",(*p).name,(*p).age);
	//“->”（箭头）是“(*p).”简写形式
	printf("%s,%d\n", p->name, p->age);
	//(*env)->

	system("pause");
}
*/

//指针与结构体数组
/*
struct Man{
	char name[20];
	int age;
};
void main(){	
	struct Man mans[] = { {"Jack",20}, {"Rose", 19} };
	//遍历结构体数组
	//1.
	struct Man *p = mans;
	for (; p < mans + 2; p++){
		printf("%s,%d\n", p->name, p->age);
	}

	//2.
	int i = 0;
	for (; i < sizeof(mans) / sizeof(struct Man); i++){
		printf("%s,%d\n", mans[i].name, mans[i].age);
	}
	
	//(*env)->

	system("pause");
}
*/

//结构体的大小（字节对齐）
/*
struct Man{
	int age;
	double weight;	
};

void main(){
	//结构体变量的大小，必须是最宽基本数据类型的整数倍
	//提升读取的效率
	struct Man m1 = {20,89.0};
	printf("%#x,%d\n", &m1,sizeof(m1));
	getchar();
}
*/

struct Man{
	char *name;
	int age;
};
//结构体与动态内存分配
/*
void main(){
	struct Man *m_p = (struct Man*)malloc(sizeof(struct Man) * 10);
	struct Man *p = m_p;
	//赋值
	p->name = "Jack";
	p->age = 20;
	p++;
	p->name = "Rose";
	p->age = 20;
	
	struct Man *loop_p = m_p;
	for (; loop_p < m_p + 2; loop_p++){
		printf("%s,%d\n", loop_p->name, loop_p->age);
	}

	free(m_p);
	getchar();
}
*/

/*
//typedef 类型取别名
//1.不同名称代表在干不同的事情typedef int jint;  
//2.不同情况下，使用不同的别名
//#if defined(__cplusplus)
//typedef _JNIEnv JNIEnv;
//typedef _JavaVM JavaVM;
//3.书写简洁

struct Man{
	char name[20];
	int age;
};

//Age int类型的别名
typedef int Age;
//Age int类型指针的别名
typedef int* Ap;

typedef struct Man JavaMan;
typedef struct Man* JM;

//结构体取别名
//typedef struct Woman W;
//typedef struct Woman* WP;
//简写
typedef struct Woman{
	char name[20];
	int age;
} W, *WP;  //W 是woman结构体的别名, WP 是woman结构体指针的别名

void main(){
	int i = 5;
	Ap p = &i;

	//结构体变量
	W w1 = {"Rose",20};
	//结构体指针
	WP wp1 = &w1;
	printf("%s,%d\n", w1.name, w1.age);
	printf("%s,%d\n", wp1->name, wp1->age);

	getchar();
}
*/

//结构体函数指针成员
/*
struct Girl{
	char *name;
	int age;
	//函数指针
	void(*sayHi)(char*);
};
//Girl结构体类似于Java中的类，name和age类似于属性，sayHi类似于方法

void sayHi(char* text){
	MessageBoxA(0, text, "title", 0);
}

void main(){
	struct Girl g1;
	g1.name = "Lucy";
	g1.age = 18;
	g1.sayHi = sayHi;

	g1.sayHi("hello");

	getchar();
}
*/

typedef struct Girl{
	char *name;
	int age;
	//函数指针
	void(*sayHi)(char*);
}Girl;

//Girl结构体指针取别名GirlP
typedef Girl* GirlP;

void sayHi(char* text){
	MessageBoxA(0, text, "title", 0);
}

//改名
void rename(GirlP gp1){
	gp1->name = "Lily";
}

void main(){
	Girl g1 = { "Lucy", 18, sayHi };
	GirlP gp1 = &g1;
	gp1->sayHi("Byebye!");
	//传递指针，改名
	rename(gp1);

	getchar();
}