// Proyecto1CallbacksSO1.cpp : Defines the entry point for the console application.
//
//

#include "stdafx.h"
#include <iostream>


static int function(int param)
{
	printf("CallBack: Funcion definida como estatica para todo el programa.\n");
	printf(" |PARAMETRO: %d | \n", param);
	printf(" |FUNCION:   1 | \n\n");
	return 1;
}


//Clase A
class ClaseA
{
public:
	static int function1(int param);
};

//Clase B
class ClaseB
{
public:
	static void setCallBack(int (ClaseB::*&cb)(int));
private:
	int function2(int param);
};



int ClaseA::function1(int param)
{
	printf("CallBack: Funcion definida como estatica de la Clase A.\n");
	printf(" |PARAMETRO: %d | \n", param);
	printf(" |FUNCION:   2 | \n\n");
	return 2;
}


int ClaseB::function2(int param)
{
	printf("CallBack: Funcion definida como privada de la Clase B.\n");
	printf(" |PARAMETRO: %d | \n", param);
	printf(" |FUNCION:   3 | \n\n");
	return 3;
}

void ClaseB::setCallBack(int (ClaseB::*&cb)(int))
{
	cb = &ClaseB::function2;
}

int main()
{
	printf("                                         CALLBACKS\n\n\n\n");

	int(*callback1)(int) = &function;
	int(*callback2)(int) = &ClaseA::function1;
	ClaseB *obj = new ClaseB();
	int (ClaseB::*callback3)(int);
	ClaseB::setCallBack(callback3);
	callback1(1);
	callback2(2);
	(obj->*callback3)(3);
	system("pause");
	return 0;

}
