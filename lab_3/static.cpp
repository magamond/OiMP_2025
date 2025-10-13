#include <iostream>
#include <ctime>
#include <cmath>

const int MAX = 100;

void random_arr(double* arr, int& n, int& l, int& r) {
  for (int i = 0; i < n; i++) {
    arr[i] = (l + (r - l) * (rand() / (double)RAND_MAX));
    arr[i] = round(arr[i] * 100) / 100;
  }
}

void input_arr(double* arr, int& n) {
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
    if (abs(arr[i]) > MAX) {
      std::cout << "Error\n";
      exit(0);
    }
  }
}

int main() {
  srand(time(0));
  int n;
  std::cout << "Input the array size: ";
  std::cin >> n;
  if (n != static_cast<int>(n) || n < 1 || n > MAX){
    std::cout << "Error\n";
    return 0;
  }
  double arr[n]{};
  std::cout << "Select the array filling method:\n  0 - Random numbers\n  1 - Input manually\n";
  int in;
  std::cin >> in;
  if (in != static_cast<int>(in) || in < 0 || in > 1) {
    std::cout << "Error\n";
    return 0;
  }
  if (in == 0){
    int l{}, r{};
    std::cout << "Input the boundaries (l and r) of the values in the array: ";
    std::cin >> l >> r;
    if (abs(l) > 100 || abs(r) > 100) {
      std::cout << "Error\n";
      return 0;
    }
    if (l > r) std::swap(l, r);
    random_arr(arr, n, l, r);
    std::cout << "Random array: ";
    for (int i = 0; i < n; i++) {
      std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
  } else {
    std::cout << "Input n real numbers: ";
    input_arr(arr, n);
  }
  double sum{}, maxk{}, mink{}, maxv = 0, minv = 1.0 * MAX;
  for (int i = 0; i < n; i++) {
    if (arr[i] > 0) sum += arr[i];
    if (abs(arr[i]) > maxv) {
      maxk = i;
      maxv = arr[i];
    }
    if (abs(arr[i]) < minv) {
      mink = i;
      minv = arr[i];
    }
  }
  double prod = 1;
  int div = 0;
  for (int i = std::min(mink, maxk); i <= std::max(mink, maxk); i++) {
    prod = (prod * arr[i]);
    div += (int)prod / 10000000;
    while (prod > 1e+7) {
      prod -= 1e+7;
    }
  }
  std::cout << "Sum: " << sum << "\nProduct: " << div * 1e+7 << " + " << prod << '\n';
  for (int i = 0; i < n; i += 2) {
    for (int j = i + 2; j < n; j += 2) {
      if (arr[j] > arr[i]){
        double t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
      }
    }
  }
  std::cout << "Sorted array: ";
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
