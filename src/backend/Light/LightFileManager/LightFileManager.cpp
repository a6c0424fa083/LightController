//
//  LightFileManager.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-16.
//

#include "LightFileManager.hpp"

uint8_t LightFileManager::addLightToLibrary(Light light)
{
    // base directory to the light "database"
    const std::string baseDir = std::filesystem::current_path().string() + "/" + std::string(LIGHT_LIBRARY_PATH);

    // check for existence of directory
    if (!std::filesystem::exists(baseDir)) return 2;

    // the path to the library file
    std::string lightsFilePath = baseDir + "library.LClib";


    // check if the library file already exists (if not: create one)
    if (!std::filesystem::exists(lightsFilePath))
    {
        std::ofstream createFile(lightsFilePath, std::ios::binary);
        if (!createFile.is_open()) return 2;  // Filesystem error
        createFile.close();
    }


    // open library file and check if it was opened successfully
    std::ifstream inFile(lightsFilePath, std::ios::binary);
    if (!inFile.is_open())
    {
        fprintf(stderr, "Error opening file for reading\n");
        return 2;  // Filesystem error
    }


    // check if the light already exists (if so: exit)
    Light existingLight;
    while (inFile.read(reinterpret_cast<char *>(&existingLight), sizeof(Light)))
    {
        if (std::strcmp(existingLight.name, light.name) == 0)
        {
            // fprintf(stderr, "Light already exists\n");
            return 1;  // Light already exists
        }
    }
    inFile.close();


    // write the light data to the file
    std::ofstream outFile(lightsFilePath, std::ios::binary | std::ios::app);

    if (!outFile.is_open())
    {
        fprintf(stderr, "Error opening file for writing\n");
        return 2;  // Filesystem error
    }

    outFile.write(reinterpret_cast<const char *>(&light), sizeof(Light));
    outFile.close();


    return 0;
}