#include <iostream>

class Time_
{
private:
    int Hours;
    int Minutes;
    int Seconds;

public:
    Time_() : Hours(0), Minutes(0), Seconds(0) {}
    Time_(int h, int m, int s) : Hours(h), Minutes(m), Seconds(s) {}
    int get_Hours()
    {
        return this->Hours;
    }
    int get_Minutes()
    {
        return this->Minutes;
    }
    int get_Seconds()
    {
        return this->Seconds;
    }
    void set_Hours(int h)
    {
        this->Hours = h;
    }
    void set_Minutes(int m)
    {
        this->Minutes = m;
    }
    void set_Seconds(int s)
    {
        this->Seconds = s;
    }
    void Time_Display() const
    {
        std::cout << this->Hours << ":" << this->Minutes << ":" << this->Seconds << std::endl;
    }
    Time_ AddTwoTimeClasses(const Time_ Obj1, const Time_ Obj2)
    {
        Time_ Ret;
        int ExtraSeconds = 0, ExtraMinuts = 0, ExtraHours = 0;
        Ret.Seconds = Obj1.Seconds + Obj2.Seconds;               // 35 +35 = 70 >> 1 min + 10 sec
        ExtraMinuts = Ret.Seconds / 60;                          // >> 1 min need to be added and 10 sec will be in seconds
        Ret.Seconds %= 60;                                       // we need to get the reminder of 70 over 60 >>  10
        Ret.Minutes = Obj1.Minutes + Obj2.Minutes + ExtraMinuts; // total mins will be 2 objectes + Extraminutes i got which is 15 + 30 + 1 = 46
        ExtraHours = Ret.Minutes / 60;                           // in case we find that minuts are > 60 >> like 80 so we have 1 hour extra and 20 mins
        Ret.Minutes %= 60;                                       // get the reminder of 80 over 60 >> 20 mins and 1 hour will be added to the total hours
        Ret.Hours = Obj1.Hours + Obj2.Hours + ExtraHours;        // total hours
        Ret.Hours %= 24;                                         // when we reach 24 hours it will be 0 hours (new day)
        return Ret;
    }
};

int main()
{
    // Create 2 Objects
    Time_ T1(3, 48, 20), T2(10, 50, 30);
    Time_ T3;
    T3 = T3.AddTwoTimeClasses(T1, T2);
    T3.Time_Display();
}