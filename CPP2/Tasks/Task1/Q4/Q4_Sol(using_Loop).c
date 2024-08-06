#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    float Population = 162100.00;
    float Rate_PerYear = (6.5/100) * Population;
    int years_counter=0;
    while(Population < 1000000)
    {
        Population += Rate_PerYear;
        years_counter++;
    }
    printf("Population = %0.2f\n",Population);
    printf("Years to exceed 1 million = %d\n",years_counter);
}
