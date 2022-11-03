
#include <Windows.h>
#include <iostream>
#include <string>
  
#include "Widget.h"  

#define SCR_WIDTH 1200 
#define SCR_HEIGHT 800 
int main() {

	printf("start\n");  

	//���ڹ���ʵ����
	Widget windowFunc =  Widget::Widget();
	//��������
	GLFWwindow* HWindow = windowFunc.CreateWindows(SCR_WIDTH, SCR_HEIGHT,"title",NULL, NULL); 
	//�趨����
	windowFunc.WindowSetting(SCR_WIDTH, SCR_HEIGHT);
	//��ʼ��imgui
	windowFunc.InitImGui(HWindow);

	//����ѭ��
	while (!glfwWindowShouldClose(HWindow))
	{
		//ÿ֡����
		glClearColor(0.f, 0.5f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//���ƴ���
		windowFunc.RunWidget();
		//ÿ֡�建��
		glfwSwapBuffers(HWindow);
		glfwPollEvents();
	}

	//�رմ��ں�Ĵ���   imgui���ڴ��ͷŵ�
	windowFunc.CloseWidget();
	 
	return 0;
}

