#include"student.h"

Student::Student()
{
	Id = 3120190971000;
	Name = "Null";
	Sex = 1;
	EnGrade = 0;
	HmGrade = 0;
	CsGrade = 0;
}

Student::~Student()
{

}

void Student::showAll()//显示在黑框框上的输出函数
{
	cout << Id << "\t" << Name << "\t";
	if (Sex)
	{
		cout << "男";
	}
	else
	{
		cout << "女";
	}
	cout << "\t" << EnGrade << " \t\t" << HmGrade << "\t\t" << CsGrade;
}

void Student::showAll(ofstream outfile)//写入到文件里的输出函数
{
	outfile << Id << "\t" << Name << "\t";
	if (Sex)
	{
		outfile << "男";
	}
	else
	{
		outfile << "女";
	}
	outfile << "\t" << EnGrade << " \t\t" << HmGrade << "\t\t" << CsGrade;
}
;

Student Student::operator=(Student& b)//学生类的重载 = 函数
{
	this->Id = b.Id;
	this->Name = b.Name;
	this->Sex = b.Sex;
	this->EnGrade = b.EnGrade;
	this->CsGrade = b.CsGrade;
	this->HmGrade = b.HmGrade;

	return Student();
}
