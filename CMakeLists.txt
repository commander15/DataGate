cmake_minimum_required(VERSION 3.30)

project(DataGate
    DESCRIPTION "Data handling toolkit for Qt"
    VERSION     "3.0.0"
    LANGUAGES   CXX C
)

# Project settings

option(DATAGATE_BUILD_TESTS        OFF "Build DataGate tests")
option(DATAGATE_BUILD_DOCS         OFF "Build DataGate documentation")
option(DATAGATE_BUILD_TRANSLATIONS OFF "Build DataGate translations")
option(DATAGATE_BUILD_EXAMPLES     OFF "Build DataGate Examples")

set(DATAGATE_LOCALES en fr)

# CMake settings
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# CXX Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# C Standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

# Registering project module path
list(PREPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Including utility scripts
include(cmake/Utils.cmake)

# Qt setup

set(CMAKE_AUTOMOC ON)

set(Qt_MODULES Core)

if (DATAGATE_BUILD_TESTS)
    list(APPEND Qt_MODULES Test)
endif()

if (DATAGATE_BUILD_TRANSLATIONS)
    list(APPEND Qt_MODULES LinguistTools)
endif()

find_package(Qt6 REQUIRED COMPONENTS ${Qt_MODULES})

qt_standard_project_setup(
    REQUIRES 6.8.0
    I18N_SOURCE_LANGUAGE      en
    I18N_TRANSLATED_LANGUAGES ${DATAGATE_LOCALES}
)

qt_policy(SET QTP0002 NEW)
qt_policy(SET QTP0003 NEW)

# Other dependencies
include(cmake/Dependencies.cmake)

# Project directories

add_subdirectory(src)

if (DATAGATE_BUILD_TESTS)
    add_subdirectory(tests)
endif()

if (DATAGATE_BUILD_DOCS)
    add_subdirectory(docs)
endif()

if (DATAGATE_BUILD_TRANSLATIONS)
    qt_collect_translation_source_targets(SOURCE_TARGETS)

    qt_add_translations(DataGate SOURCE_TARGETS ${SOURCE_TARGETS}
        TS_FILE_BASE datagate
        TS_FILE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/translations
        QM_FILES_OUTPUT_VARIABLE QM_FILES
    )
    
    # Ensure the build directory has a translations folder
    set(TRANSLATIONS_BUILD_DIR "${CMAKE_BINARY_DIR}/translations")
    file(MAKE_DIRECTORY ${TRANSLATIONS_BUILD_DIR})

    # Copy QM files to build directory after they are generated
    add_custom_command(
        TARGET DataGate_lrelease POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${QM_FILES} ${TRANSLATIONS_BUILD_DIR}
        COMMENT "Copying generated QM files to ${TRANSLATIONS_BUILD_DIR}"
    )

    install(FILES ${QM_FILES} DESTINATION translations)
endif()

if (DATAGATE_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
