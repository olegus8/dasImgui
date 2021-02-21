options indenting = 4
options remove_unused_symbols = false

module imgui_demo

require daslib/imgui_boost
require daslib/safe_addr
require daslib/static
require math
require strings

def DasHelpMarker(desc:string)
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

def DasShowExampleAppMainMenuBar()
    if BeginMainMenuBar()
        if BeginMenu("File")
            ShowExampleMenuFile()
            EndMenu()
        if BeginMenu("Edit")
            if MenuItem("Undo", "CTRL+Z")
                pass
            if MenuItem("Redo", "CTRL+Y", false, false)
                pass
            Separator()
            if MenuItem("Cut", "CTRL+X")
                pass
            if MenuItem("Copy", "CTRL+C")
                pass
            if MenuItem("Paste", "CTRL+V")
                pass
            EndMenu()
        EndMainMenuBar()

def DasShowAboutWindow(p_open: bool? implicit)
    if !Begin("About Dear ImGui", p_open, ImGuiWindowFlags AlwaysAutoResize)
        End()
        return
    Text("Dear ImGui {GetVersion()}")
    Separator()
    Text("By Omar Cornut and all Dear ImGui contributors.")
    Text("Dear ImGui is licensed under the MIT License, see LICENSE for more information.")
    static_let <|
        var show_config_info = false
    Checkbox("Config/Build Information", safe_addr(show_config_info))
    if show_config_info
        var io & = GetIO()
        var style & = GetStyle()
        let copy_to_clipboard = Button("Copy to clipboard")
        var child_size = ImVec2(0., GetTextLineHeightWithSpacing() * 18.)
        BeginChildFrame(GetID("cfg_infos"), child_size, ImGuiWindowFlags NoMove)
        if copy_to_clipboard
            LogToClipboard()
            LogText("```\n")
        Text("Dear ImGui {IMGUI_VERSION} ({IMGUI_VERSION_NUM})")
        Separator()
        // Text("sizeof(ImDrawIdx): {typeinfo(sizeof type<ImDrawIdx>)}, sizeof(ImDrawVert): {typeinfo(sizeof type<ImDrawVert>)}")
        // Separator()
        Text("io.BackendPlatformName: {io.BackendPlatformName}")
        Text("io.BackendRendererName: {io.BackendRendererName}")
        Text("io.ConfigFlags: {io.ConfigFlags}")
        var icf : ImGuiConfigFlags
        unsafe
            icf = reinterpret<ImGuiConfigFlags> io.ConfigFlags
        if icf && ImGuiConfigFlags NavEnableKeyboard
            Text(" NavEnableKeyboard")
        if icf && ImGuiConfigFlags NavEnableGamepad
            Text(" NavEnableGamepad")
        if icf && ImGuiConfigFlags NavEnableSetMousePos
            Text(" NavEnableSetMousePos")
        if icf && ImGuiConfigFlags NavNoCaptureKeyboard
            Text(" NavNoCaptureKeyboard")
        if icf && ImGuiConfigFlags NoMouse
            Text(" NoMouse")
        if icf && ImGuiConfigFlags NoMouseCursorChange
            Text(" NoMouseCursorChange")
        if io.MouseDrawCursor
            Text("io.MouseDrawCursor")
        if io.ConfigMacOSXBehaviors
            Text("io.ConfigMacOSXBehaviors")
        if io.ConfigInputTextCursorBlink
            Text("io.ConfigInputTextCursorBlink")
        if io.ConfigWindowsResizeFromEdges
            Text("io.ConfigWindowsResizeFromEdges")
        if io.ConfigWindowsMoveFromTitleBarOnly
            Text("io.ConfigWindowsMoveFromTitleBarOnly")
        if io.ConfigMemoryCompactTimer >= 0.0f
            Text("io.ConfigMemoryCompactTimer = {io.ConfigMemoryCompactTimer}")
        Text("io.BackendFlags: {io.BackendFlags}")
        var ibf : ImGuiBackendFlags
        unsafe
            ibf = reinterpret<ImGuiBackendFlags> io.BackendFlags
        if ibf && ImGuiBackendFlags HasGamepad
            Text(" HasGamepad")
        if ibf && ImGuiBackendFlags HasMouseCursors
            Text(" HasMouseCursors")
        if ibf && ImGuiBackendFlags HasSetMousePos
            Text(" HasSetMousePos")
        if ibf && ImGuiBackendFlags RendererHasVtxOffset
            Text(" RendererHasVtxOffset")
        Separator()
        Text("io.Fonts: {io.Fonts.Fonts.length} fonts, Flags: {io.Fonts.Flags}, TexSize: {io.Fonts.TexWidth},{io.Fonts.TexHeight}")
        Text("io.DisplaySize: {io.DisplaySize.x},{io.DisplaySize.y}")
        Text("io.DisplayFramebufferScale: {io.DisplayFramebufferScale.x},{io.DisplayFramebufferScale.y}")
        Separator()
        Text("style.WindowPadding: {style.WindowPadding.x},{style.WindowPadding.y}")
        Text("style.WindowBorderSize: {style.WindowBorderSize}")
        Text("style.FramePadding: {style.FramePadding.x},{style.FramePadding.y}")
        Text("style.FrameRounding: {style.FrameRounding}")
        Text("style.FrameBorderSize: {style.FrameBorderSize}")
        Text("style.ItemSpacing: {style.ItemSpacing.x},{style.ItemSpacing.y}")
        Text("style.ItemInnerSpacing: {style.ItemInnerSpacing.x},{style.ItemInnerSpacing.y}")
        if (copy_to_clipboard)
            LogText("\n```\n")
            LogFinish()
        EndChildFrame()
    End()

