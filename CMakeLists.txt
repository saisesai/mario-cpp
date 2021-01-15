cmake_minimum_required (VERSION 3.8)

project ("mario")

include_directories("./engine")

set(CXX_STANDARD 11)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_path(PLOG_INCLUDE_DIRS "plog/Appenders/AndroidAppender.h")

add_library(engine SHARED
"engine/Engine.h" "engine/Engine.cpp" 
"engine/Window.h" "engine/Window.cpp"
"engine/InstanceManager.h" "engine/InstanceManager.cpp" 
"engine/MouseListener.h" "engine/MouseListener.cpp" 
"engine/KeyboardListener.h" "engine/KeyboardListener.cpp"
"engine/Timer.h" "engine/Timer.cpp" 
"engine/Scene.h"
"engine/LevelEditorScene.h" "engine/LevelEditorScene.cpp" 
"engine/LevelScene.h" "engine/LevelScene.cpp")
target_include_directories(engine PUBLIC ${PLOG_INCLUDE_DIRS})
target_link_libraries(engine PUBLIC GLEW::GLEW)
target_link_libraries(engine PUBLIC glfw)

add_executable (mario main.cpp)
target_link_libraries(mario PRIVATE engine)
