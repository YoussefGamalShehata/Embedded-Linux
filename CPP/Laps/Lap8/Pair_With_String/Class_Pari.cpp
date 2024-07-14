#include<iostream>
class My_Pair
{
private:
    std::string First;
    std::string Second;
public:
    My_Pair():First("no input in first"),Second("no input in second")
    {}

    My_Pair(std::string x,std::string y):First(x),Second(y)
    {}
    std::string getfirst()
    {
        return this->First;
    }
    std::string getsecond()
    {
        return this->Second;
    }
    void setfirst(std::string x)
    {
        this->First = x;
    }
    void setsecond(std::string x)
    {
        this->Second = x;
    }
    void setallpair(std::string x, std::string y)
    {
        this->First = x;
        this->Second = y;
    }
    void swapmypair()
    {
        std::string temp = this->First;
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
    My_Pair P1; //will be "no input in first" , "no input in second"
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
    My_Pair P2("Hello word","FRomm the dark side");//test paramterized constructor
    P2.printmypair();



















return 0;
}