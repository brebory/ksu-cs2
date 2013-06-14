// Apache Log File Processor
//   
//  DO NOT CHANGE ANYTHING IN THIS FILE.
//
// Tests: split function
//
//  @author: Dale Haverstock
//
//  Note: In each test the assert for the vector size is first, why?
//

//==============================================================================
#include "log_view.h"
#include <cassert>
#include <string>
#include <vector>

//==============================================================================
int main()
{
    {
	//----------------------------------------------------------------------	
	//SETUP FIXTURE
	std::string str("AB CD");

	// TEST
	std::vector<std::string> vec = split(str, ' ');	

	// VERIFY
	assert(vec.size() == 2);
	assert(vec[0] == "AB");
	assert(vec[1] == "CD");
    }

    {
	//----------------------------------------------------------------------	
	//SETUP FIXTURE
	std::string str("AB:CD");

	// TEST
	std::vector<std::string> vec = split(str, ':');	

	// VERIFY
	assert(vec.size() == 2);
	assert(vec[0] == "AB");
	assert(vec[1] == "CD");
    }

    {
	//----------------------------------------------------------------------	
	//SETUP FIXTURE
	std::string str("AB CD");

	// TEST
	std::vector<std::string> vec = split(str, 'C');	

	// VERIFY
	assert(vec.size() == 2);
	assert(vec[0] == "AB ");
	assert(vec[1] == "D");
    }

    {
	//----------------------------------------------------------------------	
	//SETUP FIXTURE
	std::string str("AB");

	// TEST
	std::vector<std::string> vec = split(str, ' ');	

	// VERIFY
	assert(vec.size() == 1);
	assert(vec[0] == "AB");
    }

    {
	//----------------------------------------------------------------------	
	//SETUP FIXTURE
	std::string str;

	// TEST
	std::vector<std::string> vec = split(str, ' ');	

	// VERIFY
	assert(vec.size() == 1);
    }	

    {
	//----------------------------------------------------------------------	
	//SETUP FIXTURE
	std::string str("AB CD");

	// TEST
	std::vector<std::string> vec = split(str, 'a');	

	// VERIFY
	assert(vec.size() == 1);
	assert(vec[0] == "AB CD");
    }

    {
	//----------------------------------------------------------------------	
	//SETUP FIXTURE
	std::string str("A");

	// TEST
	std::vector<std::string> vec = split(str, ' ');	

	// VERIFY
	assert(vec.size() == 1);
	assert(vec[0] == "A");
    }

    {
	//----------------------------------------------------------------------	
	//SETUP FIXTURE
	std::string str(" ");

	// TEST
	std::vector<std::string> vec = split(str, ' ');	

	// VERIFY
	assert(vec.size() == 2);
	assert(vec[0] == "");
	assert(vec[1] == "");
    }

    {
	//----------------------------------------------------------------------	
	//SETUP FIXTURE
	std::string str("AB CD EF G");

	// TEST
	std::vector<std::string> vec = split(str, 'G');	

	// VERIFY
	assert(vec.size() == 2);
	assert(vec[0] == "AB CD EF ");
	assert(vec[1] == "");
    }

    {
	//----------------------------------------------------------------------	
	//SETUP FIXTURE
	std::string str("AB CD EF G");

	// TEST
	std::vector<std::string> vec = split(str, 'A');	

	// VERIFY
	assert(vec.size() == 2);
	assert(vec[0] == "");
	assert(vec[1] == "B CD EF G");
    }

    {
	//----------------------------------------------------------------------	
	//SETUP FIXTURE
	std::string str("AB CD123456789012345678901234567890 EF G");

	// TEST
	std::vector<std::string> vec = split(str, 'D');	

	// VERIFY
	assert(vec.size() == 2);
	assert(vec[0] == "AB C");
	assert(vec[1] == "123456789012345678901234567890 EF G");
    }
}

