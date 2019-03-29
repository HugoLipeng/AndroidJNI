#include<stdio.h>
#include<stdlib.h>

/**
输入函数 
scanf("占位符"，内地地址) 
%d  -  int
%ld - long int
%c  - char
%f -  float
%u – 无符号数
%hd – 短整型
%lf –double
%x – 十六进制输出爄nt 或者long int 或者short int
%o -  八进制输出
%s – 字符串

  System.in();
*/ 

int main(){
       
       int i ;
       printf("亲，请你输入一个你认为最帅的数字：\n"); 
       scanf("%d",&i);
       printf("您输入的数字是：%d\n",i); 

       char cArray[5];
       printf("请输入hello：\n");
       //C语言中没有String类型，但是可以用char数组来表示
       scanf("%s",&cArray);
       
      
       //在C语言中没有String 类型，但是可以用char数组来表示 
       int j;
       for( j=0;j<5;j++){
           
           printf("cArray[%d]==%c\n",j,cArray[j]);    
                
       }
       
       printf("cArray==%s\n",cArray); 

       //输入 
        char bArray[] = {'a','b','c','d','e','\0','a','b'}; //\0代表结束 
         //数组是一块连续的内存空间 
        printf("bArray==%s\n",bArray); 
        char* text = "I love you!!";
        printf("text==%s\n",text); 
        
        return 0;
    //    system("pause");
}