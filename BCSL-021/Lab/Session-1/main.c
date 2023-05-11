#include <stdio.h>
#include <math.h>
int q1() {
    int P, T, SI;
    float R, CI;
    printf("Enter the principle amount: ");
    scanf("%d", &P);
    printf("Enter the time period (in years): ");
    scanf("%d", &T);
    printf("Enter the rate of interest: ");
    scanf("%f", &R);
    SI = P * T * R/100;
    CI = (P * pow((1 + R/100), T)) - P;
    printf("%d\n%f", SI, CI);
    return 0;
}
int q2() {
    int income, tax;
    printf("Enter the income amount: ");
    scanf("%d", &income);
    if (income > 35000) {
        tax = 10000 * 0.1 + 20000 * 0.15 + (income - 35000) * 0.2;
    } else if (income <= 35000 && income > 15000) {
        tax = 10000 * 0.1 + (income - 15000) * 0.15;
    } else if (income <= 15000 && income > 5000) {
        tax = (income - 5000) * 0.1;
    } else if (income <= 5000) {
        tax = 0;
    }
    printf("%d", tax);
    return 0;
}
int q3() {
    int even_count = 0, even_sum = 0, odd_count = 0, odd_sum = 0;
    float even_avg, odd_avg;
    int input;
    printf("Enter integers (0 to stop):\n");
    while (scanf("%d", &input) == 1 && input != 0) {
        if (input % 2 == 0){
            even_count++;
            even_sum += input;
        } else {
            odd_count++;
            odd_sum += input;
        }
    }
    even_avg = even_sum / (float) even_count;
    odd_avg = odd_sum / (float) odd_count;
    printf("Number of even integers: %d\n", even_count);
    printf("Average value of even integers: %.2f\n", even_avg);
    printf("Number of odd integers: %d\n", odd_count);
    printf("Average value of odd integers: %.2f\n", odd_avg);
    return 0;
}
int q4() {
	int x, i;
	printf("\nInput an integer: ");
	scanf("%d", &x);
	printf("All the divisor of %d are: ", x);
	for(i = 1; i <= x; i++) {
		if ((x % i) == 0){
			printf("\n%d", i);
			printf("\n");
		}
	}
	return 0;
}
 
int main() {
    q1();
    q2();
    q3();
    q4();
}
