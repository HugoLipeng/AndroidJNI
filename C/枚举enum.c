#include<stdio.h>
#include<stdlib.h>

/**
枚举的值递增 
默认首元素的值是0 
*/
enum WeekDay {
     Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday
};
 
int main() {
       enum WeekDay day = Wednesday;
       printf("%d\n",day);
       return 0;
}