#
#  CMakeLists.txt
#  LightController
#  https://github.com/a6c0424fa083/LightController
#
#  Created by Jannis Sauer on 2024-12-13.
#

add_subdirectory(AddLightWindow)
add_subdirectory(ListLightsWindow)
target_sources(${APPLICATION_NAME} PUBLIC LibraryManagerWindow.cpp)
