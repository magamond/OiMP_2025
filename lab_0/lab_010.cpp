#include <iostream>
#include <string>

int main(){
  setlocale(LC_ALL, "Russian");
  int bd, bm, by, cd, cm, cy;
  std::cout << "Дата рождения (день месяц год): ";
  std::cin >> bd >> bm >> by;
  std::cout << "Текущая дата (день месяц год): ";
  std::cin >> cd >> cm >> cy;
  if (bd < 1 || bd > 30 || bm < 1 || bm > 12 || by < 0 ||
      cd < 1 || cd > 30 || cm < 1 || cm > 12 || cy < 0) {
    std::cout << "Error\n";
    return 1;
  }
  int bdays = by * 360 + (bm - 1) * 30 + bd;
  int cdays = cy * 360 + (cm - 1) * 30 + cd;
  if (cdays < bdays) {
    std::cout << "Error\n";
    return 1;
  }
  int diff = cdays - bdays;
  int y = diff / 360;
  int rem = diff % 360;
  int m = rem / 30;
  int d = rem % 30;
  std::cout << "Возраст: " << y << " лет, " << m << " месяцев, " << d << " дней\n";
  return 0;
}
