include(FetchContent)
set(FETCHCONTENT_TRY_FIND_PACKAGE_MODE ALWAYS CACHE STRING "")

# Jsoner

FetchContent_Declare(
    Jsoner
    GIT_REPOSITORY https://github.com/commander15/Jsoner.git
    GIT_TAG v1.0.0
    EXCLUDE_FROM_ALL
    FIND_PACKAGE_ARGS 1.0.0
)

FetchContent_MakeAvailable(Jsoner)

if (NOT TARGET Jsoner::Jsoner)
    add_library(Jsoner::Jsoner ALIAS Jsoner)
endif()
