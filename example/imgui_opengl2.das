require math
require strings
require imgui_app
require daslib/glfw_boost
require daslib/imgui_boost
require daslib/safe_addr
require daslib/static

def imgui_app ( title:string; blk : block )
    if glfwInit()==0
		panic("can't init glfw")
    var window = glfwCreateWindow(1920, 1280, title, null, null)
    if window==null
		panic("can't create window")
    glfwMakeContextCurrent(window)
    glfwSwapInterval(1)
    CreateContext(null)
    var io & = GetIO()
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
    ImGui_ImplOpenGL2_Shutdown()
    ImGui_ImplGlfw_Shutdown()
    DestroyContext(null)
    glfwDestroyWindow(window)
    glfwTerminate()

def HelpMarker(desc:string)
    TextDisabled("(?)")
    if IsItemHovered()
        BeginTooltip()
        PushTextWrapPos(GetFontSize() * 35.0f)
        TextUnformatted(desc)
        PopTextWrapPos()
        EndTooltip()

def DasShowUserGuide()
    let io & = GetIO()
    BulletText("Double-click on title bar to collapse window.")
    BulletText(
        "Click and drag on lower corner to resize window\n" +
        "(double-click to auto fit window to its contents).")
    BulletText("CTRL+Click on a slider or drag box to input value as text.")
    BulletText("TAB/SHIFT+TAB to cycle through keyboard editable fields.")
    if io.FontAllowUserScaling
        BulletText("CTRL+Mouse Wheel to zoom window contents.")
    BulletText("While inputing text:\n")
    Indent()
    BulletText("CTRL+Left/Right to word jump.")
    BulletText("CTRL+A or double-click to select all.")
    BulletText("CTRL+X/C/V to use clipboard cut/copy/paste.")
    BulletText("CTRL+Z,CTRL+Y to undo/redo.")
    BulletText("ESCAPE to revert.")
    BulletText("You can apply arithmetic operators +,*,/ on numerical values.\nUse +- to subtract.")
    Unindent()
    BulletText("With keyboard navigation enabled:")
    Indent()
    BulletText("Arrow keys to navigate.")
    BulletText("Space to activate a widget.")
    BulletText("Return to input text into a widget.")
    BulletText("Escape to deactivate a widget, close popup, exit child window.")
    BulletText("Alt to jump to the menu layer of a window.")
    BulletText("CTRL+Tab to select a window.")
    Unindent()


def DasShowDemoWindow ( _p_open : bool? )

    var p_open = _p_open

    verify(GetCurrentContext() != null, "Missing dear imgui context. Refer to examples app!")

    static_let <|
        var show_app_main_menu_bar = false
        var show_app_documents = false
        var show_app_console = false
        var show_app_log = false
        var show_app_layout = false
        var show_app_property_editor = false
        var show_app_long_text = false
        var show_app_auto_resize = false
        var show_app_constrained_resize = false
        var show_app_simple_overlay = false
        var show_app_window_titles = false
        var show_app_custom_rendering = false

