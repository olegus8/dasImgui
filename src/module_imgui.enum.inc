// ------------
// enumerations
// ------------

addEnumeration(make_smart<EnumerationImGuiDataType_>());
addEnumeration(make_smart<EnumerationImGuiHoveredFlags_>());
addEnumeration(make_smart<EnumerationImGuiNavInput_>());
addEnumeration(make_smart<EnumerationImGuiDir_>());
addEnumeration(make_smart<EnumerationImGuiCond>());
addEnumFlagOps<ImGuiCond_>(*this,lib,"ImGuiCond_");
addEnumeration(make_smart<EnumerationImGuiViewportFlags_>());
addEnumeration(make_smart<EnumerationImGuiDragDropFlags_>());
addEnumeration(make_smart<EnumerationImGuiColorEditFlags>());
addEnumFlagOps<ImGuiColorEditFlags_>(*this,lib,"ImGuiColorEditFlags_");
addEnumeration(make_smart<EnumerationImGuiWindowFlags>());
addEnumFlagOps<ImGuiWindowFlags_>(*this,lib,"ImGuiWindowFlags_");
addEnumeration(make_smart<EnumerationImGuiCol>());
addEnumeration(make_smart<EnumerationImGuiTableFlags>());
addEnumFlagOps<ImGuiTableFlags_>(*this,lib,"ImGuiTableFlags_");
addEnumeration(make_smart<EnumerationImGuiKeyModFlags_>());
addEnumeration(make_smart<EnumerationImGuiFocusedFlags_>());
addEnumeration(make_smart<EnumerationImGuiMouseCursor_>());
addEnumeration(make_smart<EnumerationImDrawCornerFlags>());
addEnumFlagOps<ImDrawCornerFlags_>(*this,lib,"ImDrawCornerFlags_");
addEnumeration(make_smart<EnumerationImGuiTableBgTarget_>());
addEnumeration(make_smart<EnumerationImGuiButtonFlags>());
addEnumFlagOps<ImGuiButtonFlags_>(*this,lib,"ImGuiButtonFlags_");
addEnumeration(make_smart<EnumerationImGuiMouseButton>());
addEnumeration(make_smart<EnumerationImGuiTabBarFlags>());
addEnumFlagOps<ImGuiTabBarFlags_>(*this,lib,"ImGuiTabBarFlags_");
addEnumeration(make_smart<EnumerationImGuiTreeNodeFlags>());
addEnumFlagOps<ImGuiTreeNodeFlags_>(*this,lib,"ImGuiTreeNodeFlags_");
addEnumeration(make_smart<EnumerationImGuiTabItemFlags>());
addEnumFlagOps<ImGuiTabItemFlags_>(*this,lib,"ImGuiTabItemFlags_");
addEnumeration(make_smart<EnumerationImDrawListFlags_>());
addEnumeration(make_smart<EnumerationImGuiSelectableFlags>());
addEnumFlagOps<ImGuiSelectableFlags_>(*this,lib,"ImGuiSelectableFlags_");
addEnumeration(make_smart<EnumerationImGuiTableColumnFlags_>());
addEnumeration(make_smart<EnumerationImGuiSortDirection_>());
addEnumeration(make_smart<EnumerationImGuiInputTextFlags>());
addEnumFlagOps<ImGuiInputTextFlags_>(*this,lib,"ImGuiInputTextFlags_");
addEnumeration(make_smart<EnumerationImGuiBackendFlags>());
addEnumFlagOps<ImGuiBackendFlags_>(*this,lib,"ImGuiBackendFlags_");
addEnumeration(make_smart<EnumerationImGuiPopupFlags_>());
addEnumeration(make_smart<EnumerationImGuiComboFlags_>());
addEnumeration(make_smart<EnumerationImGuiKey>());
addEnumeration(make_smart<EnumerationImGuiStyleVar>());
addEnumeration(make_smart<EnumerationImGuiConfigFlags>());
addEnumFlagOps<ImGuiConfigFlags_>(*this,lib,"ImGuiConfigFlags_");
addEnumeration(make_smart<EnumerationImGuiSliderFlags>());
addEnumFlagOps<ImGuiSliderFlags_>(*this,lib,"ImGuiSliderFlags_");
addEnumeration(make_smart<EnumerationImGuiTableRowFlags_>());
addEnumeration(make_smart<EnumerationImFontAtlasFlags_>());

