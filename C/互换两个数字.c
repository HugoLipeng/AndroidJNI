#include<stdio.h>
#include<stdlib.h>

/**
 互换两个数 
*/
void sitch(int a,int b){//传值无法改变值 
   int temp = a;
   a = b;
   b = temp; 
   printf("sitch 中a地址===%#x\n",&a); 
   printf("sitch 中b地址===%#x\n",&b); 
     
}

void sitch2(int* a,int* b){//传地址可以改变值 
   int temp = *a;
   *a = *b;
   *b = temp; 
   printf("sitch 中a地址===%#x\n",a); 
   printf("sitch 中b地址===%#x\n",b); 
     
}
main(){
   
   int a = 100;
   int b = 200;
   printf("main中a地址===%#x\n",&a); 
   printf("main中b地址===%#x\n",&b); 
   printf("a===%d\n",a); 
   printf("b===%d\n",b); 
   sitch2(&a,&b);
   printf("a===%d\n",a); 
   printf("b===%d\n",b); 
   
 
  
   
       
  system("pause");     
}     