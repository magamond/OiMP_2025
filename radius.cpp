#include <bits/stdc++.h>

int main(){
  double r1, r2;
  std::cin >> r1 >> r2;
  int dx, dy;
  std::cin >> dx >> dy;
  double d;
  d = sqrt(pow(dx, 2) + pow(dy, 2));
  if (d > r2){
    std::cout << "d3\n";
  }
  else if (d > r1){
    std::cout << "d2\n";
  }
  else{
    std::cout << "d1\n";
  }
}
