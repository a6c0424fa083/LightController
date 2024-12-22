#
#  CMakeLists.txt
#  LightController
#  https://github.com/a6c0424fa083/LightController
#
#  Created by Jannis Sauer on 2024-12-21.
#

add_subdirectory(ProjectManager)
target_sources(${APPLICATION_NAME} PUBLIC Project.cpp)
