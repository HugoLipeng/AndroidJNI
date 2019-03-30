#include<stdio.h>
#include<stdlib.h>

/**
 动态内存分配 
 https://zhuanlan.zhihu.com/p/40536998
*/

void func(int** address){
    int i = 100;
    int* temp;
    //malloc(int)-内存地址 
    temp = malloc(sizeof(int)); 
    //把i对应的值，赋值给 temp地址对应的值 
    *temp = i;
    //把address 对应的地址对应的值修改成 temp
    *address = temp;
    free(temp); 
}
int main(){
      //定义int类型的一级指针变量 iPoint
     int* iPoint; 
     func(&iPoint); 
     printf("*iPoint===%d\n",*iPoint);
     printf("*iPoint===%d\n",*iPoint);
     printf("*iPoint===%d\n",*iPoint);
     printf("*iPoint===%d\n",*iPoint);
     return 0;
}       