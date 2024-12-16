//
//  AddLightWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-14.
//

#include "AddLightWindow.hpp"

AddLightWindow::~AddLightWindow() {}

void AddLightWindow::Draw(ImVec2 pos, ImVec2 size)
{
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(NUMBER);
    setWindowPosSize(_pos, _size);

    ImGui::Begin("AddLightWindow", nullptr, STATIC__NO_VISUALS);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}

void AddLightWindow::DrawContents()
{
    static ImVec2 lastCursorPos;

#define secondRowPosY (ImGui::CalcTextSize("Channel Count: ").x + 2 * saveMargin)

    ImGui::PushFont(TITLE);
    ImGui::SetCursorPos(ImVec2(_size.x / 2.0f - ImGui::CalcTextSize("Configure new Light").x / 2.0f, saveMargin));
    ImGui::Text("Configure new Light");
    ImGui::PopFont();

    lastCursorPos = ImGui::GetCursorPos();

    ImGui::SetCursorPos(ImVec2(saveMargin, lastCursorPos.y + saveMargin));
    ImGui::Text("Manufacturer: ");
    ImGui::SetCursorPos(ImVec2(secondRowPosY, lastCursorPos.y + saveMargin));
    ImGui::SetNextItemWidth(_size.x - secondRowPosY - saveMargin);
    ImGui::InputText("##Manufacturer", _light.manufacturer, MAX_LIGHT_MANUFACTURER_LENGTH);

    lastCursorPos = ImGui::GetCursorPos();

    ImGui::SetCursorPos(ImVec2(saveMargin, lastCursorPos.y + saveMargin));
    ImGui::Text("Name: ");
    ImGui::SetCursorPos(ImVec2(secondRowPosY, lastCursorPos.y + saveMargin));
    ImGui::SetNextItemWidth(_size.x - secondRowPosY - saveMargin);
    ImGui::InputText("##Name", _light.name, MAX_LIGHT_NAME_LENGTH);

    lastCursorPos = ImGui::GetCursorPos();

    ImGui::SetCursorPos(ImVec2(saveMargin, lastCursorPos.y + saveMargin));
    ImGui::Text("Channel Count: ");
    ImGui::SetCursorPos(ImVec2(secondRowPosY, lastCursorPos.y + saveMargin));
    ImGui::SetNextItemWidth(80.0f);
    int _channelCount = _light.channelCount;
    ImGui::InputInt("##ChannelCount", &_channelCount, 1, 10);
    _light.channelCount = _channelCount;


    // Loop through each channel and render the UI
    for (uint16_t i = 0; i < _light.channelCount; ++i)
    {
        ImGui::Text("Channel %d", i + 1);  // First column: Channel index
        ImGui::NextColumn();               // Move to second column

        // Dropdown to select the channel function
        const char *currentFunction = channelFunctionStr[static_cast<int>(_light.channelFunction[i])].c_str();
        if (ImGui::BeginCombo(("##ChannelFunction" + std::to_string(i)).c_str(), currentFunction))
        {
            for (size_t j = 0; j < channelFunctionStr.size(); ++j)
            {
                bool isSelected = (_light.channelFunction[i] == static_cast<CHANNEL_FUNCTION>(j));
                if (ImGui::Selectable(channelFunctionStr[j].c_str(), isSelected))
                {
                    _light.channelFunction[i] = static_cast<CHANNEL_FUNCTION>(j);
                }
                if (isSelected) ImGui::SetItemDefaultFocus();  // Ensure focus remains on the selected item
            }
            ImGui::EndCombo();
        }
        ImGui::NextColumn();  // Return to the first column for the next row
    }


    ImGui::PushFont(SUBTITLE);

    style.Colors[ImGuiCol_Button]        = green_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = green_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = green_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(_size.x - saveMargin - ImGui::CalcTextSize("Cancel").x - 2 * saveMargin,
                               _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Add", ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
    {
        // add the light struct to file system
    }

    style.Colors[ImGuiCol_Button]        = red_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = red_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = red_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(_size.x - 2 * saveMargin - 2 * ImGui::CalcTextSize("Cancel").x - 4 * saveMargin,
                               _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Cancel",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
    {
        GLOBAL::ADDLIGHTWINDOW::isWindowActive = false;
        memset(_light.name, '\0', MAX_LIGHT_NAME_LENGTH);
        memset(_light.manufacturer, '\0', MAX_LIGHT_MANUFACTURER_LENGTH);
        _light.channelCount = 0;
        memset(_light.channelFunction, CHANNEL_FUNCTION::CHANNEL, 512);
        memset(_light.channelFunctionIdentifier, 0, 512);
    }

    style.Colors[ImGuiCol_Button]        = default_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = default_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = default_ImGuiCol_ButtonActive;

    ImGui::PopFont();

    _idealWindowSize =
        ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::size.y - GLOBAL::HEADERWINDOW::pos.y - 2 * saveMargin);

#undef secondRowPosY
}
