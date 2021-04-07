
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
void Module_imgui::initFunctions_0() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ShowStyleEditor)>(*this, lib, "ShowStyleEditor",SideEffects::worstDefault, "ImGui::ShowStyleEditor")
	->args({"ref"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, bool *, ImGuiSelectableFlags, const ImVec2 &),ImGui::Selectable>(*this, lib, "Selectable",SideEffects::worstDefault, "ImGui::Selectable")
	->args({"label","p_selected","flags","size"})
		->arg_type(2,makeType<ImGuiSelectableFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSelectableFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginTabBar)>(*this, lib, "BeginTabBar",SideEffects::worstDefault, "ImGui::BeginTabBar")
	->args({"str_id","flags"})
		->arg_type(1,makeType<ImGuiTabBarFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTabBarFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndDragDropTarget)>(*this, lib, "EndDragDropTarget",SideEffects::worstDefault, "ImGui::EndDragDropTarget")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::EditorContextSet)>(*this, lib, "EditorContextSet",SideEffects::worstDefault, "imnodes::EditorContextSet")
	->args({"arg0"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetFrameCount)>(*this, lib, "GetFrameCount",SideEffects::worstDefault, "ImGui::GetFrameCount")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::CalcListClipping)>(*this, lib, "CalcListClipping",SideEffects::worstDefault, "ImGui::CalcListClipping")
	->args({"items_count","items_height","out_items_display_start","out_items_display_end"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DragScalar)>(*this, lib, "DragScalar",SideEffects::worstDefault, "ImGui::DragScalar")
	->args({"label","data_type","p_data","v_speed","p_min","p_max","format","flags"})
		->arg_type(1,makeType<ImGuiDataType_>(lib))
		->arg_init(4,make_smart<ExprConstPtr>())
		->arg_init(5,make_smart<ExprConstPtr>())
		->arg_init(6,make_smart<ExprConstString>(""))
		->arg_type(7,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(7,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetKeyboardFocusHere)>(*this, lib, "SetKeyboardFocusHere",SideEffects::worstDefault, "ImGui::SetKeyboardFocusHere")
	->args({"offset"})
		->arg_init(0,make_smart<ExprConstInt>(0))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowPos)>(*this, lib, "SetNextWindowPos",SideEffects::worstDefault, "ImGui::SetNextWindowPos")
	->args({"pos","cond","pivot"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsItemHovered)>(*this, lib, "IsItemHovered",SideEffects::worstDefault, "ImGui::IsItemHovered")
	->args({"flags"})
		->arg_type(0,makeType<ImGuiHoveredFlags_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiHoveredFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetWindowContentRegionWidth)>(*this, lib, "GetWindowContentRegionWidth",SideEffects::worstDefault, "ImGui::GetWindowContentRegionWidth")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *, bool),ImGui::Value>(*this, lib, "Value",SideEffects::worstDefault, "ImGui::Value")
	->args({"prefix","b"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndPopup)>(*this, lib, "EndPopup",SideEffects::worstDefault, "ImGui::EndPopup")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(ImGuiCol, const ImVec4 &),ImGui::PushStyleColor>(*this, lib, "PushStyleColor",SideEffects::worstDefault, "ImGui::PushStyleColor")
	->args({"idx","col"})
		->arg_type(0,makeType<ImGuiCol_>(lib))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::VSliderScalar)>(*this, lib, "VSliderScalar",SideEffects::worstDefault, "ImGui::VSliderScalar")
	->args({"label","size","data_type","p_data","p_min","p_max","format","flags"})
		->arg_type(2,makeType<ImGuiDataType_>(lib))
		->arg_init(6,make_smart<ExprConstString>(""))
		->arg_type(7,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(7,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *),ImGui::TreePush>(*this, lib, "TreePush",SideEffects::worstDefault, "ImGui::TreePush")
	->args({"str_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::StyleColorsLight)>(*this, lib, "StyleColorsLight",SideEffects::worstDefault, "ImGui::StyleColorsLight")
	->args({"dst"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TableGetColumnFlags)>(*this, lib, "TableGetColumnFlags",SideEffects::worstDefault, "ImGui::TableGetColumnFlags")
	->args({"column_n"})
		->res_type(makeType<ImGuiTableColumnFlags_>(lib))
		->arg_init(0,make_smart<ExprConstInt>(-1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsItemActivated)>(*this, lib, "IsItemActivated",SideEffects::worstDefault, "ImGui::IsItemActivated")
	->args({})
;
#endif

#endif
#endif
}
