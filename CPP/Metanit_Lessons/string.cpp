#include <iostream>

int main() {

    std::string message {"Hello world"};
    std::string message2 = "Hello wolrd 2";
    std::string message3("Hello world 3");

    std::string hello = message2;

    std::cout << "Message : " << message << std::endl;

    std::string mes4 {"Hello"};
    mes4[0] = 'M';
    std::cout << mes4 << std::endl;

    unsigned count = 0;
    for(const char c : message) {
        if(c == 'l') {
            count++;
        }
    }
    std::cout << "Count : " << count << std::endl;

    std::cout << "Считывание строки с консоли \n" << std::endl;
    std::string text;
    std::cin >> text;
    std::cout << "Your text : " << text << std::endl;
    std::string text2;
    getline(std::cin, text2);

    std::cout << " TEXT : " << text2 << std::endl;   




    return 0;
}