// test_for.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

int main(int argc,char *argv[],char *env[])
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

    // 嵌套for，尽量不超过三层
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "(" << i << "," << j << ") ";

        }
        cout << endl;
	}
    cout << endl; // endl是回车的意思

    // 无限循环
    int index{ 0 };
    for (;;)
    {
        if (index > 10)break;
        cout << "index: " << index << endl;
        index++;
    }

    // 打印环境变量
    for (int i = 0; env[i] != nullptr; i++)
    {
        cout << "第" << i << "个环境变量" << endl;
        cout << env[i] << endl;
    }
}
