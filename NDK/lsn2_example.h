// lsn2_example.h: 标准系统包含文件的包含文件，
// 或特定于项目的包含文件。

#pragma once

#include <iostream>

#define DEBUG


inline int test2(int x,int y) {
	
	return  x * y;
}

void aaa(){
	test2(1, 2);
	int j = 1 * 2;
}

//文本替换 代码中所有的I 就会被预处理器 替换为 1
//1、宏变量
#define I 1 
//2、宏函数
#define TEST(i) printf("%d\n",i)
#define ADD(x,y) x * y ;
//  \ 换行
#define TEST1(x) if(x) {  \
  	\
} else { \
	\
} 


// TODO: 在此处引用程序需要的其他标头。
