#pragma once


#include <iostream>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class MyGui {

public:
	bool editor_Bool = false;

public:

	/// <summary>
	/// �˵���demo
	/// </summary>
	void MenuBarTest() {

		//create menu bar   �˵���
		ImGui::BeginMainMenuBar();
		ImGui::Text("barName");
		if (ImGui::BeginMenu(u8"�ļ�")) {

			//editor_Bool =   true;
			//editor_Bool = ImGui::MenuItem("editor", NULL, editor_Bool, true);
			if (ImGui::MenuItem("editor", NULL, editor_Bool, true)) {
				printf("click editor button\n");
				editor_Bool = !editor_Bool;
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	void WidgetTest() {
		//window
		ImGui::Begin("window");
		ImGui::Text("imgui window");
		ImGui::End();
	}


};