[export]
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

    if show_app_main_menu_bar
        DasShowExampleAppMainMenuBar()
    if show_app_documents
        DasShowExampleAppDocuments(safe_addr(show_app_documents))
    if show_app_console
        DasShowExampleAppConsole(safe_addr(show_app_console))
    if show_app_log
        DasShowExampleAppLog(safe_addr(show_app_log))
    if show_app_layout
        DasShowExampleAppLayout(safe_addr(show_app_layout))
    if show_app_property_editor
        DasShowExampleAppPropertyEditor(safe_addr(show_app_property_editor))
    if show_app_long_text
        DasShowExampleAppLongText(safe_addr(show_app_long_text))
    if show_app_auto_resize
        DasShowExampleAppAutoResize(safe_addr(show_app_auto_resize))
    if show_app_constrained_resize
        DasShowExampleAppConstrainedResize(safe_addr(show_app_constrained_resize))
    if show_app_simple_overlay
        DasShowExampleAppSimpleOverlay(safe_addr(show_app_simple_overlay))
    if show_app_window_titles
        DasShowExampleAppWindowTitles(safe_addr(show_app_window_titles))
    if show_app_custom_rendering
        DasShowExampleAppCustomRendering(safe_addr(show_app_custom_rendering))

    static_let <|
        var show_app_metrics = false
        var show_app_style_editor = false
        var show_app_about = false

    if show_app_metrics
        ShowMetricsWindow(safe_addr(show_app_metrics))  // NOTE: this is in imgui.cpp ???

    if show_app_about
        DasShowAboutWindow(safe_addr(show_app_about))

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
        window_flags |= ImGuiWindowFlags NoNav
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
            MenuItem("Main menu bar", "", safe_addr(show_app_main_menu_bar))
            MenuItem("Console", "", safe_addr(show_app_console))
            MenuItem("Log", "", safe_addr(show_app_log))
            MenuItem("Simple layout", "", safe_addr(show_app_layout))
            MenuItem("Property editor", "", safe_addr(show_app_property_editor))
            MenuItem("Long text display", "", safe_addr(show_app_long_text))
            MenuItem("Auto-resizing window", "", safe_addr(show_app_auto_resize))
            MenuItem("Constrained-resizing window", "", safe_addr(show_app_constrained_resize))
            MenuItem("Simple overlay", "", safe_addr(show_app_simple_overlay))
            MenuItem("Manipulating window titles", "", safe_addr(show_app_window_titles))
            MenuItem("Custom rendering", "", safe_addr(show_app_custom_rendering))
            MenuItem("Documents", "", safe_addr(show_app_documents))
            EndMenu()
        if BeginMenu("Tools")
            MenuItem("Metrics/Debugger", "", safe_addr(show_app_metrics))
            MenuItem("Style Editor", "", safe_addr(show_app_style_editor))
            MenuItem("About Dear ImGui", "", safe_addr(show_app_about))
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
            unsafe
                CheckboxFlags("io.ConfigFlags: NavEnableKeyboard", addr(io.ConfigFlags), int(ImGuiConfigFlags NavEnableKeyboard))
            SameLine()
            DasHelpMarker("Enable keyboard controls.")
            unsafe
                CheckboxFlags("io.ConfigFlags: NavEnableGamepad", addr(io.ConfigFlags), int(ImGuiConfigFlags NavEnableGamepad))
            SameLine()
            DasHelpMarker("Enable gamepad controls. Require backend to set io.BackendFlags |= ImGuiBackendFlags HasGamepad.\n\nRead instructions in imgui.cpp for details.")
            unsafe
                CheckboxFlags("io.ConfigFlags: NavEnableSetMousePos", addr(io.ConfigFlags), int(ImGuiConfigFlags NavEnableSetMousePos))
            SameLine()
            DasHelpMarker("Instruct navigation to move the mouse cursor. See comment for ImGuiConfigFlagsNavEnableSetMousePos.")
            unsafe
                CheckboxFlags("io.ConfigFlags: NoMouse", addr(io.ConfigFlags), int(ImGuiConfigFlags NoMouse))
            if (io.ConfigFlags & int(ImGuiConfigFlags NoMouse)) != 0
                if (float(GetTime()) % 0.40f) < 0.20f
                    SameLine()
                    Text("<<PRESS SPACE TO DISABLE>>")
                if IsKeyPressed(GetKeyIndex(ImGuiKey Space))
                    io.ConfigFlags &= ~int(ImGuiConfigFlags NoMouse)
            unsafe
                CheckboxFlags("io.ConfigFlags: NoMouseCursorChange", addr(io.ConfigFlags), int(ImGuiConfigFlags NoMouseCursorChange))
            SameLine()
            DasHelpMarker("Instruct backend to not alter mouse cursor shape and visibility.")
            unsafe
                Checkbox("io.ConfigInputTextCursorBlink", addr(io.ConfigInputTextCursorBlink))
            SameLine()
            DasHelpMarker("Enable blinking cursor (optional as some users consider it to be distracting)")
            unsafe
                Checkbox("io.ConfigDragClickToInputText", addr(io.ConfigDragClickToInputText))
            SameLine()
            DasHelpMarker("Enable turning DragXXX widgets into text input with a simple mouse click-release (without moving).")
            unsafe
                Checkbox("io.ConfigWindowsResizeFromEdges", addr(io.ConfigWindowsResizeFromEdges))
            SameLine()
            DasHelpMarker("Enable resizing of windows from their edges and from the lower-left corner.\nThis requires (io.BackendFlags & ImGuiBackendFlags HasMouseCursors) because it needs mouse cursor feedback.")
            unsafe
                Checkbox("io.ConfigWindowsMoveFromTitleBarOnly", addr(io.ConfigWindowsMoveFromTitleBarOnly))
            unsafe
                Checkbox("io.MouseDrawCursor", addr(io.MouseDrawCursor))
            SameLine()
            DasHelpMarker("Instruct Dear ImGui to render a mouse cursor itself. Note that a mouse cursor rendered via your application GPU rendering path will feel more laggy than hardware cursor, but will be more in sync with your other visuals.\n\nSome desktop applications may use both kinds of cursors (e.g. enable software cursor only when resizing/dragging something).")
            Text("Also see Style->Rendering for rendering options.")
            TreePop()
            Separator()
        if TreeNode("Backend Flags")
            DasHelpMarker(
                "Those flags are set by the backends (imgui_impl_xxx files) to specify their capabilities.\n" +
                "Here we expose then as read-only fields to avoid breaking interactions with your backend.")
            // Make a local copy to avoid modifying actual backend flags.
            var backend_flags = io.BackendFlags
            CheckboxFlags("io.BackendFlags: HasGamepad", safe_addr(backend_flags), int(ImGuiBackendFlags HasGamepad))
            CheckboxFlags("io.BackendFlags: HasMouseCursors", safe_addr(backend_flags), int(ImGuiBackendFlags HasMouseCursors))
            CheckboxFlags("io.BackendFlags: HasSetMousePos", safe_addr(backend_flags), int(ImGuiBackendFlags HasSetMousePos))
            CheckboxFlags("io.BackendFlags: RendererHasVtxOffset", safe_addr(backend_flags), int(ImGuiBackendFlags RendererHasVtxOffset))
            TreePop()
            Separator()
        if TreeNode("Style")
            DasHelpMarker("The same contents can be accessed in 'Tools->Style Editor' or by calling the ShowStyleEditor() function.")
            ShowStyleEditor()
            TreePop()
            Separator()
        if TreeNode("Capture/Logging")
            DasHelpMarker(
                "The logging API redirects all text output so you can easily capture the content of " +
                "a window or a block. Tree nodes can be automatically expanded.\n" +
                "Try opening any of the contents below in this window and then click one of the \"Log To\" button.")
            LogButtons()
            DasHelpMarker("You can also call LogText() to output directly to the log without a visual output.")
            if Button("Copy \"Hello, world!\" to clipboard")
                LogToClipboard()
                LogText("Hello, world!")
                LogFinish()
            TreePop()

    if CollapsingHeader("Window options")
        if BeginTable("split", 3)
            TableNextColumn()
            Checkbox("No titlebar", safe_addr(no_titlebar))
            TableNextColumn()
            Checkbox("No scrollbar", safe_addr(no_scrollbar))
            TableNextColumn()
            Checkbox("No menu", safe_addr(no_menu))
            TableNextColumn()
            Checkbox("No move", safe_addr(no_move))
            TableNextColumn()
            Checkbox("No resize", safe_addr(no_resize))
            TableNextColumn()
            Checkbox("No collapse", safe_addr(no_collapse))
            TableNextColumn()
            Checkbox("No close", safe_addr(no_close))
            TableNextColumn()
            Checkbox("No nav", safe_addr(no_nav))
            TableNextColumn()
            Checkbox("No background", safe_addr(no_background))
            TableNextColumn()
            Checkbox("No bring to front", safe_addr(no_bring_to_front))
            EndTable()

    /*
    ShowDemoWindowWidgets()
    */
    DasShowDemoWindowLayout()
    DasShowDemoWindowPopups()
    /*
    ShowDemoWindowTables()
    */
    DasShowDemoWindowMisc()
    PopItemWidth()
    End()

def DasShowDemoWindowPopups()
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
                MenuItem(name, "", toggle)
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
                    MenuItem(name, "", toggle)
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
            var name <- ImGuiInputTextBuffer("Label1", 32)
        var buf = "Button: {name |> to_string}"
        Button(buf)
        if BeginPopupContextItem()
            Text("Edit name:")
            InputText("##edit", name)
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
            Combo("Combo", safe_addr(unused_i), [[auto "Delete"; "Delete harder"]])
            static_let <|
                var dont_ask_me_next_time = false
            PushStyleVar(ImGuiStyleVar FramePadding, ImVec2(0.0f, 0.0f))
            Checkbox("Don't ask me next time", safe_addr(dont_ask_me_next_time))
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
            Combo("Combo", safe_addr(item), [[auto "aaaa"; "bbbb"; "cccc"; "dddd"; "eeee"]])
            ColorEdit4("color", safe_addr(color[0]))
            if Button("Add another modal..")
                OpenPopup("Stacked 2")
            static_let <|
                var unused_open = true
            if BeginPopupModal("Stacked 2", safe_addr(unused_open))
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
        MenuItem("Enabled", "", enabled)
        BeginChild("child", ImVec2(0., 60.), true)
        for i in range(1)
            Text("Scrolling Text {i}")
        EndChild()
        static_let <|
            var f = 0.5f
            var n = 0
        SliderFloat("Value", safe_addr(f), 0.0f, 1.0f)
        InputFloat("Input", safe_addr(f), 0.1f)
        Combo("Combo", safe_addr(n), [[auto "Yes";"No";"Maybe"]])
        EndMenu()

    if BeginMenu("Colors")
        let sz = GetTextLineHeight()
        for col in each_enum(type<ImGuiCol>)
            if col == ImGuiCol COUNT
                continue
            let name = GetStyleColorName(col)
            let p = GetCursorScreenPos()
            *GetWindowDrawList() |> AddRectFilled(p, ImVec2(p.x + sz, p.y + sz), GetColorU32(col))
            Dummy(ImVec2(sz, sz))
            SameLine()
            MenuItem(name)
        EndMenu()

    if BeginMenu("Options")
        static_let <|
            var b = true
        Checkbox("SomeOption", safe_addr(b))
        EndMenu()

    if BeginMenu("Disabled", false)
        assert(false)
    if MenuItem("Checked", "", true)
        pass
    if MenuItem("Quit", "Alt+F4")
        pass

