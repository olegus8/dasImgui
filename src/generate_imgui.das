require daslib/cpp_gen

[export]
def main

    // configure

    blocked_type_names <- [{auto[]
        "ImVector";
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
        "ImGuiTextFilter::PassFilter"
    }]

    cmres_functions <- [{auto[]
        "ImGui_ImplVulkanH_SelectSurfaceFormat"
    }]

    local_type_names <- [{auto[]
        "ImVec2";
        "ImVec3";
        "ImVec4";
        "ImColor"
    }]

    // generate

    var args <- get_command_line_arguments()
    bindHeaders(args[3], args[4])
    genDefineConstants(args[5],args[4])

