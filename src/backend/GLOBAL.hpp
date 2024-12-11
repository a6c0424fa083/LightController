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

namespace GLOBAL
{
    namespace HEADERWINDOW
    {
        inline std::vector<std::string> sections = { "Patch", "Mapping", "Scene Editor", "Live", "Settings" };

        inline uint8_t activeSection    = sections.size() - 1;  // set last element (= settings) to active
        inline uint8_t progressBarProg  = 127;
        inline auto    progressBarColor = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);

    };  // namespace HEADERWINDOW

};  // namespace GLOBAL



#endif  // GLOBAL_HPP
