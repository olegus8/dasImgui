// ------------
// functions
// ------------

addExtern<DAS_BIND_FUN(ImGui::MemAlloc)>(*this, lib, "MemAlloc",SideEffects::worstDefault, "ImGui::MemAlloc")
	->args({"size"})
;
addExtern<DAS_BIND_FUN(ImGui::GetDrawListSharedData)>(*this, lib, "GetDrawListSharedData",SideEffects::worstDefault, "ImGui::GetDrawListSharedData")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::EndDragDropTarget)>(*this, lib, "EndDragDropTarget",SideEffects::worstDefault, "ImGui::EndDragDropTarget")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::BeginPopup)>(*this, lib, "BeginPopup",SideEffects::worstDefault, "ImGui::BeginPopup")
	->args({"str_id","flags"})
		->arg_type(1,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::ListBoxFooter)>(*this, lib, "ListBoxFooter",SideEffects::worstDefault, "ImGui::ListBoxFooter")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::GetFrameCount)>(*this, lib, "GetFrameCount",SideEffects::worstDefault, "ImGui::GetFrameCount")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsItemActivated)>(*this, lib, "IsItemActivated",SideEffects::worstDefault, "ImGui::IsItemActivated")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::BeginPopupModal)>(*this, lib, "BeginPopupModal",SideEffects::worstDefault, "ImGui::BeginPopupModal")
	->args({"name","p_open","flags"})
		->arg_init(1,make_smart<ExprConstPtr>())
		->arg_type(2,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::SetKeyboardFocusHere)>(*this, lib, "SetKeyboardFocusHere",SideEffects::worstDefault, "ImGui::SetKeyboardFocusHere")
	->args({"offset"})
		->arg_init(0,make_smart<ExprConstInt>(0))
