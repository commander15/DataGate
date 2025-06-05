qt_add_library(DataGate)

configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config.h @ONLY)

target_headers(DataGate
    PUBLIC
        datagate.h
        global.h config.h
        abstractdataclient.h
        abstractdatamanager.h dataquery.h dataresponse.h
        datamanager.h
        auth/authenticator.h auth/abstractloginmanager.h
        permission/permissionmanager.h
        model/tablemodel.h
    PRIVATE
        debug_p.h
        auth/authenticator_p.h
        model/tablemodel_p.h
)

target_sources(DataGate
    PRIVATE
        debug.cpp
        abstractdataclient.cpp
        abstractdatamanager.cpp dataquery.cpp dataresponse.cpp
        datamanager.cpp
        auth/authenticator.cpp auth/abstractloginmanager.cpp
        permission/permissionmanager.cpp
        model/tablemodel.cpp
)

set_target_properties(DataGate PROPERTIES
    OUTPUT_NAME DataGate
    VERSION     ${PROJECT_VERSION}
)

target_include_directories(DataGate 
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:include/DataGate>
)

target_compile_definitions(DataGate
    PUBLIC
        $<IF:$<STREQUAL:$<TARGET_PROPERTY:TYPE>,STATIC_LIBRARY>,DATAGATE_STATIC,DATAGATE_SHARED>
    INTERFACE
        DATAGATE_LIB
    PRIVATE
        DATAGATE_BUILD
)

target_link_libraries(DataGate PUBLIC Qt::Core Jsoner::Jsoner)

install(CODE "file(REMOVE_RECURSE ${CMAKE_INSTALL_PREFIX}/include/DataGate)")

install(TARGETS DataGate
    EXPORT DataGateTargets
    ARCHIVE        DESTINATION lib
    LIBRARY        DESTINATION lib
    RUNTIME        DESTINATION bin
    PUBLIC_HEADER  DESTINATION include/DataGate
    #PRIVATE_HEADER DESTINATION include/DataGate/private
)

generate_target_headers(DataGate FOLDER DataGate)
