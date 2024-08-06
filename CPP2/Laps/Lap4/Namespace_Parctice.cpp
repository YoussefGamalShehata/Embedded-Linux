#include<iostream>
#include<string>
namespace MathFunction
{
	void print(double x)
	{
		std::cout << "The square root = " << sqrt(x) << std::endl;
	}
}
namespace StringFunction
{
	void print(char * y)
	{
		int i = 0,k=0;
		while (y[i] != '\0')
		{
			if (y[i] >= 'a' && y[i] <= 'z')
			{
				y[i] = y[i] - 32;
			}
			else if (y[i] >= 'A' && y[i] <= 'Z')
			{
				y[i] = y[i] + 32;
			}
			i++;
		}
		while (y[k] != '\0')
		{
			std::cout << y[k];
			k++;
		}
	}
}
namespace ArrayFunction
{
	void print(int * x,int size)
	{
		for (int i = size - 1; i >= 0; i--)
		{
			std::cout << x[i] << " ";
		}
		
	}
}
int main()
{
	/*MathFunction_Test*/
	//double Num;
	//std::cin >> Num;
	//MathFunction::print(Num);
	/*StringFunction_Test*/
	//char myname[] = "YoUsSeF";
	//StringFunction::print(myname);
	/*ArrayFunction_Test*/
	int myarr[5] = { 1,2,3,4,5 };
	ArrayFunction::print(myarr, 5);


}
