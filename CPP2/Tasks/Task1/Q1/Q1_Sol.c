#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int input=1,result=0;
    printf("Please Enter Number :\n");
    while(input != 0)
    {
        scanf("%d",&input);
        if(input == 0)
        {
            break;
        }
        result = input;
        printf("Please Another Enter Number :\n");
    }
    printf("The Result is : %d\n",result);

}
