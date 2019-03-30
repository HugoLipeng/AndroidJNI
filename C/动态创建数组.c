#include <stdio.h>
#include <stdlib.h>

/**
 动态创建数组 
 输出函数 printf(); 
 输入函数：scanf("占位符"，内存地址); 
 realloc()重新分配内存 
*/

int main()
{

    // 动态数组的创建
    printf("请输入您要创建数组的长度:\n");
    //1、让用户输入一个长度
    int length;
    scanf("%d", &length);
    printf("您输入数组的长度为:%d\n", length);
    //2、根据长度，分配内存空间
    int *iArray = malloc(length * 4);
    //3、让用户把数组中的元素依次的赋值；
    int i;
    for (i = 0; i < length; i++)
    {
        printf("请输入iArray[%d]的值：", i);
        scanf("%d", iArray + i);
    }
    //4、接收用户输入扩展数组长度
    int suppLength;
    printf("请输入您要扩展数组的长度:\n");
    scanf("%d", &suppLength);
    printf("您要扩展数组的长度:%d\n", suppLength);
    //5、根据扩展的长度重新分配空间�
    //realloc
    iArray = realloc(iArray, (length + suppLength) * 4);
    //6、把扩展长度的元素让用户赋值；
    for (i = length; i < length + suppLength; i++)
    {
        printf("请输入iArray[%d]的值：", i);
        scanf("%d", iArray + i);
    }
    //7、输出数组�
    for (i = 0; i < length + suppLength; i++)
    {
        printf("iArray[%d]==%d\n", i, *(iArray + i));
    }
    return 0;
}