/*
    if (show_app_main_menu_bar)       ShowExampleAppMainMenuBar();
    if (show_app_documents)           ShowExampleAppDocuments(&show_app_documents);

    if (show_app_console)             ShowExampleAppConsole(&show_app_console);
    if (show_app_log)                 ShowExampleAppLog(&show_app_log);
    if (show_app_layout)              ShowExampleAppLayout(&show_app_layout);
    if (show_app_property_editor)     ShowExampleAppPropertyEditor(&show_app_property_editor);
    if (show_app_long_text)           ShowExampleAppLongText(&show_app_long_text);
    if (show_app_auto_resize)         ShowExampleAppAutoResize(&show_app_auto_resize);
    if (show_app_constrained_resize)  ShowExampleAppConstrainedResize(&show_app_constrained_resize);
    if (show_app_simple_overlay)      ShowExampleAppSimpleOverlay(&show_app_simple_overlay);
    if (show_app_window_titles)       ShowExampleAppWindowTitles(&show_app_window_titles);
    if (show_app_custom_rendering)    ShowExampleAppCustomRendering(&show_app_custom_rendering);
*/

    static_let <|
        var show_app_metrics = false
        var show_app_style_editor = false
        var show_app_about = false

    /*
    if (show_app_metrics)       { ImGui::ShowMetricsWindow(&show_app_metrics); }
    if (show_app_about)         { ImGui::ShowAboutWindow(&show_app_about); }
    */

    if show_app_style_editor
        Begin("Dear ImGui Style Editor", safe_addr(show_app_style_editor))
        ShowStyleEditor()
        End()

    static_let <|
        var no_titlebar = false
        var no_scrollbar = false
        var no_menu = false
        var no_move = false
        var no_resize = false
        var no_collapse = false
        var no_close = false
        var no_nav = false
        var no_background = false
        var no_bring_to_front = false

    var window_flags : ImGuiWindowFlags
    if no_titlebar
        window_flags |= ImGuiWindowFlags NoTitleBar
    if no_scrollbar
        window_flags |= ImGuiWindowFlags NoScrollbar
    if !no_menu
        window_flags |= ImGuiWindowFlags MenuBar
    if no_move
        window_flags |= ImGuiWindowFlags NoMove
    if no_resize
        window_flags |= ImGuiWindowFlags NoResize
    if no_collapse
        window_flags |= ImGuiWindowFlags NoCollapse
    if no_nav
        window_flags |= imgui_boost::ImGuiWindowFlags_NoNav
    if no_background
        window_flags |= ImGuiWindowFlags NoBackground
    if no_bring_to_front
        window_flags |= ImGuiWindowFlags NoBringToFrontOnFocus
    if no_close
        p_open = null

    SetNextWindowPos( ImVec2(650., 20.), ImGuiCond FirstUseEver)
    SetNextWindowSize( ImVec2(550., 680.), ImGuiCond FirstUseEver)

    if !Begin("Dear ImGui Demo", p_open, window_flags)
        End()

    PushItemWidth(float(GetFontSize()) * -12.)

    if BeginMenuBar()
        if BeginMenu("Menu")
            ShowExampleMenuFile()
            EndMenu()
        if BeginMenu("Examples")
            MenuItem("Main menu bar", show_app_main_menu_bar)
            MenuItem("Console", show_app_console)
            MenuItem("Log", show_app_log)
            MenuItem("Simple layout", show_app_layout)
            MenuItem("Property editor", show_app_property_editor)
            MenuItem("Long text display", show_app_long_text)
            MenuItem("Auto-resizing window", show_app_auto_resize)
            MenuItem("Constrained-resizing window", show_app_constrained_resize)
            MenuItem("Simple overlay", show_app_simple_overlay)
            MenuItem("Manipulating window titles", show_app_window_titles)
            MenuItem("Custom rendering", show_app_custom_rendering)
            MenuItem("Documents", show_app_documents)
            EndMenu()
        if BeginMenu("Tools")
            MenuItem("Metrics/Debugger", show_app_metrics)
            MenuItem("Style Editor", show_app_style_editor)
            MenuItem("About Dear ImGui", show_app_about)
            EndMenu()
        EndMenuBar()

    Text("dear imgui says hello. {IMGUI_VERSION}")
    Spacing()

    if CollapsingHeader("Help")
        Text("ABOUT THIS DEMO:")
        BulletText("Sections below are demonstrating many aspects of the library.")
        BulletText("The \"Examples\" menu above leads to more demo contents.")
        BulletText("The \"Tools\" menu above gives access to: About Box, Style Editor,\n" +
                          "and Metrics/Debugger (general purpose Dear ImGui debugging tool).")
        Separator()
        Text("PROGRAMMER GUIDE:")
        BulletText("See the ShowDemoWindow() code in imgui_demo.cpp. <- you are here!")
        BulletText("See comments in imgui.cpp.")
        BulletText("See example applications in the examples/ folder.")
        BulletText("Read the FAQ at http://www.dearimgui.org/faq/")
        BulletText("Set 'io.ConfigFlags |= NavEnableKeyboard' for keyboard controls.")
        BulletText("Set 'io.ConfigFlags |= NavEnableGamepad' for gamepad controls.")
        Separator()
        Text("USER GUIDE:")
        DasShowUserGuide()

    if CollapsingHeader("Configuration")
        var io & = GetIO()
        if TreeNode("Configuration##2")
            CheckboxFlags("io.ConfigFlags: NavEnableKeyboard", io.ConfigFlags,ImGuiConfigFlags NavEnableKeyboard)
            SameLine()
            HelpMarker("Enable keyboard controls.")
            CheckboxFlags("io.ConfigFlags: NavEnableGamepad", io.ConfigFlags, ImGuiConfigFlags NavEnableGamepad)
            SameLine()
            HelpMarker("Enable gamepad controls. Require backend to set io.BackendFlags |= ImGuiBackendFlags_HasGamepad.\n\nRead instructions in imgui.cpp for details.")
            CheckboxFlags("io.ConfigFlags: NavEnableSetMousePos", io.ConfigFlags, ImGuiConfigFlags NavEnableSetMousePos)
            SameLine()
            HelpMarker("Instruct navigation to move the mouse cursor. See comment for ImGuiConfigFlags_NavEnableSetMousePos.")
            CheckboxFlags("io.ConfigFlags: NoMouse", io.ConfigFlags, ImGuiConfigFlags NoMouse)
            var icf : ImGuiConfigFlags = ImGuiConfigFlags(io.ConfigFlags)
            if ImGuiConfigFlags(io.ConfigFlags).NoMouse
                if (float(GetTime()) % 0.40f) < 0.20f
                    SameLine()
                    Text("<<PRESS SPACE TO DISABLE>>")
                if IsKeyPressed(GetKeyIndex(ImGuiKey_ ImGuiKey_Space))
                    io.ConfigFlags &= ~int(ImGuiConfigFlags_ ImGuiConfigFlags_NoMouse)
            CheckboxFlags("io.ConfigFlags: NoMouseCursorChange", io.ConfigFlags, ImGuiConfigFlags NoMouseCursorChange)
            SameLine()
            HelpMarker("Instruct backend to not alter mouse cursor shape and visibility.")
            Checkbox("io.ConfigInputTextCursorBlink", io.ConfigInputTextCursorBlink)
            SameLine()
            HelpMarker("Enable blinking cursor (optional as some users consider it to be distracting)")
            Checkbox("io.ConfigDragClickToInputText", io.ConfigDragClickToInputText)
            SameLine()
            HelpMarker("Enable turning DragXXX widgets into text input with a simple mouse click-release (without moving).")
            Checkbox("io.ConfigWindowsResizeFromEdges", io.ConfigWindowsResizeFromEdges)
            SameLine()
            HelpMarker("Enable resizing of windows from their edges and from the lower-left corner.\nThis requires (io.BackendFlags & ImGuiBackendFlags_HasMouseCursors) because it needs mouse cursor feedback.")
            Checkbox("io.ConfigWindowsMoveFromTitleBarOnly", io.ConfigWindowsMoveFromTitleBarOnly)
            Checkbox("io.MouseDrawCursor", io.MouseDrawCursor)
            SameLine()
            HelpMarker("Instruct Dear ImGui to render a mouse cursor itself. Note that a mouse cursor rendered via your application GPU rendering path will feel more laggy than hardware cursor, but will be more in sync with your other visuals.\n\nSome desktop applications may use both kinds of cursors (e.g. enable software cursor only when resizing/dragging something).")
            Text("Also see Style->Rendering for rendering options.")
            TreePop()
            Separator()
        if TreeNode("Backend Flags")
            HelpMarker(
                "Those flags are set by the backends (imgui_impl_xxx files) to specify their capabilities.\n" +
                "Here we expose then as read-only fields to avoid breaking interactions with your backend.")
            // Make a local copy to avoid modifying actual backend flags.
            var backend_flags = io.BackendFlags
            CheckboxFlags("io.BackendFlags: HasGamepad", backend_flags, ImGuiBackendFlags HasGamepad)
            CheckboxFlags("io.BackendFlags: HasMouseCursors", backend_flags, ImGuiBackendFlags HasMouseCursors)
            CheckboxFlags("io.BackendFlags: HasSetMousePos", backend_flags, ImGuiBackendFlags HasSetMousePos)
            CheckboxFlags("io.BackendFlags: RendererHasVtxOffset", backend_flags, ImGuiBackendFlags RendererHasVtxOffset)
            TreePop()
            Separator()
        if TreeNode("Style")
            HelpMarker("The same contents can be accessed in 'Tools->Style Editor' or by calling the ShowStyleEditor() function.")
            ShowStyleEditor()
            TreePop()
            Separator()
        if TreeNode("Capture/Logging")
            HelpMarker(
                "The logging API redirects all text output so you can easily capture the content of " +
                "a window or a block. Tree nodes can be automatically expanded.\n" +
                "Try opening any of the contents below in this window and then click one of the \"Log To\" button.")
            LogButtons()
            HelpMarker("You can also call LogText() to output directly to the log without a visual output.")
            if Button("Copy \"Hello, world!\" to clipboard")
                LogToClipboard()
                LogText("Hello, world!")
                LogFinish()
            TreePop()

    if CollapsingHeader("Window options")
        if BeginTable("split", 3)
            TableNextColumn()
            Checkbox("No titlebar", no_titlebar)
            TableNextColumn()
            Checkbox("No scrollbar", no_scrollbar)
            TableNextColumn()
            Checkbox("No menu", no_menu)
            TableNextColumn()
            Checkbox("No move", no_move)
            TableNextColumn()
            Checkbox("No resize", no_resize)
            TableNextColumn()
            Checkbox("No collapse", no_collapse)
            TableNextColumn()
            Checkbox("No close", no_close)
            TableNextColumn()
            Checkbox("No nav", no_nav)
            TableNextColumn()
            Checkbox("No background", no_background)
            TableNextColumn()
            Checkbox("No bring to front", no_bring_to_front)
            EndTable()

    /*
    ShowDemoWindowWidgets()
    */
    ShowDemoWindowLayout()
    ShowDemoWindowPopups()
    /*
    ShowDemoWindowTables()
    */
    ShowDemoWindowMisc()
    PopItemWidth()
    End()

