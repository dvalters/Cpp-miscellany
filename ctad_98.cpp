// This example look at the class template argument deduction
// feature which is present in C++17
//
// This is an example in C++98
#include <string>
#include <pair>

// Normally, when using class templates you have to provide
// the template arguments even when type is obvious from use:
void test(int id, std::string const& name)
{
  std::pair<int, std::string> p(id, name)
}

int main()
{
  test(1, "Hello, World!")
}