;
addExtern<bool (*)(const char *, ImGuiDataType, void *, int, const void *, const void *, const char *, ImGuiSliderFlags),ImGui::SliderScalarN>(*this, lib, "SliderScalarN",SideEffects::worstDefault, "ImGui::SliderScalarN")
	->args({"label","data_type","p_data","components","p_min","p_max","format","flags"})
		->arg_init(6,make_smart<ExprConstString>(""))
		->arg_type(7,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(7,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::ShowStyleSelector)>(*this, lib, "ShowStyleSelector",SideEffects::worstDefault, "ImGui::ShowStyleSelector")
	->args({"label"})
;
addExtern<DAS_BIND_FUN(ImGui::GetWindowContentRegionWidth)>(*this, lib, "GetWindowContentRegionWidth",SideEffects::worstDefault, "ImGui::GetWindowContentRegionWidth")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::TableGetColumnFlags)>(*this, lib, "TableGetColumnFlags",SideEffects::worstDefault, "ImGui::TableGetColumnFlags")
	->args({"column_n"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
;
addExtern<DAS_BIND_FUN(ImGui::ColorPicker3)>(*this, lib, "ColorPicker3",SideEffects::worstDefault, "ImGui::ColorPicker3")
	->args({"label","col","flags"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::EndPopup)>(*this, lib, "EndPopup",SideEffects::worstDefault, "ImGui::EndPopup")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsItemHovered)>(*this, lib, "IsItemHovered",SideEffects::worstDefault, "ImGui::IsItemHovered")
	->args({"flags"})
		->arg_init(0,make_smart<ExprConstInt>(0))
;
addExtern<DAS_BIND_FUN(ImGui::InputScalar)>(*this, lib, "InputScalar",SideEffects::worstDefault, "ImGui::InputScalar")
	->args({"label","data_type","p_data","p_step","p_step_fast","format","flags"})
		->arg_init(3,make_smart<ExprConstPtr>())
		->arg_init(4,make_smart<ExprConstPtr>())
		->arg_init(5,make_smart<ExprConstString>(""))
		->arg_type(6,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetForegroundDrawList)>(*this, lib, "GetForegroundDrawList",SideEffects::worstDefault, "ImGui::GetForegroundDrawList")
	->args({})
;
addExtern<bool (*)(const char *, bool *, ImGuiTreeNodeFlags),ImGui::CollapsingHeader>(*this, lib, "CollapsingHeader",SideEffects::worstDefault, "ImGui::CollapsingHeader")
	->args({"label","p_visible","flags"})
		->arg_init(2,make_smart<ExprConstInt>(0))
;
addExtern<DAS_BIND_FUN(ImGui::GetStyleColorName)>(*this, lib, "GetStyleColorName",SideEffects::worstDefault, "ImGui::GetStyleColorName")
	->args({"idx"})
		->arg_type(0,makeType<ImGuiCol_>(lib))
;
addExtern<DAS_BIND_FUN(ImGui::CaptureKeyboardFromApp)>(*this, lib, "CaptureKeyboardFromApp",SideEffects::worstDefault, "ImGui::CaptureKeyboardFromApp")
	->args({"want_capture_keyboard_value"})
		->arg_init(0,make_smart<ExprConstBool>(true))
;
addExtern<DAS_BIND_FUN(ImGui::CaptureMouseFromApp)>(*this, lib, "CaptureMouseFromApp",SideEffects::worstDefault, "ImGui::CaptureMouseFromApp")
	->args({"want_capture_mouse_value"})
		->arg_init(0,make_smart<ExprConstBool>(true))
;
addExtern<bool (*)(const char *, ImGuiDataType, void *, const void *, const void *, const char *, float),ImGui::SliderScalar>(*this, lib, "SliderScalar",SideEffects::worstDefault, "ImGui::SliderScalar")
	->args({"label","data_type","p_data","p_min","p_max","format","power"})
;
addExtern<DAS_BIND_FUN(ImGui::GetContentRegionAvailWidth)>(*this, lib, "GetContentRegionAvailWidth",SideEffects::worstDefault, "ImGui::GetContentRegionAvailWidth")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SetScrollFromPosX)>(*this, lib, "SetScrollFromPosX",SideEffects::worstDefault, "ImGui::SetScrollFromPosX")
	->args({"local_x","center_x_ratio"})
		->arg_init(1,make_smart<ExprConstFloat>(0.5))
;
addExtern<DAS_BIND_FUN(ImGui::OpenPopup)>(*this, lib, "OpenPopup",SideEffects::worstDefault, "ImGui::OpenPopup")
	->args({"str_id","popup_flags"})
		->arg_init(1,make_smart<ExprConstInt>(0))
;
addExtern<DAS_BIND_FUN(ImGui::NewFrame)>(*this, lib, "NewFrame",SideEffects::worstDefault, "ImGui::NewFrame")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::GetScrollX)>(*this, lib, "GetScrollX",SideEffects::worstDefault, "ImGui::GetScrollX")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowFocus)>(*this, lib, "SetNextWindowFocus",SideEffects::worstDefault, "ImGui::SetNextWindowFocus")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::DragInt)>(*this, lib, "DragInt",SideEffects::worstDefault, "ImGui::DragInt")
	->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1))
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstString>("%d"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::DestroyContext)>(*this, lib, "DestroyContext",SideEffects::worstDefault, "ImGui::DestroyContext")
	->args({"ctx"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::Checkbox)>(*this, lib, "Checkbox",SideEffects::worstDefault, "ImGui::Checkbox")
	->args({"label","v"})
;
addExtern<DAS_BIND_FUN(ImGui::GetClipboardText)>(*this, lib, "GetClipboardText",SideEffects::worstDefault, "ImGui::GetClipboardText")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::GetDrawData)>(*this, lib, "GetDrawData",SideEffects::worstDefault, "ImGui::GetDrawData")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SetNextItemOpen)>(*this, lib, "SetNextItemOpen",SideEffects::worstDefault, "ImGui::SetNextItemOpen")
	->args({"is_open","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::IsItemClicked)>(*this, lib, "IsItemClicked",SideEffects::worstDefault, "ImGui::IsItemClicked")
	->args({"mouse_button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiMouseButton_>(lib)))
;
addExtern<bool (*)(const char *, const char *, va_list),ImGui::TreeNodeV>(*this, lib, "TreeNodeV",SideEffects::worstDefault, "ImGui::TreeNodeV")
	->args({"str_id","fmt","args"})
;
addExtern<DAS_BIND_FUN(ImGui::SetItemDefaultFocus)>(*this, lib, "SetItemDefaultFocus",SideEffects::worstDefault, "ImGui::SetItemDefaultFocus")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsAnyItemActive)>(*this, lib, "IsAnyItemActive",SideEffects::worstDefault, "ImGui::IsAnyItemActive")
	->args({})
;
addExtern<void (*)(const char *),ImGui::SetWindowFocus>(*this, lib, "SetWindowFocus",SideEffects::worstDefault, "ImGui::SetWindowFocus")
	->args({"name"})
;
addExtern<DAS_BIND_FUN(ImGui::InputInt4)>(*this, lib, "InputInt4",SideEffects::worstDefault, "ImGui::InputInt4")
	->args({"label","v","flags"})
		->arg_type(2,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::InvisibleButton)>(*this, lib, "InvisibleButton",SideEffects::worstDefault, "ImGui::InvisibleButton")
	->args({"str_id","size","flags"})
		->arg_init(2,make_smart<ExprConstInt>(0))
;
addExtern<DAS_BIND_FUN(ImGui::CreateContext)>(*this, lib, "CreateContext",SideEffects::worstDefault, "ImGui::CreateContext")
	->args({"shared_font_atlas"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::Unindent)>(*this, lib, "Unindent",SideEffects::worstDefault, "ImGui::Unindent")
	->args({"indent_w"})
		->arg_init(0,make_smart<ExprConstFloat>(0))
;
addExtern<DAS_BIND_FUN(ImGui::TableSetupScrollFreeze)>(*this, lib, "TableSetupScrollFreeze",SideEffects::worstDefault, "ImGui::TableSetupScrollFreeze")
	->args({"cols","rows"})
;
addExtern<DAS_BIND_FUN(ImGui::IsItemDeactivatedAfterEdit)>(*this, lib, "IsItemDeactivatedAfterEdit",SideEffects::worstDefault, "ImGui::IsItemDeactivatedAfterEdit")
	->args({})
;
addExtern<bool (*)(const char *, int, int),ImGui::ListBoxHeader>(*this, lib, "ListBoxHeader",SideEffects::worstDefault, "ImGui::ListBoxHeader")
	->args({"label","items_count","height_in_items"})
		->arg_init(2,make_smart<ExprConstInt>(-1))
;
addExtern<bool (*)(const char *, float *, float, float, const char *, float),ImGui::SliderFloat2>(*this, lib, "SliderFloat2",SideEffects::worstDefault, "ImGui::SliderFloat2")
	->args({"label","v","v_min","v_max","format","power"})
;
addExtern<DAS_BIND_FUN(ImGui::ShowStyleEditor)>(*this, lib, "ShowStyleEditor",SideEffects::worstDefault, "ImGui::ShowStyleEditor")
	->args({"ref"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::SetCursorScreenPos)>(*this, lib, "SetCursorScreenPos",SideEffects::worstDefault, "ImGui::SetCursorScreenPos")
	->args({"pos"})
;
addExtern<DAS_BIND_FUN(ImGui::OpenPopupContextItem)>(*this, lib, "OpenPopupContextItem",SideEffects::worstDefault, "ImGui::OpenPopupContextItem")
	->args({"str_id","mb"})
		->arg_init(0,make_smart<ExprConstString>(""))
		->arg_type(1,makeType<ImGuiMouseButton_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(1,makeType<ImGuiMouseButton_>(lib)))
;
addExtern<void (*)(ImGuiStyleVar, float),ImGui::PushStyleVar>(*this, lib, "PushStyleVar",SideEffects::worstDefault, "ImGui::PushStyleVar")
	->args({"idx","val"})
		->arg_type(0,makeType<ImGuiStyleVar_>(lib))
;
addExtern<DAS_BIND_FUN(ImGui::EndTable)>(*this, lib, "EndTable",SideEffects::worstDefault, "ImGui::EndTable")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::TableHeader)>(*this, lib, "TableHeader",SideEffects::worstDefault, "ImGui::TableHeader")
	->args({"label"})
;
addExtern<DAS_BIND_FUN(ImGui::LogToTTY)>(*this, lib, "LogToTTY",SideEffects::worstDefault, "ImGui::LogToTTY")
	->args({"auto_open_depth"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
;
addExtern<DAS_BIND_FUN(ImGui::GetTreeNodeToLabelSpacing)>(*this, lib, "GetTreeNodeToLabelSpacing",SideEffects::worstDefault, "ImGui::GetTreeNodeToLabelSpacing")
	->args({})
;
addExtern<bool (*)(const char *, const char *, bool *, bool),ImGui::MenuItem>(*this, lib, "MenuItem",SideEffects::worstDefault, "ImGui::MenuItem")
	->args({"label","shortcut","p_selected","enabled"})
		->arg_init(3,make_smart<ExprConstBool>(true))
;
addExtern<DAS_BIND_FUN(ImGui::GetWindowHeight)>(*this, lib, "GetWindowHeight",SideEffects::worstDefault, "ImGui::GetWindowHeight")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SetWindowFontScale)>(*this, lib, "SetWindowFontScale",SideEffects::worstDefault, "ImGui::SetWindowFontScale")
	->args({"scale"})
;
addExtern<DAS_BIND_FUN(ImGui::SetScrollFromPosY)>(*this, lib, "SetScrollFromPosY",SideEffects::worstDefault, "ImGui::SetScrollFromPosY")
	->args({"local_y","center_y_ratio"})
		->arg_init(1,make_smart<ExprConstFloat>(0.5))
;
addExtern<bool (*)(const char *, float *, float, float, float, const char *, float),ImGui::DragFloat2>(*this, lib, "DragFloat2",SideEffects::worstDefault, "ImGui::DragFloat2")
	->args({"label","v","v_speed","v_min","v_max","format","power"})
;
addExtern<void (*)(const char *, int),ImGui::Value>(*this, lib, "Value",SideEffects::worstDefault, "ImGui::Value")
	->args({"prefix","v"})
;
addExtern<bool (*)(const char *, int *, int),ImGui::RadioButton>(*this, lib, "RadioButton",SideEffects::worstDefault, "ImGui::RadioButton")
	->args({"label","v","v_button"})
;
addExtern<DAS_BIND_FUN(ImGui::SetColorEditOptions)>(*this, lib, "SetColorEditOptions",SideEffects::worstDefault, "ImGui::SetColorEditOptions")
	->args({"flags"})
		->arg_type(0,makeType<ImGuiColorEditFlags_>(lib))
;
addExtern<DAS_BIND_FUN(ImGui::ShowFontSelector)>(*this, lib, "ShowFontSelector",SideEffects::worstDefault, "ImGui::ShowFontSelector")
	->args({"label"})
;
addExtern<DAS_BIND_FUN(ImGui::GetWindowSize), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetWindowSize",SideEffects::worstDefault, "ImGui::GetWindowSize")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SmallButton)>(*this, lib, "SmallButton",SideEffects::worstDefault, "ImGui::SmallButton")
	->args({"label"})
;
addExtern<DAS_BIND_FUN(ImGui::GetMouseCursor)>(*this, lib, "GetMouseCursor",SideEffects::worstDefault, "ImGui::GetMouseCursor")
	->args({})
;
addExtern<bool (*)(const char *, const char *, bool, bool),ImGui::MenuItem>(*this, lib, "MenuItem",SideEffects::worstDefault, "ImGui::MenuItem")
	->args({"label","shortcut","selected","enabled"})
		->arg_init(1,make_smart<ExprConstString>(""))
		->arg_init(2,make_smart<ExprConstBool>(false))
		->arg_init(3,make_smart<ExprConstBool>(true))
;
addExtern<DAS_BIND_FUN(ImGui::PopFont)>(*this, lib, "PopFont",SideEffects::worstDefault, "ImGui::PopFont")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::ColorConvertRGBtoHSV)>(*this, lib, "ColorConvertRGBtoHSV",SideEffects::worstDefault, "ImGui::ColorConvertRGBtoHSV")
	->args({"r","g","b","out_h","out_s","out_v"})
;
addExtern<DAS_BIND_FUN(ImGui::SetNextItemWidth)>(*this, lib, "SetNextItemWidth",SideEffects::worstDefault, "ImGui::SetNextItemWidth")
	->args({"item_width"})
;
addExtern<DAS_BIND_FUN(ImGui::GetItemRectMin), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetItemRectMin",SideEffects::worstDefault, "ImGui::GetItemRectMin")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SetColumnOffset)>(*this, lib, "SetColumnOffset",SideEffects::worstDefault, "ImGui::SetColumnOffset")
	->args({"column_index","offset_x"})
;
addExtern<DAS_BIND_FUN(ImGui::IsKeyPressed)>(*this, lib, "IsKeyPressed",SideEffects::worstDefault, "ImGui::IsKeyPressed")
	->args({"user_key_index","repeat"})
		->arg_init(1,make_smart<ExprConstBool>(true))
;
addExtern<DAS_BIND_FUN(ImGui::IsKeyDown)>(*this, lib, "IsKeyDown",SideEffects::worstDefault, "ImGui::IsKeyDown")
	->args({"user_key_index"})
;
addExtern<void (*)(ImGuiStyleVar, const ImVec2 &),ImGui::PushStyleVar>(*this, lib, "PushStyleVar",SideEffects::worstDefault, "ImGui::PushStyleVar")
	->args({"idx","val"})
		->arg_type(0,makeType<ImGuiStyleVar_>(lib))
;
addExtern<DAS_BIND_FUN(ImGui::IsMouseReleased)>(*this, lib, "IsMouseReleased",SideEffects::worstDefault, "ImGui::IsMouseReleased")
	->args({"button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
;
addExtern<DAS_BIND_FUN(ImGui::BeginMenuBar)>(*this, lib, "BeginMenuBar",SideEffects::worstDefault, "ImGui::BeginMenuBar")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::GetCursorStartPos), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetCursorStartPos",SideEffects::worstDefault, "ImGui::GetCursorStartPos")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::PushTextWrapPos)>(*this, lib, "PushTextWrapPos",SideEffects::worstDefault, "ImGui::PushTextWrapPos")
	->args({"wrap_local_pos_x"})
		->arg_init(0,make_smart<ExprConstFloat>(0))
;
addExtern<DAS_BIND_FUN(ImGui::GetColumnIndex)>(*this, lib, "GetColumnIndex",SideEffects::worstDefault, "ImGui::GetColumnIndex")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SetScrollX)>(*this, lib, "SetScrollX",SideEffects::worstDefault, "ImGui::SetScrollX")
	->args({"scroll_x"})
;
addExtern<bool (*)(const void *, ImGuiTreeNodeFlags, const char *, va_list),ImGui::TreeNodeExV>(*this, lib, "TreeNodeExV",SideEffects::worstDefault, "ImGui::TreeNodeExV")
	->args({"ptr_id","flags","fmt","args"})
;
addExtern<void (*)(const char *, const float *, int, int, const char *, float, float, ImVec2, int),ImGui::PlotHistogram>(*this, lib, "PlotHistogram",SideEffects::worstDefault, "ImGui::PlotHistogram")
	->args({"label","values","values_count","values_offset","overlay_text","scale_min","scale_max","graph_size","stride"})
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstString>(""))
		->arg_init(5,make_smart<ExprConstFloat>(3.40282347E+38))
		->arg_init(6,make_smart<ExprConstFloat>(3.40282347E+38))
;
addExtern<void (*)(int),ImGui::PushID>(*this, lib, "PushID",SideEffects::worstDefault, "ImGui::PushID")
	->args({"int_id"})
;
addExtern<DAS_BIND_FUN(ImGui::LogToFile)>(*this, lib, "LogToFile",SideEffects::worstDefault, "ImGui::LogToFile")
	->args({"auto_open_depth","filename"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
		->arg_init(1,make_smart<ExprConstString>(""))
;
addExtern<DAS_BIND_FUN(ImGui::PushAllowKeyboardFocus)>(*this, lib, "PushAllowKeyboardFocus",SideEffects::worstDefault, "ImGui::PushAllowKeyboardFocus")
	->args({"allow_keyboard_focus"})
;
addExtern<void (*)(const void *),ImGui::TreePush>(*this, lib, "TreePush",SideEffects::worstDefault, "ImGui::TreePush")
	->args({"ptr_id"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowPos)>(*this, lib, "SetNextWindowPos",SideEffects::worstDefault, "ImGui::SetNextWindowPos")
	->args({"pos","cond","pivot"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::InputFloat3)>(*this, lib, "InputFloat3",SideEffects::worstDefault, "ImGui::InputFloat3")
	->args({"label","v","format","flags"})
		->arg_init(2,make_smart<ExprConstString>("%.3f"))
		->arg_type(3,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
addExtern<bool (*)(const char *, ImGuiMouseButton, bool),ImGui::BeginPopupContextWindow>(*this, lib, "BeginPopupContextWindow",SideEffects::worstDefault, "ImGui::BeginPopupContextWindow")
	->args({"str_id","mb","over_items"})
		->arg_type(1,makeType<ImGuiMouseButton_>(lib))
;
addExtern<DAS_BIND_FUN(ImGui::BeginDragDropSource)>(*this, lib, "BeginDragDropSource",SideEffects::worstDefault, "ImGui::BeginDragDropSource")
	->args({"flags"})
		->arg_init(0,make_smart<ExprConstInt>(0))
;
addExtern<DAS_BIND_FUN(ImGui::GetTime)>(*this, lib, "GetTime",SideEffects::worstDefault, "ImGui::GetTime")
	->args({})
;
addExtern<bool (*)(const char *, int *, bool (*)(void *, int, const char **), void *, int, int),ImGui::Combo>(*this, lib, "Combo",SideEffects::worstDefault, "ImGui::Combo")
	->args({"label","current_item","items_getter","data","items_count","popup_max_height_in_items"})
		->arg_init(5,make_smart<ExprConstInt>(-1))
;
addExtern<DAS_BIND_FUN(ImGui::IsWindowCollapsed)>(*this, lib, "IsWindowCollapsed",SideEffects::worstDefault, "ImGui::IsWindowCollapsed")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::VSliderScalar)>(*this, lib, "VSliderScalar",SideEffects::worstDefault, "ImGui::VSliderScalar")
	->args({"label","size","data_type","p_data","p_min","p_max","format","flags"})
		->arg_init(6,make_smart<ExprConstString>(""))
		->arg_type(7,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(7,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::Render)>(*this, lib, "Render",SideEffects::worstDefault, "ImGui::Render")
	->args({})
;
addExtern<void (*)(ImGuiCol, const ImVec4 &),ImGui::PushStyleColor>(*this, lib, "PushStyleColor",SideEffects::worstDefault, "ImGui::PushStyleColor")
	->args({"idx","col"})
		->arg_type(0,makeType<ImGuiCol_>(lib))
;
addExtern<DAS_BIND_FUN(ImGui::EndFrame)>(*this, lib, "EndFrame",SideEffects::worstDefault, "ImGui::EndFrame")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::PopStyleColor)>(*this, lib, "PopStyleColor",SideEffects::worstDefault, "ImGui::PopStyleColor")
	->args({"count"})
		->arg_init(0,make_smart<ExprConstInt>(1))
;
addExtern<bool (*)(const char *, ImGuiDataType, void *, float, const void *, const void *, const char *, ImGuiSliderFlags),ImGui::DragScalar>(*this, lib, "DragScalar",SideEffects::worstDefault, "ImGui::DragScalar")
	->args({"label","data_type","p_data","v_speed","p_min","p_max","format","flags"})
		->arg_init(4,make_smart<ExprConstPtr>())
		->arg_init(5,make_smart<ExprConstPtr>())
		->arg_init(6,make_smart<ExprConstString>(""))
		->arg_type(7,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(7,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::SliderInt2)>(*this, lib, "SliderInt2",SideEffects::worstDefault, "ImGui::SliderInt2")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%d"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::TreeAdvanceToLabelPos)>(*this, lib, "TreeAdvanceToLabelPos",SideEffects::worstDefault, "ImGui::TreeAdvanceToLabelPos")
	->args({})
;
addExtern<bool (*)(const char *, int *, int),ImGui::CheckboxFlags>(*this, lib, "CheckboxFlags",SideEffects::worstDefault, "ImGui::CheckboxFlags")
	->args({"label","flags","flags_value"})
;
addExtern<bool (*)(const char *, unsigned int *, unsigned int),ImGui::CheckboxFlags>(*this, lib, "CheckboxFlags",SideEffects::worstDefault, "ImGui::CheckboxFlags")
	->args({"label","flags","flags_value"})
;
addExtern<DAS_BIND_FUN(ImGui::BeginMenu)>(*this, lib, "BeginMenu",SideEffects::worstDefault, "ImGui::BeginMenu")
	->args({"label","enabled"})
		->arg_init(1,make_smart<ExprConstBool>(true))
;
addExtern<bool (*)(const char *, float *, float, float, float, const char *, float),ImGui::DragFloat>(*this, lib, "DragFloat",SideEffects::worstDefault, "ImGui::DragFloat")
	->args({"label","v","v_speed","v_min","v_max","format","power"})
;
addExtern<ImU32 (*)(const ImVec4 &),ImGui::GetColorU32>(*this, lib, "GetColorU32",SideEffects::worstDefault, "ImGui::GetColorU32")
	->args({"col"})
;
addExtern<DAS_BIND_FUN(ImGui::SetScrollHereY)>(*this, lib, "SetScrollHereY",SideEffects::worstDefault, "ImGui::SetScrollHereY")
	->args({"center_y_ratio"})
		->arg_init(0,make_smart<ExprConstFloat>(0.5))
;
addExtern<DAS_BIND_FUN(ImGui::TableSetColumnIndex)>(*this, lib, "TableSetColumnIndex",SideEffects::worstDefault, "ImGui::TableSetColumnIndex")
	->args({"column_n"})
;
addExtern<DAS_BIND_FUN(ImGui::ColorButton)>(*this, lib, "ColorButton",SideEffects::worstDefault, "ImGui::ColorButton")
	->args({"desc_id","col","flags","size"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetScrollMaxY)>(*this, lib, "GetScrollMaxY",SideEffects::worstDefault, "ImGui::GetScrollMaxY")
	->args({})
;
addExtern<bool (*)(const char *, float *, float, float, float, const char *, ImGuiSliderFlags),ImGui::DragFloat3>(*this, lib, "DragFloat3",SideEffects::worstDefault, "ImGui::DragFloat3")
	->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1))
		->arg_init(3,make_smart<ExprConstFloat>(0))
		->arg_init(4,make_smart<ExprConstFloat>(0))
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetScrollMaxX)>(*this, lib, "GetScrollMaxX",SideEffects::worstDefault, "ImGui::GetScrollMaxX")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::EndChildFrame)>(*this, lib, "EndChildFrame",SideEffects::worstDefault, "ImGui::EndChildFrame")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::ShowAboutWindow)>(*this, lib, "ShowAboutWindow",SideEffects::worstDefault, "ImGui::ShowAboutWindow")
	->args({"p_open"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::GetKeyIndex)>(*this, lib, "GetKeyIndex",SideEffects::worstDefault, "ImGui::GetKeyIndex")
	->args({"imgui_key"})
		->arg_type(0,makeType<ImGuiKey_>(lib))
;
addExtern<DAS_BIND_FUN(ImGui::Spacing)>(*this, lib, "Spacing",SideEffects::worstDefault, "ImGui::Spacing")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SetColumnWidth)>(*this, lib, "SetColumnWidth",SideEffects::worstDefault, "ImGui::SetColumnWidth")
	->args({"column_index","width"})
;
addExtern<DAS_BIND_FUN(ImGui::ColorConvertU32ToFloat4), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "ColorConvertU32ToFloat4",SideEffects::worstDefault, "ImGui::ColorConvertU32ToFloat4")
	->args({"in"})
;
addExtern<DAS_BIND_FUN(ImGui::IsAnyMouseDown)>(*this, lib, "IsAnyMouseDown",SideEffects::worstDefault, "ImGui::IsAnyMouseDown")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::CalcItemWidth)>(*this, lib, "CalcItemWidth",SideEffects::worstDefault, "ImGui::CalcItemWidth")
	->args({})
;
addExtern<void (*)(const char *, const float *, int, int, const char *, float, float, ImVec2, int),ImGui::PlotLines>(*this, lib, "PlotLines",SideEffects::worstDefault, "ImGui::PlotLines")
	->args({"label","values","values_count","values_offset","overlay_text","scale_min","scale_max","graph_size","stride"})
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstString>(""))
		->arg_init(5,make_smart<ExprConstFloat>(3.40282347E+38))
		->arg_init(6,make_smart<ExprConstFloat>(3.40282347E+38))
;
addExtern<void (*)(const char *, unsigned int),ImGui::Value>(*this, lib, "Value",SideEffects::worstDefault, "ImGui::Value")
	->args({"prefix","v"})
;
addExtern<DAS_BIND_FUN(ImGui::SliderAngle)>(*this, lib, "SliderAngle",SideEffects::worstDefault, "ImGui::SliderAngle")
	->args({"label","v_rad","v_degrees_min","v_degrees_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(-360))
		->arg_init(3,make_smart<ExprConstFloat>(+360))
		->arg_init(4,make_smart<ExprConstString>("%.0f deg"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::LogButtons)>(*this, lib, "LogButtons",SideEffects::worstDefault, "ImGui::LogButtons")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::GetCursorPosX)>(*this, lib, "GetCursorPosX",SideEffects::worstDefault, "ImGui::GetCursorPosX")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::TabItemButton)>(*this, lib, "TabItemButton",SideEffects::worstDefault, "ImGui::TabItemButton")
	->args({"label","flags"})
		->arg_init(1,make_smart<ExprConstInt>(0))
;
addExtern<DAS_BIND_FUN(ImGui::EndTooltip)>(*this, lib, "EndTooltip",SideEffects::worstDefault, "ImGui::EndTooltip")
	->args({})
;
addExtern<bool (*)(const ImVec2 &),ImGui::IsRectVisible>(*this, lib, "IsRectVisible",SideEffects::worstDefault, "ImGui::IsRectVisible")
	->args({"size"})
;
addExtern<DAS_BIND_FUN(ImGui::CalcTextSize), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "CalcTextSize",SideEffects::worstDefault, "ImGui::CalcTextSize")
	->args({"text","text_end","hide_text_after_double_hash","wrap_width"})
		->arg_init(1,make_smart<ExprConstString>(""))
		->arg_init(2,make_smart<ExprConstBool>(false))
		->arg_init(3,make_smart<ExprConstFloat>(-1))
;
addExtern<bool (*)(const char *, float *, float, float, float, const char *, float),ImGui::DragFloat3>(*this, lib, "DragFloat3",SideEffects::worstDefault, "ImGui::DragFloat3")
	->args({"label","v","v_speed","v_min","v_max","format","power"})
;
addExtern<DAS_BIND_FUN(ImGui::SameLine)>(*this, lib, "SameLine",SideEffects::worstDefault, "ImGui::SameLine")
	->args({"offset_from_start_x","spacing"})
		->arg_init(0,make_smart<ExprConstFloat>(0))
		->arg_init(1,make_smart<ExprConstFloat>(-1))
;
addExtern<DAS_BIND_FUN(ImGui::Dummy)>(*this, lib, "Dummy",SideEffects::worstDefault, "ImGui::Dummy")
	->args({"size"})
;
addExtern<DAS_BIND_FUN(ImGui::BeginGroup)>(*this, lib, "BeginGroup",SideEffects::worstDefault, "ImGui::BeginGroup")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::EndListBox)>(*this, lib, "EndListBox",SideEffects::worstDefault, "ImGui::EndListBox")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::BeginTabBar)>(*this, lib, "BeginTabBar",SideEffects::worstDefault, "ImGui::BeginTabBar")
	->args({"str_id","flags"})
		->arg_type(1,makeType<ImGuiTabBarFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTabBarFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::TextV)>(*this, lib, "TextV",SideEffects::worstDefault, "ImGui::TextV")
	->args({"fmt","args"})
