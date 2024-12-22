//
//  Project.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-21.
//

#ifndef PROJECT_HPP
#define PROJECT_HPP


#include "backend/GLOBAL.hpp"
#include "backend/Light/Light.hpp"
#include "backend/defines.hpp"

struct Project
{
    // patch section
    uint16_t validLight  = 0;
    Light    lights[512] = { Light {} };

    // scene section
};



#endif  // PROJECT_HPP
