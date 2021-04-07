
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
void Module_imgui::initFunctions_20() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsKeyReleased)>(*this, lib, "IsKeyReleased",SideEffects::worstDefault, "ImGui::IsKeyReleased")
	->args({"user_key_index"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetClipboardText)>(*this, lib, "SetClipboardText",SideEffects::worstDefault, "ImGui::SetClipboardText")
	->args({"text"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::GetStyle), SimNode_ExtFuncCallRef>(*this, lib, "GetStyle",SideEffects::worstDefault, "imnodes::GetStyle")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::PushAttributeFlag)>(*this, lib, "PushAttributeFlag",SideEffects::worstDefault, "imnodes::PushAttributeFlag")
	->args({"flag"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::LoadCurrentEditorStateFromIniFile)>(*this, lib, "LoadCurrentEditorStateFromIniFile",SideEffects::worstDefault, "imnodes::LoadCurrentEditorStateFromIniFile")
	->args({"file_name"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PopID)>(*this, lib, "PopID",SideEffects::worstDefault, "ImGui::PopID")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsItemToggledOpen)>(*this, lib, "IsItemToggledOpen",SideEffects::worstDefault, "ImGui::IsItemToggledOpen")
	->args({})
;
#endif

#endif
#endif
}