;
addExtern<DAS_BIND_FUN(ImGui::BeginMainMenuBar)>(*this, lib, "BeginMainMenuBar",SideEffects::worstDefault, "ImGui::BeginMainMenuBar")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SetStateStorage)>(*this, lib, "SetStateStorage",SideEffects::worstDefault, "ImGui::SetStateStorage")
	->args({"storage"})
;
addExtern<DAS_BIND_FUN(ImGui::SliderInt4)>(*this, lib, "SliderInt4",SideEffects::worstDefault, "ImGui::SliderInt4")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%d"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetKeyPressedAmount)>(*this, lib, "GetKeyPressedAmount",SideEffects::worstDefault, "ImGui::GetKeyPressedAmount")
	->args({"key_index","repeat_delay","rate"})
;
addExtern<bool (*)(const char *, ImGuiDataType, void *, int, float, const void *, const void *, const char *, float),ImGui::DragScalarN>(*this, lib, "DragScalarN",SideEffects::worstDefault, "ImGui::DragScalarN")
	->args({"label","data_type","p_data","components","v_speed","p_min","p_max","format","power"})
;
addExtern<DAS_BIND_FUN(ImGui::LabelTextV)>(*this, lib, "LabelTextV",SideEffects::worstDefault, "ImGui::LabelTextV")
	->args({"label","fmt","args"})
