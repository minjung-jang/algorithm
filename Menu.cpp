#include "stdafx.h"

#include <string>
#include <cstring>

#include "Menu.h"
#include "StringAlgorithm.h"
#include "MathAlgorithm.h"
#pragma warning(disable:4996)

// enum MENU_CL {MENU_LIST, STR_REV, STR_SWAP, ARMSTRONG, PRIME, PERFECT_NUM, PALINDROME_NUM, PALINDROME_STR, FIBONACCI, FACTORIAL, GCD};
void Menu::printMenuList() {
	cout << "    [ 알고리즘 실행 메뉴 고르기 ]" << endl;
	cout << "======================================" << endl;
	cout << STR_REV << "\t문자열 뒤집기 함수" << endl;
	cout << STR_SWAP << "\t문자열 바꾸기 함수" << endl;
	cout << ARMSTRONG << "\t암스트롱 수 구하기 함수" << endl;
	cout << PRIME << "\t소수 구하기 함수" << endl;
	cout << PERFECT_NUM << "\t완전수 구하기 함수" << endl;
	cout << PALINDROME_NUM << "\tpalindrome 수 구하기 함수" << endl;
	cout << PALINDROME_STR << "\tpalindrome 문자열 확인하기 함수" << endl;
	cout << FIBONACCI << "\t피보나치 수 구하기 함수" << endl;
	cout << FACTORIAL << "\t팩토리얼 구하기 함수" << endl;
	cout << GCD << "\t최대공약수 구하기 함수" << endl;
}

int Menu::getMenu() const {
	return m_menu;
}
void Menu::setMenu(MENU_CL menu_cl) {
	m_menu = menu_cl;
}

void Menu::selectMenu() {
	int menu_sel;

	while (true) {
		cout << endl;
		cout << "(프로그램을 종료하시려면 -1을 입력해주세요.) \n무슨 함수를 실행해보시겠습니까? ";
		try {
			cin >> menu_sel;
		}
		catch (...) {
			cout << "이상한거 입력하지마라.. " << endl;
		}

		if (menu_sel < MENU_LIST || menu_sel > GCD) {
			if (menu_sel == -1) {
				cout << "프로그램을 종료합니다." << endl;
				break;
			}
			cout << "잘못 입력하셨습니다." << endl;
		}
		else {
			setMenu((MENU_CL)menu_sel);
			cout << "\n함수를 실행합니다." << endl;
			executeAlgorithm((MENU_CL)menu_sel);
		}
	}	
}

void Menu::executeAlgorithm(MENU_CL menu) {
	cout << "============================================================================" << endl;

	switch (menu) {
	case STR_REV: 
		executeSTRREV();
		break;
	case STR_SWAP:
		executeSTRSWAP();
		break;
	case ARMSTRONG:
		executeARMSTRONG();
		break;
	case PRIME:
		executePRIME();
		break;
	case PERFECT_NUM:
		executePERFECT_NUM();
		break;
	case PALINDROME_NUM:
		executePALINDROME();
		break;
	case PALINDROME_STR:
		executePALINDROME_STR();
		break;
	case FIBONACCI:
		executeFIBONACCI();
		break;
	case FACTORIAL:
		executeFACTORIAL();
		break;
	case GCD:
		executeGCD();
		break;
	}

	cout << "============================================================================" << endl;
}

void Menu::executeSTRREV() {
	string tempStr;

	cout << "\t문자열 뒤집기 함수를 선택하셨습니다. 문자열을 입력해주세요.\n ▶  ";

	cin.ignore(1, '\n');
	getline(cin, tempStr);

	char* temp = new char[tempStr.length() + 1];
	strcpy(temp, tempStr.c_str());

	reverse_string(temp);
	cout << "◆ 뒤집혀진 문자열 확인 : " << temp << endl;

	delete[] temp;
}