def DasShowDemoWindowMisc()
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
            for i in each_enum(type<ImGuiMouseButton>)
                if i!=ImGuiMouseButton COUNT && IsMouseClicked(i)
                    SameLine()
                    Text("{i}")
            Text("Mouse dblclick:")
            for i in each_enum(type<ImGuiMouseButton>)
                if i!=ImGuiMouseButton COUNT && IsMouseDoubleClicked(i)
                    SameLine()
                    Text("b{i}")
            Text("Mouse released:")
            for i in each_enum(type<ImGuiMouseButton>)
                if i!=ImGuiMouseButton COUNT && IsMouseReleased(i)
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
            Text("Chars queue:")
            for i in range(io.InputQueueCharacters.length)
                let c = int(io.InputQueueCharacters[i])
                SameLine()
                Text("'{(c > ' ' && c <= 255) ? to_char(c) : "?"}' (0x{uint(c)})")
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
                var buft <- ImGuiInputTextBuffer("hello", 32)
            Text("Use TAB/SHIFT+TAB to cycle through keyboard editable fields.")
            InputText("1", buft)
            InputText("2", buft)
            InputText("3", buft)
            PushAllowKeyboardFocus(false)
            InputText("4 (tab skip)", buft)
            PopAllowKeyboardFocus()
            InputText("5", buft)
            TreePop()

        if TreeNode("Focus from code")
            var focus_1 = Button("Focus on 1")
            SameLine()
            var focus_2 = Button("Focus on 2")
            SameLine()
            var focus_3 = Button("Focus on 3")
            var has_focus = 0
            static_let <|
                var buf <- ImGuiInputTextBuffer("click on a button to set focus", 128)
            if focus_1
                SetKeyboardFocusHere()
            InputText("1", buf)
            if IsItemActive()
                has_focus = 1
            if focus_2
                SetKeyboardFocusHere()
            InputText("2", buf)
            if IsItemActive()
                has_focus = 2
            PushAllowKeyboardFocus(false)
            if focus_3
                SetKeyboardFocusHere()
            InputText("3 (tab skip)", buf)
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
            for button in each_enum(type<ImGuiMouseButton>)
                if button!=ImGuiMouseButton COUNT
                    Text("IsMouseDragging({button}):")
                    Text("  w/ default threshold: {IsMouseDragging(button)},")
                    Text("  w/ zero threshold: {IsMouseDragging(button, 0.0f)},")
                    Text("  w/ large threshold: {IsMouseDragging(button, 20.0f)},")
            Button("Drag Me")
            if IsItemActive()
                *GetForegroundDrawList() |> AddLine(
                    io.MouseClickedPos[0],
                    io.MousePos,
                    GetColorU32(ImGuiCol Button),
                    4.0f)
            let value_raw = GetMouseDragDelta(ImGuiMouseButton Left, 0.0f)
            let value_with_lock_threshold = GetMouseDragDelta(ImGuiMouseButton Left)
            let mouse_delta = io.MouseDelta
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
            DasHelpMarker(
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

def DasShowDemoWindowLayout
    if !CollapsingHeader("Layout & Scrolling")
        return

    if TreeNode("Child windows")
        DasHelpMarker("Use child windows to begin into a self-contained independent scrolling/clipping regions within a host window.")
        static_let <|
            var disable_mouse_wheel = false
            var disable_menu = false
        Checkbox("Disable Mouse Wheel", safe_addr(disable_mouse_wheel))
        Checkbox("Disable Menu", safe_addr(disable_menu))
        if true
            var window_flags = ImGuiWindowFlags HorizontalScrollbar
            if disable_mouse_wheel
                window_flags |= ImGuiWindowFlags NoScrollWithMouse
            BeginChild("ChildL", ImVec2(GetWindowContentRegionWidth() * 0.5f, 260.), false, window_flags)
            for i in range(100)
                Text("{i}: scrollable region")
            EndChild()
        SameLine()
        if true
            var window_flags = ImGuiWindowFlags None
            if disable_mouse_wheel
                window_flags |= ImGuiWindowFlags NoScrollWithMouse
            if !disable_menu
                window_flags |= ImGuiWindowFlags MenuBar
            PushStyleVar(ImGuiStyleVar ChildRounding, 5.0f)
            BeginChild("ChildR", ImVec2(0., 260.), true, window_flags)
            if !disable_menu && BeginMenuBar()
                if BeginMenu("Menu")
                    ShowExampleMenuFile()
                    EndMenu()
                EndMenuBar()
            if BeginTable("split", 2, ImGuiTableFlags Resizable | ImGuiTableFlags NoSavedSettings)
                for i in range(100)
                    TableNextColumn()
                    Button("{i}", ImVec2(-FLT_MIN, 0.0f))
                EndTable()
            EndChild()
            PopStyleVar()
        Separator()
        if true
            static_let <|
                var offset_x = 0
            SetNextItemWidth(100.)
            DragInt("Offset X", safe_addr(offset_x), 1.0f, -1000, 1000)
            SetCursorPosX(GetCursorPosX() + float(offset_x))
            PushStyleColor(ImGuiCol ChildBg, IM_COL32(255, 0, 0, 100))
            BeginChild("Red", ImVec2(200., 100.), true, ImGuiWindowFlags None)
            for i in range(50)
                Text("Some test {i}")
            EndChild()
            let child_is_hovered = IsItemHovered()
            let child_rect_min = GetItemRectMin()
            let child_rect_max = GetItemRectMax()
            PopStyleColor()
            Text("Hovered: {child_is_hovered}")
            Text("Rect of child window is: ({child_rect_min.x},{child_rect_min.y}) ({child_rect_max.x}, {child_rect_max.y})")
        TreePop()

    if TreeNode("Widgets Width")
        static_let <|
            var f = 0.0f
            var show_indented_items = true
        Checkbox("Show indented items", safe_addr(show_indented_items))
        Text("SetNextItemWidth/PushItemWidth(100)")
        SameLine()
        DasHelpMarker("Fixed width.")
        PushItemWidth(100.)
        DragFloat("float##1b", safe_addr(f))
        if show_indented_items
            Indent()
            DragFloat("float (indented)##1b", safe_addr(f))
            Unindent()
        PopItemWidth()
        Text("SetNextItemWidth/PushItemWidth(-100)")
        SameLine()
        DasHelpMarker("Align to right edge minus 100")
        PushItemWidth(-100.)
        DragFloat("float##2a", safe_addr(f))
        if show_indented_items
            Indent()
            DragFloat("float (indented)##2b", safe_addr(f))
            Unindent()
        PopItemWidth()
        Text("SetNextItemWidth/PushItemWidth(GetContentRegionAvail().x * 0.5f)")
        SameLine()
        DasHelpMarker("Half of available width.\n(~ right-cursor_pos)\n(works within a column set)")
        PushItemWidth(GetContentRegionAvail().x * 0.5f)
        DragFloat("float##3a", safe_addr(f))
        if show_indented_items
            Indent()
            DragFloat("float (indented)##3b", safe_addr(f))
            Unindent()
        PopItemWidth()
        Text("SetNextItemWidth/PushItemWidth(-GetContentRegionAvail().x * 0.5f)")
        SameLine()
        DasHelpMarker("Align to right edge minus half")
        PushItemWidth(-GetContentRegionAvail().x * 0.5f)
        DragFloat("float##4a", safe_addr(f))
        if show_indented_items
            Indent()
            DragFloat("float (indented)##4b", safe_addr(f))
            Unindent()
        PopItemWidth()
        Text("SetNextItemWidth/PushItemWidth(-FLT_MIN)")
        SameLine()
        DasHelpMarker("Align to right edge")
        PushItemWidth(-FLT_MIN)
        DragFloat("##float5a", safe_addr(f))
        if show_indented_items
            Indent()
            DragFloat("float (indented)##5b", safe_addr(f))
            Unindent()
        PopItemWidth()
        TreePop()

    if TreeNode("Basic Horizontal Layout")
        TextWrapped("(Use SameLine() to keep adding items to the right of the preceding item)")
        Text("Two items: Hello")
        SameLine()
        TextColored(ImVec4(1.,1.,0.,1.), "Sailor")
        Text("More spacing: Hello")
        SameLine(0., 20.)
        TextColored(ImVec4(1.,1.,0.,1.), "Sailor")
        AlignTextToFramePadding()
        Text("Normal buttons")
        SameLine()
        Button("Banana")
        SameLine()
        Button("Apple")
        SameLine()
        Button("Corniflower")
        Text("Small buttons")
        SameLine()
        SmallButton("Like this one")
        SameLine()
        Text("can fit within a text block.")
        Text("Aligned")
        SameLine(150.)
        Text("x=150")
        SameLine(300.)
        Text("x=300")
        Text("Aligned")
        SameLine(150.)
        SmallButton("x=150")
        SameLine(300.)
        SmallButton("x=300")
        static_let <|
            var c1 = false
            var c2 = false
            var c3 = false
            var c4 = false
        Checkbox("My", safe_addr(c1))
        SameLine()
        Checkbox("Tailor", safe_addr(c2))
        SameLine()
        Checkbox("Is", safe_addr(c3))
        SameLine()
        Checkbox("Rich", safe_addr(c4))
        static_let <|
            var f0 = 1.0f
            var f1 = 2.0f
            var f2 = 3.0f
        PushItemWidth(80.)
        static_let <|
            let items = [[string[] "AAAA"; "BBBB"; "CCCC"; "DDDD" ]]
            var item = -1
        Combo("Combo", safe_addr(item), items)
        SameLine()
        SliderFloat("X", safe_addr(f0), 0.0f, 5.0f)
        SameLine()
        SliderFloat("Y", safe_addr(f1), 0.0f, 5.0f)
        SameLine()
        SliderFloat("Z", safe_addr(f2), 0.0f, 5.0f)
        PopItemWidth()
        PushItemWidth(80.)
        Text("Lists:")
        static_let <|
            var selection = [[int[] 0; 1; 2; 3]]
        for i in range(4)
            if (i > 0)
                SameLine()
            PushID(i)
            ListBox("", safe_addr(selection[i]), items)
            PopID()
        PopItemWidth()
        let button_sz = ImVec2(40., 40.)
        Button("A", button_sz)
        SameLine()
        Dummy(button_sz)
        SameLine()
        Button("B", button_sz)
        Text("Manually wrapping:")
        let style & = GetStyle()
        let buttons_count = 20
        let window_visible_x2 = GetWindowPos().x + GetWindowContentRegionMax().x
        for n in range(buttons_count)
            PushID(n)
            Button("Box", button_sz)
            let last_button_x2 = GetItemRectMax().x
            let next_button_x2 = last_button_x2 + style.ItemSpacing.x + button_sz.x
            if n + 1 < buttons_count && next_button_x2 < window_visible_x2
                SameLine()
            PopID()
        TreePop()

    if TreeNode("Groups")
        DasHelpMarker(
            "BeginGroup() basically locks the horizontal position for new line. " +
            "EndGroup() bundles the whole group so that you can use \"item\" functions such as " +
            "IsItemHovered()/IsItemActive() or SameLine() etc. on the whole group.")
        BeginGroup()
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
        if IsItemHovered()
            SetTooltip("First group hovered")
        var size = GetItemRectSize()
        static_let <|
            let values = [[float[] 0.5f; 0.20f; 0.80f; 0.60f; 0.25f ]]
        PlotHistogram("##values", values, 0, "", 0.0f, 1.0f, size)
        Button("ACTION", ImVec2((size.x - GetStyle().ItemSpacing.x) * 0.5f, size.y))
        SameLine()
        Button("REACTION", ImVec2((size.x - GetStyle().ItemSpacing.x) * 0.5f, size.y))
        EndGroup()
        SameLine()
        Button("LEVERAGE\nBUZZWORD", size)
        SameLine()
        if ListBoxHeader("List", size)
            Selectable("Selected", true)
            Selectable("Not Selected", false)
            ListBoxFooter()
        TreePop()

    if TreeNode("Text Baseline Alignment")
        BulletText("Text baseline:")
        SameLine()
        DasHelpMarker(
            "This is testing the vertical alignment that gets applied on text to keep it aligned with widgets. " +
            "Lines only composed of text or \"small\" widgets use less vertical space than lines with framed widgets.")
        Indent()
        Text("KO Blahblah")
        SameLine()
        Button("Some framed item")
        SameLine()
        DasHelpMarker("Baseline of button will look misaligned with text..")
        AlignTextToFramePadding()
        Text("OK Blahblah")
        SameLine()
        Button("Some framed item")
        SameLine()
        DasHelpMarker("We call AlignTextToFramePadding() to vertically align the text baseline by +FramePadding.y")
        Button("TEST##1")
        SameLine()
        Text("TEST")
        SameLine()
        SmallButton("TEST##2")
        AlignTextToFramePadding()
        Text("Text aligned to framed item")
        SameLine()
        Button("Item##1")
        SameLine()
        Text("Item")
        SameLine()
        SmallButton("Item##2")
        SameLine()
        Button("Item##3")
        Unindent()
        Spacing()
        BulletText("Multi-line text:")
        Indent()
        Text("One\nTwo\nThree")
        SameLine()
        Text("Hello\nWorld")
        SameLine()
        Text("Banana")
        Text("Banana")
        SameLine()
        Text("Hello\nWorld")
        SameLine()
        Text("One\nTwo\nThree")
        Button("HOP##1")
        SameLine()
        Text("Banana")
        SameLine()
        Text("Hello\nWorld")
        SameLine()
        Text("Banana")
        Button("HOP##2")
        SameLine()
        Text("Hello\nWorld")
        SameLine()
        Text("Banana")
        Unindent()
        Spacing()
        BulletText("Misc items:")
        Indent()
        Button("80x80", ImVec2(80., 80.))
        SameLine()
        Button("50x50", ImVec2(50., 50.))
        SameLine()
        Button("Button()")
        SameLine()
        SmallButton("SmallButton()")
        let spacing = GetStyle().ItemInnerSpacing.x;
        Button("Button##1")
        SameLine(0.0f, spacing)
        if TreeNode("Node##1")
            for i in range(6)
                BulletText("Item {i}..")
            TreePop()
        AlignTextToFramePadding()
        let node_open = TreeNode("Node##2")
        SameLine(0.0f, spacing)
        Button("Button##2")
        if node_open
            for i in range(6)
                BulletText("Item {i}..")
            TreePop()
        Button("Button##3")
        SameLine(0.0f, spacing)
        BulletText("Bullet text")
        AlignTextToFramePadding()
        BulletText("Node")
        SameLine(0.0f, spacing)
        Button("Button##4")
        Unindent()
        TreePop()

    if TreeNode("Scrolling")
        DasHelpMarker("Use SetScrollHereY() or SetScrollFromPosY() to scroll to a given vertical position.")
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
            let child_flags = enable_extra_decorations ? ImGuiWindowFlags MenuBar : ImGuiWindowFlags None
            var child_id : uint
            unsafe
                child_id = GetID(reinterpret<void?> i)
            let child_is_visible = BeginChild(child_id, ImVec2(child_w, 200.0f), true, child_flags)
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
        DasHelpMarker(
            "Use SetScrollHereX() or SetScrollFromPosX() to scroll to a given horizontal position.\n\n"+
            "Because the clipping rectangle of most window hides half worth of WindowPadding on the "+
            "left/right, using SetScrollFromPosX(+1) will usually result in clipped text whereas the "+
            "equivalent SetScrollFromPosY(+1) wouldn't.")
        PushID("##HorizontalScrolling")
        for i in range(5)
            let child_height = GetTextLineHeight() + style.ScrollbarSize + style.WindowPadding.y * 2.0f
            let child_flags = ImGuiWindowFlags HorizontalScrollbar | (enable_extra_decorations ? ImGuiWindowFlags AlwaysVerticalScrollbar : ImGuiWindowFlags None)
            var child_id : uint
            unsafe
                child_id = GetID(reinterpret<void?> i)
            let child_is_visible = BeginChild(child_id, ImVec2(-100., child_height), true, child_flags)
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
        DasHelpMarker(
            "Horizontal scrolling for a window is enabled via the ImGuiWindowFlags HorizontalScrollbar flag.\n\n"+
            "You may want to also explicitly specify content width by using SetNextWindowContentWidth() before Begin().")
        static_let <|
            var lines = 7
        SliderInt("Lines", safe_addr(lines), 1, 15)
        PushStyleVar(ImGuiStyleVar FrameRounding, 3.0f)
        PushStyleVar(ImGuiStyleVar FramePadding, ImVec2(2.0f, 1.0f))
        let scrolling_child_size = ImVec2(0., GetFrameHeightWithSpacing() * 7.0 + 30.0)
        BeginChild("scrolling", scrolling_child_size, true, ImGuiWindowFlags HorizontalScrollbar)
        for line in range(lines)
            let num_buttons = 10 + ((line & 1)!=0 ? line * 9 : line * 3)
            for n in range(num_buttons)
                if n > 0
                    SameLine()
                PushID(n + line * 1000)
                let num_buf = "{n}"
                let lab = ((n % 15)==0) ? "FizzBuzz" : ((n % 3)==0) ? "Fizz" : ((n % 5)==0) ? "Buzz" : num_buf
                let hue = float(n) * 0.05f
                PushStyleColor(ImGuiCol Button, ImVec4(HSV(hue, 0.6f, 0.6f)))
                PushStyleColor(ImGuiCol ButtonHovered,  ImVec4(HSV(hue, 0.7f, 0.7f)))
                PushStyleColor(ImGuiCol ButtonActive, ImVec4( HSV(hue, 0.8f, 0.8f)))
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
                show_h_scrollbar ? ImGuiWindowFlags HorizontalScrollbar : ImGuiWindowFlags None)
            PushStyleVar(ImGuiStyleVar ItemSpacing, ImVec2(2., 0.))
            PushStyleVar(ImGuiStyleVar FramePadding, ImVec2(2., 0.))
            DasHelpMarker("Test of different widgets react and impact the work rectangle growing when horizontal scrolling is enabled.\n\nUse 'Metrics->Tools->Show windows rectangles' to visualize rectangles.")
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
                if BeginTable("table", 4, ImGuiTableFlags Borders)
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
            if IsItemActive() && IsMouseDragging(ImGuiMouseButton Left)
                offset.x += GetIO().MouseDelta.x
                offset.y += GetIO().MouseDelta.y
            var p0 = GetItemRectMin()
            var p1 = GetItemRectMax()
            let text_str = "Line 1 hello\nLine 2 clip me!";
            let text_pos = ImVec2(p0.x + offset.x, p0.y + offset.y)
            var draw_list = GetWindowDrawList()
            if n==0
                DasHelpMarker(
                    "Using PushClipRect():\n" +
                    "Will alter ImGui hit-testing logic + ImDrawList rendering.\n" +
                    "(use this if you want your clipping rectangle to affect interactions)")
                PushClipRect(p0, p1, true)
                *draw_list |> AddRectFilled(p0, p1, IM_COL32(90, 90, 120, 255))
                *draw_list |> AddText(text_pos, IM_COL32_WHITE, text_str)
                PopClipRect()
            elif n==1
                DasHelpMarker(
                    "Using ImDrawList::PushClipRect():\n" +
                    "Will alter ImDrawList rendering only.\n" +
                    "(use this as a shortcut if you are only using ImDrawList calls)")
                *draw_list |> PushClipRect(p0, p1, true)
                *draw_list |> AddRectFilled(p0, p1, IM_COL32(90, 90, 120, 255))
                *draw_list |> AddText(text_pos, IM_COL32_WHITE, text_str)
                *draw_list |> PopClipRect()
            elif n==2
                DasHelpMarker(
                    "Using ImDrawList::AddText() with a fine ClipRect:\n" +
                    "Will alter only this specific ImDrawList::AddText() rendering.\n" +
                    "(this is often used internally to avoid altering the clipping rectangle and minimize draw calls)")
                var clip_rect = ImVec4(p0.x, p0.y, p1.x, p1.y)
                *draw_list |> AddRectFilled(p0, p1, IM_COL32(90, 90, 120, 255))
                *draw_list |> AddText(GetFont(), GetFontSize(), text_pos, IM_COL32_WHITE, text_str, 0.0f, safe_addr(clip_rect))
            EndGroup()
            PopID()
        TreePop()

