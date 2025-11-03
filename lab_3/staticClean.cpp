#include <iostream>
#include <ctime>
#include <cmath>

const int MAX = 100;
const int MOD = 1e+7;

void random_arr(double* arr, int& n, int& l, int& r);
void input_arr(double* arr, int& n);
void validate_array_size(double n1);
void validate_menu_choice(int in);
void validate_boundaries(int l, int r);
void process_array(double* arr, int n);
void sort_array(double* arr, int n);

int main() {
  srand(time(0));
  try {
    double n1;
    std::cout << "Input the array size: ";
    if (!(std::cin >> n1)) {
      throw "Error";
    }
    validate_array_size(n1);
    int n = round(n1);
    double arr[MAX]{};
    std::cout << "Select the array filling method:\n  0 - Random numbers\n  1 - Input manually\n";
    int in;
    if (!(std::cin >> in)) {
      throw "Error";
    }
    validate_menu_choice(in);
    if (in == 0) {
      int l{}, r{};
      std::cout << "Input the boundaries (l and r) of the values in the array: ";
      if (!(std::cin >> l >> r)) {
        throw "Error";
      }
      validate_boundaries(l, r);
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
    process_array(arr, n);
    sort_array(arr, n);
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
      std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
  } catch (const char* error) {
    std::cout << error << '\n';
    return 0;
  }
  return 0;
}

void random_arr(double* arr, int& n, int& l, int& r) {
  for (int i = 0; i < n; i++) {
    arr[i] = (l + (r - l) * (rand() / (double)RAND_MAX));
    arr[i] = round(arr[i] * MAX) / MAX;
  }
}

void input_arr(double* arr, int& n) {
  for (int i = 0; i < n; i++) {
    if (!(std::cin >> arr[i])) {
      throw "Error";
    }
    if (abs(arr[i]) > MAX) {
      throw "Error";
    }
  }
}

void validate_array_size(double n1) {
  int n = round(n1);
  if (n < 1 || n > MAX) {
    throw "Error";
  }
}

void validate_menu_choice(int in) {
  if (in < 0 || in > 1) {
    throw "Error";
  }
}

void validate_boundaries(int l, int r) {
  if (abs(l) > 100 || abs(r) > 100) {
    throw "Error";
  }
}

void process_array(double* arr, int n) {
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
  for (int i = std::min(mink, maxk) + 1; i <= std::max(mink, maxk) - 1; i++) {
    prod = (prod * arr[i]);
    div += (int)prod / MOD;
    while (prod > MOD) {
      prod -= MOD;
    }
  }
  std::cout << "Sum: " << sum << "\nProduct: ";
  if (div != 0) {
    std::cout << div * 1e+7 << " + " << prod << '\n';
  } else {
    std:: cout << prod << '\n';
  }
}

void sort_array(double* arr, int n) {
  for (int i = 0; i < n; i += 2) {
    for (int j = i + 2; j < n; j += 2) {
      if (arr[j] > arr[i]){
        double t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
      }
    }
  }
}
