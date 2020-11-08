#include <stdio.h>
void tower(char a, char c, char b, int n);
int main()
{
    int n;
    char source = 'A' ;
    char destination =  'C';
    char auxillary = 'B';
    printf("How many disks do you want to enter: ");
    scanf("%d", &n);
    tower(source, destination, auxillary, n);
    return 0;
}
void tower(char a, char c, char b, int n)
{
    if(n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, a, c);
        return;
    }

    tower(a, b, c, n - 1);

    printf("Move disk %d from %c to %c\n", n, a, c);

    tower(b, c, a, n - 1);

    return;
}
