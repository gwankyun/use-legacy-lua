# cmake版本
cmake_minimum_required(VERSION 4.2)

include(CMakePrintHelpers)

cmake_print_variables(CMAKE_VERSION)

# 項目名
project(
  use_legacy_lua
  # 以下屬性皆可選
  LANGUAGES
    CXX # 指定C++可以跳過C編譯器檢測
  VERSION
    1.0.0 # 版本
  DESCRIPTION "vcpkg指定庫版本示例"
)

find_package(Lua REQUIRED)

# 添加可執行文件
add_executable(main)
target_sources(
  main
  PRIVATE #
    src/main.cpp
)
target_link_libraries(main PRIVATE ${LUA_LIBRARIES}) # 鏈接lua庫
target_include_directories(main PRIVATE ${LUA_INCLUDE_DIR})
target_compile_features(main PRIVATE cxx_std_23)

# 啟用測試
enable_testing()
include(CTest)

# main返回0就是成功
add_test(NAME tests COMMAND main)
set_tests_properties(
  tests
  PROPERTIES #
    FAIL_REGULAR_EXPRESSION "FAIL"
)
