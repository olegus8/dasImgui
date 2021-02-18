options indenting = 4
options remove_unused_symbols = false

module imgui_boost shared

require imgui public
require glfw
require imgui_app
require daslib/safe_addr

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