class ExampleAppLog
    Buf:ImGuiTextBuffer? = new ImGuiTextBuffer
    Filter:ImGuiTextFilter? = new ImGuiTextFilter
    LineOffsets:array<int>
    AutoScroll:bool = true
    def ExampleAppLog()
        self->Clear()
    def finalize
        unsafe
            delete Buf
            delete Filter
    def Clear() : void
        *Buf |> clear()
        LineOffsets |> clear()
        LineOffsets |> push(0)
    def AddLog(txt:string) : void
        var old_size = *Buf |> size()
        *Buf |> append(txt)
        var new_size = *Buf |> size()
        while old_size < new_size
            if *Buf |> at(old_size) == '\n'
                LineOffsets |> push(old_size + 1)
            old_size ++
    def Draw(title:string; p_open:bool? implicit) : void
        if !Begin(title, p_open)
            End()
            return
        if BeginPopup("Options")
            Checkbox("Auto-scroll", safe_addr(AutoScroll))
            EndPopup()
        if Button("Options")
            OpenPopup("Options")
        SameLine()
        let clear = Button("Clear")
        SameLine()
        let copy = Button("Copy")
        SameLine()
        *Filter |> Draw("Filter", -100.0f)
        Separator()
        BeginChild("scrolling", ImVec2(0., 0.), false, ImGuiWindowFlags HorizontalScrollbar)
        if clear
            self->Clear()
        if copy
            LogToClipboard()
        PushStyleVar(ImGuiStyleVar ItemSpacing, ImVec2(0., 0.))
        if *Filter |> IsActive()
            var line_no = 0
            while line_no < length(LineOffsets)
                var line_start = LineOffsets[line_no]
                var line_end = (line_no + 1 < length(LineOffsets)) ? (LineOffsets[line_no + 1] - 1) : (*Buf |> size())
                var ltext = *Buf |> slice(line_start, line_end)
                if *Filter |> PassFilter(ltext)
                    TextUnformatted(ltext)
                line_no++
        else
            using() <| $ ( var clipper : ImGuiListClipper# )
                clipper |> Begin(length(LineOffsets))
                while clipper |> Step()
                    for line_no in range(clipper.DisplayStart,clipper.DisplayEnd)
                        var line_start = LineOffsets[line_no]
                        var line_end = (line_no + 1 < length(LineOffsets)) ? (LineOffsets[line_no + 1] - 1) : (*Buf |> size())
                        var ltext = *Buf |> slice(line_start, line_end)
                        TextUnformatted(ltext)
                clipper |> End()
        PopStyleVar()
        if AutoScroll && GetScrollY() >= GetScrollMaxY()
            SetScrollHereY(1.0f)
        EndChild()
        End()

def DasShowExampleAppLog(p_open:bool? implicit)
    static_let <|
        var log <- ExampleAppLog()
    SetNextWindowSize(ImVec2(500., 400.), ImGuiCond FirstUseEver)
    Begin("Example: Log", p_open)
    if SmallButton("[Debug] Add 5 entries")
        static_let <|
            var counter = 0
            let categories = [[string[] "info"; "warn"; "error"]]
            let words = [[string [] "Bumfuzzled"; "Cattywampus"; "Snickersnee"; "Abibliophobia"; "Absquatulate"; "Nincompoop"; "Pauciloquent" ]]
        for n in range(5)
            let category = categories[counter % length(categories)]
            let word = words[counter % length(words)]
            log->AddLog("[{GetFrameCount()}] [{category}] Hello, current time is {GetTime()}, here's a word: '{word}'\n")
            counter++;
    End()
    log->Draw("Example: Log", p_open)

def DasShowExampleAppLayout(var p_open:bool? implicit)
    SetNextWindowSize(ImVec2(500.0, 440.0), ImGuiCond FirstUseEver)
    if Begin("Example: Simple layout", p_open, ImGuiWindowFlags MenuBar)
        if BeginMenuBar()
            if BeginMenu("File")
                if MenuItem("Close")
                    *p_open = false
                EndMenu()
            EndMenuBar()
        static_let <|
            var selected = 0
        BeginChild("left pane", ImVec2(150., 0.), true)
        for i in range(100)
            if Selectable("MyObject {i}", selected == i)
                selected = i
        EndChild()
        SameLine()
        BeginGroup()
        BeginChild("item view", ImVec2(0., -GetFrameHeightWithSpacing())) // Leave room for 1 line below us
        Text("MyObject: {selected}")
        Separator()
        if BeginTabBar("##Tabs", ImGuiTabBarFlags None)
            if BeginTabItem("Description")
                TextWrapped("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ")
                EndTabItem()
            if BeginTabItem("Details")
                Text("ID: 0123456789")
                EndTabItem()
            EndTabBar()
        EndChild()
        if Button("Revert")
            pass
        SameLine()
        if Button("Save")
            pass
        EndGroup()
    End()

class ExampleAppConsole
    InputBuf:ImGuiInputTextBuffer <- ImGuiInputTextBuffer("",256)
    Items:array<string>
    Commands:array<string>
    History:array<string>
    HistoryPos:int = -1
    Filter:ImGuiTextFilter? = new ImGuiTextFilter
    AutoScroll:bool = true
    ScrollToBottom:bool = false
    def ExampleAppConsole()
        self->ClearLog()
        Commands |> push("HELP")
        Commands |> push("HISTORY")
        Commands |> push("CLEAR")
        Commands |> push("CLASSIFY")
        self->AddLog("Welcome to Dear ImGui!")
        unsafe
            var console  = addr(self)
            InputBuf.callback <- @ <| ( var it:ImGuiInputTextBuffer; var itc:ImGuiInputTextCallbackData ) : int
                (*console)->TextEditCallback(itc)
                return 0

    def finalize
        self->ClearLog()
        unsafe
            delete Filter
    def ClearLog()
        delete Items
    def AddLog(txt:string)
        Items |> push(txt)
    def Draw(title:string;var p_open:bool? implicit)
        SetNextWindowSize(ImVec2(520., 600.), ImGuiCond FirstUseEver)
        if !Begin(title, p_open)
            End()
            return
        if BeginPopupContextItem()
            if MenuItem("Close Console")
                *p_open = false
            EndPopup()
        TextWrapped(
            "This example implements a console with basic coloring, completion (TAB key) and history (Up/Down keys). A more elaborate "+
            "implementation may want to store entries along with extra data such as timestamp, emitter, etc.")
        TextWrapped("Enter 'HELP' for help.")
        if SmallButton("Add Debug Text")
            self->AddLog("{length(Items)} some text")
            self->AddLog("some more text")
            self->AddLog("display very important message here!")
        SameLine()
        if SmallButton("Add Debug Error")
            self->AddLog("[error] something went wrong")
        SameLine()
        if SmallButton("Clear")
            self->ClearLog()
        SameLine()
        let copy_to_clipboard = SmallButton("Copy")
        Separator()
        if BeginPopup("Options")
            Checkbox("Auto-scroll", safe_addr(AutoScroll))
            EndPopup()
        if Button("Options")
            OpenPopup("Options")
        SameLine()
        *Filter |> Draw("Filter (\"incl,-excl\") (\"error\")", 180.)
        Separator()
        let footer_height_to_reserve = GetStyle().ItemSpacing.y + GetFrameHeightWithSpacing()
        BeginChild("ScrollingRegion", ImVec2(0., -footer_height_to_reserve), false, ImGuiWindowFlags HorizontalScrollbar)
        if BeginPopupContextWindow()
            if Selectable("Clear")
                self->ClearLog()
            EndPopup()
        PushStyleVar(ImGuiStyleVar ItemSpacing, ImVec2(4., 1.))
        if copy_to_clipboard
            LogToClipboard()
        for item in Items
            if !(*Filter |> PassFilter(item))
                continue
            var color = ImVec4()
            var has_color = false
            if find(item, "[error]") != -1
                color = ImVec4(1.0f, 0.4f, 0.4f, 1.0f)
                has_color = true
            elif starts_with(item, "# ")
                color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f)
                has_color = true
            if has_color
                PushStyleColor(ImGuiCol Text, color)
            TextUnformatted(item)
            if has_color
                PopStyleColor()
        if copy_to_clipboard
            LogFinish()
        if ScrollToBottom || (AutoScroll && GetScrollY() >= GetScrollMaxY())
            SetScrollHereY(1.0f)
        ScrollToBottom = false
        PopStyleVar()
        EndChild()
        Separator()
        var reclaim_focus = false
        let input_text_flags = ImGuiInputTextFlags EnterReturnsTrue | ImGuiInputTextFlags CallbackCompletion | ImGuiInputTextFlags CallbackHistory
        if InputText("Input", InputBuf, input_text_flags)
            let s = rtrim(InputBuf |> to_string)
            if !empty(s)
                self->ExecCommand(s)
            InputBuf |> clear()
            reclaim_focus = true
        SetItemDefaultFocus()
        if reclaim_focus
            SetKeyboardFocusHere(-1)
        End()
    def ExecCommand(command_line:string)
        self->AddLog("# {command_line}\n")
        HistoryPos = -1
        let index = History |> find_index(command_line)
        if index != -1
            History |> erase(index)
        History |> push(command_line)
        if command_line=="CLEAR"
            self->ClearLog()
        elif command_line=="HELP"
            self->AddLog("Commands:\n")
            for cmd in Commands
                self->AddLog("- {cmd}\n")
        elif command_line=="HISTORY"
            let first = length(History) - 10
            for i in range(max(0,first),length(History))
                self->AddLog("{i}: {History[i]}\n")
        else
            self->AddLog("Unknown command: '{command_line}'\n")
        ScrollToBottom = true
    def TextEditCallback(var data:ImGuiInputTextCallbackData)
        if data.EventFlag==ImGuiInputTextFlags CallbackCompletion
            let word_end = data.CursorPos
            var word_start = word_end
            while word_start > 0
                var c : int
                unsafe
                    c = character_uat(data.Buf, word_start - 1)
                if c==' ' || c=='\t' || c==',' || c==';'
                    break
                word_start--
            let word = data.Buf |> slice(word_start,word_end)
            var match_len = word_end - word_start
            var candidates : array<string>
            for cmd in Commands
                if cmd |> starts_with(word)
                    candidates |> push(cmd)
            if candidates |> empty
                self->AddLog("No match for \"{word}\"!\n")
            elif length(candidates) == 1
                data |> DeleteChars(word_start, match_len)
                data |> InsertChars(data.CursorPos, candidates[0])
                data |> InsertChars(data.CursorPos, " ")
            else
                while true
                    var c = 0
                    var all_candidates_matches = true
                    var ucandidates <- [{for cn in candidates; to_upper(cn)}]
                    for cnn,i in ucandidates,range(100500)
                        var tc : int
                        unsafe
                            tc = cnn|>character_uat(match_len)
                        if i == 0
                            c = tc
                        elif c == 0 || c != tc
                            all_candidates_matches = false
                            break
                    if !all_candidates_matches
                        break
                    match_len++
                if match_len > 0
                    data |> DeleteChars(word_start, word_end - word_start)
                    data |> InsertChars(data.CursorPos, candidates[0] |> slice(0,match_len))
                self->AddLog("Possible matches:\n")
                for cn in candidates
                    self->AddLog("- {cn}\n")
        elif data.EventFlag==ImGuiInputTextFlags CallbackHistory
            let prev_history_pos = HistoryPos;
            if data.EventKey == ImGuiKey UpArrow
                if HistoryPos == -1
                    HistoryPos = length(History) - 1
                elif HistoryPos > 0
                    HistoryPos--
            elif data.EventKey == ImGuiKey DownArrow
                if HistoryPos != -1
                    if ++HistoryPos >= length(History)
                        HistoryPos = -1
            if prev_history_pos != HistoryPos
                let history_str = (HistoryPos >= 0) ? History[HistoryPos] : ""
                data |> DeleteChars(0, data.BufTextLen)
                data |> InsertChars(0, history_str)

