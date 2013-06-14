//  Apache Log File Processor
//   
//  DO NOT CHANGE ANYTHING IN THIS FILE.
//
//  @author: Dale Haverstock
//

//==============================================================================
#ifndef LOG_VIEW_H
#define LOG_VIEW_H

#include <vector>

#ifdef CS2_STRING
  #include "string.h"
  using cs33001::string;
#else
  #include <string>
  using std::string;
#endif

//==============================================================================
struct Date
{
    Date()
      : year(0) {};

    string  day;
    string  month;
    int     year;
};

//==============================================================================
struct Time
{
    Time()
      : hour(0), minute(0), second(0) {};

    int  hour;
    int  minute;
    int  second;
};

//==============================================================================
struct Log_Entry
{
    Log_Entry()
       : _number_of_bytes(0) {};
    string  _host;
    Date    _date;
    Time    _time;
    string  _request;
    string  _status;
    int     _number_of_bytes;
};

//==============================================================================
// Function declarations.
// These functions must be implemented.
std::vector<string>    split(const string&, char);
Log_Entry              create_Log_Entry(const string&);
std::vector<Log_Entry> parse(const string&);
void                   output_all(const std::vector<Log_Entry> &);
int                    byte_count(const std::vector<Log_Entry> &);
void                   output_hosts(const std::vector<Log_Entry>&);

#endif

