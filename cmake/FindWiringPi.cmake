# 查找 wiringPi
find_path(WiringPi_INCLUDE_DIR wiringPi.h)
find_library(WiringPi_LIBRARY wiringPi)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(WiringPi DEFAULT_MSG
    WiringPi_LIBRARY WiringPi_INCLUDE_DIR
)

if(WiringPi_FOUND AND NOT TARGET WiringPi)
    add_library(WiringPi INTERFACE)
    target_include_directories(WiringPi INTERFACE ${WiringPi_INCLUDE_DIR})
    target_link_libraries(WiringPi INTERFACE ${WiringPi_LIBRARY})
endif()
