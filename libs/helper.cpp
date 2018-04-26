#include <boost/tokenizer.hpp>
#include <string>
#include <iostream>
#include "helper.hpp"
#include <exception>

using namespace boost;

// Token numbers start from 0
std::string get_token_from_str(std::string str, std::string separator, int token_num){
  const char * const_str = separator.c_str();
  char_separator<char> sep(const_str);
  tokenizer< char_separator<char> > tok(str, sep);
  tokenizer< char_separator<char> >::iterator beg=tok.begin();
  tokenizer< char_separator<char> >::iterator end=tok.end();

  int i = 0;
  do{
    if(token_num == i)
      return *beg;
    beg++;
    i++;
  }
  while(beg != end);

  // for (int i = 0; beg != end; beg++){
  //     }

  throw token_out_of_range_error();
  // std::cout << tok.end() << std::endl;
  // for(int i = 0; i < token_num; i++)
  //   beg++;
  // return *beg;
}

const char* token_out_of_range_error::what() const throw(){
  return "Not allowed: Token out of range is being accessed";
}

// class token_out_of_range_error: public std::exception
// {
//   virtual const char* what() const throw()
//   {
//     return "Not allowed: Token out of range is being accessed";
//   }
// };
