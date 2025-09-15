#include <iostream>
#include <cmath>

int main(){
  setlocale(LC_ALL, "Russian");
  std::cout << "¬ведите площадь окружности: ";
  double s;
  std::cin >> s;
  if (s <= 0){
    std::cout << "Error\n";
    return 0;
  }
  double r = sqrt(s / 3.1415927);
  double l = 2 * r * 3.1415927;
  std:: cout << "ƒиаметр и длинна окружности: " << 2 * r << ' ' << l << '\n';
  return 0;
}
