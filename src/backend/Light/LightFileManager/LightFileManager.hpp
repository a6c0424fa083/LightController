//
//  LightFileManager.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-16.
//

#ifndef LIGHTFILEMANAGER_HPP
#define LIGHTFILEMANAGER_HPP


/**
 * I know that the library should be realised with a proper database
 * since the current design has horroble time complexity.
 * But as this project is intended for a smaller amount of lights
 * I found it reasenable to use this approch for now to focus
 * on other things first.
 */


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
};


#endif  // LIGHTFILEMANAGER_HPP
