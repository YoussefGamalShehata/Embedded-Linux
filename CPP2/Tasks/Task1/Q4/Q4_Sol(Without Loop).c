#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    /*We can get the number of years without using the years_counter variable as following:
    1-Define a variable refers to the StartPopulation which is 162100
    2-Define a Variabel refers to the EndPopulation which we get from the loop
    3-Calculate the Years due to the change happend in Population through StartPopulation and EndPopulation
    */
    float StartPopulation = 162100.00;
    float EndPopulation = 162100.00;
    float Rate_PerYear = (6.5/100) * StartPopulation;
    int Years_Needed=0;
    float Change_Happend;
    while(EndPopulation < 1000000)
    {
        EndPopulation += Rate_PerYear;
    }
    printf("EndPopulation = %0.2f\n",EndPopulation);
    Change_Happend = EndPopulation - StartPopulation;
    //The Division  of Change_Happend in population over the change rate per year know us how many years passed to reach this EndPopulation
    Years_Needed = Change_Happend / Rate_PerYear ;
    printf("Years_Needed = %d\n",Years_Needed);

    return 0;
}
