
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
void Module_imgui::initFunctions_4() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PopFont)>(*this, lib, "PopFont",SideEffects::worstDefault, "ImGui::PopFont")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ShowAboutWindow)>(*this, lib, "ShowAboutWindow",SideEffects::worstDefault, "ImGui::ShowAboutWindow")
	->args({"p_open"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetNextItemWidth)>(*this, lib, "SetNextItemWidth",SideEffects::worstDefault, "ImGui::SetNextItemWidth")
	->args({"item_width"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, bool),ImGui::RadioButton>(*this, lib, "RadioButton",SideEffects::worstDefault, "ImGui::RadioButton")
	->args({"label","active"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetItemRectMin)>(*this, lib, "GetItemRectMin",SideEffects::worstDefault, "ImGui::GetItemRectMin")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginPopupContextVoid)>(*this, lib, "BeginPopupContextVoid",SideEffects::worstDefault, "ImGui::BeginPopupContextVoid")
	->args({"str_id","popup_flags"})
		->arg_init(0,make_smart<ExprConstString>(""))
		->arg_init(1,make_smart<ExprConstInt>(1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetColumnOffset)>(*this, lib, "SetColumnOffset",SideEffects::worstDefault, "ImGui::SetColumnOffset")
	->args({"column_index","offset_x"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PushClipRect)>(*this, lib, "PushClipRect",SideEffects::worstDefault, "ImGui::PushClipRect")
	->args({"clip_rect_min","clip_rect_max","intersect_with_current_clip_rect"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SliderAngle)>(*this, lib, "SliderAngle",SideEffects::worstDefault, "ImGui::SliderAngle")
	->args({"label","v_rad","v_degrees_min","v_degrees_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(-360))
		->arg_init(3,make_smart<ExprConstFloat>(+360))
		->arg_init(4,make_smart<ExprConstString>("%.0f deg"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsKeyPressed)>(*this, lib, "IsKeyPressed",SideEffects::worstDefault, "ImGui::IsKeyPressed")
	->args({"user_key_index","repeat"})
		->arg_init(1,make_smart<ExprConstBool>(true))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DragFloat4)>(*this, lib, "DragFloat4",SideEffects::worstDefault, "ImGui::DragFloat4")
	->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1))
		->arg_init(3,make_smart<ExprConstFloat>(0))
		->arg_init(4,make_smart<ExprConstFloat>(0))
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::OpenPopup)>(*this, lib, "OpenPopup",SideEffects::worstDefault, "ImGui::OpenPopup")
	->args({"str_id","popup_flags"})
		->arg_init(1,make_smart<ExprConstInt>(0))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetMainViewport)>(*this, lib, "GetMainViewport",SideEffects::worstDefault, "ImGui::GetMainViewport")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<void (*)(const char *, float (*)(void *, int), void *, int, int, const char *, float, float, ImVec2),ImGui::PlotLines>(*this, lib, "PlotLines",SideEffects::worstDefault, "ImGui::PlotLines")
	->args({"label","values_getter","data","values_count","values_offset","overlay_text","scale_min","scale_max","graph_size"})
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstString>(""))
		->arg_init(6,make_smart<ExprConstFloat>(3.40282347E+38))
		->arg_init(7,make_smart<ExprConstFloat>(3.40282347E+38))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsKeyDown)>(*this, lib, "IsKeyDown",SideEffects::worstDefault, "ImGui::IsKeyDown")
	->args({"user_key_index"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::BeginMenuBar)>(*this, lib, "BeginMenuBar",SideEffects::worstDefault, "ImGui::BeginMenuBar")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetCursorStartPos)>(*this, lib, "GetCursorStartPos",SideEffects::worstDefault, "ImGui::GetCursorStartPos")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsMouseReleased)>(*this, lib, "IsMouseReleased",SideEffects::worstDefault, "ImGui::IsMouseReleased")
	->args({"button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PushTextWrapPos)>(*this, lib, "PushTextWrapPos",SideEffects::worstDefault, "ImGui::PushTextWrapPos")
	->args({"wrap_local_pos_x"})
		->arg_init(0,make_smart<ExprConstFloat>(0))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ShowDemoWindow)>(*this, lib, "ShowDemoWindow",SideEffects::worstDefault, "ImGui::ShowDemoWindow")
	->args({"p_open"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif

#endif
#endif
}
