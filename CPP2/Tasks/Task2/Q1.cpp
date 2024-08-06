#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string company;
    string model;
    int year;

public:
    // Constructor
    Car(string comp, string mod, int yr) : company(comp), model(mod), year(yr) {}

    // Getter for company
    string getCompany() const {
        return company;
    }

    // Setter for company
    void setCompany(const string &comp) {
        company = comp;
    }

    // Getter for model
    string getModel() const {
        return model;
    }

    // Setter for model
    void setModel(const string &mod) {
        model = mod;
    }

    // Getter for year
    int getYear() const {
        return year;
    }

    // Setter for year
    void setYear(int yr) {
        year = yr;
    }

    // Function to display car details
    void displayCarDetails() const {
        cout << "Company: " << company << "\nModel: " << model << "\nYear: " << year << endl;
    }
};

int main() {
    // Create a Car object
    Car myCar("Toyota", "Corolla", 2021);

    // Display initial car details
    myCar.displayCarDetails();

    // Modify car details
    myCar.setCompany("Honda");
    myCar.setModel("Civic");
    myCar.setYear(2022);

    // Display updated car details
    myCar.displayCarDetails();

    return 0;
}