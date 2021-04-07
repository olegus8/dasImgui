// ------------
// enumerations
// ------------

#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiDataType>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImDrawFlags>());
addEnumFlagOps<ImDrawFlags_>(*this,lib,"ImDrawFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiHoveredFlags>());
addEnumFlagOps<ImGuiHoveredFlags_>(*this,lib,"ImGuiHoveredFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiNavInput_>());
#endif
#ifdef IMNODES_NAMESPACE
addEnumeration(make_smart<EnumerationImNodesPinShape>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiDir>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiCond>());
addEnumFlagOps<ImGuiCond_>(*this,lib,"ImGuiCond_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiViewportFlags_>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiDragDropFlags>());
addEnumFlagOps<ImGuiDragDropFlags_>(*this,lib,"ImGuiDragDropFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiColorEditFlags>());
addEnumFlagOps<ImGuiColorEditFlags_>(*this,lib,"ImGuiColorEditFlags_");
#endif
#ifdef IMNODES_NAMESPACE
addEnumeration(make_smart<EnumerationImNodesStyleVar>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiWindowFlags>());
addEnumFlagOps<ImGuiWindowFlags_>(*this,lib,"ImGuiWindowFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiCol>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiTableFlags>());
addEnumFlagOps<ImGuiTableFlags_>(*this,lib,"ImGuiTableFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiKeyModFlags>());
addEnumFlagOps<ImGuiKeyModFlags_>(*this,lib,"ImGuiKeyModFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiFocusedFlags>());
addEnumFlagOps<ImGuiFocusedFlags_>(*this,lib,"ImGuiFocusedFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiMouseCursor_>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiTableBgTarget>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiButtonFlags>());
addEnumFlagOps<ImGuiButtonFlags_>(*this,lib,"ImGuiButtonFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiMouseButton>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiTabBarFlags>());
addEnumFlagOps<ImGuiTabBarFlags_>(*this,lib,"ImGuiTabBarFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiTreeNodeFlags>());
addEnumFlagOps<ImGuiTreeNodeFlags_>(*this,lib,"ImGuiTreeNodeFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiTabItemFlags>());
addEnumFlagOps<ImGuiTabItemFlags_>(*this,lib,"ImGuiTabItemFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImDrawListFlags_>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiSelectableFlags>());
addEnumFlagOps<ImGuiSelectableFlags_>(*this,lib,"ImGuiSelectableFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiTableColumnFlags>());
addEnumFlagOps<ImGuiTableColumnFlags_>(*this,lib,"ImGuiTableColumnFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiSortDirection>());
#endif
#ifdef IMNODES_NAMESPACE
addEnumeration(make_smart<EnumerationImNodesColorStyle>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiInputTextFlags>());
addEnumFlagOps<ImGuiInputTextFlags_>(*this,lib,"ImGuiInputTextFlags_");
#endif
#ifdef IMNODES_NAMESPACE
addEnumeration(make_smart<EnumerationImNodesStyleFlags>());
addEnumFlagOps<imnodes::StyleFlags>(*this,lib,"imnodes::StyleFlags");
#endif
#ifdef IMNODES_NAMESPACE
addEnumeration(make_smart<EnumerationImNodesAttributeFlags>());
addEnumFlagOps<imnodes::AttributeFlags>(*this,lib,"imnodes::AttributeFlags");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiBackendFlags>());
addEnumFlagOps<ImGuiBackendFlags_>(*this,lib,"ImGuiBackendFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiPopupFlags_>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiComboFlags>());
addEnumFlagOps<ImGuiComboFlags_>(*this,lib,"ImGuiComboFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiKey>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiStyleVar>());
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiConfigFlags>());
addEnumFlagOps<ImGuiConfigFlags_>(*this,lib,"ImGuiConfigFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiSliderFlags>());
addEnumFlagOps<ImGuiSliderFlags_>(*this,lib,"ImGuiSliderFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImGuiTableRowFlags>());
addEnumFlagOps<ImGuiTableRowFlags_>(*this,lib,"ImGuiTableRowFlags_");
#endif
#ifdef GLOBAL_NAMESPACE
addEnumeration(make_smart<EnumerationImFontAtlasFlags_>());
#endif

