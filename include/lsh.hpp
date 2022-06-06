#pragma once

#include <iostream>
#include <Eigen/Dense>
#include <list>
#include <string>
#include <vector>
#include <limits>
#include <unordered_map>
#include <map>

using Eigen::ArrayXd;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::VectorXi;

class LSH {
  private:
    std::unordered_map<std::string, std::vector<std::string>> table;
    std::map<std::string, std::string> optimized_table;
    MatrixXd hyperplanes, x;
    std::vector<std::string> y;

  public:
    LSH(int, MatrixXd, std::vector<std::string>);
    VectorXi projection(VectorXd);
    std::string predict(VectorXd);
    void fit();
    float evaluate(MatrixXd, std::vector<std::string>);

    unsigned int hamming_distance(std::string, std::string);
    std::string vec_to_string(VectorXi);
    void display_table();
    void display_optimized_table();
};