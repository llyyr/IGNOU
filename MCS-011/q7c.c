// Q7. Using File Handling concept in C programming, write the C programs for 
// the following:
// (a) To create and store student information of 10 MCA students in a .dat file.
// (b) To edit the file created in (a) to add data for 2 more students.
// (c) To delete specific line(one student record) from a file.

// (c)
#include <stdio.h>

int main()
{
    int line_no, temp = 1;
    FILE *fptr, *fptr2;
    char ch;
    fptr = fopen("students.dat", "r");
    if (fptr == NULL)
        return 1;
    printf("Enter line number to be deleted: ");
    scanf("%d", &line_no);
    fptr2 = fopen("temp.dat", "w");
    if (fptr2 == NULL)
        return 1;
    ch = getc(fptr);
    while (ch != EOF) {
        ch = getc(fptr);
        if (ch == '\n')
            temp++;
        if (temp != line_no)
            putc(ch, fptr2);
    }
    fclose(fptr);
    fclose(fptr2);
    remove("students.dat");
    rename("temp.dat", "students.dat");
    return 0;
}
