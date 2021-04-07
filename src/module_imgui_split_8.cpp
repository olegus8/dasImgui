
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
void Module_imgui::initFunctions_8() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DebugCheckVersionAndDataLayout)>(*this, lib, "DebugCheckVersionAndDataLayout",SideEffects::worstDefault, "ImGui::DebugCheckVersionAndDataLayout")
	->args({"version_str","sz_io","sz_style","sz_vec2","sz_vec4","sz_drawvert","sz_drawidx"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::BeginNode)>(*this, lib, "BeginNode",SideEffects::worstDefault, "imnodes::BeginNode")
	->args({"id"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SameLine)>(*this, lib, "SameLine",SideEffects::worstDefault, "ImGui::SameLine")
	->args({"offset_from_start_x","spacing"})
		->arg_init(0,make_smart<ExprConstFloat>(0))
		->arg_init(1,make_smart<ExprConstFloat>(-1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginGroup)>(*this, lib, "BeginGroup",SideEffects::worstDefault, "ImGui::BeginGroup")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndListBox)>(*this, lib, "EndListBox",SideEffects::worstDefault, "ImGui::EndListBox")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *, const float *, int, int, const char *, float, float, ImVec2, int),ImGui::PlotLines>(*this, lib, "PlotLines",SideEffects::worstDefault, "ImGui::PlotLines")
	->args({"label","values","values_count","values_offset","overlay_text","scale_min","scale_max","graph_size","stride"})
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstString>(""))
		->arg_init(5,make_smart<ExprConstFloat>(3.40282347E+38))
		->arg_init(6,make_smart<ExprConstFloat>(3.40282347E+38))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetKeyPressedAmount)>(*this, lib, "GetKeyPressedAmount",SideEffects::worstDefault, "ImGui::GetKeyPressedAmount")
	->args({"key_index","repeat_delay","rate"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::CreateContext)>(*this, lib, "CreateContext",SideEffects::worstDefault, "ImGui::CreateContext")
	->args({"shared_font_atlas"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginMainMenuBar)>(*this, lib, "BeginMainMenuBar",SideEffects::worstDefault, "ImGui::BeginMainMenuBar")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetDrawListSharedData)>(*this, lib, "GetDrawListSharedData",SideEffects::worstDefault, "ImGui::GetDrawListSharedData")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SaveIniSettingsToDisk)>(*this, lib, "SaveIniSettingsToDisk",SideEffects::worstDefault, "ImGui::SaveIniSettingsToDisk")
	->args({"ini_filename"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::PushColorStyle)>(*this, lib, "PushColorStyle",SideEffects::worstDefault, "imnodes::PushColorStyle")
	->args({"item","color"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SliderInt2)>(*this, lib, "SliderInt2",SideEffects::worstDefault, "ImGui::SliderInt2")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%d"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::EndInputAttribute)>(*this, lib, "EndInputAttribute",SideEffects::worstDefault, "imnodes::EndInputAttribute")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<ImU32 (*)(ImGuiCol, float),ImGui::GetColorU32>(*this, lib, "GetColorU32",SideEffects::worstDefault, "ImGui::GetColorU32")
	->args({"idx","alpha_mul"})
		->arg_type(0,makeType<ImGuiCol_>(lib))
		->arg_init(1,make_smart<ExprConstFloat>(1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::Dummy)>(*this, lib, "Dummy",SideEffects::worstDefault, "ImGui::Dummy")
	->args({"size"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PushButtonRepeat)>(*this, lib, "PushButtonRepeat",SideEffects::worstDefault, "ImGui::PushButtonRepeat")
	->args({"repeat"})
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::EndStaticAttribute)>(*this, lib, "EndStaticAttribute",SideEffects::worstDefault, "imnodes::EndStaticAttribute")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *, unsigned int),ImGui::Value>(*this, lib, "Value",SideEffects::worstDefault, "ImGui::Value")
	->args({"prefix","v"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::InputFloat3)>(*this, lib, "InputFloat3",SideEffects::worstDefault, "ImGui::InputFloat3")
	->args({"label","v","format","flags"})
		->arg_init(2,make_smart<ExprConstString>("%.3f"))
		->arg_type(3,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
#endif

#endif
#endif
}
