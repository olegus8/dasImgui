
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
void Module_imgui::initFunctions_9() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetColumnOffset)>(*this, lib, "GetColumnOffset",SideEffects::worstDefault, "ImGui::GetColumnOffset")
	->args({"column_index"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::GetNodeGridSpacePos)>(*this, lib, "GetNodeGridSpacePos",SideEffects::worstDefault, "imnodes::GetNodeGridSpacePos")
	->args({"node_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DragInt4)>(*this, lib, "DragInt4",SideEffects::worstDefault, "ImGui::DragInt4")
	->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1))
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstString>("%d"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginPopupContextItem)>(*this, lib, "BeginPopupContextItem",SideEffects::worstDefault, "ImGui::BeginPopupContextItem")
	->args({"str_id","popup_flags"})
		->arg_init(0,make_smart<ExprConstString>(""))
		->arg_init(1,make_smart<ExprConstInt>(1))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::GetSelectedNodes)>(*this, lib, "GetSelectedNodes",SideEffects::worstDefault, "imnodes::GetSelectedNodes")
	->args({"node_ids"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::SaveEditorStateToIniString)>(*this, lib, "SaveEditorStateToIniString",SideEffects::worstDefault, "imnodes::SaveEditorStateToIniString")
	->args({"editor","data_size"})
		->arg_init(1,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(ImGuiStyleVar, const ImVec2 &),ImGui::PushStyleVar>(*this, lib, "PushStyleVar",SideEffects::worstDefault, "ImGui::PushStyleVar")
	->args({"idx","val"})
		->arg_type(0,makeType<ImGuiStyleVar_>(lib))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::StyleColorsLight)>(*this, lib, "StyleColorsLight",SideEffects::worstDefault, "imnodes::StyleColorsLight")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::EndNodeEditor)>(*this, lib, "EndNodeEditor",SideEffects::worstDefault, "imnodes::EndNodeEditor")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetWindowContentRegionMax)>(*this, lib, "GetWindowContentRegionMax",SideEffects::worstDefault, "ImGui::GetWindowContentRegionMax")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ShowStyleSelector)>(*this, lib, "ShowStyleSelector",SideEffects::worstDefault, "ImGui::ShowStyleSelector")
	->args({"label"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetScrollHereX)>(*this, lib, "SetScrollHereX",SideEffects::worstDefault, "ImGui::SetScrollHereX")
	->args({"center_x_ratio"})
		->arg_init(0,make_smart<ExprConstFloat>(0.5))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SliderFloat3)>(*this, lib, "SliderFloat3",SideEffects::worstDefault, "ImGui::SliderFloat3")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetCursorPosY)>(*this, lib, "GetCursorPosY",SideEffects::worstDefault, "ImGui::GetCursorPosY")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PopTextWrapPos)>(*this, lib, "PopTextWrapPos",SideEffects::worstDefault, "ImGui::PopTextWrapPos")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetContentRegionAvail)>(*this, lib, "GetContentRegionAvail",SideEffects::worstDefault, "ImGui::GetContentRegionAvail")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PopItemWidth)>(*this, lib, "PopItemWidth",SideEffects::worstDefault, "ImGui::PopItemWidth")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SliderInt)>(*this, lib, "SliderInt",SideEffects::worstDefault, "ImGui::SliderInt")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%d"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TableGetSortSpecs)>(*this, lib, "TableGetSortSpecs",SideEffects::worstDefault, "ImGui::TableGetSortSpecs")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsAnyItemHovered)>(*this, lib, "IsAnyItemHovered",SideEffects::worstDefault, "ImGui::IsAnyItemHovered")
	->args({})
;
#endif

#endif
#endif
}
