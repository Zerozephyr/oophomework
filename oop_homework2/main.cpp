#include <iostream>
#include <limits>

using namespace std;

// ��������
void task1();
void task2();
void task3();
void task4();

// ������뻺����
void clearInputBuffer() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
	int choice;

	do {
		// ��ʾ�˵�
		cout << "===== C++ ʵ�����񼯺� =====" << endl;
		cout << "1. ѧ���ɼ�����ϵͳ" << endl;
		cout << "2. ͳ���ַ����е�Ԫ����ĸ����" << endl;
		cout << "3. �๦�ܼ�����" << endl;
		cout << "4. ��������" << endl;
		cout << "0. �˳�����" << endl;
		cout << "============================" << endl;
		cout << "��ѡ��Ҫ���е�ʵ������ (0-4): ";

		// ��ȡ�û�ѡ��
		cin >> choice;

		// ������뻺����
		clearInputBuffer();

		// ����ѡ��ִ����Ӧ������
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
			cout << "�������˳���" << endl;
			break;
		default:
			cout << "��Ч��ѡ�����������롣" << endl;
			cout << endl;
		}

		// ��������˳�ѡ��ȴ��û������������
		if (choice != 0) {
			cout << "�����������...";
			cin.get();
			cout << endl;
		}

	} while (choice != 0);

	return 0;
}
