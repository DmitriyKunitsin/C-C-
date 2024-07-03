#include <iostream>
void print(std::string name, unsigned age);
// Аргумент по умолчанию
void print2(std::string name = "Неизвестный", unsigned age = 18);
void print3(int* begin, int* end);
int* max(int* a, int* b);
int& maxRef(int& a, int& b);
void hello();
void goodbye();
int sum(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int operations(int (*)(int, int), int,
               int);  // Первый параметр - указатель на функцию
using BinaryOp = int (*)(int, int);
void do_operation(int a, int b, BinaryOp op);
int (*select(int choice))(int, int);

int main() {
  print("Dima", 27);

  const std::string userName{"Dimon"};
  unsigned userAge{27};
  print(userName, userAge);

  print2("DIMAAN");
  print2("DMAAAAN", 27);
  print2();

  int nums[]{1, 2, 3, 4, 5};
  int* begin{std::begin(nums)};
  int* end{std::end(nums)};

  print3(begin, end);

  std::cout << std::endl;

  int m = 6;
  int k = 10;
  int* maxVal = max(&m, &k);
  std::cout << "max val = " << *maxVal << std::endl;
  std::cout << "max val2 = " << *max(&k, &m) << std::endl;

  int result = maxRef(m, k);
  std::cout << " max ref : " << result << std::endl;

  void (*message)();

  message = hello;
  message();
  message = goodbye;
  message();

  int f = 5;
  int d = 10;
  int (*operation)(int, int){sum};
  int res = operation(d, f);
  std::cout << "res = " << res << std::endl;

  operation = subtract;

  res = operation(d, f);
  std::cout << "res = " << res << std::endl;

  int (*oper[3])(int, int){sum, subtract, multiply};
  unsigned len = std::size(oper);
  for (unsigned i{}; i < len; ++i) {
    int r = oper[i](d, f);
    d = r;
  }

  int r = operations(sum, d, f);
  std::cout << " r = " << r << std::endl;
  r = operations(subtract, d, f);
  std::cout << " r = " << r << std::endl;

  do_operation(10, 17, sum);
  do_operation(22, 24, multiply);

  int (*action)(int, int){select(1)};
  std::cout << action(6, 2) << std::endl;
  action = select(2);
  std::cout << action(6, 2) << std::endl;
  action = select(3);
  std::cout << action(6, 2) << std::endl;

  return 0;
}
void print(std::string name, unsigned age) {
  std::cout << "Name: " << name << "\tAge: " << age << std::endl;
}

// Аргумент по умолчанию
void print2(std::string name, unsigned age) {
  std::cout << "Name: " << name << "\tAge: " << age << std::endl;
}

void print3(int* begin, int* end) {
  for (int* ptr{begin}; ptr != end; ptr++) {
    std::cout << *ptr << "\t";
  }
}

int* max(int* a, int* b) {
  if (*a > *b) {
    return a;
  } else {
    return b;
  }
}

int& maxRef(int& a, int& b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

void hello() { std::cout << "Hello, World" << std::endl; }
void goodbye() { std::cout << "Good Bye, World" << std::endl; }
int sum(int x, int y) {
  std::cout << "x + y = " << x + y << std::endl;
  return x + y;
}
int subtract(int x, int y) {
  std::cout << "x - y = " << x - y << std::endl;
  return x - y;
}
int multiply(int x, int y) {
  std::cout << "x * y = " << x * y << std::endl;
  return x * y;
}
int operations(int (*op)(int, int), int a, int b) { return op(a, b); }

void do_operation(int a, int b, BinaryOp op) {
  double res = op(a, b);
  std::cout << res << std::endl;
}

int (*select(int choice))(int, int) {
  switch (choice) {
    case 1:
      return sum;
    case 2:
      return subtract;
    case 3:
      return multiply;
    default:
      return nullptr;
  }
}