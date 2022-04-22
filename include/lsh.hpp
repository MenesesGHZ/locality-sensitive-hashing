#pragma once

#include <iostream>
#include <string>
#include <Eigen/Dense>
#include "rapidcsv.h"


using Eigen::MatrixXd;
using Eigen::VectorXd;

class LSH {
  private:
    rapidcsv::Document dataset;
  public:
    void search();
    void projection(Eigen::MatrixXd);
    void read_dataset(char*);
    void display_dataset_head();
};