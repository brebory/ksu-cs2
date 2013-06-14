//  split test
//
//   DO NOT CHANGE ANYTHING IN THIS FILE.
//
//  @author Dale Haverstock
//

//==============================================================================
#ifdef CS2_STRING
  #include "string.h"
  using cs33001::string;
#else
  #include <string>
  using std::string;
#endif

//==============================================================================
#include "log_view.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
using std::cin;
using std::cout;
using std::cerr;
using std::setw;
using std::vector;

//==============================================================================
int main(int argc, char* argv[])
{
    // Command line arguments required
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " string char\n";
        exit(1);
    }

    // Get test values
    string str(argv[1]);
    char   chr = argv[2][0];

    // Do the split
    vector<string> vec = split(str, chr);

    // Output strings
    for (vector<int>::size_type idx = 0; idx < vec.size(); ++idx)
        cout << setw(2) << idx << "   \"" << vec[idx] << "\"\n";
}

