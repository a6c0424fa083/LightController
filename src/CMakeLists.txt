#
#  main.cpp
#  LightController
#  https://github.com/a6c0424fa083/LightController
#
#  Created by Jannis Sauer on 2024-12-10.
#


target_include_directories(${APPLICATION_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(backend)
add_subdirectory(frontend)
