// test_array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

#include <iostream>
#include <iomanip> // 调用 setw 需要包含的头文件

using namespace std;

int main()
{
    // 栈区数组的申请
	// 栈区数组的生命周期是在一个大括号里面，出了大括号就释放掉了
    {
        // 类型 变量名[数组数量]
        int arr1[4]{ 0 };

		// 传统for循环遍历方法
		for (int i = 0; i < 4; i++)
			cout << arr1[i] << " ";
		cout << endl;
        // c++11 for循环遍历方法
        for(int a : arr1)
			cout << a << " ";
		cout << endl;

		int arr2[4]; // ！！！未初始化，里面是随机值
        // c++11 for循环遍历
        for (int a : arr2)
            cout << a << " ";
        cout << endl;

        arr1[0] = 99; // 下标从0开始
        arr1[2] = 88;
		for (int a : arr1)
            cout << a << " ";
        cout << endl;

        // 第一个sizeof返回的是arr1的字节大小
        for (int i = 0; i < sizeof(arr1) / sizeof(int); i++) 
        {
            cout << arr1[i] << " ";
        }
        cout << endl;

        // 栈区数组空间只能用编译时常量
        int size = 5;
		const int csize = 5;    // 如果初始值是常量，则提升为编译时常量; 如果初始值是浮点数，则是运行时常量
        const int csize2 = size;
        // 编译器：OK，我不报错。但我把 csize2 当作一个“运行时只读变量”。
        // 隐患：如果你后面写 int arr[csize2]，编译器就会报错说 csize2 不是常量表达式。你会在错误的地方得到报错。
        constexpr int cesize = 5;
        int arr3[csize];
        int arr4[cesize];

        // 数组的初始化
        int arr5[10] = { 1,2,3,4,5 };
        int arr6[] = { 3,4,5,6,7,8 };
        char arr7[] = "";
        char arr8[] = "test string on array"; 
		cout << "size of arr6 = " << sizeof(arr6) / sizeof(int) << endl;
        cout << "size of arr7 = " << sizeof(arr7) << endl; // 空字符串有一个\0
		cout << "size of arr8 = " << sizeof(arr8) << endl; // 字符串结尾有一个\0, 20个字符 + 1个结束符

        // 数组是地址连续的空间
        cout << left << setw(12) << "arr1 =" << (long long)arr1 << endl;
        cout << left << setw(12) << "&arr1[0] =" << (long long)&arr1[0] << endl;
        cout << left << setw(12) << "&arr1[1] =" << (long long)&arr1[1] << endl;
        cout << left << setw(12) << "&arr1[2] =" << (long long)&arr1[2] << endl;
        cout << left << setw(12) << "&arr1[3] =" << (long long)&arr1[3] << endl;

		// 地址偏移 地址的指针运算 
		cout << left << setw(12) << "arr1+2 =" << (long long)(arr1 + 2) << endl; // 加的是元素个数，不是字节数
        // 取值
        cout << left << setw(12) << "*(arr1+2) =" << *(arr1 + 2) << endl;
    }

    
    // 堆区数组
    {
        int* arr1 = new int[4] {0};
        auto arr2 = new int[4] {1, 2, 3, 4};
		cout << "sizeof arr1 = " << sizeof(arr1) << endl; // sizeof拿不到堆区数组的大小，只能拿到指针大小
        
        int size = 10;
        auto arr3 = new int[size] {0};
		for (int i = 0; i < size; i++)
            cout << arr3[i] << " ";
		cout << endl;

        // 使用完堆区数组要释放掉 并赋为空指针
		delete[] arr1; arr1 = nullptr;
		delete[] arr2; arr2 = nullptr;
		delete[] arr3; arr3 = nullptr;

        // 内存复制
        int arr5[5] = { 1,2,3,4,5 };
        int csize = 5;
		auto* arr6 = new int[csize];
		memcpy(arr6, arr5, sizeof(arr5)); // 把栈区数组arr5的数据拷贝到堆区数组arr6
        for (int i = 0; i < csize; i++)
            cout << arr5[i] << " ";
        cout << endl;

        // 使用完堆区数组要释放掉 并赋为空指针
        delete[] arr6; arr6 = nullptr;

    }
}