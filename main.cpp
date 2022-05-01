#include <Eigen/Dense>
#include "lsh.hpp"

int main(){
  LSH lsh = LSH{10, 3};
  Eigen::VectorXd query{{1, 1, 1}};
  lsh.projection(query);
  return 0;
}