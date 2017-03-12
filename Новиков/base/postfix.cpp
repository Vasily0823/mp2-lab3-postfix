//-
#include "postfix.h"
#include "stack.h"
#include <iostream>
#include <cctype>   // для функции isdigit (проверяет, принята ли десятичная цифра)
#include <cstdlib>  // для функции atoi (преобразовать символы к типу int)
using namespace std;


string TPostfix::ToPostfix()
{
	char result[MaxSize];//массив результатов
	int result_pos=0; //позиция элемента в стеке
	TStack<char> stack_op(MaxSize); // создание объекта стека

	for (int i = 0; i < infix.length()-1; i++)
	{
		if ((infix[i] == '/') && (infix[i + 1] == '0'))
		{
			throw (infix);
		}
	}

	for ( int i = 0; i < infix.length(); i++)
	{
		
		if ((infix[i] != '(') && (infix[i] != ')') && (infix[i] != '+') && (infix[i] != '-') && (infix[i] != '*') && (infix[i] != '/'))
		{
			result[result_pos] = infix[i]; //строку result
			result_pos++;
			result[result_pos] = '\0';
		}//проверяет поступила ли на вход знак или цифра, в случае цифры записывает ее в result.

		
		if (infix[i] == '(') stack_op.Push(infix[i]);//помещает ( в стек операций
		                                          
		if (infix[i] == ')') //если поступила закрывающая скобка
		{
			while (stack_op.Top() != '(')//пока на вершине стека нет открывающейся скобки
			{
				result[result_pos] = stack_op.Pop();//извлекает элементы из стека операций в строку result
				result_pos++;// увеличивает позицию
				result[result_pos] = '\0';// символ вершины стека.
			}
			stack_op.Pop();//удаляет из стека откр. скобку.
		}
		
		//правила арифметики ----
		if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/'))//проверяем на сиволы, кроме скобок входные данные.
		{
		
			if 
				(stack_op.IsEmpty() || stack_op.Top() == '(') stack_op.Push(infix[i]);//если в стеке нет операций или верхним элементом стека является открывающая скобка, операции кладётся в стек;	

			//Пока поступившая операция имеет меньший приоритет, чем верхняя в стеке и онне пуст. 
			//Нижнии выписываются из стека, поступившая - записывается.
			//Записывает операцию в стек.
			else
			{
				while (!stack_op.IsEmpty() && Priority(infix[i]) <= Priority(stack_op.Top()))
				{
					result[result_pos] = stack_op.Pop();
					result_pos++;
					result[result_pos] = '\0';
				}
				stack_op.Push(infix[i]);

			}
		}
		//правила арифметики ^^^

	}

	// когда кончилась запись, все операции из стека переписать в результат
	while (stack_op.IsEmpty() == 0)//пока
	{
		result[result_pos] = stack_op.Pop();
		result_pos++;
		result[result_pos] = '\0';
	}
	//-----
	postfix = result;
	return postfix;
}


double TPostfix::Calculate()
{
	double Digits[MaxSize]; //используется для обозначения переменных
	double a,b; // операнды.
	char tmp[3];//псевдо-стек, для atoi.

	TStack<double> stack(MaxSize);// создали стек размером макссаайз, элементы которого типа дабл
	for (int i = 0; i < postfix.length(); i++)// посимвольно перебираем запись постфикс
	{
		
		//Если на вход подана константа, она помещается на вершину стека.
		if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/')
		{

				tmp[0] = postfix[i];
				tmp[1] = '\0';
				if ( isdigit(tmp[0]) ) 
					Digits[i] = atoi(tmp); // преобразовать символы к типу int
				else//присвоить значения с клавиатуры
				{
				cout << postfix[i] << "=";
				cin >> Digits[i];
				}
				stack.Push(Digits[i]);
		}
		
		else
		{
			if (postfix[i] == '+')
			{
				a = stack.Pop();
				b = stack.Pop();
				stack.Push(b + a);
			}
			if (postfix[i] == '-')
			{
				a = stack.Pop();
				b = stack.Pop();
				stack.Push(b - a);
			}
			if (postfix[i] == '/')
			{
				a = stack.Pop();
					b = stack.Pop();
					stack.Push(b / a);	
			}
			if (postfix[i] == '*')
			{
				a = stack.Pop();
				b = stack.Pop();
				stack.Push(b * a);
			}
		}

	}

	return stack.Pop();
}