#include <iostream>
#include <ctime>
#include <Windows.h>
#include "Client.h"

using std::cout;
using std::cin;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Ukrainian");
	int a;
	Client ac("vasya232", 1111, "Bogdan");
	ac.PrintTop3CategoryOf(Month);
	ac.PrintTop3SumOf(Month);
	ac.
}