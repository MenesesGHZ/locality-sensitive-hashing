cmake_minimum_required(VERSION 3.5.1)

# set the project name
project(lsh VERSION 1.0)

# adding configuration
#configure_file(config.h.in config.h)

# add the executable
add_executable(${PROJECT_NAME} main.cpp)

# specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# defining lsh library
add_library(lsh_source src/lsh.cpp)
target_include_directories(lsh_source PUBLIC "${PROJECT_SOURCE_DIR}/include/")

# defining read dataset library
add_library(reader src/reader.cpp)
target_include_directories(reader PUBLIC "${PROJECT_SOURCE_DIR}/include/")

# add rapidcsv library
add_library(rapidcsv INTERFACE)
target_include_directories(rapidcsv INTERFACE lib)

# add openmp library
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# add eigen library
find_package(Eigen3 REQUIRED NO_MODULE)
target_link_libraries(lsh_source PUBLIC Eigen3::Eigen)
target_link_libraries(reader PUBLIC Eigen3::Eigen rapidcsv)

# linking libraries and build/<include files>.h to executable
target_link_libraries(${PROJECT_NAME} PUBLIC lsh_source reader)
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")

# test configuration
enable_testing()

# Find boost test framework
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_definitions (-DBOOST_TEST_DYN_LINK)

include_directories(${Boost_INCLUDE_DIRS})

# The location of the test codes sources
file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} test/*.cpp)

# Find test codes
foreach(testSrc ${TEST_SRCS})
    #Extract the filename without an extension (NAME_WE)
    get_filename_component(testName ${testSrc} NAME_WE)

    # Add compile target
    add_executable(${testName} ${testSrc})

    # link to Boost libraries AND your targets and dependencies
    target_link_libraries(${testName} ${Boost_LIBRARIES} lsh_source)

    # Location of the test binaries 
    set_target_properties(${testName} PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/build/testBin)

    # Add the test to the collection of tests 
    add_test(NAME ${testName} 
             WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/testBin 
             COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/testBin/${testName} )
endforeach(testSrc)