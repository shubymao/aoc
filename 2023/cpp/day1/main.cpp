#include <fstream>
#include <iostream>
#include <optional>
#include <stdexcept>
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
  std::unordered_map<std::string, int> lookupList = {
      {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4}, {"five", 5},
      {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"zero", 0},
      {"1", 1},   {"2", 2},     {"3", 3},     {"4", 4},    {"5", 5},
      {"6", 6},   {"7", 7},     {"8", 8},     {"9", 9},    {"0", 0}};
  for (auto s : inputs) {
    std::optional<std::pair<char, int>> first = {}, last = {};
    for (const auto [lookupKey, val] : lookupList) {
      if (auto index = s.find(lookupKey); index != std::string::npos) {
        if (!first.has_value() || (*first).first > index) {
          first = {index, val};
        }
      }
      if (auto index = s.rfind(lookupKey); index != std::string::npos) {
        if (!last.has_value() || (*last).first < index) {
          last = {index, val};
        }
      }
    }
    if (first.has_value() && last.has_value()) {
      res += first.value().second * 10 + last.value().second;
    } else {
      throw std::runtime_error("first and last is missing for input: " + s);
    }
  }
  std::cout << "final result " << res;
}
int main() {
  std::ifstream inputFile("input.txt");
  /* std::ifstream inputFile("dummycase.txt"); */
  /* std::ifstream inputFile("dummy2.txt"); */
  std::string buffer;
  std::vector<std::string> inputs;
  while (std::getline(inputFile, buffer)) {
    inputs.push_back(buffer);
  }
  /* solution(inputs); */
  try {
    solution2(inputs);
  } catch (std::runtime_error e) {
    std::cout << e.what();
  }
  inputFile.close();
}
