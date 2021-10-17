#ifndef _ARITHMETIC_H_
#define _ARITHMETIC_H_

#include <vector>
#include <string>
#include <cstdint>

using namespace std;

vector<int64_t> generate_random_ints(int64_t count);
string run_ints(int64_t count, uint loops = 1);
template<typename T>
vector<T> run_arithmetic_func(T (*func)(T, T), vector<T> a, vector<T> b);
template<typename T>
string time_arithmetic_function(string desc, T (*func)(T, T), vector<T> a, vector<T> b, uint loops = 1);

#endif