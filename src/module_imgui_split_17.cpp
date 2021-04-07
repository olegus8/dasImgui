
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
void Module_imgui::initFunctions_17() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::SetCurrentContext)>(*this, lib, "SetCurrentContext",SideEffects::worstDefault, "imnodes::SetCurrentContext")
	->args({"ctx"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndChild)>(*this, lib, "EndChild",SideEffects::worstDefault, "ImGui::EndChild")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<bool (*)(int *, int *, int *, int *, bool *),imnodes::IsLinkCreated>(*this, lib, "IsLinkCreated",SideEffects::worstDefault, "imnodes::IsLinkCreated")
	->args({"started_at_node_id","started_at_attribute_id","ended_at_node_id","ended_at_attribute_id","created_from_snap"})
		->arg_init(4,make_smart<ExprConstPtr>())
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<bool (*)(int *, int *, bool *),imnodes::IsLinkCreated>(*this, lib, "IsLinkCreated",SideEffects::worstDefault, "imnodes::IsLinkCreated")
	->args({"started_at_attribute_id","ended_at_attribute_id","created_from_snap"})
		->arg_init(2,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TableGetColumnCount)>(*this, lib, "TableGetColumnCount",SideEffects::worstDefault, "ImGui::TableGetColumnCount")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginChildFrame)>(*this, lib, "BeginChildFrame",SideEffects::worstDefault, "ImGui::BeginChildFrame")
	->args({"id","size","flags"})
		->arg_type(2,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PushItemWidth)>(*this, lib, "PushItemWidth",SideEffects::worstDefault, "ImGui::PushItemWidth")
	->args({"item_width"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetFontTexUvWhitePixel)>(*this, lib, "GetFontTexUvWhitePixel",SideEffects::worstDefault, "ImGui::GetFontTexUvWhitePixel")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::Checkbox)>(*this, lib, "Checkbox",SideEffects::worstDefault, "ImGui::Checkbox")
	->args({"label","v"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::BeginNodeEditor)>(*this, lib, "BeginNodeEditor",SideEffects::worstDefault, "imnodes::BeginNodeEditor")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::GetNodeScreenSpacePos)>(*this, lib, "GetNodeScreenSpacePos",SideEffects::worstDefault, "imnodes::GetNodeScreenSpacePos")
	->args({"node_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetDragDropPayload)>(*this, lib, "SetDragDropPayload",SideEffects::worstDefault, "ImGui::SetDragDropPayload")
	->args({"type","data","sz","cond"})
		->arg_type(3,makeType<ImGuiCond_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetVersion)>(*this, lib, "GetVersion",SideEffects::worstDefault, "ImGui::GetVersion")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::BeginNodeTitleBar)>(*this, lib, "BeginNodeTitleBar",SideEffects::worstDefault, "imnodes::BeginNodeTitleBar")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, int *, const char *const *, int, int),ImGui::Combo>(*this, lib, "Combo",SideEffects::worstDefault, "ImGui::Combo")
	->args({"label","current_item","items","items_count","popup_max_height_in_items"})
		->arg_init(4,make_smart<ExprConstInt>(-1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetColumnsCount)>(*this, lib, "GetColumnsCount",SideEffects::worstDefault, "ImGui::GetColumnsCount")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::AlignTextToFramePadding)>(*this, lib, "AlignTextToFramePadding",SideEffects::worstDefault, "ImGui::AlignTextToFramePadding")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *, const ImVec2 &, ImGuiCond),ImGui::SetWindowPos>(*this, lib, "SetWindowPos",SideEffects::worstDefault, "ImGui::SetWindowPos")
	->args({"name","pos","cond"})
		->arg_type(2,makeType<ImGuiCond_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetIO), SimNode_ExtFuncCallRef>(*this, lib, "GetIO",SideEffects::worstDefault, "ImGui::GetIO")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndGroup)>(*this, lib, "EndGroup",SideEffects::worstDefault, "ImGui::EndGroup")
	->args({})
;
#endif

#endif
#endif
}
