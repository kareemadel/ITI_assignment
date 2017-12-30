#include <stdio.h>
#define STUDENTS 3
#define SUBJECTS 4

int main()
{
    /* code */
    // 2d array, each row contains the grades a student,
    // each column contains the grade of this subject
    int grades[STUDENTS][SUBJECTS] = {{0}};
    int sum_per_student[STUDENTS] = {0};
    int sum_per_subject[SUBJECTS] = {0};

    for (int i = 0; i < STUDENTS; i++)
    {
        printf("Now you will enter the grade of student %d.\n", i + 1);
        for (int j = 0; j < SUBJECTS; j++)
        {
            printf("Please enter the grade of subject %d: ", j + 1);
            scanf("%d", &grades[i][j]);
            sum_per_student[i] += grades[i][j];
            sum_per_subject[j] += grades[i][j];
        }
    }

    for (int i = 0; i < STUDENTS; i++)
    {
        printf("The sum of the grades of student %d is %d.\n", i + 1, sum_per_student[i]);
    }

    for (int i = 0; i < SUBJECTS; i++)
    {
        printf("The average of subject %d is %0.2f.\n", i + 1, (float) sum_per_subject[i] / STUDENTS);
    }

    return 0;
}