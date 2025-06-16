cmake_minimum_required(VERSION 3.30)

set(CMAKE_TOOLCHAIN_FILE "C:/tool/Android-NDK/build/cmake/android.toolchain.cmake")
set(CMAKE_SYSTEM_NAME Android)
set(CMAKE_SYSTEM_VERSION 21)
set(CMAKE_ANDROID_ABI "arm64-v8a")
set(CMAKE_ANDROID_NDK "C:/tool/Android-NDK")

project(core)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_SYSROOT "${CMAKE_ANDROID_NDK}/toolchains/llvm/prebuilt/windows-x86_64/sysroot")
set(CMAKE_CXX_FLAGS "-Wall -Oz -g0 -ffat-lto-objects -flto -fdata-sections -ffunction-sections -finline-functions -fomit-frame-pointer")


add_executable(core_static main.cpp)
set_target_properties(core_static PROPERTIES LINK_SEARCH_START_STATIC ON)
set_target_properties(core_static PROPERTIES LINK_SEARCH_END_STATIC ON)
set_target_properties(core_static PROPERTIES OUTPUT_NAME "core")
