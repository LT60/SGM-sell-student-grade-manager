//元数据（学生类）
//用在所有数据结构中
#pragma once
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class Student
{
private:
	unsigned long long int Id;	//学号
	string Name;			//姓名
	bool	Sex;			//性别:男1，女0；
	int EnGrade;			//英语成绩
	int HmGrade;			//高数成绩
	int CsGrade;			//计科成绩

public:
	Student();
	~Student();
public:
	void setId(unsigned long long int id) { Id = id; };//没想到为了保护private，每个数据都要写两个函数？
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

	Student operator =(Student& b);//等于号重载//权限过大，注意检查
};