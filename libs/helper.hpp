#ifndef _Helper
#define _Helper

#include <string>

/*
Extract the token number "token_num" from the string "str" 
while keeping the separator string "separator".
Indexing of the tokens starts from 0
*/
std::string get_token_from_str(std::string str, std::string separator, int token_num);

#endif
