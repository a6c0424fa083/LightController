//
//  PatchWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-22.
//

#ifndef PATCHWINDOW_HPP
#define PATCHWINDOW_HPP


#include <imgui.h>

#include "backend/GLOBAL.hpp"
#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"
#include "frontend/PatchWindow/LightInfoWindow/LightInfoWindow.hpp"
#include "frontend/PatchWindow/SelectLightWindow/SelectLightWindow.hpp"

class PatchWindow : BaseWindow
{
public:
    ~PatchWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

    static ImVec2 getIdealWindowSize() { return _idealWindowSize; };

private:
    ImVec2 _pos;
    ImVec2 _size;

    // colums * rows = 512 !!
    static constexpr uint8_t colums = 16;
    static constexpr uint8_t rows   = 32;

    float buttonSize;

    inline static auto _idealWindowSize = ImVec2(0.0f, 0.0f);

    ImVec2             selectLightWindowSize = ImVec2(0.0f, 0.0f);
    SelectLightWindow *selectLightWindow     = new SelectLightWindow();

    ImVec2           lightInfoWindowSize = ImVec2(0.0f, 0.0f);
    LightInfoWindow *lightInfoWindow     = new LightInfoWindow();
};



#endif  // PATCHWINDOW_HPP
