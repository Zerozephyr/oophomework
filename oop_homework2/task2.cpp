#include <iostream>
#include <cstring>

using namespace std;

// 统计字符串中的元音字母数量
int countVowels(const char* p) {
	int count = 0;

	// 遍历字符串，直到遇到'\0'结束符
	while (*p != '\0') {
		// 检查当前字符是否为元音字母
		if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' ||
			*p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U') {
			count++;
		}
		p++; // 移动指针到下一个字符
	}

	return count;
}

// 实验任务二：统计字符串中的元音字母个数
void task2() {
	const int MAX_LENGTH = 100;
	char str[MAX_LENGTH];

	cout << "===== 实验任务二：统计字符串中的元音字母个数 =====" << endl;
	cout << "请输入一行字符串: ";
	cin.getline(str, MAX_LENGTH); // 读取一行字符串

	int vowelCount = countVowels(str);

	cout << "Number of vowels: " << vowelCount << endl;
	cout << endl;
}
