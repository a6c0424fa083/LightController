//
//  KeyboardInputHandler.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-21.
//

#include "KeyboardInputHandler.hpp"

#include <backend/GLOBAL.hpp>

void KeyboardInputHandler::updateKeyStatus()
{
    if (ImGui::IsKeyReleased(ImGuiKey_Escape)) GLOBAL::KEYHANDLER::isKeyDown_Escape = false;

    if (ImGui::IsKeyReleased(ImGuiKey_Enter)) GLOBAL::KEYHANDLER::isKeyDown_Enter = false;

    if (ImGui::IsKeyReleased(ImGuiKey_A)) GLOBAL::KEYHANDLER::isKeyDown_A = false;

    if (ImGui::IsKeyReleased(ImGuiKey_E)) GLOBAL::KEYHANDLER::isKeyDown_E = false;

    if (ImGui::IsKeyReleased(ImGuiKey_Delete)) GLOBAL::KEYHANDLER::isKeyDown_Delete = false;

    if (ImGui::IsKeyReleased(ImGuiKey_DownArrow)) GLOBAL::KEYHANDLER::isKeyDown_DownArrow = false;

    if (ImGui::IsKeyReleased(ImGuiKey_UpArrow)) GLOBAL::KEYHANDLER::isKeyDown_UpArrow = false;
}
