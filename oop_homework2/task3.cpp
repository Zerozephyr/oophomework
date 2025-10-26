#include <iostream>
#include <iomanip>

using namespace std;

// 1. 内联函数：计算平方
inline double square(double x) {
	return x * x;
}

// 2. 带默认参数的函数：计算乘幂，默认计算平方
double power(double base, int exponent = 2) {
	double result = 1.0;
	for (int i = 0; i < exponent; i++) {
		result *= base;
	}
	return result;
}

// 3. 重载函数：计算两个double类型的四则运算
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
			return 0.0; // 返回一个默认值，但不会被使用
		}
		return a / b;
	default:
		cout << "Error: invalid operator" << endl;
		return 0.0;
	}
}

// 重载函数：计算两个int类型的四则运算
double calc(int a, int b, char op) {
	// 调用double版本的calc函数
	return calc(static_cast<double>(a), static_cast<double>(b), op);
}

// 实验任务三：多功能计算器
void task3() {
	// 设置精度
	cout << fixed << setprecision(2);

	double num1, num2;
	char op;

	cout << "===== 实验任务三：多功能计算器 =====" << endl;

	cout << "请输入两个操作数和一个运算符 (例如: 3 5 +): ";
	cin >> num1 >> num2 >> op;

	cout << "square(" << num1 << ") = " << square(num1) << endl;

	cout << "power(" << num1 << "," << static_cast<int>(num2) << ") = " << power(num1, static_cast<int>(num2)) << endl;

	// 根据操作数类型选择合适的calc函数版本
	if (num1 == static_cast<int>(num1) && num2 == static_cast<int>(num2)) {
		double result = calc(static_cast<int>(num1), static_cast<int>(num2), op);
		if (op != '/' || num2 != 0) { // 避免重复输出错误信息
			cout << static_cast<int>(num1) << " " << op << " " << static_cast<int>(num2) << " = " << result << endl;
		}
	}
	else {
		double result = calc(num1, num2, op);
		if (op != '/' || num2 != 0) { // 避免重复输出错误信息
			cout << num1 << " " << op << " " << num2 << " = " << result << endl;
		}
	}
	cout << endl;
}
