#pragma once

#include <iostream>
#include <string>
#include <Eigen/Dense>
#include "rapidcsv.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

class LSH {
  private:
  public:
    rapidcsv::Document dataset;
    void preprocessing();

    void approximate(VectorXd, int, float);
    void construct(VectorXd, int, float);
    void search(VectorXd, VectorXd);
    void projection(VectorXd);

    void read_dataset(char*);
    void display_dataset_head();
};