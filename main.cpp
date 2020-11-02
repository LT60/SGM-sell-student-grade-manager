#include<string>
#include<iostream>
#include<fstream>

#include"array.h"

using namespace std;

int GetSize();//获取人数，决定内存大小
void ShowMenu();//显示菜单

int main()
{
	cout << "===============学生成绩管理系统===============";
	int size = GetSize();
	if (size <= 0)
	{
		return 0;
	}
	arrayList Management(size);
	bool run = 1;//控制while循环
	while (run)
	{
		ShowMenu();
		Management.arrayGuide(&run);
	}
	return 0;
}

int GetSize()
{
	int size;
	while (1)
	{
		cout << endl << "|-----------------请输入人数：---------------|" << endl;
		cout << "                     ";
		cin >> size;
		if (size > 0 && size < 40)//合法
		{
			return size;
		}
		else if (size >= 40)
		{
			cout << "!!!!!你确定要操作如此多的人数吗？\n【友情提示：还未开发批量录入功能，您的录入操作只能一个一个录入！】\n(如果你确定，请输入1；若想重新输入，请输入0。)" << endl;
			CinClean();
			bool isContinue;
			cin >> isContinue;
			if (cin.fail())
			{
				cout << "注意数据类型输入错误！请重新输入！" << endl;
				CinClean();
			}
			else if (isContinue)
			{
				return size;
			}
			else if(!isContinue)
			{
				continue;
			}
			
		}
		else
		{
			if (cin.fail())
			{
				cout << "数据类型输入错误！请重新输入！" << endl;
				CinClean();
			}
			else
			{
				cout << "输入数值有问题，请重新输入！" << endl;
				CinClean();
			}
		}
	}
}

void ShowMenu()//显示菜单
{
	cout << endl;
	cout << "/-----------------请选择功能：---------------\\" << endl;
	cout << "|1：录入学生信息            2：读出学生信息  |" << endl;
	cout << "|3：修改学生信息            4：删除学生数据  |" << endl;
	cout << "|5：文件形式输出            6：计算成绩均值  |" << endl;
	cout << "|7：插入学生信息            8：退出管理程序  |" << endl;
	cout << "\\--------------------------------------------/" << endl;
}

