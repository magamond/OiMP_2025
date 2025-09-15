#include <iostream>

int main(){
  int a;
  std::cout << "Enter a natural number: ";
  if (a <= 0){
    std::cout << "Error\n";
    return 0;
  }
  std::cin >> a;
  std::cout << "Perimeter and area of ​​a square: " << a * 4 << ' ' << a * a;
  return 0;
}