def DasShowExampleAppConsole(var p_open:bool? implicit)
    static_let <|
        var console <- ExampleAppConsole()
    console->Draw("Example: Console", p_open)

struct MyDocument
    Name:string
    Open:bool
    OpenPrev:bool
    Dirty:bool = false
    WantClose:bool = false
    Color:ImVec4 = ImVec4()

def MyDocument(name:string; open:bool = true; color:ImVec4 = ImVec4(1.0f, 1.0f, 1.0f, 1.0f))
    var self : MyDocument
    self.Name = name
    self.Open = open
    self.OpenPrev = open
    self.Color = color
    return self

def DoOpen(var self:MyDocument)
    self.Open = true

def DoQueueClose(var self:MyDocument)
    self.WantClose = true

def DoForceClose(var self:MyDocument)
    self.Open = false
    self.Dirty = false

def DoSave(var self:MyDocument)
    self.Dirty = false

def DisplayContents(var doc:MyDocument)
    PushID(safe_addr(doc))
    Text("Document \"{doc.Name}\"")
    PushStyleColor(ImGuiCol Text, doc.Color)
    TextWrapped("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.")
    PopStyleColor()
    if Button("Modify", ImVec2(100., 0.))
        doc.Dirty = true
    SameLine()
    if Button("Save", ImVec2(100., 0.))
        doc |> DoSave()
    ColorEdit3("color", safe_addr(doc.Color.x))
    PopID()

