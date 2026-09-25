cmake_minimum_required(VERSION 4.3.0)

project(WebViewMessageBridge VERSION 1.0.0 LANGUAGES CXX)

# ---------- 创建静态库 ----------
add_library(WebViewMessageBridge STATIC
    src/WebViewMessageBridge.cpp
)

target_compile_features(WebViewMessageBridge PUBLIC cxx_std_20)

# ---------- MSVC 编译选项 ----------
if(MSVC)
    target_compile_options(WebViewMessageBridge
        PRIVATE
            /utf-8
            /W4
            /permissive-
    )
endif()

target_include_directories(WebViewMessageBridge
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

find_package(nlohmann_json CONFIG REQUIRED)

target_link_libraries(WebViewMessageBridge
    PUBLIC
        nlohmann_json::nlohmann_json
)

set_target_properties(WebViewMessageBridge PROPERTIES
    OUTPUT_NAME "WebViewMessageBridge"
    DEBUG_POSTFIX "d"
)