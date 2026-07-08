#include <fstream>
#include <sstream>

#include <nyx/configuration_parser.hpp>
#include <nyx/configuration.hpp>
#include <nyx/constants.hpp>

namespace fs = std::filesystem;

namespace
{

    constexpr auto DefaultConfiguration = R"(config_version = 7

#
# Enable protection by adding sections below.
#
# Example:
#
# [protection.obfuscation]
#

#
# Project-wide security policies.
#

[policy]
)";

}

namespace nyx
{

    bool Configuration::load(const fs::path &root)
    {
        std::ifstream file(root / ProjectFile);

        if (!file)
        {
            return false;
        }

        std::ostringstream buffer;
        buffer << file.rdbuf();

        content_ = buffer.str();

        ConfigurationParser parser;

        if (!parser.load(root, model_))
        {
            return false;
        }

        return true;
    }

    const ConfigurationModel &Configuration::model() const
    {
        return model_;
    }

    bool Configuration::save(const fs::path &root)
    {
        std::ofstream file(root / ProjectFile);

        if (!file)
        {
            return false;
        }

        file << DefaultConfiguration;

        return true;
    }

    const std::string &Configuration::content() const
    {
        return content_;
    }

}