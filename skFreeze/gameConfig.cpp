#include "GameConfig.hpp"

GameConfig::GameConfig()
{
    std::ifstream gameCfg("game.cfg", std::fstream::in);
    std::string line;
    while (std::getline(gameCfg, line))
    {

        // TODO this is very naive tokenization, should work OK for Stunt GP config fiels though
        // TODO maybe refactor this and use this kind of files for each module config instead of ini?
        size_t delimiter = line.find("=");
        if (delimiter != std::string::npos)
        {
            std::stringstream ss(line);
            std::string key;
            std::string equalSign;
            std::string value;
            
            
            
            ss >> key >> equalSign >> value;

            configContainer.insert({ key, value });
        }
        
    }
}

bool GameConfig::getDisableFramerateCorrection()
{

    auto it = configContainer.find("DISABLE_FRAMERATE_CORRECTION");
    if (it != configContainer.end()) {
        // TODO handle malformed config files
        return  static_cast<bool>(std::stoi(it->second));
    }
    OutputDebugString("DISABLE_FRAMERATE_CORRECTION not found! Using false instead");
    return false;
}
