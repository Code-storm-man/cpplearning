// 2025-12-08
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

/* 
    此代码用于测试cout输出
    用于测试变量的学习
*/

#include <iostream>  // 将iostream文件复制到当前位置  <> 表示环境中自带的文件

// 命名空间输入简化
using namespace std;  // 使用标准命名空间

int main()
{
    std::cout << "Hello World!\n";

    // std::endl 换行并刷新缓冲
    cout << "Hello Count" << endl;

    // cout输出多个内容
    cout << "字符串一" << 200 << "\n";

    // 定义一个int类型的变量x
    // 如果不给他初始化值，那这个值不确定
	//int y; // 定义了一个整型变量y，但未初始化
    //cout << "y=" << y << endl; // 会报错
	int x{ 100 }; // 定义了一个整型变量x，并初始化为100
    cout << "变量x的值为" << x << endl;
    // 通过变量前面加 & 符号获取变量的内存地址
    // 简单的强制转换（类型）
    cout << "变量x的内存地址为" 
        << (long long) & x 
        << endl;

    int z{ 200 };
    cout << "变量z的内存地址为" 
        << (long long) & z
        << endl;

    // sizeof() 获取变量所占用内存大小
    cout << "int x 的内存大小"
        << sizeof(x) << "字节"
        << endl;

    long long bigint{ 0 };
    cout << "long long bigint 内存大小"
        << sizeof(bigint) << "字节"
        << endl;

}
 