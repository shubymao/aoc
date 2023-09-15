#include <algorithm>
#include <fstream>
#include <iostream>
#include <ostream>
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

int main() {
  std::ifstream inputFile("input.txt");
  std::string buffer;
  int64_t maxSize = 0, maxIndex = -1, currentSize = 0, index = 0;
  while (std::getline(inputFile, buffer)) {
    if (!isNumber(buffer)) {
      if (maxSize < currentSize) {
        maxIndex = index;
        maxSize = currentSize;
      }
      index++;
      currentSize = 0;
    } else {
      /* std::cout << buffer << "\n"; */
      currentSize += std::stol(buffer);
    }
  }
  std::cout << maxSize << "\n";
  inputFile.close();
}
