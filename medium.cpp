#include <bits/stdc++.h>

int main(){
  int n;
  std::cin >> n;
  int s[n];
  for (int i = 0; i < n; i++){
    std::cin >> s[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++){
    sum += s[i];
  }
  std::cout << (double)sum/n << '\n';
}
