#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int Seconds;
    short H,M,S;
    printf("Please Enter the Passed Time by Seconds : \n");
    scanf("%d",&Seconds);
    H=(Seconds/(60*60));
    int MplusS_InSeconds=(Seconds%(60*60));
    S= MplusS_InSeconds % 60;
    M= (MplusS_InSeconds - S)/60;
    printf("H:M:S - %d:%d:%d",H,M,S);
}
