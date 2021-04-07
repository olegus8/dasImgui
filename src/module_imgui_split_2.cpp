
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
void Module_imgui::initFunctions_2() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetItemDefaultFocus)>(*this, lib, "SetItemDefaultFocus",SideEffects::worstDefault, "ImGui::SetItemDefaultFocus")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, int *, bool (*)(void *, int, const char **), void *, int, int),ImGui::ListBox>(*this, lib, "ListBox",SideEffects::worstDefault, "ImGui::ListBox")
	->args({"label","current_item","items_getter","data","items_count","height_in_items"})
		->arg_init(5,make_smart<ExprConstInt>(-1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginTabItem)>(*this, lib, "BeginTabItem",SideEffects::worstDefault, "ImGui::BeginTabItem")
	->args({"label","p_open","flags"})
		->arg_init(1,make_smart<ExprConstPtr>())
		->arg_type(2,makeType<ImGuiTabItemFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTabItemFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *, int),ImGui::Value>(*this, lib, "Value",SideEffects::worstDefault, "ImGui::Value")
	->args({"prefix","v"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsAnyItemActive)>(*this, lib, "IsAnyItemActive",SideEffects::worstDefault, "ImGui::IsAnyItemActive")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::GetSelectedLinks)>(*this, lib, "GetSelectedLinks",SideEffects::worstDefault, "imnodes::GetSelectedLinks")
	->args({"link_ids"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::EditorContextResetPanning)>(*this, lib, "EditorContextResetPanning",SideEffects::worstDefault, "imnodes::EditorContextResetPanning")
	->args({"pos"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::SaveCurrentEditorStateToIniFile)>(*this, lib, "SaveCurrentEditorStateToIniFile",SideEffects::worstDefault, "imnodes::SaveCurrentEditorStateToIniFile")
	->args({"file_name"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *),ImGui::SetWindowFocus>(*this, lib, "SetWindowFocus",SideEffects::worstDefault, "ImGui::SetWindowFocus")
	->args({"name"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::Unindent)>(*this, lib, "Unindent",SideEffects::worstDefault, "ImGui::Unindent")
	->args({"indent_w"})
		->arg_init(0,make_smart<ExprConstFloat>(0))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TableSetupScrollFreeze)>(*this, lib, "TableSetupScrollFreeze",SideEffects::worstDefault, "ImGui::TableSetupScrollFreeze")
	->args({"cols","rows"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsItemDeactivatedAfterEdit)>(*this, lib, "IsItemDeactivatedAfterEdit",SideEffects::worstDefault, "ImGui::IsItemDeactivatedAfterEdit")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetAllocatorFunctions)>(*this, lib, "SetAllocatorFunctions",SideEffects::worstDefault, "ImGui::SetAllocatorFunctions")
	->args({"alloc_func","free_func","user_data"})
		->arg_init(2,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *, float (*)(void *, int), void *, int, int, const char *, float, float, ImVec2),ImGui::PlotHistogram>(*this, lib, "PlotHistogram",SideEffects::worstDefault, "ImGui::PlotHistogram")
	->args({"label","values_getter","data","values_count","values_offset","overlay_text","scale_min","scale_max","graph_size"})
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstString>(""))
		->arg_init(6,make_smart<ExprConstFloat>(3.40282347E+38))
		->arg_init(7,make_smart<ExprConstFloat>(3.40282347E+38))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::LoadCurrentEditorStateFromIniString)>(*this, lib, "LoadCurrentEditorStateFromIniString",SideEffects::worstDefault, "imnodes::LoadCurrentEditorStateFromIniString")
	->args({"data","data_size"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::EditorContextCreate)>(*this, lib, "EditorContextCreate",SideEffects::worstDefault, "imnodes::EditorContextCreate")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ShowMetricsWindow)>(*this, lib, "ShowMetricsWindow",SideEffects::worstDefault, "ImGui::ShowMetricsWindow")
	->args({"p_open"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(ImGuiStyleVar, float),ImGui::PushStyleVar>(*this, lib, "PushStyleVar",SideEffects::worstDefault, "ImGui::PushStyleVar")
	->args({"idx","val"})
		->arg_type(0,makeType<ImGuiStyleVar_>(lib))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, int *, bool (*)(void *, int, const char **), void *, int, int),ImGui::Combo>(*this, lib, "Combo",SideEffects::worstDefault, "ImGui::Combo")
	->args({"label","current_item","items_getter","data","items_count","popup_max_height_in_items"})
		->arg_init(5,make_smart<ExprConstInt>(-1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndTable)>(*this, lib, "EndTable",SideEffects::worstDefault, "ImGui::EndTable")
	->args({})
;
#endif

#endif
#endif
}
