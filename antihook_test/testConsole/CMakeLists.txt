file(GLOB ProjInc "*.h")
file(GLOB ProjSrc "*.cpp")

add_executable(testConsole ${ProjSrc} ${ProjInc})