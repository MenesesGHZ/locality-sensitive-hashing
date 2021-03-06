#pragma once

#include <string>
#include <vector>
#include <Eigen/Dense>
#include "rapidcsv.h"

struct Dataset{
  Eigen::MatrixXd x;
  std::vector<std::string> y;
  std::vector<std::string> labels;
};


class DataLoader {
  public:
    Dataset read(std::string, std::vector<std::string>, std::string);
};