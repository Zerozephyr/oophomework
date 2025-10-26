#include <iostream>
#include <iomanip>

using namespace std;

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void swap(double& x, double& y) {
	double temp = x;
	x = y;
	y = temp;
}

void swap(char& x, char& y) {
	char temp = x;
	x = y;
	y = temp;
}

// ʵ�������ģ���������
void task4() {
	int x, y;

	cout << "===== ʵ�������ģ��������� =====" << endl;

	cout << "��������������: ";
	cin >> x >> y;

	cout << "Before swap: x=" << x << ", y=" << y << endl;

	// ����swap������������
	swap(x, y);

	cout << "After  swap: x=" << x << ", y=" << y << endl;

	// �����������͵�swap����
	double a = 3.14, b = 2.71;
	cout << "\nBefore swap: a=" << fixed << setprecision(2) << a << ", b=" << b << endl;
	swap(a, b);
	cout << "After  swap: a=" << a << ", b=" << b << endl;

	char c = 'A', d = 'B';
	cout << "\nBefore swap: c=" << c << ", d=" << d << endl;
	swap(c, d);
	cout << "After  swap: c=" << c << ", d=" << d << endl;
	cout << endl;
}
