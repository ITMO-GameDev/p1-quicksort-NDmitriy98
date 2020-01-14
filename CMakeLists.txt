cmake_minimum_required(VERSION 3.6)
project(p1-quicksort-NDmitriy98)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib/googletest-master)
###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations

include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
include_directories(include)
## Declare a C++ library

### Add cmake target dependencies of the library
### as an example, code may need to be generated before libraries
### either from message generation or dynamic reconfigure

### Declare a C++ executable
#
#add_executable(p1_quicksort src/sort.cpp include/sort.h test/test.cpp)
#add_executable(p2_containers src/array.cpp include/array.hpp test/test2.cpp)
add_executable(p3_search include/LLRBTree.hpp src/dictionary.cpp include/dictionary.hpp test/test3.cpp)
add_executable(p4_memory_management src/memallocator.cpp include/memallocator.hpp test/test4.cpp)


## Add cmake target dependencies of the executable
## same as for the library above
#add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against

#target_link_libraries(p1_quicksort gtest gtest_main)
#target_link_libraries(p2_containers gtest gtest_main)
target_link_libraries(p3_search gtest gtest_main)
target_link_libraries(p4_memory_management gtest gtest_main)

#############
## Install ##
#############


#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_v2v.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)