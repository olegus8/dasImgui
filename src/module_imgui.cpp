#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"

#include <imgui.h>

using namespace das;

#include "need_imgui.h"

#if USE_GENERATED

#include "module_imgui.h"

#endif

/*
[build] EXEC : warning : variadic function LabelText aka ImGui::LabelText [C:\Users\Boris\Work\yzg\build\IMGUI_GENERATE.vcxproj]
[build] EXEC : warning : variadic function BulletText aka ImGui::BulletText [C:\Users\Boris\Work\yzg\build\IMGUI_GENERATE.vcxproj]
[build] EXEC : warning : variadic function SetTooltip aka ImGui::SetTooltip [C:\Users\Boris\Work\yzg\build\IMGUI_GENERATE.vcxproj]
[build] EXEC : warning : variadic function TextWrapped aka ImGui::TextWrapped [C:\Users\Boris\Work\yzg\build\IMGUI_GENERATE.vcxproj]
[build] EXEC : warning : variadic function TreeNode aka ImGui::TreeNode [C:\Users\Boris\Work\yzg\build\IMGUI_GENERATE.vcxproj]
*/

namespace das {
    void Text ( const char * txt ) {
        ImGui::Text(txt);
    }
    void TextWrapped ( const char * txt ) {
        ImGui::TextWrapped(txt);
    }
    void TextDisabled ( const char * txt ) {
        ImGui::TextDisabled(txt);
    }
    void TextColored ( const ImVec4 & col, const char * txt ) {
        ImGui::TextColored(col,txt);
    }
    void LogText ( const char * txt ) {
        ImGui::LogText(txt);
    }
    void TreeNode ( const char * id, const char * txt ) {
        ImGui::TreeNode(id,txt);
    }
    void TreeNodeEx ( const char * id, ImGuiTreeNodeFlags flags, const char * txt ) {
        ImGui::TreeNodeEx(id, flags, txt);
    }
    void TreeNodeEx2 ( const void * id, ImGuiTreeNodeFlags flags, const char * txt ) {
        ImGui::TreeNodeEx(id, flags, txt);
    }
    void TextUnformatted ( const char * txt ) {
        ImGui::TextUnformatted(txt, nullptr);
    }
    void BulletText ( const char * txt ) {
        ImGui::BulletText(txt);
    }
    void SetTooltip ( const char * txt ) {
        ImGui::SetTooltip(txt);
    }

    /*
    IMGUI_API bool          InputText(const char* label, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL);
    IMGUI_API bool          InputTextMultiline(const char* label, char* buf, size_t buf_size, const ImVec2& size = ImVec2(0, 0), ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL);
    IMGUI_API bool          InputTextWithHint(const char* label, const char* hint, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL);
    */

    bool InputText ( const char* label, char* buf, int32_t buf_size, ImGuiInputTextFlags flags ) {
        return ImGui::InputText(label,buf,buf_size,flags);
    }

    // ImGui::ImGuiTextFilter::PassFilter

    bool PassFilter ( ImGuiTextFilter & filter, const char* text ) {
        return filter.PassFilter(text, nullptr);
    }

    void AddText( ImDrawList & drawList, const ImVec2& pos, ImU32 col, const char* text ) {
        drawList.AddText(pos, col, text);
    }

    void AddText2( ImDrawList & drawList, const ImFont* font, float font_size, const ImVec2& pos, ImU32 col,
        const char* text_begin, float wrap_width = 0.0f, const ImVec4* cpu_fine_clip_rect = nullptr) {
        drawList.AddText(font,font_size,pos,col,text_begin,nullptr,wrap_width,cpu_fine_clip_rect);
    }

    // ImColor

    ImColor HSV(float h, float s, float v, float a = 1.0f) {
        return ImColor::HSV(h,s,v,a);
    }
}

Module_imgui::Module_imgui() : Module("imgui") {
    // check version
    IMGUI_CHECKVERSION();
    // make basic module
    lib.addModule(this);
    lib.addBuiltInModule();
    addAnnotation(make_smart<DummyTypeAnnotation>("ImGuiContext", "ImGuiContext",
        1, 1)); // sizeof(ImGuiContext), alignof(ImGuiContext)));
    addAnnotation(make_smart<DummyTypeAnnotation>("ImDrawListSharedData", "ImDrawListSharedData",
        1, 1)); // sizeof(ImGuiContext), alignof(ImGuiContext)));
    // constants
    addConstant(*this,"IMGUI_VERSION", IMGUI_VERSION);
    addConstant(*this,"IMGUI_VERSION_NUM", IMGUI_VERSION_NUM);
}

