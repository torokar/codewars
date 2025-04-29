#include <iostream>
#include <vector>

std::string spinWords(const std::string& str)
{
	std::vector<std::string> rev_str;
	std::string new_str = str;
	int size = new_str.size();
	char ch[255];
	int i = 0;
	while (i < size)
	{
		ch[i] = new_str[i];
		++i;
	}
	for (int i = 0; i < size; i++)
	{
		std::string f;
		f += ch[i];
		rev_str.push_back(f);
	}
	std::string full_str;
	new_str = "";
	int j = 0;
	std::string s;
	for (size_t i = 0; i < rev_str.size(); i++)
	{
		s += rev_str[i];
	}

	while (j < size)
	{
		full_str = "";
		if (s[j] == ' ')
		{
			++j;
			continue;
		}
		while (s[j] != ' ')
		{
			full_str += s[j];
			++j;
			if (j >= size)
			{
				break;
			}
		}

		if (full_str.size() >= 5)
		{
			for (int j = full_str.size(); j >= 0; --j)
			{
				new_str += full_str[j];
			}
			new_str += " ";
		}
		else
		{
			new_str += full_str;
			new_str += " ";
		}
	}
	return new_str;
}