;
addExtern<ImU32 (*)(ImGuiCol, float),ImGui::GetColorU32>(*this, lib, "GetColorU32",SideEffects::worstDefault, "ImGui::GetColorU32")
	->args({"idx","alpha_mul"})
		->arg_type(0,makeType<ImGuiCol_>(lib))
		->arg_init(1,make_smart<ExprConstFloat>(1))
;
addExtern<DAS_BIND_FUN(ImGui::ColorPicker4)>(*this, lib, "ColorPicker4",SideEffects::worstDefault, "ImGui::ColorPicker4")
	->args({"label","col","flags","ref_col"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)))
		->arg_init(3,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::PushButtonRepeat)>(*this, lib, "PushButtonRepeat",SideEffects::worstDefault, "ImGui::PushButtonRepeat")
	->args({"repeat"})
;
addExtern<DAS_BIND_FUN(ImGui::BulletTextV)>(*this, lib, "BulletTextV",SideEffects::worstDefault, "ImGui::BulletTextV")
	->args({"fmt","args"})
;
addExtern<DAS_BIND_FUN(ImGui::GetColumnOffset)>(*this, lib, "GetColumnOffset",SideEffects::worstDefault, "ImGui::GetColumnOffset")
	->args({"column_index"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
;
addExtern<bool (*)(const char *, ImGuiTreeNodeFlags, const char *, va_list),ImGui::TreeNodeExV>(*this, lib, "TreeNodeExV",SideEffects::worstDefault, "ImGui::TreeNodeExV")
	->args({"str_id","flags","fmt","args"})
;
addExtern<bool (*)(const void *, const char *, va_list),ImGui::TreeNodeV>(*this, lib, "TreeNodeV",SideEffects::worstDefault, "ImGui::TreeNodeV")
	->args({"ptr_id","fmt","args"})
;
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowContentSize)>(*this, lib, "SetNextWindowContentSize",SideEffects::worstDefault, "ImGui::SetNextWindowContentSize")
	->args({"size"})
;
addExtern<void (*)(const char *, const ImVec2 &, ImGuiCond),ImGui::SetWindowSize>(*this, lib, "SetWindowSize",SideEffects::worstDefault, "ImGui::SetWindowSize")
	->args({"name","size","cond"})
		->arg_type(2,makeType<ImGuiCond_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
addExtern<bool (*)(const char *, bool),ImGui::RadioButton>(*this, lib, "RadioButton",SideEffects::worstDefault, "ImGui::RadioButton")
	->args({"label","active"})
;
addExtern<ImGuiID (*)(const char *, const char *),ImGui::GetID>(*this, lib, "GetID",SideEffects::worstDefault, "ImGui::GetID")
	->args({"str_id_begin","str_id_end"})
;
addExtern<DAS_BIND_FUN(ImGui::GetWindowContentRegionMax), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetWindowContentRegionMax",SideEffects::worstDefault, "ImGui::GetWindowContentRegionMax")
	->args({})
;
addExtern<bool (*)(const char *, ImGuiTreeNodeFlags),ImGui::CollapsingHeader>(*this, lib, "CollapsingHeader",SideEffects::worstDefault, "ImGui::CollapsingHeader")
	->args({"label","flags"})
		->arg_init(1,make_smart<ExprConstInt>(0))
;
addExtern<DAS_BIND_FUN(ImGui::SetScrollHereX)>(*this, lib, "SetScrollHereX",SideEffects::worstDefault, "ImGui::SetScrollHereX")
	->args({"center_x_ratio"})
		->arg_init(0,make_smart<ExprConstFloat>(0.5))
;
addExtern<DAS_BIND_FUN(ImGui::GetCursorPosY)>(*this, lib, "GetCursorPosY",SideEffects::worstDefault, "ImGui::GetCursorPosY")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::PopTextWrapPos)>(*this, lib, "PopTextWrapPos",SideEffects::worstDefault, "ImGui::PopTextWrapPos")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::GetContentRegionAvail), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetContentRegionAvail",SideEffects::worstDefault, "ImGui::GetContentRegionAvail")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::PopItemWidth)>(*this, lib, "PopItemWidth",SideEffects::worstDefault, "ImGui::PopItemWidth")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsAnyItemHovered)>(*this, lib, "IsAnyItemHovered",SideEffects::worstDefault, "ImGui::IsAnyItemHovered")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsMouseDown)>(*this, lib, "IsMouseDown",SideEffects::worstDefault, "ImGui::IsMouseDown")
	->args({"button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
;
addExtern<DAS_BIND_FUN(ImGui::LoadIniSettingsFromDisk)>(*this, lib, "LoadIniSettingsFromDisk",SideEffects::worstDefault, "ImGui::LoadIniSettingsFromDisk")
	->args({"ini_filename"})
;
addExtern<bool (*)(const char *, ImGuiDataType, void *, float, const void *, const void *, const char *, float),ImGui::DragScalar>(*this, lib, "DragScalar",SideEffects::worstDefault, "ImGui::DragScalar")
	->args({"label","data_type","p_data","v_speed","p_min","p_max","format","power"})
;
addExtern<bool (*)(const char *, float *, float, float, const char *, float),ImGui::SliderFloat4>(*this, lib, "SliderFloat4",SideEffects::worstDefault, "ImGui::SliderFloat4")
	->args({"label","v","v_min","v_max","format","power"})
;
addExtern<DAS_BIND_FUN(ImGui::DragInt4)>(*this, lib, "DragInt4",SideEffects::worstDefault, "ImGui::DragInt4")
	->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1))
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstString>("%d"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::EndMenu)>(*this, lib, "EndMenu",SideEffects::worstDefault, "ImGui::EndMenu")
	->args({})
;
addExtern<bool (*)(const char *, float *, float, float, float, const char *, ImGuiSliderFlags),ImGui::DragFloat2>(*this, lib, "DragFloat2",SideEffects::worstDefault, "ImGui::DragFloat2")
	->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1))
		->arg_init(3,make_smart<ExprConstFloat>(0))
		->arg_init(4,make_smart<ExprConstFloat>(0))
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::SetTooltipV)>(*this, lib, "SetTooltipV",SideEffects::worstDefault, "ImGui::SetTooltipV")
	->args({"fmt","args"})
;
addExtern<DAS_BIND_FUN(ImGui::StyleColorsDark)>(*this, lib, "StyleColorsDark",SideEffects::worstDefault, "ImGui::StyleColorsDark")
	->args({"dst"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::OpenPopupOnItemClick)>(*this, lib, "OpenPopupOnItemClick",SideEffects::worstDefault, "ImGui::OpenPopupOnItemClick")
	->args({"str_id","popup_flags"})
		->arg_init(0,make_smart<ExprConstString>(""))
		->arg_init(1,make_smart<ExprConstInt>(1))
;
addExtern<DAS_BIND_FUN(ImGui::DebugCheckVersionAndDataLayout)>(*this, lib, "DebugCheckVersionAndDataLayout",SideEffects::worstDefault, "ImGui::DebugCheckVersionAndDataLayout")
	->args({"version_str","sz_io","sz_style","sz_vec2","sz_vec4","sz_drawvert","sz_drawidx"})
;
addExtern<DAS_BIND_FUN(ImGui::EndMenuBar)>(*this, lib, "EndMenuBar",SideEffects::worstDefault, "ImGui::EndMenuBar")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::NextColumn)>(*this, lib, "NextColumn",SideEffects::worstDefault, "ImGui::NextColumn")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SetDragDropPayload)>(*this, lib, "SetDragDropPayload",SideEffects::worstDefault, "ImGui::SetDragDropPayload")
	->args({"type","data","sz","cond"})
		->arg_type(3,makeType<ImGuiCond_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::IsItemVisible)>(*this, lib, "IsItemVisible",SideEffects::worstDefault, "ImGui::IsItemVisible")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsMouseDoubleClicked)>(*this, lib, "IsMouseDoubleClicked",SideEffects::worstDefault, "ImGui::IsMouseDoubleClicked")
	->args({"button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
;
addExtern<DAS_BIND_FUN(ImGui::SetMouseCursor)>(*this, lib, "SetMouseCursor",SideEffects::worstDefault, "ImGui::SetMouseCursor")
	->args({"cursor_type"})
;
addExtern<DAS_BIND_FUN(ImGui::TableGetSortSpecs)>(*this, lib, "TableGetSortSpecs",SideEffects::worstDefault, "ImGui::TableGetSortSpecs")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::ArrowButton)>(*this, lib, "ArrowButton",SideEffects::worstDefault, "ImGui::ArrowButton")
	->args({"str_id","dir"})
;
addExtern<DAS_BIND_FUN(ImGui::TreePop)>(*this, lib, "TreePop",SideEffects::worstDefault, "ImGui::TreePop")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::GetMainViewport)>(*this, lib, "GetMainViewport",SideEffects::worstDefault, "ImGui::GetMainViewport")
	->args({})