void Menu::executeSTRSWAP() {
	string strA, strB;
	char* cstrA;
	char* cstrB;

	cout << "\t문자열 바꾸기 함수를 선택하셨습니다. 문자열 두개를 입력해주세요." << endl;
	cout << "■ 첫 번째 문자열 : ";

	cin.ignore(1, '\n');
	getline(cin, strA);

	cstrA = new char[strA.length() + 1];
	strcpy(cstrA, strA.c_str());

	cout << "■ 두 번째 문자열 : ";

	//cin.ignore(1, '\n');   두 번째엔 개행문자가 쓰이지 않았으므로 해당 문장을 넣을 필요가 없음.
	getline(cin, strB);

	cstrB = new char[strB.length() + 1];
	strcpy(cstrB, strB.c_str());

	cout << "- 첫 번째 문자열 [" << cstrA << "] 두 번째 문자열 [" << cstrB << "]" << endl;
	swap(&cstrA, &cstrB);
	cout << "- 첫 번째 문자열 [" << cstrA << "] 두 번째 문자열 [" << cstrB << "]" << endl;

	delete[] cstrA;
	delete[] cstrB;
}

void Menu::executeARMSTRONG() {
	cout << "\t암스트롱수 구하기 함수를 선택하셨습니다. (범위는 0 ~ 999)" << endl;

	int cnt = getArmstrong(0, 999);

	cout << "▶ 암스트롱수는 총 " << cnt << "개 입니다." << endl;
}

void Menu::executePRIME() {
	int nMin = 0, nMax = 0;
	cout << "\t소수 구하기 함수를 선택하셨습니다. 범위를 입력해주세요." << endl;
	cout << "- 최소값 : ";
	cin >> nMin;
	
	cout << "- 최소값 : ";
	cin >> nMax;

	int cnt = getPrime(nMin, nMax);

	cout << "▶ 범위 " << nMin << " ~ " << nMax << " 사이의 소수의 개수는 " << cnt << "개 입니다." << endl;
}

void Menu::executePERFECT_NUM() {
	int nMin = 0, nMax = 0;
	cout << "\t완전수 구하기 함수를 선택하셨습니다. 범위를 입력해주세요." << endl;
	cout << "- 최소값 : ";
	cin >> nMin;

	cout << "- 최소값 : ";
	cin >> nMax;

	int cnt = getPerfectNumber(nMin, nMax);

	cout << "▶ 범위 " << nMin << " ~ " << nMax << " 사이의 완전수의 개수는 " << cnt << "개 입니다." << endl;
}

void Menu::executePALINDROME() {
	int nMin = 0, nMax = 0;
	cout << "\tPalindrome 수 구하기 함수를 선택하셨습니다. 범위를 입력해주세요." << endl;
	cout << "- 최소값 : ";
	cin >> nMin;

	cout << "- 최소값 : ";
	cin >> nMax;

	int cnt = getPalindrome(nMin, nMax);

	cout << "▶ 범위 " << nMin << " ~ " << nMax << " 사이의 Palindrome 수의 개수는 " << cnt << "개 입니다." << endl;
}

void Menu::executePALINDROME_STR() {
	cout << "\tPalindrome 문자열 확인하기 함수를 선택하셨습니다." << endl;
	cout << "■ 확인할 문자열 입력 : ";
	
	string str;

	cin.ignore(1, '\n');
	getline(cin, str);

	bool bCk = isPalindromeString(str);

	cout << "▶ 입력하신 문자열 " << str << "은 Palindrome 문자열이 " << (bCk == true ? "맞습니다." : "아닙니다.") << endl;
}

void Menu::executeFIBONACCI() {
	int nMax = 0;

	cout << "\t피보나치 수 구하기 함수를 선택하셨습니다." << endl;
	cout << "■ 구하고자 하는 피보나치 수 개수 : ";
	cin >> nMax;

	int maxVal = getFibonacci(nMax);

	cout << "▶ " << nMax << " 번째의 피보나치 수는 " << maxVal << " 입니다." << endl;
}

void Menu::executeFACTORIAL() {
	int nNum = 0;

	cout << "\t팩토리얼 구하기 함수를 선택하셨습니다." << endl;
	cout << "■ 숫자를 입력해주세요 : ";
	cin >> nNum;

	int nFact = getFactorial(nNum);

	cout << "▶ !" << nNum << " : " << nFact << endl;
}

void Menu::executeGCD() {
	int nFirst = 0, nSecond = 0;

	cout << "\t최대공약수 구하기 함수를 선택하셨습니다." << endl;
	cout << "■ 두 개의 숫자를 입력해주세요." << endl;
	cout << "- 첫 번째 수 : ";
	cin >> nFirst;

	cout << "- 두 번째 수 : ";
	cin >> nSecond;

	int nGcd = getGCD(nFirst, nSecond);

	cout << "▶ " << nFirst << "와 " << nSecond << "의 최대공약수는 " << nGcd << " 입니다." << endl;
}