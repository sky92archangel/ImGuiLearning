
#include <Windows.h>
#include <iostream>
#include <string>
  
#include "Widget.h"  

#define SCR_WIDTH 1200 
#define SCR_HEIGHT 800 
int main() {

	printf("start\n");  

	//窗口功能实例化
	Widget windowFunc =  Widget::Widget();
	//创建窗口
	GLFWwindow* HWindow = windowFunc.CreateWindows(SCR_WIDTH, SCR_HEIGHT,"title",NULL, NULL); 
	//设定窗口
	windowFunc.WindowSetting(SCR_WIDTH, SCR_HEIGHT);
	//初始化imgui
	windowFunc.InitImGui(HWindow);

	//界面循环
	while (!glfwWindowShouldClose(HWindow))
	{
		//每帧清屏
		glClearColor(0.f, 0.5f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//绘制窗口
		windowFunc.RunWidget();
		//每帧清缓存
		glfwSwapBuffers(HWindow);
		glfwPollEvents();
	}

	//关闭窗口后的处理   imgui的内存释放等
	windowFunc.CloseWidget();
	 
	return 0;
}

