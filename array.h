//�����
//�ṩguide�ӿ�

#pragma once
#include"student.h"
void CinClean();

class arrayList
{
public:
	arrayList(int size);
	~arrayList();

	void arrayGuide(bool* run);//�����������������������ܺ�����
	//����������ָ�룬ǰ����Ϊ�����޸����ݣ�������Ϊ�˸�deleat�����ã������ĺ����ò��ϣ�

	void Input(Student* fp, int size);	//һ������������ѧ������
	void OutPut(Student* fp, int size);	//һ������ʾ����ѧ������
	void Fix(Student* fp, int size);	//ͨ��id�޸�ĳһ��ѧ�������ݡ�
	void Delet(Student* fp, int* size);	//ͨ��idɾ��ĳһ��ѧ�������ݡ��е����⣨�ı��������
	void Fprint(Student* fp, int size);	//һ���Դ�ӡ����ѧ�����ݡ�
	void Caculat(Student* fp, int size);//һ���Լ�������ѧ��ÿ�Ƴɼ�ƽ��ֵ
	void Insert(Student** fp, int* size);//����һ������


private:
	Student* fp;
	int size;
};
