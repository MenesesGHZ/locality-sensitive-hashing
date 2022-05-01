#include "lsh.hpp"


void LSH::approximate(RowVectorXd P, int c, float gamma){
  // Algorithm 1: Finding an approximation to CCP(r).
  return;
}

void LSH::construct(RowVectorXd P, int c, float gamma){
  // Algorithm 2: Constructing the approximate nearest neighbor data structure
  return;
}

void LSH::search(RowVectorXd P, RowVectorXd query){
  // Algorithm 3: Searching for approximate nearest neighbor
    return;
}

void LSH::projection(VectorXd query) {
  MatrixXd m = projections * query;
  
  std::cout << m << std::endl;
}

void LSH::read_dataset(char *filename){
    this->dataset = rapidcsv::Document(filename);
}

void LSH::display_dataset_head(){
  std::vector<std::string> columnNames = this->dataset.GetColumnNames();
  const int size = columnNames.size();
  for(int i = 0; i < size; i++){
    std::cout << columnNames[i] << "    ";
  }
  std::cout << std::endl; 
  for(int i = 0; i < 5; i++){
    std::vector<float> row = this->dataset.GetRow<float>(i);
    for(int j = 0; j < size; j++){
      std::cout << row[j] << "            ";
    }
    std::cout << std::endl; 
  }
}