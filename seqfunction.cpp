//顺序表数据结构的函数实现文件

#include"seq.h"

PSeqList SetNUllList_Seq(int max)			//创建空顺序表，max为顺序表的最大值
{
	PSeqList pSeqList = new(SeqList);		//申请结构体空间
	if (pSeqList != NULL)					//申请结构体成功
	{
		pSeqList->elem = new Student[max];	//申请对象数组空间（顺序表空间）
		if (pSeqList->elem)					//申请顺序表成功
		{
			pSeqList->Max = max;
			pSeqList->n = 0;
			return pSeqList;				//创建顺序表成功则返回此表指针
		}
		else
		{
			delete pSeqList;				//创建失败则删除整个结构体和顺序表体
		}
	}										//结构体申请不成功（pSeqList==NULL）
	cout << "建立顺序表失败！" << endl;
	return NULL;
}
