#pragma once
#include"student.h"

struct SeqList				//顺序表
{
	int Max;				//最大元素个数
	int n;					//实际元素个数
	Student* elem;			//首地址
};
typedef struct SeqList* PSeqList;

PSeqList SetNUllList_Seq(int max);	//申请max大小的空顺序表