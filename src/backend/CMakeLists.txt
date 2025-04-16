#
#  CMakeLists.txt
#  LightController
#  https://github.com/a6c0424fa083/LightController
#
#  Created by Jannis Sauer on 2024-12-10.
#

add_subdirectory(Light)
add_subdirectory(KeyboardInputHandler)
add_subdirectory(Project)
add_subdirectory(Patch)
add_subdirectory(USB)
target_sources(${APPLICATION_NAME} PUBLIC GLOBAL.cpp)
