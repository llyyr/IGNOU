// Q7. Using File Handling concept in C programming, write the C programs for 
// the following:
// (a) To create and store student information of 10 MCA students in a .dat file.
// (b) To edit the file created in (a) to add data for 2 more students.
// (c) To delete specific line(one student record) from a file.

// (a)
#include <stdio.h>

int main()
{
    char enroll[11], name[50];
    int age, i, n;

    printf("Enter number of MCA students: ");
    scanf("%d",&n);

    FILE *fptr = fopen("students.dat", "w");
    
    if (fptr == NULL) {
        return 1;
    }

    for (i=0; i < n; ++i) {
        printf("For student %d\nEnter enrollment no.: ", i+1);
        scanf("%s", enroll);
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter age: ");
        scanf("%d", &age);
        fprintf(fptr, "\nEnrollment No.: %s, Name: %s, Age: %d", enroll, name, age);
    }
    fclose(fptr);
    return 0;
}
