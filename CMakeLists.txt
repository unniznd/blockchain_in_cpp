cmake_minimum_required(VERSION 3.5)

project(learncpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

set(source_dir "${PROJECT_SOURCE_DIR}/src/")

file(GLOB source_files "${source_dir}/*.cpp")

add_executable(HelloWorld ${source_files})

# Find OpenSSL package
find_package(OpenSSL REQUIRED)

# Link OpenSSL to the target
target_include_directories(HelloWorld PRIVATE ${OPENSSL_INCLUDE_DIR})
target_link_libraries(HelloWorld PRIVATE OpenSSL::Crypto OpenSSL::SSL)
