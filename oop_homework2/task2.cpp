#include <iostream>
#include <cstring>

using namespace std;

// ͳ���ַ����е�Ԫ����ĸ����
int countVowels(const char* p) {
	int count = 0;

	// �����ַ�����ֱ������'\0'������
	while (*p != '\0') {
		// ��鵱ǰ�ַ��Ƿ�ΪԪ����ĸ
		if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' ||
			*p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U') {
			count++;
		}
		p++; // �ƶ�ָ�뵽��һ���ַ�
	}

	return count;
}

// ʵ���������ͳ���ַ����е�Ԫ����ĸ����
void task2() {
	const int MAX_LENGTH = 100;
	char str[MAX_LENGTH];

	cout << "===== ʵ���������ͳ���ַ����е�Ԫ����ĸ���� =====" << endl;
	cout << "������һ���ַ���: ";
	cin.getline(str, MAX_LENGTH); // ��ȡһ���ַ���

	int vowelCount = countVowels(str);

	cout << "Number of vowels: " << vowelCount << endl;
	cout << endl;
}
