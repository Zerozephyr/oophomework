#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// 定义结构体
struct Student {
	string name;
	double chinese;
	double math;
	double english;
	double average;
};

// 实验任务一：学生成绩管理系统
void task1() {
	int n;

	// 输入学生人数
	cout << "===== 实验任务一：学生成绩管理系统 =====" << endl;
	cout << "请输入学生人数: ";
	cin >> n;

	// 创建学生向量
	vector<Student> students(n);

	// 输入学生信息
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "名学生的信息 (姓名 语文 数学 英语): ";
		cin >> students[i].name >> students[i].chinese >> students[i].math >> students[i].english;

		// 计算平均分
		students[i].average = (students[i].chinese + students[i].math + students[i].english) / 3;
	}

	// 输出成绩表
	cout << endl << "学生成绩信息表:" << endl;
	cout << "----------------------------------------------------------------" << endl;

	// 设置输出格式
	cout << left << setw(10) << "姓名"
		<< right << setw(10) << "语文"
		<< setw(10) << "数学"
		<< setw(10) << "英语"
		<< setw(12) << "平均分"
		<< "评价" << endl;

	cout << "----------------------------------------------------------------" << endl;

	// 输出学生信息
	for (const auto& student : students) {
		cout << left << setw(10) << student.name
			<< right << fixed << setprecision(1)
			<< setw(10) << student.chinese
			<< setw(10) << student.math
			<< setw(10) << student.english
			<< setprecision(2)
			<< setw(12) << student.average;

		// 输出评价
		if (student.average >= 90) {
			cout << "  Excellent";
		}

		cout << endl;
	}

	cout << "----------------------------------------------------------------" << endl;
	cout << endl;
}
