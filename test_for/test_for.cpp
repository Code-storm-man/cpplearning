// test_for.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; /* 初始化 */i < 10/* 条件 */; i++ /* 迭代 */)
    {
        // cout << "Hello, World! " << i << endl;
        // true代码块
		cout <<"i = "<< i << endl;
    }

    // contitue的使用
    // “循环不退出，下面代码此次不执行，循环进入下一轮”
    // break
    // 跳出当前所在层的循环
    for (int i = 0; i < 100; i++)
    {
        if (i % 2 == 0)
            continue;
		cout << i << " ";
        if (i > 50)
            break;
    }
    cout << endl;
}
