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
                CheckboxFlags("io.ConfigFlags: NavEnableKeyboard", addr(io.ConfigFlags), ImGuiConfigFlags NavEnableKeyboard)
            SameLine()
            DasHelpMarker("Enable keyboard controls.")
            unsafe
                CheckboxFlags("io.ConfigFlags: NavEnableGamepad", addr(io.ConfigFlags), ImGuiConfigFlags NavEnableGamepad)
            SameLine()
            DasHelpMarker("Enable gamepad controls. Require backend to set io.BackendFlags |= ImGuiBackendFlags HasGamepad.\n\nRead instructions in imgui.cpp for details.")
            unsafe
                CheckboxFlags("io.ConfigFlags: NavEnableSetMousePos", addr(io.ConfigFlags), ImGuiConfigFlags NavEnableSetMousePos)
            SameLine()
            DasHelpMarker("Instruct navigation to move the mouse cursor. See comment for ImGuiConfigFlagsNavEnableSetMousePos.")
            unsafe
                CheckboxFlags("io.ConfigFlags: NoMouse", addr(io.ConfigFlags), ImGuiConfigFlags NoMouse)
            if io.ConfigFlags && ImGuiConfigFlags NoMouse
                if (float(GetTime()) % 0.40f) < 0.20f
                    SameLine()
                    Text("<<PRESS SPACE TO DISABLE>>")
                if IsKeyPressed(GetKeyIndex(ImGuiKey Space))
                    io.ConfigFlags &= ~ImGuiConfigFlags NoMouse
            unsafe
                CheckboxFlags("io.ConfigFlags: NoMouseCursorChange", addr(io.ConfigFlags), ImGuiConfigFlags NoMouseCursorChange)
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
            CheckboxFlags("io.BackendFlags: HasGamepad", safe_addr(backend_flags), ImGuiBackendFlags HasGamepad)
            CheckboxFlags("io.BackendFlags: HasMouseCursors", safe_addr(backend_flags), ImGuiBackendFlags HasMouseCursors)
            CheckboxFlags("io.BackendFlags: HasSetMousePos", safe_addr(backend_flags), ImGuiBackendFlags HasSetMousePos)
            CheckboxFlags("io.BackendFlags: RendererHasVtxOffset", safe_addr(backend_flags), ImGuiBackendFlags RendererHasVtxOffset)
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
    DasShowDemoWindowTables()
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

enum MyItemColumnID
    ID
    Name
    Action
    Quantity
    Description

struct MyItem
    ID : int
    Name : string
    Quantity : int

var s_current_sort_specs : ImGuiTableSortSpecs?

def CompareWithSortSpecs(a,b:MyItem?) : int
    for n in range(s_current_sort_specs.SpecsCount)
        unsafe
            let sort_spec & = s_current_sort_specs.Specs[n]
            var delta = 0
            if sort_spec.ColumnUserID==uint(MyItemColumnID ID)
                delta = a.ID - b.ID
            elif sort_spec.ColumnUserID==uint(MyItemColumnID Name) || sort_spec.ColumnUserID==uint(MyItemColumnID Description)
                if a.Name<b.Name
                    delta = +1
                elif a.Name>b.Name
                    delta = -1
            elif sort_spec.ColumnUserID==uint(MyItemColumnID Quantity)
                delta = a.Quantity - b.Quantity
            if delta > 0
                return sort_spec |> SortDirection == ImGuiSortDirection Ascending ? +1 : -1
            elif delta < 0
                return sort_spec |> SortDirection == ImGuiSortDirection Ascending ? -1 : +1
    return a.ID - b.ID

def PushStyleCompact
    var style & = GetStyle()
    PushStyleVar(ImGuiStyleVar FramePadding, ImVec2(style.FramePadding.x, floor(style.FramePadding.y * 0.60f)))
    PushStyleVar(ImGuiStyleVar ItemSpacing, ImVec2(style.ItemSpacing.x, floor(style.ItemSpacing.y * 0.60f)))

def PopStyleCompact
    PopStyleVar(2)

struct EnumDesc
    Value:ImGuiTableFlags
    Name:string
    Tooltip:string

def EditTableSizingFlags(var p_flags:ImGuiTableFlags? implicit)
    static_let <|
        var policies = [[EnumDesc
            Value=ImGuiTableFlags None,                 Name="Default",
                Tooltip="Use default sizing policy:\n- ImGuiTableFlags_SizingFixedFit if ScrollX is on or if host window has ImGuiWindowFlags_AlwaysAutoResize.\n" +
                    "- ImGuiTableFlags_SizingStretchSame otherwise.";
            Value=ImGuiTableFlags SizingFixedFit,       Name="ImGuiTableFlags SizingFixedFit",
                Tooltip="Columns default to _WidthFixed (if resizable) or _WidthAuto (if not resizable), matching contents width.";
            Value=ImGuiTableFlags SizingFixedSame,      Name="ImGuiTableFlags SizingFixedSame",
                Tooltip="Columns are all the same width, matching the maximum contents width.\nImplicitly disable ImGuiTableFlags_Resizable and enable ImGuiTableFlags_NoKeepColumnsVisible.";
            Value=ImGuiTableFlags SizingStretchProp,    Name="ImGuiTableFlags_SizingStretchProp",
                Tooltip="Columns default to _WidthStretch with weights proportional to their widths.";
            Value=ImGuiTableFlags SizingStretchSame,    Name="ImGuiTableFlags_SizingStretchSame",
                Tooltip="Columns default to _WidthStretch with same weights."
        ]]
    var idx = 0
    for pol in policies
        if pol.Value == (*p_flags & ImGuiTableFlags SizingMask_)
            break
        idx ++
    var preview_text = ""
    if idx < length(policies)
        if idx==0
            preview_text = policies[idx].Name
        else
            preview_text = policies[idx].Name |> slice(length("ImGuiTableFlags"))
    if BeginCombo("Sizing Policy", preview_text)
        for pol,n in policies,range(100500)
            if Selectable(pol.Name, idx == n)
                *p_flags = (*p_flags & ~ImGuiTableFlags SizingMask_) | pol.Value // TODO: add & and ~ to flags
        EndCombo()
    SameLine()
    TextDisabled("(?)")
    if IsItemHovered()
        BeginTooltip()
        PushTextWrapPos(GetFontSize() * 50.0f)
        for pol in policies
            Separator()
            Text("{pol.Name}:")
            Separator()
            SetCursorPosX(GetCursorPosX() + GetStyle().IndentSpacing * 0.5f)
            TextUnformatted(pol.Tooltip)
        PopTextWrapPos()
        EndTooltip()

def EditTableColumnsFlags(var p_flags:ImGuiTableColumnFlags? implicit)
    CheckboxFlags("_DefaultHide", p_flags, ImGuiTableColumnFlags DefaultHide)
    CheckboxFlags("_DefaultSort", p_flags, ImGuiTableColumnFlags DefaultSort)
    if CheckboxFlags("_WidthStretch", p_flags, ImGuiTableColumnFlags WidthStretch)
        *p_flags &= ~(ImGuiTableColumnFlags WidthMask_ ^ ImGuiTableColumnFlags WidthStretch)
    if CheckboxFlags("_WidthFixed", p_flags, ImGuiTableColumnFlags WidthFixed)
        *p_flags &= ~(ImGuiTableColumnFlags WidthMask_ ^ ImGuiTableColumnFlags WidthFixed)
    CheckboxFlags("_NoResize", p_flags, ImGuiTableColumnFlags NoResize)
    CheckboxFlags("_NoReorder", p_flags, ImGuiTableColumnFlags NoReorder)
    CheckboxFlags("_NoHide", p_flags, ImGuiTableColumnFlags NoHide)
    CheckboxFlags("_NoClip", p_flags, ImGuiTableColumnFlags NoClip)
    CheckboxFlags("_NoSort", p_flags, ImGuiTableColumnFlags NoSort)
    CheckboxFlags("_NoSortAscending", p_flags, ImGuiTableColumnFlags NoSortAscending)
    CheckboxFlags("_NoSortDescending", p_flags, ImGuiTableColumnFlags NoSortDescending)
    CheckboxFlags("_NoHeaderWidth", p_flags, ImGuiTableColumnFlags NoHeaderWidth)
    CheckboxFlags("_PreferSortAscending", p_flags, ImGuiTableColumnFlags PreferSortAscending)
    CheckboxFlags("_PreferSortDescending", p_flags, ImGuiTableColumnFlags PreferSortDescending)
    CheckboxFlags("_IndentEnable", p_flags, ImGuiTableColumnFlags IndentEnable)
    SameLine()
    DasHelpMarker("Default for column 0")
    CheckboxFlags("_IndentDisable", p_flags, ImGuiTableColumnFlags IndentDisable)
    SameLine()
    DasHelpMarker("Default for column >0")

def ShowTableColumnsStatusFlags(var flags:ImGuiTableColumnFlags)
    CheckboxFlags("_IsEnabled", safe_addr(flags), ImGuiTableColumnFlags IsEnabled)
    CheckboxFlags("_IsVisible", safe_addr(flags), ImGuiTableColumnFlags IsVisible)
    CheckboxFlags("_IsSorted", safe_addr(flags), ImGuiTableColumnFlags IsSorted)
    CheckboxFlags("_IsHovered", safe_addr(flags), ImGuiTableColumnFlags IsHovered)

enum ContentsType
    CT_ShowWidth
    CT_ShortText
    CT_LongText
    CT_Button
    CT_FillButton
    CT_InputText

