#define BOOST_TEST_MODULE "Sorting test"
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>
#include <iostream>
#include <bitset>

using namespace std;


BOOST_AUTO_TEST_SUITE(LLTEST)


typedef boost::mpl::list<int,long> test_types;

// Aqui su usuario define el criterio de ordenamiento.
template<typename T>
bool criterio(T& i,T& j) { return (i<j); }


// Placeholder function that creates a static unshufled sequence
template<typename T>
std::vector<T> create_static_sequence() {

    std::vector<T> elements;
        
    // Creation of an anorder set of elements
    elements.push_back(100);
    elements.push_back(10);
    elements.push_back(80);
    elements.push_back(30);
    elements.push_back(60);
    elements.push_back(50);
    elements.push_back(40);
    elements.push_back(70);
    elements.push_back(20);
    elements.push_back(90);
    
    //Not very elegant! A copy is created. 
    return elements;
}

// Covert values to a string
template<typename T>
std::string to_string(const std::vector<T> &elements){
    std::string str{};
    for(T e : elements) str += std::to_string(e) + ", ";
    return str.substr(0,str.length()-2);
}


BOOST_AUTO_TEST_CASE_TEMPLATE( sorting_test, T, test_types )
{
    bitset<2> state;

    state.set(0);

    state.set(1);

    BOOST_CHECK_EQUAL(state.all(),true);  
}

BOOST_AUTO_TEST_SUITE_END()