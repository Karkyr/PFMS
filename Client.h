#pragma once

#include <iostream>
#include <map>
#include <vector>

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
	day = 0,
	week = 1,
	month = 2
};

class Expenses
{
	std::vector<std::pair<TypeCategory, int>> expenses;
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
	bool isBlocked;
	bool isCredit;
	Expenses expenses;
public:
	Card(short PIN, bool isCredit);
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
	void CreateCard(short PIN, bool isCredit);
	void SetPassword(int password);
};



