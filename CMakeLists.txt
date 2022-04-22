cmake_minimum_required(VERSION 3.5.1)

# set the project name
project(lsh VERSION 1.0)

# adding configuration
#configure_file(config.h.in config.h)

# add the executable
add_executable(${PROJECT_NAME} main.cpp)

# specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# adding vendor libraries
#add_library(lodepng vendor/lodepng/lodepng.cpp)
#target_include_directories(lodepng PUBLIC "${PROJECT_SOURCE_DIR}/vendor/lodepng")

# defining glitch library
add_library(lsh_source src/lsh.cpp)
target_include_directories(lsh_source PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(${PROJECT_NAME} PUBLIC lsh_source)

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

# linking libraries and build/<include files>.h to executable
target_link_libraries(${PROJECT_NAME} PUBLIC lsh_source)
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")