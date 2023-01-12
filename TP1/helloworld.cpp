#include <iostream>

int main()
{
    int age = 0;
    std::cout << "Hello World !" << std::endl
              << "How old are you ?" << std::endl;
    std::cin >> age;
    std::cout << "You are " << age << " years old" << std::endl;
    return 0;
}