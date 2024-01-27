#include <cstdint>
#include <fstream>
#include <iostream>
#include <optional>
#include <string>

void solution(std::vector<std::string> &inputs) {
  int res = 0;
  for (auto s : inputs) {
    std::optional<char> first = {}, last = {};
    for (auto c : s) {
      if (c >= '0' && c <= '9') {
        if (first.has_value()) {
          last = c;
        } else {
          first = c;
          last = c;
        }
      }
    }
    if (first.has_value() && last.has_value()) {
      res += (first.value() - '0') * 10 + (last.value() - '0');
    }
  }
  std::cout << "final result " << res;
}

void solution2(std::vector<std::string> &inputs) {
  int res = 0;
  for (auto s : inputs) {
    std::optional<char> first = {}, last = {};
    for (auto c : s) {
    }
    if (first.has_value() && last.has_value()) {
      res += (first.value() - '0') * 10 + (last.value() - '0');
    }
  }
  std::cout << "final result " << res;
}
bool Compare(int64_t a, int64_t b) { return a > b; }
int main() {
  std::ifstream inputFile("input.txt");
  /* std::ifstream inputFile("dummycase.txt"); */
  std::string buffer;
  std::vector<std::string> inputs;
  while (std::getline(inputFile, buffer)) {
    inputs.push_back(buffer);
  }
  solution(inputs);
  inputFile.close();
}
