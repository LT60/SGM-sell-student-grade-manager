//˳������ݽṹ�ĺ���ʵ���ļ�

#include"seq.h"

PSeqList SetNUllList_Seq(int max)			//������˳���maxΪ˳�������ֵ
{
	PSeqList pSeqList = new(SeqList);		//����ṹ��ռ�
	if (pSeqList != NULL)					//����ṹ��ɹ�
	{
		pSeqList->elem = new Student[max];	//�����������ռ䣨˳���ռ䣩
		if (pSeqList->elem)					//����˳���ɹ�
		{
			pSeqList->Max = max;
			pSeqList->n = 0;
			return pSeqList;				//����˳���ɹ��򷵻ش˱�ָ��
		}
		else
		{
			delete pSeqList;				//����ʧ����ɾ�������ṹ���˳�����
		}
	}										//�ṹ�����벻�ɹ���pSeqList==NULL��
	cout << "����˳���ʧ�ܣ�" << endl;
	return NULL;
}
