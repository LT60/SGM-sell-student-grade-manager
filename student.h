//Ԫ���ݣ�ѧ���ࣩ
//�����������ݽṹ��
#pragma once
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class Student
{
private:
	unsigned long long int Id;	//ѧ��
	string Name;			//����
	bool	Sex;			//�Ա�:��1��Ů0��
	int EnGrade;			//Ӣ��ɼ�
	int HmGrade;			//�����ɼ�
	int CsGrade;			//�ƿƳɼ�

public:
	Student();
	~Student();
public:
	void setId(unsigned long long int id) { Id = id; };//û�뵽Ϊ�˱���private��ÿ�����ݶ�Ҫд����������
	void setName(string name) { Name = name; };
	void setSex(bool sex) { Sex = sex; };
	void setEnGrade(int enGrade) { EnGrade = enGrade; };
	void setHmGrade(int hmGrade) { HmGrade = hmGrade; };
	void setCsGrade(int csGrade) { CsGrade = csGrade; };

	unsigned long long int getId() { return Id; };
	string getName() { return Name; };
	bool getSex() { return Sex; };
	int getEnGrade() { return EnGrade; };
	int getHmGrade() { return HmGrade; };
	int getCsGrade() { return CsGrade; };

public:
	void showAll();
	void showAll(ofstream outfile);

	Student operator =(Student& b);//���ں�����//Ȩ�޹���ע����
};