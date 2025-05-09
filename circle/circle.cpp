// █
#include <iostream>
#include <string>

int nthFibo(int n)
{
    if (n == 1) return 0;
    if (n == 2) return 1;
    return nthFibo(n - 1) + nthFibo(n - 2);
}


int main()
{
	setlocale(LC_ALL, "ru");

    std::cout << nthFibo(10);

	return 0;
}