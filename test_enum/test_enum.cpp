// test_enum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 项目内容：学习C++ 枚举类型的使用

#include <iostream>
using namespace std;

enum 枚举类型名
{
    枚举值1,
    枚举值2,
	枚举值3 = 100,
	枚举值4
};

enum STATUS
{
	PLAY,
	PUASE,
	STOP
};


// C++ 11 的枚举写法
// 访问这个枚举类型里面的变量变成了 LogLevel::DEBUG
enum class LogLevel
{
	DEBUG,
	INFO,
	ERROR,
	FATAL
};


// 枚举类型的功能
// 1、替代整数
// 2、判断大小

int main()
{
	LogLevel level{ LogLevel::DEBUG };
	int s = static_cast<int>(level);
	LogLevel log_level = LogLevel::DEBUG;
	if (level <= log_level)
	{
		cout << "记录日志" << endl;
	}

	// 给ev1赋值，赋值 枚举类型名 中枚举值3
	枚举类型名 ev1{ 枚举值3};
	cout << "枚举值1 =" << 枚举值1 << endl;
	cout << "枚举值3 =" << 枚举值3 << endl;
	
	STATUS status{ STOP };
	if (status == 2)
	{
		cout << "2 STOP" << endl;
	}
}

