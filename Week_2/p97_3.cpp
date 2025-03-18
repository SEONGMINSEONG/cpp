#include <iostream>
#include <cmath>

double calculatePi(int n)
{
    double pi = 0.0;

    for (int k = 0; k <= n; k++)
    {
        pi += pow(-1, k) / (2 * k + 1);
    }

    return 4 * pi;
}

int main()
{
    int n;

    std::cout << "정수 n을 입력하세요: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "n은 0 이상의 정수여야 합니다." << std::endl;
        return 1; 
    }

    double approxPi = calculatePi(n);

    std::cout << "근사값: " << approxPi << std::endl;

    return 0;
}
