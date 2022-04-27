#include "Client.h"

using std::cout;
using std::cin;
using std::endl;

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

Card::Card(short PIN, bool isCredit) : PIN{ PIN }, isCredit{ isCredit }, isBlocked{ false }, balance{ 0 }{};

void Card::PrintCardInfo()
{
	cout << "Balance : " << balance << endl;
	cout << "Blocking : " << isBlocked ? cout << "Yes" : cout << "No" << endl;
	cout << "Credit : " << isCredit ? cout << "Yes" : cout << "No" << endl;
}

void Card::TopUp(int a)
{
	balance += a;
}

void Card::PrintBalance()
{
	cout << "Balance : " << balance << endl;
}

void Card::ChangePIN(short newPIN)
{
	PIN = newPIN;
}

void Card::BlockCard()
{
	string a;
	
	cout << "You are sure what you want to block the card" << endl
		<< "Y(yes) / N(no)";
	do
	{
		cin >> a;
	} while (a != "Y" || a != "yes" || a != "no" || a != "N");
	if (a == "Y" || a == "yes")
	{
		isBlocked = true;
		cout << "Thats your unique code : " << rand() % 99999 + 10000 << endl;
		cout << "!!!Please remember this code," 
			<< " you will need this code if you want to unlock the card!!!" << endl;
	}	
	else
	{
		return;
	}
}

void Expenses::AddExpense(int sum, TypeCategory category)
{
	std::pair<TypeCategory, int> a(category, sum);
	expenses.push_back(a);
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
