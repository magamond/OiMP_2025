#include <iostream>

int main(){
  setlocale(LC_ALL, "Russian");
  std::cout << "������� ����� ����������: ";
  double l;
  std::cin >> l;
  if (l <= 0){
    std::cout << "Error\n";
    return 0;
  }
  double r = l / (2.0 * 3.1415927);
  double s = 3.1415927 * r * r;
  std::cout << "������ � ������� ����������: " << r << ' ' << s << '\n';
  return 0;
}
