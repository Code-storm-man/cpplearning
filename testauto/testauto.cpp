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
        auto a1 = 10;
        auto d1 = 9.;
        auto f1 = 8.f;
        auto acex = cex; // auto 推导常量时会变为普通变量

    }




}


