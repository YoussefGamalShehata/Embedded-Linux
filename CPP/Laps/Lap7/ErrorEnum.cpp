#include<iostream>
enum class Error
{
    Bad_Request=400,
    Not_Found = 404,
    Server_Error=500,
    Gateway_Timeout=504
};
void printError(Error myerror)
{
    switch(myerror)
    {
        case Error::Bad_Request:
        std::cout<<"Bad Request Error\n";
        break;
        case Error::Not_Found:
        std::cout<<"Not_Found Error\n";
        break;
        case Error::Server_Error:
        std::cout<<"Server_Error Error\n";
        break;
        case Error::Gateway_Timeout:
        std::cout<<"Gateway_Timeout Error\n";
        break;
    }
}
int main()
{
    Error E = Error::Bad_Request;
    printError(E);
    return 0;

}