cmake_minimum_required(VERSION 3.16)

project(eyekeeper VERSION 0.0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

# 添加项目的模块路径
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

option(BUILD_SHARED_LIBS "If true, this will cause all libraries to be built shared unless the library was explicitly added as a static library.")
option(BUILD_TESTING "Build the testing tree." OFF)

# Release 版本开启 IPO
include(CheckIPOSupported OPTIONAL)
if(COMMAND check_ipo_supported)
    check_ipo_supported(RESULT PROJECT_IS_IPO_SUPPORTED)

    if(PROJECT_IS_IPO_SUPPORTED)
        message(STATUS "IPO is supported.")
        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)
    endif()
endif()

# 查找第三方库
# gRPC
#find_package(gRPC CONFIG REQUIRED)

# 启用测试
if(BUILD_TESTING)
    enable_testing()
    find_package(GTest CONFIG REQUIRED)
    include(GoogleTest)
endif()

# 添加源代码子目录
add_subdirectory(src)
