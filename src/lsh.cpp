#include "lsh.hpp"

LSH::LSH(int n_hyperplanes, int n_dimensions) {
  this->n_hyperplanes = n_hyperplanes;
  this->n_dimensions = n_dimensions;
  this->hyperplanes = MatrixXd::Random(
    this->n_hyperplanes,
    this->n_dimensions
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
  for(int i = 0; VectorXd row : this->data.rowwise()){
    std::string key = this->vec_to_string(this->projection(row));
    if (!table.contains(key)){
      table.insert(std::make_pair(key, std::list<int>{}));
    }
    table[key].push_back(i);
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
  for(int i = 0; i < this->n_hyperplanes; i++){
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