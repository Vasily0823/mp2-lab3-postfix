//-
#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
	string infix; //обычная запись
	string postfix; //результат преобразований
public:
	TPostfix(string val) // конструктор
	{
		infix = val;
	}

	int Priority(char val)// функция преирететов
	{
		if ((val == '*') || (val == '/')) return 2;
		if ((val == '+') || (val == '-')) return 1;
		return -7;
	}
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	
	string ToPostfix();// перевод в постфикс
	double Calculate(); // вычислить переведенное выражение
};

#endif