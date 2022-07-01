cmake_minimum_required(VERSION 3.15)

project(driver LANGUAGES CXX ASM_MASM)

# Include FindWDK
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/FindWDK/cmake")
find_package(WDK REQUIRED)

# Treat warnings as errors
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*)
file(GLOB_RECURSE INCLUDES CONFIGURE_DEPENDS include/*)

# Create driver
wdk_add_driver(driver 
	${SOURCES}
	${INCLUDES}
)

source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${SOURCES} ${INCLUDES})

# Enable std20
target_compile_features(driver PRIVATE
	cxx_std_20
)

target_include_directories(driver PRIVATE
	include
)
