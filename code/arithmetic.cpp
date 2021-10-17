#include "arithmetic.h"
#include <vector>
#include <string>
#include <cstdint>
#include <chrono>
#include "timing.h"

using namespace std;

template<typename T>
T add(T a, T b) {return(a + b);};
template<typename T>
T mydiv(T a, T b) {return(a / b);};
template<typename T>
T mul(T a, T b) {return(a * b);};
template<typename T>
T sub(T a, T b) {return(a - b);};
int64_t mod(int64_t a, int64_t b) {return(a % b);};

vector<int64_t> generate_random_ints(int64_t count)
{
    vector<int64_t> result = vector<int64_t>();
    while(result.size() < count)
    {
        result.push_back(rand());
    }
    return(result);
}

string run_ints(int64_t count, uint loops)
{
    string results = "Integer results:\n";

    chrono::time_point<chrono::steady_clock> start_time = chrono::steady_clock::now();

    vector<int64_t> a = generate_random_ints(count);
    vector<int64_t> b = generate_random_ints(count);

    chrono::time_point<chrono::steady_clock> time_random_generated = chrono::steady_clock::now();
    results += write_time_result("Random generator", start_time, time_random_generated, 1);

    results += time_arithmetic_function("Add", *add<int64_t>, a, b, loops);
    results += time_arithmetic_function("Sub", *sub<int64_t>, a, b, loops);
    results += time_arithmetic_function("Mul", *mul<int64_t>, a, b, loops);
    results += time_arithmetic_function("Div", *mydiv<int64_t>, a, b, loops);
    results += time_arithmetic_function("Mod", *mod, a, b, loops);

    chrono::time_point<chrono::steady_clock> time_end = chrono::steady_clock::now();

    results += write_time_result("Total", start_time, time_end, 1);

    return results;
}

template<typename T>
string time_arithmetic_function(string desc, T (*func)(T, T), vector<T> a, vector<T> b, uint loops)
{
    chrono::time_point<chrono::steady_clock> func_start = chrono::steady_clock::now();

    for(int i = 0; i < loops; i ++)
    {
        run_arithmetic_func(*func, a, b);
    }

    chrono::time_point<chrono::steady_clock> func_end = chrono::steady_clock::now();

    return(write_time_result(desc, func_start, func_end, 1));
}

template<typename T>
vector<T> run_arithmetic_func(T (*func)(T, T), vector<T> a, vector<T> b)
{
    vector<T> output = vector<T>();

    for(int i = 0; i < a.size(); i++)
    {
        output.push_back(func(a[i], b[i]));
    }


    return output;
}