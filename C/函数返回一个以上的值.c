#include<stdio.h>
#include<stdlib.h>

/**
 返回多个值 
*/
void colse(int* a,int* b){
    *a = 0;
    *b = 0; 
      
}
main(){
   
   //一健关闭GPS和wifi
   //1代表的是开，0代表是关闭 
   int a = 1;
   int b = 1;
  
   colse(&a,&b);
  
   
   printf("a===%d\n",a); 
   printf("b===%d\n",b); 

  system("pause");     
}     
