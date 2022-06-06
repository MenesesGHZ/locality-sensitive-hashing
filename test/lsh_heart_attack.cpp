#define BOOST_TEST_MODULE "Iris test"
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>
#include <boost/test/tools/output_test_stream.hpp>
#include <bitset>
#include <iostream>
#include <chrono>
#include "lsh.hpp"
#include "reader.hpp"

using namespace std;
using namespace std::chrono;

BOOST_AUTO_TEST_SUITE(LLTEST)


BOOST_AUTO_TEST_CASE( heart_attack )
{
  bitset<0> state;

  DataLoader reader;
  auto trainset = reader.read(
    "/home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/dataset/heart_attack/train.csv", 
    { 
      "age",
      "sex",
      "cp",
      "trtbps",
      "chol",
      "fbs",
      "restecg",
      "thalachh",
      "exng",
      "oldpeak",
      "slp",
      "caa",
      "thall"
    }, 
    "output"
  );

  auto testset = reader.read(
    "/home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/dataset/heart_attack/test.csv", 
    {
      "age",
      "sex",
      "cp",
      "trtbps",
      "chol",
      "fbs",
      "restecg",
      "thalachh",
      "exng",
      "oldpeak",
      "slp",
      "caa",
      "thall"
    }, 
    "output"
  );
  
  std::cout<<std::endl;
  std::cout<<"Number of samples (training): "<<trainset.y.size()<<std::endl; 
  std::cout<<"Number of samples (testing): "<<testset.y.size()<<std::endl; 

  int combs[]{4, 24};
  for(int k : combs){
      std::cout<<"------------------"<<std::endl;
      LSH lsh{k, trainset.x, trainset.y};
      auto training_start = high_resolution_clock::now();
      lsh.fit();
      auto training_stop = high_resolution_clock::now();
      auto training_duration = duration_cast<microseconds>(training_stop - training_start);
      auto prediction_start = high_resolution_clock::now();
      lsh.predict(testset.x.row(0));
      auto prediction_stop = high_resolution_clock::now();
      auto prediction_duration = duration_cast<microseconds>(prediction_stop - prediction_start);
      std::cout<<"Accuracy K="<< k <<": "<<lsh.evaluate(testset.x, testset.y)*100<<"%"<<std::endl;
      std::cout<<"Training Duration K=" << k <<"(microseconds): "<<training_duration.count()<<"μs"<<std::endl;
      std::cout<<"Prediction Duration K="<< k <<"(microseconds): "<<prediction_duration.count()<<"μs"<<std::endl;
      std::cout<<std::endl;
  }
 BOOST_CHECK_EQUAL(state.all(), true);  
}

BOOST_AUTO_TEST_SUITE_END()