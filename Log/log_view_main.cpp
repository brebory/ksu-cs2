//  Apache Log File Processor
//   
//  DO NOT CHANGE ANYTHING IN THIS FILE.
//
//  @author: Dale Haverstock

//==============================================================================
#include "log_view.h"

#include <iostream>
#include <vector>
#include <cstdlib>

#ifdef CS2_STRING
  #include "string.hpp"
  using cs33001::string;
#else
  #include <string>
  using std::string;
#endif

using std::cin;
using std::cerr;
using std::cout;
using std::vector;

//==============================================================================
int main(int argc, char *argv[])
{
    // The options: all, byte count, and hosts
    vector<string> opt(3);
    opt[0] = "-a";
    opt[1] = "-c";
    opt[2] = "-h";

    // Command line option required
    if (argc <= 2)
    {
         cerr << ">> usage: " << argv[0] << " ";
         for (vector<string>::size_type idx = 0; idx < opt.size() - 1; ++idx)
             cerr << opt[idx] << " | ";
         cerr << opt[opt.size() - 1]  << " log_file  "<< " \n";
         exit(1);
    }

    // Get file name
    string file_name(argv[2]);

    // Process log entry file
    vector<Log_Entry> log_entries = parse(file_name);

    // Get first command line arg, the option
    string option(argv[1]);

    // Do selected option
    if (option == opt[0])
    {
        output_all(log_entries);
        cout << "\n";
    }
    else if (option == opt[1])
    {
        int count = byte_count(log_entries);
        cout << "Total number of bytes sent: " 
             << count << "\n";
    }
    else if (option == opt[2])
    {
        output_hosts(log_entries);
        cout << "\n";
    }
    else
    {
        cerr << "Unrecognized option: " << option << "\n";
        cerr << "Recognized options: " 
             << opt[0] << " "
             << opt[1] << " "
             << opt[2] << "\n";
    }

    return 0;
}

