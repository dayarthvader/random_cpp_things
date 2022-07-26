//  Dayarthvader  2022
# include <memory>
namespace random_cpp_things {
class MyString {
  public:
    MyString() = default;
    explicit MyString(size_t);
    explicit MyString(const char*);
    MyString(const random_cpp_things::MyString&);
    MyString(random_cpp_things::MyString&);
    MyString(random_cpp_things::MyString&&);
    random_cpp_things::MyString& operator=(const random_cpp_things::MyString& rhs);
    random_cpp_things::MyString& operator=(random_cpp_things::MyString&& rhs);
    random_cpp_things::MyString  operator+(const random_cpp_things::MyString&); 
    void ReverseInplace();
    random_cpp_things::MyString Reverse();


  private:
    size_t _strlen(const char*);
    std::unique_ptr<char> _value{nullptr};
    size_t _len{0};
};
}  //  namespace random_cpp_things
