#include <stdio.h>

struct Student {
    int enrolment;
    char name[50];
    float aggregate;
    int rank;
};

void assign(struct Student students[], int num_students)
{
    for (int i = 0; i < num_students; i++) {
        students[i].rank = 1;
            for (int j = 0; j < num_students; j++)
                if (i != j && students[i].aggregate < students[j].aggregate)
                    students[i].rank++;
    }
}

void print_details(struct Student students[], int num_students)
{
    printf("Enrolment number\tName\tAggregate\tRank\n");
    for (int i = 1; i <= num_students; i++)
        for (int j = 0; j < num_students; j++)
            if (students[j].rank == i)
                printf("%d\t\t\t%s\t%.2f\t\t%d\n", students[j].enrolment, 
                                                   students[j].name,
                                                   students[j].aggregate,
                                                   students[j].rank);
}

int main()
{
    int num_students;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    struct Student students[num_students];

    for (int i = 0; i < num_students; ++i) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Enrolment Number: ");
        scanf("%d", &students[i].enrolment);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Aggregate Marks: ");
        scanf("%f", &students[i].aggregate);
    }

    assign(students, num_students);

    print_details(students, num_students);

    return 0;
}
