// Q6. Using Structures in C, write an interactive program to display the 
// pay-slips for 10 employees working in a small departmental stores.
//
// Note: Assumptions can be made wherever necessary and mention them.

#include <stdio.h>

typedef struct {
    char name[30];
    int id;
    double salary;
} Employee;

int main()
{
    int n = 10;
    Employee employees[n];
    printf("Enter %d employee details\n", n);
    for (int i=0; i<n; i++) {
        printf("Employee %d\nName: ", i+1);
        scanf("%s", employees[i].name);
        printf("Id: ");
        scanf("%d", &employees[i].id);
        printf("Salary: ");
        scanf("%lf", &employees[i].salary);
        printf("\n");
    }
    printf("Displaying employee details\n");
    for (int i=0; i<n; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Id: %d\n", employees[i].id);
        printf("Salary: %.2lf\n\n", employees[i].salary);
    }
}
