#include <iostream>

int main()
{
    auto age = std::string{};
    auto name = std::string{};
    std::cout << "Hello World !" << std::endl
              << "How old are you ?" << std::endl;
    std::cin >> age;
    std::cout << "You are " << age << " years old" << std::endl;
    std::cout << "What's your name ?" << std::endl;
    std::cin >> name;
    std::cout << "Hello " << name << std::endl;
    return 0;
}

// Les chaînes de caractères en C++ sont représentées par std::string
