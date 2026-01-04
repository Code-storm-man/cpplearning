// testconst.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 测试内容：区分运行时常量和编译时常量
// const constexpr

#include <iostream>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";

	// 大部分情况都用编译时常量
	// 涉及到参数传递时才用运行时常量



    // 运行时常量
    const int cx{ 100 };
	//cx = 100; // 修改编译时会报错
	cout << "cx: " << cx << std::endl;
	// 编译时常量
	constexpr int cy{ 200 };
	cout << "cy: " << cy << std::endl;
	int t1 = 10;
	// 运行时常量如果在运行时被外部设备传入值，如下面的传入值t1+10
	const int cx2{ t1 + 10 };
	cout << "cx2: " << cx2 << std::endl;

	// 编译时常量必须在编译时就能确定值
	//constexpr int cy2{ t1 * 10 };

	return 0;
}

  

