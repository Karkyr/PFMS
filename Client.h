#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <windows.h>
#include <algorithm>

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
};

class Expenses
{
	std::vector<Event> expenses;
	int sumEpxenses;
public:
	void AddExpense(int sum, TypeCategory category);
	void PrintTop3CategoryOf(TypePrint typePrint);
	void PrintTop3SumOf(TypePrint typePrint);
	void PrintExpenseOf(TypePrint typePrint);
};

class Card
{
	int balance;
	short PIN;
	TypeValuta valuta;
	bool isBlocked;
	bool isCredit;
	Expenses expenses;
public:
	Card(short PIN, bool isCredit, TypeValuta valuta);
	void PrintCardInfo();
	void TopUp(int a);
	void PrintBalance();
	void ChangePIN(short newPIN);
	void BlockCard();
};

class Client
{
	string login;
	int password;
	string name;
	std::vector<Card> cards;
public:
	Client(string login, int password, string name);
	void CreateCard(short PIN, bool isCredit, TypeValuta valuta);
	bool ChangePassword(int password, int newPassword);
};



