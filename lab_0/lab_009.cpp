#include <iostream>
#include <string>

int main() {
  std::string arrival, departure;
  std::cout << "Arrival time (hours:minutes format): ";
  std::cin >> arrival;
  std::cout << "Departure time (hours:minutes format): ";
  std::cin >> departure;
  int h1 = (arrival[0] - '0') * 10 + (arrival[1] - '0');
  int m1 = (arrival[3] - '0') * 10 + (arrival[4] - '0');
  int h2 = (departure[0] - '0') * 10 + (departure[1] - '0');
  int m2 = (departure[3] - '0') * 10 + (departure[4] - '0');
  int total_minutes1 = h1 * 60 + m1;
  int total_minutes2 = h2 * 60 + m2;
  int difference_minutes;
  if (total_minutes2 >= total_minutes1) {
    difference_minutes = total_minutes2 - total_minutes1;
  } else {
    difference_minutes = (24 * 60 - total_minutes1) + total_minutes2;
  }
  int h = difference_minutes / 60;
  int m = difference_minutes % 60;
  std::cout << "Parking time: " << h << " hours " << m << " minutes\n";
  return 0;
}
