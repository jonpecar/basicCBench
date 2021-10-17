#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <chrono>
#include "arithmetic.h"

using namespace std;


int main()
{
    srand(1234567); //Set seed so that runs produce identical results

    vector<int64_t> rand_ints = generate_random_ints(100000000);

    cout << run_ints(1000000, 100);
}

