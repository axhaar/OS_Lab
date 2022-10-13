//write a c program in which the parent process computes the sum off even and child process computes the sum of odd numbers stored in array first ,the child process should print its oun process ie sum off odd numbers then the parent  
#include <stdio.h>
#include <unistd.h>

int main()
{

    int pid, n;
    printf("enter the no. of terms in the array : ");
    scanf("%d", &n);
    int a[n], sum = 0, status;

    printf("\n enter vlues in the array : ");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    pid = fork();
    if (pid != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 != 0)
            {
                sum += a[i];
            }
        }
        printf("sum is odd number %d \n", sum);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                sum = sum + a[i];
            }
        }
        printf("sum of even number =%d\n", sum);
    }
    return 0;
}


// write a c program in which parent process compute the sum of even process and child process computes the sum of odd numbers .
//  stored in an array using a fork.

// first , the child process should print its ans i.e sum of odd numbers then the parent should print its ans i.e the sum of even numbers

// if pid==0


