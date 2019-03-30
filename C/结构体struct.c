#include <stdio.h>
#include <stdlib.h>

//结构体

//定义结构
struct student
{
    int age;     //4个字节
    float score; //4个字节
    char sex;    //1个字节
};
int main()
{
    //使用结构图
    struct student stu = {18, 98.9, 'W'};
    //结构体取值
    printf("stu.age==%d\n", stu.age);
    printf("stu.score==%.1f\n", stu.score);
    printf("stu.sex==%c\n", stu.sex);
    //结构体赋值
    stu.age = 20;
    stu.score = 100;
    stu.sex = 'M';
    printf("stu.age==%d\n", stu.age);
    printf("stu.score==%.1f\n", stu.score);
    printf("stu.sex==%c\n", stu.sex);
    //结构体的长度
    printf("struct student长度==%d\n", sizeof(struct student));
    return 0;
}