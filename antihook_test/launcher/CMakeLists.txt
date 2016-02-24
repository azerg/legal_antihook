file(GLOB ProjInc "*.h")
file(GLOB ProjSrc "*.cpp")

find_package(Boost 1.36.0 REQUIRED filesystem system)

include_directories(${BOOST_ROOT})

add_executable(launcher ${ProjSrc} ${ProjInc})

target_link_libraries(launcher ${Boost_LIBRARIES})