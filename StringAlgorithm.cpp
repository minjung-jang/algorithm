#include "stdafx.h"

#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;

/*	=============================================================================================
	ȣ��� �Ű������� �Ѱ����� ������ char a[10]�� ���� �迭�� �ƴ� char* ���̸� �޸� ���� ������ ���ϴ�. 
	�����Ҵ����� �޸𸮰� Ȯ���� ���� char* ���̸� ����
	============================================================================================= */
void reverse_string(char* str) {
	char c_temp;

	for (unsigned int i = strlen(str) - 1; i >= strlen(str)/2; i--) {
		c_temp = str[i];
		str[i] = str[strlen(str) - i - 1];
		str[strlen(str) - i - 1] = c_temp;
	}
}

void swap_string(char* a, unsigned int a_len, char* b, unsigned int b_len) {
	if (a_len != b_len) {
		cout << "��ȯ�� �� �迭�� ���̰� �ٸ��ϴ�." << endl;
		return;
	}

	for (unsigned int i = 0; i < a_len; i++) {
		a[i] = a[i] ^ b[i];
		b[i] = a[i] ^ b[i];
		a[i] = a[i] ^ b[i];
	}
}

bool isPalindromeString(string str) {
	bool bCk = false;

	char* revStr = new char[str.length() + 1];
	char* oriStr = new char[str.length() + 1];
	strcpy(oriStr, str.c_str());

	int i, j;
	for (i = str.length() - 1, j = 0; i >= 0; i--, j++) {
		revStr[j] = oriStr[i];
	}
	revStr[j] = '\0';

	if (strcmp(revStr, oriStr) == 0) {
		bCk = true;
	}

	delete[] revStr;
	delete[] oriStr;

	return bCk;
}