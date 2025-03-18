#include <iostream>

void PrintNumber(int a)
{
    int tenThousand = (a / 10000);
    int thousand = (a / 1000) % 10;
    int hundred = (a / 100) % 10;
    int ten = (a / 10) % 10;
    int one = a % 10;

    std::cout << tenThousand << "만 ";

    std::cout << thousand << "천 ";

    std::cout << hundred << "백 ";

    std::cout << ten << "십 ";

    std::cout << one;

    std::cout << std::endl;
}

int main()
{
    int a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    PrintNumber(a);
    return 0;
}