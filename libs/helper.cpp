#include <boost/tokenizer.hpp>
#include <string>

using namespace std;
using namespace boost;

// Token numbers start from 0
string get_token_from_str(string str, string separator, int token_num){
  const char * const_str = separator.c_str();
  //const string const_str = separator;
  char_separator<char> sep(const_str);
  tokenizer< char_separator<char> > tok(str, sep);
  tokenizer< char_separator<char> >::iterator beg=tok.begin();
  //beg = beg + token_num;
  for(int i = 0; i < token_num; i++)
    beg++;

  return *beg;
}
