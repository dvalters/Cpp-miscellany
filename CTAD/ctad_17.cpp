// This example look at the class template argument deduction
// feature which is present in C++17
//
// This is an example in C++17
#include <string>
#include <pair>

// Normally, when using class templates you have to provide
// the template arguments even when type is obvious from use.
//
// In C++17, you can use the class template argument deduction
void test(int id, std::string const& name)
{
  // C++98
  // std::pair<int, std::string> p(id, name)
  // C++11 
  // auto p(std::make_pair(id, name)
  //
  // The compiler will detect that pair names a class template,
  // but since no template arguments are supplied (< >), it will
  // deduce the arguments from the types used when the constructor
  // is called.
  std::pair p(id, name)
}

// With CTAD, the class type of the variable p is explicit . 

int main()
{
  test(1, "Hello, World!")
}

