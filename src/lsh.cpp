#include "lsh.hpp"

LSH::LSH(int number_of_hyperplanes, MatrixXd x, std::vector<std::string> y) {
  this->x = x;
  this->y = y;
  this->hyperplanes = MatrixXd::Random(
    number_of_hyperplanes,
    this->x.cols()
  );
};

std::string LSH::predict(VectorXd query){
  std::string key = this->vec_to_string(this->projection(query));
  std::string close_key = key;
  unsigned int min_distance = UINT_MAX;
  for(auto& it : this->optimized_table){
    unsigned int distance = this->hamming_distance(key, it.first);
    if (min_distance > distance){
      close_key = it.first;
      min_distance = distance;
    }
  }
  return this->optimized_table[close_key];
}

void LSH::fit(){
  // construct chaining hash table
  for(int i = 0; VectorXd row : this->x.rowwise()){
    std::string key = this->vec_to_string(this->projection(row));
    if (!this->table.contains(key)){
      this->table.insert(std::make_pair(key, std::vector<std::string>{}));
    }
    this->table[key].push_back(this->y[i]);
    i++;
  }
  
  // construct optimize table
  for (auto& it : this->table) {
    std::map<std::string, int> counter_map;
    std::string max_label;
    int max = 0;
    for (std::string label : it.second){
      if (!counter_map.contains(label)){
        counter_map.insert(std::make_pair(label, 0));
      }
      counter_map[label] += 1;
      if(counter_map[label] > max){
        max = counter_map[label];
        max_label = label;
      }
    }
    this->optimized_table[it.first] = max_label; 
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

void LSH::evaluate(MatrixXd x, std::vector<std::string> y){
    //print avg presicion + print avg time
}

unsigned int LSH::hamming_distance(std::string key1, std::string key2){
  unsigned int distance = 0;
  for(int i = 0; i < this->x.size(); i++){
    distance += key1[i] != key2[i];
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

void LSH::display_optimized_table(){
  for (auto& it : this->optimized_table) {
    std::cout << it.first;
    std::cout << " --> " << it.second;
    std::cout << std::endl;
  }
}