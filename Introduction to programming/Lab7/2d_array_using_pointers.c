#include <stdio.h>

int main()
{
    /* code */
    // 2d array, each row contains the grades a student,
    // each column contains the grade of this subject
    printf("Please insert the number of students: \n");
    int students = 0;
    scanf("%d", &students);
    printf("Please insert the number of subject: \n");
    int subjects = 0;
    scanf("%d", &subjects);

    int ** grades = 0, * sum_per_student = 0, * sum_per_subject = 0;
    grades = (int **) malloc(students * sizeof(int *));
    for (int i = 0; i < students; i ++)
    {
        grades[i] = (int *) malloc(subjects * sizeof(int));
    }

    sum_per_student = (int *)malloc(students * sizeof(int));
    sum_per_subject = (int *) malloc(subjects * sizeof(int));

    // initilization
    for (int i = 0; i < students; i++)
    {
        sum_per_student[i] = 0;
        for (int j = 0; j < subjects; j++)
        {
            grades[i][j] = 0;
            sum_per_subject[j] = 0;
        }
    }

    //input
    for (int i = 0; i < students; i++)
    {
        system("cls");
        printf("Now you will enter the grade of student %d.\n", i + 1);
        for (int j = 0; j < subjects; j++)
        {
            printf("Please enter the grade of subject %d: ", j + 1);
            scanf("%d", &grades[i][j]);
            sum_per_student[i] += grades[i][j];
            sum_per_subject[j] += grades[i][j];
        }
    }

    // output
    system("cls");
    for (int i = 0; i < students; i++)
    {
        printf("The sum of the grades of student %d is %d.\n", i + 1, sum_per_student[i]);
    }

    for (int i = 0; i < subjects; i++)
    {
        printf("The average of subject %d is %f.\n", i + 1, (float) sum_per_subject[i] / students);
    }

    return 0;
}
