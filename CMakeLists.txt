cmake_minimum_required (VERSION 3.8)

project ("mario")

include_directories("./engine")

set(CXX_STANDARD 11)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_path(PLOG_INCLUDE_DIRS "plog/Appenders/AndroidAppender.h")
find_package(glm CONFIG REQUIRED)
find_path(STB_INCLUDE_DIRS "stb.h")

add_library(engine SHARED
"engine/Engine.h" "engine/Engine.cpp" 
"engine/Window.h" "engine/Window.cpp"
"engine/InstanceManager.h" "engine/InstanceManager.cpp" 
"engine/MouseListener.h" "engine/MouseListener.cpp" 
"engine/KeyboardListener.h" "engine/KeyboardListener.cpp"
"engine/Timer.h" "engine/Timer.cpp" 
"engine/Scene.h"
"engine/LevelEditorScene.h" "engine/LevelEditorScene.cpp" 
"engine/LevelScene.h" "engine/LevelScene.cpp" 
"engine/ShaderManager.h" "engine/ShaderManager.cpp" 
"engine/Camera.h" "engine/Camera.cpp" 
"engine/TextureManager.h" "engine/TextureManager.cpp")
target_include_directories(engine PUBLIC ${PLOG_INCLUDE_DIRS})
target_include_directories(engine PUBLIC ${STB_INCLUDE_DIRS})
target_link_libraries(engine PUBLIC GLEW::GLEW)
target_link_libraries(engine PUBLIC glfw)
target_link_libraries(engine PUBLIC glm)


add_executable (mario main.cpp)
target_link_libraries(mario PRIVATE engine)
