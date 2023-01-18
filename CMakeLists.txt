cmake_minimum_required(VERSION 3.12)
project(dsproj)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
enable_testing()

# # Use FetchContent to download and install the dependencies
# include(FetchContent)

# # dataframe
# FetchContent_Declare(
#   dataframe
#   GIT_REPOSITORY https://github.com/hosseinmoein/DataFrame.git
#   GIT_TAG master
# )
# FetchContent_MakeAvailable(dataframe)
add_subdirectory(DataFrame)
include_directories(DataFrame/include)
set(SOURCES main.cpp)
add_executable(dsproj ${SOURCES})

# hmdf_target_data_files(dsproj
#     DATA_FILES
#         ${PROJECT_SOURCE_DIR}/data/IBM.csv
#         ${PROJECT_SOURCE_DIR}/data/DT_IBM.csv
#         ${PROJECT_SOURCE_DIR}/data/DT_AAPL.csv
# )

target_link_libraries(dsproj PRIVATE DataFrame)
