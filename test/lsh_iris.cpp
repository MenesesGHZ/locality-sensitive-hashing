#define BOOST_TEST_MODULE "Iris test"
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>
#include <bitset>
#include "lsh.hpp"
#include "reader.hpp"


using namespace std;

BOOST_AUTO_TEST_SUITE(LLTEST)

typedef boost::mpl::list<int,long> test_types;


BOOST_AUTO_TEST_CASE_TEMPLATE( sorting_test, T, test_types )
{
  bitset<0> state;

  DataLoader reader;
  auto trainset = reader.read(
    "/home/meneses/Documents/locality-sensitive-hashing/dataset/train/iris.csv", 
    {
      "SepalLengthCm",
      "SepalWidthCm",
      "PetalLengthCm",
      "PetalWidthCm"
    }, 
    "Species"
  );

  auto testset = reader.read(
    "/home/meneses/Documents/locality-sensitive-hashing/dataset/test/iris.csv", 
    {
      "SepalLengthCm",
      "SepalWidthCm",
      "PetalLengthCm",
      "PetalWidthCm"
    }, 
    "Species"
  );
  
  LSH lsh{8, trainset.x, trainset.y};
  lsh.fit();
  //lsh.evaluate(testset.x, testset.y);

  //LSH lsh{48, trainset.x, trainset.y};
  //lsh.fit();
  //lsh.evaluate(testset.x, testset.y);

  BOOST_CHECK_EQUAL(state.all(), true);  
}

BOOST_AUTO_TEST_SUITE_END()