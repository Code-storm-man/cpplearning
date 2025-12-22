// test_switch.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

enum class STATUS
{
    PLAY,
    STOP,
    PAUSE
};

int main()
{
    std::cout << "Hello World!\n";

    int x{ 2 };
    cin >> x;

    // switch用于整型
    switch (x) // 判断x值满足哪个条件case, 直接跳转到相应地条件代码
               // 运行到switch结束或者break
    {
    case 0:
        cout << "case 0\n"; 
        break;
    case 1:
    {
		int y{ 1 };  // 如果需要在case中定义变量, 必须加大括号
        cout << "begin 1" << endl;
        cout << "case 1\n"; 
        break;
    }
    case 2:
        cout << "case 2\n"; 
        break;
    default:
        cout << "default\n"; 
        break;
    }

    // switch用于枚举类型
    STATUS status{ STATUS::PLAY};
    switch (status)
    {
        case STATUS::PLAY:
            cout << "status: PLAY\n";
		    break;
        case STATUS::STOP:
			cout << "status: STOP\n";
            break;
		case STATUS::PAUSE:
			cout << "status: PAUSE\n";
            break;
    }

}
