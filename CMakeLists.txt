cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the directories for source and headers
include_directories(${PROJECT_SOURCE_DIR}/lib)  # This adds lib/ as the directory to search for headers

# Add the source files in the src directory
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")  # Ensure you're using full path

# Check if any source files are found
if(NOT SOURCES)
    message(FATAL_ERROR "No source files found in the src directory!")
endif()

# Specify the output directory for the final binary (executable)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Create the executable from the source files
add_executable(${PROJECT_NAME} ${SOURCES})