#include <stdio.h>
#include <stdlib.h>
/*
联合体 
 
*/

//定义一个联合体，特点，所有的字段都是使用同一块内存空间；
union Mix {
    long i;  //4个字节
    int k;   //4个字节
    char ii; //1个字节
};
int main()
{

    printf("mix:%d\n", sizeof(union Mix));

    //实验
    union Mix m;

    m.k = 123;
    m.i = 100;
    printf("m.i=%d\n", m.i);
    printf("m.k=%d\n", m.k);
    return 0;
}