bool Module_imgui::initDependencies() {
    if ( initialized ) return true;
    initialized = true;
    initEnums();
    initAnnotations();
    initFunctions();
    initMethods();
#if USE_GENERATED
    // constants
    addConstant(*this,"IM_COL32_A_MASK",uint32_t(IM_COL32_A_MASK));
    addConstant(*this,"IM_COL32_R_SHIFT",uint32_t(IM_COL32_R_SHIFT));
    addConstant(*this,"IM_COL32_G_SHIFT",uint32_t(IM_COL32_G_SHIFT));
    addConstant(*this,"IM_COL32_B_SHIFT",uint32_t(IM_COL32_B_SHIFT));
    addConstant(*this,"IM_COL32_A_SHIFT",uint32_t(IM_COL32_A_SHIFT));
    // vector C-tors
    addCtor<ImVec2>(*this,lib,"ImVec2","ImVec2");
    addCtor<ImVec2,float,float>(*this,lib,"ImVec2","ImVec2");
    addCtor<ImVec4>(*this,lib,"ImVec4","ImVec4");
    addCtor<ImVec4,float,float,float,float>(*this,lib,"ImVec4","ImVec4");
    // imgui text filter
    addExtern<DAS_BIND_FUN(das::PassFilter)>(*this, lib, "PassFilter",
        SideEffects::worstDefault, "das::PassFilter");
    // imcolor
    addExtern<DAS_BIND_FUN(das::HSV),SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "HSV",
        SideEffects::worstDefault, "das::HSV")
            ->args({"h","s","v","a"})
                ->arg_init(3,make_smart<ExprConstFloat>(1.0f));
    // imgui draw list
    addExtern<DAS_BIND_FUN(das::AddText)>(*this, lib, "AddText",
        SideEffects::worstDefault, "das::AddText");
    addExtern<DAS_BIND_FUN(das::AddText2)>(*this, lib, "AddText",
        SideEffects::worstDefault, "das::AddText2")
	        ->args({"drawList","font","font_size","pos","col","text","wrap_width","cpu_fine_clip_rect"})
		        ->arg_init(6,make_smart<ExprConstFloat>(0.0f))
		        ->arg_init(7,make_smart<ExprConstPtr>());
    // variadic functions
    addExtern<DAS_BIND_FUN(das::Text)>(*this,lib,"Text",
        SideEffects::worstDefault,"das::Text");
    addExtern<DAS_BIND_FUN(das::TextWrapped)>(*this,lib,"TextWrapped",
        SideEffects::worstDefault,"das::TextWrapped");
    addExtern<DAS_BIND_FUN(das::TextDisabled)>(*this,lib,"TextDisabled",
        SideEffects::worstDefault,"das::TextDisabled");
    addExtern<DAS_BIND_FUN(das::TextColored)>(*this,lib,"TextColored",
        SideEffects::worstDefault,"das::TextColored");
    addExtern<DAS_BIND_FUN(das::LogText)>(*this,lib,"LogText",
        SideEffects::worstDefault,"das::LogText");
    addExtern<DAS_BIND_FUN(das::TreeNode)>(*this,lib,"TreeNode",
        SideEffects::worstDefault,"das::TreeNode");
    addExtern<DAS_BIND_FUN(das::TreeNodeEx)>(*this,lib,"TreeNodeEx",
        SideEffects::worstDefault,"das::TreeNodeEx");
    addExtern<DAS_BIND_FUN(das::TreeNodeEx2)>(*this,lib,"TreeNodeEx",
        SideEffects::worstDefault,"das::TreeNodeEx2");
    addExtern<DAS_BIND_FUN(das::BulletText)>(*this,lib,"BulletText",
        SideEffects::worstDefault,"das::BulletText");
    addExtern<DAS_BIND_FUN(das::SetTooltip)>(*this,lib,"SetTooltip",
        SideEffects::worstDefault,"das::SetTooltip");
    // text unfromatted
    addExtern<DAS_BIND_FUN(das::TextUnformatted)>(*this, lib, "TextUnformatted",
        SideEffects::worstDefault, "das::TextUnformatted")
        ->arg("text");
    // input text
    addExtern<DAS_BIND_FUN(das::InputText)>(*this, lib, "InputText",
        SideEffects::worstDefault, "das::InputText")
            ->arg_init(3, make_smart<ExprConstInt>(0));
#endif
    return true;
}

ModuleAotType Module_imgui::aotRequire ( TextWriter & tw ) const  {
    // add your stuff here
    tw << "#include <imgui.h>\n";
    // specifying AOT type, in this case direct cpp mode (and not hybrid mode)
    return ModuleAotType::cpp;
}

// registering module, so that its available via 'NEED_MODULE' macro
REGISTER_MODULE(Module_imgui);
