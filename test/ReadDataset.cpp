#define BOOST_TEST_MODULE "Sorting test"
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>
#include <vector>
#include <string>
#include <bitset>
#include "lsh.hpp"

using namespace std;

BOOST_AUTO_TEST_SUITE(LLTEST)

typedef boost::mpl::list<int,long> test_types;


BOOST_AUTO_TEST_CASE_TEMPLATE( sorting_test, T, test_types )
{
    bitset<0> state;
    LSH lsh;
    lsh.read_dataset("/home/meneses/Documents/PROYECTOS/locality-sensitive-hashing/dataset/iris.csv");
    std::vector<std::string> columnNames = lsh.dataset.GetColumnNames();
    std::vector<std::string> columnNames2{"Id","SepalLengthCm","SepalWidthCm","PetalLengthCm","PetalWidthCm","Species"};
    
    if(columnNames.size() != columnNames2.size()){
      BOOST_CHECK_EQUAL(state.all(), false);  
      return;
    }

    for(int i = 0; i < columnNames.size(); i++){
      if(columnNames[i] != columnNames2[i]){
        state.set(0);
      }
    }

    std::vector<float> row = lsh.dataset.GetRow<float>(0);
    std::vector<float> row2{1,5.1,3.5,1.4,0.2,0};
    if(row.size() != row2.size()){
      BOOST_CHECK_EQUAL(state.all(), false);  
      return;
    }
    for(int i = 0; i < row.size(); i++){
      if(row[i] != row2[i]){
        state.set(1);
      }
    }
    BOOST_CHECK_EQUAL(state.all(), true);  
}

BOOST_AUTO_TEST_SUITE_END()