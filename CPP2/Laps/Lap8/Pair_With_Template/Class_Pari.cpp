#include<iostream>
template<typename T>
class My_Pair
{
private:
    T First;
    T Second;
public:
    My_Pair():First("no input in first"),Second("no input in second")
    {}

    My_Pair(T x,T y):First(x),Second(y)
    {}
    T getfirst()
    {
        return this->First;
    }
    T getsecond()
    {
        return this->Second;
    }
    void setfirst(T x)
    {
        this->First = x;
    }
    void setsecond(T x)
    {
        this->Second = x;
    }
    void setallpair(T x, T y)
    {
        this->First = x;
        this->Second = y;
    }
    void swapmypair()
    {
        T temp = this->First;
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
    My_Pair<std::string> P1; //will be "no input in first" , "no input in second"
    P1.printmypair();
    /**************************/
    P1.setallpair("Yousef","Gamal");
    P1.printmypair(); //Will print Youssef , Gamal
    /**************************/
    P1.setfirst("joe");
    P1.setsecond("Multi");
    std::string first = P1.getfirst();
    std::string second = P1.getsecond();
    std::cout<<"first = "<<first<<std::endl<<"second = "<<second<<std::endl;
    /**************************/
    My_Pair<std::string> P2("Hello word","FRomm the dark side");//test paramterized constructor
    P2.printmypair();



















return 0;
}