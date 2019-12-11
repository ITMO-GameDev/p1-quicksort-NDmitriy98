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

#add_library(v2v_send_udp src/v2v_send_udp.cpp)
#add_library(v2v_receive_udp src/v2v_receive_udp.cpp)
##add_library(race_control_receive_udp src/race_control_receive_udp.cpp)
### Add cmake target dependencies of the library
### as an example, code may need to be generated before libraries
### either from message generation or dynamic reconfigure
## add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
#
### Declare a C++ executable
#
add_executable(p1_quicksort src/sort.cpp include/sort.h test/test.cpp)
#add_executable(v2v_receive src/v2v_receive.cpp)
#
#
#add_dependencies(v2v_data ${catkin_EXPORTED_TARGETS})
##add_dependencies(v2v_receive ${catkin_EXPORTED_TARGETS})
#add_dependencies(v2v_send_udp v2v_generate_messages_cpp)
#add_dependencies(v2v_receive_udp v2v_generate_messages_cpp)
#add_dependencies(race_control_receive_udp v2v_generate_messages_cpp)

## Add cmake target dependencies of the executable
## same as for the library above
#add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
#target_link_libraries(v2v_data v2v_send_udp  ${catkin_LIBRARIES})
#target_link_libraries(v2v_receive v2v_receive_udp ${catkin_LIBRARIES})
#target_link_libraries(race_control_receive race_control_receive_udp ${catkin_LIBRARIES})
target_link_libraries(p1_quicksort gtest gtest_main)

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