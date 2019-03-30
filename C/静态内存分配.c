#include<stdio.h>
#include<stdlib.h>

/**
 静态内存分配 
 https://www.cnblogs.com/netlyf/archive/2009/12/15/1624456.html
*/

void func(int** address){
     //定义int类型的i变量，并且赋值100 
     int i = 100;
     // 把i对应的地址赋值给 iPoint变量 
     *address = &i; 
}
int main(){
      
      //定义int类型的一级指针变量 iPoint
     int* iPoint; 
     
     func(&iPoint); //一级指针的地址 对应 二级指针 int** address
     printf("*iPoint===%d\n",*iPoint);
     printf("*iPoint===%d\n",*iPoint);
     printf("*iPoint===%d\n",*iPoint);
    //  *iPoint===100  
    //  *iPoint===0  系统回收
    //  *iPoint===0
     return 0;
}       