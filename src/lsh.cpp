#include "lsh.hpp"

LSH::LSH(int number_of_hyperplanes, MatrixXd x, std::vector<std::string> y) {
  this->x = x;
  this->y = y;
  this->hyperplanes = MatrixXd::Random(
    number_of_hyperplanes,
    this->x.cols()
  );
};

void LSH::approximate(VectorXd P, int c, float gamma){
  // Algorithm 1: Finding an approximation to CCP(r).
  return;
}

void LSH::construct(VectorXd P, int c, float gamma){
  // Algorithm 2: Constructing the approximate nearest neighbor data structure
  return;
}

void LSH::predict(VectorXd query) const{
  // Algorithm 3: Searching for approximate nearest neighbor
    return;
}

void LSH::fit(){
  for(int i = 0; VectorXd row : this->x.rowwise()){
    std::string key = this->vec_to_string(this->projection(row));

    if (!this->table.contains(key)){
      this->table.insert(std::make_pair(key, std::list<int>{}));
    }
    this->table[key].push_back(i);
  }
}

std::string LSH::vec_to_string(VectorXi vec){
  std::string s;
  for(int vi : vec){
    s += std::to_string(vi);
  }
  return s;
}

VectorXi LSH::projection(VectorXd query) {
  MatrixXd projections = this->hyperplanes * query;
  VectorXi key = (projections.array() > 0).cast<int>();
  return key;
}

unsigned int LSH::hamming_distance(VectorXi v1, VectorXi v2){
  unsigned int distance = 0;
  for(int i = 0; i < this->x.cols(); i++){
    distance += v1[i] != v2[i];
  }
  return distance;
}

void LSH::display_table(){
  for (auto& it : this->table) {
    std::cout << it.first;
    for (auto value : it.second){
      std::cout << " --> " << value;
    }
    std::cout << std::endl;
  }
}