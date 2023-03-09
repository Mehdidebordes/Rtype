cmake_minimum_required(VERSION 3.4)

project(r-type)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set (CMAKE_CXX_STANDARD 20)

set(CPM_DOWNLOAD_VERSION 0.36.0)
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

file(GLOB CPP_SERVER_FILE "src/Server/src/*.cpp")
file(GLOB CPP_CLIENT_FILE "src/Client/src/*.cpp")
file(GLOB CPP_SOCKET_FILE "src/Socket/*.cpp")

include_directories(${CMAKE_SOURCE_DIR}/src/Server/include)
include_directories(${CMAKE_SOURCE_DIR}/src/Client/include)
include_directories(${CMAKE_SOURCE_DIR}/Socket)

add_executable(server src/Server/main.cpp ${CPP_SERVER_FILE} ${CPP_SOCKET_FILE})
add_executable(client src/Client/main.cpp ${CPP_CLIENT_FILE} ${CPP_SOCKET_FILE})

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(server Boost::asio Boost::thread boost_thread pthread sfml-graphics sfml-system sfml-window sfml-audio boost_thread)
    target_link_libraries(client Boost::asio Boost::thread pthread sfml-graphics sfml-system sfml-window sfml-audio boost_thread pthread)
    else()
    target_link_libraries(server)
    target_link_libraries(client sfml-graphics sfml-system sfml-window sfml-audio)
endif()

CPMAddPackage (NAME asio GITHUB_REPOSITORY chriskohlhoff/asio GIT_TAG "asio-1-24-0")
CPMAddPackage(
  NAME Boost
  VERSION 1.77.0
  GITHUB_REPOSITORY "boostorg/boost"
  GIT_TAG "boost-1.77.0"
)
include_directories(${Boost_SOURCE_DIR}/libs/thread/)
include_directories(${Boost_SOURCE_DIR}/libs/asio/)

CPMaddPackage (NAME SFML GITHUB_REPOSITORY SFML/SFML GIT_TAG "2.5.1")
message(STATUS "SFML CACA=${SFML_SOURCE_DIR}")
include_directories(${SFML_SOURCE_DIR}/include/)
set_target_properties(sfml-audio PROPERTIES CXX_STANDARD 98 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)