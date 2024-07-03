#include <chrono>
#include <iostream>

void func(unsigned int& val);
void func2(unsigned int& val);
void func3(unsigned int* val);
void func4(unsigned int* val);

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
  std::cout << "Значение переменной copyNumber  после изменения через "
               "указатель *ptr2 = 5432 : "
            << copyNumber << std::endl;

  std::cout << "Ссылки на указатели " << std::endl;

  int a = 10;
  int b = 6;

  int* pRef;         // указатель
  int*& Ref = pRef;  // ссылка на указатель

  Ref = &a;  // через ссылку указателю pRef присваивается адрес переменной a
  std::cout << "pRef value = " << *pRef << std::endl;

  *Ref = 75;  // изменяем значение по адресу, на который указывает указатель

  std::cout << "a value = " << a << std::endl;

  Ref = &b;  // изменяем адрес, на который указывает указатель
  std::cout << "pRef value = " << *pRef << std::endl;
  /*
      const int* pt; // Не могу менять значение, но могу менять адрес указателя
      int* const pt2; // Не могу менять адрес указателя, но могу менять значения
      const int* const pt3; // Не могу менять адрес и значение указателя
  */
  const int n = 5;
  int nums[n]{1, 2, 3, 4, 5};
  // Цикл начинается с первого адреса массива, до последнего элемента,
  // увеличивает адрес на +1
  for (int* ptr{nums}; ptr <= &nums[n - 1]; ptr++) {
    std::cout << "address=" << ptr << "\tvalue=" << *ptr << std::endl;
  }
  unsigned int t = 5;
  unsigned int& ref = t;
  unsigned int* ptr = &t;
  auto start = std::chrono::high_resolution_clock::now();
  func(ref);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  std::cout << "Функция 1 выполнилась за " << duration.count() << " секунд."
            << std::endl;

  auto start2 = std::chrono::high_resolution_clock::now();
  func2(ref);
  auto end2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration2 = end2 - start2;
  std::cout << "Функция 2 выполнилась за " << duration2.count() << " секунд."
            << std::endl;

  auto start3 = std::chrono::high_resolution_clock::now();
  func3(ptr);
  auto end3 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration3 = end3 - start3;
  std::cout << "Функция 3 выполнилась за " << duration3.count() << " секунд."
            << std::endl;

  auto start4 = std::chrono::high_resolution_clock::now();
  func4(ptr);
  auto end4 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration4 = end4 - start4;
  std::cout << "Функция 4 выполнилась за " << duration4.count() << " секунд."
            << std::endl;

  std::cout << t << std::endl;
  return 0;
}

void func(unsigned int& val) {
  for (int i = 0; i < 1000000000; ++i) {
    ++val;
  }
}
void func2(unsigned int& val) {
  for (int i = 0; i < 1000000000; i++) {
    val++;
  }
}
void func3(unsigned int* val) {
  for (int i = 0; i < 1000000000; ++i) {
    ++(*val);
  }
}
void func4(unsigned int* val) {
  for (int i = 0; i < 1000000000; i++) {
    (*val)++;
  }
}