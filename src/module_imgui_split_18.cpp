
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
void Module_imgui::initFunctions_18() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, int *, int),ImGui::CheckboxFlags>(*this, lib, "CheckboxFlags",SideEffects::worstDefault, "ImGui::CheckboxFlags")
	->args({"label","flags","flags_value"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::CloseCurrentPopup)>(*this, lib, "CloseCurrentPopup",SideEffects::worstDefault, "ImGui::CloseCurrentPopup")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TableNextRow)>(*this, lib, "TableNextRow",SideEffects::worstDefault, "ImGui::TableNextRow")
	->args({"row_flags","min_row_height"})
		->arg_type(0,makeType<ImGuiTableRowFlags_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTableRowFlags_>(lib)))
		->arg_init(1,make_smart<ExprConstFloat>(0))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DragFloat2)>(*this, lib, "DragFloat2",SideEffects::worstDefault, "ImGui::DragFloat2")
	->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1))
		->arg_init(3,make_smart<ExprConstFloat>(0))
		->arg_init(4,make_smart<ExprConstFloat>(0))
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsItemActive)>(*this, lib, "IsItemActive",SideEffects::worstDefault, "ImGui::IsItemActive")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DragInt)>(*this, lib, "DragInt",SideEffects::worstDefault, "ImGui::DragInt")
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
addExtern<DAS_BIND_FUN(ImGui::SetScrollY)>(*this, lib, "SetScrollY",SideEffects::worstDefault, "ImGui::SetScrollY")
	->args({"scroll_y"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<ImGuiID (*)(const char *, const char *),ImGui::GetID>(*this, lib, "GetID",SideEffects::worstDefault, "ImGui::GetID")
	->args({"str_id_begin","str_id_end"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::NewLine)>(*this, lib, "NewLine",SideEffects::worstDefault, "ImGui::NewLine")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ColorPicker3)>(*this, lib, "ColorPicker3",SideEffects::worstDefault, "ImGui::ColorPicker3")
	->args({"label","col","flags"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ColorConvertFloat4ToU32)>(*this, lib, "ColorConvertFloat4ToU32",SideEffects::worstDefault, "ImGui::ColorConvertFloat4ToU32")
	->args({"in"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::End)>(*this, lib, "End",SideEffects::worstDefault, "ImGui::End")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetCursorPos)>(*this, lib, "SetCursorPos",SideEffects::worstDefault, "ImGui::SetCursorPos")
	->args({"local_pos"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SliderInt4)>(*this, lib, "SliderInt4",SideEffects::worstDefault, "ImGui::SliderInt4")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%d"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::InputScalarN)>(*this, lib, "InputScalarN",SideEffects::worstDefault, "ImGui::InputScalarN")
	->args({"label","data_type","p_data","components","p_step","p_step_fast","format","flags"})
		->arg_type(1,makeType<ImGuiDataType_>(lib))
		->arg_init(4,make_smart<ExprConstPtr>())
		->arg_init(5,make_smart<ExprConstPtr>())
		->arg_init(6,make_smart<ExprConstString>(""))
		->arg_type(7,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(7,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetMouseDragDelta)>(*this, lib, "GetMouseDragDelta",SideEffects::worstDefault, "ImGui::GetMouseDragDelta")
	->args({"button","lock_threshold"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiMouseButton_>(lib)))
		->arg_init(1,make_smart<ExprConstFloat>(-1))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::SetNodeScreenSpacePos)>(*this, lib, "SetNodeScreenSpacePos",SideEffects::worstDefault, "imnodes::SetNodeScreenSpacePos")
	->args({"node_id","screen_space_pos"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::NumSelectedNodes)>(*this, lib, "NumSelectedNodes",SideEffects::worstDefault, "imnodes::NumSelectedNodes")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *, const char *),ImGui::PushID>(*this, lib, "PushID",SideEffects::worstDefault, "ImGui::PushID")
	->args({"str_id_begin","str_id_end"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginTable)>(*this, lib, "BeginTable",SideEffects::worstDefault, "ImGui::BeginTable")
	->args({"str_id","column","flags","outer_size","inner_width"})
		->arg_type(2,makeType<ImGuiTableFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTableFlags_>(lib)))
		->arg_init(4,make_smart<ExprConstFloat>(0))
;
#endif

#endif
#endif
}
