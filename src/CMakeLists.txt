# 默认警告
include(CheckWarningFlags)
check_warning_flags(CXX PROJECT_WARNING_FLAGS)

# 依赖 wiringPi
find_package(WiringPi REQUIRED)

# 添加项目
add_executable(eyekeeper
    main.cpp
    beeper.h beeper.cpp
)

target_compile_options(eyekeeper PRIVATE ${PROJECT_WARNING_FLAGS})
target_precompile_headers(eyekeeper PRIVATE <wiringPi.h>)
target_link_libraries(eyekeeper PRIVATE WiringPi)
