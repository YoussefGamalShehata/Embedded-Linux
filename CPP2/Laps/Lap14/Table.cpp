
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main()
{
    std::vector<int> numbers;

    std::ifstream input("input.txt");
    int num;
    while (input >> num)
    {
        numbers.push_back(num);
    }
    input.close();

    int sum = 0;
    int minNum = numbers[0];
    int maxNum = numbers[0];
    double avg;

    if (!numbers.empty())
    {
        for (int num : numbers)
        {
            sum += num;
        }
        std::sort(numbers.begin(), numbers.end());
        minNum = numbers[0];
        maxNum = numbers[numbers.size() - 1];
        avg = static_cast<double>(sum) / numbers.size();
    }

    std::ofstream output("output.txt");
    output << std::fixed << std::setprecision(2);
    output << std::setw(50) << std::setfill('-') << "" << std::endl;
    output << "|" << std::setw(6) << std::setfill(' ') << "Sum" << std::setw(6) << std::setfill(' ') << "|" << std::setw(6) << std::setfill(' ') << "Avg" << std::setw(6) << std::setfill(' ') << "|" << std::setw(6) << std::setfill(' ') << "Min" << std::setw(6) << std::setfill(' ') << "|" << std::setw(6) << std::setfill(' ') << "Max" << std::setw(6) << std::setfill(' ') << "|" << std::endl;
    output << std::setw(50) << std::setfill('-') << "" << std::endl;
    output << "|" << std::setw(6) << std::setfill(' ') << sum << std::setw(6) << std::setfill(' ') << "|" << std::setw(8) << std::setfill(' ') << avg << std::setw(4) << std::setfill(' ') << "|" << std::setw(6) << std::setfill(' ') << minNum << std::setw(6) << std::setfill(' ') << "|" << std::setw(6) << std::setfill(' ') << maxNum << std::setw(6) << std::setfill(' ') << "|" << std::endl;
    output << std::setw(50) << std::setfill('-') << "" << std::endl;
    output.close();

    return 0;
}
