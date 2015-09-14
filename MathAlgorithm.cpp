#include "stdafx.h"
#include <iostream>
using namespace std;

/* ==============================================
■ 완전수 구하기 함수
- 본인을 제외한 약수의 합이 본인과 같은수
================================================= */
int getPerfectNumber(int min, int max) {
	int cnt = 0;  /* 완전수의 개수 */
	int sum;      /* 자기자신 제외한 약수들의 합 */
	int n;

	for (int i = min; i <= max; i++) {
		n = 1;
		sum = 0;

		/* 약수들의 합 구하기 */
		while (n < i) {

			if (i % n == 0) {
				sum += n;
			}

			n++;
		}

		if (sum == i) {
			cout << "완전수 : " << sum << endl;
			cnt++;
		}
	}

	return cnt;
}

/* ==============================================
■ 암스트롱수 구하기
- 자리수만큼 각 자리의 숫자 3제곱해서 더한 값이 해당 값과 같은 수
- 예) 153 = 1^3 + 5^3 + 3^3 = 153
================================================= */
int getArmstrong(int min, int max) {
	int rest = 0;   /* 나머지 */
	int value = 0;  /* 몫 */
	int sum = 0;    /* 합 */
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
			cout << "암스트롱수 : " << i << endl;
			cnt++;
		}
	}

	return cnt;
}

/* ==============================================
■ 소수 구하기
- 1과 본인 외의 약수가 없는 정수
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
			cout << "소수 : " << i << endl;
			cnt++;
		}
	}

	return cnt;
}

/* ==============================================
■ Palindrome 수 구하기
- 121, 12321 과 같이 거꾸로 뒤집어도 같은 숫자인 수
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
			cout << "Palindrome 수 : " << i << endl;
			cnt++;
		}
	}

	return cnt;
}

/* ==============================================
■ 피보나치 수 구하기
- 0, 1, 1, 2, 3, 5, 8, 13 ...
- 마지막 피보나치 수 반환
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
■ 팩토리얼 구하기 (!n)
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
■  최대공약수 구하기
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