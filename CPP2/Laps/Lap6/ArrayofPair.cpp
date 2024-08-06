#include<iostream>
#include<utility>
namespace ArrayPair
{
	std::pair<int, int>* createArray(int size)
	{
		std::pair<int, int>* ptr = new std::pair<int, int>[size];
		return ptr;
	}
	void deleteArray(std::pair<int, int>* mypair)
	{
		delete[] mypair;
	}
	void setPair(std::pair<int, int>* mypair,int index)
	{
		std::cout << "Enter the value of the first number" << std::endl;
		std::cin >> mypair[index].first;
		std::cout << "Enter the value of the second number" << std::endl;
		std::cin >> mypair[index].second;
	}
	void getPair(std::pair<int, int>* mypair, int index)
	{
		std::cout << "The value of the first number = " << mypair[index].first;
		std::cout << "The value of the second number = " << mypair[index].second;
	}
	void printpair(std::pair<int, int>* mypair, int size)
	{
		for (int i = 0; i < size; i++)
		{
			
			std::cout << "The First and Second Element in index : " << i << std::endl;
			std::cout << mypair[i].first<<std::endl;
			std::cout << mypair[i].second << std::endl;
		}
	}
}
int main()
{
	std::pair<int, int>* ptr = ArrayPair::createArray(3);
	ArrayPair::setPair(ptr, 0);
	ArrayPair::setPair(ptr, 1);
	ArrayPair::setPair(ptr, 2);
	ArrayPair::printpair(ptr, 3);



}