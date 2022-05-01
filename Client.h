#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <windows.h>
#include <algorithm>
#include <fstream>

#define ROOT C:\\Acer\Documents

using std::string;

enum TypeCategory
{
	Food = 0,
	PublicService = 1,
	Rest = 2,
	Transport = 3,
	Health = 4,
	Clothes = 5,
	Other = 6
};

enum TypePrint
{
	Day = 0,
	Month = 1
};

enum TypeValuta
{
	Grivna = 0,
	Dollar = 1,
	Euro = 2
};

struct Event
{
	TypeCategory category;
	int sum;
	SYSTEMTIME st;
	Event(TypeCategory category, int sum);
	Event(TypeCategory category, int sum, SYSTEMTIME st);
};

class Expenses
{
	std::vector<Event> expenses;
public:
	void AddExpense(int sum, TypeCategory category);
	void PrintTop3CategoryOf(TypePrint typePrint);
	void PrintTop3SumOf(TypePrint typePrint);
	void PrintExpenseOf(TypePrint typePrint);
	friend class Client;
};


class Client
{
	string login;
	int password;
	string name;
	Expenses expenses;
public:
	Client(string login, int password, string name);
	void AddExpenses(int sum, TypeCategory category);
	bool ChangePassword(int password, int newPassword);
	void PrintTop3CategoryOf(TypePrint typePrint);
	void PrintTop3SumOf(TypePrint typePrint);
	void PrintExpenseOf(TypePrint typePrint);
};

void SaveExpensesToFile(Event& ev);

void LoadExpensesFromFile(std::vector<Event>& m);