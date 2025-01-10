//
//  PatchManager.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2025-01-10.
//

#include "PatchManager.hpp"

uint8_t PatchManager::reloadPatchButtonsFromVector2()
{
    // clear all patchButton states
    for (uint16_t i = 0; i < 512; i++)
    {
        GLOBAL::PATCH::patchButtons.at(i).isUsed  = false;
        GLOBAL::PATCH::patchButtons.at(i).address = i + 1;
        // for later
        // GLOBAL::PATCH::patchButtons.at(i).bgColor
        // GLOBAL::PATCH::patchButtons.at(i).bgColorActive
        // GLOBAL::PATCH::patchButtons.at(i).bgColorHovered
        GLOBAL::PATCH::patchButtons.at(i).referenceLightIndex = -1;
    }

    // fill in the vector information

    for (size_t i = 0; i < GLOBAL::PATCH::patchLights.size(); i++)
    {
        for (size_t j = 0; j < GLOBAL::PATCH::patchLights.at(i).channelCount; j++) {
            GLOBAL::PATCH::patchButtons.at(GLOBAL::PATCH::patchLights.at(i).rootAddress + j - 1).isUsed         = true;
            //auto *light                                      = new Light(GLOBAL::PATCH::patchLights.at(i), i + 1);
            GLOBAL::PATCH::patchButtons.at(GLOBAL::PATCH::patchLights.at(i).rootAddress + j - 1).referenceLightIndex = i;
        }
    }
}