def ShowDemoWindowPopups()
    if !CollapsingHeader("Popups & Modal windows")
        return

    if TreeNode("Popups")
        TextWrapped(
            "When a popup is active, it inhibits interacting with windows that are behind the popup. " +
            "Clicking outside the popup closes it.")

        static_let <|
            var selected_fish = -1
            var toggles <- [{bool[] true; false; false; false; false}]
            let names <- [{auto[] "Bream"; "Haddock"; "Mackerel"; "Pollock"; "Tilefish"}]

        if Button("Select..")
            OpenPopup("my_select_popup")
        SameLine()
        TextUnformatted(selected_fish == -1 ? "<None>" : names[selected_fish])
        if BeginPopup("my_select_popup")
            Text("Aquarium")
            Separator()
            for name,i in names,range(100500)
                if Selectable(name)
                    selected_fish = i
            EndPopup()
        if Button("Toggle..")
            OpenPopup("my_toggle_popup")
        if BeginPopup("my_toggle_popup")
            for name,toggle in names,toggles
                imgui_boost::MenuItem(name, "", toggle)
            if BeginMenu("Sub-menu")
                MenuItem("Click me")
                EndMenu()
            Separator()
            Text("Tooltip here")
            if IsItemHovered()
                SetTooltip("I am a tooltip over a popup")
            if Button("Stacked Popup")
                OpenPopup("another popup")
            if BeginPopup("another popup")
                for name,toggle in names,toggles
                    imgui_boost::MenuItem(name, "", toggle)
                if BeginMenu("Sub-menu")
                    MenuItem("Click me")
                    if Button("Stacked Popup")
                        OpenPopup("another popup")
                    if BeginPopup("another popup")
                        Text("I am the last one here.")
                        EndPopup()
                    EndMenu()
                EndPopup()
            EndPopup()

        if Button("File Menu..")
            OpenPopup("my_file_popup")
        if BeginPopup("my_file_popup")
            ShowExampleMenuFile()
            EndPopup()
        TreePop()

    if TreeNode("Context menus")
        static_let <|
            var value = 0.5f
        Text("Value = {value} (<-- right-click here)")
        if BeginPopupContextItem("item context menu")
            if Selectable("Set to zero")
                value = 0.0f
            if Selectable("Set to PI")
                value = 3.1415f
            SetNextItemWidth(-1.)
            DragFloat("##Value", safe_addr(value), 0.1f, 0.0f, 0.0f)
            EndPopup()
        Text("(You can also right-click me to open the same popup as above.)")
        OpenPopupOnItemClick("item context menu", 1)
        static_let <|
            var name = reserve_string_buffer("Label1", 32)
        var buf = "Button: {name}"
        Button(buf)
        if BeginPopupContextItem()
            Text("Edit name:")
            InputText("##edit", name, 32)
            if Button("Close")
                CloseCurrentPopup()
            EndPopup()
        SameLine()
        Text("(<-- right-click here)")
        TreePop()

    if TreeNode("Modals")
        TextWrapped("Modal windows are like popups but the user cannot close them by clicking outside.")
        if Button("Delete..")
            OpenPopup("Delete?")
        var center = ImVec2(GetIO().DisplaySize.x * 0.5f, GetIO().DisplaySize.y * 0.5f)
        SetNextWindowPos(center, ImGuiCond Appearing, ImVec2(0.5f, 0.5f))
        if BeginPopupModal("Delete?", null, ImGuiWindowFlags AlwaysAutoResize)
            Text("All those beautiful files will be deleted.\nThis operation cannot be undone!\n\n")
            Separator()
            static_let <|
                var unused_i = 0
            Combo("Combo", unused_i, [[auto "Delete"; "Delete harder"]])
            static_let <|
                var dont_ask_me_next_time = false
            PushStyleVar(ImGuiStyleVar_ ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f))
            Checkbox("Don't ask me next time", dont_ask_me_next_time)
            PopStyleVar()
            if Button("OK", ImVec2(120., 0.))
                CloseCurrentPopup()
            SetItemDefaultFocus()
            SameLine()
            if Button("Cancel", ImVec2(120., 0.))
                CloseCurrentPopup()
            EndPopup()
        if Button("Stacked modals..")
            OpenPopup("Stacked 1")
        if BeginPopupModal("Stacked 1", null, ImGuiWindowFlags MenuBar)
            if BeginMenuBar()
                if BeginMenu("File")
                    if MenuItem("Some menu item")
                        pass
                    EndMenu()
                EndMenuBar()
            Text("Hello from Stacked The First\nUsing style.Colors[ImGuiCol_ModalWindowDimBg] behind it.")
            static_let <|
                var item = 1
                var color = [[float[4] 0.4f; 0.7f; 0.0f; 0.5f]]
            Combo("Combo", item, [[auto "aaaa"; "bbbb"; "cccc"; "dddd"; "eeee"]])
            ColorEdit4("color", color)
            if Button("Add another modal..")
                OpenPopup("Stacked 2")
            static_let <|
                var unused_open = true
            if BeginPopupModal("Stacked 2", unused_open)
                Text("Hello from Stacked The Second!")
                if Button("Close")
                    CloseCurrentPopup()
                EndPopup()
            if Button("Close")
                CloseCurrentPopup()
            EndPopup()
        TreePop()

    if TreeNode("Menus inside a regular window")
        TextWrapped("Below we are testing adding menu items to a regular window. It's rather unusual but should work!")
        Separator()
        PushID("foo")
        MenuItem("Menu item", "CTRL+M")
        if BeginMenu("Menu inside a regular window")
            ShowExampleMenuFile()
            EndMenu()
        PopID()
        Separator()
        TreePop()

def ShowExampleMenuFile()
    MenuItem("(demo menu)", "", false, false)
    if MenuItem("New")
        pass
    if MenuItem("Open", "Ctrl+O")
        pass
    if BeginMenu("Open Recent")
        MenuItem("fish_hat.c")
        MenuItem("fish_hat.inl")
        MenuItem("fish_hat.h")
        if BeginMenu("More..")
            MenuItem("Hello")
            MenuItem("Sailor")
            if BeginMenu("Recurse..")
                ShowExampleMenuFile()
                EndMenu()
            EndMenu()
        EndMenu()
    if MenuItem("Save", "Ctrl+S")
        pass
    if MenuItem("Save As..")
        pass

    Separator()
    if BeginMenu("Options")
        static_let <|
            var enabled = true
        imgui_boost::MenuItem("Enabled", "", enabled)
        BeginChild("child", ImVec2(0., 60.), true)
        for i in range(1)
            Text("Scrolling Text {i}")
        EndChild()
        static_let <|
            var f = 0.5f
            var n = 0
        SliderFloat("Value", f, 0.0f, 1.0f)
        InputFloat("Input", f, 0.1f)
        Combo("Combo", n, [[auto "Yes";"No";"Maybe"]])
        EndMenu()

    if BeginMenu("Colors")
        let sz = GetTextLineHeight()
        for col,i in range(100500),each_enum(type<ImGuiCol_>)
            if i == ImGuiCol_ ImGuiCol_COUNT
                continue
            let name = GetStyleColorName(col)
            let p = GetCursorScreenPos()
            *GetWindowDrawList() |> AddRectFilled(p, ImVec2(p.x + sz, p.y + sz), GetColorU32(uint(i)))
            Dummy(ImVec2(sz, sz))
            SameLine()
            MenuItem(name)
        EndMenu()

    if BeginMenu("Options")
        static_let <|
            var b = true
        Checkbox("SomeOption", b)
        EndMenu()

    if BeginMenu("Disabled", false)
        assert(false)
    if MenuItem("Checked", "", true)
        pass
    if MenuItem("Quit", "Alt+F4")
        pass

