#include <bits/stdc++.h>

int main(){
  setlocale(LC_ALL, "Russian");
  std::cout << "������� 3 ����� �����: ";
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << "����������: " << std::min({a,b,c}) << '\n';
  std::cout << "����������: " << std::max({a,b,c}) << '\n';
  std::cout << "�����: " << a + b + c << '\n';
  std::cout << "������������: " << a*b*c << '\n';
  std::cout << "������� ��������: " << (a+b+c)/3.0 << '\n';
  return 0;
}
