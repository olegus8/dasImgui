
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
void Module_imgui::initFunctions_13() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetWindowContentRegionMin)>(*this, lib, "GetWindowContentRegionMin",SideEffects::worstDefault, "ImGui::GetWindowContentRegionMin")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsWindowAppearing)>(*this, lib, "IsWindowAppearing",SideEffects::worstDefault, "ImGui::IsWindowAppearing")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowBgAlpha)>(*this, lib, "SetNextWindowBgAlpha",SideEffects::worstDefault, "ImGui::SetNextWindowBgAlpha")
	->args({"alpha"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetScrollY)>(*this, lib, "GetScrollY",SideEffects::worstDefault, "ImGui::GetScrollY")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PopAllowKeyboardFocus)>(*this, lib, "PopAllowKeyboardFocus",SideEffects::worstDefault, "ImGui::PopAllowKeyboardFocus")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetTextLineHeightWithSpacing)>(*this, lib, "GetTextLineHeightWithSpacing",SideEffects::worstDefault, "ImGui::GetTextLineHeightWithSpacing")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::Begin)>(*this, lib, "Begin",SideEffects::worstDefault, "ImGui::Begin")
	->args({"name","p_open","flags"})
		->arg_init(1,make_smart<ExprConstPtr>())
		->arg_type(2,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *, float, const char *),ImGui::Value>(*this, lib, "Value",SideEffects::worstDefault, "ImGui::Value")
	->args({"prefix","v","float_format"})
		->arg_init(2,make_smart<ExprConstString>(""))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetCurrentContext)>(*this, lib, "GetCurrentContext",SideEffects::worstDefault, "ImGui::GetCurrentContext")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *),ImGui::TreeNode>(*this, lib, "TreeNode",SideEffects::worstDefault, "ImGui::TreeNode")
	->args({"label"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetColumnWidth)>(*this, lib, "GetColumnWidth",SideEffects::worstDefault, "ImGui::GetColumnWidth")
	->args({"column_index"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::LogToClipboard)>(*this, lib, "LogToClipboard",SideEffects::worstDefault, "ImGui::LogToClipboard")
	->args({"auto_open_depth"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::LogFinish)>(*this, lib, "LogFinish",SideEffects::worstDefault, "ImGui::LogFinish")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowCollapsed)>(*this, lib, "SetNextWindowCollapsed",SideEffects::worstDefault, "ImGui::SetNextWindowCollapsed")
	->args({"collapsed","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::Indent)>(*this, lib, "Indent",SideEffects::worstDefault, "ImGui::Indent")
	->args({"indent_w"})
		->arg_init(0,make_smart<ExprConstFloat>(0))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, const char *, bool, bool),ImGui::MenuItem>(*this, lib, "MenuItem",SideEffects::worstDefault, "ImGui::MenuItem")
	->args({"label","shortcut","selected","enabled"})
		->arg_init(1,make_smart<ExprConstString>(""))
		->arg_init(2,make_smart<ExprConstBool>(false))
		->arg_init(3,make_smart<ExprConstBool>(true))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const ImVec2 &, const ImVec2 &),ImGui::IsRectVisible>(*this, lib, "IsRectVisible",SideEffects::worstDefault, "ImGui::IsRectVisible")
	->args({"rect_min","rect_max"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetMousePosOnOpeningCurrentPopup)>(*this, lib, "GetMousePosOnOpeningCurrentPopup",SideEffects::worstDefault, "ImGui::GetMousePosOnOpeningCurrentPopup")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<ImGuiID (*)(const char *),ImGui::GetID>(*this, lib, "GetID",SideEffects::worstDefault, "ImGui::GetID")
	->args({"str_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetItemRectSize)>(*this, lib, "GetItemRectSize",SideEffects::worstDefault, "ImGui::GetItemRectSize")
	->args({})
;
#endif

#endif
#endif
}
