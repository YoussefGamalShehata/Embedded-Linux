#include <iostream>
class Solution
{
public:
    int addDigits(int num)
    {
        int res = 0;
        while (1)
        {
            while (num != 0)
            {
                res += (num % 10);
                num /= 10;
            }
            if (res < 10)
            {
                break;
            }
            else
            {
                num = res;
                res = 0;
            }
        }
        return res;
    }
};
int main()
{
    Solution obj;
    int ret = obj.addDigits(38);
    std::cout << ret;
}