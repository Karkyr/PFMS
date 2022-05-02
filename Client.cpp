#include "Client.h"

using std::cout;
using std::cin;
using std::endl;

Event::Event(TypeCategory category, int sum) :
	category{ category }, sum{ sum } {GetSystemTime(&st);}
Event::Event(TypeCategory category, int sum, SYSTEMTIME st) :
	category{ category }, sum{ sum }, st{ st }{}

bool IsPathExist(const std::string& s)
{
	struct stat buffer;
	return (stat(s.c_str(), &buffer) == 0);
}

Client SignInAccount(string login, int password, string name)
{
	std::ifstream fin("accounts.dat", std::ios::binary);
	string _login, _name, _path;
	int _password;
	while (fin >> _login >> _password >> _name >> _path)
	{
		if (login == _login && _password == password && _name == name)
		{
			fin.close();
			Client c(login, password, name);
			return c;
		}
	}
	Client a(0,0,0);
	return a;
}

Client CreateAccount(string login, int password, string name)
{
	std::ofstream fout;
	if (!(IsPathExist(R"(Expenses\)")))
	{
		_mkdir(R"(Expenses\)");
	}
	string path = R"(Expenses\)" + name;
	fout.open("accounts.dat", std::ios::binary | std::ios::app);
	fout << login << " " << password << " " << name << " " << path << " ";
	fout.close();
	Client client(login, password, name);
	return client;
}

void SaveExpensesToFile(Event& ev, string path)
{
	std::ofstream fout;
	fout.open(path, std::ios::binary | std::ios::app);
	fout << ev.category << " " << ev.sum << " " << ev.st.wDay << " " << ev.st.wMonth << " " << ev.st.wYear << " ";
	fout.close();
}

void LoadExpensesFromFile(std::vector<Event>& m, string path)
{
	std::ifstream fin(path, std::ios::binary);
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

void Client::SetLogin(string login) { this->login = login; }

void Client::SetPassword(int password) { this->password = password; }

void Client::SetName(string name) { this->name = name; }

string Client::GetName() { return name; }

std::vector<Event>& Client::GetExpenses()
{
	return expenses.expenses;
}

void Client::AddExpenses(int sum, TypeCategory category)
{
	string path = R"(Expenses\)" + name + ".dat";
	expenses.AddExpense(sum, category, path);
}

Client::Client(string login, int password, string name)
{
	this->login = login;
	this->password = password;
	this->name = name;
	string path = R"(Expenses\)" + name + ".dat";
	LoadExpensesFromFile(expenses.expenses, path);
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

void Client::PrintExpensesOf(TypePrint typePrint)
{
	expenses.PrintExpenseOf(typePrint);
}

void Expenses::AddExpense(int sum, TypeCategory category, string path)
{
	Event a(category, sum);
	expenses.push_back(a);
	SaveExpensesToFile(a, path);
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

	cout << "Топ 3 популярні категорії: ";
	switch (buff1)
	{
	case Food:
		cout << "Їжа | ";
		break;
	case PublicService:
		cout << "Комунальні послуги | ";
		break;
	case Rest:
		cout << "Відпочинок | ";
		break;
	case Transport:
		cout << "Транспорт | ";
		break;
	case Health:
		cout << "Здоровья та краса | ";
		break;
	case Clothes:
		cout << "Одяг | ";
		break;
	case Other:
		cout << "Інше | ";
		break;
	default:
		break;
	}
	switch (buff2)
	{
	case Food:
		cout << "Їжа | ";
		break;
	case PublicService:
		cout << "Комунальні послуги | ";
		break;
	case Rest:
		cout << "Відпочинок | ";
		break;
	case Transport:
		cout << "Транспорт | ";
		break;
	case Health:
		cout << "Здоровья та краса | ";
		break;
	case Clothes:
		cout << "Одяг | ";
		break;
	case Other:
		cout << "Інше | ";
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
		cout << "Комунальні послуги" << endl;
		break;
	case Rest:
		cout << "Відпочинок" << endl;
		break;
	case Transport:
		cout << "Транспорт" << endl;
		break;
	case Health:
		cout << "Здоровья та краса" << endl;
		break;
	case Clothes:
		cout << "Одяг" << endl;
		break;
	case Other:
		cout << "Інше" << endl;
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
	cout << "Топ 3 великі суми: ";
	cout << buff1 << " | " << buff2 << " | " << buff3 << endl;
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
			cout << "Їжа | ";
			break;
		case PublicService:
			cout << "Комунальні послуги | ";
			break;
		case Rest:
			cout << "Відпочинок | ";
			break;
		case Transport:
			cout << "Транспорт | ";
			break;
		case Health:
			cout << "Здоровья та краса | ";
			break;
		case Clothes:
			cout << "Одяг | ";
			break;
		case Other:
			cout << "Інше | ";
			break;
		default:
			break;
		}
		cout << expenses[i].sum << endl;
	}
}
