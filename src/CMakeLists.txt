# 默认警告
include(CheckWarningFlags)
check_warning_flags(CXX PROJECT_WARNING_FLAGS)

# 添加项目
add_executable(eyekeeper
    main.cpp
)

target_compile_options(eyekeeper PRIVATE ${PROJECT_WARNING_FLAGS})
