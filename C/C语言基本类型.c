#include<stdio.h>
#include<stdlib.h>

/**
C语言基本类型 
char, int, float, double, long, short, signed, unsigned, void
计算类型的长度：sizeof("类型")返回int类型的长度
占位符：%d 
printf("内容");
java基本数据类和C语言的一些区别
1.Java中char类型的长度为2个字节，C语言中的长度为1个字节
2.Java中long类型的长度为8个字节，C语言中的长度为4个字节
  C99标准规定：long类型的规定，不小于整形。
3.C语言中没有byte
4.C语言中 boolean类型，0表示flase,非零表示true 
 signed : 有符号：-128~127 = -2^7~ 2^7-1 
 unsigned：无符号 0~255 = 0~2^8-1 
 void: 无类型，代表任意类型 
*/

int main()
{
  
 
   printf("int类型的长度为：%d\n",sizeof(int)); 
   printf("char类型的长度为：%d\n",sizeof(char)); 
   printf("float类型的长度为：%d\n",sizeof(float)); 
   printf("long类型的长度为：%d\n",sizeof(long));
   printf("short类型的长度为：%d\n",sizeof(short));    
   
   if(-1){
        printf("true\n");       
   }else{
         printf("flase\n");     
   }         
   return 0;
//   system("pause"); 
 
}
       
       
       

