#include <iostream>
#include <iomanip>

using namespace std;

// 1. ��������������ƽ��
inline double square(double x) {
	return x * x;
}

// 2. ��Ĭ�ϲ����ĺ�����������ݣ�Ĭ�ϼ���ƽ��
double power(double base, int exponent = 2) {
	double result = 1.0;
	for (int i = 0; i < exponent; i++) {
		result *= base;
	}
	return result;
}

// 3. ���غ�������������double���͵���������
double calc(double a, double b, char op) {
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0) {
			cout << "Error: divide by zero" << endl;
			return 0.0; // ����һ��Ĭ��ֵ�������ᱻʹ��
		}
		return a / b;
	default:
		cout << "Error: invalid operator" << endl;
		return 0.0;
	}
}

// ���غ�������������int���͵���������
double calc(int a, int b, char op) {
	// ����double�汾��calc����
	return calc(static_cast<double>(a), static_cast<double>(b), op);
}

// ʵ�����������๦�ܼ�����
void task3() {
	// ���þ���
	cout << fixed << setprecision(2);

	double num1, num2;
	char op;

	cout << "===== ʵ�����������๦�ܼ����� =====" << endl;

	cout << "������������������һ������� (����: 3 5 +): ";
	cin >> num1 >> num2 >> op;

	cout << "square(" << num1 << ") = " << square(num1) << endl;

	cout << "power(" << num1 << "," << static_cast<int>(num2) << ") = " << power(num1, static_cast<int>(num2)) << endl;

	// ���ݲ���������ѡ����ʵ�calc�����汾
	if (num1 == static_cast<int>(num1) && num2 == static_cast<int>(num2)) {
		double result = calc(static_cast<int>(num1), static_cast<int>(num2), op);
		if (op != '/' || num2 != 0) { // �����ظ����������Ϣ
			cout << static_cast<int>(num1) << " " << op << " " << static_cast<int>(num2) << " = " << result << endl;
		}
	}
	else {
		double result = calc(num1, num2, op);
		if (op != '/' || num2 != 0) { // �����ظ����������Ϣ
			cout << num1 << " " << op << " " << num2 << " = " << result << endl;
		}
	}
	cout << endl;
}
