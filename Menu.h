#pragma once
#ifndef _MENU_H
#define _MENU_H

#include <iostream>
using namespace std;

class Menu {
private :
	enum MENU_CL {MENU_LIST, STR_REV, STR_SWAP, ARMSTRONG, PRIME, PERFECT_NUM, PALINDROME_NUM, PALINDROME_STR, FIBONACCI, FACTORIAL, GCD};
	MENU_CL m_menu;
	
public :
	Menu() {
		m_menu = MENU_LIST;
		printMenuList();
		selectMenu();
	}

	void printMenuList();
	int getMenu() const;
	void setMenu(MENU_CL menu_cl);
	void selectMenu();

private :
	void executeAlgorithm(MENU_CL menu);
	void executeSTRREV();
	void executeSTRSWAP();
	void executeARMSTRONG();
	void executePRIME();
	void executePALINDROME();
	void executePERFECT_NUM();
	void executePALINDROME_STR();
	void executeFIBONACCI();
	void executeFACTORIAL();
	void executeGCD();
};

#endif
