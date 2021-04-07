
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
void Module_imgui::initFunctions_5() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetScrollX)>(*this, lib, "SetScrollX",SideEffects::worstDefault, "ImGui::SetScrollX")
	->args({"scroll_x"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<ImU32 (*)(const ImVec4 &),ImGui::GetColorU32>(*this, lib, "GetColorU32",SideEffects::worstDefault, "ImGui::GetColorU32")
	->args({"col"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetColumnIndex)>(*this, lib, "GetColumnIndex",SideEffects::worstDefault, "ImGui::GetColumnIndex")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(int),ImGui::PushID>(*this, lib, "PushID",SideEffects::worstDefault, "ImGui::PushID")
	->args({"int_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TableGetColumnName)>(*this, lib, "TableGetColumnName",SideEffects::worstDefault, "ImGui::TableGetColumnName")
	->args({"column_n"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetFont)>(*this, lib, "GetFont",SideEffects::worstDefault, "ImGui::GetFont")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ColorEdit4)>(*this, lib, "ColorEdit4",SideEffects::worstDefault, "ImGui::ColorEdit4")
	->args({"label","col","flags"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PushAllowKeyboardFocus)>(*this, lib, "PushAllowKeyboardFocus",SideEffects::worstDefault, "ImGui::PushAllowKeyboardFocus")
	->args({"allow_keyboard_focus"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowContentSize)>(*this, lib, "SetNextWindowContentSize",SideEffects::worstDefault, "ImGui::SetNextWindowContentSize")
	->args({"size"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::InputFloat4)>(*this, lib, "InputFloat4",SideEffects::worstDefault, "ImGui::InputFloat4")
	->args({"label","v","format","flags"})
		->arg_init(2,make_smart<ExprConstString>("%.3f"))
		->arg_type(3,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::GetNodeDimensions)>(*this, lib, "GetNodeDimensions",SideEffects::worstDefault, "imnodes::GetNodeDimensions")
	->args({"id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::Image)>(*this, lib, "Image",SideEffects::worstDefault, "ImGui::Image")
	->args({"user_texture_id","size","uv0","uv1","tint_col","border_col"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::IsEditorHovered)>(*this, lib, "IsEditorHovered",SideEffects::worstDefault, "imnodes::IsEditorHovered")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::IsNodeHovered)>(*this, lib, "IsNodeHovered",SideEffects::worstDefault, "imnodes::IsNodeHovered")
	->args({"node_id"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::IsAttributeActive)>(*this, lib, "IsAttributeActive",SideEffects::worstDefault, "imnodes::IsAttributeActive")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::SaveCurrentEditorStateToIniString)>(*this, lib, "SaveCurrentEditorStateToIniString",SideEffects::worstDefault, "imnodes::SaveCurrentEditorStateToIniString")
	->args({"data_size"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginDragDropSource)>(*this, lib, "BeginDragDropSource",SideEffects::worstDefault, "ImGui::BeginDragDropSource")
	->args({"flags"})
		->arg_type(0,makeType<ImGuiDragDropFlags_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiDragDropFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DragFloatRange2)>(*this, lib, "DragFloatRange2",SideEffects::worstDefault, "ImGui::DragFloatRange2")
	->args({"label","v_current_min","v_current_max","v_speed","v_min","v_max","format","format_max","flags"})
		->arg_init(3,make_smart<ExprConstFloat>(1))
		->arg_init(4,make_smart<ExprConstFloat>(0))
		->arg_init(5,make_smart<ExprConstFloat>(0))
		->arg_init(6,make_smart<ExprConstString>("%.3f"))
		->arg_init(7,make_smart<ExprConstString>(""))
		->arg_type(8,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(8,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ColorButton)>(*this, lib, "ColorButton",SideEffects::worstDefault, "ImGui::ColorButton")
	->args({"desc_id","col","flags","size"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetTime)>(*this, lib, "GetTime",SideEffects::worstDefault, "ImGui::GetTime")
	->args({})
;
#endif

#endif
#endif
}
