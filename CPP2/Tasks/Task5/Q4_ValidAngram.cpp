#include <iostream>
#include <string>
#include <algorithm>
bool isAnagram(std::string s, std::string t)
{
    bool ret;
    if (s.length() != t.length())
    {
        ret = false;
    }
    else
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
        {
            ret = true;
        }
        else
        {
            ret = false;
        }
    }
    return ret;
}
int main()
{
    bool res;
    res = isAnagram("anagram", "ramanag");
    // using std::boolalpha to pring true and false instead of 1 and 0
    std::cout << std::boolalpha << res << std::endl;
    return 0;
}