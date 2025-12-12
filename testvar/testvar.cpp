// 2025-12-09
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

/*
    此代码用于测试变量的运算
*/

#include <iostream>  // 将iostream文件复制到当前位置  <> 表示环境中自带的文件

// 命名空间输入简化
using namespace std;  // 使用标准命名空间

int main()
{
    cout << "welcome TestVar" << endl;

    // 类型 变量名{初始化值}
    // 整数int 字面量
    cout << 123 << -123 << endl;
    cout << 123LL << endl;
    cout << "sizeof(123) "
        << sizeof(123) << "个字节" << endl;
    cout << "sizeof(123LL) "
        << sizeof(123LL) << "个字节" << endl;

    // 浮点类型的字面量
    float f1{ 1.3f };
    f1 = 1.f;
    f1 = 2.0f;
    f1 = 3.3; // 将double类型的字面量赋值给float会损失精度

    double d1{ 1.4 };
    1.5;

    // 运算符支持字面量
    int x{ 1 + 2 };
    cout << " x = " << x << endl;
    int y{ 3 };
    int z{ x + y };
    z = x + y + 1;
    z = x * y + 10;
    cout << " z = " << z << endl;

    // 自增 自减
    z += 10;
    z -= 5;
    z *= 4;
    z /= 2;
    z++; // z = z + 1
    z--;
    ++z;
    --z;
    cout << " z = " << z << endl;

    // 除法运算的特性
    int u{ 0 };
    u = 10 / 2;
    cout << " u = " << u << endl;
    cout << "sizeof(u) = " << sizeof(u) << endl;
    // 浮点数转整数小数直接丢掉，不会四舍五入！！！
    u = 1.3;
    cout << "1.3 u = " << u << endl;
    u = 1.9;
    cout << "1.9 u = " << u << endl;
    u = 2 / 3;
    cout << "2/3 u = " << u << endl;

    // 整数相处会损失精度，丢弃小数位
    // 想要保留，要保证其中一个数是浮点数！！！
    int x1{ 1 };
    int x2{ 2 };

    float f2{ 0 };
    f2 = x1 / x2;
	cout << " f2 = " << f2 << endl;
    cout << " 1/2 = " << 1 / 2 << endl;
    cout << " 1/2. = " << 1 / 2. << endl;
    // 保证其中一个数是浮点数
    f2 = x1 / (float)x2;  // 正确除法
    cout << " f2 = " << f2 << endl;
    f2 = (float)(x1 / x2); // 无效
    cout << " f2 = " << f2 << endl;


}