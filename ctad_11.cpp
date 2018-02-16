// This example look at the class template argument deduction
// feature which is present in C++17
//
// This is an example in C++11
#include <string>
#include <pair>

// Normally, when using class templates you have to provide
// the template arguments even when type is obvious from use.
//
// In C++11, you can make things a bit easier with the auto
// type deducer, and the built in helper function make_pair
void test(int id, std::string const& name)
{
  //std::pair<int, std::string> p(id, name)
  auto p(std::make_pair(id, name)
}

int main()
{
  test(1, "Hello, World!")
}

