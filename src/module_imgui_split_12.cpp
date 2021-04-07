
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
void Module_imgui::initFunctions_12() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(ImGuiCol, ImU32),ImGui::PushStyleColor>(*this, lib, "PushStyleColor",SideEffects::worstDefault, "ImGui::PushStyleColor")
	->args({"idx","col"})
		->arg_type(0,makeType<ImGuiCol_>(lib))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, int *, const char *const *, int, int),ImGui::ListBox>(*this, lib, "ListBox",SideEffects::worstDefault, "ImGui::ListBox")
	->args({"label","current_item","items","items_count","height_in_items"})
		->arg_init(4,make_smart<ExprConstInt>(-1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TableGetRowIndex)>(*this, lib, "TableGetRowIndex",SideEffects::worstDefault, "ImGui::TableGetRowIndex")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *, const ImVec2 &, ImGuiCond),ImGui::SetWindowSize>(*this, lib, "SetWindowSize",SideEffects::worstDefault, "ImGui::SetWindowSize")
	->args({"name","size","cond"})
		->arg_type(2,makeType<ImGuiCond_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ProgressBar)>(*this, lib, "ProgressBar",SideEffects::worstDefault, "ImGui::ProgressBar")
	->args({"fraction","size_arg","overlay"})
		->arg_init(2,make_smart<ExprConstString>(""))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::StyleColorsClassic)>(*this, lib, "StyleColorsClassic",SideEffects::worstDefault, "ImGui::StyleColorsClassic")
	->args({"dst"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ShowUserGuide)>(*this, lib, "ShowUserGuide",SideEffects::worstDefault, "ImGui::ShowUserGuide")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(),ImGui::SetWindowFocus>(*this, lib, "SetWindowFocus",SideEffects::worstDefault, "ImGui::SetWindowFocus")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PushFont)>(*this, lib, "PushFont",SideEffects::worstDefault, "ImGui::PushFont")
	->args({"font"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetFontSize)>(*this, lib, "GetFontSize",SideEffects::worstDefault, "ImGui::GetFontSize")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginDragDropTarget)>(*this, lib, "BeginDragDropTarget",SideEffects::worstDefault, "ImGui::BeginDragDropTarget")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::AcceptDragDropPayload)>(*this, lib, "AcceptDragDropPayload",SideEffects::worstDefault, "ImGui::AcceptDragDropPayload")
	->args({"type","flags"})
		->arg_type(1,makeType<ImGuiDragDropFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiDragDropFlags_>(lib)))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::BeginOutputAttribute)>(*this, lib, "BeginOutputAttribute",SideEffects::worstDefault, "imnodes::BeginOutputAttribute")
	->args({"id","shape"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetWindowWidth)>(*this, lib, "GetWindowWidth",SideEffects::worstDefault, "ImGui::GetWindowWidth")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DragIntRange2)>(*this, lib, "DragIntRange2",SideEffects::worstDefault, "ImGui::DragIntRange2")
	->args({"label","v_current_min","v_current_max","v_speed","v_min","v_max","format","format_max","flags"})
		->arg_init(3,make_smart<ExprConstFloat>(1))
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstInt>(0))
		->arg_init(6,make_smart<ExprConstString>("%d"))
		->arg_init(7,make_smart<ExprConstString>(""))
		->arg_type(8,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(8,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::SetImGuiContext)>(*this, lib, "SetImGuiContext",SideEffects::worstDefault, "imnodes::SetImGuiContext")
	->args({"ctx"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetTextLineHeight)>(*this, lib, "GetTextLineHeight",SideEffects::worstDefault, "ImGui::GetTextLineHeight")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetItemAllowOverlap)>(*this, lib, "SetItemAllowOverlap",SideEffects::worstDefault, "ImGui::SetItemAllowOverlap")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::EditorContextGetPanning)>(*this, lib, "EditorContextGetPanning",SideEffects::worstDefault, "imnodes::EditorContextGetPanning")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetDrawData)>(*this, lib, "GetDrawData",SideEffects::worstDefault, "ImGui::GetDrawData")
	->args({})
;
#endif

#endif
#endif
}
