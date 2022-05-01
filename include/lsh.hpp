#pragma once

#include <iostream>
#include <string>
#include <Eigen/Dense>
#include "rapidcsv.h"

using Eigen::MatrixXd;
using Eigen::RowVectorXd;
using Eigen::VectorXd;

class LSH {
  private:
    int hyperplanes, dimensions;
  
  public:
    MatrixXd projections;

    LSH(int hyperplanes, int dimensions) : hyperplanes{hyperplanes}, dimensions{dimensions} {
      this->projections = MatrixXd::Random(
        this->hyperplanes,
        this->dimensions
      );
    };

    rapidcsv::Document dataset;
    void preprocessing();

    void approximate(RowVectorXd, int, float);
    void construct(RowVectorXd, int, float);
    void search(RowVectorXd, RowVectorXd);
    void projection(VectorXd);

    void read_dataset(char*);
    void display_dataset_head();
};