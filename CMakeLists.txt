cmake_minimum_required(VERSION 3.6)
project(mandarin)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(GenerateExportHeader)
include(utils/CompileUtility)
include(utils/InstallUtility)

set(CMAKE_CXX_STANDARD 17)

# Options
option(MANDARIN_INSTALL "Generate installation target" ON)

# Generate compile flags.
generate_flags(MANDARIN_COMPILE_FLAGS "native" 2 true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}${MANDARIN_COMPILE_FLAGS}")

find_package(lambdacommon REQUIRED)
find_package(CURL REQUIRED)
find_package(cpptoml REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(nlohmann_fifo_map REQUIRED)
include_directories(${LAMBDACOMMON_INCLUDE_DIRS} ${CPPTOML_INCLUDE_DIRS} ${NLOHMANN_JSON_INCLUDE_DIRS} ${NLOHMANN_FIFO_MAP_INCLUDE_DIRS} ${CURL_INCLUDE_DIRS})

# All files:
# There is the C++ header files.
set(HEADERS_BASE include/mandarin/mandarin.h include/mandarin/base.h include/mandarin/config.h)
set(HEADER_FILES ${HEADERS_BASE})
# There is the C++ source files.
set(SOURCES_BASE src/mandarin.cpp)
set(SOURCE_FILES ${SOURCES_BASE})

# Build the shared library.
add_library(libmandarin SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(libmandarin AperLambda::lambdacommon CURL::libcurl)
# Sets some properties.
set_target_properties(libmandarin PROPERTIES PREFIX "lib")
set_target_properties(libmandarin PROPERTIES OUTPUT_NAME "mandarin")
# Generate the export header and include it.
GENERATE_EXPORT_HEADER(libmandarin
        BASE_NAME mandarin
        EXPORT_MACRO_NAME MANDARIN_API
        EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/mandarin_exports.h
        STATIC_DEFINE MANDARIN_SHARED_EXPORTS_BUILT_AS_STATIC)
target_include_directories(libmandarin PUBLIC ${CMAKE_BINARY_DIR}/exports)

include_directories(include)

# Build the executable.
add_executable(mandarin src/exe/main.cpp)
target_link_libraries(mandarin libmandarin AperLambda::lambdacommon CURL::libcurl)