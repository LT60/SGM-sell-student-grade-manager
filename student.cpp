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

void Student::showAll()//��ʾ�ںڿ���ϵ��������
{
	cout << Id << "\t" << Name << "\t";
	if (Sex)
	{
		cout << "��";
	}
	else
	{
		cout << "Ů";
	}
	cout << "\t" << EnGrade << " \t\t" << HmGrade << "\t\t" << CsGrade;
}

void Student::showAll(ofstream outfile)//д�뵽�ļ�����������
{
	outfile << Id << "\t" << Name << "\t";
	if (Sex)
	{
		outfile << "��";
	}
	else
	{
		outfile << "Ů";
	}
	outfile << "\t" << EnGrade << " \t\t" << HmGrade << "\t\t" << CsGrade;
}
;

Student Student::operator=(Student& b)//ѧ��������� = ����
{
	this->Id = b.Id;
	this->Name = b.Name;
	this->Sex = b.Sex;
	this->EnGrade = b.EnGrade;
	this->CsGrade = b.CsGrade;
	this->HmGrade = b.HmGrade;

	return Student();
}
