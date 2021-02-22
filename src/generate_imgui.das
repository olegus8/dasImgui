require daslib/cpp_gen

[export]
def main

    // configure

    blocked_type_names <- [{auto[]
        // "ImVector";
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
        "ImVec3";
        "ImVec4";
        "ImColor";
        "ImGuiTableColumnSortSpecs"
    }]

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
        "ImGuiTabBarFlags_" => [[ExEnum() name = "ImGuiTabBarFlags", isFlags=true]];
        "ImGuiTabItemFlags_" => [[ExEnum() name = "ImGuiTabItemFlags", isFlags=true]];
        "ImGuiTreeNodeFlags_" => [[ExEnum() name = "ImGuiTreeNodeFlags", isFlags=true]];
        "ImGuiButtonFlags_"  => [[ExEnum() name = "ImGuiButtonFlags", isFlags=true]];
        "ImGuiTableColumnFlags_"  => [[ExEnum() name = "ImGuiTableColumnFlags", isFlags=true]];
        "ImGuiKeyModFlags_"  => [[ExEnum() name = "ImGuiKeyModFlags", isFlags=true]];

    // not flags
        "ImGuiStyleVar_" => [[ExEnum() name = "ImGuiStyleVar"]];
        "ImGuiCol_" => [[ExEnum() name = "ImGuiCol"]];
        "ImGuiKey_" => [[ExEnum() name = "ImGuiKey"]];
        "ImGuiSortDirection_" => [[ExEnum() name = "ImGuiSortDirection"]];
        "ImGuiMouseButton_" => [[ExEnum() name = "ImGuiMouseButton"]]
    }}

    substitute_field_types <- {{
        "ImGuiInputTextCallbackData::EventFlag" => "ImGuiInputTextFlags_";
        "ImGuiInputTextCallbackData::Flags" => "ImGuiInputTextFlags_";
        "ImGuiInputTextCallbackData::EventKey" => "ImGuiKey_";
        "ImGuiIO::ConfigFlags" => "ImGuiConfigFlags_";
        "ImGuiIO::BackendFlags" => "ImGuiBackendFlags_";
        "ImGuiIO::ImGuiKeyModFlags" => "ImGuiKeyModFlags_"
    }}

    // generate

    var args <- get_command_line_arguments()
    bindHeaders(args[3], args[4])
    genDefineConstants(args[5],args[4])

