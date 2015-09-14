#include "stdafx.h"

#include <string>
#include <cstring>

#include "Menu.h"
#include "StringAlgorithm.h"
#include "MathAlgorithm.h"
#pragma warning(disable:4996)

// enum MENU_CL {MENU_LIST, STR_REV, STR_SWAP, ARMSTRONG, PRIME, PERFECT_NUM, PALINDROME_NUM, PALINDROME_STR, FIBONACCI, FACTORIAL, GCD};
void Menu::printMenuList() {
	cout << "    [ �˰��� ���� �޴� ���� ]" << endl;
	cout << "======================================" << endl;
	cout << STR_REV << "\t���ڿ� ������ �Լ�" << endl;
	cout << STR_SWAP << "\t���ڿ� �ٲٱ� �Լ�" << endl;
	cout << ARMSTRONG << "\t�Ͻ�Ʈ�� �� ���ϱ� �Լ�" << endl;
	cout << PRIME << "\t�Ҽ� ���ϱ� �Լ�" << endl;
	cout << PERFECT_NUM << "\t������ ���ϱ� �Լ�" << endl;
	cout << PALINDROME_NUM << "\tpalindrome �� ���ϱ� �Լ�" << endl;
	cout << PALINDROME_STR << "\tpalindrome ���ڿ� Ȯ���ϱ� �Լ�" << endl;
	cout << FIBONACCI << "\t�Ǻ���ġ �� ���ϱ� �Լ�" << endl;
	cout << FACTORIAL << "\t���丮�� ���ϱ� �Լ�" << endl;
	cout << GCD << "\t�ִ����� ���ϱ� �Լ�" << endl;
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
		cout << "(���α׷��� �����Ͻ÷��� -1�� �Է����ּ���.) \n���� �Լ��� �����غ��ðڽ��ϱ�? ";
		try {
			cin >> menu_sel;
		}
		catch (...) {
			cout << "�̻��Ѱ� �Է���������.. " << endl;
		}

		if (menu_sel < MENU_LIST || menu_sel > GCD) {
			if (menu_sel == -1) {
				cout << "���α׷��� �����մϴ�." << endl;
				break;
			}
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		}
		else {
			setMenu((MENU_CL)menu_sel);
			cout << "\n�Լ��� �����մϴ�." << endl;
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

	cout << "\t���ڿ� ������ �Լ��� �����ϼ̽��ϴ�. ���ڿ��� �Է����ּ���.\n ��  ";

	cin.ignore(1, '\n');
	getline(cin, tempStr);

	char* temp = new char[tempStr.length() + 1];
	strcpy(temp, tempStr.c_str());

	reverse_string(temp);
	cout << "�� �������� ���ڿ� Ȯ�� : " << temp << endl;

	delete[] temp;
}

void Menu::executeSTRSWAP() {
	string strA, strB;
	char* cstrA;
	char* cstrB;

	cout << "\t���ڿ� �ٲٱ� �Լ��� �����ϼ̽��ϴ�. ���ڿ� �ΰ��� �Է����ּ���." << endl;
	cout << "�� ù ��° ���ڿ� : ";

	cin.ignore(1, '\n');
	getline(cin, strA);

	cstrA = new char[strA.length() + 1];
	strcpy(cstrA, strA.c_str());

	cout << "�� �� ��° ���ڿ� : ";

	//cin.ignore(1, '\n');   �� ��°�� ���๮�ڰ� ������ �ʾ����Ƿ� �ش� ������ ���� �ʿ䰡 ����.
	getline(cin, strB);

	cstrB = new char[strB.length() + 1];
	strcpy(cstrB, strB.c_str());

	cout << "- ù ��° ���ڿ� [" << cstrA << "] �� ��° ���ڿ� [" << cstrB << "]" << endl;
	swap(&cstrA, &cstrB);
	cout << "- ù ��° ���ڿ� [" << cstrA << "] �� ��° ���ڿ� [" << cstrB << "]" << endl;

	delete[] cstrA;
	delete[] cstrB;
}

void Menu::executeARMSTRONG() {
	cout << "\t�Ͻ�Ʈ�ռ� ���ϱ� �Լ��� �����ϼ̽��ϴ�. (������ 0 ~ 999)" << endl;

	int cnt = getArmstrong(0, 999);

	cout << "�� �Ͻ�Ʈ�ռ��� �� " << cnt << "�� �Դϴ�." << endl;
}

void Menu::executePRIME() {
	int nMin = 0, nMax = 0;
	cout << "\t�Ҽ� ���ϱ� �Լ��� �����ϼ̽��ϴ�. ������ �Է����ּ���." << endl;
	cout << "- �ּҰ� : ";
	cin >> nMin;
	
	cout << "- �ּҰ� : ";
	cin >> nMax;

	int cnt = getPrime(nMin, nMax);

	cout << "�� ���� " << nMin << " ~ " << nMax << " ������ �Ҽ��� ������ " << cnt << "�� �Դϴ�." << endl;
}

void Menu::executePERFECT_NUM() {
	int nMin = 0, nMax = 0;
	cout << "\t������ ���ϱ� �Լ��� �����ϼ̽��ϴ�. ������ �Է����ּ���." << endl;
	cout << "- �ּҰ� : ";
	cin >> nMin;

	cout << "- �ּҰ� : ";
	cin >> nMax;

	int cnt = getPerfectNumber(nMin, nMax);

	cout << "�� ���� " << nMin << " ~ " << nMax << " ������ �������� ������ " << cnt << "�� �Դϴ�." << endl;
}

void Menu::executePALINDROME() {
	int nMin = 0, nMax = 0;
	cout << "\tPalindrome �� ���ϱ� �Լ��� �����ϼ̽��ϴ�. ������ �Է����ּ���." << endl;
	cout << "- �ּҰ� : ";
	cin >> nMin;

	cout << "- �ּҰ� : ";
	cin >> nMax;

	int cnt = getPalindrome(nMin, nMax);

	cout << "�� ���� " << nMin << " ~ " << nMax << " ������ Palindrome ���� ������ " << cnt << "�� �Դϴ�." << endl;
}

void Menu::executePALINDROME_STR() {
	cout << "\tPalindrome ���ڿ� Ȯ���ϱ� �Լ��� �����ϼ̽��ϴ�." << endl;
	cout << "�� Ȯ���� ���ڿ� �Է� : ";
	
	string str;

	cin.ignore(1, '\n');
	getline(cin, str);

	bool bCk = isPalindromeString(str);

	cout << "�� �Է��Ͻ� ���ڿ� " << str << "�� Palindrome ���ڿ��� " << (bCk == true ? "�½��ϴ�." : "�ƴմϴ�.") << endl;
}

void Menu::executeFIBONACCI() {
	int nMax = 0;

	cout << "\t�Ǻ���ġ �� ���ϱ� �Լ��� �����ϼ̽��ϴ�." << endl;
	cout << "�� ���ϰ��� �ϴ� �Ǻ���ġ �� ���� : ";
	cin >> nMax;

	int maxVal = getFibonacci(nMax);

	cout << "�� " << nMax << " ��°�� �Ǻ���ġ ���� " << maxVal << " �Դϴ�." << endl;
}

void Menu::executeFACTORIAL() {
	int nNum = 0;

	cout << "\t���丮�� ���ϱ� �Լ��� �����ϼ̽��ϴ�." << endl;
	cout << "�� ���ڸ� �Է����ּ��� : ";
	cin >> nNum;

	int nFact = getFactorial(nNum);

	cout << "�� !" << nNum << " : " << nFact << endl;
}

void Menu::executeGCD() {
	int nFirst = 0, nSecond = 0;

	cout << "\t�ִ����� ���ϱ� �Լ��� �����ϼ̽��ϴ�." << endl;
	cout << "�� �� ���� ���ڸ� �Է����ּ���." << endl;
	cout << "- ù ��° �� : ";
	cin >> nFirst;

	cout << "- �� ��° �� : ";
	cin >> nSecond;

	int nGcd = getGCD(nFirst, nSecond);

	cout << "�� " << nFirst << "�� " << nSecond << "�� �ִ������� " << nGcd << " �Դϴ�." << endl;
}