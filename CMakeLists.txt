cmake_minimum_required(VERSION 3.29)
project(untitled2)

set(CMAKE_CXX_STANDARD 26)

# Fetch nlohmann/json
include(FetchContent)
FetchContent_Declare(
        nlohmann_json
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.hpp
        DOWNLOAD_NO_EXTRACT TRUE
        SOURCE_DIR ${CMAKE_BINARY_DIR}/include/nlohmann
)
FetchContent_MakeAvailable(nlohmann_json)

add_executable(untitled2 main.cpp
        Credential.cpp
        Credential.h
        Vault.cpp
        Vault.h)

# Link it
target_include_directories(untitled2 PRIVATE ${CMAKE_BINARY_DIR}/include)