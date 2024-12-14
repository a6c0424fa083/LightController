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
    ImGui::Text("Name: ");
    ImGui::SetCursorPos(ImVec2(secondRowPosY, lastCursorPos.y + saveMargin));
    ImGui::SetNextItemWidth(_size.x - secondRowPosY - saveMargin);
    ImGui::InputText("##Name", _name, MAX_LIGHT_NAME_LENGTH);

    lastCursorPos = ImGui::GetCursorPos();

    ImGui::SetCursorPos(ImVec2(saveMargin, lastCursorPos.y + saveMargin));
    ImGui::Text("Manufacturer: ");
    ImGui::SetCursorPos(ImVec2(secondRowPosY, lastCursorPos.y + saveMargin));
    ImGui::SetNextItemWidth(_size.x - secondRowPosY - saveMargin);
    ImGui::InputText("##Manufacturer", _manufacturer, MAX_LIGHT_MANUFACTURER_LENGTH);

    lastCursorPos = ImGui::GetCursorPos();

    ImGui::SetCursorPos(ImVec2(saveMargin, lastCursorPos.y + saveMargin));
    ImGui::Text("Channel Count: ");
    ImGui::SetCursorPos(ImVec2(secondRowPosY, lastCursorPos.y + saveMargin));
    ImGui::SetNextItemWidth(80.0f);
    ImGui::InputInt("##ChannelCount", &_channelCount, 1, 10);


    _idealWindowSize = ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::size.y - GLOBAL::HEADERWINDOW::pos.y - 2 * saveMargin);

#undef secondRowPosY
}