;
addExtern<bool (*)(const char *, ImGuiDataType, void *, int, const void *, const void *, const char *, float),ImGui::SliderScalarN>(*this, lib, "SliderScalarN",SideEffects::worstDefault, "ImGui::SliderScalarN")
	->args({"label","data_type","p_data","components","p_min","p_max","format","power"})
;
addExtern<DAS_BIND_FUN(ImGui::SliderInt3)>(*this, lib, "SliderInt3",SideEffects::worstDefault, "ImGui::SliderInt3")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%d"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::Button)>(*this, lib, "Button",SideEffects::worstDefault, "ImGui::Button")
	->args({"label","size"})
;
addExtern<bool (*)(const char *, float *, float, float, float, const char *, float),ImGui::DragFloat4>(*this, lib, "DragFloat4",SideEffects::worstDefault, "ImGui::DragFloat4")
	->args({"label","v","v_speed","v_min","v_max","format","power"})
;
addExtern<bool (*)(const char *, ImGuiTreeNodeFlags),ImGui::TreeNodeEx>(*this, lib, "TreeNodeEx",SideEffects::worstDefault, "ImGui::TreeNodeEx")
	->args({"label","flags"})
		->arg_init(1,make_smart<ExprConstInt>(0))
;
addExtern<DAS_BIND_FUN(ImGui::GetFrameHeight)>(*this, lib, "GetFrameHeight",SideEffects::worstDefault, "ImGui::GetFrameHeight")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::InputFloat)>(*this, lib, "InputFloat",SideEffects::worstDefault, "ImGui::InputFloat")
	->args({"label","v","step","step_fast","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(0))
		->arg_init(3,make_smart<ExprConstFloat>(0))
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
addExtern<void (*)(const char *),ImGui::PushID>(*this, lib, "PushID",SideEffects::worstDefault, "ImGui::PushID")
	->args({"str_id"})
;
addExtern<DAS_BIND_FUN(ImGui::SaveIniSettingsToDisk)>(*this, lib, "SaveIniSettingsToDisk",SideEffects::worstDefault, "ImGui::SaveIniSettingsToDisk")
	->args({"ini_filename"})
;
addExtern<void (*)(bool, ImGuiCond),ImGui::SetWindowCollapsed>(*this, lib, "SetWindowCollapsed",SideEffects::worstDefault, "ImGui::SetWindowCollapsed")
	->args({"collapsed","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::SetNextTreeNodeOpen)>(*this, lib, "SetNextTreeNodeOpen",SideEffects::worstDefault, "ImGui::SetNextTreeNodeOpen")
	->args({"open","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
addExtern<bool (*)(const char *, float *, float, float, const char *, ImGuiSliderFlags),ImGui::SliderFloat>(*this, lib, "SliderFloat",SideEffects::worstDefault, "ImGui::SliderFloat")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<void (*)(const ImVec2 &, ImGuiCond),ImGui::SetWindowSize>(*this, lib, "SetWindowSize",SideEffects::worstDefault, "ImGui::SetWindowSize")
	->args({"size","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::SetCursorPos)>(*this, lib, "SetCursorPos",SideEffects::worstDefault, "ImGui::SetCursorPos")
	->args({"local_pos"})
;
addExtern<DAS_BIND_FUN(ImGui::ImageButton)>(*this, lib, "ImageButton",SideEffects::worstDefault, "ImGui::ImageButton")
	->args({"user_texture_id","size","uv0","uv1","frame_padding","bg_col","tint_col"})
		->arg_init(4,make_smart<ExprConstInt>(-1))
;
addExtern<DAS_BIND_FUN(ImGui::LoadIniSettingsFromMemory)>(*this, lib, "LoadIniSettingsFromMemory",SideEffects::worstDefault, "ImGui::LoadIniSettingsFromMemory")
	->args({"ini_data","ini_size"})
;
addExtern<DAS_BIND_FUN(ImGui::BeginCombo)>(*this, lib, "BeginCombo",SideEffects::worstDefault, "ImGui::BeginCombo")
	->args({"label","preview_value","flags"})
		->arg_init(2,make_smart<ExprConstInt>(0))
;
addExtern<DAS_BIND_FUN(ImGui::GetContentRegionMax), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetContentRegionMax",SideEffects::worstDefault, "ImGui::GetContentRegionMax")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::GetStyle), SimNode_ExtFuncCallRef>(*this, lib, "GetStyle",SideEffects::worstDefault, "ImGui::GetStyle")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::BeginTabItem)>(*this, lib, "BeginTabItem",SideEffects::worstDefault, "ImGui::BeginTabItem")
	->args({"label","p_open","flags"})
		->arg_init(1,make_smart<ExprConstPtr>())
		->arg_init(2,make_smart<ExprConstInt>(0))
;
addExtern<DAS_BIND_FUN(ImGui::BeginChildFrame)>(*this, lib, "BeginChildFrame",SideEffects::worstDefault, "ImGui::BeginChildFrame")
	->args({"id","size","flags"})
		->arg_type(2,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::TableSetupColumn)>(*this, lib, "TableSetupColumn",SideEffects::worstDefault, "ImGui::TableSetupColumn")
	->args({"label","flags","init_width_or_weight","user_id"})
		->arg_init(1,make_smart<ExprConstInt>(0))
		->arg_init(2,make_smart<ExprConstFloat>(0))
;
addExtern<DAS_BIND_FUN(ImGui::ProgressBar)>(*this, lib, "ProgressBar",SideEffects::worstDefault, "ImGui::ProgressBar")
	->args({"fraction","size_arg","overlay"})
		->arg_init(2,make_smart<ExprConstString>(""))
;
addExtern<void (*)(const ImVec2 &, ImGuiCond),ImGui::SetWindowPos>(*this, lib, "SetWindowPos",SideEffects::worstDefault, "ImGui::SetWindowPos")
	->args({"pos","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::TextWrappedV)>(*this, lib, "TextWrappedV",SideEffects::worstDefault, "ImGui::TextWrappedV")
	->args({"fmt","args"})
;
addExtern<DAS_BIND_FUN(ImGui::TableSetBgColor)>(*this, lib, "TableSetBgColor",SideEffects::worstDefault, "ImGui::TableSetBgColor")
	->args({"target","color","column_n"})
		->arg_init(2,make_smart<ExprConstInt>(-1))
;
addExtern<void (*)(ImGuiCol, ImU32),ImGui::PushStyleColor>(*this, lib, "PushStyleColor",SideEffects::worstDefault, "ImGui::PushStyleColor")
	->args({"idx","col"})
		->arg_type(0,makeType<ImGuiCol_>(lib))
;
addExtern<DAS_BIND_FUN(ImGui::CalcListClipping)>(*this, lib, "CalcListClipping",SideEffects::worstDefault, "ImGui::CalcListClipping")
	->args({"items_count","items_height","out_items_display_start","out_items_display_end"})
;
addExtern<bool (*)(const char *, const ImVec2 &),ImGui::ListBoxHeader>(*this, lib, "ListBoxHeader",SideEffects::worstDefault, "ImGui::ListBoxHeader")
	->args({"label","size"})
;
addExtern<DAS_BIND_FUN(ImGui::ColorConvertHSVtoRGB)>(*this, lib, "ColorConvertHSVtoRGB",SideEffects::worstDefault, "ImGui::ColorConvertHSVtoRGB")
	->args({"h","s","v","out_r","out_g","out_b"})
;
addExtern<bool (*)(const char *, float *, float, float, float, const char *, ImGuiSliderFlags),ImGui::DragFloat4>(*this, lib, "DragFloat4",SideEffects::worstDefault, "ImGui::DragFloat4")
	->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1))
		->arg_init(3,make_smart<ExprConstFloat>(0))
		->arg_init(4,make_smart<ExprConstFloat>(0))
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::TableGetRowIndex)>(*this, lib, "TableGetRowIndex",SideEffects::worstDefault, "ImGui::TableGetRowIndex")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::BeginDragDropTarget)>(*this, lib, "BeginDragDropTarget",SideEffects::worstDefault, "ImGui::BeginDragDropTarget")
	->args({})
;
addExtern<void (*)(),ImGui::SetWindowFocus>(*this, lib, "SetWindowFocus",SideEffects::worstDefault, "ImGui::SetWindowFocus")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::ShowUserGuide)>(*this, lib, "ShowUserGuide",SideEffects::worstDefault, "ImGui::ShowUserGuide")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SaveIniSettingsToMemory)>(*this, lib, "SaveIniSettingsToMemory",SideEffects::worstDefault, "ImGui::SaveIniSettingsToMemory")
	->args({"out_ini_size"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::ShowMetricsWindow)>(*this, lib, "ShowMetricsWindow",SideEffects::worstDefault, "ImGui::ShowMetricsWindow")
	->args({"p_open"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::GetFontSize)>(*this, lib, "GetFontSize",SideEffects::worstDefault, "ImGui::GetFontSize")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::BeginTable)>(*this, lib, "BeginTable",SideEffects::worstDefault, "ImGui::BeginTable")
	->args({"str_id","column","flags","outer_size","inner_width"})
		->arg_type(2,makeType<ImGuiTableFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTableFlags_>(lib)))
		->arg_init(4,make_smart<ExprConstFloat>(0))
;
addExtern<DAS_BIND_FUN(ImGui::InputFloat2)>(*this, lib, "InputFloat2",SideEffects::worstDefault, "ImGui::InputFloat2")
	->args({"label","v","format","flags"})
		->arg_init(2,make_smart<ExprConstString>("%.3f"))
		->arg_type(3,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetWindowWidth)>(*this, lib, "GetWindowWidth",SideEffects::worstDefault, "ImGui::GetWindowWidth")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::GetCurrentContext)>(*this, lib, "GetCurrentContext",SideEffects::worstDefault, "ImGui::GetCurrentContext")
	->args({})
;
addExtern<bool (*)(const char *, ImGuiDataType, void *, const void *, const void *, const char *, ImGuiSliderFlags),ImGui::SliderScalar>(*this, lib, "SliderScalar",SideEffects::worstDefault, "ImGui::SliderScalar")
	->args({"label","data_type","p_data","p_min","p_max","format","flags"})
		->arg_init(5,make_smart<ExprConstString>(""))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<bool (*)(const char *, const ImVec2 &, bool, ImGuiWindowFlags),ImGui::BeginChild>(*this, lib, "BeginChild",SideEffects::worstDefault, "ImGui::BeginChild")
	->args({"str_id","size","border","flags"})
		->arg_init(2,make_smart<ExprConstBool>(false))
		->arg_type(3,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::Begin)>(*this, lib, "Begin",SideEffects::worstDefault, "ImGui::Begin")
	->args({"name","p_open","flags"})
		->arg_init(1,make_smart<ExprConstPtr>())
		->arg_type(2,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetTextLineHeight)>(*this, lib, "GetTextLineHeight",SideEffects::worstDefault, "ImGui::GetTextLineHeight")
	->args({})
;
addExtern<void (*)(const char *, float, const char *),ImGui::Value>(*this, lib, "Value",SideEffects::worstDefault, "ImGui::Value")
	->args({"prefix","v","float_format"})
		->arg_init(2,make_smart<ExprConstString>(""))
;
addExtern<DAS_BIND_FUN(ImGui::GetWindowContentRegionMin), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetWindowContentRegionMin",SideEffects::worstDefault, "ImGui::GetWindowContentRegionMin")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::GetTextLineHeightWithSpacing)>(*this, lib, "GetTextLineHeightWithSpacing",SideEffects::worstDefault, "ImGui::GetTextLineHeightWithSpacing")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsWindowAppearing)>(*this, lib, "IsWindowAppearing",SideEffects::worstDefault, "ImGui::IsWindowAppearing")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowBgAlpha)>(*this, lib, "SetNextWindowBgAlpha",SideEffects::worstDefault, "ImGui::SetNextWindowBgAlpha")
	->args({"alpha"})
;
addExtern<DAS_BIND_FUN(ImGui::GetScrollY)>(*this, lib, "GetScrollY",SideEffects::worstDefault, "ImGui::GetScrollY")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::PopAllowKeyboardFocus)>(*this, lib, "PopAllowKeyboardFocus",SideEffects::worstDefault, "ImGui::PopAllowKeyboardFocus")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::Image)>(*this, lib, "Image",SideEffects::worstDefault, "ImGui::Image")
	->args({"user_texture_id","size","uv0","uv1","tint_col","border_col"})
;
addExtern<DAS_BIND_FUN(ImGui::LogToClipboard)>(*this, lib, "LogToClipboard",SideEffects::worstDefault, "ImGui::LogToClipboard")
	->args({"auto_open_depth"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
;
addExtern<DAS_BIND_FUN(ImGui::LogFinish)>(*this, lib, "LogFinish",SideEffects::worstDefault, "ImGui::LogFinish")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SetItemAllowOverlap)>(*this, lib, "SetItemAllowOverlap",SideEffects::worstDefault, "ImGui::SetItemAllowOverlap")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::GetIO), SimNode_ExtFuncCallRef>(*this, lib, "GetIO",SideEffects::worstDefault, "ImGui::GetIO")
	->args({})
;
addExtern<bool (*)(const ImVec2 &, const ImVec2 &),ImGui::IsRectVisible>(*this, lib, "IsRectVisible",SideEffects::worstDefault, "ImGui::IsRectVisible")
	->args({"rect_min","rect_max"})
;
addExtern<DAS_BIND_FUN(ImGui::TextDisabledV)>(*this, lib, "TextDisabledV",SideEffects::worstDefault, "ImGui::TextDisabledV")
	->args({"fmt","args"})
;
addExtern<DAS_BIND_FUN(ImGui::DragFloatRange2)>(*this, lib, "DragFloatRange2",SideEffects::worstDefault, "ImGui::DragFloatRange2")
	->args({"label","v_current_min","v_current_max","v_speed","v_min","v_max","format","format_max","flags"})
		->arg_init(3,make_smart<ExprConstFloat>(1))
		->arg_init(4,make_smart<ExprConstFloat>(0))
		->arg_init(5,make_smart<ExprConstFloat>(0))
		->arg_init(6,make_smart<ExprConstString>("%.3f"))
		->arg_init(7,make_smart<ExprConstString>(""))
		->arg_type(8,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(8,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetColumnWidth)>(*this, lib, "GetColumnWidth",SideEffects::worstDefault, "ImGui::GetColumnWidth")
	->args({"column_index"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
;
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowCollapsed)>(*this, lib, "SetNextWindowCollapsed",SideEffects::worstDefault, "ImGui::SetNextWindowCollapsed")
	->args({"collapsed","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::Indent)>(*this, lib, "Indent",SideEffects::worstDefault, "ImGui::Indent")
	->args({"indent_w"})
		->arg_init(0,make_smart<ExprConstFloat>(0))
;
addExtern<DAS_BIND_FUN(ImGui::ColorConvertFloat4ToU32)>(*this, lib, "ColorConvertFloat4ToU32",SideEffects::worstDefault, "ImGui::ColorConvertFloat4ToU32")
	->args({"in"})
;
addExtern<DAS_BIND_FUN(ImGui::SetCurrentContext)>(*this, lib, "SetCurrentContext",SideEffects::worstDefault, "ImGui::SetCurrentContext")
	->args({"ctx"})
;
addExtern<DAS_BIND_FUN(ImGui::IsMouseHoveringRect)>(*this, lib, "IsMouseHoveringRect",SideEffects::worstDefault, "ImGui::IsMouseHoveringRect")
	->args({"r_min","r_max","clip"})
		->arg_init(2,make_smart<ExprConstBool>(true))
;
addExtern<DAS_BIND_FUN(ImGui::GetItemRectSize), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetItemRectSize",SideEffects::worstDefault, "ImGui::GetItemRectSize")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::InputDouble)>(*this, lib, "InputDouble",SideEffects::worstDefault, "ImGui::InputDouble")
	->args({"label","v","step","step_fast","format","flags"})
		// step : double = 0
		// step_fast : double = 0
		->arg_init(4,make_smart<ExprConstString>("%.6f"))
		->arg_type(5,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetMousePosOnOpeningCurrentPopup), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetMousePosOnOpeningCurrentPopup",SideEffects::worstDefault, "ImGui::GetMousePosOnOpeningCurrentPopup")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::PushFont)>(*this, lib, "PushFont",SideEffects::worstDefault, "ImGui::PushFont")
	->args({"font"})
;
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowSizeConstraints)>(*this, lib, "SetNextWindowSizeConstraints",SideEffects::worstDefault, "ImGui::SetNextWindowSizeConstraints")
	->args({"size_min","size_max","custom_callback","custom_callback_data"})
		->arg_init(2,make_smart<ExprConstPtr>())
		->arg_init(3,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::Separator)>(*this, lib, "Separator",SideEffects::worstDefault, "ImGui::Separator")
	->args({})
;
addExtern<bool (*)(const char *, ImGuiDataType, void *, int, float, const void *, const void *, const char *, ImGuiSliderFlags),ImGui::DragScalarN>(*this, lib, "DragScalarN",SideEffects::worstDefault, "ImGui::DragScalarN")
	->args({"label","data_type","p_data","components","v_speed","p_min","p_max","format","flags"})
		->arg_init(5,make_smart<ExprConstPtr>())
		->arg_init(6,make_smart<ExprConstPtr>())
		->arg_init(7,make_smart<ExprConstString>(""))
		->arg_type(8,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(8,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::SetCursorPosX)>(*this, lib, "SetCursorPosX",SideEffects::worstDefault, "ImGui::SetCursorPosX")
	->args({"local_x"})
;
addExtern<void (*)(const char *, float (*)(void *, int), void *, int, int, const char *, float, float, ImVec2),ImGui::PlotLines>(*this, lib, "PlotLines",SideEffects::worstDefault, "ImGui::PlotLines")
	->args({"label","values_getter","data","values_count","values_offset","overlay_text","scale_min","scale_max","graph_size"})
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstString>(""))
		->arg_init(6,make_smart<ExprConstFloat>(3.40282347E+38))
		->arg_init(7,make_smart<ExprConstFloat>(3.40282347E+38))
;
addExtern<DAS_BIND_FUN(ImGui::IsWindowHovered)>(*this, lib, "IsWindowHovered",SideEffects::worstDefault, "ImGui::IsWindowHovered")
	->args({"flags"})
		->arg_init(0,make_smart<ExprConstInt>(0))
;
addExtern<DAS_BIND_FUN(ImGui::VSliderFloat)>(*this, lib, "VSliderFloat",SideEffects::worstDefault, "ImGui::VSliderFloat")
	->args({"label","size","v","v_min","v_max","format","flags"})
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::ColorEdit3)>(*this, lib, "ColorEdit3",SideEffects::worstDefault, "ImGui::ColorEdit3")
	->args({"label","col","flags"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::SetClipboardText)>(*this, lib, "SetClipboardText",SideEffects::worstDefault, "ImGui::SetClipboardText")
	->args({"text"})
;
addExtern<DAS_BIND_FUN(ImGui::IsWindowFocused)>(*this, lib, "IsWindowFocused",SideEffects::worstDefault, "ImGui::IsWindowFocused")
	->args({"flags"})
		->arg_init(0,make_smart<ExprConstInt>(0))
;
addExtern<DAS_BIND_FUN(ImGui::IsAnyItemFocused)>(*this, lib, "IsAnyItemFocused",SideEffects::worstDefault, "ImGui::IsAnyItemFocused")
	->args({})
;
addExtern<void (*)(const char *, bool, ImGuiCond),ImGui::SetWindowCollapsed>(*this, lib, "SetWindowCollapsed",SideEffects::worstDefault, "ImGui::SetWindowCollapsed")
	->args({"name","collapsed","cond"})
		->arg_type(2,makeType<ImGuiCond_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
addExtern<bool (*)(const char *, int *, const char *, int),ImGui::Combo>(*this, lib, "Combo",SideEffects::worstDefault, "ImGui::Combo")
	->args({"label","current_item","items_separated_by_zeros","popup_max_height_in_items"})
		->arg_init(3,make_smart<ExprConstInt>(-1))
;
addExtern<bool (*)(const char *, float *, float, float, float, const char *, ImGuiSliderFlags),ImGui::DragFloat>(*this, lib, "DragFloat",SideEffects::worstDefault, "ImGui::DragFloat")
	->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1))
		->arg_init(3,make_smart<ExprConstFloat>(0))
		->arg_init(4,make_smart<ExprConstFloat>(0))
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::AcceptDragDropPayload)>(*this, lib, "AcceptDragDropPayload",SideEffects::worstDefault, "ImGui::AcceptDragDropPayload")
	->args({"type","flags"})
		->arg_init(1,make_smart<ExprConstInt>(0))
;
addExtern<void (*)(const char *),ImGui::TreePush>(*this, lib, "TreePush",SideEffects::worstDefault, "ImGui::TreePush")
	->args({"str_id"})
;
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
addExtern<DAS_BIND_FUN(ImGui::GetStateStorage)>(*this, lib, "GetStateStorage",SideEffects::worstDefault, "ImGui::GetStateStorage")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::Columns)>(*this, lib, "Columns",SideEffects::worstDefault, "ImGui::Columns")
	->args({"count","id","border"})
		->arg_init(0,make_smart<ExprConstInt>(1))
		->arg_init(1,make_smart<ExprConstString>(""))
		->arg_init(2,make_smart<ExprConstBool>(true))
;
addExtern<bool (*)(const char *, int *, const char *const *, int, int),ImGui::ListBox>(*this, lib, "ListBox",SideEffects::worstDefault, "ImGui::ListBox")
	->args({"label","current_item","items","items_count","height_in_items"})
		->arg_init(4,make_smart<ExprConstInt>(-1))
;
addExtern<bool (*)(const char *),ImGui::TreeNode>(*this, lib, "TreeNode",SideEffects::worstDefault, "ImGui::TreeNode")
	->args({"label"})
;
addExtern<DAS_BIND_FUN(ImGui::EndCombo)>(*this, lib, "EndCombo",SideEffects::worstDefault, "ImGui::EndCombo")
	->args({})
;
addExtern<ImGuiID (*)(const void *),ImGui::GetID>(*this, lib, "GetID",SideEffects::worstDefault, "ImGui::GetID")
	->args({"ptr_id"})
;
addExtern<bool (*)(const char *, float *, float, float, const char *, ImGuiSliderFlags),ImGui::SliderFloat4>(*this, lib, "SliderFloat4",SideEffects::worstDefault, "ImGui::SliderFloat4")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::EndTabItem)>(*this, lib, "EndTabItem",SideEffects::worstDefault, "ImGui::EndTabItem")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsItemDeactivated)>(*this, lib, "IsItemDeactivated",SideEffects::worstDefault, "ImGui::IsItemDeactivated")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SetNextWindowSize)>(*this, lib, "SetNextWindowSize",SideEffects::worstDefault, "ImGui::SetNextWindowSize")
	->args({"size","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetCursorPos), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetCursorPos",SideEffects::worstDefault, "ImGui::GetCursorPos")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::InputInt3)>(*this, lib, "InputInt3",SideEffects::worstDefault, "ImGui::InputInt3")
	->args({"label","v","flags"})
		->arg_type(2,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::TableNextColumn)>(*this, lib, "TableNextColumn",SideEffects::worstDefault, "ImGui::TableNextColumn")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::TableGetColumnIndex)>(*this, lib, "TableGetColumnIndex",SideEffects::worstDefault, "ImGui::TableGetColumnIndex")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::PopStyleVar)>(*this, lib, "PopStyleVar",SideEffects::worstDefault, "ImGui::PopStyleVar")
	->args({"count"})
		->arg_init(0,make_smart<ExprConstInt>(1))
