
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
void Module_imgui::initFunctions_19() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::LoadEditorStateFromIniString)>(*this, lib, "LoadEditorStateFromIniString",SideEffects::worstDefault, "imnodes::LoadEditorStateFromIniString")
	->args({"editor","data","data_size"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetAllocatorFunctions)>(*this, lib, "GetAllocatorFunctions",SideEffects::worstDefault, "ImGui::GetAllocatorFunctions")
	->args({"p_alloc_func","p_free_func","p_user_data"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::MemFree)>(*this, lib, "MemFree",SideEffects::worstDefault, "ImGui::MemFree")
	->args({"ptr"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::Link)>(*this, lib, "Link",SideEffects::worstDefault, "imnodes::Link")
	->args({"id","start_attribute_id","end_attribute_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginTooltip)>(*this, lib, "BeginTooltip",SideEffects::worstDefault, "ImGui::BeginTooltip")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const ImVec2 &, ImGuiCond),ImGui::SetWindowPos>(*this, lib, "SetWindowPos",SideEffects::worstDefault, "ImGui::SetWindowPos")
	->args({"pos","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetWindowPos)>(*this, lib, "GetWindowPos",SideEffects::worstDefault, "ImGui::GetWindowPos")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PopButtonRepeat)>(*this, lib, "PopButtonRepeat",SideEffects::worstDefault, "ImGui::PopButtonRepeat")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowSizeConstraints)>(*this, lib, "SetNextWindowSizeConstraints",SideEffects::worstDefault, "ImGui::SetNextWindowSizeConstraints")
	->args({"size_min","size_max","custom_callback","custom_callback_data"})
		->arg_init(2,make_smart<ExprConstPtr>())
		->arg_init(3,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *, bool, ImGuiCond),ImGui::SetWindowCollapsed>(*this, lib, "SetWindowCollapsed",SideEffects::worstDefault, "ImGui::SetWindowCollapsed")
	->args({"name","collapsed","cond"})
		->arg_type(2,makeType<ImGuiCond_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<ImU32 (*)(ImU32),ImGui::GetColorU32>(*this, lib, "GetColorU32",SideEffects::worstDefault, "ImGui::GetColorU32")
	->args({"col"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ColorEdit3)>(*this, lib, "ColorEdit3",SideEffects::worstDefault, "ImGui::ColorEdit3")
	->args({"label","col","flags"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TableHeadersRow)>(*this, lib, "TableHeadersRow",SideEffects::worstDefault, "ImGui::TableHeadersRow")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndDragDropSource)>(*this, lib, "EndDragDropSource",SideEffects::worstDefault, "ImGui::EndDragDropSource")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsItemFocused)>(*this, lib, "IsItemFocused",SideEffects::worstDefault, "ImGui::IsItemFocused")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ColorConvertHSVtoRGB)>(*this, lib, "ColorConvertHSVtoRGB",SideEffects::worstDefault, "ImGui::ColorConvertHSVtoRGB")
	->args({"h","s","v","out_r","out_g","out_b"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsMouseClicked)>(*this, lib, "IsMouseClicked",SideEffects::worstDefault, "ImGui::IsMouseClicked")
	->args({"button","repeat"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(1,make_smart<ExprConstBool>(false))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetMousePos)>(*this, lib, "GetMousePos",SideEffects::worstDefault, "ImGui::GetMousePos")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TabItemButton)>(*this, lib, "TabItemButton",SideEffects::worstDefault, "ImGui::TabItemButton")
	->args({"label","flags"})
		->arg_type(1,makeType<ImGuiTabItemFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTabItemFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetCursorPosY)>(*this, lib, "SetCursorPosY",SideEffects::worstDefault, "ImGui::SetCursorPosY")
	->args({"local_y"})
;
#endif

#endif
#endif
}
