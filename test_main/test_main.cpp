// test_main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。


#include <iostream>
using namespace std;

int main(int argc, char *argv[], char *env[])
{
	// 传递了三个参数 DEBUG 16 13.14
	// argc 在不传递参数的时候，默认值为1
	cout << "argc = " << argc << endl;
	
	// argv[0] 存储的是程序的名称，不传递参数时也可以生成
	// 生成的是执行程序exe的全局路径
	cout << "argv[0] = " << argv[0] << endl;

	if (argc > 1)
	{
		cout << argv[1] << endl;
	}

	if (argc > 2)
	{
		cout << argv[2] << endl;
	}

	if (argc > 3)
	{
		cout << argv[3] << endl;
	}

	cout << env[0] << endl;

}

