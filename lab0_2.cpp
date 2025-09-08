#include <bits/stdc++.h>

int main(){
  setlocale(LC_ALL, "Russian");
  std::cout << "Введите 3 целых числа: ";
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << "Наименьшее: " << std::min({a,b,c}) << '\n';
  std::cout << "Наибольшее: " << std::max({a,b,c}) << '\n';
  std::cout << "Сумма: " << a + b + c << '\n';
  std::cout << "Произведение: " << a*b*c << '\n';
  std::cout << "Среднее значение: " << (a+b+c)/3.0 << '\n';
  return 0;
}
