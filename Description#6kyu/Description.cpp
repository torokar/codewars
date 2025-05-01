#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string likes(const std::vector<std::string>& names)
{

	if (names.empty())
	{
	std::string n = "no one likes this";
	return n;
	}
	
	if (names.size() == 1)
	{
		std::string people_one;
		people_one = names[0];
		std::string s;
		s = people_one + " likes this";

		return s;
	}

	if (names.size() == 2)
	{
		std::string people_one, people_two;
		people_one = names[0];
		people_two = names[1];
		std::cout << people_one << " and " << people_two << " likes this";
	}

	if (names.size() == 3)
	{
		std::string people_one, people_two, people_three;
		people_one = names[0];
		people_two = names[1];
		people_three = names[2];

		std::cout << people_one << ", " << people_two << " and "
			<< people_three << " like this";
	}

	if (names.size() >= 4)
	{
		for (auto a : names)
		{

		}
	}




}

int main()
{
	setlocale(LC_ALL, "ru");

	std::vector<std::string> names = {"Peter"};

	std::cout << likes(names);

	return 0;
}