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

// note - this needs to correspond to C++ structure

struct ImGuiSizeConstraints
    context: Context?
    callback: lambda<(var data:ImGuiSizeCallbackData):void>
    at: LineInfo

def ImGuiSizeConstraints(var lmb:lambda<(var data:ImGuiSizeCallbackData):void>)
    var self : ImGuiSizeConstraints
    self.callback <- lmb
    return <- self

def SetNextWindowSizeConstraints(size_min,size_max:ImVec2; var cn:ImGuiSizeConstraints)
    _builtin_SetNextWindowSizeConstraints(cn,size_min,size_max)

let IM_COL32_WHITE = IM_COL32(255,255,255,255)
let IM_COL32_BLACK = IM_COL32(0,0,0,255)
let IM_COL32_BLACK_TRANS = IM_COL32(0,0,0,0)

def IM_COL32(R,G,B,A:uint)
    return (A<<IM_COL32_A_SHIFT) | (B<<IM_COL32_B_SHIFT) | (G<<IM_COL32_G_SHIFT) | (R<<IM_COL32_R_SHIFT)

def IM_COL32(R,G,B,A:int)
    return (uint(A)<<IM_COL32_A_SHIFT) | (uint(B)<<IM_COL32_B_SHIFT) | (uint(G)<<IM_COL32_G_SHIFT) | (uint(R)<<IM_COL32_R_SHIFT)

def ImVec4 ( col:ImColor )
    return col.Value

def Combo ( lab:string; current_item:int? implicit; items:array<string>; popul_max_heigh_in_items : int = -1 )
    let nItems = length(items)
    unsafe
        if nItems != 0
            imgui::Combo(lab,current_item,addr(items[0]),nItems,popul_max_heigh_in_items)
        else
            imgui::Combo(lab,current_item,null,0,popul_max_heigh_in_items)

def Combo ( lab:string; current_item:int? implicit; items:string[]; popul_max_heigh_in_items : int = -1 )
    unsafe
        imgui::Combo(lab,current_item,addr(items[0]),length(items),popul_max_heigh_in_items)

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

def PlotHistogram(
    lab:string; values:float[]; values_offset:int = 0;
    overlay_text:string = "";
    scale_min : float = FLT_MAX; scale_max : float = FLT_MAX;
    graph_size : ImVec2 = ImVec2();
    stride : int = typeinfo(sizeof type<float>))
    var gsize = graph_size
    unsafe
        imgui::PlotHistogram(lab, addr(values[0]), length(values), values_offset, overlay_text, scale_min, scale_max, gsize, stride)

def PlotHistogram(
    lab:string; values:array<float>; values_offset:int = 0;
    overlay_text:string = "";
    scale_min : float = FLT_MAX; scale_max : float = FLT_MAX;
    graph_size : ImVec2 = ImVec2();
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

