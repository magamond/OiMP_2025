// корректный ввод по условию.
#include <iostream>
#include <fstream>
#include <type_traits>
#include <string>
#include <cmath>
#include <stdlib.h>

void solve(std::string);
int sumOfDigits(int32_t);
int32_t magic(int32_t);
int32_t magic(int32_t, int32_t);
double magic(double, double);
template <typename T> void printResult(std::string, char, T (*operation)(T, T));

int main() {
    solve("integers.txt");
    solve("double.txt");
    return 0;
}

void solve(std::string type) {
    std::ifstream fin(type);
    if (!fin.is_open()) {
        std::cerr << "Cannot open file: " << type << std::endl;
        return;
    }
    char separator = fin.get();
    std::string str1{}, str{};
    while (std::getline(fin, str1)) {
        str += str1;
    }
    if (type == "integers.txt") {
        printResult<int32_t>(str, separator, static_cast<int32_t(*)(int32_t, int32_t)>(magic));
    }
    else {
        printResult<double>(str, separator, static_cast<double (*)(double, double)>(magic));
    }
    fin.close();
    std::cout << '\n';
}

int sumOfDigits(int32_t num) {
    int32_t sum{};
    num = abs(num);
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int32_t magic(int32_t num) {
    return sumOfDigits(num);
}

int32_t magic(int32_t num1, int32_t num2) {
    return (sumOfDigits(num1) > sumOfDigits(num2) ? num1 : num2);
}

double magic(double num1, double num2) {
    double frac1 = std::abs(num1 - std::floor(num1));
    double frac2 = std::abs(num2 - std::floor(num2));
    return (frac1 > frac2 ? num1 : num2);
}

template <typename T> void printResult(std::string str, char separator, T(*operation)(T, T)) {
    T* arr = new T[str.size() / 2 + 1];
    size_t start = 0, end = 0, arrSize = 0;
    while (start < str.size()) {
        end = str.find(separator, start);
        if (end == std::string::npos) {
            end = str.size();
        }
        if (end > start) {
            if constexpr (std::is_same_v<T, double>) {
                arr[arrSize] = std::stod(str.substr(start, end - start));
            }
            else {
                arr[arrSize] = std::stoi(str.substr(start, end - start));
            }
            ++arrSize;
        }
        start = end + 1;
    }
    for (size_t i = 1; i < arrSize - 1; ++i) {
        if ((operation(arr[i - 1], arr[i]) == arr[i - 1]) && (operation(arr[i], arr[i + 1]) == arr[i + 1])) {
            std::cout << arr[i] << ' ';
        }
    }
    delete[] arr;
}
