#include <iostream>
//#include <cxxopts.hpp>
#include "boost/program_options.hpp"
#include "helper.hpp"
using namespace std;
namespace po = boost::program_options;

int main(int argc, char *argv[]){
  // desc = description
  po::options_description desc("Allowed options");
  desc.add_options()
    ("list,l", "list the current processes running background")
    ("help,h", "set compression level");

  // vm = variables map
  po::variables_map vm;

  // try{ 
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);   

    if (vm.count("help")) {
      cout << desc << "\n";
      return 1;
    }

    if (vm.count("list")) {
      // cout << desc << "\n";
      //cout << "list running" << endl;
      system("screen -ls");
      return 1;
    }
    // if(result.count("list") == 1)
    //   cout << result["list"].as<bool>() << endl;
      

    //} // catch(cxxopts::option_not_exists_exception e){
  //   string const err_str = e.what(); 
  //   cout << get_token_from_str(err_str, " ", 2) << endl;
  //   // int first_space = err_str.find(' ');
  //   // int second_space = err_str.find(' ', first_space + 1);
  //   // string parameter_str = err_str.substr(first_space + 1, second_space - first_space - 1);
  //   // cout << "Invalid parameter: " << parameter_str << endl; 
  // }
    

}


