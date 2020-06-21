#include <stdio.h>

int main (){
    printf("hello world! \n");
    //数组在内存中连续存储
	int ids[] = { 78, 90, 23, 65, 19 };
	//数组变量名：ids就是数组的首地址
	printf("%d\n",ids);
	printf("%d\n",&ids);
	printf("%d\n",&ids[0]);
	//指针变量
	int *p = ids;
	printf("%d\n",*p);
	//指针的加法
	p++; //p++向前移动sizeof(数据类型)个字节
	printf("p的值:%d\n", p);
	//p--;
	printf("%d\n", *p);
	// getchar();
    return 0;
}