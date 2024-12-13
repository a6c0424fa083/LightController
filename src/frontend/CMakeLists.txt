#
#  CMakeLists.txt
#  LightController
#  https://github.com/a6c0424fa083/LightController
#
#  Created by Jannis Sauer on 2024-12-10.
#

add_subdirectory(HeaderWindow)
add_subdirectory(SettingsWindow)
target_sources(${APPLICATION_NAME} PUBLIC BaseWindow.cpp MasterWindow.cpp)
