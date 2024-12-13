#
#  CMakeLists.txt
#  LightController
#  https://github.com/a6c0424fa083/LightController
#
#  Created by Jannis Sauer on 2024-12-12.
#

add_subdirectory(ProjectManagerWindow)
add_subdirectory(LibraryManagerWindow)
target_sources(${APPLICATION_NAME} PUBLIC SettingsWindow.cpp)
