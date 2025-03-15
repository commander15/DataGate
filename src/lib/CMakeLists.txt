qt_add_library(DataGate)

configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config.h @ONLY)

target_headers(DataGate
    PUBLIC
        global.h config.h
        abstractdatacontroller.h dataquery.h dataresponse.h
        auth/authenticator.h
        auth/abstractlogincontroller.h
        permission/permissionmanager.h
        model/tablemodel.h
    PRIVATE
        auth/authenticator_p.h
        model/tablemodel_p.h
)

target_sources(DataGate
    PRIVATE
        abstractdatacontroller.cpp dataquery.cpp dataresponse.cpp
        auth/authenticator.cpp
        auth/abstractlogincontroller.cpp
        permission/permissionmanager.cpp
        model/tablemodel.cpp
)

target_include_directories(DataGate PUBLIC $<INSTALL_INTERFACE:include>)

target_link_libraries(DataGate PUBLIC Qt::Core Jsoner::Jsoner)

install(TARGETS DataGate
    EXPORT DataGateTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION lib
    PUBLIC_HEADER DESTINATION include/DataGate
)

generate_target_headers(DataGate FOLDER DataGate)
