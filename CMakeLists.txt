cmake_minimum_required(VERSION 3.23)
project(Football LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === CORE (domena; bez I/O i czasu) ===
file(GLOB_RECURSE CORE_SOURCES
        CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/src/core/*.cpp"
)
add_library(football_core ${CORE_SOURCES})
target_include_directories(football_core PUBLIC "${PROJECT_SOURCE_DIR}/src")

# === APP (formatowanie, zapis, symulacja czasu) ===
file(GLOB_RECURSE APP_SOURCES
        CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/src/app/*.cpp"
)
add_library(football_app ${APP_SOURCES})
target_include_directories(football_app PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(football_app PUBLIC football_core)

# === CLI (main.cpp) ===
set(APP_MAIN "${PROJECT_SOURCE_DIR}/src/cli/main.cpp")
if(EXISTS "${APP_MAIN}")
    add_executable(Football "${APP_MAIN}")
    target_link_libraries(Football PRIVATE football_app football_core)
endif()

# === TESTY (GoogleTest) ===
file(GLOB_RECURSE TEST_SOURCES
        CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/tests/*.cpp"
)
if(TEST_SOURCES)
    include(CTest)
    enable_testing()
    include(FetchContent)
    FetchContent_Declare(googletest
            URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
            DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    add_executable(FootballTests ${TEST_SOURCES})
    target_include_directories(FootballTests PUBLIC
            "${PROJECT_SOURCE_DIR}/src"
            "${PROJECT_SOURCE_DIR}/tests"
    )
    target_link_libraries(FootballTests PRIVATE gtest_main football_app football_core)
    include(GoogleTest)
    gtest_discover_tests(FootballTests)
endif()
