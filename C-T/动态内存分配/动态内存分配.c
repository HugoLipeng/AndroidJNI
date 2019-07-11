#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//动态内存分配
/*
void main(){
	//40M
	//stack overflow错误，栈溢出
	//静态内存分配
	int a[1024 * 1024 * 10];
	//栈内存

	//C语言内存分配：
	//1.栈区(stack)
	//windows下，栈内存分配2M（确定的常数），超出了限制，提示stack overflow错误
	//自动分配，释放
	//2.堆区(heap)
	//程序员手动分配释放，操作系统80%内存
	//3.全局区或静态区
	//4.字符常量区
	//5.程序代码区

	getchar();
}
*/

/*
//栈内存
void stackFun(){
	int a[1024];
	//栈内存自动释放
}

//堆内存
void heapFun(){
	//40M内存
	//字节
	//void *任意类型的指针
	int* p = malloc(1024 * 1024 * 10 * sizeof(int));

	//释放
	free(p);
}

void main(){	
	//在堆内存上，分配40M的内存
	while (1){
		Sleep(1000);	
		stackFun();
	}

	getchar();
}
*/

//创建一个数组，动态指定数组的大小
//（在程序运行过长中，可以随意的开辟指定大小的内存，以供使用，相当于Java中的集合）
//静态内存分配，分配内存大小的是固定，问题：1.很容易超出栈内存的最大值 2.为了防止内存不够用会开辟更多的内存，容易浪费内存
//动态内存分配，在程序运行过程中，动态指定需要使用的内存大小，手动释放，释放之后这些内存还可以被重新使用（活水）
/*
void main(){
	//静态内存分配创建数组，数组的大小是固定的
	//int i = 10;
	//int a[i];

	int len;
	printf("输入数组的长度：");
	scanf("%d",&len);

	//开辟内存，大小len*4字节
	int* p = malloc(len * sizeof(int));
	//p是数组的首地址，p就是数组的名称
	//给数组元素赋值（使用这一块刚刚开辟出来的内存区域）
	int i = 0;
	for (; i < len - 1; i++){
		p[i] = rand() % 100;
		printf("%d,%#x\n", p[i], &p[i]);
	}
	
	//手动释放内存
	free(p);

	getchar();
}
*/

//realloc 重新分配内存
/*
void main(){
	int len;
	printf("第一次输入数组的长度：");
	scanf("%d", &len);

	//int* p = malloc(len * sizeof(int));	
	int* p = calloc(len, sizeof(int));
	int i = 0;
	for (; i < len; i++){
		p[i] = rand() % 100;
		printf("%d,%#x\n", p[i], &p[i]);
	}

	int addLen;
	printf("输入数组增加的长度：");
	scanf("%d", &addLen);
	//内存不够用，扩大刚刚分配的内存空间
	//1.原来内存的指针 2.内存扩大之后的总大小		
	int* p2 = realloc(p, sizeof(int) * (len + addLen));
	if (p2 == NULL){
		printf("重新分配失败，世界那么大，容不下我。。。");
	}
	//重新分配内存的两种情况：
	//缩小，缩小的那一部分数据会丢失
	//扩大，（连续的）
	//1.如果当前内存段后面有需要的内存空间，直接扩展这段内存空间，realloc返回原指针
	//2.如果当前内存段后面的空闲字节不够，那么就使用堆中的第一个能够满足这一要求的内存块，将目前的数据复制到新的位置，并将原来的数据库释放掉，返回新的内存地址
	//3.如果申请失败，返回NULL，原来的指针仍然有效

	//重新赋值
	i = 0;
	printf("--------------------------\n");
	for (; i < len + addLen; i++){
		p2[i] = rand() % 200;
		printf("%d,%#x\n", p2[i], &p2[i]);
	}

	//手动释放内存
	if (p != NULL){
		free(p);
		p = NULL;
	}	
	if (p2 != NULL){
		free(p2);
		p2 = NULL;
	}

	getchar();
}
*/

//内存分配的几个注意细节
//1.不能多次释放
//2.释放完之后（指针仍然有值），给指针置NULL，标志释放完成
//3.内存泄露（p重新赋值之后，再free，并没有真正释放内存）
/*
void main(){
	int len;
	printf("输入数组的长度：");
	scanf("%d", &len);

	int* p = malloc(len * sizeof(int));		
	int i = 0;
	for (; i < len; i++){
		p[i] = rand() % 100;
		printf("%d,%#x\n", p[i], &p[i]);
	}

	if (p != NULL){
		free(p);
		p = NULL;
	}

	getchar();
}
*/

void main(){
	//40M
	int* p1 = malloc(1024 * 1024 * 10 * sizeof(int));
	free(p1);
	p1 = NULL;
	printf("%#x\n",p1);

	//80M
	p1 = malloc(1024 * 1024 * 10 * sizeof(int) * 2);
	
	free(p1);
	p1 = NULL;

	getchar();
}