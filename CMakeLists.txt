cmake_minimum_required(VERSION 3.15)
project(Lab2 LANGUAGES CXX)

# prevent for in-source building
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

set(CMAKE_BUILD_TYPE Debug) #Debug
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

include(FetchContent)
#https://codeload.github.com/Critteros/gsl_cpp_wrapper/zip/refs/heads/adding_FetchContent_integration
FetchContent_Declare(
  gsl_cpp_wrapper
  GIT_REPOSITORY https://github.com/Critteros/gsl_cpp_wrapper
  GIT_TAG "main"
)
FetchContent_MakeAvailable(gsl_cpp_wrapper)

include_directories("include")

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_definitions(-Wextra -Wpedantic)
add_link_options(-fsanitize=address -fsanitize=leak)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gsl_cpp_wrapper)



