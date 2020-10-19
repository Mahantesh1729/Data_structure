#include <stdio.h>

typedef struct
{
    float age;
    float marks;
    int id;
}
students;

int main()
{
    students a[2];
    
    for(int i = 0; i < 2; i++)
    {
        printf("student %d\nEnter your ID: ",i + 1);
        scanf("%d", &a[i].id);
        printf("Enter your age: ");
        scanf("%f", &a[i].age);
        printf("Enter your marks: ");
        scanf("%f", &a[i].marks);
    }
    
    for(int i = 0; i < 2; i++)
    {
        if(a[i].age < 20 || a[i].marks > 100 || a[i].marks < 0)
        {
            printf("Student ID %d data is invalid\n", a[i].id);
        }
        else if(a[i].marks >= 65)
        {
            printf("Student ID %d is qualified for admission\n",a[i].id);
        }
        else
        {
            printf("Student ID %d is not qualified for admission\n",a[i].id);
        }
    }
}
