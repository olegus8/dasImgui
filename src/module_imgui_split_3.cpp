
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
void Module_imgui::initFunctions_3() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::LogToTTY)>(*this, lib, "LogToTTY",SideEffects::worstDefault, "ImGui::LogToTTY")
	->args({"auto_open_depth"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetTreeNodeToLabelSpacing)>(*this, lib, "GetTreeNodeToLabelSpacing",SideEffects::worstDefault, "ImGui::GetTreeNodeToLabelSpacing")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetWindowHeight)>(*this, lib, "GetWindowHeight",SideEffects::worstDefault, "ImGui::GetWindowHeight")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetWindowFontScale)>(*this, lib, "SetWindowFontScale",SideEffects::worstDefault, "ImGui::SetWindowFontScale")
	->args({"scale"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetScrollFromPosY)>(*this, lib, "SetScrollFromPosY",SideEffects::worstDefault, "ImGui::SetScrollFromPosY")
	->args({"local_y","center_y_ratio"})
		->arg_init(1,make_smart<ExprConstFloat>(0.5))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::InputInt)>(*this, lib, "InputInt",SideEffects::worstDefault, "ImGui::InputInt")
	->args({"label","v","step","step_fast","flags"})
		->arg_init(2,make_smart<ExprConstInt>(1))
		->arg_init(3,make_smart<ExprConstInt>(100))
		->arg_type(4,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(4,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const void *),ImGui::TreePush>(*this, lib, "TreePush",SideEffects::worstDefault, "ImGui::TreePush")
	->args({"ptr_id"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *, const float *, int, int, const char *, float, float, ImVec2, int),ImGui::PlotHistogram>(*this, lib, "PlotHistogram",SideEffects::worstDefault, "ImGui::PlotHistogram")
	->args({"label","values","values_count","values_offset","overlay_text","scale_min","scale_max","graph_size","stride"})
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstString>(""))
		->arg_init(5,make_smart<ExprConstFloat>(3.40282347E+38))
		->arg_init(6,make_smart<ExprConstFloat>(3.40282347E+38))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SaveIniSettingsToMemory)>(*this, lib, "SaveIniSettingsToMemory",SideEffects::worstDefault, "ImGui::SaveIniSettingsToMemory")
	->args({"out_ini_size"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::CreateContext)>(*this, lib, "CreateContext",SideEffects::worstDefault, "imnodes::CreateContext")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DragInt2)>(*this, lib, "DragInt2",SideEffects::worstDefault, "ImGui::DragInt2")
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
addExtern<DAS_BIND_FUN(ImGui::SetColorEditOptions)>(*this, lib, "SetColorEditOptions",SideEffects::worstDefault, "ImGui::SetColorEditOptions")
	->args({"flags"})
		->arg_type(0,makeType<ImGuiColorEditFlags_>(lib))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::EditorContextMoveToNode)>(*this, lib, "EditorContextMoveToNode",SideEffects::worstDefault, "imnodes::EditorContextMoveToNode")
	->args({"node_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginMenu)>(*this, lib, "BeginMenu",SideEffects::worstDefault, "ImGui::BeginMenu")
	->args({"label","enabled"})
		->arg_init(1,make_smart<ExprConstBool>(true))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetWindowSize)>(*this, lib, "GetWindowSize",SideEffects::worstDefault, "ImGui::GetWindowSize")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::SetNodeEditorSpacePos)>(*this, lib, "SetNodeEditorSpacePos",SideEffects::worstDefault, "imnodes::SetNodeEditorSpacePos")
	->args({"node_id","editor_space_pos"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<ImGuiID (*)(const void *),ImGui::GetID>(*this, lib, "GetID",SideEffects::worstDefault, "ImGui::GetID")
	->args({"ptr_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetMouseCursor)>(*this, lib, "GetMouseCursor",SideEffects::worstDefault, "ImGui::GetMouseCursor")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(ImGuiID, const ImVec2 &, bool, ImGuiWindowFlags),ImGui::BeginChild>(*this, lib, "BeginChild",SideEffects::worstDefault, "ImGui::BeginChild")
	->args({"id","size","border","flags"})
		->arg_init(2,make_smart<ExprConstBool>(false))
		->arg_type(3,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::ClearLinkSelection)>(*this, lib, "ClearLinkSelection",SideEffects::worstDefault, "imnodes::ClearLinkSelection")
	->args({})
;
#endif

#endif
#endif
}
