//数组表
//提供guide接口

#pragma once
#include"student.h"
void CinClean();

class arrayList
{
public:
	arrayList(int size);
	~arrayList();

	void arrayGuide(bool* run);//引导函数（数字引导至功能函数）
	//（接收两个指针，前者是为了能修改数据，后者是为了给deleat那里用，其它的函数用不上）

	void Input(Student* fp, int size);	//一次性输入所有学生数据
	void OutPut(Student* fp, int size);	//一次性显示所有学生数据
	void Fix(Student* fp, int size);	//通过id修改某一个学生的数据。
	void Delet(Student* fp, int* size);	//通过id删除某一个学生的数据。有点特殊（改变了体积）
	void Fprint(Student* fp, int size);	//一次性打印所有学生数据。
	void Caculat(Student* fp, int size);//一次性计算所有学生每科成绩平均值
	void Insert(Student** fp, int* size);//插入一个数据


private:
	Student* fp;
	int size;
};
