#include <iostream>
#include <cmath>

int main(){
  std::cout << "Enter the area of ​​the circle: ";
  double s;
  std::cin >> s;
  if (s <= 0){
    std::cout << "Error\n";
    return 0;
  }
  double r = sqrt(s / 3.1415927);
  double l = 2 * r * 3.1415927;
  std:: cout << "Diameter and circumference: " << 2 * r << ' ' << l << '\n';
  return 0;
}
