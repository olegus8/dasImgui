
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
void Module_imgui::initFunctions_16() {
#if USE_GENERATED
#if USE_GENERATED_SPLIT
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TableNextColumn)>(*this, lib, "TableNextColumn",SideEffects::worstDefault, "ImGui::TableNextColumn")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::TableGetColumnIndex)>(*this, lib, "TableGetColumnIndex",SideEffects::worstDefault, "ImGui::TableGetColumnIndex")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PopStyleVar)>(*this, lib, "PopStyleVar",SideEffects::worstDefault, "ImGui::PopStyleVar")
	->args({"count"})
		->arg_init(0,make_smart<ExprConstInt>(1))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndMainMenuBar)>(*this, lib, "EndMainMenuBar",SideEffects::worstDefault, "ImGui::EndMainMenuBar")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::PopClipRect)>(*this, lib, "PopClipRect",SideEffects::worstDefault, "ImGui::PopClipRect")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetItemRectMax)>(*this, lib, "GetItemRectMax",SideEffects::worstDefault, "ImGui::GetItemRectMax")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::EndTabBar)>(*this, lib, "EndTabBar",SideEffects::worstDefault, "ImGui::EndTabBar")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::InputInt2)>(*this, lib, "InputInt2",SideEffects::worstDefault, "ImGui::InputInt2")
	->args({"label","v","flags"})
		->arg_type(2,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const ImVec2 &),ImGui::IsRectVisible>(*this, lib, "IsRectVisible",SideEffects::worstDefault, "ImGui::IsRectVisible")
	->args({"size"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetCursorScreenPos)>(*this, lib, "GetCursorScreenPos",SideEffects::worstDefault, "ImGui::GetCursorScreenPos")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<bool (*)(const char *, bool *, ImGuiTreeNodeFlags),ImGui::CollapsingHeader>(*this, lib, "CollapsingHeader",SideEffects::worstDefault, "ImGui::CollapsingHeader")
	->args({"label","p_visible","flags"})
		->arg_type(2,makeType<ImGuiTreeNodeFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTreeNodeFlags_>(lib)))
;
#endif
#ifdef IMNODES_NAMESPACE
addExtern<DAS_BIND_FUN(imnodes::SetNodeGridSpacePos)>(*this, lib, "SetNodeGridSpacePos",SideEffects::worstDefault, "imnodes::SetNodeGridSpacePos")
	->args({"node_id","grid_pos"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::Bullet)>(*this, lib, "Bullet",SideEffects::worstDefault, "ImGui::Bullet")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::DragFloat3)>(*this, lib, "DragFloat3",SideEffects::worstDefault, "ImGui::DragFloat3")
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
addExtern<DAS_BIND_FUN(ImGui::BeginPopupModal)>(*this, lib, "BeginPopupModal",SideEffects::worstDefault, "ImGui::BeginPopupModal")
	->args({"name","p_open","flags"})
		->arg_init(1,make_smart<ExprConstPtr>())
		->arg_type(2,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ResetMouseDragDelta)>(*this, lib, "ResetMouseDragDelta",SideEffects::worstDefault, "ImGui::ResetMouseDragDelta")
	->args({"button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiMouseButton_>(lib)))
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::ShowFontSelector)>(*this, lib, "ShowFontSelector",SideEffects::worstDefault, "ImGui::ShowFontSelector")
	->args({"label"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::GetFrameHeightWithSpacing)>(*this, lib, "GetFrameHeightWithSpacing",SideEffects::worstDefault, "ImGui::GetFrameHeightWithSpacing")
	->args({})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::SetTabItemClosed)>(*this, lib, "SetTabItemClosed",SideEffects::worstDefault, "ImGui::SetTabItemClosed")
	->args({"tab_or_docked_window_label"})
;
#endif
#ifdef GLOBAL_NAMESPACE
addExtern<DAS_BIND_FUN(ImGui::IsMousePosValid)>(*this, lib, "IsMousePosValid",SideEffects::worstDefault, "ImGui::IsMousePosValid")
	->args({"mouse_pos"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
#endif

#endif
#endif
}
