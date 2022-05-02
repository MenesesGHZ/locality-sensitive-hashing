#include <Eigen/Dense>
#include "reader.hpp"
#include "lsh.hpp"

int main(){
  DataLoader reader;
  auto dataset = reader.read(
    "/home/meneses/Documents/locality-sensitive-hashing/dataset/iris.csv", 
    {
      "SepalLengthCm",
      "SepalWidthCm",
      "PetalLengthCm",
      "PetalWidthCm"
    }, 
    "Species"
  );
  LSH lsh{25, dataset.x, dataset.y};
  lsh.fit();
  lsh.display_table();

  return 0;
}