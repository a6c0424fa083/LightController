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

    if (GLOBAL::ADDLIGHTWINDOW::isEditMode && !loadedLightToEdit)
    {
        _light            = GLOBAL::ADDLIGHTWINDOW::lightToEdit;
        loadedLightToEdit = true;
    }

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

    lastCursorPos = ImGui::GetCursorPos();


    //// Loop through each channel and render the UI
    // for (uint16_t i = 0; i < _light.channelCount; ++i)
    //{
    //     ImGui::Text("Channel %d", i + 1);  // First column: Channel index
    //     ImGui::NextColumn();               // Move to second column
    //
    //    // Dropdown to select the channel function
    //    const char *currentFunction = channelFunctionStr[static_cast<int>(_light.channelFunction[i])].c_str();
    //    if (ImGui::BeginCombo(("##ChannelFunction" + std::to_string(i)).c_str(), currentFunction))
    //    {
    //        for (size_t j = 0; j < channelFunctionStr.size(); ++j)
    //        {
    //            bool isSelected = (_light.channelFunction[i] == static_cast<CHANNEL_FUNCTION>(j));
    //            if (ImGui::Selectable(channelFunctionStr[j].c_str(), isSelected))
    //            {
    //                _light.channelFunction[i] = static_cast<CHANNEL_FUNCTION>(j);
    //            }
    //            if (isSelected) ImGui::SetItemDefaultFocus();  // Ensure focus remains on the selected item
    //        }
    //        ImGui::EndCombo();
    //    }
    //    ImGui::NextColumn();  // Return to the first column for the next row
    //}

    // ImGui::SetNextWindowPos(ImVec2(saveMargin, lastCursorPos.y + saveMargin));
    ImGui::SetCursorPos(ImVec2(saveMargin, lastCursorPos.y + saveMargin));
    ImGui::PushFont(SUBTITLE);  // _size.y * 0.55f
    ImGui::BeginChild("ChannelContainer",
                      ImVec2(_size.x - 2 * saveMargin, _size.y - lastCursorPos.y - 5 * saveMargin - ImGui::CalcTextSize("XXX").y),
                      true,
                      ImGuiWindowFlags_AlwaysVerticalScrollbar);
    ImGui::PopFont();
    /*if (_light.channelCount == 0)
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

    for (uint16_t i = 0; i < _light.channelCount; ++i)
    {
        // First column: Channel index
        ImGui::Text("%3d", i + 1);
        ImGui::SameLine();
        // Dropdown to select the channel function on the same line
        ImGui::PushID(i);  // Ensure unique ID for each combo
        const char *currentFunction = channelFunctionStr[static_cast<int>(_light.channelFunction[i])].c_str();
        ImGui::SetNextItemWidth(-1);  // Use full width of remaining column space

        if (ImGui::BeginCombo("##ChannelFunction", currentFunction))
        {
            for (size_t j = 0; j < channelFunctionStr.size(); ++j)
            {
                bool isSelected = (_light.channelFunction[i] == static_cast<uint8_t>(j));
                if (ImGui::Selectable(channelFunctionStr[j].c_str(), isSelected))
                {
                    _light.channelFunction[i] = static_cast<CHANNEL_FUNCTION>(static_cast<uint8_t>(j));
                }
                if (isSelected) ImGui::SetItemDefaultFocus();
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

    style.Colors[ImGuiCol_Button]        = green_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = green_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = green_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(_size.x - saveMargin - ImGui::CalcTextSize("Cancel").x - 2 * saveMargin,
                               _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (GLOBAL::ADDLIGHTWINDOW::isEditMode)
    {
        if (ImGui::Button("Save",
                          ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)) || (ImGui::IsKeyPressed(ImGuiKey_Enter) && !GLOBAL::KEYHANDLER::isKeyDown_Enter))
        {
            GLOBAL::KEYHANDLER::isKeyDown_Enter = true;
            // add the light struct to file system
            LightFileManager::deleteLightByIndex(GLOBAL::LISTLIGHTSWINDOW::activeItemIndex);
            LightFileManager::addLightToLibrary(_light);

            if (GLOBAL::ADDLIGHTWINDOW::cameFromListLightsWindow) GLOBAL::LISTLIGHTSWINDOW::isWindowActive = true;

            GLOBAL::ADDLIGHTWINDOW::isWindowActive = false;
            memset(_light.name, '\0', MAX_LIGHT_NAME_LENGTH);
            memset(_light.manufacturer, '\0', MAX_LIGHT_MANUFACTURER_LENGTH);
            _light.channelCount = 0;
            memset(_light.channelFunction, CHANNEL_FUNCTION::CHANNEL, 512);
            memset(_light.channelFunctionIdentifier, 0, 512);

            loadedLightToEdit = false;

            GLOBAL::ADDLIGHTWINDOW::isEditMode = false;
        }
    }
    else
    {
        if (ImGui::Button("Add",
                          ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)) || (ImGui::IsKeyPressed(ImGuiKey_Enter) && !GLOBAL::KEYHANDLER::isKeyDown_Enter))
        {
            GLOBAL::KEYHANDLER::isKeyDown_Enter = true;
            // add the light struct to file system
            LightFileManager::addLightToLibrary(_light);

            if (GLOBAL::ADDLIGHTWINDOW::cameFromListLightsWindow) GLOBAL::LISTLIGHTSWINDOW::isWindowActive = true;

            GLOBAL::ADDLIGHTWINDOW::isWindowActive = false;
            memset(_light.name, '\0', MAX_LIGHT_NAME_LENGTH);
            memset(_light.manufacturer, '\0', MAX_LIGHT_MANUFACTURER_LENGTH);
            _light.channelCount = 0;
            memset(_light.channelFunction, CHANNEL_FUNCTION::CHANNEL, 512);
            memset(_light.channelFunctionIdentifier, 0, 512);
        }
    }

    style.Colors[ImGuiCol_Button]        = red_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = red_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = red_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(saveMargin, _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Cancel",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)) || (ImGui::IsKeyPressed(ImGuiKey_Escape) && !GLOBAL::KEYHANDLER::isKeyDown_Escape))
    {
        GLOBAL::KEYHANDLER::isKeyDown_Escape = true;
        GLOBAL::ADDLIGHTWINDOW::isWindowActive = false;
        if (GLOBAL::ADDLIGHTWINDOW::cameFromListLightsWindow) GLOBAL::LISTLIGHTSWINDOW::isWindowActive = true;
        memset(_light.name, '\0', MAX_LIGHT_NAME_LENGTH);
        memset(_light.manufacturer, '\0', MAX_LIGHT_MANUFACTURER_LENGTH);
        _light.channelCount = 0;
        memset(_light.channelFunction, CHANNEL_FUNCTION::CHANNEL, 512);
        memset(_light.channelFunctionIdentifier, 0, 512);

        if (GLOBAL::ADDLIGHTWINDOW::isEditMode)
        {
            loadedLightToEdit                  = false;
            GLOBAL::ADDLIGHTWINDOW::isEditMode = false;
        }
    }

    style.Colors[ImGuiCol_Button]        = default_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = default_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = default_ImGuiCol_ButtonActive;

    // ImGui::SetCursorPos(ImVec2(_size.x - 3 * saveMargin - 3 * ImGui::CalcTextSize("Cancel").x - 6 * saveMargin,
    //                            _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    /*ImGui::SetCursorPos(ImVec2(_size.x - 2 * saveMargin - 2 * ImGui::CalcTextSize("Cancel").x - 4 * saveMargin,
                               _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Print",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
    {
        LightFileManager::loadLightsFromLibrary();
        LightFileManager::printLights();
    }*/

    ImGui::PopFont();

    _idealWindowSize =
        ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::size.y - GLOBAL::HEADERWINDOW::pos.y - 2 * saveMargin);

#undef secondRowPosY
}
