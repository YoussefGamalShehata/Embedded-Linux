#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    int Number;
    int arr[32];
    int Result_In_Dec;
    char Type;
    printf("Please Enter The Type of The Number [B / D] : ");
    scanf(" %c",&Type);
    printf("\n");
    printf("Please Enter The Number : ");
    scanf(" %d",&Number);
    printf("\n");
    switch(Type)
    {
    case 'B':
        printf("The Number in Decimal Form is : \n");
        for(int i=31;i>=0;i--)
        {
            arr[i] = Number % 10;
            Number /=10;
        }
        for(int i=31;i>=0;i--)
        {
            Result_In_Dec += arr[i] * pow(2,(31-i));
        }
        printf("%d\n",Result_In_Dec);
        break;
    case 'D':
        printf("The Number in Binary Form is : \n");
        for(int i=31;i>=0;i--)
        {
            printf("%d",((Number >> i) & 1));
        }
        break;
    default:
        printf("Invalid Number Type!!\n");
        break;
    }


}
