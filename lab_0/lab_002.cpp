#include <iostream>

int main(){
  setlocale(LC_ALL, "Russian");
  std::cout << "Введите целое трехзначное число: ";
  int n;
  std::cin >> n;
  if (abs(n) < 100 || abs(n) > 999){
    std:: cout << "Error\n";
    return 0;
  }
  int num = n / 100;
  n %= 100;
  n *= 10;
  n += num;
  std::cout << n << '\n';
  return 0;
}
