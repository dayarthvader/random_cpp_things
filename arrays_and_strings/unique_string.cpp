// Find if the string contains unique characters
// Invariants - ASCII or UNICODE ?

#include <cstring>
#include <iostream>
#include <map>
#include <string>

static const int kCharacterSetLen{128 /*256 otherwise*/};

bool has_unique_memoize(const char* input, int len) {
  std::map<char, int> char_map;
  for (int i = 0; i < len; i++) {
    if (char_map.find(input[i]) == char_map.end()) {
      char_map[input[i]] = i;
    } else {
      return false;
    }
  }
  return true;
}

bool has_unique_basic(const char* input, int len) {
  if (len > kCharacterSetLen) {
    return false;
  }
  //  The case where no extra data structures are used.
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (input[j] == input[i]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  std::string input_str{""};
  std::cin >> input_str;
  auto len = input_str.size();
  if (has_unique_basic(input_str.c_str(), len)) {
    std::cout << input_str << " is unique\n";
  } else {
    std::cout << input_str << " is not unique\n";
  }
}
