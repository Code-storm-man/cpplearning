// test_while.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 测试内容：
// 实现一个在windows上支持ls命令的shell
// 使用cin接受用户输入的命令
// 使用system函数调用dir命令模拟ls命令
// 支持ls不传参数和传递参数
// 用户输入exit和quit退出shell


#include <iostream>
#include <string>  // string 类的头文件
using namespace std;

// 测试步骤，首先简单测试system函数中的命令，然后实现简单命令的模拟
// 完成其他命令的模拟

int main()
{
	// ============= 这里相当于创建另一个线程，实现一个ls简单的shell ==============
	{
		bool is_exit{ false };
		while (!is_exit)
		{
			string cmd;		// 用户输入的命令分类
			string execmd;	// 执行的命令
			cout << "xshell>>";
			cin >> cmd;
			if (cmd == "ls")
			{
				execmd = "dir";
				string arg;
				// 取出输入的盘符或者路径参数
				if (cin.rdbuf()->in_avail() > 1)
				{
					cin >> arg;
					execmd += " " + arg;
				}
				// system执行对应命令
				system(execmd.c_str());
			}
			else if (cmd == "exit" || cmd == "quit")
			{
				is_exit = "true";
				continue;
			}
			else
			{
				cerr << "命令: " << cmd  << "不支持！" << endl;
			}
		}
	}

	return 0;

	// ============= ⬆️ 测试system函数 ==============

	// 刚开始单独测试系统命令
	// system 执行系统命令
	//system("cd");

	string cmd = "dir";
	//system(cmd.c_str());

	// 接受用户输入的命令，再用system执行
	cout << ">>";
	
	cin >> cmd;

	cout << "cmd: " << cmd << endl;
	// 打印缓冲区可用的内容
	// 至少有一个换行符\n
	// 如果是ls c: 则有4个字符，分别是 c : \n \0
	cout << "in_avail= " << cin.rdbuf()->in_avail() << endl;

	// in_avil输出为1 表示输入ls后，后面的字符只有一个换行符\n
	// 如果输入ls c:则表示c:是两个字符，而字符串每次结尾都是带有\0，再加上一个换行符\n，就是4个

	// 缓冲区有内容，不止有\n
	// 如果ls后面有内容（就不会是一个字符\\n了）
	if (cin.rdbuf()->in_avail() > 1)
	{
		string tmp;
		cin >> tmp;
		cmd += " " + tmp;
	}

	cout << "cmd: " << cmd << endl;

	// 终端暂停，等待用户按任意键继续
	system("pause");

	return 0;

	int index{ 0 };

	// 无限循环
	// 无限循环会把一个核心CPU占掉
	while (1)
	{
		index++;
		if (index % 2 == 0)
			continue;
		if (index > 10)
			break;
		cout << index << " ";
	};
	cout << endl;

	bool is_exit{ false };
	while (!is_exit)
	{
		index++;
		if(index>10)
			is_exit = true;
			cout << index << " ";
	}
	cout << endl;

	// while里面的条件可以是任何表达式
	index = 0;
	while (index++ < 10)
		cout << index << " ";
	cout << endl;

	index = 0;
	while(++index<10)
		cout << index << " ";
	cout << endl;

	index = 0;
	while (int i = ++index)
	{
		cout << index << " ";
		if (i > 10)break;
	}
	cout << endl;
}