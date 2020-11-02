#include <stdio.h>
# define SIZE 3

int top = -1;

void push(int [], int);
int pop(int []);
void display(int []);

int main()
{
    int stack[SIZE];
    int choice, element;
    char ch;

    do
    {
        printf("Enter your choice:\n");
        printf("1.  Push\n");
        printf("2.  Pop\n");
        printf("3.  Display\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("Enter the element to be pushed: ");
                    scanf("%d", &element);
                    push(stack, element);
                    break;

            case 2: element = pop(stack);
                    if(element == -1)
                    {
                        printf("Stack Underflow!\n");
                    }
                    else
                    {
                        printf("Poped element is %d\n", element);
                    }
                    break;

            case 3: display(stack);
                    break;

            default: printf("Invalid Choice\n");
        }
        printf("Do you want to continue: ");
        scanf(" %c", &ch);
    }while(ch == 'y' || ch == 'Y');

    return 0;
}

void push(int stack[], int element)
{
    if(top == SIZE - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        top++;
        stack[top] = element;
    }
}

int pop(int stack[])
{
    int popele;
    if(top == -1)
    {
        return -1;
    }
    else
    {
        popele = stack[top];
        top--;
        return popele;
    }
}

void display(int stack[])
{
    printf("Stack elements\n");
    for(int i = top; i >= 0; i--)
    {
        printf("%d\n",stack[i]);
    }
}
