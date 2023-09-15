#include <algorithm>
#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>
#include <ostream>
#include <queue>
#include <string>

bool isNumber(const std::string &buffer) {
  if (buffer.size() == 0) {
    return false;
  }
  auto it = buffer.begin();
  while (it != buffer.end()) {
    if (!std::isdigit(*it)) {
      return false;
    }
    it++;
  }
  return true;
}

bool Compare(int64_t a, int64_t b) { return a > b; }
int main() {
  std::ifstream inputFile("input.txt");
  std::string buffer;
  std::priority_queue<int64_t, std::vector<int64_t>,
                      std::function<bool(int64_t, int64_t)>>
      pq(Compare);
  int64_t currentSize = 0;
  while (std::getline(inputFile, buffer)) {
    if (!isNumber(buffer)) {
      pq.push(currentSize);
      if (pq.size() > 3) {
        pq.pop();
      }
      currentSize = 0;
    } else {
      /* std::cout << buffer << "\n"; */
      currentSize += std::stol(buffer);
    }
  }
  inputFile.close();
  int64_t total = 0;
  while (pq.size()) {
    std::cout << pq.top() << ", ";
    total += pq.top();
    pq.pop();
  }
  std::cout << "total: " << total << "\n";
}
