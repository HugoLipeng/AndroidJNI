// lsn3_cpp.cpp: 定义应用程序的入口点。
//

#include "lsn3_cpp.h"


// #include "a.h"


namespace A {
	namespace B {
		void test() {

		}
	}
}

using namespace std;
using namespace A;
using namespace A::B;




void change(int& j) {
	j = 11;
}

int ii;

int main()
{
	ii = 11;
	int ii = 10;
	cout << ii << endl;
	//操作重名的全局变量的时候 可以使用域作用符
	cout << ::ii << endl;
	::ii = 88;
	ii = 11;
	cout << ::ii << endl;
	//:: 域作用符
	A::B::test();
	B::test();
	test();

	cout << "Hello CMake。" << endl;
	// 1、c与c++ 兼容
	// test(1,2);

	//2、 引用
	int i = 10;
	// int&  引用类型
	// 10这个内存地址 给了个别名 j
	int& j = i;
	change(j);
	cout << i << endl;
	cout << j << endl;
	// i是一个标签， 再创建一个j标签 表示 10 保存的地址
	
	//3、字符串
	//c 使用 NULL \0 结尾的一个字符数组
	char c_str1[] = { 'h','e','l','\0' };
	//默认给我们在末尾增加 \0
	char *c_str2 = "hello";
	cout <<  "c_str1:" << c_str1 << endl;
	cout << "c_str2:" << c_str2 << endl;
	char c_str3[10];
	strcpy(c_str3, c_str1);
	cout << "c_str3:" << c_str3 << endl;
	
	//c++ string 类  #include <string>
	
	string str1 = "hello";
	//调用构造方法
	string str2(str1);
	string str3("天之道");
	//申请内存 调用构造方法
	string *str4 = new string("David爱去找88号技师");
	
	// 拼接字符串
	// + 操作符重载:重新定义 的 行为
	string str5 = str1 + str3;

	str1.append(str3);

	//获得c的字符串
	cout << str1.c_str() << endl;

	//获得字符串长度
	str1.size();
	str1.empty();
	//......
	// 1、出方法 清理栈
	// 2、指针 4/8 对象 x个字节 效率更高
	str4->c_str();


	//4、命名空间  package
	



	//释放内存
	delete str4;
	//malloc = free
	// new = delete 
	// new 数组 = delete[] 
	system("pause");
	return 0;
}
