#
#  CMakeLists.txt
#  LightController
#  https://github.com/a6c0424fa083/LightController
#
#  Created by Jannis Sauer on 2024-12-10.
#


############################
###   GENERAL SETTINGS   ###
############################

# set cmake minimal version
cmake_minimum_required(VERSION 3.25)

# define global standards
set(CMAKE_C_STANDARD          17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS        OFF)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# define build architecture
set(CMAKE_OSX_ARCHITECTURES    x86_64) # x86_64 / arm64
set(CMAKE_LIBRARY_ARCHITECTURE x84_64) # x86_64 / arm64

# define project
set(APPLICATION_NAME LightController)
option(BUILD_FOR_GUI_LAUNCH "Enable to execution via GUI (Terminal calls won't work)" OFF) # changes the Base-Path for the data

project(${APPLICATION_NAME}
    VERSION 0.1.0
    LANGUAGES C CXX
)

# set cmake module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/)

# include necessary modules
include(Warnings)


#######################
###   MAIN TARGET   ###
#######################

# add main target
add_executable(${APPLICATION_NAME})

# add sources
target_sources(${APPLICATION_NAME} PUBLIC main.cpp)

# main target options
target_set_warnings(${APPLICATION_NAME} ON OFF)
if (${BUILD_FOR_GUI_LAUNCH})
    target_compile_definitions(${APPLICATION_NAME} PUBLIC APPLICATION_DATA_PATH="Library/Application Support/LightController/")
else ()
    target_compile_definitions(${APPLICATION_NAME} PUBLIC APPLICATION_DATA_PATH="../applicationData/")
endif ()

# include subdirectories to build the project recursively
add_subdirectory(src)


#########################
###   ADD LIBRARIES   ###
#########################

# set library base path
set(LIB_BASE_DIR ${CMAKE_SOURCE_DIR}/lib/thirdParty)
set(OWN_LIB_BASE_DIR ${CMAKE_SOURCE_DIR}/lib/own)

# opengl
find_package(OpenGL REQUIRED) # easiest way to include OpenGL

# glfw
#set(GLFW_LIB_NAME glfw)
set(GLFW_LIB_NAME glfw)
set(GLFW_LIB_PATH ${LIB_BASE_DIR}/glfw) # set library path
add_subdirectory(${GLFW_LIB_PATH}) # build library from their build system (CMAKE)

# libusb
set(LIBUSB_LIB_NAME usb-1.0)
set(LIBUSB_LIB_PATH ${LIB_BASE_DIR}/libusb-cmake) # set library path
add_subdirectory(${LIBUSB_LIB_PATH}) # build library from their build system (CMAKE)
target_include_directories(${LIBUSB_LIB_NAME} PUBLIC
        ${LIBUSB_LIB_PATH}/libusb/libusb
        ${LIBUSB_LIB_PATH}/libusb/libusb/os
)

# imgui
set(IMGUI_LIB_NAME imgui) # set library name
set(IMGUI_LIB_PATH ${LIB_BASE_DIR}/imgui) # set library path
set(IMGUI_SOURCES
        ${IMGUI_LIB_PATH}/imgui_demo.cpp
        ${IMGUI_LIB_PATH}/imgui_draw.cpp
        ${IMGUI_LIB_PATH}/imgui_tables.cpp
        ${IMGUI_LIB_PATH}/imgui_widgets.cpp
        ${IMGUI_LIB_PATH}/imgui.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_allegro5.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_android.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_dx9.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_dx10.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_dx11.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_dx12.cpp
        ${IMGUI_LIB_PATH}/backends/imgui_impl_glfw.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_glut.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_metal.mm
        #${IMGUI_LIB_PATH}/backends/imgui_impl_opengl2.cpp
        ${IMGUI_LIB_PATH}/backends/imgui_impl_opengl3.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_osx.mm
        #${IMGUI_LIB_PATH}/backends/imgui_impl_sdl2.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_sdl3.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_sdlrenderer2.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_sdlrenderer3.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_vulkan.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_wgpu.cpp
        #${IMGUI_LIB_PATH}/backends/imgui_impl_win32.cpp
) # define all source files (only the ones necessary for OpenGL use are included here)
add_library(${IMGUI_LIB_NAME} ${IMGUI_SOURCES}) # add a library with defined source files
target_include_directories(${IMGUI_LIB_NAME} PUBLIC
        ${IMGUI_LIB_PATH}
        ${IMGUI_LIB_PATH}/backends
) # include the header files necessary

# implot
set(IMPLOT_LIB_NAME implot) # set library name
set(IMPLOT_LIB_PATH ${LIB_BASE_DIR}/implot) # set library path
set(IMPLOT_SOURCES
        ${IMPLOT_LIB_PATH}/implot.cpp
        ${IMPLOT_LIB_PATH}/implot_items.cpp
)
add_library(${IMPLOT_LIB_NAME} ${IMPLOT_SOURCES}) # add a library with defined source files
target_include_directories(${IMPLOT_LIB_NAME} PUBLIC
        ${IMPLOT_LIB_PATH}
)



##########################
###   Link LIBRARIES   ###
##########################

# imgui
target_link_libraries(${IMGUI_LIB_NAME} PUBLIC ${GLFW_LIB_NAME}) # link glfw to imgui
target_link_libraries(${IMGUI_LIB_NAME} PUBLIC OpenGL::GL) # link OpenGL to imgui ('OpenGL:GL' is the system name of the library)

target_link_libraries(${IMPLOT_LIB_NAME} PUBLIC ${IMGUI_LIB_NAME})

# main
target_link_libraries(${APPLICATION_NAME} PUBLIC ${IMPLOT_LIB_NAME}) # OpenGL and glfw are already linked publicly to imgui
target_link_libraries(${APPLICATION_NAME} PUBLIC ${LIBUSB_LIB_NAME})



###################################
###   Post-Build-Instructions   ###
###################################

# select build mode
if (${BUILD_FOR_GUI_LAUNCH})
#add_custom_command(TARGET ${APPLICATION_NAME} POST_BUILD
#    COMMAND cp ${CMAKE_SOURCE_DIR}/cmake-build-production/LightController /Applications/
#)
endif ()
