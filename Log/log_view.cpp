////////////////////////////////////////////////////////////
//                                                        //
// Author: Brendon Roberto                                //
// Project: CS23001 CS II Summer 2013                     //
//                                                        //
// log_view.cpp                                           //
// Implements helpful functions for parsing Apache logs.  //
//                                                        //
////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "log_view.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::atoi;

string remove(const string&, const string&);

vector<string> split(const string& source, char delimiter) {
    // Variable declarations
    string::size_type next_idx, last_idx;
    string str_delimiter;
    vector<string> result;

    // Convert char delimiter to string
    str_delimiter = string(1, delimiter);

    // Seek through source string, extracting substrings between delimiters
    for(last_idx = 0; (next_idx = source.find(str_delimiter, last_idx)) != string::npos; last_idx = next_idx + str_delimiter.length()) {
        string substr;

        substr = source.substr(last_idx, next_idx - last_idx);
        result.push_back(substr);
    }

    result.push_back(source.substr(last_idx, source.length() - last_idx));

    return result;
}

Log_Entry create_Log_Entry(const string& source) {
    Log_Entry result;
    vector<string> log_vec, datetime_vec, date_vec, time_vec;
    Date logdate;
    Time logtime;
    string request;
    string status;
    int number_of_bytes;

    // Split source string on spaces into constituent parts
    log_vec = split(source, ' ');
    
    // Make sure that log_vec has 10 entries
    if(log_vec.size() < 10) {
        result._number_of_bytes = 0;
        return result;
    }

    // Split substring on colons to get timestamps
    datetime_vec = split(log_vec.at(3), ':');

    // Split substring from datetime_vec on slashes and open brackets to get days in date
    date_vec = split(remove(datetime_vec.at(0), "["), '/');

    // Construct time_vec from values stored in datetime_vec
    time_vec.push_back(datetime_vec.at(1));
    time_vec.push_back(datetime_vec.at(2));
    time_vec.push_back(datetime_vec.at(3));

    // Get request from source
    request = split(source, '"').at(1);
    
    // Get status from log_vec
    status = log_vec.at(8);

    // Get number of bytes from log_vec
    number_of_bytes = atoi(log_vec.at(9).c_str());

    // Populate Log_Entry members
    result._host = log_vec.at(0);
    result._date.day = date_vec.at(0);
    result._date.month = date_vec.at(1);
    result._date.year = atoi(date_vec.at(2).c_str());
    result._time.hour = atoi(time_vec.at(0).c_str());
    result._time.minute = atoi(time_vec.at(1).c_str());
    result._time.second = atoi(time_vec.at(2).c_str());
    result._request = request;
    result._status = status;
    result._number_of_bytes = number_of_bytes;
    return result;
}

string remove(const string& source, const string& target) {
    string::size_type next_idx, last_idx;

    // Copy result    
    string result = string(source);

    // Initialize last_idx
    last_idx = 0;

    while((next_idx = source.find(target, last_idx)) != string::npos) {
        // Erase the found substring from result
        result.erase(next_idx, target.length());

        // Advance last_idx to next position
        last_idx = next_idx + target.length();
    }
    return result;
}

vector<Log_Entry> parse(const string& filename) {
    vector<Log_Entry> result;

    return result;
}
/*
void output_all(const vector<Log_Entry>& entries) {
    return 1;
}

int byte_count(const vector<Log_Entry>& entries) {
    return 1;
}

void output_hosts(const vector<Log_Entry>& entries) {
    return 1;
}
*/
