file(GLOB MainProjInc "*.h")
file(GLOB MainProjSrc "*.cpp")

add_library(SampleDll MODULE ${MainProjSrc} ${MainProjInc})