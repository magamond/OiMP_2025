#include <iostream>

int main(){
  int n;
  std::cout << "Please enter a three-digit integer: ";
  std::cin >> n;
  if (abs(n) < 100 || abs(n) > 999){
    std::cout << "Error\n";
    return 0;
  }
  int hundreds = abs(n / 100);
  int tens = abs((n / 10) % 10);
  int units = abs(n % 10);
  std::cout << "Sum and product of digits: " << hundreds + tens + units << ' ' << hundreds * tens * units << '\n';
  return 0;
}
