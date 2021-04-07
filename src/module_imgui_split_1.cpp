
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
void Module_imgui::initFunctions_1() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const void *),ImGui::PushID>(*this, lib, "PushID",SideEffects::worstDefault, "ImGui::PushID")
	->args({"ptr_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, ImGuiTreeNodeFlags),ImGui::TreeNodeEx>(*this, lib, "TreeNodeEx",SideEffects::worstDefault, "ImGui::TreeNodeEx")
	->args({"label","flags"})
		->arg_type(1,makeType<ImGuiTreeNodeFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTreeNodeFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::CaptureKeyboardFromApp)>(*this, lib, "CaptureKeyboardFromApp",SideEffects::worstDefault, "ImGui::CaptureKeyboardFromApp")
	->args({"want_capture_keyboard_value"})
		->arg_init(0,make_smart<ExprConstBool>(true))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::CaptureMouseFromApp)>(*this, lib, "CaptureMouseFromApp",SideEffects::worstDefault, "ImGui::CaptureMouseFromApp")
	->args({"want_capture_mouse_value"})
		->arg_init(0,make_smart<ExprConstBool>(true))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::PopAttributeFlag)>(*this, lib, "PopAttributeFlag",SideEffects::worstDefault, "imnodes::PopAttributeFlag")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetScrollFromPosX)>(*this, lib, "SetScrollFromPosX",SideEffects::worstDefault, "ImGui::SetScrollFromPosX")
	->args({"local_x","center_x_ratio"})
		->arg_init(1,make_smart<ExprConstFloat>(0.5))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::SetNodeDraggable)>(*this, lib, "SetNodeDraggable",SideEffects::worstDefault, "imnodes::SetNodeDraggable")
	->args({"node_id","draggable"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::NewFrame)>(*this, lib, "NewFrame",SideEffects::worstDefault, "ImGui::NewFrame")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, int *, int),ImGui::RadioButton>(*this, lib, "RadioButton",SideEffects::worstDefault, "ImGui::RadioButton")
	->args({"label","v","v_button"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ArrowButton)>(*this, lib, "ArrowButton",SideEffects::worstDefault, "ImGui::ArrowButton")
	->args({"str_id","dir"})
		->arg_type(1,makeType<ImGuiDir_>(lib))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetScrollX)>(*this, lib, "GetScrollX",SideEffects::worstDefault, "ImGui::GetScrollX")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowFocus)>(*this, lib, "SetNextWindowFocus",SideEffects::worstDefault, "ImGui::SetNextWindowFocus")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetWindowDrawList)>(*this, lib, "GetWindowDrawList",SideEffects::worstDefault, "ImGui::GetWindowDrawList")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::LoadIniSettingsFromMemory)>(*this, lib, "LoadIniSettingsFromMemory",SideEffects::worstDefault, "ImGui::LoadIniSettingsFromMemory")
	->args({"ini_data","ini_size"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::GetCurrentContext)>(*this, lib, "GetCurrentContext",SideEffects::worstDefault, "imnodes::GetCurrentContext")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::BeginStaticAttribute)>(*this, lib, "BeginStaticAttribute",SideEffects::worstDefault, "imnodes::BeginStaticAttribute")
	->args({"id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginCombo)>(*this, lib, "BeginCombo",SideEffects::worstDefault, "ImGui::BeginCombo")
	->args({"label","preview_value","flags"})
		->arg_type(2,makeType<ImGuiComboFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiComboFlags_>(lib)))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::NumSelectedLinks)>(*this, lib, "NumSelectedLinks",SideEffects::worstDefault, "imnodes::NumSelectedLinks")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetNextItemOpen)>(*this, lib, "SetNextItemOpen",SideEffects::worstDefault, "ImGui::SetNextItemOpen")
	->args({"is_open","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsItemClicked)>(*this, lib, "IsItemClicked",SideEffects::worstDefault, "ImGui::IsItemClicked")
	->args({"mouse_button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiMouseButton_>(lib)))
;
#endif

#endif
#endif
}
