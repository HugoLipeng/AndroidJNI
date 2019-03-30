#include<stdio.h>
#include<stdlib.h>

/**
 数组的介绍
 1.数组的取值
 2.数组的取地址
 3.数组是一块连续的内地空间
 4.数组的首元素的首地址和数组的地址相同 
 4.数组的设计
 5.用户输入数组
  
*/

int main(){
  
  char cArray[] = {'H','E','L','L','O'}; 
  int iArray[] = {1,2,3,4,5};
  //取数组的值
  printf("cArray[0]==%c\n",cArray[0]);  
  printf("cArray[1]==%c\n",cArray[1]); 
  
  
  printf("iArray[0]==%d\n",iArray[0]);  
  printf("iArray[1]==%d\n",iArray[1]); 
  
  //取内存地址值 
   printf("cArray地址==%#x\n",&cArray); 
   printf("cArray[0]地址==%#x\n",&cArray[0]);  
   printf("cArray[1]地址==%#x\n",&cArray[1]); 
   printf("cArray[2]地址==%#x\n",&cArray[2]); 
   
   printf("cArray地址==%#x\n",cArray); 
   printf("cArray+0地址==%#x\n",cArray+0);  
   printf("cArray+1地址==%#x\n", cArray+1); 
   printf("cArray+2地址==%#x\n", cArray+2); 
   
     printf("iArray + 0==%#x\n",iArray+0);
     printf("iArray + 1==%#x\n",iArray+1);
     printf("iArray + 2==%#x\n",iArray+2);  
     printf("iArray + 3==%#x\n",iArray+3);  
   
   //内存是一块连续的内存空间 
   printf("iArray地址==%#x\n",&iArray);  
   printf("iArray[0]地址==%#x\n",&iArray[0]);  
   printf("iArray[1]地址==%#x\n",&iArray[1]); 
   printf("iArray[2]地址==%#x\n",&iArray[2]); 
   printf("iArray[3]地址==%#x\n",&iArray[3]); 
   
   //用指针取值
     printf("iArray==%d\n",*iArray);  
     printf("iArray[0]==%d\n",*iArray+0);
     printf("iArray[1]==%d\n",*iArray+5);
     printf("iArray[2]==%d\n",*iArray+6);  
     printf("iArray[3]==%d\n",*iArray+7);  
     
     printf("iArray[0]==%d\n",*(iArray+0));
     printf("iArray[1]==%d\n",*(iArray+1));
     printf("iArray[2]==%d\n",*(iArray+2));  
     printf("iArray[3]==%d\n",*(iArray+3));  

       printf("请输入数组的长度：\n"); 
     //1.用户输入数组的长度
      int length;
      scanf("%d",&length);
      printf("您输入的数组长度为：%d\n",length);
     //2.根据用户输入的长度创建数组
     int yArray[length]; 
     //3.让用户输入数组的值
     int i;
     for(i=0;i<length;i++){
        printf("请输入iArray[%d]的值:\n",i);  
        //scanf("%d",&yArray[i]); 
         scanf("%d",yArray+i);                 
     }                     
     //4.把数组内容打印出来 
     for(i=0;i<length;i++){
        printf("yArray[%d]==%d\n",i,*(yArray+i));  
                       
     }  
   
     return 0; 
} 
