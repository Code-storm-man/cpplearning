// test_vector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// vector的基础使用
	// vector后面接的<>表示容器
	// vector在定义的时候没有空间大小，只有用的时候有空间
	/* 下面三种是不同的类型 */
	/* 即vi、vs、vf是三种不同类型的变量 */
	vector<int>		vi;
	vector<string>	vs;
	vector<float>	vf;

	vector<int> vd(10); // 设置数组大小

	// 初始化
	vector<int> vd2{ 1,2,3,4,5 };
	vector<string> vs1{ "ss1","ss2","ss3" };

	// vector的增（结尾）
	{
		std::vector<int>datas;
		datas.push_back(10); // 结尾处插入内容
		datas.push_back(20);
		datas.push_back(30);

		// 三种遍历方法
		// 1、传统遍历方法
		cout << "传统遍历方法: " << endl;
		for(int i= 0; i < datas.size(); i++)
		{
			cout << datas[i]<< " ";
		}
		cout <<"\n"<< endl;
		
		// 2、迭代器遍历
		vector<int>::iterator it = datas.begin();
		cout << "迭代器遍历: " << endl;
		// datas.begin() 返回第一个元素的地址, datas.end()返回最后一个元素的下一个地址
		cout << "vector容器datas的第一个元素地址:\t" << (long long)&(*datas.begin()) << endl;
		cout << "vector容器datas的最后一个元素地址:\t" << (long long)&(*(datas.end()-1)) << endl;
		cout << "vector容器datas的大小: " << datas.size() << endl;

		for(auto itr=datas.begin(); itr != datas.end();itr++)
			cout << *itr << ",";
		cout <<"\n"<< endl;

		// 3、c++11的方法
		// 类似于迭代器的方法
		cout << "c++11的方法: " << endl;
		for (auto& d : datas)
		{
			cout << d << "|";
		}
		cout <<"\n"<< endl;
	}

	// vector的搜索 删除 插入 排序
	{
		cout << "原vector数组中的数据: " << endl;
		std::vector<int>datas{ 0,1,2,3,4,5,6,7,8,9,10,5,12,331,334,134,11};
		for (auto& d : datas)
		{
			cout << d << " ";
		}
		cout <<"\n"<< endl;

		// auto f = find(datas.begin(), datas.end(), 99); // 查找99是否存在
		auto f = find(datas.begin(), datas.end(), 5);	// 查找5是否存在
		if (f != datas.end())
		{
			cout << "find: " << *f << " in " << f-datas.begin() << endl;
		}

		// 查找vector中的fdata元素，找到并输出其位置
		int fdata = 5;
		vector<int> datapos;
		cout << "查找元素 " << fdata << " 在vector中的位置: ";
		for (int i = 0; i< datas.size(); i++)
		{
			if(datas[i]==fdata)
			{
				datapos.push_back(i);
			}
		}
		for(auto p : datapos)  
		{
			// 打印元素的位置
cout << p << " ";
		}
		cout << "\n" << endl;

		// 删除元素
		auto del = find(datas.begin(), datas.end(), 7);	// 查找7是否存在并删除
		if (del != datas.end())
		{
			cout << "find: " << *del << " in " << del - datas.begin() << endl;
			datas.erase(del); // 删除元素
		}
		cout << "删除元素7之后，vector数组中的数据: " << endl;
		for (auto& d : datas)
		{
			cout << d << " ";
		}
		cout << "\n" << endl;

		// 一次性删除多个重复元素
		// 注意：删除重复元素时会导致数组内部元素索引变化
		// 解决方法：从后往前删除
		int deldata = 5;
		cout << "从后往查找元素 " << deldata << " 在vector中的位置: ";
		vector<int> datapos2;
		// 修改查找元素的方法，先从后往前找到对应需要删除的元素位置
		for (int i = datas.size() - 1; i >= 0; i--)
		{
			if (datas[i] == deldata)
			{
				datapos2.push_back(i);
			}
		}
		for (auto p : datapos2)
		{
			// 打印元素的位置
			cout << p << " ";
		}
		cout << endl;
		cout << "删除元素 " << deldata << " 之后，vector数组中的数据: " << endl;
		for (auto p : datapos2)
		{
			datas.erase(datas.begin() + p);
		}
		for (auto& d : datas)
		{
			cout << d << " ";
		}
		cout << "\n" << endl;


		// 插入元素
		cout << "插入元素5" << endl;
		datas.insert(datas.begin() + 5, 5);
		for (auto& d : datas)
		{
			cout << d << " ";
		}
		cout << "\n" << endl;
		cout << "需要在331后面插入多个元素" << endl;
		f = find(datas.begin(), datas.end(), 331);

		if (f != datas.end())
		{
			cout << "find " << *f << " in " << f - datas.begin() << endl;
		}

		// datas.insert(f+1,332);
		// 注意：当你执行第一句 datas.insert(f+1, 332); 时，vector 的内部结构发生了变化，导致旧的迭代器 f 变成了“野指针”
		// datas.insert(f + 2,333);
		// 正确做法
		f = datas.insert(f + 1, 332); // 插在331后面
		f = datas.insert(f + 1, 333); // 此时f是332的地址

		for (auto& d : datas)
		{
			cout << d << " ";
		}
		cout << "\n" << endl;

		// vector的排序
		cout << "正序排序" << endl;
		sort(datas.begin(), datas.end());
		for (auto& d : datas)
		{
			cout << d << " ";
		}
		cout << "\n" << endl;

		cout << "倒序排序" << endl;
		sort(datas.begin(), datas.end(), greater<int>());
		for (auto& d : datas)
		{
			cout << d << " ";
		}
		cout << "\n" << endl;

	}

	// vector的使用效率 / 空间的优化
	{
		vector<int> v1;
		vector<int> vdata(10); // 创建了10个对象

		// size()存储的是元素的个数
		cout << "v1.size() =     \t" << v1.size() << endl;
		cout << "vdata.size() =   \t" << vdata.size() << endl;

		// capacity()存储的是分配的内存空间
		cout << "v1.capacity() = \t" << v1.capacity() << endl;
		cout << "vdata.capacity() = \t" << vdata.capacity() << endl;

		// 对v1进行扩容
		// resize  扩充元素个数时会初始化一个对象
		// reserve 扩充了一块内存在那里，不会初始化一个对象
		v1.resize(8);	// 扩充元素数量 初始化对象	！！！
		v1.reserve(16);	// 扩充内存数量 只扩充内存 不初始化对象 ！！！
		cout << "v1扩容后: " << endl;
		cout << "v1.size() =     \t" << v1.size() << endl;
		cout << "v1.capacity() = \t" << v1.capacity() << endl;
		v1.push_back(99);
		for (auto v : v1)
			cout << v << " ";
		cout << "\n" << endl;

		v1.clear(); // 清空元素，但不释放内存
		cout << "v1.clear()后: " << endl;
		v1.shrink_to_fit(); // 内存适应元素，释放多余内存
		cout << "v1.shrink_to_fit()后: " << endl;
		cout << "v1.size() =     \t" << v1.size() << endl;
		cout << "v1.capacity() = \t" << v1.capacity() << endl;
		int c{ 0 };
		// 元素空间动态变化
		for (int i = 0; i < 200; i++)
		{
			v1.push_back(i);
			if (c != v1.capacity())
			{
				cout << "v1.capacity() = \t" << v1.capacity() << endl;
			}
			c = v1.capacity();
		}
	}

	// vector插入元素的效率
	{
		vector<string> vs;
		// 结尾出插入元素
		// push_back
		// 1 "test"转为string对象
		// 2 vs内部分配string对象空间
		// 3 复制一份string存入vs ?? 
		// 3 现代版本移动一份string存入vs
		vs.push_back("test");

		// emplace_back
		// 1 vs内部分配string对象空间
		// 2 直接将string对象创建在分配的空间中
		vs.emplace_back("test");
		
		// 可以在这里打个断点，运行到这里的时候右键 “反汇编”
		cout << "vector插入元素的效率测试断点" << endl;

	}
}