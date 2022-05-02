#include <iostream>
#include <ctime>
#include <Windows.h>
#include "Client.h"

using std::cout;
using std::cin;

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a;
	string login, name;
	int password;
	do
	{
		cout << "0 - �����\n1 - ��������������\n2 - ³���\n";
		cin >> a;
		if (a == 1)
		{
			cout << "������ ���� : ";
			cin >> login;
			cout << "�����!!! ������ �� ���������� ����� � ����\n";
			cout << "������ ������ : ";
			cin >> password;
			cout << "������ ���� ��'� : ";
			cin >> name;
			Client client(CreateAccount(login, password, name));
			do
			{
				cout << " 1 - ������ ������� \n 2 - �������� 3 ������ ������� ����� �� \n"
					<< " 3 - �������� 3 ��� ����� ������� �� \n 4 - �������� ������� �� \n 0 - ����� \n";
				do
				{
					cin >> a;
				} while (a < 0 && a > 4);
				switch (a)
				{
				case 0:
					return EXIT_SUCCESS;
					break;
				case 1:
					int sum, category;
					cout << "0 - ��� | 1 - ��������� ������� | 2 - ³�������� | 3 - ���������"
						<< " | 4 - ������'� �� ����� | 5 - ���� | 6 - ����\n";
					do
					{
						cin >> category;
					} while (a < 0 && a > 6);
					cout << "������ ���� : ";
					cin >> sum;
					client.AddExpenses(sum, TypeCategory(category));
					break;
				case 2:
					cout << "0 - ����, 1 - ̳����\n";
					do
					{
						cin >> a;
					} while (a < 0 && a > 1);
					if (a == 0)
					{
						client.PrintTop3CategoryOf(Day);
					}
					else if (a == 1)
					{
						client.PrintTop3CategoryOf(Month);
					}
					break;
				case 3:
					cout << "0 - ����, 1 - ̳����\n";
					do
					{
						cin >> a;
					} while (a < 0 && a > 1);
					if (a == 0)
					{
						client.PrintTop3SumOf(Day);
					}
					else if (a == 1)
					{
						client.PrintTop3SumOf(Month);
					}
					break;
				case 4:
					cout << "0 - ����, 1 - ̳����\n";
					do
					{
						cin >> a;
					} while (a < 0 && a > 1);
					if (a == 0)
					{
						client.PrintExpensesOf(Day);
					}
					else if (a == 1)
					{
						client.PrintExpensesOf(Month);
					}
					break;
				}
			} while (true);
		}
		else if(a == 2)
		{
			cout << "������ ���� : ";
			cin >> login;
			cout << "�����!!! ������ �� ���������� ����� � ����\n";
			cout << "������ ������ : ";
			cin >> password;
			cout << "������ ���� ��'� : ";
			cin >> name;
			Client client(SignInAccount(login, password, name));
			do
			{
				cout << " 1 - ������ ������� \n 2 - �������� 3 ������ ������� ����� �� \n" 
					<< " 3 - �������� 3 ��� ����� ������� �� \n 4 - �������� ������� �� \n 0 - ����� \n";
				do
				{
					cin >> a;
				} while (a < 0 && a > 4);
				switch (a)
				{
				case 0:
					return EXIT_SUCCESS;
					break;
				case 1:
					int sum, category;
					cout << "0 - ��� | 1 - ��������� ������� | 2 - ³�������� | 3 - ���������"
						<< " | 4 - ������'� �� ����� | 5 - ���� | 6 - ����\n";
					do
					{
						cin >> category;
					} while (a < 0 && a > 6);
					cout << "������ ���� : ";
					cin >> sum;
					client.AddExpenses(sum, TypeCategory(category));
					break;
				case 2:
					cout << "0 - ����, 1 - ̳����\n";
					do
					{
						cin >> a;
					} while (a < 0 && a > 1);
					if (a == 0)
					{
						client.PrintTop3CategoryOf(Day);
					}
					else if(a == 1)
					{
						client.PrintTop3CategoryOf(Month);
					}
					break;
				case 3:
					cout << "0 - ����, 1 - ̳����\n";
					do
					{
						cin >> a;
					} while (a < 0 && a > 1);
					if (a == 0)
					{
						client.PrintTop3SumOf(Day);
					}
					else if (a == 1)
					{
						client.PrintTop3SumOf(Month);
					}
					break;
				case 4:
					cout << "0 - ����, 1 - ̳����\n";
					do
					{
						cin >> a;
					} while (a < 0 && a > 1);
					if (a == 0)
					{
						client.PrintExpensesOf(Day);
					}
					else if (a == 1)
					{
						client.PrintExpensesOf(Month);
					}
					break;
				}
			} while (true);
		}
		else if (a == 0)
		{
			return EXIT_SUCCESS;
		}
	} while (true);

	return EXIT_SUCCESS;
}