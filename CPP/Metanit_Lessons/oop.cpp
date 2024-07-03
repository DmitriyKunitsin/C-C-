#include <iostream>

class Person {
 private:
  std::string name{"Undefined"};
  unsigned age{18};
  static inline unsigned count{};

 public:
  void print() {
    std::cout << "Name : " << name << " Age : " << age << std::endl;
  }
  Person(std::string _name, unsigned _age) {
    age = _age;
    name = _name;
    ++count;
    std::cout << "Person has been created" << std::endl;
    std::cout << "First construct" << std::endl;
  }
  Person(std::string _name) : Person(_name, 18) {
    std::cout << "Second construct" << std::endl;
  }
  Person() : Person(std::string("Undefined")) {
    std::cout << "Person has void created" << std::endl;
    std::cout << "Third construct " << std::endl;
  }
  Person(const Person& p);
  void setName(std::string _name);
  void setAge(int _age);
  std::string getName();
  unsigned getAge();

  void constPrint() const;
  static void printCount() {
    std::cout << "Всего объектов класса Person : " << count << std::endl;
  }
};

void Person::constPrint() const {
  std::cout << "Name: " << name << "\tAge: " << age << std::endl;
}
Person::Person(const Person& p) {  // конструктор копирования
  name = p.name;
  age = p.age + 1;
}
void Person::setName(std::string _name) { name = _name; }
void Person::setAge(int _age) {
  if (_age > 0 && _age < 110) {
    age = _age;
  }
}
std::string Person::getName() { return name; }
unsigned Person::getAge() { return age; }

class Points {
 private:
  int x;
  int y;

 public:
  Points(int x, int y);
  ~Points();
  void ShowCoord();
  Points& move(int x, int y) {
    this->x += x;
    this->y += y;
    return *this;
  }
};
void Points::ShowCoord() {
  std::cout << "Point x: " << this->x << "\t y: " << this->y << std::endl;
}
Points::Points(int x, int y) {
  this->x = x;
  this->y = y;
}

Points::~Points() {}

class Intager {
 private:
  int value;

 public:
  Intager(int number);
  ~Intager();
  Intager& add(const Intager& obj) {
    value += obj.value;
    return *this;
  }
  Intager& substract(const Intager& obj) {
    value -= obj.value;
    return *this;
  }
  Intager& multiply(const Intager& obj) {
    value *= obj.value;
    return *this;
  }
  void print() { std::cout << "Value : " << value << std::endl; }
};

Intager::Intager(int _number) { value = _number; }

Intager::~Intager() {}

int main() {
  Person person;
  person.print();

  Person* ptr = &person;

  ptr->print();
  Person person2("Dimon", 27);
  person2.print();
  std::cout << "_________________________" << std::endl;
  Person dima;
  dima.print();
  dima.setName("DIMON");
  dima.setAge(27);
  std::cout << "Person name : " << dima.getName()
            << " Person age : " << dima.getAge() << std::endl;
  dima.print();
  Person dimon{dima};
  dimon.print();
  const Person serega{"Setega", 26};
  serega.constPrint();

  Points p1{20, 5};
  p1.ShowCoord();
  p1.move(10, 29).move(21, 11);
  p1.ShowCoord();

  Intager num{10};
  num.add(Intager{30}).substract(Intager{15}).multiply(Intager{2});
  num.print();

  dimon.printCount();
  Person::printCount();

  return 0;
}