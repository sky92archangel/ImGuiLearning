#pragma once


#include <iostream>
#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class MyGui {

public:
	bool editor_Bool = false;
	std::vector<int> dragList; 
	std:: string dragItemTag = "DragButtonDemoTag";

public:

	/// <summary>
	/// 菜单栏demo
	/// </summary>
	void MenuBarTest() {

		//create menu bar   菜单栏
		ImGui::BeginMainMenuBar();
		ImGui::Text("barName");
		if (ImGui::BeginMenu(u8"文件")) {

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
	/// 超级绘制   用于绘制和自定义控件
	/// </summary>
	void DrawHyperGUI() {
		ImGui::Begin("DrawHyperGUI");

		ImDrawList* drawList = ImGui::GetForegroundDrawList();
		drawList->AddRectFilled(ImVec2(0, 0), ImGui::GetMousePos(), ImColor(40, 55, 120));

		ImGui::End();
	}

	/// <summary>
	/// 键盘按键事件
	/// </summary>
	void GetKeyBoardGUI() {

		ImGui::Begin("GetKeyBoardGUI"); 
		//ImGui::SetNextWindowSize(ImVec2(550, 680), ImGuiCond_FirstUseEver);
		if (ImGui::IsKeyDown((ImGuiKey)562) && ImGui::IsItemHovered())
		{
			printf("QQ");
			ImGui::Text(u8"是的饭卡");
		}

		ImGui::End();
	}

	/// <summary>
	/// 在窗体之间拖曳控件
	/// </summary>
	void DragGUI() {
		ImGui::Begin("drag item source win");
	 
		for (int i = 0; i < 5; i++)
		{		 
			ImGui::Button(std::to_string(i).c_str() );
			if (i+1<5)
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
		ImGui::Begin("drag item target win",0,ImGuiWindowFlags_::ImGuiWindowFlags_MenuBar);

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