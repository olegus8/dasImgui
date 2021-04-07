options persistent_heap
options persistent_string_heap

require imgui_app
require daslib/glfw_boost
require daslib/imgui_boost
require daslib/static_let
require daslib/imnodes_boost
require daslib/safe_addr

var window : GLFWwindow?

def imgui_app ( title:string; blk : block )
    if glfwInit()==0
		panic("can't init glfw")
    window = glfwCreateWindow(1920, 1280, title, null, null)
    if window==null
  		panic("can't create window")
    glfwMakeContextCurrent(window)
    glfwSwapInterval(1)
    CreateContext(null)
    imnodes::CreateContext()
    var io & = imgui::GetIO()
    io.FontGlobalScale = 2.0;   // BBATKIN: note - my monitor is HUGE
    StyleColorsDark(null)
    ImGui_ImplGlfw_InitForOpenGL(window, true)
    ImGui_ImplOpenGL2_Init()
    var clear_color = float4(0.45f, 0.55f, 0.60f, 1.00f)
    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        ImGui_ImplOpenGL2_NewFrame()
        ImGui_ImplGlfw_NewFrame()
        invoke(blk)
        var display_w, display_h : int
        glfwGetFramebufferSize(window, display_w, display_h)
        glViewport(0, 0, display_w, display_h)
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w)
        glClear(GL_COLOR_BUFFER_BIT)
        ImGui_ImplOpenGL2_RenderDrawData(GetDrawData())
        glfwMakeContextCurrent(window)
        glfwSwapBuffers(window)
    imnodes::DestroyContext()
    ImGui_ImplOpenGL2_Shutdown()
    ImGui_ImplGlfw_Shutdown()
    imgui::DestroyContext(null)
    glfwDestroyWindow(window)
    glfwTerminate()

def EditNode(id:int;cap:string)
    BeginNode(id) <|
        BeginNodeTitleBar() <|
            TextUnformatted("{cap} id:{id}")
        BeginInputAttribute(id*1000+2) <|
            Text("input")
        BeginOutputAttribute(id*1000+3) <|
            Indent(40.)
            Text("output")

def LinkNode(lid,id1,id2:int)
    imnodes::Link(lid,id1*1000+2,id2*1000+3)

def MainMenu()
    BeginMenuBar <|
        BeginMenu("File") <|
            pass
        BeginMenu("Edit") <|
            MenuItem("Undo", "CTRL+Z") <|
                pass
            MenuItem("Redo", "CTRL+Y", false, false) <|
                pass
            Separator()
            MenuItem("Cut", "CTRL+X") <|
                pass
            MenuItem("Copy", "CTRL+C") <|
                pass
            MenuItem("Paste", "CTRL+V") <|
                pass

def EditorDemo()
    // creating editor context
    static_let <|
        var edc : EditorContext?
    if edc==null
        edc = imnodes::EditorContextCreate()
    // this is how we make sure node editor is full window and resizes
    Begin("Node editor",null,ImGuiWindowFlags MenuBar | ImGuiWindowFlags NoTitleBar | ImGuiWindowFlags NoResize | ImGuiWindowFlags NoMove) <|
        var IO & = imgui::GetIO()
        SetWindowPos(float2(0.,0.), ImGuiCond Once)
        SetWindowSize(float2(IO.DisplaySize.x,IO.DisplaySize.y), ImGuiCond Always)
        // main menu
        MainMenu()
        // editor
        imnodes::EditorContextSet(edc)
        BeginNodeEditor() <|
            // this is how we do context menu for the node editor
            if BeginPopupContextWindow("Node editor")
                Text("Ok")
                if BeginMenu("Sub-menu")
                    MenuItem("Click me")
                    EndMenu()
                EndPopup()
            // nodes
            EditNode(1,"One")
            EditNode(2,"Two")
            // links
            LinkNode(1234,1,2)
            // node locations
            static_let <|
                var once = true
            if once
                once = false
                SetNodeGridSpacePos(1,float2(10))
                SetNodeGridSpacePos(2,float2(50))
    // link events
    IsLinkCreated <| $ ( l_from, l_to )
        print("linked {l_from} {l_to}\n")
    IsLinkDestroyed <| $ ( l_del )
        print("unlinked {l_del}\n")


[export]
def main
	var f = 0.0
	imgui_app("Testing IMGUI") <|
        NewFrame()
        EditorDemo()
        Render()
