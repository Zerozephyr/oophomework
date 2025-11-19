#include <iostream>
#include <string>
using namespace std;

class Date {

private:
	int day;
	int month;
	int year;

public:
	//录入年月日信息
	void initDate(int x, int y, int z) {
		day = x;
		month = y;
		year = z;
	}

	//显示年月日信息
	void showDate() {
		cout << year << "年" << month << "月" << day << "日" << endl;
	}

	//获取年月日信息
	void getDay(int& x) {
		x = day;
	}
	void getMonth(int& y) {
		y = month;
	}
	void getYear(int& z) {
		z = year;
	}

	//更改年月日信息
	void setDay(int x) {
		day = x;
	}
	void setMonth(int y) {
		month = y;
	}
	void setYear(int z) {
		year = z;
	}

	// 计算并输出当前日期为星期几
	int calWeekday() {
		int y = year, m = month, d = day;
		// 处理1月和2月的特殊情况
		if (m == 1 || m == 2) {
			m += 12;
			y--;
		}
		// 基姆拉尔森计算公式
		int weekday = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
		// 转换为0-6对应星期日到星期六
		string weekStr[7] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
		cout << "该日期是:" << weekStr[weekday] << endl;
		return weekday;
	}

};

class Triangle {
private:
	//三角形的三个边长
	double a;
	double b;
	double c;

public:
	// 录入边长信息
	void initTriangle(double x, double y, double z) {
		a = x;
		b = y;
		c = z;
	}

	// 显示三角形的三个边长信息
	void showTriangle() {
		cout << "三角形的三边长分别为: " << a << ", " << b << ", " << c << endl;
	}

	// 获取三角形的三个边长信息
	void getA(double& x) { x = a; }
	void getB(double& y) { y = b; }
	void getC(double& z) { z = c; }

	// 更改三角形的三个边长信息
	void setA(double x) { a = x; }
	void setB(double y) { b = y; }
	void setC(double z) { c = z; }

	// 判断当前边长是否能构成一个有效的三角形
	bool isValid() {
		return (a + b > c) && (a + c > b) && (b + c > a);
	}

	// 计算三角形周长
	double perimeter() {
		if (!isValid()) {
			cout << "不是有效三角形，无法计算周长" << endl;
			return 0;
		}
		return a + b + c;
	}

	// 计算三角形面积（海伦公式）
	double area() {
		if (!isValid()) {
			cout << "不是有效三角形，无法计算面积" << endl;
			return 0;
		}
		double p = perimeter() / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}

	// 判断三角形类型（0-直角，1-锐角，2-钝角）
	int typeTriangle() {
		if (!isValid()) {
			cout << "不是有效三角形，无法判断类型" << endl;
			return -1;
		}
		// 确定最长边
		double maxSide = a;
		double other1 = b, other2 = c;
		if (b > maxSide) {
			maxSide = b;
			other1 = a;
			other2 = c;
		}
		if (c > maxSide) {
			maxSide = c;
			other1 = a;
			other2 = b;
		}
		// 判断类型
		double sumSquare = other1 * other1 + other2 * other2;
		double maxSquare = maxSide * maxSide;
		if (fabs(sumSquare - maxSquare) < 1e-6) { // 直角三角形
			return 0;
		}
		else if (sumSquare > maxSquare) { // 锐角三角形
			return 1;
		}
		else { // 钝角三角形
			return 2;
		}
	}

};

int main() {
    Date today;
    int d, m, y;
    int choice;

    cout << "===== 测试 Date 类 =====" << endl;
    cout << "请输入今天的日期（年 月 日）：";
    cin >> y >> m >> d;
    today.initDate(d, m, y);
    cout << "今天是：";
    today.showDate();
    today.calWeekday();

    cout << "\n--- 修改日期信息 ---" << endl;
    do {
        cout << "请选择要修改的内容（1-年 2-月 3-日 0-退出）：";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "请输入新的年份：";
            cin >> y;
            today.setYear(y);
            cout << "年修改成功！" << endl;
            break;
        case 2:
            cout << "请输入新的月份：";
            cin >> m;
            today.setMonth(m);
            cout << "月修改成功！" << endl;
            break;
        case 3:
            cout << "请输入新的日期：";
            cin >> d;
            today.setDay(d);
            cout << "日修改成功！" << endl;
            break;
        case 0:
            cout << "退出修改模式。" << endl;
            break;
        default:
            cout << "无效的选择，请重新输入。" << endl;
            break;
        }
    } while (choice != 0);

    cout << "\n--- 显示日期信息 ---" << endl;
    today.getYear(y);
    today.getMonth(m);
    today.getDay(d);
    do {
        cout << "请选择要显示的内容（1-年 2-月 3-日 0-退出）：";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "年份是：" << y << endl;
            break;
        case 2:
            cout << "月份是：" << m << endl;
            break;
        case 3:
            cout << "日期是：" << d << endl;
            break;
        case 0:
            cout << "退出输出模式。" << endl;
            break;
        default:
            cout << "无效的选择，请重新输入。" << endl;
            break;
        }
    } while (choice != 0);

    cout << "\n===== 测试 Triangle 类 =====" << endl;
    Triangle tri;
    double a, b, c;
    cout << "请输入三角形的三条边长：";
    cin >> a >> b >> c;
    tri.initTriangle(a, b, c);
    tri.showTriangle();

    cout << "\n--- 验证三角形有效性 ---" << endl;
    if (tri.isValid()) {
        cout << "这是一个有效的三角形。" << endl;
        cout << "三角形周长：" << tri.perimeter() << endl;
        cout << "三角形面积：" << tri.area() << endl;

        cout << "\n--- 三角形类型判断 ---" << endl;
        int type = tri.typeTriangle();
        string typeStr[] = { "直角三角形", "锐角三角形", "钝角三角形" };
        cout << "三角形类型：" << typeStr[type] << endl;
    }
    else {
        cout << "输入的边长无法构成三角形。" << endl;
    }

    cout << "\n--- 修改三角形边长 ---" << endl;
    do {
        cout << "请选择要修改的边长（1-a 2-b 3-c 0-退出）：";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "请输入新的边长 a：";
            cin >> a;
            tri.setA(a);
            cout << "边长 a 修改成功！" << endl;
            break;
        case 2:
            cout << "请输入新的边长 b：";
            cin >> b;
            tri.setB(b);
            cout << "边长 b 修改成功！" << endl;
            break;
        case 3:
            cout << "请输入新的边长 c：";
            cin >> c;
            tri.setC(c);
            cout << "边长 c 修改成功！" << endl;
            break;
        case 0:
            cout << "退出修改模式。" << endl;
            break;
        default:
            cout << "无效的选择，请重新输入。" << endl;
            break;
        }
    } while (choice != 0);

    cout << "\n--- 修改后的三角形信息 ---" << endl;
    tri.showTriangle();
    if (tri.isValid()) {
        cout << "修改后的三角形是有效的。" << endl;
        cout << "新周长：" << tri.perimeter() << endl;
        cout << "新面积：" << tri.area() << endl;
        int type = tri.typeTriangle();
        string typeStr[] = { "直角三角形", "锐角三角形", "钝角三角形" };
        cout << "新三角形类型：" << typeStr[type] << endl;
    }
    else {
        cout << "修改后的边长无法构成三角形。" << endl;
    }

    return 0;
}

