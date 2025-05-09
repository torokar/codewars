#include <iostream>
#include <string>
#include <set>

class Solution 
{
/*Идея такая
Вытягиваю из исходной строки символ записываю в в две строки 
одну из них переворачиваю и просто сравниваю равны друг другу они или нет
но пока работает это так что он возвращает самый первый палидром. Нужно сейчас как 
записать все палидромы и потом сравнить их длины 
Идеи:
1) Самая первая это просто записать все палидромы в какой то контейнер и вернуть 
самый большой
*/
public:

    std::string longestPalindrome(std::string s) 
    {
        std::set<std::string> max_size_str;
        std::string one_str, two_str;
        std::string Line_redu = s;
        int i = 0;
        int j = 0;
        int q = 1;

        int ii = 0; //тоже оптимизация 

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
            /*Очень длинный цикл который берет из строки 
            по одному символу и проверяет на палидром
            */
            while (true)
            {
                one_str += Line_redu[i];
                ++i;
                if (Line_redu.size() == 0)
                {
                    break;
                }
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
                //Переворачивает строку для проверки палидрома
                std::reverse(two_str.begin(), two_str.end());

                if (one_str == two_str)
                {
                    max_size_str.insert(one_str);
                    /*return one_str;*/
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
                std::cout << "\n\nЦикл " << ii << std::endl << std::endl; //Для проверки где можно оптимизировать 
                ++ii;
            }
            
        }

        std::string str;
        std::set<std::string>::iterator second = max_size_str.end();
        std::set<std::string>::iterator first = max_size_str.begin();
        //Ну хз условия вернуть палидром в длиною 1 символ 
        if (!max_size_str.empty())
        {

            for (; first != second; ++first)
            {
                str = *first;
                for (auto first2 : max_size_str)
                {
                    if (str.size() < first2.size())
                    {
                        str = first2;
                    }
                }
            }
        }
        else
        {
            str = s[0];
        }

        return str;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    system("color 0A");

    Solution sol;
    std::cout << sol.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

    return 0;
}