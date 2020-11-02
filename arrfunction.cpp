#include"student.h"
#include "array.h"

static void enter(Student* fp);//���뵥��ѧ������Ϣ��¼����޸ģ�
static int getGrade();
static int findPlace(Student* p, int size);
void CinClean();

arrayList::arrayList(int size)
{
	fp = new Student[size];
	this->size = size;
}

arrayList::~arrayList()
{
	delete[] fp;
}

void arrayList::arrayGuide(bool* run)//�����������������������ܺ�����
{								//fp��size����ָ�롣ֻ�ı����ݣ�pp��˫��ָ�룬���Ըı�ָ�������
	int income;
	cin >> income;
	switch (income)
	{
	case 1:Input(fp, size);	//Guide�������յ�������ָ�룬��ָ��ȡ���ݾ�Ϊintֵ
		break;
	case 2:OutPut(fp, size);	//��sizeֵ������������ı�ԭֵ
		break;
	case 3:Fix(fp, size);
		break;
	case 4:Delet(fp, &size);		//����ֱ�Ӵ�sizeԭֵ�ĵ�ַ��ȥ
		break;
	case 5:Fprint(fp, size);
		break;
	case 6:Caculat(fp, size);
		break;
	case 7:Insert(&fp, &size);	//����ָ��ĵ�ַ��
		break;
	case 8:*run = 0;
		break;
	default:cout << "����������ݴ������������롣" << endl;
		CinClean();
		break;
	}
}

static int getGrade()
{
	int grade;
	while (1)
	{
		cin >> grade;
		if (cin.fail())
		{
			cout << "�����������ʹ������������룡" << endl;
			CinClean();
		}
		else if (grade >= 0 && grade <= 100)
		{
			return grade;
		}
		else
		{
			cout << "�������ݴ������������룡" << endl;
			CinClean();
		}
	}
}


static void enter(Student* fp)//���뵥��ѧ������Ϣ��¼����޸ģ�
{
	cout << "������ѧ����ѧ�ţ�ID��" << endl;
	unsigned long long int id;
	while (true)
	{
		cin >> id;
		if (id >= (1e12) && id <= (1e13 - 1))
		{
			fp->setId(id);
			break;
		}
		else
		{
			cout << "�������ݲ��Ϸ���������һ��13λ������" << endl;
			CinClean();
		}
	}
	cout << "������ѧ��������" << endl;
	string name;
	//getline(cin, name);**************************************���У�Ϊ�Σ�
	cin >> name;
	fp->setName(name);
	cout << "������ѧ���Ա����������롮1����Ů�������롮0������" << endl;
	int psex;
	while (1)
	{
		cin >> psex;
		if ((psex != 1) && (psex != 0))
		{
			cout << "�Ա�����������������룡" << endl;
			CinClean();
		}
		else
		{
			break;
		}
	}
	bool sex;
	sex = psex;
	fp->setSex(sex);

	int G;
	cout << "������ѧ����Ӣ��ɼ���" << endl;
	G = getGrade();
	fp->setEnGrade(G);
	cout << "������ѧ���ĸ����ɼ���" << endl;
	G = getGrade();
	fp->setHmGrade(G);
	cout << "������ѧ���ļƿƳɼ���" << endl;
	bool judge = 1;//���һ�����룬����飨����Ϊ����ʾ���ɼ�¼��ɹ���˳������ˣ���������ݶ�����������飩
	while (judge == 1)//judge=1����鲻�ɹ�������cin��judge=0:���ɹ�������while��
	{
		cin >> G;
		if ((G >= 0) && (G <= 100))//������һ�γɼ�ֵ
		{
			fp->setCsGrade(G);
			judge = 0;
			cout << "==============�ɼ�¼��ɹ���============" << endl;
		}
		else
		{
			cout << "�ƿƳɼ��������������0-100��ֵ" << endl;
			CinClean();
			G = 0;
			judge = 1;
		}
	}
}

static int findPlace(Student* p, int size)
{
	cout << "������ѧ�Ż������" << endl;
	int place;
	unsigned long long int in;
	while (true)
	{
		cin >> in;
		if (cin.fail())
		{
			cout << "�����������ʹ������������룡" << endl;
			CinClean();
		}
		else if ((in <= size) && (in >= 0))//in==place
		{
			place = (int)in;
			return place;
		}
		else//in==id or not!
		{
			for (int i = 0; i < size; i++)
			{
				if (in != p->getId())
				{
					p++;
				}
				else if (in == p->getId())
				{
					place = i + 1;
					return place;
				}
				if (i == size - 1)
				{
					cout << "δ�ҵ����ݣ����������룡" << endl;
					CinClean();
				}
			}
		}
	}
	return 0;
}

