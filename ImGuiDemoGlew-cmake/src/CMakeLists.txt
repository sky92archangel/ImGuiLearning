#向工程添加多个头文件搜索路径  PROJECT_SOURCE_DIR 项目根目录路径  
# INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../_dependency_/glad/include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../_dependency_/glm)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../_dependency_/glfw/glfw-3.3.8.bin.WIN64/include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../_dependency_/imgui/1.88)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../_dependency_/glew/glew-2.1.0/include)
  

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../_dependency_/glfw/glfw-3.3.8.bin.WIN64/lib-vc2022)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../_dependency_/glew/glew-2.1.0/lib/Release/x64)
 

#将当前目录下的所有文件都放入变量DIR_SRCS内
AUX_SOURCE_DIRECTORY(./ DIR_SRCS) 


#添加可执行程序
ADD_EXECUTABLE(ImGuiDemoGlew ${DIR_SRCS})

#将子目录生成的库链接过来
TARGET_LINK_LIBRARIES(ImGuiDemoGlew 
PRIVATE
glfw3.lib
opengl32.lib 
glew32s.lib
 
)
 