#include "Client.h"

using std::cout;
using std::cin;
using std::endl;

Event::Event(TypeCategory category, int sum) :
	category{ category }, sum{ sum } {GetSystemTime(&st);}

Client::Client(string login, int password, string name)
{
	this->login = login;
	this->password = password;
	this->name = name;
}

void Client::CreateCard(short PIN, bool isCredit, TypeValuta valuta)
{
	cards.push_back(Card(PIN, isCredit, valuta));
}

bool Client::ChangePassword(int password, int newPassword)
{
	if (this->password == password)
	{
		this->password = newPassword;
		return true;
	}
	return false;
}

Card::Card(short PIN, bool isCredit, TypeValuta valuta)
	: PIN{ PIN }, isCredit{ isCredit }, valuta{valuta}, isBlocked{false}, balance{0}{};

void Card::PrintCardInfo()
{
	cout << "Balance : " << balance << endl;
	cout << "Valuta : ";
	switch (valuta)
	{
	case Grivna:
		cout << "Grivna" << endl;
		break;
	case Dollar:
		cout << "Dollar" << endl;
		break;
	case Euro:
		cout << "Euro" << endl;
		break;
	default:
		break;
	}
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
	Event a(category, sum);
	expenses.push_back(a);
}

void Expenses::PrintTop3CategoryOf(TypePrint typePrint)
{
	int food = 0, publicService = 0, rest = 0,
		transport = 0, health = 0, clothes = 0, other = 0;
	SYSTEMTIME now;
	GetSystemTime(&now);
	for (int i = 0; i < expenses.size(); i++)
	{
		if (typePrint == Day)
		{
			if (expenses[i].st.wDay != now.wDay ||
				expenses[i].st.wMonth != now.wMonth ||
				expenses[i].st.wYear != now.wYear) {return;}
		}
		else if (typePrint == Month)
		{
			if (expenses[i].st.wMonth != now.wMonth ||
				expenses[i].st.wYear != now.wYear) {return;}
		}
		switch (expenses[i].category)
		{
		case Food:
			food++;
			break;
		case PublicService:
			publicService++;
			break;
		case Rest:
			rest++;
			break;
		case Transport:
			transport++;
			break;
		case Health:
			health++;
			break;
		case Clothes:
			clothes++;
			break;
		case Other:
			other++;
			break;
		default:
			break;
		}
	}
	TypeCategory buff1, buff2, buff3;
	std::vector<std::pair<TypeCategory, int>> m;
	m.push_back(std::pair<TypeCategory, int>(Food, food));
	m.push_back(std::pair<TypeCategory, int>(PublicService, publicService));
	m.push_back(std::pair<TypeCategory, int>(Rest, rest));
	m.push_back(std::pair<TypeCategory, int>(Transport, transport));
	m.push_back(std::pair<TypeCategory, int>(Health, health));
	m.push_back(std::pair<TypeCategory, int>(Clothes, clothes));
	m.push_back(std::pair<TypeCategory, int>(Other, other));

	std::sort(m.begin(), m.end());
	buff1 = m[m.size() - 1].first;
	buff2 = m[m.size() - 2].first;
	buff3 = m[m.size() - 3].first;

	cout << "Топ 3 популярні категорії: ";
	switch (buff1)
	{
	case Food:
		cout << "Їжа |";
		break;
	case PublicService:
		cout << "Комунальні послуги |";
		break;
	case Rest:
		cout << "Відпочинок |";
		break;
	case Transport:
		cout << "Транспорт |";
		break;
	case Health:
		cout << "Здоровья та краса |";
		break;
	case Clothes:
		cout << "Одяг |";
		break;
	case Other:
		cout << "Інше |";
		break;
	default:
		break;
	}
	switch (buff2)
	{
	case Food:
		cout << "Їжа |";
		break;
	case PublicService:
		cout << "Комунальні послуги |";
		break;
	case Rest:
		cout << "Відпочинок |";
		break;
	case Transport:
		cout << "Транспорт |";
		break;
	case Health:
		cout << "Здоровья та краса |";
		break;
	case Clothes:
		cout << "Одяг |";
		break;
	case Other:
		cout << "Інше |";
		break;
	default:
		break;
	}
	switch (buff3)
	{
	case Food:
		cout << "Їжа" << endl;
		break;
	case PublicService:
		cout << "Комунальні послуги |" << endl;
		break;
	case Rest:
		cout << "Відпочинок |" << endl;
		break;
	case Transport:
		cout << "Транспорт |" << endl;
		break;
	case Health:
		cout << "Здоровья та краса |" << endl;
		break;
	case Clothes:
		cout << "Одяг |" << endl;
		break;
	case Other:
		cout << "Інше |" << endl;
		break;
	default:
		break;
	}

}

void Expenses::PrintTop3SumOf(TypePrint typePrint)
{

}

void Expenses::PrintExpenseOf(TypePrint typePrint)
{

}
