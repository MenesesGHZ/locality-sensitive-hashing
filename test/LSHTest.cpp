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

    // test projection
    LSH lsh = LSH{3, 3};
    Eigen::VectorXd query{{1, 1, 1}};
    lsh.projection(query);

    BOOST_CHECK_EQUAL(state.all(), true);  
}

BOOST_AUTO_TEST_SUITE_END()