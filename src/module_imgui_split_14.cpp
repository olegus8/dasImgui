
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
void Module_imgui::initFunctions_14() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetClipboardText)>(*this, lib, "GetClipboardText",SideEffects::worstDefault, "ImGui::GetClipboardText")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::LoadIniSettingsFromDisk)>(*this, lib, "LoadIniSettingsFromDisk",SideEffects::worstDefault, "ImGui::LoadIniSettingsFromDisk")
	->args({"ini_filename"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::StyleColorsDark)>(*this, lib, "StyleColorsDark",SideEffects::worstDefault, "imnodes::StyleColorsDark")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginPopupContextWindow)>(*this, lib, "BeginPopupContextWindow",SideEffects::worstDefault, "ImGui::BeginPopupContextWindow")
	->args({"str_id","popup_flags"})
		->arg_init(0,make_smart<ExprConstString>(""))
		->arg_init(1,make_smart<ExprConstInt>(1))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::PopColorStyle)>(*this, lib, "PopColorStyle",SideEffects::worstDefault, "imnodes::PopColorStyle")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::PushStyleVar)>(*this, lib, "PushStyleVar",SideEffects::worstDefault, "imnodes::PushStyleVar")
	->args({"style_item","value"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::BeginInputAttribute)>(*this, lib, "BeginInputAttribute",SideEffects::worstDefault, "imnodes::BeginInputAttribute")
	->args({"id","shape"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::Separator)>(*this, lib, "Separator",SideEffects::worstDefault, "ImGui::Separator")
	->args({})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::IsLinkStarted)>(*this, lib, "IsLinkStarted",SideEffects::worstDefault, "imnodes::IsLinkStarted")
	->args({"started_at_attribute_id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetCursorPosX)>(*this, lib, "SetCursorPosX",SideEffects::worstDefault, "ImGui::SetCursorPosX")
	->args({"local_x"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DragFloat)>(*this, lib, "DragFloat",SideEffects::worstDefault, "ImGui::DragFloat")
	->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1))
		->arg_init(3,make_smart<ExprConstFloat>(0))
		->arg_init(4,make_smart<ExprConstFloat>(0))
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::IsLinkDropped)>(*this, lib, "IsLinkDropped",SideEffects::worstDefault, "imnodes::IsLinkDropped")
	->args({"started_at_attribute_id","including_detached_links"})
		->arg_init(0,make_smart<ExprConstPtr>())
		->arg_init(1,make_smart<ExprConstBool>(true))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsWindowHovered)>(*this, lib, "IsWindowHovered",SideEffects::worstDefault, "ImGui::IsWindowHovered")
	->args({"flags"})
		->arg_type(0,makeType<ImGuiHoveredFlags_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiHoveredFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SliderFloat)>(*this, lib, "SliderFloat",SideEffects::worstDefault, "ImGui::SliderFloat")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TableHeader)>(*this, lib, "TableHeader",SideEffects::worstDefault, "ImGui::TableHeader")
	->args({"label"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::EndNode)>(*this, lib, "EndNode",SideEffects::worstDefault, "imnodes::EndNode")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, const char *, bool *, bool),ImGui::MenuItem>(*this, lib, "MenuItem",SideEffects::worstDefault, "ImGui::MenuItem")
	->args({"label","shortcut","p_selected","enabled"})
		->arg_init(3,make_smart<ExprConstBool>(true))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::VSliderFloat)>(*this, lib, "VSliderFloat",SideEffects::worstDefault, "ImGui::VSliderFloat")
	->args({"label","size","v","v_min","v_max","format","flags"})
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsWindowFocused)>(*this, lib, "IsWindowFocused",SideEffects::worstDefault, "ImGui::IsWindowFocused")
	->args({"flags"})
		->arg_type(0,makeType<ImGuiFocusedFlags_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiFocusedFlags_>(lib)))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::ClearNodeSelection)>(*this, lib, "ClearNodeSelection",SideEffects::worstDefault, "imnodes::ClearNodeSelection")
	->args({})
;
#endif

#endif
#endif
}
