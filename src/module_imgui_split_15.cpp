
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
void Module_imgui::initFunctions_15() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::InputInt3)>(*this, lib, "InputInt3",SideEffects::worstDefault, "ImGui::InputInt3")
	->args({"label","v","flags"})
		->arg_type(2,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::IsLinkDestroyed)>(*this, lib, "IsLinkDestroyed",SideEffects::worstDefault, "imnodes::IsLinkDestroyed")
	->args({"link_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::InvisibleButton)>(*this, lib, "InvisibleButton",SideEffects::worstDefault, "ImGui::InvisibleButton")
	->args({"str_id","size","flags"})
		->arg_type(2,makeType<ImGuiButtonFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiButtonFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetStyleColorVec4), SimNode_ExtFuncCallRef>(*this, lib, "GetStyleColorVec4",SideEffects::worstDefault, "ImGui::GetStyleColorVec4")
	->args({"idx"})
		->arg_type(0,makeType<ImGuiCol_>(lib))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsAnyItemFocused)>(*this, lib, "IsAnyItemFocused",SideEffects::worstDefault, "ImGui::IsAnyItemFocused")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::InputFloat2)>(*this, lib, "InputFloat2",SideEffects::worstDefault, "ImGui::InputFloat2")
	->args({"label","v","format","flags"})
		->arg_init(2,make_smart<ExprConstString>("%.3f"))
		->arg_type(3,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginPopup)>(*this, lib, "BeginPopup",SideEffects::worstDefault, "ImGui::BeginPopup")
	->args({"str_id","flags"})
		->arg_type(1,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetBackgroundDrawList)>(*this, lib, "GetBackgroundDrawList",SideEffects::worstDefault, "ImGui::GetBackgroundDrawList")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetStyleColorName)>(*this, lib, "GetStyleColorName",SideEffects::worstDefault, "ImGui::GetStyleColorName")
	->args({"idx"})
		->arg_type(0,makeType<ImGuiCol_>(lib))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::SaveEditorStateToIniFile)>(*this, lib, "SaveEditorStateToIniFile",SideEffects::worstDefault, "imnodes::SaveEditorStateToIniFile")
	->args({"editor","file_name"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SliderScalarN)>(*this, lib, "SliderScalarN",SideEffects::worstDefault, "ImGui::SliderScalarN")
	->args({"label","data_type","p_data","components","p_min","p_max","format","flags"})
		->arg_type(1,makeType<ImGuiDataType_>(lib))
		->arg_init(6,make_smart<ExprConstString>(""))
		->arg_type(7,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(7,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsItemDeactivated)>(*this, lib, "IsItemDeactivated",SideEffects::worstDefault, "ImGui::IsItemDeactivated")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, ImGuiTreeNodeFlags),ImGui::CollapsingHeader>(*this, lib, "CollapsingHeader",SideEffects::worstDefault, "ImGui::CollapsingHeader")
	->args({"label","flags"})
		->arg_type(1,makeType<ImGuiTreeNodeFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTreeNodeFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::StyleColorsDark)>(*this, lib, "StyleColorsDark",SideEffects::worstDefault, "ImGui::StyleColorsDark")
	->args({"dst"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndCombo)>(*this, lib, "EndCombo",SideEffects::worstDefault, "ImGui::EndCombo")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsMouseDragging)>(*this, lib, "IsMouseDragging",SideEffects::worstDefault, "ImGui::IsMouseDragging")
	->args({"button","lock_threshold"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(1,make_smart<ExprConstFloat>(-1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndTabItem)>(*this, lib, "EndTabItem",SideEffects::worstDefault, "ImGui::EndTabItem")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetForegroundDrawList)>(*this, lib, "GetForegroundDrawList",SideEffects::worstDefault, "ImGui::GetForegroundDrawList")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetCursorPos)>(*this, lib, "GetCursorPos",SideEffects::worstDefault, "ImGui::GetCursorPos")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsItemEdited)>(*this, lib, "IsItemEdited",SideEffects::worstDefault, "ImGui::IsItemEdited")
	->args({})
;
#endif

#endif
#endif
}
