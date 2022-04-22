#include "lsh.hpp"

int main(){
  LSH lsh;
  lsh.read_dataset("/home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/dataset/iris.csv");
  lsh.display_dataset_head();
  return 0;
}