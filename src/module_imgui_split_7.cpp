
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
void Module_imgui::initFunctions_7() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetScrollMaxY)>(*this, lib, "GetScrollMaxY",SideEffects::worstDefault, "ImGui::GetScrollMaxY")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DragScalarN)>(*this, lib, "DragScalarN",SideEffects::worstDefault, "ImGui::DragScalarN")
	->args({"label","data_type","p_data","components","v_speed","p_min","p_max","format","flags"})
		->arg_type(1,makeType<ImGuiDataType_>(lib))
		->arg_init(5,make_smart<ExprConstPtr>())
		->arg_init(6,make_smart<ExprConstPtr>())
		->arg_init(7,make_smart<ExprConstString>(""))
		->arg_type(8,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(8,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetScrollMaxX)>(*this, lib, "GetScrollMaxX",SideEffects::worstDefault, "ImGui::GetScrollMaxX")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::InputFloat)>(*this, lib, "InputFloat",SideEffects::worstDefault, "ImGui::InputFloat")
	->args({"label","v","step","step_fast","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(0))
		->arg_init(3,make_smart<ExprConstFloat>(0))
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginListBox)>(*this, lib, "BeginListBox",SideEffects::worstDefault, "ImGui::BeginListBox")
	->args({"label","size"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowSize)>(*this, lib, "SetNextWindowSize",SideEffects::worstDefault, "ImGui::SetNextWindowSize")
	->args({"size","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::Spacing)>(*this, lib, "Spacing",SideEffects::worstDefault, "ImGui::Spacing")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::Columns)>(*this, lib, "Columns",SideEffects::worstDefault, "ImGui::Columns")
	->args({"count","id","border"})
		->arg_init(0,make_smart<ExprConstInt>(1))
		->arg_init(1,make_smart<ExprConstString>(""))
		->arg_init(2,make_smart<ExprConstBool>(true))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetColumnWidth)>(*this, lib, "SetColumnWidth",SideEffects::worstDefault, "ImGui::SetColumnWidth")
	->args({"column_index","width"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::CalcItemWidth)>(*this, lib, "CalcItemWidth",SideEffects::worstDefault, "ImGui::CalcItemWidth")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::Button)>(*this, lib, "Button",SideEffects::worstDefault, "ImGui::Button")
	->args({"label","size"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::LogButtons)>(*this, lib, "LogButtons",SideEffects::worstDefault, "ImGui::LogButtons")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetStateStorage)>(*this, lib, "SetStateStorage",SideEffects::worstDefault, "ImGui::SetStateStorage")
	->args({"storage"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetCursorPosX)>(*this, lib, "GetCursorPosX",SideEffects::worstDefault, "ImGui::GetCursorPosX")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndTooltip)>(*this, lib, "EndTooltip",SideEffects::worstDefault, "ImGui::EndTooltip")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndChildFrame)>(*this, lib, "EndChildFrame",SideEffects::worstDefault, "ImGui::EndChildFrame")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ColorConvertU32ToFloat4)>(*this, lib, "ColorConvertU32ToFloat4",SideEffects::worstDefault, "ImGui::ColorConvertU32ToFloat4")
	->args({"in"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetKeyIndex)>(*this, lib, "GetKeyIndex",SideEffects::worstDefault, "ImGui::GetKeyIndex")
	->args({"imgui_key"})
		->arg_type(0,makeType<ImGuiKey_>(lib))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsMouseHoveringRect)>(*this, lib, "IsMouseHoveringRect",SideEffects::worstDefault, "ImGui::IsMouseHoveringRect")
	->args({"r_min","r_max","clip"})
		->arg_init(2,make_smart<ExprConstBool>(true))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsAnyMouseDown)>(*this, lib, "IsAnyMouseDown",SideEffects::worstDefault, "ImGui::IsAnyMouseDown")
	->args({})
;
#endif

#endif
#endif
}