def ShowDemoWindowMisc()
    if CollapsingHeader("Filtering")
        static_let <|
            var filter = new ImGuiTextFilter
        Text("Filter usage:\n" +
                    "  \"\"         display all lines\n" +
                    "  \"xxx\"      display lines containing \"xxx\"\n" +
                    "  \"xxx,yyy\"  display lines containing \"xxx\" or \"yyy\"\n" +
                    "  \"-xxx\"     hide lines containing \"xxx\"")

        *filter |> Draw()
        static_let <|
            var lines = [[string[] "aaa1.c"; "bbb1.c"; "ccc1.c"; "aaa2.cpp"; "bbb2.cpp"; "ccc2.cpp"; "abc.h"; "hello, world"]]
        for ln in lines
            if *filter |> PassFilter(ln)
                BulletText("{ln}")

    if CollapsingHeader("Inputs, Navigation & Focus")
        var io & = GetIO()

        Text("WantCaptureMouse: {io.WantCaptureMouse}")
        Text("WantCaptureKeyboard: {io.WantCaptureKeyboard}")
        Text("WantTextInput: {io.WantTextInput}")
        Text("WantSetMousePos: {io.WantSetMousePos}")
        Text("NavActive: {io.NavActive}, NavVisible: {io.NavVisible}")

        if TreeNode("Keyboard, Mouse & Navigation State")
            if (IsMousePosValid())
                Text("Mouse pos: ({io.MousePos.x}, {io.MousePos.y})")
            else
                Text("Mouse pos: <INVALID>")
            Text("Mouse delta: ({io.MouseDelta.x}, {io.MouseDelta.y})")
            Text("Mouse down:")
            for i in range(length(io.MouseDown))
                if io.MouseDownDuration[i] >= 0.0f
                    SameLine()
                    Text("b{i} ({io.MouseDownDuration[i]} secs)")
            Text("Mouse clicked:")
            for i in range(length(io.MouseDown))
                if IsMouseClicked(i)
                    SameLine()
                    Text("b{i}")
            Text("Mouse dblclick:")
            for i in range(length(io.MouseDown))
                if IsMouseDoubleClicked(i)
                    SameLine()
                    Text("b{i}")
            Text("Mouse released:")
            for i in range(length(io.MouseDown))
                if IsMouseReleased(i)
                    SameLine()
                    Text("b{i}")
            Text("Mouse wheel: {io.MouseWheel}")
            Text("Keys down:")
            for i in range(length(io.KeysDown))
                if io.KeysDownDuration[i] >= 0.0f
                    SameLine()
                    Text("{i} (0x{uint(i)}) ({io.KeysDownDuration[i]} secs)")
            Text("Keys pressed:")
            for i in range(length(io.KeysDown))
                if IsKeyPressed(i)
                    SameLine()
                    Text("{i} (0x{uint(i)})")
            Text("Keys release:")
            for i in range(length(io.KeysDown))
                if IsKeyReleased(i)
                    SameLine()
                    Text("{i} (0x{uint(i)})")
            Text("Keys mods: {io.KeyCtrl ? "CTRL " : ""}{io.KeyShift ? "SHIFT " : ""}{io.KeyAlt ? "ALT " : ""}{io.KeySuper ? "SUPER " : ""}")

            // TODO: support ImVector
            /*
            Text("Chars queue:")
            for i in range(io.InputQueueCharacters.Size)
                let c = io.InputQueueCharacters[i]
                SameLine()
                Text("'{(c > ' ' && c <= 255) ? to_char(c) : "?"}' (0x{uint(c)})")
            */

            Text("NavInputs down:")
            for i in range(length(io.NavInputs))
                if io.NavInputs[i] > 0.0f
                    SameLine()
                    Text("[{i}] {io.NavInputs[i]}")
            Text("NavInputs pressed:")
            for i in range(length(io.NavInputs))
                if io.NavInputsDownDuration[i] == 0.0f
                    SameLine()
                    Text("[{i}]")
            Text("NavInputs duration:")
            for i in range(length(io.NavInputs))
                if io.NavInputsDownDuration[i] >= 0.0f
                    SameLine()
                    Text("[{i}] {io.NavInputsDownDuration[i]}")
            Button("Hovering me sets the\nkeyboard capture flag")
            if IsItemHovered()
                CaptureKeyboardFromApp(true)
            SameLine()
            Button("Holding me clears the\nthe keyboard capture flag")
            if IsItemActive()
                CaptureKeyboardFromApp(false)
            TreePop()

        if TreeNode("Tabbing")
            static_let <|
                var buft = reserve_string_buffer("hello", 32)
            Text("Use TAB/SHIFT+TAB to cycle through keyboard editable fields.")
            InputText("1", buft, 32)
            InputText("2", buft, 32)
            InputText("3", buft, 32)
            PushAllowKeyboardFocus(false)
            InputText("4 (tab skip)", buft, 32)
            PopAllowKeyboardFocus()
            InputText("5", buft, 32)
            TreePop()

        if TreeNode("Focus from code")
            var focus_1 = Button("Focus on 1")
            SameLine()
            var focus_2 = Button("Focus on 2")
            SameLine()
            var focus_3 = Button("Focus on 3")
            var has_focus = 0
            static_let <|
                var buf = reserve_string_buffer("click on a button to set focus", 128)
            if focus_1
                SetKeyboardFocusHere()
            InputText("1", buf, 128)
            if IsItemActive()
                has_focus = 1
            if focus_2
                SetKeyboardFocusHere()
            InputText("2", buf, 128)
            if IsItemActive()
                has_focus = 2
            PushAllowKeyboardFocus(false)
            if focus_3
                SetKeyboardFocusHere()
            InputText("3 (tab skip)", buf, 128)
            if IsItemActive()
                has_focus = 3
            PopAllowKeyboardFocus()
            if has_focus!=0
                Text("Item with focus: {has_focus}")
            else
                Text("Item with focus: <none>")
            static_let <|
                var f3 = [[float[3] 0.0f; 0.0f; 0.0f ]]
            var focus_ahead = -1
            if Button("Focus on X")
                focus_ahead = 0
            SameLine()
            if Button("Focus on Y")
                focus_ahead = 1
            SameLine()
            if Button("Focus on Z")
                focus_ahead = 2
            if focus_ahead != -1
                SetKeyboardFocusHere(focus_ahead)
            SliderFloat3("Float3", safe_addr(f3[0]), 0.0f, 1.0f)
            TextWrapped("NB: Cursor & selection are preserved when refocusing last used item in code.")
            TreePop()

        if TreeNode("Dragging")
            TextWrapped("You can use GetMouseDragDelta(0) to query for the dragged amount on any widget.")
            for button in range(3)
                Text("IsMouseDragging({button}):")
                Text("  w/ default threshold: {IsMouseDragging(button)},")
                Text("  w/ zero threshold: {IsMouseDragging(button, 0.0f)},")
                Text("  w/ large threshold: {IsMouseDragging(button, 20.0f)},")
            Button("Drag Me")
            if IsItemActive()
                *GetForegroundDrawList() |> AddLine(
                    io.MouseClickedPos[0],
                    io.MousePos,
                    GetColorU32(int(ImGuiCol_ ImGuiCol_Button)),
                    4.0f)
            let value_raw = GetMouseDragDelta(0, 0.0f)
            let value_with_lock_threshold = GetMouseDragDelta(0)
            let mouse_delta = io.MouseDelta;
            Text("GetMouseDragDelta(0):")
            Text("  w/ default threshold: ({value_with_lock_threshold.x}, {value_with_lock_threshold.y})")
            Text("  w/ zero threshold: ({value_raw.x}, {value_raw.y})")
            Text("io.MouseDelta: ({mouse_delta.x}, {mouse_delta.y})")
            TreePop()

        if TreeNode("Mouse cursors")
            static_let <|
                var mouse_cursors_names = [[string[] "Arrow"; "TextInput"; "ResizeAll"; "ResizeNS"; "ResizeEW"; "ResizeNESW"; "ResizeNWSE"; "Hand"; "NotAllowed" ]]
            let current = GetMouseCursor()
            Text("Current mouse cursor = {current}: {mouse_cursors_names[current]}")
            Text("Hover to see mouse cursors:")
            SameLine()
            HelpMarker(
                "Your application can render a different mouse cursor based on what GetMouseCursor() returns. " +
                "If software cursor rendering (io.MouseDrawCursor) is set ImGui will draw the right cursor for you, " +
                "otherwise your backend needs to handle it.")
            for mcn,i in mouse_cursors_names,range(100500)
                let lab = "Mouse cursor {i}: {mcn}"
                Bullet()
                Selectable(lab, false)
                if IsItemHovered()
                    SetMouseCursor(i)
            TreePop()

