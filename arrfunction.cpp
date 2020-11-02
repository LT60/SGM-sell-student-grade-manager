#include"student.h"
#include "array.h"

static void enter(Student* fp);//键入单条学生的信息（录入或修改）
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

void arrayList::arrayGuide(bool* run)//引导函数（数字引导至功能函数）
{								//fp和size都是指针。只改变内容，pp是双重指针，可以改变指针和内容
	int income;
	cin >> income;
	switch (income)
	{
	case 1:Input(fp, size);	//Guide函数接收的是两个指针，对指针取内容就为int值
		break;
	case 2:OutPut(fp, size);	//传size值进函数，不会改变原值
		break;
	case 3:Fix(fp, size);
		break;
	case 4:Delet(fp, &size);		//这是直接传size原值的地址进去
		break;
	case 5:Fprint(fp, size);
		break;
	case 6:Caculat(fp, size);
		break;
	case 7:Insert(&fp, &size);	//传递指针的地址！
		break;
	case 8:*run = 0;
		break;
	default:cout << "您输入的内容错误，请重新输入。" << endl;
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
			cout << "输入数据类型错误，请重新输入！" << endl;
			CinClean();
		}
		else if (grade >= 0 && grade <= 100)
		{
			return grade;
		}
		else
		{
			cout << "输入数据错误，请重新输入！" << endl;
			CinClean();
		}
	}
}


static void enter(Student* fp)//键入单条学生的信息（录入或修改）
{
	cout << "请输入学生的学号（ID）" << endl;
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
			cout << "输入数据不合法，请输入一个13位的数！" << endl;
			CinClean();
		}
	}
	cout << "请输入学生姓名：" << endl;
	string name;
	//getline(cin, name);**************************************不行，为何？
	cin >> name;
	fp->setName(name);
	cout << "请输入学生性别（男生请输入‘1’，女生请输入‘0’）：" << endl;
	int psex;
	while (1)
	{
		cin >> psex;
		if ((psex != 1) && (psex != 0))
		{
			cout << "性别输入错误！请重新输入！" << endl;
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
	cout << "请输入学生的英语成绩：" << endl;
	G = getGrade();
	fp->setEnGrade(G);
	cout << "请输入学生的高数成绩：" << endl;
	G = getGrade();
	fp->setHmGrade(G);
	cout << "请输入学生的计科成绩：" << endl;
	bool judge = 1;//最后一次输入，做检查（就是为了显示“成绩录入成功”顺带检查了，上面的数据都可以这样检查）
	while (judge == 1)//judge=1：检查不成功，继续cin；judge=0:检查成功，跳出while。
	{
		cin >> G;
		if ((G >= 0) && (G <= 100))//检查最后一次成绩值
		{
			fp->setCsGrade(G);
			judge = 0;
			cout << "==============成绩录入成功！============" << endl;
		}
		else
		{
			cout << "计科成绩输入出错：请输入0-100的值" << endl;
			CinClean();
			G = 0;
			judge = 1;
		}
	}
}

static int findPlace(Student* p, int size)
{
	cout << "请输入学号或者序号" << endl;
	int place;
	unsigned long long int in;
	while (true)
	{
		cin >> in;
		if (cin.fail())
		{
			cout << "输入数据类型错误，请重新输入！" << endl;
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
					cout << "未找到数据，请重新输入！" << endl;
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

void arrayList::Input(Student* fp, int size)		//录入信息
{
	do
	{
		enter(fp);
		fp++;
		size--;
	} while (size > 0);
}



void arrayList::OutPut(Student* fp, int size)		//显示信息
{
	if (size == 0)		//健壮性：怕你给我删完咯！
	{
		cout << "无数据";
	}
	else
	{
		cout << "    ID    " << "\t" << "姓名" << "\t" << "性别" << "\t" << "英语成绩" << " \t" << "高数成绩" << "\t" << "计科成绩" << endl;
		do				//如果写成while（size>0）开头也行，但直接告诉用户"没有"，总比空空的表格低熵吧~
		{
			fp->showAll();
			cout << endl;
			fp++;
			size--;
		} while (size > 0);

	}
}

void arrayList::Fix(Student* fp, int size)					//修改数据（我函数名这么明显了还注释个jir）
{
	/*cout << "请输入需要修改的学生的学号：" << endl;
	unsigned long long int id;	//保存输入的学号咯
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
		cout << "未找到信息" << endl;
		break;
	}*/
	int place = findPlace(fp, size);
	/*for (int i = 0; i < place-1; i++)
	{
		fp++;
	}*/
	fp += (place - 1);//定位fp
	enter(fp);
}

void arrayList::Delet(Student* fp, int* size)
{
	int place = findPlace(fp, *size);
	fp += (place - 1);
	for (int j = 0; j < (*size - place); j++)
	{
		Student* rp = fp;
		rp++;									//保证每次：rp指向fp的下一位
		*fp = *rp;
		fp++;
	}
	*size -= 1;									//通过改变全局size值来使最后一个值溢出
	cout << "删除数据成功！";
	
	/*int place = findPlace(fp, *size);
	for (int i = 0; i < place; i++)
	{

	}*/
}

void arrayList::Fprint(Student* fp, int size)
{
	ofstream outFile("学生成绩本.txt", ios::out | ios::binary);
	outFile << "    ID    " << "\t      " << "姓名" << "\t " << "性别" << "\t      " << "英语成绩" << " \t      " << "高数成绩" << "\t      " << "计科成绩" << endl;
	do
	{
		outFile << fp->getId() << "\t" << fp->getName() << "\t" << fp->getSex() << "\t" << fp->getEnGrade() << " \t\t" << fp->getHmGrade() << "\t\t" << fp->getCsGrade();
		outFile << endl;
		fp++;
		size--;
	} while (size > 0);
	cout << "=============输出为文件成功！============";
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
	cout << "英语成绩的平均值为：" << (sumEn /= size) << endl;
	cout << "高数成绩的平均值为：" << (sumHm /= size) << endl;
	cout << "计科成绩的平均值为：" << (sumCs /= size) << endl;
}

void arrayList::Insert(Student** pp, int* size)	//接收指向指针的指针
{
	cout << "想插入到哪个位置？";
	int place = findPlace(*pp, *size+1);//结尾位置也可插入！
	//新建一个数组！
	Student* newp = new Student[*size + 1];
	for (int i = 0; i < *size + 1; i++)//每一次循环就是对新的数组(size+1个值)一次赋值
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
	}			//插入语句块
	newp -= *size + 1;
	*pp -= *size;
	//两个指针回退到初始位置
	delete[] * pp;
	*pp = newp;			//将新的数组赋给原来的指针
	*size += 1;			//改变原来的size值大小
}

