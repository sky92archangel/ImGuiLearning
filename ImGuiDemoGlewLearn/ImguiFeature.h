#pragma once


#include <iostream>
#include <imgui.h>



class ImguiFeature
{
public:
	ImguiFeature();
	~ImguiFeature();
	void MenuBarTest();

private:

};

ImguiFeature::ImguiFeature()
{
}

ImguiFeature::~ImguiFeature()
{
}


bool editor_Bool;
/// <summary>
/// �˵���demo
/// </summary>
void ImguiFeature::MenuBarTest() {

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



void ImguiFeature::WidgetTest() {
	//window
	ImGui::Begin("window");
	ImGui::Text("imgui window");
	ImGui::End();
}

/// <summary>
/// imgui��Ⱦ
/// </summary>
void ImguiFeature::WidgetRender() {

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}