#include <iostream>
#include <cxxopts.hpp>

using namespace std;
int main(int argc, char *argv[]){

  cxxopts::Options options("guiter", "Frictionless Terminal to GUI Interaction");
  options.add_options()
  ("l,list", "Enable debugging");
  
  try{ 
    auto result = options.parse(argc, argv);

    if(result.count("list") == 1)
      cout << result["list"].as<bool>() << endl;

  } catch(cxxopts::option_not_exists_exception e){
    string const err_str = e.what(); 
    int first_space = err_str.find(' ');
    int second_space = err_str.find(' ', first_space + 1);
    string parameter_str = err_str.substr(first_space + 1, second_space - first_space - 1);
    cout << "Invalid parameter: " << parameter_str << endl; 
  }
    

}
