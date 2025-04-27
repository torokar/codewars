#include <iostream>

std::string spinWords(const std::string& str)
{
	std::string _New_str = str;
	char ch[255];
	int i = 0;
	int size = _New_str.size();

	while (i < size)
	{
		ch[i] = _New_str[i];
		//if (ch[i] == ' ') { break; }
		++i;
	}
	int k = 0;
	std::string merger_char = "";
	std::string resers = "";

	//Это основной цикл который должен перебрать все слово
	while (true)
	{

		while (true)
		{
			if (ch[k] == ' ')
			{
				continue; //Это я не протестировал не знаю как сработает 
			}
			merger_char += ch[k]; //строка принимает из массива по идеи она должна принить до пробела не знаю почему он светиться зеленным 

			if (ch[k] == ' ') //если массив доходит до пробела выхожим
			{
				break;
			}
			++k;
		}
		if (merger_char.size() >= 5)
		{
			//Реверс строки 
			for (int i = merger_char.size() - 1; i >= 0; --i)
			{
				resers += ch[i];
			}
		}
		//слияние строк 
		else
		{
			resers += merger_char;
		}
		std::cout << resers;
		//Условия выхода из цикла основного 
		if (k >= size)
		{
			break;
		}
	}

	//while (true)
	//{
	//	int j = 0;


	//	_New_str = "";
	//	for (int i = merger_char.size(); i >= 0; i++)
	//	{
	//		_New_str[i] += merger_char[i];
	//	}
	//	std::cout << _New_str;
	//}

	for (int k = 0; k <= 5; k++)
		merger_char += ch[k];


	if (merger_char.size() >= 5)
	{
		for (int i = merger_char.size(); i >= 0; --i)
		{
			std::cout << merger_char[i];
		}
	}


	return str;
}

int main()
{
	setlocale(LC_ALL, "ru");


	spinWords("Hello worl");

	return 0;
}