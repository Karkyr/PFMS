#pragma once
#include <iostream>
#include <map>
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

class Client
{

};

class Card
{
	int countMoney;
	short PIN;
	bool isBlocked;
	bool isCredit;
	Expenses expenses;
public:
	Card(short PIN, bool isCredit);
	void PrintCardInfo();
	void TopUp(int a);
	void Withdraw(int a);
	void PrintMoney();
	void ChangePIN(short newPIN);
};

class Expenses
{
	std::map<TypeCategory, int> expenses;
	/*std::map<TypeCategory, int> top3Category;
	std::map<TypeCategory, int> top3Sum;*/
	int sumEpxenses;

	void AddExpense(int sum, TypeCategory category);
	void PrintTop3Category();
	void PrintTop3Sum();
};