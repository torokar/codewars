#include <vector>
#include <iostream>
#include <thread>

/*В заданном массиве целых чисел найдите такое, которое встречается нечётное количество раз.

Всегда будет только одно целое число, которое появляется нечетное количество раз.

Примеры
[7] должен вернуться 7, потому что это происходит 1 раз (что странно).
[0] должен вернуться 0, потому что это происходит 1 раз (что странно).
[1,1,2] должен вернуться 2, потому что это происходит 1 раз (что странно).
[0,1,0,1,0] должен вернуться 0, потому что это происходит 3 раза (что странно).
[1,2,2,3,3,3,4,3,3,3,2,2,1] должен вернуться 4, потому что он появляется 1 раз (что странно).*/


//Создал еще один поток чтобы ускорить обработку ращделив на две части вектор
int theard_first(std::vector<int>& num)
{
	int count = 0;
	int number = 0;
	int right = num.size() - 1;
	int left = 0;
	int middle = num[left + (right - left) / 2];
	int size = num.size();
	//Планирую изменить потом на бинарный поиск 
	//пока так чтобы просто понять как работать с 2 потоками
	for (int i = middle; i < size; i++)
	{
		for (int q = 0; q < size; q++)
		{
			if (i == q)
			{
				continue;
			}
			if (num[i] == num[q])
			{
				++count;
				number = num[i];
			}
		}
		if (count % 2 == 0)
		{
			count = 0;
			number = 0;
		}
		else
		{
			break;
		}
	}
	return number;
}

int findOdd(const std::vector<int>& numbers) 
{
	std::vector<int> copy = numbers;
	int count = 0;
	int number = 0;
	int r = 0;
	int res_thread = 0;
	//Пытаюсь получить значения через лямбду функцию
	std::thread right_side([&res_thread, &copy]()mutable
		{
			res_thread = theard_first(copy);
		});
	return res_thread;
}


int main()
{
	setlocale(LC_ALL, "ru");
	std::vector<int> w = { 1,2,3,4,5 };
	findOdd(w);

	return 0;
}