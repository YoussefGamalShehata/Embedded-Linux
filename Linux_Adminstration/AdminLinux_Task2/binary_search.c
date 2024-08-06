#include<stdio.h>
int binary_searchFun(int * myarr , int size , int target)
{
	int left = 0, right = size-1;
	while(left<=right)
	{
		int middle = left +(right-left)/2;
		if(myarr[middle]==target)
		{
			return middle;
		}
		if(myarr[middle] < target)
		{
			left=middle+1;
		}
		else
		{
			right=middle-1;
		}
	}
	return -1;
}
int main()
{
	int arr[5]={2,3,4,10,40};
	int size = sizeof(arr)/sizeof(arr[0]);
	int target=10;
	int result = binary_searchFun(arr,size,target);
	if(result != -1)
	{
		printf("Element is present at index %d\n",result);
	}
	else
	{
		printf("Element is not present in the array\n");
	}
return 0;

}
