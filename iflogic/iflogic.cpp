// iflogic.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 项目目的：测试if else 和 算术运算 和 逻辑运算


#include <iostream>
#include <bitset> // 引入bitset头文件，可以用来输出二进制

using namespace std;

int main()
{
    // 算术运算符
    // 逐位非 ~
    // 逐位与 &
    // 逐位或 |

    char a = 0b10000001; // 0b 开头表示这是一个二进制显示的数值
    char b = 0b00000001; 

    // 用bitset输出二进制
	// 需要引入#include <bitset>
	// \t 相当于tab键，用于对齐
	cout << "a: \t" << bitset<8>(a) << endl;
    cout << "b: \t" << bitset<8>(b) << endl;

    // 逐位非
	cout << "~a: \t" << bitset<8>(~a) << endl;
	cout << "~b: \t" << bitset<8>(~b) << endl;

    // 逐位与
	cout << "a & b: \t" << bitset<8>(a & b) << endl;

	// 逐位或
	cout << "a | b: \t" << bitset<8>(a | b) << endl;

    // bool类型的运算
    bool f1{ false };
	bool f2{ false };
    bool t1{ true };
	bool t2{ true };
	if (t1) cout << "t1 is true" << endl;
	cout << "f1 = " << f1 << endl;
    cout << "t1 = " << t1 << endl;

    // 算术运算符的 非 ~ 无法用到bool类型的逻辑判断
    // bool类型的false true都是1个字节的
    // true     0000 0001  ~  1111 1110
    // false    0000 0000  ~  1111 1111
    cout << "sizeof(true) =" << sizeof(true)  << "个字节" << endl;
    cout << "sizeof(false) =" << sizeof(false) << "个字节" << endl;

    // 但是算术运算符的 与 & 和 或 | 可以用到bool类型的运算
    if (f1 & t1) cout << "(f1 & t1) true" << endl;
    if (f1 | t1) cout << "(f1 | t1) true" << endl;

    // 逻辑运算符（代用运算符）
    // 逻辑非 ！    not
    // 逻辑与 &&    and
    // 逻辑或 ||    or
    if (f1 && t1)
    {
        cout << "f1 and t1 true" << endl;
    }

    else
    {
        cout << "f1 and t1 false" << endl;
    }

    if (!f1) cout << "!f1为true" << endl;


    // 验证短路求值
    cout << "验证短路求值，区分逻辑运算符||与算术运算符|" << endl;
    int x1{ 0 };
    if ((++x1) || (x1 += 2))
    {
        cout << "使用 || 运算 (++x1) || (x1 += 2)" << endl;
    }
    cout << "x1 = " << x1 << endl;

    x1 = 0;
    if ((++x1) | (x1 += 2))
    {
        cout << "使用 | 运算 (++x1) | (x1 += 2)" << endl;
    }
    cout << "x1 = " << x1 << endl;

    
    cout << "请输入一个整数！！\n";
    // 标准输入 cin 控制台接受的输入内容
    int x{ 0 };
    cin >> x; // 用户输入的值存入了x
    cout << "x= " << x << endl;
    
    // if 条件判断语句有一个满足的话
    // 剩下的永远不会进入
    // 比较表达式 < > == != <= >=
    if (x > 100)
    {
        cout << "x > 100" << endl;
        // if嵌套，代码块如果只有一行，可以省略大括号
        if (x == 101)
            cout << "x==101" << endl;
        if (x != 101) cout << "[!102]"<<endl;
    }
    else if(x>200)
    {
        cout << "x > 200" << endl;
    }
    else if (x < 50)
    {
        cout << "x < 50" << endl;
    }
    else  
    {
        // 前面的条件全部都不满足
        // 直接进入else 代码块 
        cout << "else x =" << x << endl;
    }
}