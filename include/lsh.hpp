#pragma once

#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class LSH {
  private:
  public:
    void search();
    void projection(Eigen::MatrixXd query);
    void read();
};