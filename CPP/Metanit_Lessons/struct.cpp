#include <iostream>

struct person {
    unsigned age;
    std::string name;
};

int main() {
    person dima;
    dima.age = 27;
    dima.name = "Dima";
    std::cout << "Person Name : " << dima.name << "\t age : " << dima.age << std::endl; 



    return 0;
}