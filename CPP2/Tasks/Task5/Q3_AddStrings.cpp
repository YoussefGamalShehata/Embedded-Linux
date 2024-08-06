#include <iostream>
#include <string>
#include <algorithm>
std::string addStrings(std::string num1, std::string num2)
{
    int i = num1.size() - 1; // 1
    int j = num2.size() - 1; // 2
    int carry = 0;
    std::string result = "";

    // 11 + 123
    while (i >= 0 || j >= 0 || carry)
    {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry; // #1- 1+3+0=4 & carry = 4 /10 =0------- #2- 1+2+0 =3 & carry=3/10=0 ---------#3- 0+1+0=1 & carry = 1/10 = 0
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
        // now we have a result in the string as 431
        i--;
        j--;
    }
    // we need to reverse string to get the right number
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    std::string num1 = "11";
    std::string num2 = "123";
    std::string res = "";
    res = addStrings(num1, num2);
    std::cout << res << std::endl;
    return 0;
}