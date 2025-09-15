#include <iostream>

int main(){
  setlocale(LC_ALL, "Russian");
  int n;
  std::cout << "Введите трехзачное целое число: ";
  std::cin >> n;
  if (abs(n) < 100 || abs(n) > 999){
    std::cout << "Error\n";
    return 0;
  }
  int hundreds = abs(n / 100);
  int tens = abs((n / 10) % 10);
  int units = abs(n % 10);
  std::cout << "Сумма и произведение цифр: " << hundreds + tens + units << ' ' << hundreds * tens * units << '\n';
  return 0;
}
