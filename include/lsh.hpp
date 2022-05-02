#pragma once

#include <iostream>
#include <Eigen/Dense>
#include <list>
#include <string>
#include <unordered_map>

using Eigen::ArrayXd;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::VectorXi;

class LSH {
  private:
    int n_hyperplanes, n_dimensions;
    std::unordered_map<std::string, std::list<int>> table;
    MatrixXd hyperplanes;

  public:
    MatrixXd data;
    LSH(int, int);
    VectorXi projection(VectorXd);
    void fit();
    void predict(VectorXd) const;

    void approximate(VectorXd, int, float);
    void construct(VectorXd, int, float);

    unsigned int hamming_distance(VectorXi, VectorXi);
    std::string vec_to_string(VectorXi);
    void display_table();
};