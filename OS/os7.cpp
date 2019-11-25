#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int sum;

void *runner(void *param)
{
    int *upper = (int *)param;
    sum = 0;
    for (int i = 1; i <= *upper; i++)
        sum += i;
    pthread_exit(0);
}

int main()
{
    pthread_t tid;
    int num = 6;
    pthread_create(&tid, NULL, runner, &num);
    pthread_join(tid, NULL);
    printf("sum = %d\n", sum);
    return 0;
}