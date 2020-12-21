cmake_minimum_required(VERSION 3.16)
project(hw1_osx_10_9)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(osxlib)
include_directories(shaders)
include_directories(UCB)
include_directories(glm-0.9.2.7)

add_executable(hw1_osx_10_9
        main.cpp
        shaders.cpp
        Transform.cpp
        UCB/grader.cpp
        )

#LINK_DIRECTORIES(${ROOT_DIR}/osxlib/mac)
target_link_libraries(hw1_osx_10_9 /Users/chaofang/Downloads/hw1-osx-10.9/osxlib/libfreeimage.a)

# 添加头文件
set(GLEW_H /usr/local/Cellar/glew/2.2.0/include/GL/)
set(GLFW_H /usr/local/Cellar/glfw/3.3.2/include/GLFW/)
set(FREEIMAGE_H ${ROOT_DIR}/include/)
set(GLM_H  ${ROOT_DIR}/glm-0.9.2.7/)
include_directories(${GLEW_H} ${GLFW_H} ${FREEIMAGE_H} ${GLM_H})

# 添加目标链接
set(GLEW_LINK /usr/local/Cellar/glew/2.2.0/lib/libGLEW.2.2.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.3.2/lib/libglfw.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK} )


if (APPLE)
    target_link_libraries(hw1_osx_10_9 "-framework OpenGL")
    target_link_libraries(hw1_osx_10_9 "-framework GLUT")
endif()