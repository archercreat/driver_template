cmake_minimum_required(VERSION 3.15)

project(driver LANGUAGES CXX ASM_MASM)

# Include FindWDK
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/FindWDK/cmake")
find_package(WDK REQUIRED)

# Treat warnings as errors
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")

# Create driver
wdk_add_driver(driver 
	"src/main.cpp"
	"src/example.asm"
)

# Enable std20
target_compile_features(driver PRIVATE
	cxx_std_20
)

target_include_directories(driver PRIVATE
	include
)
