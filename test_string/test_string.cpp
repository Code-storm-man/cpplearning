// test_string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 学习使用string的语法

#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::string str1{ "test string 1" };
	//   这块在栈空间    这块在堆空间
	// 赋初始化值 从堆空间复制一份到这个栈区对应变量的位置

	cout << "str1: " << str1 << endl;

	str1 = "test string 1-2";

	string str2{ str1 };
	cout << "str2: " << str2 << endl;

	string str3; // 默认空串
	str3 = str2;
	cout << "str3: " << str3 << endl;

	// 字符串长度与空间
	string str4{"123456789"};
	cout << "str4: " << str4 << endl;
	cout << "字符串长度 size str4 :" << str4.size() << endl;
	cout << "字符串分配的空间大小 str4 capacity :" << str4.capacity() << endl;

	// 截断字符串
	// substr(pos, len) 第一个是起始位置 第二个是长度
	cout << str4.substr(0, 2) << endl; // 截取前两个字符
	cout << str4.substr(1, 3) << endl; // 从第二个字符开始 截取三个字符

	string strif;
	// 空串判断
	if (strif.empty()) // 常用
	{
		cout << "strif empty" << endl;
	}
	if (strif.size() == 0)
	{
		cout << "strif empty" << endl;
	}
	if (strif == "")
	{
		cout << "strif empty" << endl;
	}

	strif = "test";
	if (strif == "test")
	{
		cout << "strif == test" << endl;
	}
	if (strif != "test1")
	{
		cout << "strif != test1" << endl;
	}

	// 5、字符串和数字的转换
	// stoX
	// 字符串转换为数字，出错抛出异常
	auto i1 = stoi("1234");
	i1++;
	cout << "i1 = " << i1 << endl;
	string sd1 = "123.5";
	auto d2 = stod(sd1);
	cout << d2 << endl;
	auto f1 = stof("33.1f");
	cout << "f1 = " << f1 << endl;
	auto f2 = stof("33.2f");
	cout << "f2 = " << f2 << endl;
	cout << stoll("123123123123") << endl;

	// 数字转换为字符串
	// to_string
	auto pistr = to_string(3.1415926);
	cout << "pistr" << pistr << endl;  // 这里double转string的时候会损失精度
	cout << to_string(-1998) << endl;

	// 6、字符串的拼接
	string log;
	string txt = "login success!";
	string user = "zx";
	auto thread_id = 20251213;
	
	log = user + ":" + txt + ":" + to_string(thread_id);
	cout << log << endl;

	log = "[debug]" + log;
	log += ";";
	cout << log << endl;

	// 7、字符串的查找与替换
	string strfind = "test for find [user] test";
	string suser = "zx";
	// 尝试查找不在这个string里面的字符串
	auto pos = strfind.find("[test]");
	if (pos == string::npos) // string里面没有查找到的返回值
	{
		cout << "[test] not find" << endl;
	}
	string key = "[user]";
	pos = strfind.find(key); // find返回的是需要查找字符串的对应首位置
	if (pos != string::npos)
	{
		cout << strfind.substr(pos) << endl; // 从[user]开始截断出后面的
		auto backup = strfind;
		auto re = strfind.replace(pos, key.size(), suser); // 被替换的首位置，长度，内容
		cout << backup << endl;
		cout << "替换结果" << endl;
		cout << re << endl;
	}
}
