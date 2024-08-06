#include<iostream>
template<typename T1,typename T2>
class KeyValuePair
{
private:
    T1 key;
    T2 value;
public:

    KeyValuePair(T1 k,T2 v):key(k),value(v)
    {}
    void setKey(T1 k)
    {
        key = k;
    }
    T1 getKey(void)
    {
        return key;
    }
    void setvalue(T2 v)
    {
        value = v;
    }
    T2 getvalue(void)
    {
        return value;
    }
    void setKey(double k) = delete;
    void setvalue(struct v) = delete;
};
int main()
{
    KeyValuePair<int,std::string> obj1(5,(std::string)"Youssef");
    int k = obj1.getKey();
    std::string v = obj1.getvalue();
    std::cout<<k<<std::endl<<v<<std::endl;

    return 0;
}