#include <bits/stdc++.h>

int main(){
  int n;
  std::cin >> n;
  int f = 1;
  double sum = 1;
  for (int i = 2; i <= n; i++){
    f*=i;
    sum+=1.0/f;
  }
  std::cout << sum << '\n';
}
