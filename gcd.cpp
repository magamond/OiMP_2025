#include <bits/stdc++.h>

int gcd(int a, int b){
  while (true){
    if (a >= b){
      a %= b;
    }
    else{
      b %= a;
    }
    if (a == 0){
      return b;
    }
    if (b == 0){
      return a;
    }
  }
}

int main(){
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << '\n';
}
