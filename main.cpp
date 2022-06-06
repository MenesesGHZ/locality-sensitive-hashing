#include <Eigen/Dense>
#include "reader.hpp"
#include "lsh.hpp"

int main(){
  DataLoader reader;
  auto dataset = reader.read(
    "/home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/dataset/iris/train/iris.csv", 
    {
      "SepalLengthCm",
      "SepalWidthCm",
      "PetalLengthCm",
      "PetalWidthCm"
    }, 
    "Species"
  );
  LSH lsh{50, dataset.x, dataset.y};
  lsh.fit();
  std::cout<<std::endl<<std::endl;
  lsh.display_table();
  std::cout<<std::endl<<std::endl;
  lsh.display_optimized_table();
  std::cout<<std::endl<<std::endl;

  VectorXd query{{ 4.4, 2.9, 1.4, 0.2 }};
  std::string y = lsh.predict(query);
  std::cout << "Real: 0 --- Prediction: " << y << std::endl;

  query = VectorXd({{ 5.1, 3.5, 1.4, 0.2 }});
  y = lsh.predict(query);
  std::cout << "Real: 0 --- Prediction: " << y << std::endl;

  query = VectorXd({{ 6.7, 3.1, 4.7, 1.5 }});
  y = lsh.predict(query);
  std::cout << "Real: 1 --- Prediction: " << y << std::endl;

  query = VectorXd({{ 7.0, 3.2, 4.7, 1.4 }});
  y = lsh.predict(query);
  std::cout << "Real: 1 --- Prediction: " << y << std::endl;

  query = VectorXd({{ 7.7, 2.6, 6.9, 2.3 }});
  y = lsh.predict(query);
  std::cout << "Real: 2 --- Prediction: " << y << std::endl;

  query = VectorXd({{ 6.2, 3.4, 5.4, 2.3 }});
  y = lsh.predict(query);
  std::cout << "Real: 2 --- Prediction: " << y << std::endl;

  return 0;
}