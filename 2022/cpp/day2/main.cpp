#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
std::unordered_map<char, char> winComb = {{'A', 'Y'}, {'B', 'Z'}, {'C', 'X'}};
std::unordered_map<char, char> drawComb = {{'A', 'X'}, {'B', 'Y'}, {'C', 'Z'}};
std::unordered_map<char, char> loseComb = {{'A', 'Z'}, {'B', 'X'}, {'C', 'Y'}};
std::unordered_map<char, int> shapeScore = {{'X', 1}, {'Y', 2}, {'Z', 3}};

int calculate(std::pair<char, char> &input) {
  if (winComb[input.first] == input.second) {
    return 6 + shapeScore[input.second];
  }
  if (drawComb[input.first] == input.second) {
    return 3 + shapeScore[input.second];
  }
  return shapeScore[input.second];
}

int calculate2(std::pair<char, char> &input) {
  if (input.second == 'X') {
    return shapeScore[loseComb[input.first]];
  } else if (input.second == 'Y') {
    return shapeScore[drawComb[input.first]] + 3;
  } else {
    return shapeScore[winComb[input.first]] + 6;
  }
}

int main() {
  std::string buffer;
  std::ifstream inputFile("input.txt");
  std::vector<std::pair<char, char>> inputs;
  while (std::getline(inputFile, buffer)) {
    inputs.push_back({buffer[0], buffer[2]});
  }
  int score = 0, score2 = 0;
  for (auto input : inputs) {
    score += calculate(input);
    score2 += calculate2(input);
  }
  std::cout << "Final Result :" << score << "\n";
  std::cout << "Final Result Sol2 :" << score2 << "\n";
  return 0;
}
