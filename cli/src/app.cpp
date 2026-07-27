#include <CLI/CLI.hpp>
#include <fmt/core.h>

namespace wtg
{

    int run(int argc, char **argv)
    {
        CLI::App app{
            "Developer-first security planning framework"};

        app.set_version_flag(
            "--version",
            "War-Te-G 0.0.1");

        CLI11_PARSE(app, argc, argv);

        fmt::print("War-Te-G (WTG)\n");
        fmt::print("Version 0.0.1\n\n");
        fmt::print("Developer-first security planning framework.\n");

        return 0;
    }

}