def DisplayContextMenu(var doc:MyDocument)
    if !BeginPopupContextItem()
        return
    if MenuItem("Save {doc.Name}", "CTRL+S", false, doc.Open)
        doc |> DoSave()
    if MenuItem("Close", "CTRL+W", false, doc.Open)
        doc |> DoQueueClose()
    EndPopup()

struct ExampleAppDocuments
    Documents:array<MyDocument>

def ExampleAppDocuments()
    var self : ExampleAppDocuments
    self.Documents |> push(MyDocument("Lettuce",             true,  ImVec4(0.4f, 0.8f, 0.4f, 1.0f)))
    self.Documents |> push(MyDocument("Eggplant",            true,  ImVec4(0.8f, 0.5f, 1.0f, 1.0f)))
    self.Documents |> push(MyDocument("Carrot",              true,  ImVec4(1.0f, 0.8f, 0.5f, 1.0f)))
    self.Documents |> push(MyDocument("Tomato",              false, ImVec4(1.0f, 0.3f, 0.4f, 1.0f)))
    self.Documents |> push(MyDocument("A Rather Long Title", false))
    self.Documents |> push(MyDocument("Some Document",       false))
    return <- self

def NotifyOfDocumentsClosedElsewhere(var app:ExampleAppDocuments)
    for doc in app.Documents
        if !doc.Open && doc.OpenPrev
            SetTabItemClosed(doc.Name)
        doc.OpenPrev = doc.Open

def DasShowExampleAppDocuments(p_open:bool? implicit)
    static_let <|
        var app <- ExampleAppDocuments()
    static_let <|
        var opt_reorderable = true
        var opt_fitting_flags = ImGuiTabBarFlags FittingPolicyDefault_
    let window_contents_visible = Begin("Example: Documents", p_open, ImGuiWindowFlags MenuBar)
    if !window_contents_visible
        End()
        return
    if BeginMenuBar()
        if BeginMenu("File")
            var open_count = 0
            for doc in app.Documents
                open_count += doc.Open ? 1 : 0;
            if BeginMenu("Open", open_count < length(app.Documents))
                for doc in app.Documents
                    if !doc.Open
                        if MenuItem(doc.Name)
                            doc |> DoOpen()
                EndMenu()
            if MenuItem("Close All Documents", "", false, open_count > 0)
                for doc in app.Documents
                    doc |> DoQueueClose()
            if MenuItem("Exit", "Alt+F4")
                pass
            EndMenu()
        EndMenuBar()
    for doc,doc_n in app.Documents,range(100500)
        if doc_n > 0
            SameLine()
        PushID(safe_addr(doc))
        if Checkbox(doc.Name, safe_addr(doc.Open))
            if !doc.Open
                doc |> DoForceClose()
        PopID()
    Separator()
    let tab_bar_flags = (opt_fitting_flags) | (opt_reorderable ? ImGuiTabBarFlags Reorderable : ImGuiTabBarFlags None)
    if BeginTabBar("##tabs", tab_bar_flags)
        if opt_reorderable
            NotifyOfDocumentsClosedElsewhere(app)
        for doc in app.Documents
            if !doc.Open
                continue
            let tab_flags = (doc.Dirty ? ImGuiTabItemFlags UnsavedDocument : ImGuiTabItemFlags None)
            let visible = BeginTabItem(doc.Name, safe_addr(doc.Open), tab_flags)
            if !doc.Open && doc.Dirty
                doc.Open = true
                doc |> DoQueueClose()
            DisplayContextMenu(doc)
            if visible
                DisplayContents(doc)
                EndTabItem()
        EndTabBar()
    static_let <|
        var close_queue : array<MyDocument?>
    if close_queue |> empty()
        for doc in app.Documents
            if doc.WantClose
                doc.WantClose = false
                unsafe
                    close_queue |> push(addr(doc))
    if !(close_queue |> empty())
        var close_queue_unsaved_documents = 0
        for qq in close_queue
            if qq.Dirty
                close_queue_unsaved_documents++
        if close_queue_unsaved_documents == 0
            for qq in close_queue
                (*qq) |> DoForceClose()
            close_queue |> clear()
        else
            if !IsPopupOpen("Save?")
                OpenPopup("Save?")
            if BeginPopupModal("Save?", null, ImGuiWindowFlags AlwaysAutoResize)
                Text("Save change to the following items?")
                let item_height = GetTextLineHeightWithSpacing()
                if BeginChildFrame(GetID("frame"), ImVec2(-FLT_MIN, 6.25f * item_height))
                    for qq in close_queue
                        if qq.Dirty
                            Text("{qq.Name}")
                    EndChildFrame()
                var button_size = ImVec2(GetFontSize() * 7.0f, 0.0f)
                if Button("Yes", button_size)
                    for qq in close_queue
                        if qq.Dirty
                            (*qq) |> DoSave()
                        (*qq) |> DoForceClose()
                    close_queue |> clear()
                    CloseCurrentPopup()
                SameLine()
                if Button("No", button_size)
                    for qq in close_queue
                        (*qq) |> DoForceClose()
                    close_queue |> clear()
                    CloseCurrentPopup()
                SameLine()
                if Button("Cancel", button_size)
                    close_queue |> clear()
                    CloseCurrentPopup()
                EndPopup()
    End()

def ShowPlaceholderObject(prefix:string;uid:int)
    PushID(uid)
    TableNextRow()
    TableSetColumnIndex(0)
    AlignTextToFramePadding()
    let node_open = TreeNode("Object", "{prefix}_{uid}")
    TableSetColumnIndex(1)
    Text("my sailor is rich")
    if (node_open)
        static_let <|
            var placeholder_members = [[float[8] 0.0f; 0.0f; 1.0f; 3.1416f; 100.0f; 999.0f; 0.0f; 0.0f]]
        for i in range(8)
            PushID(i)
            if i < 2
                ShowPlaceholderObject("Child", 424242)
            else
                TableNextRow()
                TableSetColumnIndex(0)
                AlignTextToFramePadding()
                let flags = ImGuiTreeNodeFlags Leaf | ImGuiTreeNodeFlags NoTreePushOnOpen | ImGuiTreeNodeFlags Bullet
                TreeNodeEx("Field", flags, "Field_{i}")
                TableSetColumnIndex(1)
                SetNextItemWidth(-FLT_MIN)
                if i >= 5
                    InputFloat("##value", safe_addr(placeholder_members[i]), 1.0f)
                else
                    DragFloat("##value", safe_addr(placeholder_members[i]), 0.01f)
                NextColumn()
            PopID()
        TreePop()
    PopID()

def DasShowExampleAppPropertyEditor(p_open:bool? implicit)
    SetNextWindowSize(ImVec2(430., 450.), ImGuiCond FirstUseEver)
    if !Begin("Example: Property editor", p_open)
        End()
        return
    DasHelpMarker(
        "This example shows how you may implement a property editor using two columns.\n" +
        "All objects/fields data are dummies here.\n" +
        "Remember that in many simple cases, you can use SameLine(xxx) to position\n" +
        "your cursor horizontally instead of using the Columns() API.")
    PushStyleVar(ImGuiStyleVar FramePadding, ImVec2(2., 2.))
    if BeginTable("split", 2, ImGuiTableFlags BordersOuter | ImGuiTableFlags Resizable)
        for obj_i in range(4)
            ShowPlaceholderObject("Object", obj_i)
        EndTable()
    PopStyleVar()
    End()

