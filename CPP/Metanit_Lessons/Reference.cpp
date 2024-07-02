#include <iostream>

int main() {

    int number {5};
    int &refNumber {number};

    std::cout << refNumber << std::endl;
    refNumber = 20;
    std::cout << number << std::endl;

    const int number2 = 5;
    const int &ref2 = number2;

    std::cout << "const ref" << ref2 << std::endl;

    int num3 = 11;
    const int &ref3 = num3;
    std::cout << " const ref : " << ref3 << std::endl;
    num3 = 222;
    std::cout << "num3 ++  : " << ref3 << std::endl;


    std::cout << "Ссылки в цикле for" << std::endl;

    int num4[5] = {1,2,3,4,5};
    for(auto n : num4) {
        n = n * n;
    }
    for(auto n : num4) {
        std::cout << n << "\t";
    }
    std::cout << "\n" <<  std::endl;
    // теперь n - ссылка на элемент массива
    for(auto &n : num4) {
        n = n * n;
    }

    for(auto n : num4) {
        std::cout << n << "\t";
    }
    std::cout << "\n" << std::endl;
    /*не можем изменять значение элемента, 
    но также с помощью ссылок оптимизируем перебор массива, 
    так как элементы массива не копируются в переменную n.*/
    for(const auto &n : num4) {
        std::cout << n << "\t";
    }
    std::cout << std::endl;




    
    return 0;
}