/*
static void ShowDemoWindowLayout()
{

    if (TreeNode("Child windows"))
    {
        HelpMarker("Use child windows to begin into a self-contained independent scrolling/clipping regions within a host window.")
        static bool disable_mouse_wheel = false;
        static bool disable_menu = false;
        Checkbox("Disable Mouse Wheel", &disable_mouse_wheel)
        Checkbox("Disable Menu", &disable_menu)

        // Child 1: no border, enable horizontal scrollbar
        {
            ImGuiWindowFlags window_flags = ImGuiWindowFlags_HorizontalScrollbar;
            if (disable_mouse_wheel)
                window_flags |= ImGuiWindowFlags_NoScrollWithMouse;
            BeginChild("ChildL", ImVec2(GetWindowContentRegionWidth() * 0.5f, 260), false, window_flags)
            for (int i = 0; i < 100; i++)
                Text("%04d: scrollable region", i)
            EndChild()
        }

        SameLine()

        // Child 2: rounded border
        {
            ImGuiWindowFlags window_flags = ImGuiWindowFlags_None;
            if (disable_mouse_wheel)
                window_flags |= ImGuiWindowFlags_NoScrollWithMouse;
            if (!disable_menu)
                window_flags |= ImGuiWindowFlags_MenuBar;
            PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f)
            BeginChild("ChildR", ImVec2(0, 260), true, window_flags)
            if (!disable_menu && BeginMenuBar())
            {
                if (BeginMenu("Menu"))
                {
                    ShowExampleMenuFile()
                    EndMenu()
                }
                EndMenuBar()
            }
            if (BeginTable("split", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_NoSavedSettings))
            {
                for (int i = 0; i < 100; i++)
                {
                    char buf[32];
                    sprintf(buf, "%03d", i)
                    TableNextColumn()
                    Button(buf, ImVec2(-FLT_MIN, 0.0f))
                }
                EndTable()
            }
            EndChild()
            PopStyleVar()
        }

        Separator()

        // Demonstrate a few extra things
        // - Changing ImGuiCol_ChildBg (which is transparent black in default styles)
        // - Using SetCursorPos() to position child window (the child window is an item from the POV of parent window)
        //   You can also call SetNextWindowPos() to position the child window. The parent window will effectively
        //   layout from this position.
        // - Using GetItemRectMin/Max() to query the "item" state (because the child window is an item from
        //   the POV of the parent window). See 'Demo->Querying Status (Active/Focused/Hovered etc.)' for details.
        {
            static int offset_x = 0;
            SetNextItemWidth(100)
            DragInt("Offset X", &offset_x, 1.0f, -1000, 1000)

            SetCursorPosX(GetCursorPosX() + (float)offset_x)
            PushStyleColor(ImGuiCol_ChildBg, IM_COL32(255, 0, 0, 100))
            BeginChild("Red", ImVec2(200, 100), true, ImGuiWindowFlags_None)
            for (int n = 0; n < 50; n++)
                Text("Some test %d", n)
            EndChild()
            bool child_is_hovered = IsItemHovered()
            ImVec2 child_rect_min = GetItemRectMin()
            ImVec2 child_rect_max = GetItemRectMax()
            PopStyleColor()
            Text("Hovered: %d", child_is_hovered)
            Text("Rect of child window is: (%.0f,%.0f) (%.0f,%.0f)", child_rect_min.x, child_rect_min.y, child_rect_max.x, child_rect_max.y)
        }

        TreePop()
    }

    if (TreeNode("Widgets Width"))
    {
        // Use SetNextItemWidth() to set the width of a single upcoming item.
        // Use PushItemWidth()/PopItemWidth() to set the width of a group of items.
        // In real code use you'll probably want to choose width values that are proportional to your font size
        // e.g. Using '20.0f * GetFontSize()' as width instead of '200.0f', etc.

        static float f = 0.0f;
        static bool show_indented_items = true;
        Checkbox("Show indented items", &show_indented_items)

        Text("SetNextItemWidth/PushItemWidth(100)")
        SameLine() HelpMarker("Fixed width.")
        PushItemWidth(100)
        DragFloat("float##1b", &f)
        if (show_indented_items)
        {
            Indent()
            DragFloat("float (indented)##1b", &f)
            Unindent()
        }
        PopItemWidth()

        Text("SetNextItemWidth/PushItemWidth(-100)")
        SameLine() HelpMarker("Align to right edge minus 100")
        PushItemWidth(-100)
        DragFloat("float##2a", &f)
        if (show_indented_items)
        {
            Indent()
            DragFloat("float (indented)##2b", &f)
            Unindent()
        }
        PopItemWidth()

        Text("SetNextItemWidth/PushItemWidth(GetContentRegionAvail().x * 0.5f)")
        SameLine() HelpMarker("Half of available width.\n(~ right-cursor_pos)\n(works within a column set)")
        PushItemWidth(GetContentRegionAvail().x * 0.5f)
        DragFloat("float##3a", &f)
        if (show_indented_items)
        {
            Indent()
            DragFloat("float (indented)##3b", &f)
            Unindent()
        }
        PopItemWidth()

        Text("SetNextItemWidth/PushItemWidth(-GetContentRegionAvail().x * 0.5f)")
        SameLine() HelpMarker("Align to right edge minus half")
        PushItemWidth(-GetContentRegionAvail().x * 0.5f)
        DragFloat("float##4a", &f)
        if (show_indented_items)
        {
            Indent()
            DragFloat("float (indented)##4b", &f)
            Unindent()
        }
        PopItemWidth()

        // Demonstrate using PushItemWidth to surround three items.
        // Calling SetNextItemWidth() before each of them would have the same effect.
        Text("SetNextItemWidth/PushItemWidth(-FLT_MIN)")
        SameLine() HelpMarker("Align to right edge")
        PushItemWidth(-FLT_MIN)
        DragFloat("##float5a", &f)
        if (show_indented_items)
        {
            Indent()
            DragFloat("float (indented)##5b", &f)
            Unindent()
        }
        PopItemWidth()

        TreePop()
    }

    if (TreeNode("Basic Horizontal Layout"))
    {
        TextWrapped("(Use SameLine() to keep adding items to the right of the preceding item)")

        // Text
        Text("Two items: Hello") SameLine()
        TextColored(ImVec4(1,1,0,1), "Sailor")

        // Adjust spacing
        Text("More spacing: Hello") SameLine(0, 20)
        TextColored(ImVec4(1,1,0,1), "Sailor")

        // Button
        AlignTextToFramePadding()
        Text("Normal buttons") SameLine()
        Button("Banana") SameLine()
        Button("Apple") SameLine()
        Button("Corniflower")

        // Button
        Text("Small buttons") SameLine()
        SmallButton("Like this one") SameLine()
        Text("can fit within a text block.")

        // Aligned to arbitrary position. Easy/cheap column.
        Text("Aligned")
        SameLine(150) Text("x=150")
        SameLine(300) Text("x=300")
        Text("Aligned")
        SameLine(150) SmallButton("x=150")
        SameLine(300) SmallButton("x=300")

        // Checkbox
        static bool c1 = false, c2 = false, c3 = false, c4 = false;
        Checkbox("My", &c1) SameLine()
        Checkbox("Tailor", &c2) SameLine()
        Checkbox("Is", &c3) SameLine()
        Checkbox("Rich", &c4)

        // Various
        static float f0 = 1.0f, f1 = 2.0f, f2 = 3.0f;
        PushItemWidth(80)
        const char* items[] = { "AAAA", "BBBB", "CCCC", "DDDD" };
        static int item = -1;
        Combo("Combo", &item, items, IM_ARRAYSIZE(items)) SameLine()
        SliderFloat("X", &f0, 0.0f, 5.0f) SameLine()
        SliderFloat("Y", &f1, 0.0f, 5.0f) SameLine()
        SliderFloat("Z", &f2, 0.0f, 5.0f)
        PopItemWidth()

        PushItemWidth(80)
        Text("Lists:")
        static int selection[4] = { 0, 1, 2, 3 };
        for (int i = 0; i < 4; i++)
        {
            if (i > 0) SameLine()
            PushID(i)
            ListBox("", &selection[i], items, IM_ARRAYSIZE(items))
            PopID()
            //if (IsItemHovered()) SetTooltip("ListBox %d hovered", i)
        }
        PopItemWidth()

        // Dummy
        ImVec2 button_sz(40, 40)
        Button("A", button_sz) SameLine()
        Dummy(button_sz) SameLine()
        Button("B", button_sz)

        // Manually wrapping
        // (we should eventually provide this as an automatic layout feature, but for now you can do it manually)
        Text("Manually wrapping:")
        ImGuiStyle& style = GetStyle()
        int buttons_count = 20;
        float window_visible_x2 = GetWindowPos().x + GetWindowContentRegionMax().x;
        for (int n = 0; n < buttons_count; n++)
        {
            PushID(n)
            Button("Box", button_sz)
            float last_button_x2 = GetItemRectMax().x;
            float next_button_x2 = last_button_x2 + style.ItemSpacing.x + button_sz.x; // Expected position if next button was on same line
            if (n + 1 < buttons_count && next_button_x2 < window_visible_x2)
                SameLine()
            PopID()
        }

        TreePop()
    }

    if (TreeNode("Groups"))
    {
        HelpMarker(
            "BeginGroup() basically locks the horizontal position for new line. "
            "EndGroup() bundles the whole group so that you can use \"item\" functions such as "
            "IsItemHovered()/IsItemActive() or SameLine() etc. on the whole group.")
        BeginGroup()
        {
            BeginGroup()
            Button("AAA")
            SameLine()
            Button("BBB")
            SameLine()
            BeginGroup()
            Button("CCC")
            Button("DDD")
            EndGroup()
            SameLine()
            Button("EEE")
            EndGroup()
            if (IsItemHovered())
                SetTooltip("First group hovered")
        }
        // Capture the group size and create widgets using the same size
        ImVec2 size = GetItemRectSize()
        const float values[5] = { 0.5f, 0.20f, 0.80f, 0.60f, 0.25f };
        PlotHistogram("##values", values, IM_ARRAYSIZE(values), 0, NULL, 0.0f, 1.0f, size)

        Button("ACTION", ImVec2((size.x - GetStyle().ItemSpacing.x) * 0.5f, size.y))
        SameLine()
        Button("REACTION", ImVec2((size.x - GetStyle().ItemSpacing.x) * 0.5f, size.y))
        EndGroup()
        SameLine()

        Button("LEVERAGE\nBUZZWORD", size)
        SameLine()

        if (ListBoxHeader("List", size))
        {
            Selectable("Selected", true)
            Selectable("Not Selected", false)
            ListBoxFooter()
        }

        TreePop()
    }

    if (TreeNode("Text Baseline Alignment"))
    {
        {
            BulletText("Text baseline:")
            SameLine() HelpMarker(
                "This is testing the vertical alignment that gets applied on text to keep it aligned with widgets. "
                "Lines only composed of text or \"small\" widgets use less vertical space than lines with framed widgets.")
            Indent()

            Text("KO Blahblah") SameLine()
            Button("Some framed item") SameLine()
            HelpMarker("Baseline of button will look misaligned with text..")

            // If your line starts with text, call AlignTextToFramePadding() to align text to upcoming widgets.
            // (because we don't know what's coming after the Text() statement, we need to move the text baseline
            // down by FramePadding.y ahead of time)
            AlignTextToFramePadding()
            Text("OK Blahblah") SameLine()
            Button("Some framed item") SameLine()
            HelpMarker("We call AlignTextToFramePadding() to vertically align the text baseline by +FramePadding.y")

            // SmallButton() uses the same vertical padding as Text
            Button("TEST##1") SameLine()
            Text("TEST") SameLine()
            SmallButton("TEST##2")

            // If your line starts with text, call AlignTextToFramePadding() to align text to upcoming widgets.
            AlignTextToFramePadding()
            Text("Text aligned to framed item") SameLine()
            Button("Item##1") SameLine()
            Text("Item") SameLine()
            SmallButton("Item##2") SameLine()
            Button("Item##3")

            Unindent()
        }

        Spacing()

        {
            BulletText("Multi-line text:")
            Indent()
            Text("One\nTwo\nThree") SameLine()
            Text("Hello\nWorld") SameLine()
            Text("Banana")

            Text("Banana") SameLine()
            Text("Hello\nWorld") SameLine()
            Text("One\nTwo\nThree")

            Button("HOP##1") SameLine()
            Text("Banana") SameLine()
            Text("Hello\nWorld") SameLine()
            Text("Banana")

            Button("HOP##2") SameLine()
            Text("Hello\nWorld") SameLine()
            Text("Banana")
            Unindent()
        }

        Spacing()

        {
            BulletText("Misc items:")
            Indent()

            // SmallButton() sets FramePadding to zero. Text baseline is aligned to match baseline of previous Button.
            Button("80x80", ImVec2(80, 80))
            SameLine()
            Button("50x50", ImVec2(50, 50))
            SameLine()
            Button("Button()")
            SameLine()
            SmallButton("SmallButton()")

            // Tree
            const float spacing = GetStyle().ItemInnerSpacing.x;
            Button("Button##1")
            SameLine(0.0f, spacing)
            if (TreeNode("Node##1"))
            {
                // Placeholder tree data
                for (int i = 0; i < 6; i++)
                    BulletText("Item %d..", i)
                TreePop()
            }

            // Vertically align text node a bit lower so it'll be vertically centered with upcoming widget.
            // Otherwise you can use SmallButton() (smaller fit).
            AlignTextToFramePadding()

            // Common mistake to avoid: if we want to SameLine after TreeNode we need to do it before we add
            // other contents below the node.
            bool node_open = TreeNode("Node##2")
            SameLine(0.0f, spacing) Button("Button##2")
            if (node_open)
            {
                // Placeholder tree data
                for (int i = 0; i < 6; i++)
                    BulletText("Item %d..", i)
                TreePop()
            }

            // Bullet
            Button("Button##3")
            SameLine(0.0f, spacing)
            BulletText("Bullet text")

            AlignTextToFramePadding()
            BulletText("Node")
            SameLine(0.0f, spacing) Button("Button##4")
            Unindent()
        }

        TreePop()
    }
*/

