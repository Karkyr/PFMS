#include "Client.h"

using std::cout;
using std::cin;
using std::endl;

Event::Event(TypeCategory category, int sum) :
	category{ category }, sum{ sum } {GetSystemTime(&st);}
Event::Event(TypeCategory category, int sum, SYSTEMTIME st) :
	category{ category }, sum{ sum }, st{ st }{}

void SaveExpensesToFile(Event& ev)
{
	std::ofstream fout;
	fout.open("log.dat", std::ios::binary | std::ios::app);
	fout << ev.category << " " << ev.sum << " " << ev.st.wDay << " " << ev.st.wMonth << " " << ev.st.wYear << " ";
	fout.close();
}

void LoadExpensesFromFile(std::vector<Event>& m)
{
	std::ifstream fin("log.dat", std::ios::binary);
	int category;
	int sum;
	SYSTEMTIME st;
	int i = 0;
	while (fin >> category >> sum >> st.wDay >> st.wMonth >> st.wYear)
	{
		m.push_back(Event(TypeCategory(category), sum, st));
	}
	fin.close();
}

void Client::AddExpenses(int sum, TypeCategory category)
{
	expenses.AddExpense(sum, category);
}

Client::Client(string login, int password, string name)
{
	this->login = login;
	this->password = password;
	this->name = name;
	LoadExpensesFromFile(expenses.expenses);
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

void Client::PrintTop3CategoryOf(TypePrint typePrint)
{
	expenses.PrintTop3CategoryOf(typePrint);
}

void Client::PrintTop3SumOf(TypePrint typePrint)
{
	expenses.PrintTop3SumOf(typePrint);
}

void Client::PrintExpenseOf(TypePrint typePrint)
{
	expenses.PrintExpenseOf(typePrint);
}

void Expenses::AddExpense(int sum, TypeCategory category)
{
	Event a(category, sum);
	expenses.push_back(a);
	SaveExpensesToFile(a);
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
				expenses[i].st.wYear != now.wYear) {continue;}
		}
		else if (typePrint == Month)
		{
			if (expenses[i].st.wMonth != now.wMonth ||
				expenses[i].st.wYear != now.wYear) {continue;}
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
	std::vector<std::pair<int, TypeCategory>> m;
	m.push_back(std::pair<int, TypeCategory>(food, Food));
	m.push_back(std::pair<int, TypeCategory>(publicService, PublicService));
	m.push_back(std::pair<int, TypeCategory>(rest, Rest));
	m.push_back(std::pair<int, TypeCategory>(transport, Transport));
	m.push_back(std::pair<int, TypeCategory>(health, Health));
	m.push_back(std::pair<int, TypeCategory>(clothes, Clothes));
	m.push_back(std::pair<int, TypeCategory>(other, Other));

	std::sort(m.begin(), m.end());
	buff1 = m[m.size() - 1].second;
	buff2 = m[m.size() - 2].second;
	buff3 = m[m.size() - 3].second;

	cout << "��� 3 ��������� �������: ";
	switch (buff1)
	{
	case Food:
		cout << "��� | ";
		break;
	case PublicService:
		cout << "���������� ������� | ";
		break;
	case Rest:
		cout << "³�������� | ";
		break;
	case Transport:
		cout << "��������� | ";
		break;
	case Health:
		cout << "�������� �� ����� | ";
		break;
	case Clothes:
		cout << "���� | ";
		break;
	case Other:
		cout << "���� | ";
		break;
	default:
		break;
	}
	switch (buff2)
	{
	case Food:
		cout << "��� | ";
		break;
	case PublicService:
		cout << "���������� ������� | ";
		break;
	case Rest:
		cout << "³�������� | ";
		break;
	case Transport:
		cout << "��������� | ";
		break;
	case Health:
		cout << "�������� �� ����� | ";
		break;
	case Clothes:
		cout << "���� | ";
		break;
	case Other:
		cout << "���� | ";
		break;
	default:
		break;
	}
	switch (buff3)
	{
	case Food:
		cout << "���" << endl;
		break;
	case PublicService:
		cout << "���������� �������" << endl;
		break;
	case Rest:
		cout << "³��������" << endl;
		break;
	case Transport:
		cout << "���������" << endl;
		break;
	case Health:
		cout << "�������� �� �����" << endl;
		break;
	case Clothes:
		cout << "����" << endl;
		break;
	case Other:
		cout << "����" << endl;
		break;
	default:
		break;
	}

}

void Expenses::PrintTop3SumOf(TypePrint typePrint)
{
	SYSTEMTIME now;
	GetSystemTime(&now);
	int buff1 = expenses[0].sum, buff2 = expenses[0].sum, buff3 = expenses[0].sum;
	for (int i = 0; i < expenses.size(); i++)
	{
		if (typePrint == Day)
		{
			if (expenses[i].st.wDay != now.wDay ||
				expenses[i].st.wMonth != now.wMonth ||
				expenses[i].st.wYear != now.wYear) {
				continue;
			}
		}
		else if (typePrint == Month)
		{
			if (expenses[i].st.wMonth != now.wMonth ||
				expenses[i].st.wYear != now.wYear) {
				continue;
			}
		}
		if (expenses[i].sum > buff1)
		{
			if (buff1 > buff2)
			{
				buff2 = buff1;
			}
			buff1 = expenses[i].sum;
		}
		else if (expenses[i].sum > buff2)
		{
			if (buff2 > buff3)
			{
				buff3 = buff2;
			}
			buff2 = expenses[i].sum;
		}
		else if (expenses[i].sum > buff3)
		{
			buff3 = expenses[i].sum;
		}
	}
	cout << "��� 3 ����� ����: ";
	cout << buff1 << " | " << buff2 << " | " << buff3 << " | " << endl;
}

void Expenses::PrintExpenseOf(TypePrint typePrint)
{
	SYSTEMTIME now;
	GetSystemTime(&now);
	for (int i = 0; i < expenses.size(); i++)
	{
		if (typePrint == Day)
		{
			if (expenses[i].st.wDay != now.wDay ||
				expenses[i].st.wMonth != now.wMonth ||
				expenses[i].st.wYear != now.wYear) {
				continue;
			}
		}
		else if (typePrint == Month)
		{
			if (expenses[i].st.wMonth != now.wMonth ||
				expenses[i].st.wYear != now.wYear) {
				continue;
			}
		}
		switch (expenses[i].category)
		{
		case Food:
			cout << "��� | ";
			break;
		case PublicService:
			cout << "���������� ������� | ";
			break;
		case Rest:
			cout << "³�������� | ";
			break;
		case Transport:
			cout << "��������� | ";
			break;
		case Health:
			cout << "�������� �� ����� | ";
			break;
		case Clothes:
			cout << "���� | ";
			break;
		case Other:
			cout << "���� | ";
			break;
		default:
			break;
		}
		cout << expenses[i].sum << endl;
	}
}
