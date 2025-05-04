#include <iostream>
#include <string>

//Перевод из числа в строку и сравнения 
class Solution {
public:
    bool isPalindrome(int x) {

        if (x <= 0)
        {
            return false;
        }

        std::string revers;
        std::string check_revers;
        revers = std::to_string(x);

        //Перебор символов и запись в обратном порядке
        for (int i = revers.length() - 1; i >= 0 ; --i)
            check_revers += revers[i];

        if (check_revers == revers)
            return true;
        else
            return false;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    Solution sol;
    std::cout << sol.isPalindrome(-101);

    return 0;
}