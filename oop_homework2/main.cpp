#include <iostream>
#include <limits>

using namespace std;

// 函数声明
void task1();
void task2();
void task3();
void task4();

// 清空输入缓冲区
void clearInputBuffer() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
	int choice;

	do {
		// 显示菜单
		cout << "===== C++ 实验任务集合 =====" << endl;
		cout << "1. 学生成绩管理系统" << endl;
		cout << "2. 统计字符串中的元音字母个数" << endl;
		cout << "3. 多功能计算器" << endl;
		cout << "4. 函数重载" << endl;
		cout << "0. 退出程序" << endl;
		cout << "============================" << endl;
		cout << "请选择要运行的实验任务 (0-4): ";

		// 读取用户选择
		cin >> choice;

		// 清空输入缓冲区
		clearInputBuffer();

		// 根据选择执行相应的任务
		switch (choice) {
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 0:
			cout << "程序已退出。" << endl;
			break;
		default:
			cout << "无效的选择，请重新输入。" << endl;
			cout << endl;
		}

		// 如果不是退出选项，等待用户按任意键继续
		if (choice != 0) {
			cout << "按任意键继续...";
			cin.get();
			cout << endl;
		}

	} while (choice != 0);

	return 0;
}
