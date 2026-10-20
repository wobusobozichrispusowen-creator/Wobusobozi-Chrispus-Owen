// Welcome a student to their assigned residence hall
#include <iostream>

int main()
{
    std::cout << "Which hall are you assigned to?\n";
    std::string hall_name;              // hall_name is a variable of type string
    std::cin >> hall_name;              // read characters into hall_name
    std::cout << "Welcome to " << hall_name << " Hall!\n";
    return 0;
}