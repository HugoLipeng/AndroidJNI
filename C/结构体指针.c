#include <stdio.h>
#include <stdlib.h>

//结构体指针

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

    //结构体指针
    struct student *point = &stu;

    struct student **point2 = &point;

    //取值运算(*point).age  等价于 point->age
    printf("(*point).age ==%d\n", (*point).age);
    printf("point->age ==%d\n", point->age);
    printf("point->score ==%f\n", point->score);
    printf("point->sex ==%c\n", point->sex);
    //赋值运算
    point->age = 20;
    point->score = 100;
    point->sex = 'M';
    printf("point->age ==%d\n", point->age);
    printf("point->age ==%d\n", point->age);
    printf("point->score ==%f\n", point->score);
    printf("point->sex ==%c\n", point->sex);

    //二级结构体指针取值 (*point).age  等价于 point->age   所以  (**point).age 等价于 (*point)->age
    printf("(**point2).age ==%d\n", (**point2).age);
    printf("(*point2)->age ==%d\n", (*point2)->age);
    //二级指针赋值
    (**point2).age = 2000;
    printf("(**point2).age ==%d\n", (**point2).age);
    printf("(*point2)->age ==%d\n", (*point2)->age);
    return 0;
}