#pragma once


#include <iostream>
#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class MyGui {

public:
	std::string text = "unclicked";
	char textbox[50] = "dfjs";
	bool editor_Bool = false;
	std::vector<int> dragList;
	std::string dragItemTag = "DragButtonDemoTag";

	ImVec4 color;

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
		ImGui::Begin("WidgetTest");

		ImGui::Text("imgui window");

		ImGui::End();
	}

	/// <summary>
	/// ��������
	/// </summary>
	void BasicDemoGUI() {
		//window
		ImGui::Begin("WidgetTest");

		ImGui::Text("imgui window");
		ImGui::Text(text.c_str());

		//BUTTON
		if (ImGui::Button("click me!")) {
			text = "clicked";
		}

		//TEXTBOX
		ImGui::InputText("text box", textbox, 50, IM_ARRAYSIZE(textbox));

		//LIST
		ImGui::ListBoxHeader("list title");
		for (int i = 0; i < 12; i++)
		{
			if (ImGui::Selectable(std::to_string(i).c_str())) {
				text = std::to_string(i);
			}
		}
		ImGui::ListBoxFooter();

		//COMBO
		if (ImGui::BeginCombo("DDD", text.c_str())) {
			for (int i = 0; i < 5; i++)
			{
				if (ImGui::Selectable(std::to_string(i).c_str())) {
					text =std::to_string( i)  ;
				}
			}
			ImGui::EndCombo();
		}

		//COLOR
		ImGui::ColorEdit4("test color", (float*)&color,ImGuiColorEditFlags_::ImGuiColorEditFlags_AlphaBar);


		ImGui::End();
	}


	/// <summary>
	/// ��������   ���ڻ��ƺ��Զ���ؼ�
	/// </summary>
	void DrawHyperGUI() {
		ImGui::Begin("DrawHyperGUI");

		ImDrawList* drawList = ImGui::GetForegroundDrawList();
		drawList->AddRectFilled(ImVec2(0, 0), ImGui::GetMousePos(), ImColor(40, 55, 120));

		ImGui::End();
	}

	/// <summary>
	/// ���̰����¼�
	/// </summary>
	void GetKeyBoardGUI() {

		ImGui::Begin("GetKeyBoardGUI");
		//ImGui::SetNextWindowSize(ImVec2(550, 680), ImGuiCond_FirstUseEver);
		if (ImGui::IsKeyDown((ImGuiKey)562) && ImGui::IsItemHovered())
		{
			printf("QQ");
			ImGui::Text(u8"�ǵķ���");
		}

		ImGui::End();
	}

	/// <summary>
	/// �ڴ���֮����ҷ�ؼ�
	/// </summary>
	void DragGUI() {
		ImGui::Begin("drag item source win");

		for (int i = 0; i < 5; i++)
		{
			ImGui::Button(std::to_string(i).c_str());
			if (i + 1 < 5)
			{
				ImGui::SameLine();
			}
			if (ImGui::BeginDragDropSource())
			{
				ImGui::Text(std::string("drag:").append(std::to_string(i)).c_str());
				ImGui::SetDragDropPayload(dragItemTag.c_str(), &i, sizeof(int));
				ImGui::EndDragDropSource();
			}
		}
		ImGui::End();

		//------------------------------
		ImGui::Begin("drag item target win", 0, ImGuiWindowFlags_::ImGuiWindowFlags_MenuBar);

		if (ImGui::BeginDragDropTarget())
		{
			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload(dragItemTag.c_str())) {
				dragList.push_back(*(const int*)payload->Data);
			}
			ImGui::EndDragDropTarget();
		}

		//std::cout << dragList.size()<<std::endl;
		for (int i = 0; i < dragList.size(); i++)
		{
			ImGui::Button(std::to_string(i).c_str());
			if (i + 1 < dragList.size())
			{
				ImGui::SameLine();
			}
		}

		ImGui::End();

	}

};