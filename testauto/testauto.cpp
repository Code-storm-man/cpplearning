// testauto.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 测试内容：学会auto的使用
// 1. auto 可以确保变量被初始化
// 2. 代码的简洁、后面的泛型编程用得更多
// 3. 简化代码，比如后面的迭代器代码简化，并在替换容器后代码可以不变
// 4. 从初始化器推导类型
// 5. 建议优先使用auto去定义变量

#include <iostream>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    // 普通变量
    constexpr int cex{ 300 };
	cout << "cex = " << cex << endl;

    {
        // auto 赋初始值等号和大括号是等效的，但是还是统一用大括号
        // 但对于前面的变量来说只用大括号的形式
        auto a1 = 10;
        auto d1 = 9.;
        auto f1 = 8.f;
        auto acex = cex; // auto 推导常量时会变为普通变量
        const auto c2 = a1;
		constexpr auto c1 = cex; // constexpr 变量
        auto a3{ 11.3 };
        auto a4 = 14LL;
        auto a5 = (int)d1; // auto支持的强制转换
    }




}


