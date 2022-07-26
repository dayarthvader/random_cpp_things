//  Dayarthvader 2022
#include <iostream>
#include <utility>
#include <cstring>
#include "strings.h"

int main() {
  // contstructor demonstration
  random_cpp_things::MyString default_constructed;
  random_cpp_things::MyString parameterised_constructed("Param constructed string");
  random_cpp_things::MyString copy_constructed(parameterised_constructed);
  random_cpp_things::MyString move_constructed(std::move(random_cpp_things::MyString("Move Constructed")));
  random_cpp_things::MyString copy_assigned; 
  copy_assigned = copy_constructed;
  random_cpp_things::MyString move_assigned; 
  move_assigned = move_constructed;

  random_cpp_things::MyString for_reserval{"random_cpp_things_test_string"};
  for_reserval.ReverseInplace();
  for_reserval.Reverse();
  for_reserval + move_constructed;
  auto append = for_reserval + move_constructed;
  // destructors of 4 constructed and 2 assigned should be called here
  return 0;
}

random_cpp_things::MyString::MyString(const char* param) {  
   if (! param)
      return;
  _len = _strlen(param);
  _value = std::unique_ptr<char>(new char [_len + 1 ]);
  _value.get()[_len] = '\0';
  for (auto i = 0 ; i < _len ; i++) {
   _value.get()[i] = param[i];
  }
  std::cout << "Parameterised Ctor: " << _value.get() <<'\n'; 
}

random_cpp_things::MyString::MyString(size_t len) {
  _len = len;
  _value = std::unique_ptr<char>(new char [_len + 1]);
  _value.get()[_len] = '\0';
}

random_cpp_things::MyString::MyString(const random_cpp_things::MyString& rhs) {
  _len = rhs._len;
  _value = std::unique_ptr<char>(new char [_len + 1 ]);
  _value.get()[_len] = '\0';
  for (auto i = 0 ; i < _len ; i++) {
   _value.get()[i] = rhs._value.get()[i];
  }
  std::cout << "Copy Constructed Ctor: " << _value.get() <<'\n'; 
}

random_cpp_things::MyString::MyString(random_cpp_things::MyString& rhs) {
  _len = rhs._len;
  _value = std::unique_ptr<char>(new char [_len + 1 ]);
  _value.get()[_len] = '\0';
  for (auto i = 0 ; i < _len ; i++) {
   _value.get()[i] = rhs._value.get()[i];
  }
  std::cout << "Copy Constructed Ctor: " << _value.get() <<'\n'; 
}

random_cpp_things::MyString::MyString(random_cpp_things::MyString&& rhs) {
  _len = rhs._len;
  _value = std::move(rhs._value);
  std::cout << "move Constructed Ctor: " << _value.get() <<'\n'; 
  rhs._value = nullptr;
  rhs._len = 0;
}

random_cpp_things::MyString& random_cpp_things::MyString::operator= (const random_cpp_things::MyString& rhs) {
  _len = rhs._len;
  _value = std::unique_ptr<char>(new char [_len + 1 ]);
  _value.get()[_len] = '\0';
  for (auto i = 0 ; i < _len ; i++) {
   _value.get()[i] = rhs._value.get()[i];
  }
  std::cout << "copy assigned Oprtr: " << _value.get() <<'\n'; 
  return *this;
}

random_cpp_things::MyString& random_cpp_things::MyString::operator= (random_cpp_things::MyString&& rhs) {
  _len = rhs._len;
  _value = std::move(rhs._value);
  std::cout << "move assigned Oprtr: " << _value.get() <<'\n'; 
  rhs._value = nullptr;
  rhs._len = 0;
  return *this;
}

void random_cpp_things::MyString::ReverseInplace() {
  if (!_len || ! _value)
    // Raise expection?
    return;

  std::cout << "Original: " << _value.get() <<'\n';
  auto front = 0;
  auto back = _len - 1;
  while (front != back) {
    auto temp = _value.get()[front];
    _value.get()[front] = _value.get()[back];
    _value.get()[back] = temp;
    front++;
    back--;
  }
  std::cout << "Reversed Inplace: " << _value.get() <<'\n';
}

random_cpp_things::MyString  random_cpp_things::MyString::Reverse() {
  std::cout << "Original: " << _value.get() <<'\n';
  char reverse[_len + 1];
  size_t src = 0;
  size_t dst = _len-1;
  reverse[_len] = '\0';
  while (_value.get()[src] != '\0' ) {
   reverse[dst] = _value.get()[src];
   src++; 
   dst--;
  }
   std::cout << "Reversed : " << reverse <<'\n';
   return random_cpp_things::MyString(reverse);
}

size_t random_cpp_things::MyString::_strlen(const char* param) {
    if (! param)
      return 0;
    size_t i = 0;
    while (param[i] != '\0') {
      i++;
    }
    return i;
}

random_cpp_things::MyString random_cpp_things::MyString::operator+(const random_cpp_things::MyString& other) {
  std::cout << "string 1: " << _value.get() << " string 2: " << other._value.get() << '\n';
  auto total_len = _len + other._len;
  random_cpp_things::MyString temp(total_len);
  std::memcpy(temp._value.get(),_value.get(),_len);
  std::memcpy(temp._value.get() + _len, other._value.get(), other._len);
  std::cout << "Appended:" << temp._value.get() << '\n';
  return temp;
}
 
