#ifndef _TIMING_
#define _TIMING_

#include <chrono>
#include <string>
using namespace std;

string write_time_result(string desc, chrono::time_point<chrono::steady_clock> start, chrono::time_point<chrono::steady_clock> end, int indents = 0);

#endif