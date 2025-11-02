#include "card_operations.h"

int main() {
	using namespace card;

	// 系统初始化
	title("Campus Card System");
	int n;
	cout << "请输入学生数量: ";
	while (!(cin >> n) || n <= 0) { // 输入校验
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "输入错误，请输入正整数: ";
	}

	Card* users = createCards(n);
	inputCards(users, n);
	cout << "初始化完成！" << endl;



	// 菜单循环（核心修改：调用showMenu和findUserIndex）
	int choice;
	int idx;
	do {
		showMenu(); // 调用菜单显示函数
		cout << "请选择操作(0-5): ";
		while (!(cin >> choice) || choice < 0 || choice > 5) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "输入错误，请输入0-5之间的数字: ";
		}

		if (choice == 0) break;

		// 操作逻辑（保持原switch结构不变）
		switch (choice) {
		case 1: { // 充值
			idx = chooseUser(users, n);
			double amount;
			cout << "请输入充值金额: ";
			cin >> amount;
			try {
				deposit(users[idx], amount);
				cout << "充值成功！当前余额（已扣除服务费）: " << fixed << setprecision(2) << users[idx].balance << endl;
			}
			catch (const exception& e) {
				cout << "充值失败: " << e.what() << endl;
			}
			break;
		}
		case 2: { // 消费
			idx = chooseUser(users, n);
			double cost;
			string item;
			cout << "请输入消费项目: ";
			cin.ignore();
			getline(cin, item);
			cout << "请输入消费金额: ";
			cin >> cost;
			spend(users[idx], cost, item);
			break;
		}
		case 3: // 查询余额
			idx = chooseUser(users, n);
			showBalance(users[idx]);
			break;
		case 4: // 查询用户ID
			idx = chooseUser(users, n);
			viewStudentID(&users[idx]);
			break;
		case 5: // 打印报表
			printReport(users, n);
			break;
		}
	} while (true);

	// 资源释放
	destroyCards(users);
	return 0;
}