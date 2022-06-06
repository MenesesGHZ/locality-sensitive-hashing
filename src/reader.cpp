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
