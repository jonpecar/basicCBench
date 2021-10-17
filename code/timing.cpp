#include "timing.h"
#include <chrono>
#include <string>
using namespace std;


string write_time_result(string desc, chrono::time_point<chrono::steady_clock> start, chrono::time_point<chrono::steady_clock> end, int indents)
{
    string output = "";
    for(int i = 0; i < indents; i++)
    {
        output += "\t";
    }
    output += desc + " time: ";
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
    double elapsed_s = (double)elapsed.count()/1000.0;
    output += to_string(elapsed_s) + " s";
    output += "\n";
    return output;
}