#pragma once

#ifndef _STRINGALGORITHM_H
#define _STRINGALGORITHM_H

#include <string>
using namespace std;

void reverse_string(char*);
void swap_string(char*, unsigned int, char*, unsigned int);
bool isPalindromeString(string str);

// template swap ÇÔ¼ö
template <typename T>
void swap(T* a, T* b) {
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

#endif