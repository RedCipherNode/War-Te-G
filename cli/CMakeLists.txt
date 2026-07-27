add_executable(wtg
    src/main.cpp
    /app.cpp
)

target_include_directories(wtg
    PRIVATE
    include
)

target_link_libraries(wtg
    PRIVATE
    CLI11::CLI11
    fmt::fmt
    wtg_core
)