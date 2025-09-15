#include <iostream>
#include <cmath>

int main(){
  setlocale(LC_ALL, "Russian");
  std::cout << "Введите координаты вершин треугольника: ";
  int x1, x2, x3, y1, y2, y3;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  double a, b, c;
  a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
  c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
  double p = (a + b + c) / 2;
  double s = sqrt(p * (p - a) * (p - b) * (p - c));
  std::cout << "Площадь треугольника: " << s << '\n';
  return 0;
}
