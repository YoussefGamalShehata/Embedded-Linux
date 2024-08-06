#include <iostream>
#include <vector>
int largestAltitude(std::vector<int> &gain)
{
    int Highest = 0, PreAltitude = 0, CurrentAltitude = 0;
    gain.insert(gain.begin(), 0);
    for (int i = 0; i < gain.size(); i++)
    {
        PreAltitude = CurrentAltitude; //[0,-4,-3,-2,-1,4,3,2] //-4 - -7 - -9 - -10 - -6 - -3
        CurrentAltitude += gain[i];    //-7 - -9 - -10 - -6 - -3 - -1
        if (CurrentAltitude > PreAltitude)
        {
            if (CurrentAltitude > Highest)
            {
                Highest = CurrentAltitude;
            }
        }
    }
    return Highest;
}
int main()
{
    std::vector<int> a{-5, 1, 5, 0, -7}; // 0,-5,1,5,0,-7 >>>> 0+-5 =-5 , 1 + -5 = -4,
    int res = largestAltitude(a);
    std::cout << res << std::endl;

    return 0;
}