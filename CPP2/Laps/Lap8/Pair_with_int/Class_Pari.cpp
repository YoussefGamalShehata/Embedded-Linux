#include<iostream>
class My_Pair
{
private:
    int First;
    int Second;
public:
    My_Pair():First(0),Second(0)
    {}

    My_Pair(int x,int y):First(x),Second(y)
    {}
    int getfirst()
    {
        return this->First;
    }
    int getsecond()
    {
        return this->Second;
    }
    void setfirst(int x)
    {
        this->First = x;
    }
    void setsecond(int x)
    {
        this->Second = x;
    }
    void setallpair(int x, int y)
    {
        this->First = x;
        this->Second = y;
    }
    void swapmypair()
    {
        int temp = this->First;
        this->First = this->Second;
        this->Second = temp;
    }
    void printmypair()
    {
        std::cout<<"The First Element = "<<this->First<<std::endl;
        std::cout<<"The Second Element = "<<this->Second<<std::endl;
    }
};
int main()
{
    My_Pair P1; //will be zeros
    P1.printmypair();
    /**************************/
    P1.setallpair(2,3);
    P1.printmypair(); //Will print 2 , 3
    /**************************/
    P1.setfirst(5);
    P1.setsecond(20);
    int first = P1.getfirst();
    int second = P1.getsecond();
    std::cout<<"first = "<<first<<std::endl<<"second = "<<second<<std::endl;
    /**************************/
    My_Pair P2(30,40);//test paramterized constructor
    P2.printmypair();



















return 0;
}