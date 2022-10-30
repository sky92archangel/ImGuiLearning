#include "Widget.h"


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



bool editor_Bool;
void MenuBarTest() {

	//create menu bar   ²Ëµ¥À¸
	ImGui::BeginMainMenuBar();
	ImGui::Text("barName");
	if (ImGui::BeginMenu(u8"ÎÄ¼þ")) {

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
void WidgetRender() {

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
void Widget::RunWidget()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	ImGui::ShowDemoWindow();

	

	if (editor_Bool)
	{
		WidgetTest();
	}
	MenuBarTest();


	WidgetRender();

}

void Widget::InitImGui(GLFWwindow* HWindows)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext(NULL);

	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	ImGui::StyleColorsDark();
	io.ConfigViewportsNoAutoMerge=true;

	io.Fonts->AddFontFromFileTTF("Fonts/simhei.ttf",15.0f,NULL,io.Fonts->GetGlyphRangesChineseFull());
	//io.Fonts->AddFontFromMemoryCompressedTTF
	ImGui_ImplGlfw_InitForOpenGL(HWindows, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiViewportFlags_NoDecoration; // ImGuiViewportFlags_NoDecration;
}
