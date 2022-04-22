#include "lsh.hpp"

void LSH::projection(Eigen::MatrixXd query){
    const int w = 10; //witdh of each quantization bin
    VectorXd x = VectorXd::Random(query.norm());
    VectorXd b = VectorXd::Random((0, w)); //between 0 and w
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