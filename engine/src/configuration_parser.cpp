#include <iostream>
#include <toml++/toml.h>

#include <nyx/constants.hpp>
#include <nyx/configuration_parser.hpp>

namespace nyx
{

    bool ConfigurationParser::load(
        const std::filesystem::path &root,
        ConfigurationModel &model)
    {
        try
        {
            auto table = toml::parse_file((root / ProjectFile).string());

            std::cout << "Parsed config_version = "
                      << table["config_version"].value<int64_t>().value_or(-1)
                      << '\n';

            model.configVersion =
                table["config_version"].value_or(0);

            return true;
        }
        catch (const toml::parse_error &)
        {
            return false;
        }
    }

}