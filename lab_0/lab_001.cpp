#include <iostream>

int main(){
  setlocale(LC_ALL, "Russian");
  int a;
  std::cout << "¬ведите натуральное число: ";
  if (a <= 0){
    std::cout << "Error\n";
    return 0;
  }
  std::cin >> a;
  std::cout << "ѕериметр и площадь квадрата: " << a * 4 << ' ' << a * a;
  return 0;
}
