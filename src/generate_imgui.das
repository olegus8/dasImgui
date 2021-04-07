require daslib/cpp_gen

[export]
def main

    // configure

    blocked_type_names <- [{auto[]
        "va_list";
        "ImGuiStoragePair";
        "ImDrawListSharedData";
        "ImGuiInputTextCallback"
    }]

    blocked_functions <- [{auto[]
        "operator delete";
        "operator new";
        "__security_init_cookie";
        "__security_check_cookie";
        "ImGui::TextUnformatted";
        "ImGuiTextFilter::PassFilter";
        "ImGuiTextBuffer::append";
        "ImGuiInputTextCallbackData::InsertChars";
        "ImGui::CalcTextSize"
    }]

    cmres_functions <- [{auto[]
        "ImGui_ImplVulkanH_SelectSurfaceFormat"
    }]

    local_type_names <- [{auto[]
        "ImVec2";
        "ImVec4";
        "ImColor";
        "ImGuiTableColumnSortSpecs"
    }]

    alias_types <- {{
        "ImVec2" => "Type::tFloat2";
        "ImVec4" => "Type::tFloat4";
        "ImColor" => "Type::tFloat4"
    }}

    ex_enums <- {{
    // flags
        "ImGuiWindowFlags_" => [[ExEnum() name="ImGuiWindowFlags", isFlags=true]];
        "ImGuiBackendFlags_" => [[ExEnum() name="ImGuiBackendFlags", isFlags=true]];
        "ImGuiConfigFlags_"  => [[ExEnum() name="ImGuiConfigFlags", isFlags=true]];
        "ImGuiSliderFlags_" => [[ExEnum() name = "ImGuiSliderFlags", isFlags=true]];
        "ImGuiCond_" => [[ExEnum() name = "ImGuiCond", isFlags=true]];
        "ImGuiTableFlags_" => [[ExEnum() name = "ImGuiTableFlags", isFlags=true]];
        "ImGuiSelectableFlags_" => [[ExEnum() name = "ImGuiSelectableFlags", isFlags=true]];
        "ImGuiInputTextFlags_" => [[ExEnum() name = "ImGuiInputTextFlags", isFlags=true]];
        "ImGuiColorEditFlags_" => [[ExEnum() name = "ImGuiColorEditFlags", isFlags=true]];
        "ImDrawCornerFlags_" => [[ExEnum() name = "ImDrawCornerFlags", isFlags=true]];
        "ImDrawFlags_" => [[ExEnum() name = "ImDrawFlags", isFlags=true]];
        "ImGuiTabBarFlags_" => [[ExEnum() name = "ImGuiTabBarFlags", isFlags=true]];
        "ImGuiTabItemFlags_" => [[ExEnum() name = "ImGuiTabItemFlags", isFlags=true]];
        "ImGuiTreeNodeFlags_" => [[ExEnum() name = "ImGuiTreeNodeFlags", isFlags=true]];
        "ImGuiButtonFlags_"  => [[ExEnum() name = "ImGuiButtonFlags", isFlags=true]];
        "ImGuiTableColumnFlags_"  => [[ExEnum() name = "ImGuiTableColumnFlags", isFlags=true]];
        "ImGuiKeyModFlags_"  => [[ExEnum() name = "ImGuiKeyModFlags", isFlags=true]];
        "ImGuiTableRowFlags_"  => [[ExEnum() name = "ImGuiTableRowFlags", isFlags=true]];
        "ImGuiComboFlags_" => [[ExEnum() name = "ImGuiComboFlags", isFlags=true]];
        "ImGuiDragDropFlags_" => [[ExEnum() name = "ImGuiDragDropFlags", isFlags=true]];
        "ImGuiHoveredFlags_" => [[ExEnum() name = "ImGuiHoveredFlags", isFlags=true]];
        "ImGuiFocusedFlags_" => [[ExEnum() name = "ImGuiFocusedFlags", isFlags=true]];
        // imnodes
        "StyleFlags" => [[ExEnum() name = "ImNodesStyleFlags", isFlags=true]];
        "AttributeFlags" => [[ExEnum() name = "ImNodesAttributeFlags", isFlags=true]];

    // not flags
        "ImGuiStyleVar_" => [[ExEnum() name = "ImGuiStyleVar"]];
        "ImGuiCol_" => [[ExEnum() name = "ImGuiCol"]];
        "ImGuiKey_" => [[ExEnum() name = "ImGuiKey"]];
        "ImGuiSortDirection_" => [[ExEnum() name = "ImGuiSortDirection"]];
        "ImGuiMouseButton_" => [[ExEnum() name = "ImGuiMouseButton"]];
        "ImGuiDir_" => [[ExEnum() name = "ImGuiDir"]];
        "ImGuiDataType_" => [[ExEnum() name = "ImGuiDataType"]];
        "ImGuiTableBgTarget_" => [[ExEnum() name = "ImGuiTableBgTarget"]];
        // imnodes
        "PinShape" => [[ExEnum() name = "ImNodesPinShape"]];
        "StyleVar" => [[ExEnum() name = "ImNodesStyleVar"]];
        "ColorStyle" => [[ExEnum() name = "ImNodesColorStyle"]]
    }}

    substitute_field_types <- {{
        "ImGuiInputTextCallbackData::EventFlag" => "ImGuiInputTextFlags_";
        "ImGuiInputTextCallbackData::Flags" => "ImGuiInputTextFlags_";
        "ImGuiInputTextCallbackData::EventKey" => "ImGuiKey_";
        "ImGuiIO::ConfigFlags" => "ImGuiConfigFlags_";
        "ImGuiIO::BackendFlags" => "ImGuiBackendFlags_";
        "ImGuiIO::ImGuiKeyModFlags" => "ImGuiKeyModFlags_"
    }}

    namespace_to_prefix <- {{
        "imnodes" => "IMNODES_NAMESPACE"
    }}

    // generate
    var args <- get_command_line_arguments()
    generate_split_functions = true
    split_prefix = "{args[4]}_split"

    split_cpp_prefix="
#include \"daScript\/daScript.h\"
#include \"daScript\/ast\/ast_typefactory_bind.h\"
#include \"imgui_stub.h\"
#include \"imnodes_stub.h\"
using namespace das;
#include \"need_imgui.h\"
#include \"need_imnodes.h\"
#if USE_GENERATED
#define GLOBAL_NAMESPACE    1
#include \"module_imgui.h\"
#endif
void Module_imgui::initFunctions_$$$() \{
#if USE_GENERATED
#if USE_GENERATED_SPLIT
"

    split_cpp_suffix="
#endif
#endif
}
"

    bindHeaders(args[3], args[4])
    genDefineConstants(args[5],args[4])

