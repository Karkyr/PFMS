#include "Client.h"

using std::cout;
using std::cin;

Client::Client(string login, int password, string name)
{
	this->login = login;
	this->password = password;
	this->name = name;
}

void Client::CreateCard(short PIN, bool isCredit)
{
	cards.push_back(Card(PIN, isCredit));
}

void Client::SetPassword(int password)
{
	this->password = password;
}

Card::Card(short PIN, bool isCredit) : PIN{ PIN }, isCredit{ isCredit }, isBlocked{ false }, countMoney{ 0 }{};

void Card::PrintCardInfo()
{
	cout << "Balance : " << countMoney;
}

void Card::TopUp(int a)
{
}

void Card::Withdraw(int a)
{
}

void Card::PrintBalance()
{
}

void Card::ChangePIN(short newPIN)
{
}

void Expenses::AddExpense(int sum, TypeCategory category)
{
}

void Expenses::PrintTop3CategoryOf(TypePrint typePrint)
{
}

void Expenses::PrintTop3SumOf(TypePrint typePrint)
{
}

void Expenses::PrintExpenseOf(TypePrint typePrint)
{
}
