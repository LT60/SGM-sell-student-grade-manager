#pragma once
#include"student.h"

struct SeqList				//˳���
{
	int Max;				//���Ԫ�ظ���
	int n;					//ʵ��Ԫ�ظ���
	Student* elem;			//�׵�ַ
};
typedef struct SeqList* PSeqList;

PSeqList SetNUllList_Seq(int max);	//����max��С�Ŀ�˳���