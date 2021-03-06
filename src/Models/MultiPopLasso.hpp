//
// Created by haohanwang on 2/2/16.
//

#ifndef ALGORITHMS_MULTIPOPLASSO_HPP
#define ALGORITHMS_MULTIPOPLASSO_HPP

#include <iostream>
#include <vector>

#ifdef BAZEL
#include "Models/Model.hpp"
#include "Math/Math.hpp"
#else
#include "../Models/Model.hpp"
#include "../Math/Math.hpp"
#endif


using namespace std;
using namespace Eigen;

class MultiPopLasso : public Model {
private:
    MatrixXd betaAll;
    double lambda;
    double mu;
    double gamma;
    VectorXd population;
    MatrixXd Z;
    long popNum;
    double L;
    bool initTrainingFlag;

    VectorXi removeCols;
    MatrixXd C;

    MatrixXd getBetaInside();

    double groupPenalization();
    void reArrangeData();

    void removeColumns();
    MatrixXd normalizeData_col(MatrixXd);
    void formatData();

//    MatrixXd deriveMatrixA(double, long, double);
//    MatrixXd project(MatrixXd);

    vector<long> getPopulationIndex(long);
    void initC();

    static constexpr double default_lambda = 0;
    static constexpr double default_mu = 1;
    static constexpr double default_gamma = 0;

public:
    void reSetFlag();
    void setXY(MatrixXd, MatrixXd);
    void setLambda(double);
    void setPopulation(VectorXd);
    void setMu(double);
    void setGamma(double);
    void setAttributeMatrix(const string&, MatrixXd*);

    void initBeta();
    double cost();
    MatrixXd predict();
    MatrixXd predict(MatrixXd);
    MatrixXd predict(MatrixXd, VectorXd);
    void assertReadyToRun();
    void initTraining();

    MatrixXd proximal_derivative();
    MatrixXd proximal_operator(MatrixXd, float);

    double getL();
    MatrixXd getBeta();
    MatrixXd getFormattedBeta();

    void updateBetaAll();
    MatrixXd getBetaAll();

    MultiPopLasso();
    MultiPopLasso(const unordered_map<string, string>& options);
};


#endif //ALGORITHMS_MULTIPOPLASSO_HPP