;
addExtern<DAS_BIND_FUN(ImGui::EndMainMenuBar)>(*this, lib, "EndMainMenuBar",SideEffects::worstDefault, "ImGui::EndMainMenuBar")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::BeginPopupContextItem)>(*this, lib, "BeginPopupContextItem",SideEffects::worstDefault, "ImGui::BeginPopupContextItem")
	->args({"str_id","popup_flags"})
		->arg_init(0,make_smart<ExprConstString>(""))
		->arg_init(1,make_smart<ExprConstInt>(1))
;
addExtern<DAS_BIND_FUN(ImGui::TextColoredV)>(*this, lib, "TextColoredV",SideEffects::worstDefault, "ImGui::TextColoredV")
	->args({"col","fmt","args"})
;
addExtern<DAS_BIND_FUN(ImGui::PopClipRect)>(*this, lib, "PopClipRect",SideEffects::worstDefault, "ImGui::PopClipRect")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsItemEdited)>(*this, lib, "IsItemEdited",SideEffects::worstDefault, "ImGui::IsItemEdited")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::EndTabBar)>(*this, lib, "EndTabBar",SideEffects::worstDefault, "ImGui::EndTabBar")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::GetItemRectMax), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetItemRectMax",SideEffects::worstDefault, "ImGui::GetItemRectMax")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsMouseDragging)>(*this, lib, "IsMouseDragging",SideEffects::worstDefault, "ImGui::IsMouseDragging")
	->args({"button","lock_threshold"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(1,make_smart<ExprConstFloat>(-1))
;
addExtern<DAS_BIND_FUN(ImGui::SetScrollHere)>(*this, lib, "SetScrollHere",SideEffects::worstDefault, "ImGui::SetScrollHere")
	->args({"center_ratio"})
		->arg_init(0,make_smart<ExprConstFloat>(0.5))
;
addExtern<void (*)(const char *, const ImVec2 &, ImGuiCond),ImGui::SetWindowPos>(*this, lib, "SetWindowPos",SideEffects::worstDefault, "ImGui::SetWindowPos")
	->args({"name","pos","cond"})
		->arg_type(2,makeType<ImGuiCond_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)))