def ShowDemoWindowLayout
    if !CollapsingHeader("Layout & Scrolling")
        return

    if TreeNode("Scrolling")
        HelpMarker("Use SetScrollHereY() or SetScrollFromPosY() to scroll to a given vertical position.")
        static_let <|
            var track_item = 50
            var enable_track = true
            var enable_extra_decorations = false
            var scroll_to_off_px = 0.0f
            var scroll_to_pos_px = 200.0f
        Checkbox("Decoration", safe_addr(enable_extra_decorations))
        Checkbox("Track", safe_addr(enable_track))
        PushItemWidth(100.)
        SameLine(140.)
        enable_track = DragInt("##item", safe_addr(track_item), 0.25f, 0, 99, "Item = %d") || enable_track
        var scroll_to_off = Button("Scroll Offset")
        SameLine(140.)
        scroll_to_off = DragFloat("##off", safe_addr(scroll_to_off_px), 1.00f, 0., FLT_MAX, "+%.0f px") || scroll_to_off
        var scroll_to_pos = Button("Scroll To Pos")
        SameLine(140.)
        scroll_to_pos = DragFloat("##pos", safe_addr(scroll_to_pos_px), 1.00f, -10., FLT_MAX, "X/Y = %.0f px") || scroll_to_pos
        PopItemWidth()
        if scroll_to_off || scroll_to_pos
            enable_track = false
        var style & = GetStyle()
        var child_w = (GetContentRegionAvail().x - 4. * style.ItemSpacing.x) / 5.
        if child_w < 1.0f
            child_w = 1.0f
        PushID("##VerticalScrolling")
        for i in range(5)
            if i > 0
                SameLine()
            BeginGroup()
            static_let <|
                let names_v = [[string[] "Top"; "25%"; "Center"; "75%"; "Bottom" ]]
            TextUnformatted(names_v[i])
            let child_flags = enable_extra_decorations ? ImGuiWindowFlags MenuBar : bitfield(0)
            var child_id : uint
            unsafe
                child_id = GetID(reinterpret<void?> i)
            let child_is_visible = BeginChild(child_id, ImVec2(child_w, 200.0f), true, int(child_flags))
            if BeginMenuBar()
                TextUnformatted("abc")
                EndMenuBar()
            if scroll_to_off
                SetScrollY(scroll_to_off_px)
            if scroll_to_pos
                SetScrollFromPosY(GetCursorStartPos().y + scroll_to_pos_px, float(i) * 0.25f)
            if child_is_visible
                for item in range(100)
                    if enable_track && item==track_item
                        TextColored(ImVec4(1., 1., 0., 1.), "Item {item}")
                        SetScrollHereY(float(i) * 0.25f)
                    else
                        Text("Item {item}")
            let scroll_y = GetScrollY()
            let scroll_max_y = GetScrollMaxY()
            EndChild()
            Text("{scroll_y}/{scroll_max_y}")
            EndGroup()
        PopID()
        Spacing()
        HelpMarker(
            "Use SetScrollHereX() or SetScrollFromPosX() to scroll to a given horizontal position.\n\n"+
            "Because the clipping rectangle of most window hides half worth of WindowPadding on the "+
            "left/right, using SetScrollFromPosX(+1) will usually result in clipped text whereas the "+
            "equivalent SetScrollFromPosY(+1) wouldn't.")
        PushID("##HorizontalScrolling")
        for i in range(5)
            let child_height = GetTextLineHeight() + style.ScrollbarSize + style.WindowPadding.y * 2.0f
            let child_flags = ImGuiWindowFlags HorizontalScrollbar | (enable_extra_decorations ? ImGuiWindowFlags AlwaysVerticalScrollbar : bitfield(0))
            var child_id : uint
            unsafe
                child_id = GetID(reinterpret<void?> i)
            let child_is_visible = BeginChild(child_id, ImVec2(-100., child_height), true, int(child_flags))
            if scroll_to_off
                SetScrollX(scroll_to_off_px)
            if scroll_to_pos
                SetScrollFromPosX(GetCursorStartPos().x + scroll_to_pos_px, float(i) * 0.25f)
            if child_is_visible
                for item in range(100)
                    if enable_track && item == track_item
                        TextColored(ImVec4(1., 1., 0., 1.), "Item {item}")
                        SetScrollHereX(float(i) * 0.25f)
                    else
                        Text("Item {item}")
                    SameLine()
            let scroll_x = GetScrollX()
            let scroll_max_x = GetScrollMaxX()
            EndChild()
            SameLine()
            static_let <|
                let names_h = [[string[] "Left"; "25%"; "Center"; "75%"; "Right" ]]
            Text("{names_h[i]}\n{scroll_x}/{scroll_max_x}")
            Spacing()
        PopID()
        HelpMarker(
            "Horizontal scrolling for a window is enabled via the ImGuiWindowFlags_HorizontalScrollbar flag.\n\n"+
            "You may want to also explicitly specify content width by using SetNextWindowContentWidth() before Begin().")
        static_let <|
            var lines = 7
        SliderInt("Lines", safe_addr(lines), 1, 15)
        PushStyleVar(ImGuiStyleVar_ ImGuiStyleVar_FrameRounding, 3.0f)
        PushStyleVar(ImGuiStyleVar_ ImGuiStyleVar_FramePadding, ImVec2(2.0f, 1.0f))
        let scrolling_child_size = ImVec2(0., GetFrameHeightWithSpacing() * 7.0 + 30.0)
        BeginChild("scrolling", scrolling_child_size, true, int(ImGuiWindowFlags_ ImGuiWindowFlags_HorizontalScrollbar))
        for line in range(lines)
            let num_buttons = 10 + ((line & 1)!=0 ? line * 9 : line * 3)
            for n in range(num_buttons)
                if n > 0
                    SameLine()
                PushID(n + line * 1000)
                let num_buf = "{n}"
                let lab = ((n % 15)==0) ? "FizzBuzz" : ((n % 3)==0) ? "Fizz" : ((n % 5)==0) ? "Buzz" : num_buf
                let hue = float(n) * 0.05f
                PushStyleColor(ImGuiCol_ ImGuiCol_Button, ImVec4(HSV(hue, 0.6f, 0.6f)))
                PushStyleColor(ImGuiCol_ ImGuiCol_ButtonHovered,  ImVec4(HSV(hue, 0.7f, 0.7f)))
                PushStyleColor(ImGuiCol_ ImGuiCol_ButtonActive, ImVec4( HSV(hue, 0.8f, 0.8f)))
                Button(lab, ImVec2(40.0f + sin(float(line + n)) * 20.0f, 0.0f))
                PopStyleColor(3)
                PopID()
        let scroll_x = GetScrollX()
        let scroll_max_x = GetScrollMaxX()
        EndChild()
        PopStyleVar(2)
        var scroll_x_delta = 0.0f
        SmallButton("<<")
        if IsItemActive()
            scroll_x_delta = -GetIO().DeltaTime * 1000.0f
        SameLine()
        Text("Scroll from code")
        SameLine()
        SmallButton(">>")
        if IsItemActive()
            scroll_x_delta = +GetIO().DeltaTime * 1000.0f
        SameLine()
        Text("{scroll_x}/{scroll_max_x}")
        if scroll_x_delta != 0.0f
            BeginChild("scrolling", ImVec2(0.,0.))
            SetScrollX(GetScrollX() + scroll_x_delta)
            EndChild()
        Spacing()
        static_let <|
            var show_horizontal_contents_size_demo_window = false
        Checkbox("Show Horizontal contents size demo window", safe_addr(show_horizontal_contents_size_demo_window))
        if show_horizontal_contents_size_demo_window
            static_let <|
                var show_h_scrollbar = true
                var show_button = true
                var show_tree_nodes = true
                var show_text_wrapped = false
                var show_columns = true
                var show_tab_bar = true
                var show_child = false
                var explicit_content_size = false
                var contents_size_x = 300.0f
            if explicit_content_size
                SetNextWindowContentSize(ImVec2(contents_size_x, 0.0f))
            Begin("Horizontal contents size demo window", safe_addr(show_horizontal_contents_size_demo_window),
                int(show_h_scrollbar ? ImGuiWindowFlags HorizontalScrollbar : bitfield(0)))
            PushStyleVar(ImGuiStyleVar_ ImGuiStyleVar_ItemSpacing, ImVec2(2., 0.))
            PushStyleVar(ImGuiStyleVar_ ImGuiStyleVar_FramePadding, ImVec2(2., 0.))
            HelpMarker("Test of different widgets react and impact the work rectangle growing when horizontal scrolling is enabled.\n\nUse 'Metrics->Tools->Show windows rectangles' to visualize rectangles.")
            Checkbox("H-scrollbar", safe_addr(show_h_scrollbar))
            Checkbox("Button", safe_addr(show_button))
            Checkbox("Tree nodes", safe_addr(show_tree_nodes))
            Checkbox("Text wrapped", safe_addr(show_text_wrapped))
            Checkbox("Columns", safe_addr(show_columns))
            Checkbox("Tab bar", safe_addr(show_tab_bar))
            Checkbox("Child", safe_addr(show_child))
            Checkbox("Explicit content size", safe_addr(explicit_content_size))
            Text("Scroll {GetScrollX()}/{GetScrollMaxX()} {GetScrollY()}/{GetScrollMaxY()}")
            if explicit_content_size
                SameLine()
                SetNextItemWidth(100.)
                DragFloat("##csx", safe_addr(contents_size_x))
                var p = GetCursorScreenPos()
                *GetWindowDrawList() |> AddRectFilled(p, ImVec2(p.x + 10., p.y + 10.), IM_COL32_WHITE)
                *GetWindowDrawList() |> AddRectFilled(ImVec2(p.x + contents_size_x - 10., p.y), ImVec2(p.x + contents_size_x, p.y + 10.), IM_COL32_WHITE)
                Dummy(ImVec2(0., 10.))
            PopStyleVar(2)
            Separator()
            if show_button
                Button("this is a 300-wide button", ImVec2(300., 0.))
            if show_tree_nodes
                var open = true
                if TreeNode("this is a tree node")
                    if TreeNode("another one of those tree node...")
                        Text("Some tree contents")
                        TreePop()
                    TreePop()
                CollapsingHeader("CollapsingHeader", safe_addr(open))
            if show_text_wrapped
                TextWrapped("This text should automatically wrap on the edge of the work rectangle.")
            if show_columns
                Text("Tables:")
                if BeginTable("table", 4, ImGuiTableFlags_Borders)
                    for n in range(4)
                        TableNextColumn()
                        Text("Width {GetContentRegionAvail().x}")
                    EndTable()
                Text("Columns:")
                Columns(4)
                for n in range(4)
                    Text("Width {GetColumnWidth()}")
                    NextColumn()
                Columns(1)
            if show_tab_bar && BeginTabBar("Hello")
                if BeginTabItem("OneOneOne")
                    EndTabItem()
                if BeginTabItem("TwoTwoTwo")
                    EndTabItem()
                if BeginTabItem("ThreeThreeThree")
                    EndTabItem()
                if BeginTabItem("FourFourFour")
                    EndTabItem()
                EndTabBar()
            if show_child
                BeginChild("child", ImVec2(0., 0.), true)
                EndChild()
            End()
        TreePop()

    if TreeNode("Clipping")
        static_let <|
            var size = ImVec2(100.0f, 100.0f)
            var offset = ImVec2(30.0f, 30.0f)
        DragFloat2("size", safe_addr(size.x), 0.5f, 1.0f, 200.0f, "%.0f")
        TextWrapped("(Click and drag to scroll)")
        for n in range(3)
            if n > 0
                SameLine()
            PushID(n)
            BeginGroup()
            InvisibleButton("##empty", size)
            if IsItemActive() && IsMouseDragging(int(ImGuiMouseButton_ ImGuiMouseButton_Left))
                offset.x += GetIO().MouseDelta.x
                offset.y += GetIO().MouseDelta.y
            var p0 = GetItemRectMin()
            var p1 = GetItemRectMax()
            let text_str = "Line 1 hello\nLine 2 clip me!";
            let text_pos = ImVec2(p0.x + offset.x, p0.y + offset.y)
            var draw_list = GetWindowDrawList()
            if n==0
                HelpMarker(
                    "Using PushClipRect():\n" +
                    "Will alter ImGui hit-testing logic + ImDrawList rendering.\n" +
                    "(use this if you want your clipping rectangle to affect interactions)")
                PushClipRect(p0, p1, true)
                *draw_list |> AddRectFilled(p0, p1, IM_COL32(90, 90, 120, 255))
                *draw_list |> AddText(text_pos, IM_COL32_WHITE, text_str)
                PopClipRect()
            elif n==1
                HelpMarker(
                    "Using ImDrawList::PushClipRect():\n" +
                    "Will alter ImDrawList rendering only.\n" +
                    "(use this as a shortcut if you are only using ImDrawList calls)")
                *draw_list |> PushClipRect(p0, p1, true)
                *draw_list |> AddRectFilled(p0, p1, IM_COL32(90, 90, 120, 255))
                *draw_list |> AddText(text_pos, IM_COL32_WHITE, text_str)
                *draw_list |> PopClipRect()
            elif n==2
                HelpMarker(
                    "Using ImDrawList::AddText() with a fine ClipRect:\n" +
                    "Will alter only this specific ImDrawList::AddText() rendering.\n" +
                    "(this is often used internally to avoid altering the clipping rectangle and minimize draw calls)")
                var clip_rect = ImVec4(p0.x, p0.y, p1.x, p1.y)
                *draw_list |> AddRectFilled(p0, p1, IM_COL32(90, 90, 120, 255))
                *draw_list |> AddText(GetFont(), GetFontSize(), text_pos, IM_COL32_WHITE, text_str, 0.0f, safe_addr(clip_rect))
            EndGroup()
            PopID()
        TreePop()


[export]
def main
	var f = 0.0
	imgui_app("Testing IMGUI") <|
        NewFrame()
        // ShowDemoWindow(null)
        DasShowDemoWindow(null)
        Render()

