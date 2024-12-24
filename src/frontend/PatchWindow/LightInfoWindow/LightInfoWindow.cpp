//
//  LightInfoWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-24.
//

#include "LightInfoWindow.hpp"

#define light (GLOBAL::LIGHTINFOWINDOW::light)

LightInfoWindow::~LightInfoWindow() {}

void LightInfoWindow::Draw(ImVec2 pos, ImVec2 size)
{
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(NUMBER);
    setWindowPosSize(_pos, _size);

    ImGui::Begin("LightInfoWindow", nullptr, STATIC__NO_VISUALS);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}

void LightInfoWindow::DrawContents()
{
    static ImVec2 lastCursorPos;

#define secondRowPosY (ImGui::CalcTextSize("Channel Count: ").x + 2 * saveMargin)

    ImGui::PushFont(TITLE);
    ImGui::SetCursorPos(ImVec2(_size.x / 2.0f - ImGui::CalcTextSize("View Light").x / 2.0f, saveMargin));
    ImGui::Text("View Light");
    ImGui::PopFont();

    lastCursorPos = ImGui::GetCursorPos();

    ImGui::SetCursorPos(ImVec2(saveMargin, lastCursorPos.y + saveMargin));
    ImGui::Text("Manufacturer: ");
    ImGui::SetCursorPos(ImVec2(secondRowPosY, lastCursorPos.y + saveMargin));
    ImGui::SetNextItemWidth(_size.x - secondRowPosY - saveMargin);
    ImGui::InputText("##Manufacturer", light->manufacturer, MAX_LIGHT_MANUFACTURER_LENGTH, ImGuiInputTextFlags_ReadOnly);

    lastCursorPos = ImGui::GetCursorPos();

    ImGui::SetCursorPos(ImVec2(saveMargin, lastCursorPos.y + saveMargin));
    ImGui::Text("Name: ");
    ImGui::SetCursorPos(ImVec2(secondRowPosY, lastCursorPos.y + saveMargin));
    ImGui::SetNextItemWidth(_size.x - secondRowPosY - saveMargin);
    ImGui::InputText("##Name", light->name, MAX_LIGHT_NAME_LENGTH, ImGuiInputTextFlags_ReadOnly);

    lastCursorPos = ImGui::GetCursorPos();

    ImGui::SetCursorPos(ImVec2(saveMargin, lastCursorPos.y + saveMargin));
    ImGui::Text("Channel Count: ");
    ImGui::SetCursorPos(ImVec2(secondRowPosY, lastCursorPos.y + saveMargin));
    ImGui::SetNextItemWidth(80.0f);
    int _channelCount = light->channelCount;
    ImGui::InputInt("##ChannelCount", &_channelCount, 1, 10, ImGuiInputTextFlags_ReadOnly);
    light->channelCount = _channelCount;

    lastCursorPos = ImGui::GetCursorPos();


    // ImGui::SetNextWindowPos(ImVec2(saveMargin, lastCursorPos.y + saveMargin));
    ImGui::SetCursorPos(ImVec2(saveMargin, lastCursorPos.y + saveMargin));
    ImGui::PushFont(SUBTITLE);  // _size.y * 0.55f
    ImGui::BeginChild("ChannelContainer",
                      ImVec2(_size.x - 2 * saveMargin, _size.y - lastCursorPos.y - 5 * saveMargin - ImGui::CalcTextSize("XXX").y),
                      true,
                      ImGuiWindowFlags_AlwaysVerticalScrollbar);
    ImGui::PopFont();
    /*if (light->channelCount == 0)
    {
        ImGui::Text("No channels available.");
        ImGui::EndChild();
        return;
    }*/

    // Create two columns for the channel index and combo box
    ImGui::SetCursorPos(ImVec2(_size.x / 2.0f - ImGui::CalcTextSize("Channel Functions").x / 2.0f, saveMargin));
    ImGui::Text("Channel Functions");
    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + saveMargin));
    ImGui::Columns(4, nullptr, false);

    for (uint16_t i = 0; i < light->channelCount; ++i)
    {
        // First column: Channel index
        ImGui::Text("%3d", i + 1);
        ImGui::SameLine();
        // Dropdown to select the channel function on the same line
        ImGui::PushID(i);  // Ensure unique ID for each combo
        const char *currentFunction = channelFunctionStr[static_cast<int>(light->channelFunction[i])].c_str();
        ImGui::SetNextItemWidth(-1);  // Use full width of remaining column space

        if (ImGui::BeginCombo("##ChannelFunction", currentFunction))
        {
            for (size_t j = 0; j < channelFunctionStr.size(); ++j)
            {
                bool isSelected = (light->channelFunction[i] == static_cast<uint8_t>(j));
                ImGui::Selectable(channelFunctionStr[j].c_str(), isSelected, ImGuiSelectableFlags_Disabled);
            }
            ImGui::EndCombo();
        }

        ImGui::PopID();

        ImGui::NextColumn();  // Go to next column
    }

    ImGui::Columns(1);  // Reset columns
    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + saveMargin));
    ImGui::EndChild();


    ImGui::PushFont(SUBTITLE);

    style.Colors[ImGuiCol_Button]        = red_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = red_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = red_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(_size.x - saveMargin - ImGui::CalcTextSize("Cancel").x - 2 * saveMargin,
                               _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));

    if (ImGui::Button("Delete",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)) ||
        (ImGui::IsKeyPressed(ImGuiKey_Delete) && !GLOBAL::KEYHANDLER::isKeyDown_Delete))
    {

        for (uint16_t i = light->rootAddress - 1; i < light->rootAddress - 1 + light->channelCount; i++)
        {
            //if (GLOBAL::PATCH::patchButtons.at(i).referenceLight->name == light->name)
            //{
                GLOBAL::PATCH::patchButtons.at(i).isUsed         = false;
                GLOBAL::PATCH::patchButtons.at(i).referenceLight = nullptr;
            //}
        }

        GLOBAL::LIGHTINFOWINDOW::isWindowActive = false;
    }


    ImGui::SetCursorPos(ImVec2(saveMargin, _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Cancel",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)) ||
        (ImGui::IsKeyPressed(ImGuiKey_Escape) && !GLOBAL::KEYHANDLER::isKeyDown_Escape))
    {
        GLOBAL::LIGHTINFOWINDOW::isWindowActive = false;
    }

    style.Colors[ImGuiCol_Button]        = default_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = default_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = default_ImGuiCol_ButtonActive;


    ImGui::PopFont();

    _idealWindowSize =
        ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::size.y - GLOBAL::HEADERWINDOW::pos.y - 2 * saveMargin);

#undef secondRowPosY
}
