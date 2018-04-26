#ifndef _Helper
#define _Helper

#include <string>
#include <exception>

/*
Extract the token number "token_num" from the string "str" 
while keeping the separator string "separator".
Indexing of the tokens starts from 0
*/
std::string get_token_from_str(std::string str, std::string separator, int token_num);

// Thrown when function get_token_from_str is asked to return a token out of range
class token_out_of_range_error: public std::exception{
  virtual const char* what() const throw();
};

#endif
