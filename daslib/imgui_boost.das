options indenting = 4
options remove_unused_symbols = false

module imgui_boost shared

require imgui public
require glfw
require imgui_app
require daslib/safe_addr
require rtti
require strings
require math

let IMGUI_PAYLOAD_TYPE_COLOR_3F = "_COL3F"
let IMGUI_PAYLOAD_TYPE_COLOR_4F = "_COL4F"

// note - this has to correspond to C++ das::DasImguiInputText structure
struct ImGuiInputTextBuffer
    context : Context?
    callback : lambda<(var it:ImGuiInputTextBuffer; var itc:ImGuiInputTextCallbackData):int>
    buffer : array<uint8>
    at : LineInfo

def make_input_buffer ( var buf : ImGuiInputTextBuffer; txt:string; len:int )
    buf.buffer |> resize(len)
    let bytes = clamp ( length(txt), 0, len-1 )
    unsafe
        memcpy ( addr(buf.buffer[0]), reinterpret<void?> txt, bytes )

def ImGuiInputTextBuffer ( txt:string; len:int )
    var buf : ImGuiInputTextBuffer
    make_input_buffer(buf, txt, len)
    return <- buf

def ImGuiInputTextBuffer ( txt:string; len:int; var cb:lambda<(var it:ImGuiInputTextBuffer; var itc:ImGuiInputTextCallbackData):int> )
    var buf : ImGuiInputTextBuffer
    make_input_buffer(buf, txt, len)
    buf.callback <- cb
    return <- buf

