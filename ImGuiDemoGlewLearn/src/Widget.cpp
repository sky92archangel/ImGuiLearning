#include "Widget.h"
#include "MyRenderGUI.h"
#include "PathHelper.h"

/// <summary>
/// 创建窗体
/// </summary>
/// <param name="width"></param>
/// <param name="height"></param>
/// <param name="title"></param>
/// <param name="monitor"></param>
/// <param name="window"></param>
/// <returns></returns>
GLFWwindow* Widget::CreateWindows(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* window)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* HWindow = glfwCreateWindow(width, height, title, monitor, window);

	if (HWindow == NULL)
	{
		printf("create window failed\n");
		glfwTerminate();
		return nullptr;
	}

	glfwMakeContextCurrent(HWindow);
	return HWindow;
}
/// <summary>
/// 设定窗体
/// </summary>
/// <param name="width"></param>
/// <param name="height"></param>
void Widget::WindowSetting(int width, int height)
{
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		printf("glew failed\n");
		glfwTerminate();
		return;
	}

	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	return;
}

/// <summary>
/// 初始化imgui
/// </summary>
/// <param name="HWindows"></param>
void Widget::InitImGui(GLFWwindow* HWindows)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext(NULL);

	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	_io = &io;

	//风格
	ImGui::StyleColorsDark();
	io.ConfigViewportsNoAutoMerge = true;

	//io.Fonts->AddFontFromFileTTF("R:/Z_BACKUP_ORDER/_PROJECT_/CPP/ImGuiDemo/_dependency_/Fonts/simhei.ttf",15.0f,NULL,io.Fonts->GetGlyphRangesChineseFull());
	//找到当前目录并定位字体文件
	std::string fontPathStr = GetCWD() + "/Fonts/simhei.ttf";
	std::cout << fontPathStr << std::endl;
	const char* fontPath = fontPathStr.c_str();
	io.Fonts->AddFontFromFileTTF(fontPath, 15.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
	//io.Fonts->AddFontFromMemoryCompressedTTF

	//docking setting 
	io.ConfigFlags |= ImGuiViewportFlags_NoDecoration;
	//io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	//io.ConfigFlags |= ImGuiCol_DockingEmptyBg; 
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows


	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(HWindows, true);
	ImGui_ImplOpenGL3_Init("#version 330");


}

MyGui	mygui = MyGui::MyGui();
/// <summary>
/// 运行imgui
/// </summary>
void Widget::RunWidget()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	//设定在主窗体上可停靠子窗体
	ImGui::DockSpaceOverViewport();

	//官方实例
	ImGui::ShowDemoWindow();

	//自定义窗体绘制
	{
		//由bool控制的imgui子窗
		if (mygui.editor_Bool)
		{
			mygui.WidgetTest();
		}
		//运行 imgui菜单栏子窗
		mygui.MenuBarTest();
	}

	//开始整体渲染
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	if ((*_io).ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}

}

void Widget::CloseWidget()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}



///// <summary>
///// imgui渲染
///// </summary>
//void WidgetRender() {
//
//	ImGui::Render();
//	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//}
