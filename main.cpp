#include<string>
#include<iostream>
#include<fstream>

#include"array.h"

using namespace std;

int GetSize();//��ȡ�����������ڴ��С
void ShowMenu();//��ʾ�˵�

int main()
{
	cout << "===============ѧ���ɼ�����ϵͳ===============";
	int size = GetSize();
	if (size <= 0)
	{
		return 0;
	}
	arrayList Management(size);
	bool run = 1;//����whileѭ��
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
		cout << endl << "|-----------------������������---------------|" << endl;
		cout << "                     ";
		cin >> size;
		if (size > 0 && size < 40)//�Ϸ�
		{
			return size;
		}
		else if (size >= 40)
		{
			cout << "!!!!!��ȷ��Ҫ������˶��������\n��������ʾ����δ��������¼�빦�ܣ�����¼�����ֻ��һ��һ��¼�룡��\n(�����ȷ����������1�������������룬������0��)" << endl;
			CinClean();
			bool isContinue;
			cin >> isContinue;
			if (cin.fail())
			{
				cout << "ע��������������������������룡" << endl;
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
				cout << "������������������������룡" << endl;
				CinClean();
			}
			else
			{
				cout << "������ֵ�����⣬���������룡" << endl;
				CinClean();
			}
		}
	}
}

void ShowMenu()//��ʾ�˵�
{
	cout << endl;
	cout << "/-----------------��ѡ���ܣ�---------------\\" << endl;
	cout << "|1��¼��ѧ����Ϣ            2������ѧ����Ϣ  |" << endl;
	cout << "|3���޸�ѧ����Ϣ            4��ɾ��ѧ������  |" << endl;
	cout << "|5���ļ���ʽ���            6������ɼ���ֵ  |" << endl;
	cout << "|7������ѧ����Ϣ            8���˳��������  |" << endl;
	cout << "\\--------------------------------------------/" << endl;
}

