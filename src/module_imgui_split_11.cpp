
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
void Module_imgui::initFunctions_11() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::VSliderInt)>(*this, lib, "VSliderInt",SideEffects::worstDefault, "ImGui::VSliderInt")
	->args({"label","size","v","v_min","v_max","format","flags"})
		->arg_init(5,make_smart<ExprConstString>("%d"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(bool, ImGuiCond),ImGui::SetWindowCollapsed>(*this, lib, "SetWindowCollapsed",SideEffects::worstDefault, "ImGui::SetWindowCollapsed")
	->args({"collapsed","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::InputScalar)>(*this, lib, "InputScalar",SideEffects::worstDefault, "ImGui::InputScalar")
	->args({"label","data_type","p_data","p_step","p_step_fast","format","flags"})
		->arg_type(1,makeType<ImGuiDataType_>(lib))
		->arg_init(3,make_smart<ExprConstPtr>())
		->arg_init(4,make_smart<ExprConstPtr>())
		->arg_init(5,make_smart<ExprConstString>(""))
		->arg_type(6,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::GetIO), SimNode_ExtFuncCallRef>(*this, lib, "GetIO",SideEffects::worstDefault, "imnodes::GetIO")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::InputInt4)>(*this, lib, "InputInt4",SideEffects::worstDefault, "ImGui::InputInt4")
	->args({"label","v","flags"})
		->arg_type(2,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SliderScalar)>(*this, lib, "SliderScalar",SideEffects::worstDefault, "ImGui::SliderScalar")
	->args({"label","data_type","p_data","p_min","p_max","format","flags"})
		->arg_type(1,makeType<ImGuiDataType_>(lib))
		->arg_init(5,make_smart<ExprConstString>(""))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SliderFloat4)>(*this, lib, "SliderFloat4",SideEffects::worstDefault, "ImGui::SliderFloat4")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ColorConvertRGBtoHSV)>(*this, lib, "ColorConvertRGBtoHSV",SideEffects::worstDefault, "ImGui::ColorConvertRGBtoHSV")
	->args({"r","g","b","out_h","out_s","out_v"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::InputDouble)>(*this, lib, "InputDouble",SideEffects::worstDefault, "ImGui::InputDouble")
	->args({"label","v","step","step_fast","format","flags"})
		// step : double = 0
		// step_fast : double = 0
		->arg_init(4,make_smart<ExprConstString>("%.6f"))
		->arg_type(5,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, bool, ImGuiSelectableFlags, const ImVec2 &),ImGui::Selectable>(*this, lib, "Selectable",SideEffects::worstDefault, "ImGui::Selectable")
	->args({"label","selected","flags","size"})
		->arg_init(1,make_smart<ExprConstBool>(false))
		->arg_type(2,makeType<ImGuiSelectableFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSelectableFlags_>(lib)))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::IsAnyAttributeActive)>(*this, lib, "IsAnyAttributeActive",SideEffects::worstDefault, "imnodes::IsAnyAttributeActive")
	->args({"attribute_id"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::StyleColorsClassic)>(*this, lib, "StyleColorsClassic",SideEffects::worstDefault, "imnodes::StyleColorsClassic")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetCurrentContext)>(*this, lib, "SetCurrentContext",SideEffects::worstDefault, "ImGui::SetCurrentContext")
	->args({"ctx"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetContentRegionMax)>(*this, lib, "GetContentRegionMax",SideEffects::worstDefault, "ImGui::GetContentRegionMax")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SliderFloat2)>(*this, lib, "SliderFloat2",SideEffects::worstDefault, "ImGui::SliderFloat2")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ColorPicker4)>(*this, lib, "ColorPicker4",SideEffects::worstDefault, "ImGui::ColorPicker4")
	->args({"label","col","flags","ref_col"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)))
		->arg_init(3,make_smart<ExprConstPtr>())
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::IsLinkHovered)>(*this, lib, "IsLinkHovered",SideEffects::worstDefault, "imnodes::IsLinkHovered")
	->args({"link_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::OpenPopupOnItemClick)>(*this, lib, "OpenPopupOnItemClick",SideEffects::worstDefault, "ImGui::OpenPopupOnItemClick")
	->args({"str_id","popup_flags"})
		->arg_init(0,make_smart<ExprConstString>(""))
		->arg_init(1,make_smart<ExprConstInt>(1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DragInt3)>(*this, lib, "DragInt3",SideEffects::worstDefault, "ImGui::DragInt3")
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
addExtern<DAS_BIND_FUN(ImGui::TableSetBgColor)>(*this, lib, "TableSetBgColor",SideEffects::worstDefault, "ImGui::TableSetBgColor")
	->args({"target","color","column_n"})
		->arg_type(0,makeType<ImGuiTableBgTarget_>(lib))
		->arg_init(2,make_smart<ExprConstInt>(-1))
;
#endif

#endif
#endif
}
