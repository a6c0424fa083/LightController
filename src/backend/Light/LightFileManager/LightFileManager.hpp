//
//  LightFileManager.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-16.
//

#ifndef LIGHTFILEMANAGER_HPP
#define LIGHTFILEMANAGER_HPP


#include <cstring>
#include <filesystem>
#include <fstream>
#include <imgui.h>

#include "backend/GLOBAL.hpp"
#include "backend/Light/Light.cpp"
#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"

class LightFileManager : BaseWindow
{
public:
    ~LightFileManager();
    static uint8_t addLightToLibrary(Light light);
    static uint8_t loadLightsFromLibrary();
    static uint8_t deleteLightByIndex(size_t index);
    static void    printLights();
    static void    printLight(Light light);
};


#endif  // LIGHTFILEMANAGER_HPP
