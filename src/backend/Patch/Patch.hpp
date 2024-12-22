//
//  Patch.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-22.
//

#ifndef PATCH_HPP
#define PATCH_HPP


#include <vector>
#include <imgui.h>

#include "backend/Light/Light.hpp"
#include "frontend/BaseWindow.hpp"

struct PatchButton {
    uint16_t address = 0;
    bool isUsed = false;
    Light *referenceLight = nullptr;
    ImVec4 bgColor = BaseWindow::default_ImGuiCol_Button;
    ImVec4 bgColorHovered = BaseWindow::default_ImGuiCol_ButtonHovered;
    ImVec4 bgColorActive = BaseWindow::default_ImGuiCol_ButtonActive;
};



#endif //PATCH_HPP
