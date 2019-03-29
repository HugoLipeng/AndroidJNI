#include<stdio.h>
#include<stdlib.h>

/**

输出函数 
printf("你要输出的内容");


%d  -  int
%ld - long int
%c  - char
%f -  float
%u - 无符号数
%hd - 短整型
%lf - double
%x - 十六进制输出 int 或者long int 或者short int
%o -  八进制输出
%s - 字符串
 
 printf("你要输出的内容对应的占位符");
 在C语言中，默认保留小数点后六位 
 要想保留对应的位数，就需要在百分号后边加上“.数字” 
 
 十进制：12345678
 二进制：101111000110000101001110 
                  110000101001110

 不同的类型，要用不同的占位去输出，否则精度丢失。 
*/ 

int main(){
       
       char c = 'A';
       int i = 12345678;
       long l = 123456789;
       float f = 3.1415;
       double d = 3.1415926535;
       
       printf("c==%c\n",c); 
       printf("i==%d\n",i); 
       printf("l==%ld\n",l); 
       printf("f==%.4f\n",f); 
       printf("d==%.10lf\n",d); 
       
       printf("i==%hd\n",i); 
       //C语言的数组的括号不能写在左边 
       char cArray[]   = {'A','B'};
       
       printf("cArray内存地址==%#x\n",&cArray); 
       
       char* text = "I love you!";
       
       printf("text内容==%s\n",text); 
       
       return 0;
    //    system("pause");
}
       
       
       
       
       
       
       
       
       
       
       
        
