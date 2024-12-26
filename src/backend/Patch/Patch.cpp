//
//  Patch.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-22.
//

#include "Patch.hpp"

#include <backend/GLOBAL.hpp>

void reloadPatchButtonsFromVector()
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
        GLOBAL::PATCH::patchButtons.at(i).referenceLight = nullptr;
    }

    // fill in the vector information

    for (uint16_t i = 0; i < GLOBAL::PATCH::patchLights.size(); i++)
    {
        GLOBAL::PATCH::patchButtons.at(i).isUsed         = true;
        auto *light                                      = new Light(GLOBAL::PATCH::patchLights.at(i), i + 1);
        GLOBAL::PATCH::patchButtons.at(i).referenceLight = light;
    }
}
