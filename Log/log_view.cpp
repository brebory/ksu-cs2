/*
 * Author: Brendon Roberto
 * Project: CS23001 CS II Summer 2013
 *
 * log_view.cpp
 * Implements helpful functions for parsing Apache logs.
 *
 */

#include <string>
#include <iostream>
#include "log_view.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

vector<string> split(const string& source, char delimiter) {
    // Variable declarations
    string::size_type next_idx, last_idx;
    string str_delimiter;
    vector<string> result;

    // Convert char delimiter to string
    str_delimiter = string(1, delimiter);

    // Initialize last_idx
    last_idx = 0;

    // Seek through source string, extracting substrings between delimiters
    while((next_idx = source.find(str_delimiter, last_idx)) != string::npos) {
        string substr;

        substr = source.substr(last_idx, next_idx - last_idx);

        result.push_back(substr);

        // Advance last_idx to next position
        last_idx = next_idx + str_delimiter.length();
    }

    result.push_back(source.substr(last_idx, source.length() - last_idx));

    return result;
}

Log_Entry create_Log_Entry(const string& source) {
    Log_Entry result;
    vector<string> log_vec, date_vec;
    Date logdate;

    result = new Log_Entry;
    source_vec = split(source, ' ');
    
    result._host = source_vec.at(0);
    return result;
}
/*
vector<Log_Entry> parse(const string& source) {
    return 1;
}

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
