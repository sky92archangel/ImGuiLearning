#pragma once

#include <iostream>

 
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"
#include "imgui_internal.h"

#include  <GL/glew.h>
#include  <GLFW/glfw3.h>

class Widget {

public:
	GLFWwindow* CreateWindows(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* window);
	void WindowSetting(int width, int height);

	void RunWidget();

	void InitImGui(GLFWwindow* HWindows);

};