;
addExtern<bool (*)(const char *, int *, const char *const *, int, int),ImGui::Combo>(*this, lib, "Combo",SideEffects::worstDefault, "ImGui::Combo")
	->args({"label","current_item","items","items_count","popup_max_height_in_items"})
		->arg_init(4,make_smart<ExprConstInt>(-1))
;
addExtern<DAS_BIND_FUN(ImGui::GetCursorScreenPos), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetCursorScreenPos",SideEffects::worstDefault, "ImGui::GetCursorScreenPos")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::BeginListBox)>(*this, lib, "BeginListBox",SideEffects::worstDefault, "ImGui::BeginListBox")
	->args({"label","size"})
;
addExtern<DAS_BIND_FUN(ImGui::MemFree)>(*this, lib, "MemFree",SideEffects::worstDefault, "ImGui::MemFree")
	->args({"ptr"})
;
addExtern<bool (*)(const char *, float *, float, float, const char *, float),ImGui::SliderFloat3>(*this, lib, "SliderFloat3",SideEffects::worstDefault, "ImGui::SliderFloat3")
	->args({"label","v","v_min","v_max","format","power"})
;
addExtern<DAS_BIND_FUN(ImGui::Bullet)>(*this, lib, "Bullet",SideEffects::worstDefault, "ImGui::Bullet")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::InputScalarN)>(*this, lib, "InputScalarN",SideEffects::worstDefault, "ImGui::InputScalarN")
	->args({"label","data_type","p_data","components","p_step","p_step_fast","format","flags"})
		->arg_init(4,make_smart<ExprConstPtr>())
		->arg_init(5,make_smart<ExprConstPtr>())
		->arg_init(6,make_smart<ExprConstString>(""))
		->arg_type(7,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(7,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::ResetMouseDragDelta)>(*this, lib, "ResetMouseDragDelta",SideEffects::worstDefault, "ImGui::ResetMouseDragDelta")
	->args({"button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiMouseButton_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetFrameHeightWithSpacing)>(*this, lib, "GetFrameHeightWithSpacing",SideEffects::worstDefault, "ImGui::GetFrameHeightWithSpacing")
	->args({})
;
addExtern<void (*)(const char *, const char *),ImGui::PushID>(*this, lib, "PushID",SideEffects::worstDefault, "ImGui::PushID")
	->args({"str_id_begin","str_id_end"})
;
addExtern<bool (*)(const char *, int *, bool (*)(void *, int, const char **), void *, int, int),ImGui::ListBox>(*this, lib, "ListBox",SideEffects::worstDefault, "ImGui::ListBox")
	->args({"label","current_item","items_getter","data","items_count","height_in_items"})
		->arg_init(5,make_smart<ExprConstInt>(-1))
;
addExtern<bool (*)(const char *, float *, float, float, const char *, float),ImGui::SliderFloat>(*this, lib, "SliderFloat",SideEffects::worstDefault, "ImGui::SliderFloat")
	->args({"label","v","v_min","v_max","format","power"})
;
addExtern<DAS_BIND_FUN(ImGui::EndChild)>(*this, lib, "EndChild",SideEffects::worstDefault, "ImGui::EndChild")
	->args({})
;
addExtern<bool (*)(const char *, ImGuiPopupFlags),ImGui::BeginPopupContextWindow>(*this, lib, "BeginPopupContextWindow",SideEffects::worstDefault, "ImGui::BeginPopupContextWindow")
	->args({"str_id","popup_flags"})
		->arg_init(0,make_smart<ExprConstString>(""))
		->arg_init(1,make_smart<ExprConstInt>(1))
;
addExtern<DAS_BIND_FUN(ImGui::TableGetColumnCount)>(*this, lib, "TableGetColumnCount",SideEffects::worstDefault, "ImGui::TableGetColumnCount")
	->args({})
;
addExtern<void (*)(const void *),ImGui::PushID>(*this, lib, "PushID",SideEffects::worstDefault, "ImGui::PushID")
	->args({"ptr_id"})
;
addExtern<DAS_BIND_FUN(ImGui::IsMousePosValid)>(*this, lib, "IsMousePosValid",SideEffects::worstDefault, "ImGui::IsMousePosValid")
	->args({"mouse_pos"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::PushItemWidth)>(*this, lib, "PushItemWidth",SideEffects::worstDefault, "ImGui::PushItemWidth")
	->args({"item_width"})
;
addExtern<DAS_BIND_FUN(ImGui::GetFontTexUvWhitePixel), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetFontTexUvWhitePixel",SideEffects::worstDefault, "ImGui::GetFontTexUvWhitePixel")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::GetStyleColorVec4), SimNode_ExtFuncCallRef>(*this, lib, "GetStyleColorVec4",SideEffects::worstDefault, "ImGui::GetStyleColorVec4")
	->args({"idx"})
		->arg_type(0,makeType<ImGuiCol_>(lib))
;
addExtern<void (*)(const char *, bool),ImGui::Value>(*this, lib, "Value",SideEffects::worstDefault, "ImGui::Value")
	->args({"prefix","b"})
;
addExtern<DAS_BIND_FUN(ImGui::SetAllocatorFunctions)>(*this, lib, "SetAllocatorFunctions",SideEffects::worstDefault, "ImGui::SetAllocatorFunctions")
	->args({"alloc_func","free_func","user_data"})
		->arg_init(2,make_smart<ExprConstPtr>())
;
addExtern<void (*)(const char *, float (*)(void *, int), void *, int, int, const char *, float, float, ImVec2),ImGui::PlotHistogram>(*this, lib, "PlotHistogram",SideEffects::worstDefault, "ImGui::PlotHistogram")
	->args({"label","values_getter","data","values_count","values_offset","overlay_text","scale_min","scale_max","graph_size"})
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstString>(""))
		->arg_init(6,make_smart<ExprConstFloat>(3.40282347E+38))
		->arg_init(7,make_smart<ExprConstFloat>(3.40282347E+38))
;
addExtern<DAS_BIND_FUN(ImGui::StyleColorsClassic)>(*this, lib, "StyleColorsClassic",SideEffects::worstDefault, "ImGui::StyleColorsClassic")
	->args({"dst"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::SetTabItemClosed)>(*this, lib, "SetTabItemClosed",SideEffects::worstDefault, "ImGui::SetTabItemClosed")
	->args({"tab_or_docked_window_label"})
;
addExtern<DAS_BIND_FUN(ImGui::GetColumnsCount)>(*this, lib, "GetColumnsCount",SideEffects::worstDefault, "ImGui::GetColumnsCount")
	->args({})
;
addExtern<ImGuiID (*)(const char *),ImGui::GetID>(*this, lib, "GetID",SideEffects::worstDefault, "ImGui::GetID")
	->args({"str_id"})
;
addExtern<DAS_BIND_FUN(ImGui::AlignTextToFramePadding)>(*this, lib, "AlignTextToFramePadding",SideEffects::worstDefault, "ImGui::AlignTextToFramePadding")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsItemActive)>(*this, lib, "IsItemActive",SideEffects::worstDefault, "ImGui::IsItemActive")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::EndGroup)>(*this, lib, "EndGroup",SideEffects::worstDefault, "ImGui::EndGroup")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::CloseCurrentPopup)>(*this, lib, "CloseCurrentPopup",SideEffects::worstDefault, "ImGui::CloseCurrentPopup")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::TableNextRow)>(*this, lib, "TableNextRow",SideEffects::worstDefault, "ImGui::TableNextRow")
	->args({"row_flags","min_row_height"})
		->arg_init(0,make_smart<ExprConstInt>(0))
		->arg_init(1,make_smart<ExprConstFloat>(0))
