#include "lsh.hpp"

void LSH::projection(Eigen::MatrixXd query){
    const int w = 10; //witdh of each quantization bin
    VectorXd x = VectorXd::Random(query.norm());
    VectorXd b = VectorXd::Random((0, w)); //between 0 and w
}