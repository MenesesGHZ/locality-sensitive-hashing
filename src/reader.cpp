#include "reader.hpp"

Dataset ReadDataset::read(std::string filename, std::vector<std::string> features, std::string label){
    Dataset dataset;  
    rapidcsv::Document doc("/home/meneses/Documents/locality-sensitive-hashing/dataset/iris.csv");
    dataset.y = doc.GetColumn<std::string>(label);
    for(std::string feature : features){
        std::vector<double> column = doc.GetColumn<double>(feature);
        Eigen::VectorXd vec = Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(column.data(), column.size());
        dataset.x = Eigen::MatrixXd(features.size(), 1);
        dataset.x.conservativeResize(dataset.x.rows(), dataset.x.cols()+1);
        dataset.x.col(dataset.x.cols()-1) = vec;
    }
    return dataset;
}

//void ReadDataset::display_dataset_head(){
//  std::vector<std::string> columnNames = this->dataset.GetColumnNames();
//  const int size = columnNames.size();
//  for(int i = 0; i < size; i++){
//    std::cout << columnNames[i] << "    ";
//  }
//  std::cout << std::endl; 
//  for(int i = 0; i < 5; i++){
//    std::vector<float> row = this->dataset.GetRow<float>(i);
//    for(int j = 0; j < size; j++){
//      std::cout << row[j] << "            ";
//    }
//    std::cout << std::endl; 
//  }
//}
