#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include <nyx/protection.hpp>

namespace nyx
{

    struct ConfigurationModel
    {
        int configVersion = 0;

        std::vector<Protection> protections;
    };

    class Configuration
    {
    public:
        bool load(const std::filesystem::path &root);
        bool save(const std::filesystem::path &root);

        const ConfigurationModel &model() const;

        const std::string &content() const;

    private:
        ConfigurationModel model_;
        std::string content_;
    };

}