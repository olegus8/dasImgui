
#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "imgui_stub.h"
#include "imnodes_stub.h"
using namespace das;
#include "need_imgui.h"
#include "need_imnodes.h"
#if USE_GENERATED
#define GLOBAL_NAMESPACE    1
#include "module_imgui.h"
#endif
void Module_imgui::initFunctions_6() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsWindowCollapsed)>(*this, lib, "IsWindowCollapsed",SideEffects::worstDefault, "ImGui::IsWindowCollapsed")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TableSetupColumn)>(*this, lib, "TableSetupColumn",SideEffects::worstDefault, "ImGui::TableSetupColumn")
	->args({"label","flags","init_width_or_weight","user_id"})
		->arg_type(1,makeType<ImGuiTableColumnFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTableColumnFlags_>(lib)))
		->arg_init(2,make_smart<ExprConstFloat>(0))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::Render)>(*this, lib, "Render",SideEffects::worstDefault, "ImGui::Render")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::LoadEditorStateFromIniFile)>(*this, lib, "LoadEditorStateFromIniFile",SideEffects::worstDefault, "imnodes::LoadEditorStateFromIniFile")
	->args({"editor","file_name"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetStyle), SimNode_ExtFuncCallRef>(*this, lib, "GetStyle",SideEffects::worstDefault, "ImGui::GetStyle")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndFrame)>(*this, lib, "EndFrame",SideEffects::worstDefault, "ImGui::EndFrame")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PopStyleColor)>(*this, lib, "PopStyleColor",SideEffects::worstDefault, "ImGui::PopStyleColor")
	->args({"count"})
		->arg_init(0,make_smart<ExprConstInt>(1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, int *, const char *, int),ImGui::Combo>(*this, lib, "Combo",SideEffects::worstDefault, "ImGui::Combo")
	->args({"label","current_item","items_separated_by_zeros","popup_max_height_in_items"})
		->arg_init(3,make_smart<ExprConstInt>(-1))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::IsPinHovered)>(*this, lib, "IsPinHovered",SideEffects::worstDefault, "imnodes::IsPinHovered")
	->args({"attribute_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetDragDropPayload)>(*this, lib, "GetDragDropPayload",SideEffects::worstDefault, "ImGui::GetDragDropPayload")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::GetNodeEditorSpacePos)>(*this, lib, "GetNodeEditorSpacePos",SideEffects::worstDefault, "imnodes::GetNodeEditorSpacePos")
	->args({"node_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ImageButton)>(*this, lib, "ImageButton",SideEffects::worstDefault, "ImGui::ImageButton")
	->args({"user_texture_id","size","uv0","uv1","frame_padding","bg_col","tint_col"})
		->arg_init(4,make_smart<ExprConstInt>(-1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::MemAlloc)>(*this, lib, "MemAlloc",SideEffects::worstDefault, "ImGui::MemAlloc")
	->args({"size"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DestroyContext)>(*this, lib, "DestroyContext",SideEffects::worstDefault, "ImGui::DestroyContext")
	->args({"ctx"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetScrollHereY)>(*this, lib, "SetScrollHereY",SideEffects::worstDefault, "ImGui::SetScrollHereY")
	->args({"center_y_ratio"})
		->arg_init(0,make_smart<ExprConstFloat>(0.5))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TableSetColumnIndex)>(*this, lib, "TableSetColumnIndex",SideEffects::worstDefault, "ImGui::TableSetColumnIndex")
	->args({"column_n"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::EditorContextFree)>(*this, lib, "EditorContextFree",SideEffects::worstDefault, "imnodes::EditorContextFree")
	->args({"arg0"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, unsigned int *, unsigned int),ImGui::CheckboxFlags>(*this, lib, "CheckboxFlags",SideEffects::worstDefault, "ImGui::CheckboxFlags")
	->args({"label","flags","flags_value"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, const ImVec2 &, bool, ImGuiWindowFlags),ImGui::BeginChild>(*this, lib, "BeginChild",SideEffects::worstDefault, "ImGui::BeginChild")
	->args({"str_id","size","border","flags"})
		->arg_init(2,make_smart<ExprConstBool>(false))
		->arg_type(3,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const ImVec2 &, ImGuiCond),ImGui::SetWindowSize>(*this, lib, "SetWindowSize",SideEffects::worstDefault, "ImGui::SetWindowSize")
	->args({"size","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
#endif

#endif
#endif
}
