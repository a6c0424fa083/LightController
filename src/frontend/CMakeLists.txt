#
#  CMakeLists.txt
#  LightController
#  https://github.com/a6c0424fa083/LightController
#
#  Created by Jannis Sauer on 2024-12-10.
#

add_subdirectory(HeaderWindow)
add_subdirectory(SettingsWindow)
add_subdirectory(PatchWindow)
add_subdirectory(ClearWindow)
add_subdirectory(ArrangeWindow)
target_sources(${APPLICATION_NAME} PUBLIC BaseWindow.cpp MasterWindow.cpp)
