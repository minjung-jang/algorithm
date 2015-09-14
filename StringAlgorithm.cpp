#include "stdafx.h"

#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;

/*	=============================================================================================
	호출시 매개변수로 넘겨지는 변수가 char a[10]와 같은 배열이 아닌 char* 형이면 메모리 참조 오류가 납니다. 
	동적할당으로 메모리가 확보된 경우라도 char* 형이면 오류
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
		cout << "교환할 두 배열의 길이가 다릅니다." << endl;
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