#include <iostream>
class ParkingSystem
{
private:
    int BIG;
    int MED;
    int SMALL;

public:
    // Once creating an object we must pass the number of slots for each size
    ParkingSystem(int big, int medium, int small) : BIG(big), MED(medium), SMALL(small)
    {
    }
    /*this function checks if there is avaliable slot for the carType passed in this function and return
      true if there is a slot and false in case of not
      carType may be : 1- big 2-medium 3-small */
    bool addCar(int carType)
    {
        bool ret;
        switch (carType)
        {
        case 1: /*BIG*/
            if (BIG != 0)
            {
                ret = true;
                BIG--;
            }
            else
            {
                ret = false;
            }
            break;
        case 2: /*MED*/
            if (MED != 0)
            {
                ret = true;
                MED--;
            }
            else
            {
                ret = false;
            }
            break;
        case 3: /*SMALL*/
            if (SMALL != 0)
            {
                ret = true;
                SMALL--;
            }
            else
            {
                ret = false;
            }
            break;
        default:
            /*Nothing*/
            break;
        }
        return ret;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
int main()
{
    int Big_Car = 1, Medium_Car = 2, Small_Car = 3;
    int big, medium, small;
    int Scar_Counter, Mcar_Counter, Bcar_Counter;
    int Parked_counter = 0;
    std::cout << "Please Enter the number of Big slots : ";
    std::cin >> big;
    std::cout << "Please Enter the number of Medium slots : ";
    std::cin >> medium;
    std::cout << "Please Enter the number of Small slots : ";
    std::cin >> small;
    std::cout << "Please Enter the number of Big Cars you need to park : ";
    std::cin >> Bcar_Counter;
    std::cout << "Please Enter the number of Medium Cars you need to park : ";
    std::cin >> Mcar_Counter;
    std::cout << "Please Enter the number of Small Cars you need to park : ";
    std::cin >> Scar_Counter;
    ParkingSystem *obj = new ParkingSystem(big, medium, small);
    for (int i = 0; i < Bcar_Counter; i++)
    {
        if ((obj->addCar(Big_Car)))
        {
            Parked_counter++;
            std::cout << Parked_counter << " Big Car Have been in the garage right now and " << (Bcar_Counter - Parked_counter) << " Remaining out !!" << std::endl;
        }
        else
        {
            std::cout << Parked_counter << " Big Car Have been in the garage right now and " << (Bcar_Counter - Parked_counter) << " Remaining out !!" << std::endl;
            break;
        }
    }
    Parked_counter = 0;
    for (int i = 0; i < Mcar_Counter; i++)
    {
        if ((obj->addCar(Medium_Car)))
        {
            Parked_counter++;
            std::cout << Parked_counter << " Medium Car Have been in the garage right now and " << (Mcar_Counter - Parked_counter) << " Remaining out !!" << std::endl;
        }
        else
        {
            std::cout << Parked_counter << " Medium Car Have been in the garage right now and " << (Mcar_Counter - Parked_counter) << " Remaining out !!" << std::endl;
            break;
        }
    }
    Parked_counter = 0;
    for (int i = 0; i < Scar_Counter; i++)
    {
        if ((obj->addCar(Small_Car)))
        {
            Parked_counter++;
            std::cout << Parked_counter << " Small Car Have been in the garage right now and " << (Mcar_Counter - Parked_counter) << " Remaining out !!" << std::endl;
        }
        else
        {
            std::cout << Parked_counter << " Small Car Have been in the garage right now and " << (Mcar_Counter - Parked_counter) << " Remaining out !!" << std::endl;
            break;
        }
    }

    return 0;
}