#include "card_operations.h"

// 命名空间实现：格式化输出
namespace card
{
	void printLine(char c, int len)
	{
		for (int i = 0; i < len; ++i)
			cout << c;
		cout << endl;
	}

	void title(const string& s)
	{
		printLine('=');
		cout << "==================== " << s << " ====================" << endl;
		printLine('=');
	}
}

// 动态内存管理实现
Card* createCards(int n)
{
	try
	{
		Card* p = new Card[n];
		return p;
	}
	catch (const bad_alloc& e)
	{
		cerr << "内存分配失败: " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}

void destroyCards(Card* p)
{
	delete[] p;
}

// 账户录入实现（带异常处理）
void inputCards(Card* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "请输入第"<<i+1<<"位用户的学号、姓名和初始余额: ";
		try
		{
			cin >> arr[i].id >> arr[i].name >> arr[i].balance;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				throw runtime_error("输入格式错误，请输入正确的类型");
			}

			if (arr[i].balance < 0)
				throw invalid_argument("初始余额不能为负数");

			arr[i].transactions = 0;
		}
		catch (const exception& e)
		{
			cout << "输入异常: " << e.what() << "，请重新输入" << endl;
			i--;  // 重新输入当前用户
		}
	}
}

// 账户操作实现
void deposit(Card& c, double amount, double fee)
{
	if (amount <= 0)
		throw invalid_argument("充值金额必须为正数");
	c.balance += amount * (1.0 - fee);
	c.transactions++;
}

bool spend(Card& c, double cost)
{
	if (cost <= 0)
		throw invalid_argument("消费金额不能为负数");
	if (c.balance < cost)
		throw runtime_error("余额不足，消费失败");

	c.balance -= cost;
	c.transactions++;
	return true;
}

bool spend(Card& c, double cost, const string& item)
{
	cout << "消费项目: " << item << endl;
	try
	{
		return spend(c, cost);
	}
	catch (const exception& e)
	{
		cout << "异常提示: " << e.what() << endl;
		return false;
	}
}

// 常量引用与指针实现
void showBalance(const Card& c)
{
	cout << c.name << " 当前余额为: " << fixed << setprecision(2) << c.balance << endl;
}

void viewStudentID(const Card* p)
{
	cout << "账户ID为: " << p->id << endl;
}

// 类型转换实现
int toCent(double amount)
{
	return static_cast<int>(amount * 100);
}

// 报表输出实现
void printReport(const Card* arr, int n)
{
	using namespace card;
	printLine('=');
	cout << left << setw(8) << "ID"
		<< left << setw(12) << "Name"
		<< right << setw(14) << "Balance"
		<< right << setw(14) << "Transactions" << endl;
	printLine('-');

	cout << fixed << setprecision(2);
	for (int i = 0; i < n; ++i)
	{
		cout << left << setw(8) << arr[i].id
			<< left << setw(12) << arr[i].name
			<< right << setw(14) << arr[i].balance
			<< right << setw(14) << arr[i].transactions << endl;
	}
	printLine('=');
}

// 显示操作菜单
void showMenu() {
	card::printLine();
	cout << "===== 操作菜单 =====" << endl;
	cout << "1. 充值" << endl;
	cout << "2. 消费" << endl;
	cout << "3. 查看余额" << endl;
	cout << "4. 查看账户ID" << endl;
	cout << "5. 打印所有用户报表" << endl;
	cout << "0. 退出系统" << endl;
	card::printLine();
}

// 查找用户索引（根据学号）
int findUserIndex(const Card* arr, int n, int id) {
	for (int i = 0; i < n; ++i) {
		if (arr[i].id == id) {
			return i;
		}
	}
	return -1; // 未找到
}

// 选择用户（调用用户查找函数）
int chooseUser(const Card* users, int n) {
	int userId;
	cout << "请输入操作的学号: ";
	cin >> userId;
	int idx = findUserIndex(users, n, userId); // 此时可访问users和n（通过参数传入）
	if (idx == -1) {
		cout << "未找到学号为 " << userId << " 的用户！" << endl;
	}
	return idx; 
}