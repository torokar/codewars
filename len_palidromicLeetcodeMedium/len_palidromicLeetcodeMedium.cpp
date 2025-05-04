#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) 
    {
        std::string one_str, two_str;
        std::string Line_redu = s;
        int i = 0;
        int j = 0;
        int q = 1;

        one_str = Line_redu;
        two_str = Line_redu;
        std::reverse(two_str.begin(), two_str.end());

        if (one_str == two_str)
        {
            return one_str;
        }

        if (Line_redu.size() <= 2)
        {
            std::string ss;
            ss += Line_redu[0];
            return ss;
        }

        //Так ну это проверка если строка является изначально палидромом
        //Например xabay yabax xabax 

        else
        {
            one_str = "";
            two_str = "";
            while (true)
            {
                one_str += Line_redu[i];
                ++i;
                if (one_str.size() <= 1)
                {
                    continue;
                }
                while (true)
                {
                    two_str += one_str[j];
                    ++j;
                    if (j >= one_str.size())
                    {
                        break;
                    }
                }
                std::reverse(two_str.begin(), two_str.end());

                if (one_str == two_str)
                {
                    return one_str;
                }
                std::reverse(two_str.begin(), two_str.end());

                //Обрезаем строку если не нашли палидром
                //И обнуляем все значения
                if (i >= Line_redu.size())
                {
                    i = 0;
                    j = 0;
                    Line_redu = Line_redu.substr(q, Line_redu.size());
                    one_str = "";
                    two_str = "";
                }
            }
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    Solution sol;
    std::cout << sol.longestPalindrome("as");

    return 0;
}