def DasShowExampleAppLongText(p_open:bool? implicit)
    SetNextWindowSize(ImVec2(520., 600.), ImGuiCond FirstUseEver)
    if !Begin("Example: Long text display", p_open)
        End()
        return
    static_let <|
        var test_type = 0
        var log = new ImGuiTextBuffer
        var lines = 0
    Text("Printing unusually long amount of text.")
    Combo("Test type", safe_addr(test_type),
        [[auto "Single call to TextUnformatted()";
        "Multiple calls to Text(), clipped";
        "Multiple calls to Text(), not clipped (slow)"]])
    Text("Buffer contents: {lines} lines, {*log |> size} bytes")
    if Button("Clear")
        *log |> clear()
        lines = 0
    SameLine()
    if Button("Add 1000 lines")
        for i in range(1000)
            *log |> append("{lines+i} The quick brown fox jumps over the lazy dog\n")
        lines += 1000
    BeginChild("Log", ImVec2())
    if test_type==0
        TextUnformatted(*log |> c_str())
    elif test_type==1
        PushStyleVar(ImGuiStyleVar ItemSpacing, ImVec2(0., 0.))
        using() <| $ ( var clipper : ImGuiListClipper# )
            clipper |> Begin(lines)
            while clipper |> Step()
                for i in range(clipper.DisplayStart,clipper.DisplayEnd)
                    Text("{i} The quick brown fox jumps over the lazy dog")
            clipper |> End()
            PopStyleVar()
    elif test_type==2
        PushStyleVar(ImGuiStyleVar ItemSpacing, ImVec2(0., 0.))
        for i in range(lines)
            Text("{i} The quick brown fox jumps over the lazy dog")
        PopStyleVar()
    EndChild()
    End()

def DasShowExampleAppAutoResize(p_open:bool? implicit)
    if !Begin("Example: Auto-resizing window", p_open, ImGuiWindowFlags AlwaysAutoResize)
        End()
        return
    static_let <|
        var lines = 10
    TextUnformatted(
        "Window will resize every-frame to the size of its content.\n" +
        "Note that you probably don't want to query the window size to\n" +
        "output your content because that would create a feedback loop.")
    SliderInt("Number of lines", safe_addr(lines), 1, 20)
    for i in range(lines)
        Text("This is line {i}")
    End()

def DasShowExampleAppConstrainedResize(p_open:bool? implicit)
    static_let <|
        let test_desc =[[auto
            "Resize vertical only";
            "Resize horizontal only";
            "Width > 100, Height > 100";
            "Width 400-500";
            "Height 400-500";
            "Custom: Always Square";
            "Custom: Fixed Steps (100)"
        ]]
        var auto_resize = false
        var con_type = 0
        var display_lines = 10
        var ccs_square <- ImGuiSizeConstraints() <| @(var data:ImGuiSizeCallbackData)
            let t = max(data.DesiredSize.x, data.DesiredSize.y)
            data.DesiredSize.x = t
            data.DesiredSize.y = t
        var ccs_step <- ImGuiSizeConstraints() <| @(var data:ImGuiSizeCallbackData)
            let step = 100.f
            data.DesiredSize = ImVec2(
                floor(data.DesiredSize.x / step + 0.5f) * step,
                floor(data.DesiredSize.y / step + 0.5f) * step
            )
    if con_type == 0
        SetNextWindowSizeConstraints(ImVec2(-1., 0.),    ImVec2(-1., FLT_MAX))
    elif con_type == 1
        SetNextWindowSizeConstraints(ImVec2(0., -1.),    ImVec2(FLT_MAX, -1.))
    elif con_type == 2
        SetNextWindowSizeConstraints(ImVec2(100., 100.), ImVec2(FLT_MAX, FLT_MAX))
    elif con_type == 3
        SetNextWindowSizeConstraints(ImVec2(400., -1.),  ImVec2(500., -1.))
    elif con_type == 4
        SetNextWindowSizeConstraints(ImVec2(-1., 400.),  ImVec2(-1., 500.))
    elif con_type == 5
        SetNextWindowSizeConstraints(ImVec2(0., 0.),     ImVec2(FLT_MAX, FLT_MAX), ccs_square)
    elif con_type == 6
        SetNextWindowSizeConstraints(ImVec2(0., 0.),     ImVec2(FLT_MAX, FLT_MAX), ccs_step)
    let flags = auto_resize ? ImGuiWindowFlags AlwaysAutoResize : ImGuiWindowFlags None
    if Begin("Example: Constrained Resize", p_open, flags)
        if Button("200x200")
            SetWindowSize(ImVec2(200., 200.))
        SameLine()
        if Button("500x500")
            SetWindowSize(ImVec2(500., 500.))
        SameLine()
        if Button("800x200")
            SetWindowSize(ImVec2(800., 200.))
        SetNextItemWidth(200.)
        Combo("Constraint", safe_addr(con_type), test_desc)
        SetNextItemWidth(200.)
        DragInt("Lines", safe_addr(display_lines), 0.2f, 1, 100)
        Checkbox("Auto-resize", safe_addr(auto_resize))
        for i in range(display_lines)
            Text("{i} Hello, sailor! Making this line long enough for the example.")
    End()

def DasShowExampleAppSimpleOverlay(var p_open:bool? implicit)
    let PAD = 10.0f
    static_let <|
        var corner = 0
    var io & = GetIO()
    var window_flags = ImGuiWindowFlags NoDecoration | ImGuiWindowFlags AlwaysAutoResize | ImGuiWindowFlags NoSavedSettings | ImGuiWindowFlags NoFocusOnAppearing | ImGuiWindowFlags NoNav
    if corner != -1
        let viewport = GetMainViewport()
        var work_pos = viewport.WorkPos
        var work_size = viewport.WorkSize
        var window_pos = ImVec2()
        var window_pos_pivot = ImVec2()
        window_pos.x = (corner & 1)!=0 ? (work_pos.x + work_size.x - PAD) : (work_pos.x + PAD)
        window_pos.y = (corner & 2)!=0 ? (work_pos.y + work_size.y - PAD) : (work_pos.y + PAD)
        window_pos_pivot.x = (corner & 1)!=0 ? 1.0f : 0.0f
        window_pos_pivot.y = (corner & 2)!=0 ? 1.0f : 0.0f
        SetNextWindowPos(window_pos, ImGuiCond Always, window_pos_pivot)
        window_flags |= ImGuiWindowFlags NoMove
    SetNextWindowBgAlpha(0.35f)
    if Begin("Example: Simple overlay", p_open, window_flags)
        Text("Simple overlay\nin the corner of the screen.\n(right-click to change position)")
        Separator()
        if IsMousePosValid()
            Text("Mouse Position: ({io.MousePos.x},{io.MousePos.y})")
        else
            Text("Mouse Position: <invalid>")
        if BeginPopupContextWindow()
            if MenuItem("Custom",       "", corner == -1)
                corner = -1
            if MenuItem("Top-left",     "", corner == 0)
                corner = 0
            if MenuItem("Top-right",    "", corner == 1)
                corner = 1
            if MenuItem("Bottom-left",  "", corner == 2)
                corner = 2
            if MenuItem("Bottom-right", "", corner == 3)
                corner = 3
            if p_open!=null && MenuItem("Close")
                *p_open = false
            EndPopup()
    End()

def DasShowExampleAppWindowTitles(p_open:bool? implicit)
    let viewport = GetMainViewport()
    let base_pos = viewport.Pos
    SetNextWindowPos(ImVec2(base_pos.x + 100., base_pos.y + 100.), ImGuiCond FirstUseEver)
    Begin("Same title as another window##1")
    Text("This is window 1.\nMy title is the same as window 2, but my identifier is unique.")
    End()
    SetNextWindowPos(ImVec2(base_pos.x + 100., base_pos.y + 200.), ImGuiCond FirstUseEver)
    Begin("Same title as another window##2")
    Text("This is window 2.\nMy title is the same as window 1, but my identifier is unique.")
    End()
    SetNextWindowPos(ImVec2(base_pos.x + 100., base_pos.y + 300.), ImGuiCond FirstUseEver)
    static_let <|
        let crot = [[int '|'; '/'; '-'; '\\']]
    let ch = crot[ int(GetTime() / 0.25lf) & 3 ]
    Begin("Animated title {to_char(ch)} {GetFrameCount()}###AnimatedTitle")
    Text("This window has a changing title.")
    End()

def DasShowExampleAppCustomRendering(p_open:bool? implicit)
    if !Begin("Example: Custom rendering", p_open)
        End()
        return

    if BeginTabBar("##TabBar")
        if BeginTabItem("Primitives")
            PushItemWidth(-GetFontSize() * 15.)
            var draw_list = GetWindowDrawList()
            Text("Gradients")
            var gradient_size = ImVec2(CalcItemWidth(), GetFrameHeight())
            if true
                let p0 = GetCursorScreenPos()
                let p1 = ImVec2(p0.x + gradient_size.x, p0.y + gradient_size.y)
                let col_a = GetColorU32(IM_COL32(0, 0, 0, 255))
                let col_b = GetColorU32(IM_COL32(255, 255, 255, 255))
                *draw_list |> AddRectFilledMultiColor(p0, p1, col_a, col_b, col_b, col_a)
                InvisibleButton("##gradient1", gradient_size)
            if true
                let p0 = GetCursorScreenPos()
                let p1 = ImVec2(p0.x + gradient_size.x, p0.y + gradient_size.y)
                let col_a = GetColorU32(IM_COL32(0, 255, 0, 255))
                let col_b = GetColorU32(IM_COL32(255, 0, 0, 255))
                *draw_list |> AddRectFilledMultiColor(p0, p1, col_a, col_b, col_b, col_a)
                InvisibleButton("##gradient2", gradient_size)

            Text("All primitives")
            static_let <|
                var sz = 36.0f
                var thickness = 3.0f
                var ngon_sides = 6
                var circle_segments_override = false
                var circle_segments_override_v = 12
                var curve_segments_override = false
                var curve_segments_override_v = 8
                var colf = ImVec4(1.0f, 1.0f, 0.4f, 1.0f)
            DragFloat("Size", safe_addr(sz), 0.2f, 2.0f, 100.0f, "%.0f")
            DragFloat("Thickness", safe_addr(thickness), 0.05f, 1.0f, 8.0f, "%.02f")
            SliderInt("N-gon sides", safe_addr(ngon_sides), 3, 12)
            Checkbox("##circlesegmentoverride", safe_addr(circle_segments_override))
            SameLine(0.0f, GetStyle().ItemInnerSpacing.x)
            circle_segments_override = SliderInt("Circle segments override", safe_addr(circle_segments_override_v), 3, 40) || circle_segments_override
            Checkbox("##curvessegmentoverride", safe_addr(curve_segments_override))
            SameLine(0.0f, GetStyle().ItemInnerSpacing.x)
            curve_segments_override = SliderInt("Curves segments override", safe_addr(curve_segments_override_v), 3, 40) || curve_segments_override
            ColorEdit4("Color", safe_addr(colf.x))

            let p = GetCursorScreenPos()
            let col = ColorConvertFloat4ToU32(colf)
            let spacing = 10.0f
            let corners_none = ImDrawCornerFlags None
            let corners_all = ImDrawCornerFlags All
            let corners_tl_br = ImDrawCornerFlags TopLeft | ImDrawCornerFlags BotRight
            let rounding = sz / 5.0f
            let circle_segments = circle_segments_override ? circle_segments_override_v : 0
            let curve_segments = curve_segments_override ? curve_segments_override_v : 0
            var x = p.x + 4.0f
            var y = p.y + 4.0f
            for n in range(2)
                let th = (n == 0) ? 1.0f : thickness
                *draw_list |> AddNgon(ImVec2(x + sz*0.5f, y + sz*0.5f), sz*0.5f, col, ngon_sides, th)
                x += sz + spacing
                *draw_list |> AddCircle(ImVec2(x + sz*0.5f, y + sz*0.5f), sz*0.5f, col, circle_segments, th)
                x += sz + spacing
                *draw_list |> AddRect(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 0.0f,  corners_none, th)
                x += sz + spacing
                *draw_list |> AddRect(ImVec2(x, y), ImVec2(x + sz, y + sz), col, rounding, corners_all, th)
                x += sz + spacing
                *draw_list |> AddRect(ImVec2(x, y), ImVec2(x + sz, y + sz), col, rounding, corners_tl_br, th)
                x += sz + spacing
                *draw_list |> AddTriangle(ImVec2(x+sz*0.5f,y), ImVec2(x+sz, y+sz-0.5f), ImVec2(x, y+sz-0.5f), col, th)
                x += sz + spacing
                *draw_list |> AddLine(ImVec2(x, y), ImVec2(x + sz, y), col, th)
                x += sz + spacing
                *draw_list |> AddLine(ImVec2(x, y), ImVec2(x, y + sz), col, th)
                x += spacing
                *draw_list |> AddLine(ImVec2(x, y), ImVec2(x + sz, y + sz), col, th)
                x += sz + spacing
                var cp3 = [[ImVec2[3] ImVec2(x, y + sz * 0.6f); ImVec2(x + sz * 0.5f, y - sz * 0.4f); ImVec2(x + sz, y + sz) ]]
                *draw_list |> AddBezierQuadratic(cp3[0], cp3[1], cp3[2], col, th, curve_segments)
                x += sz + spacing;
                var cp4 = [[ImVec2[4] ImVec2(x, y); ImVec2(x + sz * 1.3f, y + sz * 0.3f); ImVec2(x + sz - sz * 1.3f, y + sz - sz * 0.3f); ImVec2(x + sz, y + sz) ]]
                *draw_list |> AddBezierCubic(cp4[0], cp4[1], cp4[2], cp4[3], col, th, curve_segments)
                x = p.x + 4.
                y += sz + spacing

            *draw_list |> AddNgonFilled(ImVec2(x + sz * 0.5f, y + sz * 0.5f), sz*0.5f, col, ngon_sides)
            x += sz + spacing
            *draw_list |> AddCircleFilled(ImVec2(x + sz*0.5f, y + sz*0.5f), sz*0.5f, col, circle_segments)
            x += sz + spacing
            *draw_list |> AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col)
            x += sz + spacing
            *draw_list |> AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 10.0f)
            x += sz + spacing
            *draw_list |> AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 10.0f, corners_tl_br)
            x += sz + spacing
            *draw_list |> AddTriangleFilled(ImVec2(x+sz*0.5f,y), ImVec2(x+sz, y+sz-0.5f), ImVec2(x, y+sz-0.5f), col)
            x += sz + spacing
            *draw_list |> AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + thickness), col)
            x += sz + spacing
            *draw_list |> AddRectFilled(ImVec2(x, y), ImVec2(x + thickness, y + sz), col)
            x += spacing * 2.0f
            *draw_list |> AddRectFilled(ImVec2(x, y), ImVec2(x + 1., y + 1.), col)
            x += sz
            *draw_list |> AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + sz, y + sz), IM_COL32(0, 0, 0, 255), IM_COL32(255, 0, 0, 255), IM_COL32(255, 255, 0, 255), IM_COL32(0, 255, 0, 255))

            Dummy(ImVec2((sz + spacing) * 10.2f, (sz + spacing) * 3.0f))
            PopItemWidth()
            EndTabItem()

        if (BeginTabItem("Canvas"))
            static_let <|
                var points:array<float2>
                var scrolling = ImVec2(0.0f, 0.0f)
                var opt_enable_grid = true
                var opt_enable_context_menu = true
                var adding_line = false;
            Checkbox("Enable grid", safe_addr(opt_enable_grid))
            Checkbox("Enable context menu", safe_addr(opt_enable_context_menu))
            Text("Mouse Left: drag to add lines,\nMouse Right: drag to scroll, click for context menu.")

            var canvas_p0 = GetCursorScreenPos()
            var canvas_sz = GetContentRegionAvail()
            if canvas_sz.x < 50.0f
                canvas_sz.x = 50.0f
            if canvas_sz.y < 50.0f
                canvas_sz.y = 50.0f
            var canvas_p1 = ImVec2(canvas_p0.x + canvas_sz.x, canvas_p0.y + canvas_sz.y)

            var io & = GetIO()
            var draw_list = GetWindowDrawList()
            *draw_list |> AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255))
            *draw_list |> AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255))

            InvisibleButton("canvas", canvas_sz, ImGuiButtonFlags MouseButtonLeft | ImGuiButtonFlags MouseButtonRight)
            let is_hovered = IsItemHovered()
            let is_active = IsItemActive()
            let origin = ImVec2(canvas_p0.x + scrolling.x, canvas_p0.y + scrolling.y)
            let mouse_pos_in_canvas = float2(io.MousePos.x - origin.x, io.MousePos.y - origin.y)

            if is_hovered && !adding_line && IsMouseClicked(ImGuiMouseButton Left)
                points |> push(mouse_pos_in_canvas)
                points |> push(mouse_pos_in_canvas)
                adding_line = true
            if adding_line
                points [ points |> length() - 1 ] = mouse_pos_in_canvas
                if !IsMouseDown(ImGuiMouseButton Left)
                    adding_line = false

            let mouse_threshold_for_pan = opt_enable_context_menu ? -1.0f : 0.0f
            if is_active && IsMouseDragging(ImGuiMouseButton Right, mouse_threshold_for_pan)
                scrolling.x += io.MouseDelta.x
                scrolling.y += io.MouseDelta.y

            let drag_delta = GetMouseDragDelta(ImGuiMouseButton Right)
            if opt_enable_context_menu && IsMouseReleased(ImGuiMouseButton Right) && drag_delta.x == 0.0f && drag_delta.y == 0.0f
                OpenPopupOnItemClick("context")
            if BeginPopup("context")
                if adding_line
                    points |> resize(points |> length() - 2)
                adding_line = false
                if MenuItem("Remove one", "", false, points |> length() > 0)
                    points |> resize(points |> length() - 2)
                if MenuItem("Remove all", "", false, points |> length() > 0)
                    points |> clear()
                EndPopup()

            *draw_list |> PushClipRect(canvas_p0, canvas_p1, true)
            if opt_enable_grid
                let GRID_STEP = 64.0f;
                var x = scrolling.x % GRID_STEP
                while x < canvas_sz.x
                    *draw_list |> AddLine(ImVec2(canvas_p0.x + x, canvas_p0.y), ImVec2(canvas_p0.x + x, canvas_p1.y), IM_COL32(200, 200, 200, 40))
                    x += GRID_STEP
                var y = scrolling.y % GRID_STEP
                while y < canvas_sz.y
                    *draw_list |> AddLine(ImVec2(canvas_p0.x, canvas_p0.y + y), ImVec2(canvas_p1.x, canvas_p0.y + y), IM_COL32(200, 200, 200, 40))
                    y += GRID_STEP
            var n = 0
            while n < points |> length()
                *draw_list |> AddLine(ImVec2(origin.x + points[n].x, origin.y + points[n].y), ImVec2(origin.x + points[n + 1].x, origin.y + points[n + 1].y), IM_COL32(255, 255, 0, 255), 2.0f)
                n += 2
            *draw_list |> PopClipRect()
            EndTabItem()

        if BeginTabItem("BG/FG draw lists")
            static_let <|
                var draw_bg = true
                var draw_fg = true
            Checkbox("Draw in Background draw list", safe_addr(draw_bg))
            SameLine()
            DasHelpMarker("The Background draw list will be rendered below every Dear ImGui windows.")
            Checkbox("Draw in Foreground draw list", safe_addr(draw_fg))
            SameLine()
            DasHelpMarker("The Foreground draw list will be rendered over every Dear ImGui windows.")
            let window_pos = GetWindowPos()
            let window_size = GetWindowSize()
            let window_center = ImVec2(window_pos.x + window_size.x * 0.5f, window_pos.y + window_size.y * 0.5f)
            if draw_bg
                *GetBackgroundDrawList() |> AddCircle(window_center, window_size.x * 0.6f, IM_COL32(255, 0, 0, 200), 0, 10. + 4.)
            if draw_fg
                *GetForegroundDrawList() |> AddCircle(window_center, window_size.y * 0.6f, IM_COL32(0, 255, 0, 200), 0, 10.)
            EndTabItem()
        EndTabBar()
    End()