def DasShowDemoWindowTables()
    if !CollapsingHeader("Tables & Columns")
        return
    let TEXT_BASE_WIDTH = CalcTextSize("A").x;
    let TEXT_BASE_HEIGHT = GetTextLineHeightWithSpacing()
    PushID("Tables")

    var open_action = -1
    if Button("Open all")
        open_action = 1
    SameLine()
    if Button("Close all")
        open_action = 0
    SameLine()

    static_let <|
        var disable_indent = false
    Checkbox("Disable tree indentation", safe_addr(disable_indent))
    SameLine()
    DasHelpMarker("Disable the indenting of tree nodes so demo tables can use the full window width.")
    Separator()
    if disable_indent
        PushStyleVar(ImGuiStyleVar IndentSpacing, 0.0f)

    if open_action != -1
        SetNextItemOpen(open_action != 0)
    if TreeNode("Basic")
        DasHelpMarker("Using TableNextRow() + calling TableSetColumnIndex() _before_ each cell, in a loop.")
        if BeginTable("table1", 3)
            for row in range(4)
                TableNextRow()
                for column in range(3)
                    TableSetColumnIndex(column)
                    Text("Row {row} Column {column}")
            EndTable()
        DasHelpMarker("Using TableNextRow() + calling TableNextColumn() _before_ each cell, manually.")
        if BeginTable("table2", 3)
            for row in range(4)
                TableNextRow()
                TableNextColumn()
                Text("Row {row}")
                TableNextColumn()
                Text("Some contents")
                TableNextColumn()
                Text("123.456")
            EndTable()
        DasHelpMarker(
            "Only using TableNextColumn(), which tends to be convenient for tables where every cells contains the same type of contents.\n" +
            "This is also more similar to the old NextColumn() function of the Columns API, and provided to facilitate the Columns->Tables API transition.")
        if BeginTable("table3", 3)
            for item in range(14)
                TableNextColumn()
                Text("Item {item}")
            EndTable()
        TreePop()

    if open_action != -1
        SetNextItemOpen(open_action != 0)
    if TreeNode("Borders, background")
        static_let <|
            var flags = ImGuiTableFlags Borders | ImGuiTableFlags RowBg
            var display_headers = false
            var contents_type = ContentsType CT_ShortText
        PushStyleCompact()
        CheckboxFlags("ImGuiTableFlags_RowBg", safe_addr(flags), ImGuiTableFlags RowBg)
        CheckboxFlags("ImGuiTableFlags_Borders", safe_addr(flags), ImGuiTableFlags Borders)
        SameLine()
        DasHelpMarker("ImGuiTableFlags Borders\n = ImGuiTableFlags BordersInnerV\n | ImGuiTableFlags BordersOuterV\n | ImGuiTableFlags BordersInnerV\n | ImGuiTableFlags BordersOuterH")
        Indent()
        CheckboxFlags("ImGuiTableFlags BordersH", safe_addr(flags), ImGuiTableFlags BordersH)
        Indent()
        CheckboxFlags("ImGuiTableFlags BordersOuterH", safe_addr(flags), ImGuiTableFlags BordersOuterH)
        CheckboxFlags("ImGuiTableFlags BordersInnerH", safe_addr(flags), ImGuiTableFlags BordersInnerH)
        Unindent()
        CheckboxFlags("ImGuiTableFlags BordersV", safe_addr(flags), ImGuiTableFlags BordersV)
        Indent()
        CheckboxFlags("ImGuiTableFlags BordersOuterV", safe_addr(flags), ImGuiTableFlags BordersOuterV)
        CheckboxFlags("ImGuiTableFlags BordersInnerV", safe_addr(flags), ImGuiTableFlags BordersInnerV)
        Unindent()
        CheckboxFlags("ImGuiTableFlags BordersOuter", safe_addr(flags), ImGuiTableFlags BordersOuter)
        CheckboxFlags("ImGuiTableFlags BordersInner", safe_addr(flags), ImGuiTableFlags BordersInner)
        Unindent()
        AlignTextToFramePadding()
        Text("Cell contents:")
        SameLine()
        RadioButton("Text", safe_addr(contents_type), ContentsType CT_ShortText)
        SameLine()
        RadioButton("FillButton", safe_addr(contents_type), ContentsType CT_FillButton)
        Checkbox("Display headers", safe_addr(display_headers))
        CheckboxFlags("ImGuiTableFlags_NoBordersInBody", safe_addr(flags), ImGuiTableFlags NoBordersInBody)
        SameLine()
        DasHelpMarker("Disable vertical borders in columns Body (borders will always appears in Headers")
        PopStyleCompact()
        if BeginTable("table1", 3, flags)
            if display_headers
                TableSetupColumn("One")
                TableSetupColumn("Two")
                TableSetupColumn("Three")
                TableHeadersRow()
            for row in range(5)
                TableNextRow()
                for column in range(3)
                    TableSetColumnIndex(column)
                    let buf = "Hello {column},{row}"
                    if contents_type == ContentsType CT_ShortText
                        TextUnformatted(buf)
                    elif contents_type == ContentsType CT_FillButton
                        Button(buf, ImVec2(-FLT_MIN, 0.0f))
            EndTable()
        TreePop()

    if open_action != -1
        SetNextItemOpen(open_action != 0)
    if TreeNode("Resizable, stretch")
        static_let <|
            var flags = ImGuiTableFlags SizingStretchSame | ImGuiTableFlags Resizable | ImGuiTableFlags BordersOuter | ImGuiTableFlags BordersV | ImGuiTableFlags ContextMenuInBody
        PushStyleCompact()
        CheckboxFlags("ImGuiTableFlags_Resizable", safe_addr(flags), ImGuiTableFlags Resizable)
        CheckboxFlags("ImGuiTableFlags_BordersV", safe_addr(flags), ImGuiTableFlags BordersV)
        SameLine()
        DasHelpMarker("Using the _Resizable flag automatically enables the _BordersInnerV flag as well, this is why the resize borders are still showing when unchecking this.")
        PopStyleCompact()
        if BeginTable("table1", 3, flags)
            for row in range(5)
                TableNextRow()
                for column in range(3)
                    TableSetColumnIndex(column)
                    Text("Hello {column},{row}")
            EndTable()
        TreePop()

    if open_action != -1
        SetNextItemOpen(open_action != 0)
    if TreeNode("Resizable, fixed")
        DasHelpMarker(
            "Using _Resizable + _SizingFixedFit flags.\n" +
            "Fixed-width columns generally makes more sense if you want to use horizontal scrolling.\n\n" +
            "Double-click a column border to auto-fit the column to its contents.")
        PushStyleCompact()
        static_let <|
            var flags = ImGuiTableFlags SizingFixedFit | ImGuiTableFlags Resizable | ImGuiTableFlags BordersOuter | ImGuiTableFlags BordersV | ImGuiTableFlags ContextMenuInBody
        CheckboxFlags("ImGuiTableFlags_NoHostExtendX", safe_addr(flags), ImGuiTableFlags NoHostExtendX)
        PopStyleCompact()
        if BeginTable("table1", 3, flags)
            for row in range(5)
                TableNextRow()
                for column in range(3)
                    TableSetColumnIndex(column)
                    Text("Hello {column},{row}")
            EndTable()
        TreePop()

    if open_action != -1
        SetNextItemOpen(open_action != 0)
    if TreeNode("Resizable, mixed")
        DasHelpMarker(
            "Using TableSetupColumn() to alter resizing policy on a per-column basis.\n\n" +
            "When combining Fixed and Stretch columns, generally you only want one, maybe two trailing columns to use _WidthStretch.")
        static_let <|
            var flags = ImGuiTableFlags SizingFixedFit | ImGuiTableFlags RowBg | ImGuiTableFlags Borders | ImGuiTableFlags Resizable | ImGuiTableFlags Reorderable | ImGuiTableFlags Hideable
        if BeginTable("table1", 3, flags)
            TableSetupColumn("AAA", ImGuiTableColumnFlags WidthFixed)
            TableSetupColumn("BBB", ImGuiTableColumnFlags WidthFixed)
            TableSetupColumn("CCC", ImGuiTableColumnFlags WidthStretch)
            TableHeadersRow()
            for row in range(5)
                TableNextRow()
                for column in range(3)
                    TableSetColumnIndex(column)
                    Text("{(column == 2) ? "Stretch" : "Fixed"} {column},{row}")
            EndTable()
        if BeginTable("table2", 6, flags)
            TableSetupColumn("AAA", ImGuiTableColumnFlags WidthFixed)
            TableSetupColumn("BBB", ImGuiTableColumnFlags WidthFixed)
            TableSetupColumn("CCC", ImGuiTableColumnFlags WidthFixed | ImGuiTableColumnFlags DefaultHide)
            TableSetupColumn("DDD", ImGuiTableColumnFlags WidthStretch)
            TableSetupColumn("EEE", ImGuiTableColumnFlags WidthStretch)
            TableSetupColumn("FFF", ImGuiTableColumnFlags WidthStretch | ImGuiTableColumnFlags DefaultHide)
            TableHeadersRow()
            for row in range(5)
                TableNextRow()
                for column in range(3)
                    TableSetColumnIndex(column)
                    Text("{(column == 2) ? "Stretch" : "Fixed"} {column},{row}")
            EndTable()
        TreePop()

    if open_action != -1
        SetNextItemOpen(open_action != 0)
    if TreeNode("Reorderable, hideable, with headers")
        DasHelpMarker(
            "Click and drag column headers to reorder columns.\n\n" +
            "Right-click on a header to open a context menu.")
        static_let <|
            var flags = ImGuiTableFlags Resizable | ImGuiTableFlags Reorderable | ImGuiTableFlags Hideable | ImGuiTableFlags BordersOuter | ImGuiTableFlags BordersV
        PushStyleCompact()
        CheckboxFlags("ImGuiTableFlags_Resizable", safe_addr(flags), ImGuiTableFlags Resizable)
        CheckboxFlags("ImGuiTableFlags_Reorderable", safe_addr(flags), ImGuiTableFlags Reorderable)
        CheckboxFlags("ImGuiTableFlags_Hideable", safe_addr(flags), ImGuiTableFlags Hideable)
        CheckboxFlags("ImGuiTableFlags_NoBordersInBody", safe_addr(flags), ImGuiTableFlags NoBordersInBody)
        CheckboxFlags("ImGuiTableFlags_NoBordersInBodyUntilResize", safe_addr(flags), ImGuiTableFlags NoBordersInBodyUntilResize)
        SameLine()
        DasHelpMarker("Disable vertical borders in columns Body until hovered for resize (borders will always appears in Headers)")
        PopStyleCompact()
        if BeginTable("table1", 3, flags)
            TableSetupColumn("One")
            TableSetupColumn("Two")
            TableSetupColumn("Three")
            TableHeadersRow()
            for row in range(6)
                TableNextRow()
                for column in range(3)
                    TableSetColumnIndex(column)
                    Text("Hello {column},{row}")
            EndTable()
        if BeginTable("table2", 3, flags | ImGuiTableFlags SizingFixedFit, ImVec2(0.0f, 0.0f))
            TableSetupColumn("One")
            TableSetupColumn("Two")
            TableSetupColumn("Three")
            TableHeadersRow()
            for row in range(6)
                TableNextRow()
                for column in range(3)
                    TableSetColumnIndex(column)
                    Text("Fixed {column},{row}")
            EndTable()
        TreePop()

    if open_action != -1
        SetNextItemOpen(open_action != 0)
    if TreeNode("Padding")
        DasHelpMarker(
            "We often want outer padding activated when any using features which makes the edges of a column visible:\n" +
            "e.g.:\n" +
            "- BorderOuterV\n" +
            "- any form of row selection\n" +
            "Because of this, activating BorderOuterV sets the default to PadOuterX. Using PadOuterX or NoPadOuterX you can override the default.\n\n" +
            "Actual padding values are using style.CellPadding.\n\n" +
            "In this demo we don't show horizontal borders to emphasis how they don't affect default horizontal padding.")
        static_let <|
            var flags1 = ImGuiTableFlags BordersV
        PushStyleCompact()
        CheckboxFlags("ImGuiTableFlags_PadOuterX", safe_addr(flags1), ImGuiTableFlags PadOuterX)
        SameLine()
        DasHelpMarker("Enable outer-most padding (default if ImGuiTableFlags_BordersOuterV is set)")
        CheckboxFlags("ImGuiTableFlags_NoPadOuterX", safe_addr(flags1), ImGuiTableFlags NoPadOuterX)
        SameLine()
        DasHelpMarker("Disable outer-most padding (default if ImGuiTableFlags_BordersOuterV is not set)")
        CheckboxFlags("ImGuiTableFlags_NoPadInnerX", safe_addr(flags1), ImGuiTableFlags NoPadInnerX)
        SameLine()
        DasHelpMarker("Disable inner padding between columns (double inner padding if BordersOuterV is on, single inner padding if BordersOuterV is off)")
        CheckboxFlags("ImGuiTableFlags_BordersOuterV", safe_addr(flags1), ImGuiTableFlags BordersOuterV)
        CheckboxFlags("ImGuiTableFlags_BordersInnerV", safe_addr(flags1), ImGuiTableFlags BordersInnerV)
        static_let <|
            var show_headers = false
        Checkbox("show_headers", safe_addr(show_headers))
        PopStyleCompact()
        if BeginTable("table_padding", 3, flags1)
            if show_headers
                TableSetupColumn("One")
                TableSetupColumn("Two")
                TableSetupColumn("Three")
                TableHeadersRow()
            for row in range(5)
                TableNextRow()
                for column in range(3)
                    TableSetColumnIndex(column)
                    if row == 0
                        Text("Avail {GetContentRegionAvail().x}")
                    else
                        Button("Hello {column},{row}", ImVec2(-FLT_MIN, 0.0f))
            EndTable()
        DasHelpMarker("Setting style.CellPadding to (0,0) or a custom value.")
        static_let <|
            var flags2 = ImGuiTableFlags Borders | ImGuiTableFlags RowBg
            var cell_padding =  ImVec2(0.0f, 0.0f)
            var show_widget_frame_bg = true
        PushStyleCompact()
        CheckboxFlags("ImGuiTableFlags_Borders", safe_addr(flags2), ImGuiTableFlags Borders)
        CheckboxFlags("ImGuiTableFlags_BordersH", safe_addr(flags2), ImGuiTableFlags BordersH)
        CheckboxFlags("ImGuiTableFlags_BordersV", safe_addr(flags2), ImGuiTableFlags BordersV)
        CheckboxFlags("ImGuiTableFlags_BordersInner", safe_addr(flags2), ImGuiTableFlags BordersInner)
        CheckboxFlags("ImGuiTableFlags_BordersOuter", safe_addr(flags2), ImGuiTableFlags BordersOuter)
        CheckboxFlags("ImGuiTableFlags_RowBg", safe_addr(flags2), ImGuiTableFlags RowBg)
        CheckboxFlags("ImGuiTableFlags_Resizable", safe_addr(flags2), ImGuiTableFlags Resizable)
        Checkbox("show_widget_frame_bg", safe_addr(show_widget_frame_bg))
        SliderFloat2("CellPadding", safe_addr(cell_padding.x), 0.0f, 10.0f, "%.0f")
        PopStyleCompact()
        PushStyleVar(ImGuiStyleVar CellPadding, cell_padding)
        if BeginTable("table_padding_2", 3, flags2)
            static_let <|
                var text_bufs : array<ImGuiInputTextBuffer?>
                var init = true
            if !show_widget_frame_bg
                PushStyleColor(ImGuiCol FrameBg, 0u)
            for cell in range(3*5)
                TableNextColumn()
                if init
                    text_bufs |> emplace(new ImGuiInputTextBuffer("edit me",16))
                SetNextItemWidth(-FLT_MIN)
                PushID(cell)
                InputText("##cell", *(text_bufs[cell]))
                PopID()
            if !show_widget_frame_bg
                PopStyleColor()
            init = false
            EndTable()
        PopStyleVar()
        TreePop()

    if open_action != -1
        SetNextItemOpen(open_action != 0)
    if TreeNode("Sizing policies")
        static_let <|
            var flags1 = ImGuiTableFlags BordersV | ImGuiTableFlags BordersOuterH | ImGuiTableFlags RowBg | ImGuiTableFlags ContextMenuInBody
        PushStyleCompact()
        CheckboxFlags("ImGuiTableFlags_Resizable", safe_addr(flags1), ImGuiTableFlags Resizable)
        CheckboxFlags("ImGuiTableFlags_NoHostExtendX", safe_addr(flags1), ImGuiTableFlags NoHostExtendX)
        PopStyleCompact()
        static_let <|
            var sizing_policy_flags = [[ImGuiTableFlags ImGuiTableFlags SizingFixedFit; ImGuiTableFlags SizingFixedSame; ImGuiTableFlags SizingStretchProp; ImGuiTableFlags SizingStretchSame]]
        for table_n in range(4)
            PushID(table_n)
            SetNextItemWidth(TEXT_BASE_WIDTH * 30.0)
            EditTableSizingFlags(safe_addr(sizing_policy_flags[table_n]))
            if BeginTable("table1", 3, sizing_policy_flags[table_n] | flags1)
                for row in range(3)
                    TableNextRow()
                    TableNextColumn()
                    Text("Oh dear")
                    TableNextColumn()
                    Text("Oh dear")
                    TableNextColumn()
                    Text("Oh dear")
                EndTable()
            if BeginTable("table2", 3, sizing_policy_flags[table_n] | flags1)
                for row in range(3)
                    TableNextRow()
                    TableNextColumn()
                    Text("AAAA")
                    TableNextColumn()
                    Text("BBBBBBBB")
                    TableNextColumn()
                    Text("CCCCCCCCCCCC")
                EndTable()
            PopID()
        Spacing()
        TextUnformatted("Advanced")
        SameLine()
        DasHelpMarker("This section allows you to interact and see the effect of various sizing policies depending on whether Scroll is enabled and the contents of your columns.")
        static_let <|
            var flags = ImGuiTableFlags ScrollY | ImGuiTableFlags Borders | ImGuiTableFlags RowBg | ImGuiTableFlags Resizable
            var contents_type = ContentsType CT_ShowWidth
            var column_count = 3
        PushStyleCompact()
        PushID("Advanced")
        PushItemWidth(TEXT_BASE_WIDTH * 30.0)
        EditTableSizingFlags(safe_addr(flags))
        unsafe
            Combo("Contents", reinterpret<int?>(addr(contents_type)), [[auto "Show width"; "Short Text"; "Long Text"; "Button"; "Fill Button"; "InputText"]])
        if contents_type == ContentsType CT_FillButton
            SameLine()
            DasHelpMarker("Be mindful that using right-alignment (e.g. size.x = -FLT_MIN) creates a feedback loop where contents width can feed into auto-column width can feed into contents width.")
        DragInt("Columns", safe_addr(column_count), 0.1f, 1, 64, "%d", ImGuiSliderFlags AlwaysClamp)
        CheckboxFlags("ImGuiTableFlagsResizable", safe_addr(flags), ImGuiTableFlags Resizable)
        CheckboxFlags("ImGuiTableFlags PreciseWidths", safe_addr(flags), ImGuiTableFlags PreciseWidths)
        SameLine()
        DasHelpMarker("Disable distributing remainder width to stretched columns (width allocation on a 100-wide table with 3 columns: Without this flag: 33,33,34. With this flag: 33,33,33)." +
            " With larger number of columns, resizing will appear to be less smooth.")
        CheckboxFlags("ImGuiTableFlags ScrollX", safe_addr(flags), ImGuiTableFlags ScrollX)
        CheckboxFlags("ImGuiTableFlags ScrollY", safe_addr(flags), ImGuiTableFlags ScrollY)
        CheckboxFlags("ImGuiTableFlags NoClip", safe_addr(flags), ImGuiTableFlags NoClip)
        PopItemWidth()
        PopID()
        PopStyleCompact()
        if BeginTable("table2", column_count, flags, ImVec2(0.0f, TEXT_BASE_HEIGHT * 7.))
            for cell in range(10 * column_count)
                TableNextColumn()
                let column = TableGetColumnIndex()
                let row = TableGetRowIndex()
                PushID(cell)
                let lab = "Hello {column},{row}"
                if contents_type==ContentsType CT_ShortText
                    TextUnformatted(lab)
                elif contents_type==ContentsType CT_LongText
                    Text("Some {column == 0 ? "long" : "longeeer"} text {column},{row}\nOver two lines..")
                elif contents_type==ContentsType CT_ShowWidth
                    Text("W: {GetContentRegionAvail().x}")
                elif contents_type==ContentsType CT_Button
                    Button(lab)
                elif contents_type==ContentsType CT_FillButton
                    Button(lab, ImVec2(-FLT_MIN, 0.0f))
                elif contents_type==ContentsType CT_InputText
                    SetNextItemWidth(-FLT_MIN)
                    static_let <|
                        var text_buf <- ImGuiInputTextBuffer("", 32)
                    InputText("##", text_buf)
                PopID()
            EndTable()
        TreePop()

    if open_action != -1
        SetNextItemOpen(open_action != 0)
    if TreeNode("Vertical scrolling, with clipping")
        DasHelpMarker("Here we activate ScrollY, which will create a child window container to allow hosting scrollable contents.\n" +
            "\nWe also demonstrate using ImGuiListClipper to virtualize the submission of many items.")
        static_let <|
            var flags = ( ImGuiTableFlags ScrollY | ImGuiTableFlags RowBg | ImGuiTableFlags BordersOuter |
            ImGuiTableFlags BordersV | ImGuiTableFlags Resizable | ImGuiTableFlags Reorderable | ImGuiTableFlags Hideable )
        PushStyleCompact()
        CheckboxFlags("ImGuiTableFlags_ScrollY", safe_addr(flags), ImGuiTableFlags ScrollY)
        PopStyleCompact()
        var outer_size = ImVec2(0.0f, TEXT_BASE_HEIGHT * 8.)
        if BeginTable("table_scrolly", 3, flags, outer_size)
            TableSetupScrollFreeze(0, 1)
            TableSetupColumn("One", ImGuiTableColumnFlags None)
            TableSetupColumn("Two", ImGuiTableColumnFlags None)
            TableSetupColumn("Three", ImGuiTableColumnFlags None)
            TableHeadersRow()
            using() <| $ ( var clipper : ImGuiListClipper# )
                clipper |> Begin(1000)
                while clipper |> Step()
                    for row in range(clipper.DisplayStart,clipper.DisplayEnd)
                        TableNextRow()
                        for column in range(3)
                            TableSetColumnIndex(column)
                            Text("Hello {column},{row}")
                clipper |> End()
            EndTable()
        TreePop()

    if open_action != -1
        SetNextItemOpen(open_action != 0)
    if TreeNode("Horizontal scrolling")
        DasHelpMarker(
            "When ScrollX is enabled, the default sizing policy becomes ImGuiTableFlags_SizingFixedFit, " +
            "as automatically stretching columns doesn't make much sense with horizontal scrolling.\n\n" +
            "Also note that as of the current version, you will almost always want to enable ScrollY along with ScrollX," +
            "because the container window won't automatically extend vertically to fix contents (this may be improved in future versions).")
        static_let  <|
            var flags = ( ImGuiTableFlags ScrollX | ImGuiTableFlags ScrollY | ImGuiTableFlags RowBg | ImGuiTableFlags BordersOuter |
                ImGuiTableFlags BordersV | ImGuiTableFlags Resizable | ImGuiTableFlags Reorderable | ImGuiTableFlags Hideable )
            var freeze_cols = 1
            var freeze_rows = 1
        PushStyleCompact()
        CheckboxFlags("ImGuiTableFlags Resizable", safe_addr(flags), ImGuiTableFlags Resizable)
        CheckboxFlags("ImGuiTableFlags ScrollX", safe_addr(flags), ImGuiTableFlags ScrollX)
        CheckboxFlags("ImGuiTableFlags ScrollY", safe_addr(flags), ImGuiTableFlags ScrollY)
        SetNextItemWidth(GetFrameHeight())
        DragInt("freeze_cols", safe_addr(freeze_cols), 0.2f, 0, 9, "", ImGuiSliderFlags NoInput)
        SetNextItemWidth(GetFrameHeight())
        DragInt("freeze_rows", safe_addr(freeze_rows), 0.2f, 0, 9, "", ImGuiSliderFlags NoInput)
        PopStyleCompact()
        var outer_size = ImVec2(0.0f, TEXT_BASE_HEIGHT * 8.)
        if BeginTable("table_scrollx", 7, flags, outer_size)
            TableSetupScrollFreeze(freeze_cols, freeze_rows)
            TableSetupColumn("Line #", ImGuiTableColumnFlags NoHide)
            TableSetupColumn("One")
            TableSetupColumn("Two")
            TableSetupColumn("Three")
            TableSetupColumn("Four")
            TableSetupColumn("Five")
            TableSetupColumn("Six")
            TableHeadersRow()
            for row in range(20)
                TableNextRow()
                for column in range(7)
                    if !TableSetColumnIndex(column) && column>0
                        continue
                    if column == 0
                        Text("Line {row}")
                    else
                        Text("Hello world {column},{row}")
            EndTable()
        Spacing()
        TextUnformatted("Stretch + ScrollX")
        SameLine()
        DasHelpMarker(
            "Showcase using Stretch columns + ScrollX together: " +
            "this is rather unusual and only makes sense when specifying an 'inner_width' for the table!\n" +
            "Without an explicit value, inner_width is == outer_size.x and therefore using Stretch columns + ScrollX together doesn't make sense.")
        static_let <|
            var flags2 = ( ImGuiTableFlags SizingStretchSame | ImGuiTableFlags ScrollX | ImGuiTableFlags ScrollY | ImGuiTableFlags BordersOuter
                | ImGuiTableFlags RowBg | ImGuiTableFlags ContextMenuInBody )
            var inner_width = 1000.0f
        PushStyleCompact()
        PushID("flags3")
        PushItemWidth(TEXT_BASE_WIDTH * 30.)
        CheckboxFlags("ImGuiTableFlags_ScrollX", safe_addr(flags2), ImGuiTableFlags ScrollX)
        DragFloat("inner_width", safe_addr(inner_width), 1.0f, 0.0f, FLT_MAX, "%.1f")
        PopItemWidth()
        PopID()
        PopStyleCompact()
        if BeginTable("table2", 7, flags2, outer_size, inner_width)
            for cell in range(20 * 7)
                TableNextColumn()
                Text("Hello world {TableGetColumnIndex()},{TableGetRowIndex()}")
            EndTable()
        TreePop()

    if open_action != -1
        SetNextItemOpen(open_action != 0)
    if TreeNode("Columns flags")
        let column_count = 3
        let column_names= [[string "One"; "Two"; "Three"]]
        static_let <|
            var column_flags = [[ImGuiTableColumnFlags ImGuiTableColumnFlags DefaultSort; ImGuiTableColumnFlags None; ImGuiTableColumnFlags DefaultHide]]
            var column_flags_out = [[ImGuiTableColumnFlags  ImGuiTableColumnFlags None; ImGuiTableColumnFlags None; ImGuiTableColumnFlags None]]
        if BeginTable("table_columns_flags_checkboxes", column_count, ImGuiTableFlags None)
            PushStyleCompact()
            for column in range(column_count)
                TableNextColumn()
                PushID(column)
                AlignTextToFramePadding()
                Text("'{column_names[column]}'")
                Spacing()
                Text("Input flags:")
                EditTableColumnsFlags(safe_addr(column_flags[column]))
                Spacing()
                Text("Output flags:")
                ShowTableColumnsStatusFlags(column_flags_out[column])
                PopID()
            PopStyleCompact()
            EndTable()
        let flags = (
              ImGuiTableFlags SizingFixedFit | ImGuiTableFlags ScrollX | ImGuiTableFlags ScrollY
            | ImGuiTableFlags RowBg | ImGuiTableFlags BordersOuter | ImGuiTableFlags BordersV
            | ImGuiTableFlags Resizable | ImGuiTableFlags Reorderable | ImGuiTableFlags Hideable | ImGuiTableFlags Sortable )
        var outer_size = ImVec2(0.0f, TEXT_BASE_HEIGHT * 9.)
        if BeginTable("table_columns_flags", column_count, flags, outer_size)
            for column in range(column_count)
                TableSetupColumn(column_names[column], column_flags[column])
            TableHeadersRow()
            for column in range(column_count)
                column_flags_out[column] = TableGetColumnFlags(column)
            let indent_step = floor(TEXT_BASE_WIDTH / 2.)
            for row in range(8)
                Indent(indent_step)
                TableNextRow()
                for column in range(column_count)
                    TableSetColumnIndex(column)
                    Text("{(column == 0) ? "Indented" : "Hello"} {TableGetColumnName(column)}")
            Unindent(indent_step * 8.0f)
            EndTable()
        TreePop()

/*

    if (open_action != -1)
        SetNextItemOpen(open_action != 0)
    if (TreeNode("Columns widths"))
    {
        HelpMarker("Using TableSetupColumn() to setup default width.")

        static ImGuiTableFlags flags1 = ImGuiTableFlags_Borders | ImGuiTableFlags_NoBordersInBodyUntilResize;
        PushStyleCompact()
        CheckboxFlags("ImGuiTableFlags_Resizable", &flags1, ImGuiTableFlags_Resizable)
        CheckboxFlags("ImGuiTableFlags_NoBordersInBodyUntilResize", &flags1, ImGuiTableFlags_NoBordersInBodyUntilResize)
        PopStyleCompact()
        if (BeginTable("table1", 3, flags1))
        {
            // We could also set ImGuiTableFlags_SizingFixedFit on the table and all columns will default to ImGuiTableColumnFlags_WidthFixed.
            TableSetupColumn("one", ImGuiTableColumnFlags_WidthFixed, 100.0f) // Default to 100.0f
            TableSetupColumn("two", ImGuiTableColumnFlags_WidthFixed, 200.0f) // Default to 200.0f
            TableSetupColumn("three", ImGuiTableColumnFlags_WidthFixed)       // Default to auto
            TableHeadersRow()
            for (int row = 0; row < 4; row++)
            {
                TableNextRow()
                for (int column = 0; column < 3; column++)
                {
                    TableSetColumnIndex(column)
                    if (row == 0)
                        Text("(w: %5.1f)", GetContentRegionAvail().x)
                    else
                        Text("Hello %d,%d", column, row)
                }
            }
            EndTable()
        }

        HelpMarker("Using TableSetupColumn() to setup explicit width.\n\nUnless _NoKeepColumnsVisible is set, fixed columns with set width may still be shrunk down if there's not enough space in the host.")

        static ImGuiTableFlags flags2 = ImGuiTableFlags_None;
        PushStyleCompact()
        CheckboxFlags("ImGuiTableFlags_NoKeepColumnsVisible", &flags2, ImGuiTableFlags_NoKeepColumnsVisible)
        CheckboxFlags("ImGuiTableFlags_BordersInnerV", &flags2, ImGuiTableFlags_BordersInnerV)
        CheckboxFlags("ImGuiTableFlags_BordersOuterV", &flags2, ImGuiTableFlags_BordersOuterV)
        PopStyleCompact()
        if (BeginTable("table2", 4, flags2))
        {
            // We could also set ImGuiTableFlags_SizingFixedFit on the table and all columns will default to ImGuiTableColumnFlags_WidthFixed.
            TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, 100.0f)
            TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, TEXT_BASE_WIDTH * 15.0f)
            TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, TEXT_BASE_WIDTH * 30.0f)
            TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, TEXT_BASE_WIDTH * 15.0f)
            for (int row = 0; row < 5; row++)
            {
                TableNextRow()
                for (int column = 0; column < 4; column++)
                {
                    TableSetColumnIndex(column)
                    if (row == 0)
                        Text("(w: %5.1f)", GetContentRegionAvail().x)
                    else
                        Text("Hello %d,%d", column, row)
                }
            }
            EndTable()
        }
        TreePop()
    }

    if (open_action != -1)
        SetNextItemOpen(open_action != 0)
    if (TreeNode("Nested tables"))
    {
        HelpMarker("This demonstrate embedding a table into another table cell.")

        if (BeginTable("table_nested1", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable))
        {
            TableSetupColumn("A0")
            TableSetupColumn("A1")
            TableHeadersRow()

            TableNextColumn()
            Text("A0 Row 0")
            {
                float rows_height = TEXT_BASE_HEIGHT * 2;
                if (BeginTable("table_nested2", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable))
                {
                    TableSetupColumn("B0")
                    TableSetupColumn("B1")
                    TableHeadersRow()

                    TableNextRow(ImGuiTableRowFlags_None, rows_height)
                    TableNextColumn()
                    Text("B0 Row 0")
                    TableNextColumn()
                    Text("B1 Row 0")
                    TableNextRow(ImGuiTableRowFlags_None, rows_height)
                    TableNextColumn()
                    Text("B0 Row 1")
                    TableNextColumn()
                    Text("B1 Row 1")

                    EndTable()
                }
            }
            TableNextColumn() Text("A1 Row 0")
            TableNextColumn() Text("A0 Row 1")
            TableNextColumn() Text("A1 Row 1")
            EndTable()
        }
        TreePop()
    }

    if (open_action != -1)
        SetNextItemOpen(open_action != 0)
    if (TreeNode("Row height"))
    {
        HelpMarker("You can pass a 'min_row_height' to TableNextRow().\n\nRows are padded with 'style.CellPadding.y' on top and bottom, so effectively the minimum row height will always be >= 'style.CellPadding.y * 2.0f'.\n\nWe cannot honor a _maximum_ row height as that would requires a unique clipping rectangle per row.")
        if (BeginTable("table_row_height", 1, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInnerV))
        {
            for (int row = 0; row < 10; row++)
            {
                float min_row_height = (float)(int)(TEXT_BASE_HEIGHT * 0.30f * row)
                TableNextRow(ImGuiTableRowFlags_None, min_row_height)
                TableNextColumn()
                Text("min_row_height = %.2f", min_row_height)
            }
            EndTable()
        }
        TreePop()
    }

    if (open_action != -1)
        SetNextItemOpen(open_action != 0)
    if (TreeNode("Outer size"))
    {
        // Showcasing use of ImGuiTableFlags_NoHostExtendX and ImGuiTableFlags_NoHostExtendY
        // Important to that note how the two flags have slightly different behaviors!
        Text("Using NoHostExtendX and NoHostExtendY:")
        PushStyleCompact()
        static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable | ImGuiTableFlags_ContextMenuInBody | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_NoHostExtendX;
        CheckboxFlags("ImGuiTableFlags_NoHostExtendX", &flags, ImGuiTableFlags_NoHostExtendX)
        SameLine() HelpMarker("Make outer width auto-fit to columns, overriding outer_size.x value.\n\nOnly available when ScrollX/ScrollY are disabled and Stretch columns are not used.")
        CheckboxFlags("ImGuiTableFlags_NoHostExtendY", &flags, ImGuiTableFlags_NoHostExtendY)
        SameLine() HelpMarker("Make outer height stop exactly at outer_size.y (prevent auto-extending table past the limit).\n\nOnly available when ScrollX/ScrollY are disabled. Data below the limit will be clipped and not visible.")
        PopStyleCompact()

        ImVec2 outer_size = ImVec2(0.0f, TEXT_BASE_HEIGHT * 5.5f)
        if (BeginTable("table1", 3, flags, outer_size))
        {
            for (int row = 0; row < 10; row++)
            {
                TableNextRow()
                for (int column = 0; column < 3; column++)
                {
                    TableNextColumn()
                    Text("Cell %d,%d", column, row)
                }
            }
            EndTable()
        }
        SameLine()
        Text("Hello!")

        Spacing()

        Text("Using explicit size:")
        if (BeginTable("table2", 3, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg, ImVec2(TEXT_BASE_WIDTH * 30, 0.0f)))
        {
            for (int row = 0; row < 5; row++)
            {
                TableNextRow()
                for (int column = 0; column < 3; column++)
                {
                    TableNextColumn()
                    Text("Cell %d,%d", column, row)
                }
            }
            EndTable()
        }
        SameLine()
        if (BeginTable("table3", 3, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg, ImVec2(TEXT_BASE_WIDTH * 30, 0.0f)))
        {
            for (int row = 0; row < 3; row++)
            {
                TableNextRow(0, TEXT_BASE_HEIGHT * 1.5f)
                for (int column = 0; column < 3; column++)
                {
                    TableNextColumn()
                    Text("Cell %d,%d", column, row)
                }
            }
            EndTable()
        }

        TreePop()
    }

    if (open_action != -1)
        SetNextItemOpen(open_action != 0)
    if (TreeNode("Background color"))
    {
        static ImGuiTableFlags flags = ImGuiTableFlags_RowBg;
        static int row_bg_type = 1;
        static int row_bg_target = 1;
        static int cell_bg_type = 1;

        PushStyleCompact()
        CheckboxFlags("ImGuiTableFlags_Borders", &flags, ImGuiTableFlags_Borders)
        CheckboxFlags("ImGuiTableFlags_RowBg", &flags, ImGuiTableFlags_RowBg)
        SameLine() HelpMarker("ImGuiTableFlags_RowBg automatically sets RowBg0 to alternative colors pulled from the Style.")
        Combo("row bg type", (int*)&row_bg_type, "None\0Red\0Gradient\0")
        Combo("row bg target", (int*)&row_bg_target, "RowBg0\0RowBg1\0") SameLine() HelpMarker("Target RowBg0 to override the alternating odd/even colors,\nTarget RowBg1 to blend with them.")
        Combo("cell bg type", (int*)&cell_bg_type, "None\0Blue\0") SameLine() HelpMarker("We are colorizing cells to B1->C2 here.")
        IM_ASSERT(row_bg_type >= 0 && row_bg_type <= 2)
        IM_ASSERT(row_bg_target >= 0 && row_bg_target <= 1)
        IM_ASSERT(cell_bg_type >= 0 && cell_bg_type <= 1)
        PopStyleCompact()

        if (BeginTable("table1", 5, flags))
        {
            for (int row = 0; row < 6; row++)
            {
                TableNextRow()

                // Demonstrate setting a row background color with 'TableSetBgColor(ImGuiTableBgTarget_RowBgX, ...)'
                // We use a transparent color so we can see the one behind in case our target is RowBg1 and RowBg0 was already targeted by the ImGuiTableFlags_RowBg flag.
                if (row_bg_type != 0)
                {
                    ImU32 row_bg_color = GetColorU32(row_bg_type == 1 ? ImVec4(0.7f, 0.3f, 0.3f, 0.65f) : ImVec4(0.2f + row * 0.1f, 0.2f, 0.2f, 0.65f)) // Flat or Gradient?
                    TableSetBgColor(ImGuiTableBgTarget_RowBg0 + row_bg_target, row_bg_color)
                }

                // Fill cells
                for (int column = 0; column < 5; column++)
                {
                    TableSetColumnIndex(column)
                    Text("%c%c", 'A' + row, '0' + column)

                    // Change background of Cells B1->C2
                    // Demonstrate setting a cell background color with 'TableSetBgColor(ImGuiTableBgTarget_CellBg, ...)'
                    // (the CellBg color will be blended over the RowBg and ColumnBg colors)
                    // We can also pass a column number as a third parameter to TableSetBgColor() and do this outside the column loop.
                    if (row >= 1 && row <= 2 && column >= 1 && column <= 2 && cell_bg_type == 1)
                    {
                        ImU32 cell_bg_color = GetColorU32(ImVec4(0.3f, 0.3f, 0.7f, 0.65f))
                        TableSetBgColor(ImGuiTableBgTarget_CellBg, cell_bg_color)
                    }
                }
            }
            EndTable()
        }
        TreePop()
    }

    if (open_action != -1)
        SetNextItemOpen(open_action != 0)
    if (TreeNode("Tree view"))
    {
        static ImGuiTableFlags flags = ImGuiTableFlags_BordersV | ImGuiTableFlags_BordersOuterH | ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_NoBordersInBody;

        if (BeginTable("3ways", 3, flags))
        {
            // The first column will use the default _WidthStretch when ScrollX is Off and _WidthFixed when ScrollX is On
            TableSetupColumn("Name", ImGuiTableColumnFlags_NoHide)
            TableSetupColumn("Size", ImGuiTableColumnFlags_WidthFixed, TEXT_BASE_WIDTH * 12.0f)
            TableSetupColumn("Type", ImGuiTableColumnFlags_WidthFixed, TEXT_BASE_WIDTH * 18.0f)
            TableHeadersRow()

            // Simple storage to output a dummy file-system.
            struct MyTreeNode
            {
                const char*     Name;
                const char*     Type;
                int             Size;
                int             ChildIdx;
                int             ChildCount;
                static void DisplayNode(const MyTreeNode* node, const MyTreeNode* all_nodes)
                {
                    TableNextRow()
                    TableNextColumn()
                    const bool is_folder = (node->ChildCount > 0)
                    if (is_folder)
                    {
                        bool open = TreeNodeEx(node->Name, ImGuiTreeNodeFlags_SpanFullWidth)
                        TableNextColumn()
                        TextDisabled("--")
                        TableNextColumn()
                        TextUnformatted(node->Type)
                        if (open)
                        {
                            for (int child_n = 0; child_n < node->ChildCount; child_n++)
                                DisplayNode(&all_nodes[node->ChildIdx + child_n], all_nodes)
                            TreePop()
                        }
                    }
                    else
                    {
                        TreeNodeEx(node->Name, ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_Bullet | ImGuiTreeNodeFlags_NoTreePushOnOpen | ImGuiTreeNodeFlags_SpanFullWidth)
                        TableNextColumn()
                        Text("%d", node->Size)
                        TableNextColumn()
                        TextUnformatted(node->Type)
                    }
                }
            };
            static const MyTreeNode nodes[] =
            {
                { "Root",                         "Folder",       -1,       1, 3    }, // 0
                { "Music",                        "Folder",       -1,       4, 2    }, // 1
                { "Textures",                     "Folder",       -1,       6, 3    }, // 2
                { "desktop.ini",                  "System file",  1024,    -1,-1    }, // 3
                { "File1_a.wav",                  "Audio file",   123000,  -1,-1    }, // 4
                { "File1_b.wav",                  "Audio file",   456000,  -1,-1    }, // 5
                { "Image001.png",                 "Image file",   203128,  -1,-1    }, // 6
                { "Copy of Image001.png",         "Image file",   203256,  -1,-1    }, // 7
                { "Copy of Image001 (Final2).png","Image file",   203512,  -1,-1    }, // 8
            };

            MyTreeNode::DisplayNode(&nodes[0], nodes)

            EndTable()
        }
        TreePop()
    }

    if (open_action != -1)
        SetNextItemOpen(open_action != 0)
    if (TreeNode("Item width"))
    {
        HelpMarker(
            "Showcase using PushItemWidth() and how it is preserved on a per-column basis.\n\n"
            "Note that on auto-resizing non-resizable fixed columns, querying the content width for e.g. right-alignment doesn't make sense.")
        if (BeginTable("table_item_width", 3, ImGuiTableFlags_Borders))
        {
            TableSetupColumn("small")
            TableSetupColumn("half")
            TableSetupColumn("right-align")
            TableHeadersRow()

            for (int row = 0; row < 3; row++)
            {
                TableNextRow()
                if (row == 0)
                {
                    // Setup ItemWidth once (instead of setting up every time, which is also possible but less efficient)
                    TableSetColumnIndex(0)
                    PushItemWidth(TEXT_BASE_WIDTH * 3.0f) // Small
                    TableSetColumnIndex(1)
                    PushItemWidth(-GetContentRegionAvail().x * 0.5f)
                    TableSetColumnIndex(2)
                    PushItemWidth(-FLT_MIN) // Right-aligned
                }

                // Draw our contents
                static float dummy_f = 0.0f;
                PushID(row)
                TableSetColumnIndex(0)
                SliderFloat("float0", &dummy_f, 0.0f, 1.0f)
                TableSetColumnIndex(1)
                SliderFloat("float1", &dummy_f, 0.0f, 1.0f)
                TableSetColumnIndex(2)
                SliderFloat("float2", &dummy_f, 0.0f, 1.0f)
                PopID()
            }
            EndTable()
        }
        TreePop()
    }

    // Demonstrate using TableHeader() calls instead of TableHeadersRow()
    if (open_action != -1)
        SetNextItemOpen(open_action != 0)
    if (TreeNode("Custom headers"))
    {
        const int COLUMNS_COUNT = 3;
        if (BeginTable("table_custom_headers", COLUMNS_COUNT, ImGuiTableFlags_Borders | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable))
        {
            TableSetupColumn("Apricot")
            TableSetupColumn("Banana")
            TableSetupColumn("Cherry")

            // Dummy entire-column selection storage
            // FIXME: It would be nice to actually demonstrate full-featured selection using those checkbox.
            static bool column_selected[3] = {};

            // Instead of calling TableHeadersRow() we'll submit custom headers ourselves
            TableNextRow(ImGuiTableRowFlags_Headers)
            for (int column = 0; column < COLUMNS_COUNT; column++)
            {
                TableSetColumnIndex(column)
                const char* column_name = TableGetColumnName(column) // Retrieve name passed to TableSetupColumn()
                PushID(column)
                PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0))
                Checkbox("##checkall", &column_selected[column])
                PopStyleVar()
                SameLine(0.0f, GetStyle().ItemInnerSpacing.x)
                TableHeader(column_name)
                PopID()
            }

            for (int row = 0; row < 5; row++)
            {
                TableNextRow()
                for (int column = 0; column < 3; column++)
                {
                    char buf[32];
                    sprintf(buf, "Cell %d,%d", column, row)
                    TableSetColumnIndex(column)
                    Selectable(buf, column_selected[column])
                }
            }
            EndTable()
        }
        TreePop()
    }

    // Demonstrate creating custom context menus inside columns, while playing it nice with context menus provided by TableHeadersRow()/TableHeader()
    if (open_action != -1)
        SetNextItemOpen(open_action != 0)
    if (TreeNode("Context menus"))
    {
        HelpMarker("By default, right-clicking over a TableHeadersRow()/TableHeader() line will open the default context-menu.\nUsing ImGuiTableFlags_ContextMenuInBody we also allow right-clicking over columns body.")
        static ImGuiTableFlags flags1 = ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable | ImGuiTableFlags_Borders | ImGuiTableFlags_ContextMenuInBody;

        PushStyleCompact()
        CheckboxFlags("ImGuiTableFlags_ContextMenuInBody", &flags1, ImGuiTableFlags_ContextMenuInBody)
        PopStyleCompact()

        // Context Menus: first example
        // [1.1] Right-click on the TableHeadersRow() line to open the default table context menu.
        // [1.2] Right-click in columns also open the default table context menu (if ImGuiTableFlags_ContextMenuInBody is set)
        const int COLUMNS_COUNT = 3;
        if (BeginTable("table_context_menu", COLUMNS_COUNT, flags1))
        {
            TableSetupColumn("One")
            TableSetupColumn("Two")
            TableSetupColumn("Three")

            // [1.1]] Right-click on the TableHeadersRow() line to open the default table context menu.
            TableHeadersRow()

            // Submit dummy contents
            for (int row = 0; row < 4; row++)
            {
                TableNextRow()
                for (int column = 0; column < COLUMNS_COUNT; column++)
                {
                    TableSetColumnIndex(column)
                    Text("Cell %d,%d", column, row)
                }
            }
            EndTable()
        }

        // Context Menus: second example
        // [2.1] Right-click on the TableHeadersRow() line to open the default table context menu.
        // [2.2] Right-click on the ".." to open a custom popup
        // [2.3] Right-click in columns to open another custom popup
        HelpMarker("Demonstrate mixing table context menu (over header), item context button (over button) and custom per-colum context menu (over column body).")
        ImGuiTableFlags flags2 = ImGuiTableFlags_Resizable | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable | ImGuiTableFlags_Borders;
        if (BeginTable("table_context_menu_2", COLUMNS_COUNT, flags2))
        {
            TableSetupColumn("One")
            TableSetupColumn("Two")
            TableSetupColumn("Three")

            // [2.1] Right-click on the TableHeadersRow() line to open the default table context menu.
            TableHeadersRow()
            for (int row = 0; row < 4; row++)
            {
                TableNextRow()
                for (int column = 0; column < COLUMNS_COUNT; column++)
                {
                    // Submit dummy contents
                    TableSetColumnIndex(column)
                    Text("Cell %d,%d", column, row)
                    SameLine()

                    // [2.2] Right-click on the ".." to open a custom popup
                    PushID(row * COLUMNS_COUNT + column)
                    SmallButton("..")
                    if (BeginPopupContextItem())
                    {
                        Text("This is the popup for Button(\"..\") in Cell %d,%d", column, row)
                        if (Button("Close"))
                            CloseCurrentPopup()
                        EndPopup()
                    }
                    PopID()
                }
            }

            // [2.3] Right-click anywhere in columns to open another custom popup
            // (instead of testing for !IsAnyItemHovered() we could also call OpenPopup() with ImGuiPopupFlags_NoOpenOverExistingPopup
            // to manage popup priority as the popups triggers, here "are we hovering a column" are overlapping)
            int hovered_column = -1;
            for (int column = 0; column < COLUMNS_COUNT + 1; column++)
            {
                PushID(column)
                if (TableGetColumnFlags(column) & ImGuiTableColumnFlags_IsHovered)
                    hovered_column = column;
                if (hovered_column == column && !IsAnyItemHovered() && IsMouseReleased(1))
                    OpenPopup("MyPopup")
                if (BeginPopup("MyPopup"))
                {
                    if (column == COLUMNS_COUNT)
                        Text("This is a custom popup for unused space after the last column.")
                    else
                        Text("This is a custom popup for Column %d", column)
                    if (Button("Close"))
                        CloseCurrentPopup()
                    EndPopup()
                }
                PopID()
            }

            EndTable()
            Text("Hovered column: %d", hovered_column)
        }
        TreePop()
    }

    // Demonstrate creating multiple tables with the same ID
    if (open_action != -1)
        SetNextItemOpen(open_action != 0)
    if (TreeNode("Synced instances"))
    {
        HelpMarker("Multiple tables with the same identifier will share their settings, width, visibility, order etc.")
        for (int n = 0; n < 3; n++)
        {
            char buf[32];
            sprintf(buf, "Synced Table %d", n)
            bool open = CollapsingHeader(buf, ImGuiTreeNodeFlags_DefaultOpen)
            if (open && BeginTable("Table", 3, ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable | ImGuiTableFlags_Borders | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_NoSavedSettings))
            {
                TableSetupColumn("One")
                TableSetupColumn("Two")
                TableSetupColumn("Three")
                TableHeadersRow()
                for (int cell = 0; cell < 9; cell++)
                {
                    TableNextColumn()
                    Text("this cell %d", cell)
                }
                EndTable()
            }
        }
        TreePop()
    }

    // Demonstrate using Sorting facilities
    // This is a simplified version of the "Advanced" example, where we mostly focus on the code necessary to handle sorting.
    // Note that the "Advanced" example also showcase manually triggering a sort (e.g. if item quantities have been modified)
    static const char* template_items_names[] =
    {
        "Banana", "Apple", "Cherry", "Watermelon", "Grapefruit", "Strawberry", "Mango",
        "Kiwi", "Orange", "Pineapple", "Blueberry", "Plum", "Coconut", "Pear", "Apricot"
    };
    if (open_action != -1)
        SetNextItemOpen(open_action != 0)
    if (TreeNode("Sorting"))
    {
        // Create item list
        static ImVector<MyItem> items;
        if (items.Size == 0)
        {
            items.resize(50, MyItem())
            for (int n = 0; n < items.Size; n++)
            {
                const int template_n = n % IM_ARRAYSIZE(template_items_names)
                MyItem& item = items[n];
                item.ID = n;
                item.Name = template_items_names[template_n];
                item.Quantity = (n * n - n) % 20; // Assign default quantities
            }
        }

        // Options
        static ImGuiTableFlags flags =
            ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable | ImGuiTableFlags_Sortable | ImGuiTableFlags_SortMulti
            | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_NoBordersInBody
            | ImGuiTableFlags_ScrollY;
        PushStyleCompact()
        CheckboxFlags("ImGuiTableFlags_SortMulti", &flags, ImGuiTableFlags_SortMulti)
        SameLine() HelpMarker("When sorting is enabled: hold shift when clicking headers to sort on multiple column. TableGetSortSpecs() may return specs where (SpecsCount > 1).")
        CheckboxFlags("ImGuiTableFlags_SortTristate", &flags, ImGuiTableFlags_SortTristate)
        SameLine() HelpMarker("When sorting is enabled: allow no sorting, disable default sorting. TableGetSortSpecs() may return specs where (SpecsCount == 0).")
        PopStyleCompact()

        if (BeginTable("table_sorting", 4, flags, ImVec2(0.0f, TEXT_BASE_HEIGHT * 15), 0.0f))
        {
            // Declare columns
            // We use the "user_id" parameter of TableSetupColumn() to specify a user id that will be stored in the sort specifications.
            // This is so our sort function can identify a column given our own identifier. We could also identify them based on their index!
            // Demonstrate using a mixture of flags among available sort-related flags:
            // - ImGuiTableColumnFlags_DefaultSort
            // - ImGuiTableColumnFlags_NoSort / ImGuiTableColumnFlags_NoSortAscending / ImGuiTableColumnFlags_NoSortDescending
            // - ImGuiTableColumnFlags_PreferSortAscending / ImGuiTableColumnFlags_PreferSortDescending
            TableSetupColumn("ID",       ImGuiTableColumnFlags_DefaultSort          | ImGuiTableColumnFlags_WidthFixed,   0.0f, MyItemColumnID_ID)
            TableSetupColumn("Name",                                                  ImGuiTableColumnFlags_WidthFixed,   0.0f, MyItemColumnID_Name)
            TableSetupColumn("Action",   ImGuiTableColumnFlags_NoSort               | ImGuiTableColumnFlags_WidthFixed,   0.0f, MyItemColumnID_Action)
            TableSetupColumn("Quantity", ImGuiTableColumnFlags_PreferSortDescending | ImGuiTableColumnFlags_WidthStretch, 0.0f, MyItemColumnID_Quantity)
            TableSetupScrollFreeze(0, 1) // Make row always visible
            TableHeadersRow()

            // Sort our data if sort specs have been changed!
            if (ImGuiTableSortSpecs* sorts_specs = TableGetSortSpecs())
                if (sorts_specs->SpecsDirty)
                {
                    MyItem::s_current_sort_specs = sorts_specs; // Store in variable accessible by the sort function.
                    if (items.Size > 1)
                        qsort(&items[0], (size_t)items.Size, sizeof(items[0]), MyItem::CompareWithSortSpecs)
                    MyItem::s_current_sort_specs = NULL;
                    sorts_specs->SpecsDirty = false;
                }

            // Demonstrate using clipper for large vertical lists
            ImGuiListClipper clipper;
            clipper.Begin(items.Size)
            while (clipper.Step())
                for (int row_n = clipper.DisplayStart; row_n < clipper.DisplayEnd; row_n++)
                {
                    // Display a data item
                    MyItem* item = &items[row_n];
                    PushID(item->ID)
                    TableNextRow()
                    TableNextColumn()
                    Text("%04d", item->ID)
                    TableNextColumn()
                    TextUnformatted(item->Name)
                    TableNextColumn()
                    SmallButton("None")
                    TableNextColumn()
                    Text("%d", item->Quantity)
                    PopID()
                }
            EndTable()
        }
        TreePop()
    }

    //SetNextItemOpen(true, ImGuiCond_Once) // [DEBUG]
    if (open_action != -1)
        SetNextItemOpen(open_action != 0)
    if (TreeNode("Advanced"))
    {
        static ImGuiTableFlags flags =
            ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable
            | ImGuiTableFlags_Sortable | ImGuiTableFlags_SortMulti
            | ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_NoBordersInBody
            | ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY
            | ImGuiTableFlags_SizingFixedFit;

        enum ContentsType { CT_ShortText, CT_Button, CT_SmallButton, CT_FillButton, CT_Selectable, CT_SelectableSpanRow };
        static int contents_type = CT_SelectableSpanRow;
        const char* contents_type_names[] = { "Text", "Button", "SmallButton", "FillButton", "Selectable", "Selectable (span row)" };
        static int freeze_cols = 1;
        static int freeze_rows = 1;
        static int items_count = IM_ARRAYSIZE(template_items_names) * 2;
        static ImVec2 outer_size_value = ImVec2(0.0f, TEXT_BASE_HEIGHT * 12)
        static float row_min_height = 0.0f; // Auto
        static float inner_width_with_scroll = 0.0f; // Auto-extend
        static bool outer_size_enabled = true;
        static bool show_headers = true;
        static bool show_wrapped_text = false;
        //static ImGuiTextFilter filter;
        //SetNextItemOpen(true, ImGuiCond_Once) // FIXME-TABLE: Enabling this results in initial clipped first pass on table which tend to affects column sizing
        if (TreeNode("Options"))
        {
            // Make the UI compact because there are so many fields
            PushStyleCompact()
            PushItemWidth(TEXT_BASE_WIDTH * 28.0f)

            if (TreeNodeEx("Features:", ImGuiTreeNodeFlags_DefaultOpen))
            {
                CheckboxFlags("ImGuiTableFlags_Resizable", &flags, ImGuiTableFlags_Resizable)
                CheckboxFlags("ImGuiTableFlags_Reorderable", &flags, ImGuiTableFlags_Reorderable)
                CheckboxFlags("ImGuiTableFlags_Hideable", &flags, ImGuiTableFlags_Hideable)
                CheckboxFlags("ImGuiTableFlags_Sortable", &flags, ImGuiTableFlags_Sortable)
                CheckboxFlags("ImGuiTableFlags_NoSavedSettings", &flags, ImGuiTableFlags_NoSavedSettings)
                CheckboxFlags("ImGuiTableFlags_ContextMenuInBody", &flags, ImGuiTableFlags_ContextMenuInBody)
                TreePop()
            }

            if (TreeNodeEx("Decorations:", ImGuiTreeNodeFlags_DefaultOpen))
            {
                CheckboxFlags("ImGuiTableFlags_RowBg", &flags, ImGuiTableFlags_RowBg)
                CheckboxFlags("ImGuiTableFlags_BordersV", &flags, ImGuiTableFlags_BordersV)
                CheckboxFlags("ImGuiTableFlags_BordersOuterV", &flags, ImGuiTableFlags_BordersOuterV)
                CheckboxFlags("ImGuiTableFlags_BordersInnerV", &flags, ImGuiTableFlags_BordersInnerV)
                CheckboxFlags("ImGuiTableFlags_BordersH", &flags, ImGuiTableFlags_BordersH)
                CheckboxFlags("ImGuiTableFlags_BordersOuterH", &flags, ImGuiTableFlags_BordersOuterH)
                CheckboxFlags("ImGuiTableFlags_BordersInnerH", &flags, ImGuiTableFlags_BordersInnerH)
                CheckboxFlags("ImGuiTableFlags_NoBordersInBody", &flags, ImGuiTableFlags_NoBordersInBody) SameLine() HelpMarker("Disable vertical borders in columns Body (borders will always appears in Headers")
                CheckboxFlags("ImGuiTableFlags_NoBordersInBodyUntilResize", &flags, ImGuiTableFlags_NoBordersInBodyUntilResize) SameLine() HelpMarker("Disable vertical borders in columns Body until hovered for resize (borders will always appears in Headers)")
                TreePop()
            }

            if (TreeNodeEx("Sizing:", ImGuiTreeNodeFlags_DefaultOpen))
            {
                EditTableSizingFlags(&flags)
                SameLine() HelpMarker("In the Advanced demo we override the policy of each column so those table-wide settings have less effect that typical.")
                CheckboxFlags("ImGuiTableFlags_NoHostExtendX", &flags, ImGuiTableFlags_NoHostExtendX)
                SameLine() HelpMarker("Make outer width auto-fit to columns, overriding outer_size.x value.\n\nOnly available when ScrollX/ScrollY are disabled and Stretch columns are not used.")
                CheckboxFlags("ImGuiTableFlags_NoHostExtendY", &flags, ImGuiTableFlags_NoHostExtendY)
                SameLine() HelpMarker("Make outer height stop exactly at outer_size.y (prevent auto-extending table past the limit).\n\nOnly available when ScrollX/ScrollY are disabled. Data below the limit will be clipped and not visible.")
                CheckboxFlags("ImGuiTableFlags_NoKeepColumnsVisible", &flags, ImGuiTableFlags_NoKeepColumnsVisible)
                SameLine() HelpMarker("Only available if ScrollX is disabled.")
                CheckboxFlags("ImGuiTableFlags_PreciseWidths", &flags, ImGuiTableFlags_PreciseWidths)
                SameLine() HelpMarker("Disable distributing remainder width to stretched columns (width allocation on a 100-wide table with 3 columns: Without this flag: 33,33,34. With this flag: 33,33,33). With larger number of columns, resizing will appear to be less smooth.")
                CheckboxFlags("ImGuiTableFlags_NoClip", &flags, ImGuiTableFlags_NoClip)
                SameLine() HelpMarker("Disable clipping rectangle for every individual columns (reduce draw command count, items will be able to overflow into other columns). Generally incompatible with ScrollFreeze options.")
                TreePop()
            }

            if (TreeNodeEx("Padding:", ImGuiTreeNodeFlags_DefaultOpen))
            {
                CheckboxFlags("ImGuiTableFlags_PadOuterX", &flags, ImGuiTableFlags_PadOuterX)
                CheckboxFlags("ImGuiTableFlags_NoPadOuterX", &flags, ImGuiTableFlags_NoPadOuterX)
                CheckboxFlags("ImGuiTableFlags_NoPadInnerX", &flags, ImGuiTableFlags_NoPadInnerX)
                TreePop()
            }

            if (TreeNodeEx("Scrolling:", ImGuiTreeNodeFlags_DefaultOpen))
            {
                CheckboxFlags("ImGuiTableFlags_ScrollX", &flags, ImGuiTableFlags_ScrollX)
                SameLine()
                SetNextItemWidth(GetFrameHeight())
                DragInt("freeze_cols", &freeze_cols, 0.2f, 0, 9, NULL, ImGuiSliderFlags_NoInput)
                CheckboxFlags("ImGuiTableFlags_ScrollY", &flags, ImGuiTableFlags_ScrollY)
                SameLine()
                SetNextItemWidth(GetFrameHeight())
                DragInt("freeze_rows", &freeze_rows, 0.2f, 0, 9, NULL, ImGuiSliderFlags_NoInput)
                TreePop()
            }

            if (TreeNodeEx("Sorting:", ImGuiTreeNodeFlags_DefaultOpen))
            {
                CheckboxFlags("ImGuiTableFlags_SortMulti", &flags, ImGuiTableFlags_SortMulti)
                SameLine() HelpMarker("When sorting is enabled: hold shift when clicking headers to sort on multiple column. TableGetSortSpecs() may return specs where (SpecsCount > 1).")
                CheckboxFlags("ImGuiTableFlags_SortTristate", &flags, ImGuiTableFlags_SortTristate)
                SameLine() HelpMarker("When sorting is enabled: allow no sorting, disable default sorting. TableGetSortSpecs() may return specs where (SpecsCount == 0).")
                TreePop()
            }

            if (TreeNodeEx("Other:", ImGuiTreeNodeFlags_DefaultOpen))
            {
                Checkbox("show_headers", &show_headers)
                Checkbox("show_wrapped_text", &show_wrapped_text)

                DragFloat2("##OuterSize", &outer_size_value.x)
                SameLine(0.0f, GetStyle().ItemInnerSpacing.x)
                Checkbox("outer_size", &outer_size_enabled)
                SameLine()
                HelpMarker("If scrolling is disabled (ScrollX and ScrollY not set):\n"
                    "- The table is output directly in the parent window.\n"
                    "- OuterSize.x < 0.0f will right-align the table.\n"
                    "- OuterSize.x = 0.0f will narrow fit the table unless there are any Stretch column.\n"
                    "- OuterSize.y then becomes the minimum size for the table, which will extend vertically if there are more rows (unless NoHostExtendY is set).")

                // From a user point of view we will tend to use 'inner_width' differently depending on whether our table is embedding scrolling.
                // To facilitate toying with this demo we will actually pass 0.0f to the BeginTable() when ScrollX is disabled.
                DragFloat("inner_width (when ScrollX active)", &inner_width_with_scroll, 1.0f, 0.0f, FLT_MAX)

                DragFloat("row_min_height", &row_min_height, 1.0f, 0.0f, FLT_MAX)
                SameLine() HelpMarker("Specify height of the Selectable item.")

                DragInt("items_count", &items_count, 0.1f, 0, 9999)
                Combo("items_type (first column)", &contents_type, contents_type_names, IM_ARRAYSIZE(contents_type_names))
                //filter.Draw("filter")
                TreePop()
            }

            PopItemWidth()
            PopStyleCompact()
            Spacing()
            TreePop()
        }

        // Recreate/reset item list if we changed the number of items
        static ImVector<MyItem> items;
        static ImVector<int> selection;
        static bool items_need_sort = false;
        if (items.Size != items_count)
        {
            items.resize(items_count, MyItem())
            for (int n = 0; n < items_count; n++)
            {
                const int template_n = n % IM_ARRAYSIZE(template_items_names)
                MyItem& item = items[n];
                item.ID = n;
                item.Name = template_items_names[template_n];
                item.Quantity = (template_n == 3) ? 10 : (template_n == 4) ? 20 : 0; // Assign default quantities
            }
        }

        const ImDrawList* parent_draw_list = GetWindowDrawList()
        const int parent_draw_list_draw_cmd_count = parent_draw_list->CmdBuffer.Size;
        ImVec2 table_scroll_cur, table_scroll_max; // For debug display
        const ImDrawList* table_draw_list = NULL;  // "

        const float inner_width_to_use = (flags & ImGuiTableFlags_ScrollX) ? inner_width_with_scroll : 0.0f;
        if (BeginTable("table_advanced", 6, flags, outer_size_enabled ? outer_size_value : ImVec2(0, 0), inner_width_to_use))
        {
            // Declare columns
            // We use the "user_id" parameter of TableSetupColumn() to specify a user id that will be stored in the sort specifications.
            // This is so our sort function can identify a column given our own identifier. We could also identify them based on their index!
            TableSetupColumn("ID",           ImGuiTableColumnFlags_DefaultSort | ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoHide, 0.0f, MyItemColumnID_ID)
            TableSetupColumn("Name",         ImGuiTableColumnFlags_WidthFixed, 0.0f, MyItemColumnID_Name)
            TableSetupColumn("Action",       ImGuiTableColumnFlags_NoSort | ImGuiTableColumnFlags_WidthFixed, 0.0f, MyItemColumnID_Action)
            TableSetupColumn("Quantity",     ImGuiTableColumnFlags_PreferSortDescending, 0.0f, MyItemColumnID_Quantity)
            TableSetupColumn("Description",  (flags & ImGuiTableFlags_NoHostExtendX) ? 0 : ImGuiTableColumnFlags_WidthStretch, 0.0f, MyItemColumnID_Description)
            TableSetupColumn("Hidden",       ImGuiTableColumnFlags_DefaultHide | ImGuiTableColumnFlags_NoSort)
            TableSetupScrollFreeze(freeze_cols, freeze_rows)

            // Sort our data if sort specs have been changed!
            ImGuiTableSortSpecs* sorts_specs = TableGetSortSpecs()
            if (sorts_specs && sorts_specs->SpecsDirty)
                items_need_sort = true;
            if (sorts_specs && items_need_sort && items.Size > 1)
            {
                MyItem::s_current_sort_specs = sorts_specs; // Store in variable accessible by the sort function.
                qsort(&items[0], (size_t)items.Size, sizeof(items[0]), MyItem::CompareWithSortSpecs)
                MyItem::s_current_sort_specs = NULL;
                sorts_specs->SpecsDirty = false;
            }
            items_need_sort = false;

            // Take note of whether we are currently sorting based on the Quantity field,
            // we will use this to trigger sorting when we know the data of this column has been modified.
            const bool sorts_specs_using_quantity = (TableGetColumnFlags(3) & ImGuiTableColumnFlags_IsSorted) != 0;

            // Show headers
            if (show_headers)
                TableHeadersRow()

            // Show data
            // FIXME-TABLE FIXME-NAV: How we can get decent up/down even though we have the buttons here?
            PushButtonRepeat(true)
#if 1
            // Demonstrate using clipper for large vertical lists
            ImGuiListClipper clipper;
            clipper.Begin(items.Size)
            while (clipper.Step())
            {
                for (int row_n = clipper.DisplayStart; row_n < clipper.DisplayEnd; row_n++)
#else
            // Without clipper
            {
                for (int row_n = 0; row_n < items.Size; row_n++)
#endif
                {
                    MyItem* item = &items[row_n];
                    //if (!filter.PassFilter(item->Name))
                    //    continue;

                    const bool item_is_selected = selection.contains(item->ID)
                    PushID(item->ID)
                    TableNextRow(ImGuiTableRowFlags_None, row_min_height)
                    TableNextColumn()

                    // For the demo purpose we can select among different type of items submitted in the first column
                    char label[32];
                    sprintf(label, "%04d", item->ID)
                    if (contents_type == CT_ShortText)
                        TextUnformatted(label)
                    else if (contents_type == CT_Button)
                        Button(label)
                    else if (contents_type == CT_SmallButton)
                        SmallButton(label)
                    else if (contents_type == CT_FillButton)
                        Button(label, ImVec2(-FLT_MIN, 0.0f))
                    else if (contents_type == CT_Selectable || contents_type == CT_SelectableSpanRow)
                    {
                        ImGuiSelectableFlags selectable_flags = (contents_type == CT_SelectableSpanRow) ? ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowItemOverlap : ImGuiSelectableFlags_None;
                        if (Selectable(label, item_is_selected, selectable_flags, ImVec2(0, row_min_height)))
                        {
                            if (GetIO().KeyCtrl)
                            {
                                if (item_is_selected)
                                    selection.find_erase_unsorted(item->ID)
                                else
                                    selection.push_back(item->ID)
                            }
                            else
                            {
                                selection.clear()
                                selection.push_back(item->ID)
                            }
                        }
                    }

                    if (TableNextColumn())
                        TextUnformatted(item->Name)

                    // Here we demonstrate marking our data set as needing to be sorted again if we modified a quantity,
                    // and we are currently sorting on the column showing the Quantity.
                    // To avoid triggering a sort while holding the button, we only trigger it when the button has been released.
                    // You will probably need a more advanced system in your code if you want to automatically sort when a specific entry changes.
                    if (TableNextColumn())
                    {
                        if (SmallButton("Chop")) { item->Quantity += 1; }
                        if (sorts_specs_using_quantity && IsItemDeactivated()) { items_need_sort = true; }
                        SameLine()
                        if (SmallButton("Eat")) { item->Quantity -= 1; }
                        if (sorts_specs_using_quantity && IsItemDeactivated()) { items_need_sort = true; }
                    }

                    if (TableNextColumn())
                        Text("%d", item->Quantity)

                    TableNextColumn()
                    if (show_wrapped_text)
                        TextWrapped("Lorem ipsum dolor sit amet")
                    else
                        Text("Lorem ipsum dolor sit amet")

                    if (TableNextColumn())
                        Text("1234")

                    PopID()
                }
            }
            PopButtonRepeat()

            // Store some info to display debug details below
            table_scroll_cur = ImVec2(GetScrollX(), GetScrollY())
            table_scroll_max = ImVec2(GetScrollMaxX(), GetScrollMaxY())
            table_draw_list = GetWindowDrawList()
            EndTable()
        }
        static bool show_debug_details = false;
        Checkbox("Debug details", &show_debug_details)
        if (show_debug_details && table_draw_list)
        {
            SameLine(0.0f, 0.0f)
            const int table_draw_list_draw_cmd_count = table_draw_list->CmdBuffer.Size;
            if (table_draw_list == parent_draw_list)
                Text(": DrawCmd: +%d (in same window)",
                    table_draw_list_draw_cmd_count - parent_draw_list_draw_cmd_count)
            else
                Text(": DrawCmd: +%d (in child window), Scroll: (%.f/%.f) (%.f/%.f)",
                    table_draw_list_draw_cmd_count - 1, table_scroll_cur.x, table_scroll_max.x, table_scroll_cur.y, table_scroll_max.y)
        }
        TreePop()
    }

*/

    PopID()
    // ShowDemoWindowColumns()
    if disable_indent
        PopStyleVar()

