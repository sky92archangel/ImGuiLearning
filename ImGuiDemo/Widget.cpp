#include "Widget.h"


void WidgetEnd() {

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	 
}
 
 
GLFWwindow* Widget::CreateWindows(int width,int height,const char* title,GLFWmonitor* monitor,GLFWwindow* window)
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

void Widget::RunWidget()
{ 
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();  
	ImGui::NewFrame();
	ImGui::ShowDemoWindow();

	//window
	ImGui::Begin("window");
	ImGui::Text("imgui window");
	ImGui::End();

	WidgetEnd();

}

void Widget::InitImGui(GLFWwindow* HWindows)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext(NULL);
	 
	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	ImGui::StyleColorsDark();
	/*io.ConfigViewportsNoAutoMerge();*/
	ImGui_ImplGlfw_InitForOpenGL(HWindows, true);
	ImGui_ImplOpenGL3_Init("#version 330");


}
