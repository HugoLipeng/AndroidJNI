#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//使用字符数组存储字符串
/*
void main(){
	//char str[] = {'c','h','i','n','a','\0'};
	//char str[6] = { 'c', 'h', 'i', 'n', 'a' };
	char str[10] = "china";
	//可以修改
	str[0] = 's';

	printf("%s\n",str);
	printf("%#x\n", str);
	getchar();
}
*/

//字符指针
/*
void main(){
	//内存连续排列
	char *str = "how are you?";

	//不可以修改
	//str += 1;
	//*str = 'y';
	printf("%s\n", str);
	printf("%#x\n", str);

	//使用指针加法，截取字符串
	str += 3;
	while (*str){
		printf("%c",*str);
		str++;
	}
	printf("\n结束了");
	getchar();
}
*/

//strcat字符串拼接函数
//在线API文档：
//http://www.kuqin.com/clib/string/strcpy.html
/*
void main(void){
	char dest[50];	
	char *a = "china";
	char *b = " is powerful!";
	strcpy(dest, a);
	strcat(dest, b);
	printf("%s\n", dest);

	system("pause");
}
*/


//strchr在一个串中查找给定字符的第一个匹配之处
/*
void main(void){
	char *str = "I want go to USA!";
	printf("%#x\n", str);
	//U元素的指针
	//str+3
	char* p = strchr(str, 'w');
	if (p){
		printf("索引位置：%d\n", p - str);
	}
	else{
		printf("没有找到");
	}

	system("pause");
}
*/

//strstr 从字符串haystack中寻找needle第一次出现的位置

void main(void){
	char *haystack = "I want go to USA!";
	char *needle = "to";
	//U元素的指针

	char* p = strstr(haystack, needle);
	if (p){
		printf("索引位置：%d\n", p - haystack);
	}
	else{
		printf("没有找到");
	}

	system("pause");
}