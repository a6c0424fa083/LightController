//
//  GLOBAL.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-11.
//

#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <cstdint>
#include <string>
#include <vector>

#include <imgui.h>

#include "backend/Light/Light.hpp"


namespace GLOBAL
{
    namespace HEADERWINDOW
    {
        inline std::vector<std::string> sections = { "Patch", "CH Control", "Scene Editor", "Live", "Settings" };

        inline uint8_t activeSection    = sections.size() - 1;  // set last element (= settings) to active
        inline uint8_t progressBarProg  = 127;
        inline auto    progressBarColor = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
        inline auto    size             = ImVec2(0.0f, 0.0f);
        inline auto    pos              = ImVec2(0.0f, 0.0f);
    };  // namespace HEADERWINDOW

    namespace ADDLIGHTWINDOW
    {
        inline bool isWindowActive = false;
        inline bool cameFromListLightsWindow = false;
        inline bool isEditMode = false;
        inline Light lightToEdit = Light{};
    };

    namespace LIGHTFILEMANAGER
    {
        inline std::vector<Light> lightsLibrary;
    };

    namespace LISTLIGHTSWINDOW
    {
        inline bool isWindowActive = false;
        inline size_t activeItemIndex = 0;
    };

};  // namespace GLOBAL



#endif  // GLOBAL_HPP
