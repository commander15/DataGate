add_subdirectory(lib)

include(CMakePackageConfigHelpers)

set(ROOT .)

configure_package_config_file(DataGateConfig.cmake.in DataGateConfig.cmake
    PATH_VARS ROOT
    INSTALL_DESTINATION lib/cmake/DataGate
)

write_basic_package_version_file(DataGateConfigVersion.cmake
    VERSION ${DataGate_VERSION}
    COMPATIBILITY AnyNewerVersion
    ARCH_INDEPENDENT
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/DataGateConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/DataGateConfigVersion.cmake
    DESTINATION lib/cmake/DataGate
)

install(EXPORT DataGateTargets
    NAMESPACE DataGate::
    DESTINATION lib/cmake/DataGate
)
