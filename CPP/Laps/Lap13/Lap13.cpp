#include <iostream>
void change(std::string &mainstr, std::string &existstr, std::string &newstr)
{
    int pos = mainstr.find(existstr);
    if (pos != std::string::npos)
    {
        mainstr.replace(pos, existstr.length(), newstr);
    }
    else
    {
        std::cout << existstr << " is not found" << std::endl;
    }
    std::cout << mainstr << std ::endl;
}
int main()
{
    /******** Testin fail replace ***************/
    std::string M = "Hello FRom the dark side";
    std::string Old = "saa";
    std::string New = "white side isa";
    change(M, Old, New);
    /******** Testin success replace ***************/
    M = "Hello FRom the dark side";
    Old = "dark side";
    New = "white side isa";
    change(M, Old, New);
}