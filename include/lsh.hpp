#pragma once

#include <iostream>
#include <Eigen/Dense>
#include <list>
#include <string>
#include <vector>
#include <unordered_map>

using Eigen::ArrayXd;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::VectorXi;

class LSH {
  private:
    std::unordered_map<std::string, std::list<int>> table;
    MatrixXd hyperplanes, x;
    std::vector<std::string> y;

  public:
    LSH(int, MatrixXd, std::vector<std::string>);
    VectorXi projection(VectorXd);
    void fit();
    void predict(VectorXd) const;

    void approximate(VectorXd, int, float);
    void construct(VectorXd, int, float);

    unsigned int hamming_distance(VectorXi, VectorXi);
    std::string vec_to_string(VectorXi);
    void display_table();
};