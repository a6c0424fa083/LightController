//
//  LightFileManager.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-16.
//

#include "LightFileManager.hpp"

LightFileManager::~LightFileManager() {}

/**
 * @brief This function adds a 'Light' struct to the library.<br>
 * this also accounts for if the library doesn't exst jet
 * @param light The 'Light' struct that should be added
 * @return Return 0 on success, other on failure
 *
 * <b>Return values:</b><br>
 * 00 - Success<br>
 * 01 - Base directory doesn't exist or is not a directory<br>
 * 02 - Couldn't open library file after creation<br>
 * 03 - Couldn't open existing library file for input<br>
 * 04 - Couldn't open existing library file for output<br>
 */
uint8_t LightFileManager::addLightToLibrary(Light light)
{
    // directory of the light library (relative to executable)
    const std::string baseDir = std::filesystem::current_path().string() + "/" + std::string(LIGHT_LIBRARY_PATH);

    // check for existence of directory
    if (!std::filesystem::exists(baseDir) || !std::filesystem::is_directory(baseDir)) return 1;

    // the path to the library file
    std::string lightsFilePath = baseDir + "library.LClib";

    // check if the library file already exists (if not: create one)
    if (!std::filesystem::exists(lightsFilePath))
    {
        std::ofstream createFile(lightsFilePath, std::ios::binary);
        if (!createFile.is_open()) return 2;
        createFile.close();
    }

    // open library file
    std::ifstream inFile(lightsFilePath, std::ios::binary);
    if (!inFile.is_open()) { return 3; }

    // check if the light already exists (if so: exit)
    Light existingLight;
    while (inFile.read(reinterpret_cast<char *>(&existingLight), sizeof(Light)))
    {
        if (std::strcmp(existingLight.name, light.name) == 0) { return 0; }
    }
    inFile.close();

    // write the light data to the file
    std::ofstream outFile(lightsFilePath, std::ios::binary | std::ios::app);
    if (!outFile.is_open())
    {
        fprintf(stderr, "Error opening file for writing\n");
        return 4;
    }

    outFile.write(reinterpret_cast<const char *>(&light), sizeof(Light));
    outFile.close();

    return 0;
}


/**
 * @brief This function loads the lights from the library file
 * to the structure in the GLOBAL namespace
 * @return Return 0 on success, other on failure
 *
 * <b>Return values:</b><br>
 * 00 - Success<br>
 * 01 - Base directory doesn't exist or is not a directory<br>
 * 02 - Couldn't open library file after creation<br>
 * 03 - Couldn't open existing library file for input<br>
 */
uint8_t LightFileManager::loadLightsFromLibrary()
{
    // clear the existing lights
    GLOBAL::LIGHTFILEMANAGER::lightsLibrary.clear();

    // directory of the light library (relative to executable)
    const std::string baseDir = std::filesystem::current_path().string() + "/" + std::string(LIGHT_LIBRARY_PATH);

    // check for existence of directory
    if (!std::filesystem::exists(baseDir) || !std::filesystem::is_directory(baseDir)) return 1;

    // the path to the library file
    std::string lightsFilePath = baseDir + "library.LClib";

    // check if the library file already exists (if not: create one)
    if (!std::filesystem::exists(lightsFilePath))
    {
        std::ofstream createFile(lightsFilePath, std::ios::binary);
        if (!createFile.is_open()) return 2;
        createFile.close();
    }

    // open library file
    std::ifstream inFile(lightsFilePath, std::ios::binary);
    if (!inFile.is_open()) { return 3; }

    // Load the lights in the library file to the GLOBAL structure
    Light light;
    while (inFile.read(reinterpret_cast<char *>(&light), sizeof(Light)))
    {
        GLOBAL::LIGHTFILEMANAGER::lightsLibrary.push_back(light);
    }
    inFile.close();

    return 0;
}


/**
 * @brief This function deleted a element based in the index
 * @param index This index leeding the the element that should be deleted
 * @return Return 0 on success, other on failure
 *
 * <b>Return values:</b><br>
 * 00 - Success<br>
 * 01 - Base directory doesn't exist or is not a directory<br>
 * 02 - Couldn't open library file<br>
 */
uint8_t LightFileManager::deleteLightByIndex(const size_t index)
{
    // check if index is in range of the vectors size
    if (index >= GLOBAL::LIGHTFILEMANAGER::lightsLibrary.size()) return 1;

    // directory of the light library (relative to executable)
    const std::string baseDir = std::filesystem::current_path().string() + "/" + std::string(LIGHT_LIBRARY_PATH);

    // check for existence of directory
    if (!std::filesystem::exists(baseDir) || !std::filesystem::is_directory(baseDir)) return 1;

    // the path to the library file
    std::string lightsFilePath = baseDir + "library.LClib";

    // check if the library file already exists (if not: return)
    if (!std::filesystem::exists(lightsFilePath)) { return 0; }

    // open library file to modify it
    std::fstream file(lightsFilePath, std::ios::binary | std::ios::in | std::ios::out);
    if (!file.is_open()) { return 2; }

    // create a struct to store the last element of the libary
    Light lastLight;

    // set the input cursor to the beginning of the last element in the file
    file.seekg(static_cast<std::streamoff>((GLOBAL::LIGHTFILEMANAGER::lightsLibrary.size() - 1) * sizeof(Light)));

    // store the position of the last light for later
    const size_t lastLightPos = file.tellg();

    // read the last element to the struct
    file.read(reinterpret_cast<char *>(&lastLight), sizeof(Light));

    // set input cursor to the beginning of the file
    file.seekg(0);

    // set output cursor the the beginning of the element that should be deleted
    file.seekp(static_cast<ssize_t>(index * sizeof(Light)));

    // replace the light with the last light (effectively deleting it)
    file.write(reinterpret_cast<char *>(&lastLight), sizeof(Light));

    file.close();

    // resize the file (cut the last element)
    std::filesystem::resize_file(lightsFilePath, lastLightPos);

    return 0;  // Success
}
