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
		cout << "0 - Вихід\n1 - Зареєструватися\n2 - Війти\n";
		cin >> a;
		if (a == 1)
		{
			cout << "Введіть логін : ";
			cin >> login;
			cout << "Увага!!! Пароль має складатися тільки з цифр\n";
			cout << "Введіть пароль : ";
			cin >> password;
			cout << "Введіть ваше ім'я : ";
			cin >> name;
			Client client(CreateAccount(login, password, name));
			do
			{
				cout << " 1 - Додати витрати \n 2 - Показати 3 частіші категорії вітрат за \n"
					<< " 3 - Показати 3 самі великі витрати за \n 4 - Показати витрати за \n 0 - Вихід \n";
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
					cout << "0 - Їжа | 1 - Комунальні послуги | 2 - Відпочинок | 3 - Транспорт"
						<< " | 4 - Здоров'я та краса | 5 - Одяг | 6 - Інше\n";
					do
					{
						cin >> category;
					} while (a < 0 && a > 6);
					cout << "Введіть суму : ";
					cin >> sum;
					client.AddExpenses(sum, TypeCategory(category));
					break;
				case 2:
					cout << "0 - День, 1 - Місяць\n";
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
					cout << "0 - День, 1 - Місяць\n";
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
					cout << "0 - День, 1 - Місяць\n";
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
			cout << "Введіть логін : ";
			cin >> login;
			cout << "Увага!!! Пароль має складатися тільки з цифр\n";
			cout << "Введіть пароль : ";
			cin >> password;
			cout << "Введіть ваше ім'я : ";
			cin >> name;
			Client client(SignInAccount(login, password, name));
			do
			{
				cout << " 1 - Додати витрати \n 2 - Показати 3 частіші категорії вітрат за \n" 
					<< " 3 - Показати 3 самі великі витрати за \n 4 - Показати витрати за \n 0 - Вихід \n";
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
					cout << "0 - Їжа | 1 - Комунальні послуги | 2 - Відпочинок | 3 - Транспорт"
						<< " | 4 - Здоров'я та краса | 5 - Одяг | 6 - Інше\n";
					do
					{
						cin >> category;
					} while (a < 0 && a > 6);
					cout << "Введіть суму : ";
					cin >> sum;
					client.AddExpenses(sum, TypeCategory(category));
					break;
				case 2:
					cout << "0 - День, 1 - Місяць\n";
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
					cout << "0 - День, 1 - Місяць\n";
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
					cout << "0 - День, 1 - Місяць\n";
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