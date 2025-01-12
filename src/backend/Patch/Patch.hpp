//
//  Patch.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-22.
//

#ifndef PATCH_HPP
#define PATCH_HPP


#include <imgui.h>
#include <vector>

//#include "backend/GLOBAL.hpp"
#include "backend/Light/Light.hpp"
#include "frontend/BaseWindow.hpp"

struct PatchButton
{
    uint16_t address             = 0;
    bool     isUsed              = false;
    size_t   referenceLightIndex = -1;
    ImVec4   bgColor             = BaseWindow::default_ImGuiCol_Button;
    ImVec4   bgColorHovered      = BaseWindow::default_ImGuiCol_ButtonHovered;
    ImVec4   bgColorActive       = BaseWindow::default_ImGuiCol_ButtonActive;

    PatchButton() = default;
};

//void reloadPatchButtonsFromVector();



#endif  // PATCH_HPP
