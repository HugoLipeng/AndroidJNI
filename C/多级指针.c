#include<stdio.h>
#include<stdlib.h>

/**
 多级指针 
 指针指向的是内存地址
 地址就是指针 
*/

int main(){
  
  //定义一个int类型的变量i,并且赋值为100； 
  int i = 100;  
  //定义一个int类型的一级指针变量address1,并且把i的地址赋值给它 
  int* address1 = &i;
  //定义一个int类型的二级指针变量 address2，并且把 address1对应的地址赋值给它 
  int** address2 = &address1;
  //定义三级指针 
  int*** address3 =  &address2;
  //定义四级指针 
 // int**** address4 =  &address3;
  
  //多级指针取值 ****address4得到的值是100
  printf("***address3==%d\n",***address3); 
  //*address4
  ***address3 = 2000;
  printf("***address3==%d\n",***address3); 
  return 0;
//   system("pause");      
} 