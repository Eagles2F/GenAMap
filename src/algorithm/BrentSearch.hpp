#ifndef ALGORITHMS_BRENTSEARCH_HPP
#define ALGORITHMS_BRENTSEARCH_HPP

#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <iostream>

#ifdef BAZEL
#include "algorithm/Algorithm.hpp"
#include "algorithm/AlgorithmOptions.hpp"
#include "model/LinearMixedModel.hpp"
#else
#include "Algorithm.hpp"
#include "AlgorithmOptions.hpp"
#include "../model/LinearMixedModel.hpp"
#endif

using namespace std;

class BrentSearch:public Algorithm{

private :
    double a; // start of the search
    double b; // End point of the search
    double c; // Prior value/estimate of least value
    double m; // Positive tolerance
    double e; // Positive tolerance error
    double t;
    double min_val; // Minimum value of the objective function
    double min_val_param; // Search parameter at which the value is minimum
    double delta; // 2*Delta window will be set based on the optimal Grid Search result.

public :

    BrentSearch();
    // Setters and Getters
    void set_a(double);
    void set_b(double);
    void set_c(double);
    void set_m(double);
    void set_e(double);
    void set_t(double);

    double get_a();
    double get_b();
    double get_c();
    double get_m();
    double get_e();
    double get_t();

    // Pass the objective function pointer from the model
    vector<double> get_brent_params();
    // Old Methods : double brent_search(double (*f)(double),double &);

    void run(LinearMixedModel *);
};

#endif