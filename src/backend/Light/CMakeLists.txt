#
#  CMakeLists.txt
#  LightController
#  https://github.com/a6c0424fa083/LightController
#
#  Created by Jannis Sauer on 2024-12-14.
#

add_subdirectory(LightFileManager)
add_subdirectory(ChannelFunction)
target_sources(${APPLICATION_NAME} PUBLIC Light.cpp)
