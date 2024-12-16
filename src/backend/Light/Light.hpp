//
//  Light.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-14.
//

#ifndef LIGHT_HPP
#define LIGHT_HPP


#include <array>

#include "backend/Light/ChannelFunction/ChannelFunction.hpp"
#include "backend/defines.hpp"

struct Light
{
    uint16_t         channelCount                                = 0;
    uint16_t         rootAddress                                 = 1;
    CHANNEL_FUNCTION channelFunction[512]                        = { CHANNEL_FUNCTION::CHANNEL };
    uint8_t          channelFunctionIdentifier[512]              = { 0 };
    char             name[MAX_LIGHT_NAME_LENGTH]                 = { 0 };
    char             manufacturer[MAX_LIGHT_MANUFACTURER_LENGTH] = { 0 };
};


#endif  // LIGHT_HPP
