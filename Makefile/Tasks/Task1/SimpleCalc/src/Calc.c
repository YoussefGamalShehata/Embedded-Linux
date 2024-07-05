#include<stdio.h>
#include<stdlib.h>
int Operation(int Num1,int Num2)
{
  char operator_;
  printf("Please Enter one of [+ , - , * , /]\n");
  scanf(" %c",&operator_);
  switch(operator_)
  {
	case '+':
	  return (Num1+Num2);
	break;
	case '-':
          return (Num1-Num2);
        break;
	case '*':
          return (Num1*Num2);
        break;
	case '/':
          return (Num1/Num2);
        break;
	default:
	  printf("Invalid Operator!!\n");
	  return -1;
	break;
  }


}
