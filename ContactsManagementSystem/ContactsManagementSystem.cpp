#include <iostream>
#include <cstring>

#define MAX 1000

using namespace std;

// 联系人结构体
struct Person
{
	string personName; // 姓名
	int personSex = 0; // 性别 1男 2女
	int personAge = 0; // 年龄
	int personPhone = 0; // 电话
	string personAddress; // 住址
};

// 通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX]; // 通讯录中保存的联系人数组
	int size = 0; // 当前通讯录联系人个数
};

// 显示菜单函数
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

// 检查联系人是否存在，存在则返回联系人在数组中的具体位置，不存在返回-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArray[i].personName == name)
			return i;
	}
	return -1;
}

// 1、添加联系人
void addPerson(Addressbooks* abs)
{
	if (abs->size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	// 添加具体联系人
	
	// 姓名
	string name;
	cout << "请输入姓名： " << endl;
	cin >> name;
	abs->personArray[abs->size].personName = name;

	// 性别
	int sex = 0;
	cout << "请输入性别： " << endl;
	cout << "1 --- 男" << endl;
	cout << "2 --- 女" << endl;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[abs->size].personSex = sex;
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	// 年龄
	int age = 0;
	cout << "请输入年龄： " << endl;
	while (true)
	{
		cin >> age;
		if (age > 0)
		{
			abs->personArray[abs->size].personAge = age;
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	// 电话
	int phone;
	cout << "请输入联系电话： " << endl;
	cin >> phone;
	abs->personArray[abs->size].personPhone = phone;

	// 住址
	string address;
	cout << "请输入家庭住址： " << endl;
	cin >> address;
	abs->personArray[abs->size].personAddress = address;

	// 更新通讯录人数
	abs->size++;

	cout << "添加成功" << endl;
	system("pause"); // 请按任意键继续
	system("cls"); // 清屏操作
}

// 2、显示联系人
void showPerson(Addressbooks* abs)
{
	// 判断通讯录中人数是否为0
	if (abs->size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名：" << abs->personArray[i].personName << '\t';
			cout << "性别：" << (abs->personArray[i].personSex == 1 ? "男" : "女") << '\t';
			cout << "年龄：" << abs->personArray[i].personAge << '\t';
			cout << "电话：" << abs->personArray[i].personPhone << '\t';
			cout << "住址：" << abs->personArray[i].personAddress << endl;
		}
	}
	system("pause"); // 请按任意键继续
	system("cls"); // 清屏操作
}

// 3、删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人： " << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) // 查询到了，删除此联系人
	{
		// 数据前移
		for (int i = ret + 1; i < abs->size; i++)
		{
			abs->personArray[i - 1] = abs->personArray[i];
		}
		// 更新通讯录人员数
		abs->size--;
		
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

// 4、查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人： " << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].personName << '\t';
		cout << "性别：" << abs->personArray[ret].personSex << '\t';
		cout << "年龄：" << abs->personArray[ret].personAge << '\t';
		cout << "电话：" << abs->personArray[ret].personPhone << '\t';
		cout << "地址：" << abs->personArray[ret].personAddress << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

// 5、修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人： " << endl;

	string name;
	cin >> name;
	
	int ret = isExist(abs, name);
	if (ret != -1) // 找到指定联系人
	{
		// 姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[ret].personName = name;

		// 性别
		int sex = 0;
		cout << "请输入性别： " << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].personSex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		// 年龄
		int age = 0;
		cout << "请输入年龄： " << endl;
		while (true)
		{
			cin >> age;
			if (age > 0)
			{
				abs->personArray[ret].personAge = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		// 电话
		int phone;
		cout << "请输入联系电话： " << endl;
		cin >> phone;
		abs->personArray[ret].personPhone = phone;

		// 住址
		string address;
		cout << "请输入家庭住址： " << endl;
		cin >> address;
		abs->personArray[ret].personAddress = address;

		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

// 6、清空联系人
void cleanPerson(Addressbooks* abs)
{
	char ret;
	cout << "是否确定清空通讯录？" << endl;
	cout << "y：确认    n：取消" << endl;
	cin >> ret;
	if (ret == 'y')
	{
		abs->size = 0; // 逻辑清空
		cout << "通讯录已清空！" << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	// 创建通讯录
	Addressbooks abs;
	abs.size = 0;

	int select = 0;
	while (true)
	{
		// 菜单调用
		showMenu();

		// 读取用户的选择
		cin >> select;
		switch (select)
		{
		case 1: // 添加联系人
			addPerson(&abs); // 传入引用参数修改通讯录
			break;
		case 2: // 显示联系人
			showPerson(&abs);
			break;
		case 3: // 删除联系人
			deletePerson(&abs);
			break;
		case 4: // 查找联系人
			findPerson(&abs);
			break;
		case 5: // 修改联系人
			modifyPerson(&abs);
			break;
		case 6: // 清空联系人
			cleanPerson(&abs);
			break;
		case 0: // 退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
		{
			cout << "输入有误，请重新输入：" << endl;
			system("pause");
			system("cls");
		}
			break;
		}
	}
	system("pause");

	return 0;
}