#include <iostream>
#include <cmath>

class InterestCalculator {
private:
    float principal;
    float rate;
    int time;

public:
    // Constructor
    InterestCalculator(float p, float r, int t) : principal(p), rate(r), time(t) {}

    float calculate_si() {
        return (principal * rate * time) / 100;
    }

    float calculate_ci() {
        return principal * (pow((1 + rate / 100), time)) - principal;
    }
};

int main() {
    float principal, rate;
    int time;

    std::cout << "Enter principal amount: ";
    std::cin >> principal;

    std::cout << "Enter rate of interest: ";
    std::cin >> rate;

    std::cout << "Enter time period (in years): ";
    std::cin >> time;

    InterestCalculator calculator(principal, rate, time);
    std::cout << "SI: " << calculator.calculate_si() << std::endl;
    std::cout << "CI: " << calculator.calculate_ci() << std::endl;

    return 0;
}