;
addExtern<bool (*)(ImGuiID, const ImVec2 &, bool, ImGuiWindowFlags),ImGui::BeginChild>(*this, lib, "BeginChild",SideEffects::worstDefault, "ImGui::BeginChild")
	->args({"id","size","border","flags"})
		->arg_init(2,make_smart<ExprConstBool>(false))
		->arg_type(3,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetFont)>(*this, lib, "GetFont",SideEffects::worstDefault, "ImGui::GetFont")
	->args({})
;
addExtern<bool (*)(const char *, bool, ImGuiSelectableFlags, const ImVec2 &),ImGui::Selectable>(*this, lib, "Selectable",SideEffects::worstDefault, "ImGui::Selectable")
	->args({"label","selected","flags","size"})
		->arg_init(1,make_smart<ExprConstBool>(false))
		->arg_type(2,makeType<ImGuiSelectableFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSelectableFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetDragDropPayload)>(*this, lib, "GetDragDropPayload",SideEffects::worstDefault, "ImGui::GetDragDropPayload")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SetScrollY)>(*this, lib, "SetScrollY",SideEffects::worstDefault, "ImGui::SetScrollY")
	->args({"scroll_y"})
;
addExtern<DAS_BIND_FUN(ImGui::ColorEdit4)>(*this, lib, "ColorEdit4",SideEffects::worstDefault, "ImGui::ColorEdit4")
	->args({"label","col","flags"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::NewLine)>(*this, lib, "NewLine",SideEffects::worstDefault, "ImGui::NewLine")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::BeginPopupContextVoid)>(*this, lib, "BeginPopupContextVoid",SideEffects::worstDefault, "ImGui::BeginPopupContextVoid")
	->args({"str_id","popup_flags"})
		->arg_init(0,make_smart<ExprConstString>(""))
		->arg_init(1,make_smart<ExprConstInt>(1))
;
addExtern<DAS_BIND_FUN(ImGui::GetMouseDragDelta), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetMouseDragDelta",SideEffects::worstDefault, "ImGui::GetMouseDragDelta")
	->args({"button","lock_threshold"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiMouseButton_>(lib)))
		->arg_init(1,make_smart<ExprConstFloat>(-1))
;
addExtern<DAS_BIND_FUN(ImGui::End)>(*this, lib, "End",SideEffects::worstDefault, "ImGui::End")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::VSliderInt)>(*this, lib, "VSliderInt",SideEffects::worstDefault, "ImGui::VSliderInt")
	->args({"label","size","v","v_min","v_max","format","flags"})
		->arg_init(5,make_smart<ExprConstString>("%d"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::InputFloat4)>(*this, lib, "InputFloat4",SideEffects::worstDefault, "ImGui::InputFloat4")
	->args({"label","v","format","flags"})
		->arg_init(2,make_smart<ExprConstString>("%.3f"))
		->arg_type(3,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::InputInt)>(*this, lib, "InputInt",SideEffects::worstDefault, "ImGui::InputInt")
	->args({"label","v","step","step_fast","flags"})
		->arg_init(2,make_smart<ExprConstInt>(1))
		->arg_init(3,make_smart<ExprConstInt>(100))
		->arg_type(4,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(4,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetOverlayDrawList)>(*this, lib, "GetOverlayDrawList",SideEffects::worstDefault, "ImGui::GetOverlayDrawList")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::ShowDemoWindow)>(*this, lib, "ShowDemoWindow",SideEffects::worstDefault, "ImGui::ShowDemoWindow")
	->args({"p_open"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::GetWindowDrawList)>(*this, lib, "GetWindowDrawList",SideEffects::worstDefault, "ImGui::GetWindowDrawList")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::BeginTooltip)>(*this, lib, "BeginTooltip",SideEffects::worstDefault, "ImGui::BeginTooltip")
	->args({})
;
addExtern<ImU32 (*)(ImU32),ImGui::GetColorU32>(*this, lib, "GetColorU32",SideEffects::worstDefault, "ImGui::GetColorU32")
	->args({"col"})
;
addExtern<DAS_BIND_FUN(ImGui::GetWindowPos), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetWindowPos",SideEffects::worstDefault, "ImGui::GetWindowPos")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::PopButtonRepeat)>(*this, lib, "PopButtonRepeat",SideEffects::worstDefault, "ImGui::PopButtonRepeat")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::SliderInt)>(*this, lib, "SliderInt",SideEffects::worstDefault, "ImGui::SliderInt")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%d"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::EndDragDropSource)>(*this, lib, "EndDragDropSource",SideEffects::worstDefault, "ImGui::EndDragDropSource")
	->args({})
;
addExtern<bool (*)(const char *, float *, float, float, const char *, ImGuiSliderFlags),ImGui::SliderFloat2>(*this, lib, "SliderFloat2",SideEffects::worstDefault, "ImGui::SliderFloat2")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::TableHeadersRow)>(*this, lib, "TableHeadersRow",SideEffects::worstDefault, "ImGui::TableHeadersRow")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::PushClipRect)>(*this, lib, "PushClipRect",SideEffects::worstDefault, "ImGui::PushClipRect")
	->args({"clip_rect_min","clip_rect_max","intersect_with_current_clip_rect"})
;
addExtern<DAS_BIND_FUN(ImGui::DragInt3)>(*this, lib, "DragInt3",SideEffects::worstDefault, "ImGui::DragInt3")
	->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1))
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstString>("%d"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::IsItemFocused)>(*this, lib, "IsItemFocused",SideEffects::worstDefault, "ImGui::IsItemFocused")
	->args({})
;
addExtern<bool (*)(const char *, bool *, ImGuiSelectableFlags, const ImVec2 &),ImGui::Selectable>(*this, lib, "Selectable",SideEffects::worstDefault, "ImGui::Selectable")
	->args({"label","p_selected","flags","size"})
		->arg_type(2,makeType<ImGuiSelectableFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSelectableFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::GetVersion)>(*this, lib, "GetVersion",SideEffects::worstDefault, "ImGui::GetVersion")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsMouseClicked)>(*this, lib, "IsMouseClicked",SideEffects::worstDefault, "ImGui::IsMouseClicked")
	->args({"button","repeat"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(1,make_smart<ExprConstBool>(false))
;
addExtern<DAS_BIND_FUN(ImGui::GetMousePos), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetMousePos",SideEffects::worstDefault, "ImGui::GetMousePos")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::DragInt2)>(*this, lib, "DragInt2",SideEffects::worstDefault, "ImGui::DragInt2")
	->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1))
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstString>("%d"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::SetCursorPosY)>(*this, lib, "SetCursorPosY",SideEffects::worstDefault, "ImGui::SetCursorPosY")
	->args({"local_y"})
;
addExtern<DAS_BIND_FUN(ImGui::StyleColorsLight)>(*this, lib, "StyleColorsLight",SideEffects::worstDefault, "ImGui::StyleColorsLight")
	->args({"dst"})
		->arg_init(0,make_smart<ExprConstPtr>())
;
addExtern<DAS_BIND_FUN(ImGui::IsPopupOpen)>(*this, lib, "IsPopupOpen",SideEffects::worstDefault, "ImGui::IsPopupOpen")
	->args({"str_id","flags"})
		->arg_init(1,make_smart<ExprConstInt>(0))
;
addExtern<DAS_BIND_FUN(ImGui::GetBackgroundDrawList)>(*this, lib, "GetBackgroundDrawList",SideEffects::worstDefault, "ImGui::GetBackgroundDrawList")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsKeyReleased)>(*this, lib, "IsKeyReleased",SideEffects::worstDefault, "ImGui::IsKeyReleased")
	->args({"user_key_index"})
;
addExtern<bool (*)(const char *, float *, float, float, const char *, ImGuiSliderFlags),ImGui::SliderFloat3>(*this, lib, "SliderFloat3",SideEffects::worstDefault, "ImGui::SliderFloat3")
	->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::PopID)>(*this, lib, "PopID",SideEffects::worstDefault, "ImGui::PopID")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::IsItemToggledOpen)>(*this, lib, "IsItemToggledOpen",SideEffects::worstDefault, "ImGui::IsItemToggledOpen")
	->args({})
;
addExtern<DAS_BIND_FUN(ImGui::InputInt2)>(*this, lib, "InputInt2",SideEffects::worstDefault, "ImGui::InputInt2")
	->args({"label","v","flags"})
		->arg_type(2,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)))
;
addExtern<DAS_BIND_FUN(ImGui::TableGetColumnName)>(*this, lib, "TableGetColumnName",SideEffects::worstDefault, "ImGui::TableGetColumnName")
	->args({"column_n"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
;
