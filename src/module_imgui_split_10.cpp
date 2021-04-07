
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
void Module_imgui::initFunctions_10() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsPopupOpen)>(*this, lib, "IsPopupOpen",SideEffects::worstDefault, "ImGui::IsPopupOpen")
	->args({"str_id","flags"})
		->arg_init(1,make_smart<ExprConstInt>(0))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsMouseDown)>(*this, lib, "IsMouseDown",SideEffects::worstDefault, "ImGui::IsMouseDown")
	->args({"button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetCursorScreenPos)>(*this, lib, "SetCursorScreenPos",SideEffects::worstDefault, "ImGui::SetCursorScreenPos")
	->args({"pos"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *),ImGui::PushID>(*this, lib, "PushID",SideEffects::worstDefault, "ImGui::PushID")
	->args({"str_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndMenu)>(*this, lib, "EndMenu",SideEffects::worstDefault, "ImGui::EndMenu")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::DestroyContext)>(*this, lib, "DestroyContext",SideEffects::worstDefault, "imnodes::DestroyContext")
	->args({"ctx"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::PopStyleVar)>(*this, lib, "PopStyleVar",SideEffects::worstDefault, "imnodes::PopStyleVar")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::EndOutputAttribute)>(*this, lib, "EndOutputAttribute",SideEffects::worstDefault, "imnodes::EndOutputAttribute")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SmallButton)>(*this, lib, "SmallButton",SideEffects::worstDefault, "ImGui::SmallButton")
	->args({"label"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndMenuBar)>(*this, lib, "EndMenuBar",SideEffects::worstDefault, "ImGui::EndMenuBar")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::NextColumn)>(*this, lib, "NextColumn",SideEffects::worstDefault, "ImGui::NextColumn")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::LogToFile)>(*this, lib, "LogToFile",SideEffects::worstDefault, "ImGui::LogToFile")
	->args({"auto_open_depth","filename"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
		->arg_init(1,make_smart<ExprConstString>(""))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsItemVisible)>(*this, lib, "IsItemVisible",SideEffects::worstDefault, "ImGui::IsItemVisible")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsMouseDoubleClicked)>(*this, lib, "IsMouseDoubleClicked",SideEffects::worstDefault, "ImGui::IsMouseDoubleClicked")
	->args({"button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TreePop)>(*this, lib, "TreePop",SideEffects::worstDefault, "ImGui::TreePop")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SliderInt3)>(*this, lib, "SliderInt3",SideEffects::worstDefault, "ImGui::SliderInt3")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%d"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetMouseCursor)>(*this, lib, "SetMouseCursor",SideEffects::worstDefault, "ImGui::SetMouseCursor")
	->args({"cursor_type"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetStateStorage)>(*this, lib, "GetStateStorage",SideEffects::worstDefault, "ImGui::GetStateStorage")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::EndNodeTitleBar)>(*this, lib, "EndNodeTitleBar",SideEffects::worstDefault, "imnodes::EndNodeTitleBar")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetFrameHeight)>(*this, lib, "GetFrameHeight",SideEffects::worstDefault, "ImGui::GetFrameHeight")
	->args({})
;
#endif

#endif
#endif
}
