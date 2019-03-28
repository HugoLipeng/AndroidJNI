#include <stdio.h>//#include 相当于Java的import  ;stdio : standard input$output 标准的输入输出 ； .h 头文件的后缀；包含一些函数 
#include <stdlib.h>// 到标准的C语言函数库 
int main()//想当于Java 的public static void main(String args[]){}
{//函数的开始 
    printf("Hello world !\n");//printf(内容)输出函数 ，相当于Java的System.out.print("Hello world !\n"); \n是回车换行 
    //   system("calc");//调起计算器 
    //   system("mspaint");//调起画版 
    //   system("services.msc");//调起画版 
    //   system("java Hello");//执行字节码 
    //   system("pause");//让docs命令行执行pause命令，作用是控制台停留。 
    return 0;
}//函数的结束 