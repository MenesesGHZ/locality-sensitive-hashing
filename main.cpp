#include <Eigen/Dense>
#include "reader.hpp"
#include "lsh.hpp"

int main(){
  ReadDataset reader;
  reader.read(
    "../iris.csv", 
    {
      "SepalLengthCm",
      "SepalWidthCm",
      "PetalLengthCm",
      "PetalWidthCm"
    }, 
    "Species"
  );
  //LSH lsh = LSH{4, 4};
  //lsh.fit();
  //lsh.display_table();

  return 0;
}