#include "stdafx.h"
#include <iostream>
using namespace std;

/* ==============================================
�� ������ ���ϱ� �Լ�
- ������ ������ ����� ���� ���ΰ� ������
================================================= */
int getPerfectNumber(int min, int max) {
	int cnt = 0;  /* �������� ���� */
	int sum;      /* �ڱ��ڽ� ������ ������� �� */
	int n;

	for (int i = min; i <= max; i++) {
		n = 1;
		sum = 0;

		/* ������� �� ���ϱ� */
		while (n < i) {

			if (i % n == 0) {
				sum += n;
			}

			n++;
		}

		if (sum == i) {
			cout << "������ : " << sum << endl;
			cnt++;
		}
	}

	return cnt;
}

/* ==============================================
�� �Ͻ�Ʈ�ռ� ���ϱ�
- �ڸ�����ŭ �� �ڸ��� ���� 3�����ؼ� ���� ���� �ش� ���� ���� ��
- ��) 153 = 1^3 + 5^3 + 3^3 = 153
================================================= */
int getArmstrong(int min, int max) {
	int rest = 0;   /* ������ */
	int value = 0;  /* �� */
	int sum = 0;    /* �� */
	int cnt = 0;

	for (int i = min; i <= max; i++) {
		value = i;
		sum = 0;

		while (value != 0) {
			rest = value % 10;
			value = value / 10;
			sum = sum + (rest*rest*rest);
		}

		if (sum == i) {
			cout << "�Ͻ�Ʈ�ռ� : " << i << endl;
			cnt++;
		}
	}

	return cnt;
}

/* ==============================================
�� �Ҽ� ���ϱ�
- 1�� ���� ���� ����� ���� ����
================================================= */
int getPrime(int min, int max) {
	int cnt = 0;

	for (int i = min; i <= max; i++) {
		bool isMod = false;

		for (int j = 2; j <= i / 2; j++) {
			if (i % j == 0) {
				isMod = true;
				break;
			}
		}

		if (isMod == false) {
			cout << "�Ҽ� : " << i << endl;
			cnt++;
		}
	}

	return cnt;
}

/* ==============================================
�� Palindrome �� ���ϱ�
- 121, 12321 �� ���� �Ųٷ� ����� ���� ������ ��
================================================= */
int getPalindrome(int min, int max) {
	int cnt = 0;

	for (int i = min; i <= max; i++) {
		int sum = 0;

		for (int j = i; j != 0; j = j / 10) {
			int rest = j % 10;
			sum = sum * 10 + rest;
		}

		if (sum == i) {
			cout << "Palindrome �� : " << i << endl;
			cnt++;
		}
	}

	return cnt;
}

/* ==============================================
�� �Ǻ���ġ �� ���ϱ�
- 0, 1, 1, 2, 3, 5, 8, 13 ...
- ������ �Ǻ���ġ �� ��ȯ
================================================= */
int getFibonacci(int range) {
	int nFib = 0;
	int nFirst = 0, nSecond = 1;
	cout << nFirst << ", " << nSecond;

	int i = 2;
	while (i < range - 2) {
		nFib = nFirst + nSecond;
		nFirst = nSecond;
		nSecond = nFib;

		cout << ", " << nFib;

		i++;
	}

	return nFib;
}

/* ==============================================
�� ���丮�� ���ϱ� (!n)
- 5! = 1 * 2 * 3 * 4 * 5
================================================= */
int getFactorial(int num) {
	int nFact = 1;

	int i = 1;
	while (i <= num) {
		nFact = nFact * i;
		i++;
	}

	return nFact;
}

/* ==============================================
��  �ִ����� ���ϱ�
================================================= */
int getGCD(int x, int y) {
	while (x != y) {
		if (x > y)
			return getGCD(x - y, y);
		else 
			return getGCD(x, y - x);
	}

	return x;
}