void CinClean()
{
	cin.clear();
	cin.ignore(1024, '\n');
}

void arrayList::Input(Student* fp, int size)		//¼����Ϣ
{
	do
	{
		enter(fp);
		fp++;
		size--;
	} while (size > 0);
}



void arrayList::OutPut(Student* fp, int size)		//��ʾ��Ϣ
{
	if (size == 0)		//��׳�ԣ��������ɾ�꿩��
	{
		cout << "������";
	}
	else
	{
		cout << "    ID    " << "\t" << "����" << "\t" << "�Ա�" << "\t" << "Ӣ��ɼ�" << " \t" << "�����ɼ�" << "\t" << "�ƿƳɼ�" << endl;
		do				//���д��while��size>0����ͷҲ�У���ֱ�Ӹ����û�"û��"���ܱȿտյı����ذ�~
		{
			fp->showAll();
			cout << endl;
			fp++;
			size--;
		} while (size > 0);

	}
}

void arrayList::Fix(Student* fp, int size)					//�޸����ݣ��Һ�������ô�����˻�ע�͸�jir��
{
	/*cout << "��������Ҫ�޸ĵ�ѧ����ѧ�ţ�" << endl;
	unsigned long long int id;	//���������ѧ�ſ�
	cin >> id;
	for (int i = 0; i < size; i++)
	{
		if (id == fp->getId())
		{
			enter(fp);
			break;
		}
		else
		{
			fp++;
			continue;
		}
		cout << "δ�ҵ���Ϣ" << endl;
		break;
	}*/
	int place = findPlace(fp, size);
	/*for (int i = 0; i < place-1; i++)
	{
		fp++;
	}*/
	fp += (place - 1);//��λfp
	enter(fp);
}

void arrayList::Delet(Student* fp, int* size)
{
	int place = findPlace(fp, *size);
	fp += (place - 1);
	for (int j = 0; j < (*size - place); j++)
	{
		Student* rp = fp;
		rp++;									//��֤ÿ�Σ�rpָ��fp����һλ
		*fp = *rp;
		fp++;
	}
	*size -= 1;									//ͨ���ı�ȫ��sizeֵ��ʹ���һ��ֵ���
	cout << "ɾ�����ݳɹ���";
	
	/*int place = findPlace(fp, *size);
	for (int i = 0; i < place; i++)
	{

	}*/
}

void arrayList::Fprint(Student* fp, int size)
{
	ofstream outFile("ѧ���ɼ���.txt", ios::out | ios::binary);
	outFile << "    ID    " << "\t      " << "����" << "\t " << "�Ա�" << "\t      " << "Ӣ��ɼ�" << " \t      " << "�����ɼ�" << "\t      " << "�ƿƳɼ�" << endl;
	do
	{
		outFile << fp->getId() << "\t" << fp->getName() << "\t" << fp->getSex() << "\t" << fp->getEnGrade() << " \t\t" << fp->getHmGrade() << "\t\t" << fp->getCsGrade();
		outFile << endl;
		fp++;
		size--;
	} while (size > 0);
	cout << "=============���Ϊ�ļ��ɹ���============";
}

void arrayList::Caculat(Student* fp, int size)
{
	int sumEn = 0, sumHm = 0, sumCs = 0;
	for (int i = 0; i < size; i++)
	{
		sumEn += fp->getEnGrade();
		sumHm += fp->getHmGrade();
		sumCs += fp->getCsGrade();
		fp++;
	}
	cout << "Ӣ��ɼ���ƽ��ֵΪ��" << (sumEn /= size) << endl;
	cout << "�����ɼ���ƽ��ֵΪ��" << (sumHm /= size) << endl;
	cout << "�ƿƳɼ���ƽ��ֵΪ��" << (sumCs /= size) << endl;
}

void arrayList::Insert(Student** pp, int* size)	//����ָ��ָ���ָ��
{
	cout << "����뵽�ĸ�λ�ã�";
	int place = findPlace(*pp, *size+1);//��βλ��Ҳ�ɲ��룡
	//�½�һ�����飡
	Student* newp = new Student[*size + 1];
	for (int i = 0; i < *size + 1; i++)//ÿһ��ѭ�����Ƕ��µ�����(size+1��ֵ)һ�θ�ֵ
	{
		if (i == place - 1)
		{
			enter(newp);
			newp++;
		}
		else
		{
			*newp = **pp;
			newp++;
			*pp += 1;
		}
	}			//��������
	newp -= *size + 1;
	*pp -= *size;
	//����ָ����˵���ʼλ��
	delete[] * pp;
	*pp = newp;			//���µ����鸳��ԭ����ָ��
	*size += 1;			//�ı�ԭ����sizeֵ��С
}

