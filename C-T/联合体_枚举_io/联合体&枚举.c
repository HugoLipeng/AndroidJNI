#include "stdlib.h"
#include "stdio.h"

//联合体（共用体）
//不同类型的变量共同占用一段内存（相互覆盖），联合变量任何时刻只有一个成员存在，节省内存
//联合体变量的大小=最大的成员所占的字节数
//比喻：同穿一条裤子
/*
union  MyValue{
	int x;
	int y;
	double z;
};

void main(){
	union MyValue d1;
	d1.x = 90;
	d1.y = 100; //最后一次赋值有效
	//d1.z = 23.8;

	printf("%d,%d,%lf\n",d1.x,d1.y,d1.z);
	system("pause");
}
*/

/*
typedef union jvalue {
	jboolean    z;
	jbyte       b;
	jchar       c;
	jshort      s;
	jint        i;
	jlong       j;
	jfloat      f;
	jdouble     d;
	jobject     l;
} jvalue;
*/

//枚举（列举所有的情况）
//限定值，保证取值的安全性
//enumeration
//enum Day
//{
//	Monday = 0,
//	Tuesday = 1,
//	Wednesday = 2,
//	Thursday = 3,
//	Friday = 4,
//	Saturday = 5,
//	Sunday = 6
//};
/*
enum Day
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};


void main(){
	//枚举的值，必须是括号中的值
	enum Day d = Monday;
	printf("%#x,%d\n",&d,d);
	
	getchar();
}
*/