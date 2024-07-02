#include <iostream>

int main() {

    // тип_данных* название_указателя

    int* pint{};
    double* pdouble{};
    std::cout << "pint =  " << sizeof(pint) << std::endl;
    std::cout << "pdouble = " << sizeof(pdouble) << std::endl;

    int number = 25;
    int* pnumber = &number;

    std::cout << "Значение pnumber : " << *pnumber << std::endl;
    std::cout << "Адрес указателя pnumber : " << &pnumber << std::endl;
    std::cout << "Адрес переменной number : " << pnumber << std::endl;
    int copyNumber = *pnumber;
    std::cout << "CopyNumber : " << copyNumber << std::endl;
    *pnumber = 65535;
    std::cout << "Изменил значение переменной number : " << number << std::endl;


    int* ptr1;
    int* ptr2;

    ptr1 = &copyNumber;
    ptr2 = ptr1;
    std::cout << "Значение переменной copyNumber : " << copyNumber << std::endl;
    std::cout << "Значение указателя ptr1 : " << *ptr1 << std::endl;
    std::cout << "Значение указателя ptr2 : " << *ptr2 << std::endl;
    *ptr2 = 5432;
    std::cout << "Значение переменной copyNumber  после изменения через указатель *ptr2 = 5432 : " << copyNumber << std::endl;


    std::cout << "Ссылки на указатели " << std::endl;

    int a = 10;
    int b = 6;

    int* pRef; // указатель
    int* &Ref = pRef;  // ссылка на указатель

    Ref = &a; // через ссылку указателю pRef присваивается адрес переменной a
    std::cout << "pRef value = " << *pRef << std::endl;

    *Ref = 75; // изменяем значение по адресу, на который указывает указатель

    std::cout << "a value = " << a << std::endl;

    Ref = &b; // изменяем адрес, на который указывает указатель
    std::cout << "pRef value = " << *pRef << std::endl;
/*
    const int* pt; // Не могу менять значение, но могу менять адрес указателя
    int* const pt2; // Не могу менять адрес указателя, но могу менять значения
    const int* const pt3; // Не могу менять адрес и значение указателя
*/
    const int n = 5;
    int nums[n]{1, 2, 3, 4, 5};
    // Цикл начинается с первого адреса массива, до последнего элемента, увеличивает адрес на +1
    for(int *ptr{nums}; ptr<=&nums[n-1]; ptr++)
    {
        std::cout << "address=" << ptr << "\tvalue=" << *ptr << std::endl;
    }
    return 0;
}