def lock ( buf : ImGuiInputTextBuffer; blk : block < ( st:string# ) : void > )
    unsafe
        let pbuf = addr(buf.buffer[0])
        blk |> invoke ( reinterpret<string#> pbuf )

def to_string ( buf : ImGuiInputTextBuffer )
    unsafe
        let pbuf = addr(buf.buffer[0])
        return clone_string(reinterpret<string> pbuf)

def clear ( var buf : ImGuiInputTextBuffer )
    for t in buf.buffer
        t = uint8(0)

def InputText ( lab:string; buf:ImGuiInputTextBuffer; flags:ImGuiInputTextFlags = ImGuiInputTextFlags None )
    return _builtin_InputText(buf, lab, flags)

def InputTextWithHint ( lab,hint:string; buf:ImGuiInputTextBuffer; flags:ImGuiInputTextFlags = ImGuiInputTextFlags None )
    return _builtin_InputTextWithHint(buf, lab, hint, flags)

def InputTextMultiline ( lab:string; buf:ImGuiInputTextBuffer; siz:float2 = float2(0.0f,0.0f); flags:ImGuiInputTextFlags = ImGuiInputTextFlags None )
    return _builtin_InputTextMultiline(buf, lab, siz, flags)

// note - this needs to correspond to C++ structure
struct ImGuiSizeConstraints
    context: Context?
    callback: lambda<(var data:ImGuiSizeCallbackData):void>
    at: LineInfo

def ImGuiSizeConstraints(var lmb:lambda<(var data:ImGuiSizeCallbackData):void>)
    var self : ImGuiSizeConstraints
    self.callback <- lmb
    return <- self

def SetNextWindowSizeConstraints(size_min,size_max:float2; var cn:ImGuiSizeConstraints)
    _builtin_SetNextWindowSizeConstraints(cn,size_min,size_max)

// note - this needs to correspond to C++ structure
struct ImGuiComboGetter
    context : Context?
    callback : lambda<(idx:int;var result:string&):bool>
    at : LineInfo

def ImGuiComboGetter(var lmb:lambda<(idx:int;var result:string&):bool>)
    var self : ImGuiComboGetter
    self.callback <- lmb
    return <-self

def Combo ( lab:string; current_item:int? implicit; getter:ImGuiComboGetter; items_count:int; popup_max_height_in_items:int = -1 )
    return _builtin_Combo(getter, lab, current_item, items_count, popup_max_height_in_items)

// note - this needs to correspond to C++ structure
struct ImGuiPlotGetter
    context : Context?
    callback : lambda<(idx:int):float>
    at : LineInfo

def ImGuiPlotGetter(var lmb:lambda<(idx:int):float>)
    var self : ImGuiPlotGetter
    self.callback <- lmb
    return <-self

def PlotLines(
    lab:string; getter:ImGuiPlotGetter; values_count:int; values_offset:int = 0;
    overlay_text:string = "";
    scale_min : float = FLT_MAX; scale_max : float = FLT_MAX;
    graph_size : float2 = float2())
    var gsize = graph_size
    unsafe
        _builtin_PlotLines(getter, lab, values_count, values_offset, overlay_text, scale_min, scale_max, gsize)

def PlotHistogram(
    lab:string; getter:ImGuiPlotGetter; values_count:int; values_offset:int = 0;
    overlay_text:string = "";
    scale_min : float = FLT_MAX; scale_max : float = FLT_MAX;
    graph_size : float2 = float2())
    var gsize = graph_size
    unsafe
        _builtin_PlotHistogram(getter, lab, values_count, values_offset, overlay_text, scale_min, scale_max, gsize)

let IM_COL32_WHITE = IM_COL32(255,255,255,255)
let IM_COL32_BLACK = IM_COL32(0,0,0,255)
let IM_COL32_BLACK_TRANS = IM_COL32(0,0,0,0)

def IM_COL32(R,G,B,A:uint)
    return (A<<IM_COL32_A_SHIFT) | (B<<IM_COL32_B_SHIFT) | (G<<IM_COL32_G_SHIFT) | (R<<IM_COL32_R_SHIFT)

def IM_COL32(R,G,B,A:int)
    return (uint(A)<<IM_COL32_A_SHIFT) | (uint(B)<<IM_COL32_B_SHIFT) | (uint(G)<<IM_COL32_G_SHIFT) | (uint(R)<<IM_COL32_R_SHIFT)

def Combo ( lab:string; current_item:int? implicit; items:array<string>; popul_max_heigh_in_items : int = -1 )
    let nItems = length(items)
    unsafe
        if nItems != 0
            return imgui::Combo(lab,current_item,addr(items[0]),nItems,popul_max_heigh_in_items)
        else
            return imgui::Combo(lab,current_item,null,0,popul_max_heigh_in_items)

def Combo ( lab:string; current_item:int? implicit; items:string[]; popul_max_heigh_in_items : int = -1 )
    unsafe
        return imgui::Combo(lab,current_item,addr(items[0]),length(items),popul_max_heigh_in_items)

def ListBox ( lab:string; current_item:int? implicit; items:array<string>; height_in_items:int = -1 )
    let nItems = length(items)
    unsafe
        if nItems != 0
            return imgui::ListBox(lab,current_item,addr(items[0]),nItems,height_in_items)
        else
            return imgui::ListBox(lab,current_item,null,0,height_in_items)

def ListBox ( lab:string; current_item:int? implicit; items:string[]; height_in_items:int = -1 )
    unsafe
        return imgui::ListBox(lab,current_item,addr(items[0]),length(items),height_in_items)

def PlotLines(
    lab:string; values:float[]; values_offset:int = 0;
    overlay_text:string = "";
    scale_min : float = FLT_MAX; scale_max : float = FLT_MAX;
    graph_size : float2 = float2();
    stride : int = typeinfo(sizeof type<float>))
    var gsize = graph_size
    unsafe
        imgui::PlotLines(lab, addr(values[0]), length(values), values_offset, overlay_text, scale_min, scale_max, gsize, stride)

def PlotLines(
    lab:string; values:array<float>; values_offset:int = 0;
    overlay_text:string = "";
    scale_min : float = FLT_MAX; scale_max : float = FLT_MAX;
    graph_size : float2 = float2();
    stride : int = typeinfo(sizeof type<float>))
    var gsize = graph_size
    unsafe
        imgui::PlotLines(lab, addr(values[0]), length(values), values_offset, overlay_text, scale_min, scale_max, gsize, stride)

def PlotHistogram(
    lab:string; values:float[]; values_offset:int = 0;
    overlay_text:string = "";
    scale_min : float = FLT_MAX; scale_max : float = FLT_MAX;
    graph_size : float2 = float2();
    stride : int = typeinfo(sizeof type<float>))
    var gsize = graph_size
    unsafe
        imgui::PlotHistogram(lab, addr(values[0]), length(values), values_offset, overlay_text, scale_min, scale_max, gsize, stride)

def PlotHistogram(
    lab:string; values:array<float>; values_offset:int = 0;
    overlay_text:string = "";
    scale_min : float = FLT_MAX; scale_max : float = FLT_MAX;
    graph_size : float2 = float2();
    stride : int = typeinfo(sizeof type<float>))
    var gsize = graph_size
    unsafe
        imgui::PlotHistogram(lab, addr(values[0]), length(values), values_offset, overlay_text, scale_min, scale_max, gsize, stride)

def CheckboxFlags(lab:string; var p_flags:auto(FLAGT)? implicit; flags:FLAGT )
    unsafe
        return imgui::CheckboxFlags(lab,
            reinterpret<int?> p_flags,
            int(flags))

def RadioButton(lab:string; var p_flags:auto(FLAGT)? implicit; flags:FLAGT)
    unsafe
        return imgui::RadioButton(lab,
            reinterpret<int?> p_flags,
            int(flags))

def Begin(name:string; blk:block)
    Begin(name)
    invoke(blk)
    End()

def Begin(name:string; p_open:bool?; blk:block)
    Begin(name,p_open)
    invoke(blk)
    End()

def Begin(name:string; p_open:bool?; flags:ImGuiWindowFlags; blk:block)
    Begin(name,p_open,flags)
    invoke(blk)
    End()

def BeginMainMenuBar ( blk:block )
    if BeginMainMenuBar()
        invoke(blk)
        EndMainMenuBar()

def BeginMenuBar ( blk:block )
    if BeginMenuBar()
        invoke(blk)
        EndMenuBar()

def BeginMenu ( lab:string; blk:block )
    if BeginMenu(lab)
        invoke(blk)
        EndMenu()

def BeginMenu ( lab:string; enabled:bool; blk:block )
    if BeginMenu(lab,enabled)
        invoke(blk)
        EndMenu()

def MenuItem ( lab:string; blk:block )
    if MenuItem(lab)
        invoke(blk)

def MenuItem ( lab,shortcut:string; blk:block )
    if MenuItem(lab,shortcut)
        invoke(blk)

def MenuItem ( lab,shortcut:string; selected:bool; blk:block )
    if MenuItem(lab,shortcut,selected)
        invoke(blk)

def MenuItem ( lab,shortcut:string; selected,enabled:bool; blk:block )
    if MenuItem(lab,shortcut,selected,enabled)
        invoke(blk)

def MenuItem ( lab,shortcut:string; selected:bool?; blk:block )
    if MenuItem(lab,shortcut,selected)
        invoke(blk)

def MenuItem ( lab,shortcut:string; selected:bool?; enabled:bool; blk:block )
    if MenuItem(lab,shortcut,selected,enabled)
        invoke(blk)
