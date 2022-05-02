#include "reader.hpp"

Dataset DataLoader::read(std::string filename, std::vector<std::string> features, std::string label){
    Dataset dataset;  
    rapidcsv::Document doc(filename);
    dataset.x = Eigen::MatrixXd(doc.GetRowCount(), features.size());
    dataset.y = doc.GetColumn<std::string>(label);
    for(int i = 0; std::string feature : features){
        std::vector<double> column = doc.GetColumn<double>(feature);
        Eigen::VectorXd vec = Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(column.data(), column.size());
        dataset.x.col(i) = vec; 
        i++; 
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
