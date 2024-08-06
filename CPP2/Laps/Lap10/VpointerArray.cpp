#include<iostream>
class VPointerArray
{
private:
    int size;
    void ** ptr;
public:
    VPointerArray(int S):size(S)
    {
        ptr = new void *[size];
    }
    void settypeandvalue(char t,void * p)
    {
        
        switch(t)
        {
            case 'i':
                *(int *)ptr[0] = *(int *)p;
            break;
            case 'd':
                *(double *)ptr[1] = *(double *)p;
            break;
            case 'c':
                *(char *)ptr[2] = *(char *)p;
            break;
        }
    }
    std::string *gettypeandvalue(void * retval)
    {
        std::string * ptr;
        if(typeid(ptr[0])==typeid(int))
        {
           *ptr ="integer";
           
        }
        else if(typeid(ptr[1])==typeid(double))
        {
            *ptr ="double";
          
        }
        else if(typeid(ptr[2])==typeid(double))
        {
            *ptr ="char";
            
        }
        return ptr;
    }

    ~VPointerArray()
    {
        for(int i=0;i<size;i++)
        {

            delete ptr[i];
        }
        delete ptr;
    }
};
int main()
{
    char type = 'c';
    char value = 'a';
    char retval;
    VPointerArray obj(3);
    obj.settypeandvalue(type,&value);
    std::string * ret = obj.gettypeandvalue(&retval);
    std::cout<<retval<<std::endl<<ret;


return 0;
}