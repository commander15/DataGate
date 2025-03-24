enable_testing()

find_package(GTest REQUIRED)

add_executable(DataGateTest
    main.cpp
)

target_compile_definitions(DataGateTest PRIVATE TEST_DATA_DIR="${PROJECT_SOURCE_DIR}/testdata")

target_link_libraries(DataGateTest PRIVATE GTest::gtest Qt::Test DataGate)
