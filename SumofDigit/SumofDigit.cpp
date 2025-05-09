#include <iostream>
#include <string>
#include <vector>

int digital_root(int n)
{
	if (n < 10)
	{
		return n;
	}
	std::string s = std::to_string(n);
	s += '\0';

	std::vector<std::string> v;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '\0')
		{
			break;
		}
		std::string tmp;
		tmp = s[i];
		v.push_back(tmp);
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		std::string revers_str = v[i];
		int tmp = std::stoi(revers_str);
		sum += tmp;
	}

	return digital_root(sum);

}

int main()
{
	setlocale(LC_ALL, "RU");

	std::cout << digital_root(19);
	
	return 0;
}

