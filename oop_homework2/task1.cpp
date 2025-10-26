#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// ����ṹ��
struct Student {
	string name;
	double chinese;
	double math;
	double english;
	double average;
};

// ʵ������һ��ѧ���ɼ�����ϵͳ
void task1() {
	int n;

	// ����ѧ������
	cout << "===== ʵ������һ��ѧ���ɼ�����ϵͳ =====" << endl;
	cout << "������ѧ������: ";
	cin >> n;

	// ����ѧ������
	vector<Student> students(n);

	// ����ѧ����Ϣ
	for (int i = 0; i < n; i++) {
		cout << "�������" << i + 1 << "��ѧ������Ϣ (���� ���� ��ѧ Ӣ��): ";
		cin >> students[i].name >> students[i].chinese >> students[i].math >> students[i].english;

		// ����ƽ����
		students[i].average = (students[i].chinese + students[i].math + students[i].english) / 3;
	}

	// ����ɼ���
	cout << endl << "ѧ���ɼ���Ϣ��:" << endl;
	cout << "----------------------------------------------------------------" << endl;

	// ���������ʽ
	cout << left << setw(10) << "����"
		<< right << setw(10) << "����"
		<< setw(10) << "��ѧ"
		<< setw(10) << "Ӣ��"
		<< setw(12) << "ƽ����"
		<< "����" << endl;

	cout << "----------------------------------------------------------------" << endl;

	// ���ѧ����Ϣ
	for (const auto& student : students) {
		cout << left << setw(10) << student.name
			<< right << fixed << setprecision(1)
			<< setw(10) << student.chinese
			<< setw(10) << student.math
			<< setw(10) << student.english
			<< setprecision(2)
			<< setw(12) << student.average;

		// �������
		if (student.average >= 90) {
			cout << "  Excellent";
		}

		cout << endl;
	}

	cout << "----------------------------------------------------------------" << endl;
	cout << endl;
}
