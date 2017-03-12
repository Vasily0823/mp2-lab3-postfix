//---
#ifndef __STACK_H__
#define __STACK_H__
#include <cstddef>

const int MaxSize = 100;
template <class T> // тип Т
class TStack
{
protected:
	T *pMem; 
	int size;// размер стека
	int count;//вершина стека
public:
	TStack(int = 10); // конструктор
	~TStack(); // деструктор
	bool IsEmpty(); // пуст ли стек
	bool IsFull(); // полон ли стек
	void Push(const T &val);//add
	T Pop();//показать и удалить
	T Top();//view
};
//-----------------------------------


template <class T>
TStack<T>::TStack(int len) {  // конструктор
	if ((len<1) || (len>MaxSize)) throw (len);// может ли стек быть такого размера
	size = len;
	count = 0;
	pMem = new T[size];// pMem[0] and pMem[1]
}



template <class T>// деструктор
TStack<T>::~TStack() {
	delete[]pMem;
	pMem = NULL;
}

template <class T> // пуст ли стек
bool TStack<T>::IsEmpty() {
	return(count == 0);
}

template <class T> // полон ли стек
bool TStack<T>::IsFull() {
	return (count == size);
}

template <class T> // добавить 
void TStack<T>::Push(const T &val) {
	if (IsFull())  throw (count); // исключение
	pMem[count] = val;
	count++;
}

template <class T> //достать
T TStack<T>::Pop() {
	if (IsEmpty()) throw (count); //пуст ли - исключение
	count--;
	return pMem[count];
}

template <class T>
T TStack<T>::Top() {
	if (IsEmpty()) throw (count);
	return pMem[count - 1];
}
#endif