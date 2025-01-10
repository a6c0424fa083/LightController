//
//  Project.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-21.
//

#ifndef PROJECT_HPP
#define PROJECT_HPP


#include "backend/Light/Light.hpp"
#include "backend/defines.hpp"

struct Project
{
    // patch section
    uint16_t _validLights = 0;
    Light    _lights[512] = { Light {} };

    // scene section



    explicit Project(const std::vector<Light> &lights)
    {
        _validLights = lights.size();
        for (uint16_t i = 0; i < (lights.size() > 512 ? 512 : lights.size()); i++) { _lights[i] = lights.at(i); }
    }

    Project() = default;
};


#endif  // PROJECT_HPP
