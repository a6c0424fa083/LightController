//
//  LightFileManager.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-16.
//

#include "LightFileManager.hpp"

LightFileManager::~LightFileManager()
{
    // delete GLOBAL::LIGHTFILEMANAGER::lightsLibrary;
    // GLOBAL::LIGHTFILEMANAGER::lightsLibrary = nullptr;
}

uint8_t LightFileManager::addLightToLibrary(Light light)
{
    // base directory to the light "database"
    const std::string baseDir = std::filesystem::current_path().string() + "/" + std::string(LIGHT_LIBRARY_PATH);

    // check for existence of directory
    if (!std::filesystem::exists(baseDir) || !std::filesystem::is_directory(baseDir)) return 2;

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


uint8_t LightFileManager::loadLightsFromLibrary()
{
    GLOBAL::LIGHTFILEMANAGER::lightsLibrary.clear();


    // base directory to the light "database"
    const std::string baseDir = std::filesystem::current_path().string() + "/" + std::string(LIGHT_LIBRARY_PATH);


    // Check if the base directory exists
    if (!std::filesystem::exists(baseDir) || !std::filesystem::is_directory(baseDir))
    {
        fprintf(stderr, "Base directory does not exist or is invalid\n");
        return 2;  // filesystem error
    }


    // the path to the library file
    std::string lightsFilePath = baseDir + "library.LClib";

    if (!std::filesystem::exists(lightsFilePath))
    {
        std::ofstream file(lightsFilePath, std::ios::binary);
        if (!file.is_open())
        {
            fprintf(stderr, "Error opening file: \n");
            return 2;  // filesystem error
        }
        file.close();
    }

    std::ifstream inFile(lightsFilePath, std::ios::binary);
    if (!inFile.is_open())
    {
        fprintf(stderr, "Error opening file: \n");
        return 2;  // filesystem error
    }

    // Load GLOBAL::LIGHTFILEMANAGER:lightsLibrary
    Light light;
    while (inFile.read(reinterpret_cast<char *>(&light), sizeof(Light)))
    {
        GLOBAL::LIGHTFILEMANAGER::lightsLibrary.push_back(light);
        // printf("Added light! New size: %lu\n", GLOBAL::LIGHTFILEMANAGER::lightsLibrary.size());
    }
    inFile.close();


    return 0;
}

uint8_t LightFileManager::deleteLightByIndex(size_t index)
{
    if (index >= GLOBAL::LIGHTFILEMANAGER::lightsLibrary.size()) return 1;
    // base directory to the light "database"
    const std::string baseDir = std::filesystem::current_path().string() + "/" + std::string(LIGHT_LIBRARY_PATH);

    // Check if the base directory exists
    if (!std::filesystem::exists(baseDir) || !std::filesystem::is_directory(baseDir))
    {
        fprintf(stderr, "Base directory does not exist or is invalid\n");
        return 2;  // filesystem error
    }


    // the path to the library file
    std::string lightsFilePath = baseDir + "library.LClib";

    if (!std::filesystem::exists(lightsFilePath))
    {
        fprintf(stderr, "File does not exist: \n");
        return 2;  // File error
    }

    std::fstream file(lightsFilePath, std::ios::binary | std::ios::in | std::ios::out);
    if (!file.is_open())
    {
        fprintf(stderr, "Error opening file: \n");
        return 2;  // File error
    }

    Light          lastLight;
    Light light;

    // replace element with last element

    // get last element
    file.seekg(static_cast<std::streamoff>((GLOBAL::LIGHTFILEMANAGER::lightsLibrary.size() - 1) * sizeof(Light)));
    size_t lastLightPos = file.tellg();
    file.read(reinterpret_cast<char *>(&lastLight), sizeof(Light));

    printf("###   Last Light   ###\n");
    printf("  seekg: %lu", lastLightPos);
    printLight(lastLight);
    printf("######################\n\n\n");

    // jump to the beginning of the file
    file.seekg(0);


            // go to the beginning of the latest read in light
            file.seekp(static_cast<ssize_t>(index * sizeof(Light)));

            printf("###   Light to be removed   ###\n");
            printf("  seekg: %lu", static_cast<size_t>(file.tellp()));
            printLight(light);
            printf("###############################\n\n\n");

            // replace the light with the last light
            file.write(reinterpret_cast<char *>(&lastLight), sizeof(Light));




    file.close();
    std::filesystem::resize_file(lightsFilePath, lastLightPos);

    return 0;  // Success
}


void LightFileManager::printLights()
{
    for (const auto &light : GLOBAL::LIGHTFILEMANAGER::lightsLibrary)
    {
        printf("Name: %50s\n", light.name);
        printf("Man.: %50s\n", light.manufacturer);
        printf("Ch. : %50d\n\n", light.channelCount);
    }
}

void LightFileManager::printLight(Light light)
{
    printf("Name: %50s\n", light.name);
    printf("Man.: %50s\n", light.manufacturer);
    printf("Ch. : %50d\n\n", light.channelCount);
}
