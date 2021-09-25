# 默认警告
include(CheckWarningFlags)
check_warning_flags(CXX PROJECT_WARNING_FLAGS)

# 依赖 wiringPi，boost
find_package(WiringPi REQUIRED)
find_package(Boost REQUIRED COMPONENTS atomic filesystem program_options thread)

# 添加项目
add_executable(eyekeeper
    main.cpp
    basicunit.h basicunit.cpp
    beeper.h beeper.cpp
    humaninfraredsensor.h humaninfraredsensor.cpp
    ultrasound.h ultrasound.cpp
)

target_compile_options(eyekeeper PRIVATE ${PROJECT_WARNING_FLAGS})
target_precompile_headers(eyekeeper PRIVATE
    <wiringPi.h>
    <boost/chrono.hpp> <boost/signals2.hpp> <boost/program_options.hpp> <boost/thread.hpp>
)
target_link_libraries(eyekeeper PRIVATE
    WiringPi
    Boost::atomic Boost::filesystem Boost::program_options Boost::thread
)
