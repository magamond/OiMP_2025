#include <iostream>

int main(){
  std::cout << "Enter the circumference: ";
  double l;
  std::cin >> l;
  if (l <= 0){
    std::cout << "Error\n";
    return 0;
  }
  double r = l / (2.0 * 3.1415927);
  double s = 3.1415927 * r * r;
  std::cout << "Radius and area of ​​a circle: " << r << ' ' << s << '\n';
  return 0;
}
