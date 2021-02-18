// ------------
// methods 
// ------------

using _Clear_method_1 = DAS_CALL_MEMBER(ImDrawData::Clear);
addExtern<DAS_CALL_METHOD(_Clear_method_1)>(*this, lib, "Clear",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawData::Clear))
	->args({"self",})
;
using _DeIndexAllBuffers_method_2 = DAS_CALL_MEMBER(ImDrawData::DeIndexAllBuffers);
addExtern<DAS_CALL_METHOD(_DeIndexAllBuffers_method_2)>(*this, lib, "DeIndexAllBuffers",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawData::DeIndexAllBuffers))
	->args({"self",})
;
using _ScaleClipRects_method_3 = DAS_CALL_MEMBER(ImDrawData::ScaleClipRects);
addExtern<DAS_CALL_METHOD(_ScaleClipRects_method_3)>(*this, lib, "ScaleClipRects",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawData::ScaleClipRects))
	->args({"self","fb_scale"})
;
using _Clear_method_4 = DAS_CALL_MEMBER(ImFontGlyphRangesBuilder::Clear);
addExtern<DAS_CALL_METHOD(_Clear_method_4)>(*this, lib, "Clear",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontGlyphRangesBuilder::Clear))
	->args({"self",})
;
using _GetBit_method_5 = DAS_CALL_MEMBER(ImFontGlyphRangesBuilder::GetBit);
addExtern<DAS_CALL_METHOD(_GetBit_method_5)>(*this, lib, "GetBit",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontGlyphRangesBuilder::GetBit))
	->args({"self","n"})
;
using _SetBit_method_6 = DAS_CALL_MEMBER(ImFontGlyphRangesBuilder::SetBit);
addExtern<DAS_CALL_METHOD(_SetBit_method_6)>(*this, lib, "SetBit",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontGlyphRangesBuilder::SetBit))
	->args({"self","n"})
;
using _AddChar_method_7 = DAS_CALL_MEMBER(ImFontGlyphRangesBuilder::AddChar);
addExtern<DAS_CALL_METHOD(_AddChar_method_7)>(*this, lib, "AddChar",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontGlyphRangesBuilder::AddChar))
	->args({"self","c"})
;
using _AddText_method_8 = DAS_CALL_MEMBER(ImFontGlyphRangesBuilder::AddText);
addExtern<DAS_CALL_METHOD(_AddText_method_8)>(*this, lib, "AddText",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontGlyphRangesBuilder::AddText))
	->args({"self","text","text_end"})
		->arg_init(2,make_smart<ExprConstString>(""))
;
using _AddRanges_method_9 = DAS_CALL_MEMBER(ImFontGlyphRangesBuilder::AddRanges);
addExtern<DAS_CALL_METHOD(_AddRanges_method_9)>(*this, lib, "AddRanges",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontGlyphRangesBuilder::AddRanges))
	->args({"self","ranges"})
;
using _BuildRanges_method_10 = DAS_CALL_MEMBER(ImFontGlyphRangesBuilder::BuildRanges);
addExtern<DAS_CALL_METHOD(_BuildRanges_method_10)>(*this, lib, "BuildRanges",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontGlyphRangesBuilder::BuildRanges))
	->args({"self","out_ranges"})
;
using _Clear_method_11 = DAS_CALL_MEMBER(ImGuiPayload::Clear);
addExtern<DAS_CALL_METHOD(_Clear_method_11)>(*this, lib, "Clear",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiPayload::Clear))
	->args({"self",})
;
using _IsDataType_method_12 = DAS_CALL_MEMBER(ImGuiPayload::IsDataType);
addExtern<DAS_CALL_METHOD(_IsDataType_method_12)>(*this, lib, "IsDataType",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiPayload::IsDataType))
	->args({"self","type"})
;
using _IsPreview_method_13 = DAS_CALL_MEMBER(ImGuiPayload::IsPreview);
addExtern<DAS_CALL_METHOD(_IsPreview_method_13)>(*this, lib, "IsPreview",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiPayload::IsPreview))
	->args({"self",})
;
using _IsDelivery_method_14 = DAS_CALL_MEMBER(ImGuiPayload::IsDelivery);
addExtern<DAS_CALL_METHOD(_IsDelivery_method_14)>(*this, lib, "IsDelivery",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiPayload::IsDelivery))
	->args({"self",})
;
using _AddInputCharacter_method_15 = DAS_CALL_MEMBER(ImGuiIO::AddInputCharacter);
addExtern<DAS_CALL_METHOD(_AddInputCharacter_method_15)>(*this, lib, "AddInputCharacter",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiIO::AddInputCharacter))
	->args({"self","c"})
;
using _AddInputCharacterUTF16_method_16 = DAS_CALL_MEMBER(ImGuiIO::AddInputCharacterUTF16);
addExtern<DAS_CALL_METHOD(_AddInputCharacterUTF16_method_16)>(*this, lib, "AddInputCharacterUTF16",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiIO::AddInputCharacterUTF16))
	->args({"self","c"})
;
using _AddInputCharactersUTF8_method_17 = DAS_CALL_MEMBER(ImGuiIO::AddInputCharactersUTF8);
addExtern<DAS_CALL_METHOD(_AddInputCharactersUTF8_method_17)>(*this, lib, "AddInputCharactersUTF8",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiIO::AddInputCharactersUTF8))
	->args({"self","str"})
;
using _ClearInputCharacters_method_18 = DAS_CALL_MEMBER(ImGuiIO::ClearInputCharacters);
addExtern<DAS_CALL_METHOD(_ClearInputCharacters_method_18)>(*this, lib, "ClearInputCharacters",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiIO::ClearInputCharacters))
	->args({"self",})
;
using _AddFont_method_19 = DAS_CALL_MEMBER(ImFontAtlas::AddFont);
addExtern<DAS_CALL_METHOD(_AddFont_method_19)>(*this, lib, "AddFont",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::AddFont))
	->args({"self","font_cfg"})
;
using _AddFontDefault_method_20 = DAS_CALL_MEMBER(ImFontAtlas::AddFontDefault);
addExtern<DAS_CALL_METHOD(_AddFontDefault_method_20)>(*this, lib, "AddFontDefault",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::AddFontDefault))
	->args({"self","font_cfg"})
		->arg_init(1,make_smart<ExprConstPtr>())
;
using _AddFontFromFileTTF_method_21 = DAS_CALL_MEMBER(ImFontAtlas::AddFontFromFileTTF);
addExtern<DAS_CALL_METHOD(_AddFontFromFileTTF_method_21)>(*this, lib, "AddFontFromFileTTF",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::AddFontFromFileTTF))
	->args({"self","filename","size_pixels","font_cfg","glyph_ranges"})
		->arg_init(3,make_smart<ExprConstPtr>())
		->arg_init(4,make_smart<ExprConstPtr>())
;
using _AddFontFromMemoryTTF_method_22 = DAS_CALL_MEMBER(ImFontAtlas::AddFontFromMemoryTTF);
addExtern<DAS_CALL_METHOD(_AddFontFromMemoryTTF_method_22)>(*this, lib, "AddFontFromMemoryTTF",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::AddFontFromMemoryTTF))
	->args({"self","font_data","font_size","size_pixels","font_cfg","glyph_ranges"})
		->arg_init(4,make_smart<ExprConstPtr>())
		->arg_init(5,make_smart<ExprConstPtr>())
;
using _AddFontFromMemoryCompressedTTF_method_23 = DAS_CALL_MEMBER(ImFontAtlas::AddFontFromMemoryCompressedTTF);
addExtern<DAS_CALL_METHOD(_AddFontFromMemoryCompressedTTF_method_23)>(*this, lib, "AddFontFromMemoryCompressedTTF",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::AddFontFromMemoryCompressedTTF))
	->args({"self","compressed_font_data","compressed_font_size","size_pixels","font_cfg","glyph_ranges"})
		->arg_init(4,make_smart<ExprConstPtr>())
		->arg_init(5,make_smart<ExprConstPtr>())
;
using _AddFontFromMemoryCompressedBase85TTF_method_24 = DAS_CALL_MEMBER(ImFontAtlas::AddFontFromMemoryCompressedBase85TTF);
addExtern<DAS_CALL_METHOD(_AddFontFromMemoryCompressedBase85TTF_method_24)>(*this, lib, "AddFontFromMemoryCompressedBase85TTF",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::AddFontFromMemoryCompressedBase85TTF))
	->args({"self","compressed_font_data_base85","size_pixels","font_cfg","glyph_ranges"})
		->arg_init(3,make_smart<ExprConstPtr>())
		->arg_init(4,make_smart<ExprConstPtr>())
;
using _ClearInputData_method_25 = DAS_CALL_MEMBER(ImFontAtlas::ClearInputData);
addExtern<DAS_CALL_METHOD(_ClearInputData_method_25)>(*this, lib, "ClearInputData",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::ClearInputData))
	->args({"self",})
;
using _ClearTexData_method_26 = DAS_CALL_MEMBER(ImFontAtlas::ClearTexData);
addExtern<DAS_CALL_METHOD(_ClearTexData_method_26)>(*this, lib, "ClearTexData",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::ClearTexData))
	->args({"self",})
;
using _ClearFonts_method_27 = DAS_CALL_MEMBER(ImFontAtlas::ClearFonts);
addExtern<DAS_CALL_METHOD(_ClearFonts_method_27)>(*this, lib, "ClearFonts",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::ClearFonts))
	->args({"self",})
;
using _Clear_method_28 = DAS_CALL_MEMBER(ImFontAtlas::Clear);
addExtern<DAS_CALL_METHOD(_Clear_method_28)>(*this, lib, "Clear",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::Clear))
	->args({"self",})
;
using _Build_method_29 = DAS_CALL_MEMBER(ImFontAtlas::Build);
addExtern<DAS_CALL_METHOD(_Build_method_29)>(*this, lib, "Build",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::Build))
	->args({"self",})
;
using _GetTexDataAsAlpha8_method_30 = DAS_CALL_MEMBER(ImFontAtlas::GetTexDataAsAlpha8);
addExtern<DAS_CALL_METHOD(_GetTexDataAsAlpha8_method_30)>(*this, lib, "GetTexDataAsAlpha8",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::GetTexDataAsAlpha8))
	->args({"self","out_pixels","out_width","out_height","out_bytes_per_pixel"})
		->arg_init(4,make_smart<ExprConstPtr>())
;
using _GetTexDataAsRGBA32_method_31 = DAS_CALL_MEMBER(ImFontAtlas::GetTexDataAsRGBA32);
addExtern<DAS_CALL_METHOD(_GetTexDataAsRGBA32_method_31)>(*this, lib, "GetTexDataAsRGBA32",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::GetTexDataAsRGBA32))
	->args({"self","out_pixels","out_width","out_height","out_bytes_per_pixel"})
		->arg_init(4,make_smart<ExprConstPtr>())
;
using _IsBuilt_method_32 = DAS_CALL_MEMBER(ImFontAtlas::IsBuilt);
addExtern<DAS_CALL_METHOD(_IsBuilt_method_32)>(*this, lib, "IsBuilt",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::IsBuilt))
	->args({"self",})
;
using _SetTexID_method_33 = DAS_CALL_MEMBER(ImFontAtlas::SetTexID);
addExtern<DAS_CALL_METHOD(_SetTexID_method_33)>(*this, lib, "SetTexID",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::SetTexID))
	->args({"self","id"})
;
using _GetGlyphRangesDefault_method_34 = DAS_CALL_MEMBER(ImFontAtlas::GetGlyphRangesDefault);
addExtern<DAS_CALL_METHOD(_GetGlyphRangesDefault_method_34)>(*this, lib, "GetGlyphRangesDefault",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::GetGlyphRangesDefault))
	->args({"self",})
;
using _GetGlyphRangesKorean_method_35 = DAS_CALL_MEMBER(ImFontAtlas::GetGlyphRangesKorean);
addExtern<DAS_CALL_METHOD(_GetGlyphRangesKorean_method_35)>(*this, lib, "GetGlyphRangesKorean",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::GetGlyphRangesKorean))
	->args({"self",})
;
using _GetGlyphRangesJapanese_method_36 = DAS_CALL_MEMBER(ImFontAtlas::GetGlyphRangesJapanese);
addExtern<DAS_CALL_METHOD(_GetGlyphRangesJapanese_method_36)>(*this, lib, "GetGlyphRangesJapanese",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::GetGlyphRangesJapanese))
	->args({"self",})
;
using _GetGlyphRangesChineseFull_method_37 = DAS_CALL_MEMBER(ImFontAtlas::GetGlyphRangesChineseFull);
addExtern<DAS_CALL_METHOD(_GetGlyphRangesChineseFull_method_37)>(*this, lib, "GetGlyphRangesChineseFull",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::GetGlyphRangesChineseFull))
	->args({"self",})
;
using _GetGlyphRangesChineseSimplifiedCommon_method_38 = DAS_CALL_MEMBER(ImFontAtlas::GetGlyphRangesChineseSimplifiedCommon);
addExtern<DAS_CALL_METHOD(_GetGlyphRangesChineseSimplifiedCommon_method_38)>(*this, lib, "GetGlyphRangesChineseSimplifiedCommon",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::GetGlyphRangesChineseSimplifiedCommon))
	->args({"self",})
;
using _GetGlyphRangesCyrillic_method_39 = DAS_CALL_MEMBER(ImFontAtlas::GetGlyphRangesCyrillic);
addExtern<DAS_CALL_METHOD(_GetGlyphRangesCyrillic_method_39)>(*this, lib, "GetGlyphRangesCyrillic",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::GetGlyphRangesCyrillic))
	->args({"self",})
;
using _GetGlyphRangesThai_method_40 = DAS_CALL_MEMBER(ImFontAtlas::GetGlyphRangesThai);
addExtern<DAS_CALL_METHOD(_GetGlyphRangesThai_method_40)>(*this, lib, "GetGlyphRangesThai",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::GetGlyphRangesThai))
	->args({"self",})
;
using _GetGlyphRangesVietnamese_method_41 = DAS_CALL_MEMBER(ImFontAtlas::GetGlyphRangesVietnamese);
addExtern<DAS_CALL_METHOD(_GetGlyphRangesVietnamese_method_41)>(*this, lib, "GetGlyphRangesVietnamese",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::GetGlyphRangesVietnamese))
	->args({"self",})
;
using _AddCustomRectRegular_method_42 = DAS_CALL_MEMBER(ImFontAtlas::AddCustomRectRegular);
addExtern<DAS_CALL_METHOD(_AddCustomRectRegular_method_42)>(*this, lib, "AddCustomRectRegular",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::AddCustomRectRegular))
	->args({"self","width","height"})
;
using _AddCustomRectFontGlyph_method_43 = DAS_CALL_MEMBER(ImFontAtlas::AddCustomRectFontGlyph);
addExtern<DAS_CALL_METHOD(_AddCustomRectFontGlyph_method_43)>(*this, lib, "AddCustomRectFontGlyph",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::AddCustomRectFontGlyph))
	->args({"self","font","id","width","height","advance_x","offset"})
;
using _GetCustomRectByIndex_method_44 = DAS_CALL_MEMBER(ImFontAtlas::GetCustomRectByIndex);
addExtern<DAS_CALL_METHOD(_GetCustomRectByIndex_method_44)>(*this, lib, "GetCustomRectByIndex",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::GetCustomRectByIndex))
	->args({"self","index"})
;
using _CalcCustomRectUV_method_45 = DAS_CALL_MEMBER(ImFontAtlas::CalcCustomRectUV);
addExtern<DAS_CALL_METHOD(_CalcCustomRectUV_method_45)>(*this, lib, "CalcCustomRectUV",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::CalcCustomRectUV))
	->args({"self","rect","out_uv_min","out_uv_max"})
;
using _GetMouseCursorTexData_method_46 = DAS_CALL_MEMBER(ImFontAtlas::GetMouseCursorTexData);
addExtern<DAS_CALL_METHOD(_GetMouseCursorTexData_method_46)>(*this, lib, "GetMouseCursorTexData",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlas::GetMouseCursorTexData))
	->args({"self","cursor","out_offset","out_size","out_uv_border","out_uv_fill"})
;
using _Draw_method_47 = DAS_CALL_MEMBER(ImGuiTextFilter::Draw);
addExtern<DAS_CALL_METHOD(_Draw_method_47)>(*this, lib, "Draw",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextFilter::Draw))
	->args({"self","label","width"})
		->arg_init(1,make_smart<ExprConstString>("Filter (inc,-exc)"))
		->arg_init(2,make_smart<ExprConstFloat>(0))
;
using _Build_method_48 = DAS_CALL_MEMBER(ImGuiTextFilter::Build);
addExtern<DAS_CALL_METHOD(_Build_method_48)>(*this, lib, "Build",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextFilter::Build))
	->args({"self",})
;
using _Clear_method_49 = DAS_CALL_MEMBER(ImGuiTextFilter::Clear);
addExtern<DAS_CALL_METHOD(_Clear_method_49)>(*this, lib, "Clear",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextFilter::Clear))
	->args({"self",})
;
using _IsActive_method_50 = DAS_CALL_MEMBER(ImGuiTextFilter::IsActive);
addExtern<DAS_CALL_METHOD(_IsActive_method_50)>(*this, lib, "IsActive",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextFilter::IsActive))
	->args({"self",})
;
using _Begin_method_51 = DAS_CALL_MEMBER(ImGuiListClipper::Begin);
addExtern<DAS_CALL_METHOD(_Begin_method_51)>(*this, lib, "Begin",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiListClipper::Begin))
	->args({"self","items_count","items_height"})
		->arg_init(2,make_smart<ExprConstFloat>(-1))
;
using _End_method_52 = DAS_CALL_MEMBER(ImGuiListClipper::End);
addExtern<DAS_CALL_METHOD(_End_method_52)>(*this, lib, "End",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiListClipper::End))
	->args({"self",})
;
using _Step_method_53 = DAS_CALL_MEMBER(ImGuiListClipper::Step);
addExtern<DAS_CALL_METHOD(_Step_method_53)>(*this, lib, "Step",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiListClipper::Step))
	->args({"self",})
;
using _FindGlyph_method_54 = DAS_CALL_MEMBER(ImFont::FindGlyph);
addExtern<DAS_CALL_METHOD(_FindGlyph_method_54)>(*this, lib, "FindGlyph",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::FindGlyph))
	->args({"self","c"})
;
using _FindGlyphNoFallback_method_55 = DAS_CALL_MEMBER(ImFont::FindGlyphNoFallback);
addExtern<DAS_CALL_METHOD(_FindGlyphNoFallback_method_55)>(*this, lib, "FindGlyphNoFallback",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::FindGlyphNoFallback))
	->args({"self","c"})
;
using _GetCharAdvance_method_56 = DAS_CALL_MEMBER(ImFont::GetCharAdvance);
addExtern<DAS_CALL_METHOD(_GetCharAdvance_method_56)>(*this, lib, "GetCharAdvance",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::GetCharAdvance))
	->args({"self","c"})
;
using _IsLoaded_method_57 = DAS_CALL_MEMBER(ImFont::IsLoaded);
addExtern<DAS_CALL_METHOD(_IsLoaded_method_57)>(*this, lib, "IsLoaded",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::IsLoaded))
	->args({"self",})
;
using _GetDebugName_method_58 = DAS_CALL_MEMBER(ImFont::GetDebugName);
addExtern<DAS_CALL_METHOD(_GetDebugName_method_58)>(*this, lib, "GetDebugName",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::GetDebugName))
	->args({"self",})
;
using _CalcTextSizeA_method_59 = DAS_CALL_MEMBER(ImFont::CalcTextSizeA);
addExtern<DAS_CALL_METHOD(_CalcTextSizeA_method_59), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "CalcTextSizeA",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::CalcTextSizeA))
	->args({"self","size","max_width","wrap_width","text_begin","text_end","remaining"})
		->arg_init(5,make_smart<ExprConstString>(""))
		->arg_init(6,make_smart<ExprConstPtr>())
;
using _CalcWordWrapPositionA_method_60 = DAS_CALL_MEMBER(ImFont::CalcWordWrapPositionA);
addExtern<DAS_CALL_METHOD(_CalcWordWrapPositionA_method_60)>(*this, lib, "CalcWordWrapPositionA",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::CalcWordWrapPositionA))
	->args({"self","scale","text","text_end","wrap_width"})
;
using _RenderChar_method_61 = DAS_CALL_MEMBER(ImFont::RenderChar);
addExtern<DAS_CALL_METHOD(_RenderChar_method_61)>(*this, lib, "RenderChar",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::RenderChar))
	->args({"self","draw_list","size","pos","col","c"})
;
using _RenderText_method_62 = DAS_CALL_MEMBER(ImFont::RenderText);
addExtern<DAS_CALL_METHOD(_RenderText_method_62)>(*this, lib, "RenderText",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::RenderText))
	->args({"self","draw_list","size","pos","col","clip_rect","text_begin","text_end","wrap_width","cpu_fine_clip"})
		->arg_init(8,make_smart<ExprConstFloat>(0))
		->arg_init(9,make_smart<ExprConstBool>(false))
;
using _BuildLookupTable_method_63 = DAS_CALL_MEMBER(ImFont::BuildLookupTable);
addExtern<DAS_CALL_METHOD(_BuildLookupTable_method_63)>(*this, lib, "BuildLookupTable",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::BuildLookupTable))
	->args({"self",})
;
using _ClearOutputData_method_64 = DAS_CALL_MEMBER(ImFont::ClearOutputData);
addExtern<DAS_CALL_METHOD(_ClearOutputData_method_64)>(*this, lib, "ClearOutputData",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::ClearOutputData))
	->args({"self",})
;
using _GrowIndex_method_65 = DAS_CALL_MEMBER(ImFont::GrowIndex);
addExtern<DAS_CALL_METHOD(_GrowIndex_method_65)>(*this, lib, "GrowIndex",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::GrowIndex))
	->args({"self","new_size"})
;
using _AddGlyph_method_66 = DAS_CALL_MEMBER(ImFont::AddGlyph);
addExtern<DAS_CALL_METHOD(_AddGlyph_method_66)>(*this, lib, "AddGlyph",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::AddGlyph))
	->args({"self","src_cfg","c","x0","y0","x1","y1","u0","v0","u1","v1","advance_x"})
;
using _AddRemapChar_method_67 = DAS_CALL_MEMBER(ImFont::AddRemapChar);
addExtern<DAS_CALL_METHOD(_AddRemapChar_method_67)>(*this, lib, "AddRemapChar",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::AddRemapChar))
	->args({"self","dst","src","overwrite_dst"})
		->arg_init(3,make_smart<ExprConstBool>(true))
;
using _SetGlyphVisible_method_68 = DAS_CALL_MEMBER(ImFont::SetGlyphVisible);
addExtern<DAS_CALL_METHOD(_SetGlyphVisible_method_68)>(*this, lib, "SetGlyphVisible",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::SetGlyphVisible))
	->args({"self","c","visible"})
;
using _SetFallbackChar_method_69 = DAS_CALL_MEMBER(ImFont::SetFallbackChar);
addExtern<DAS_CALL_METHOD(_SetFallbackChar_method_69)>(*this, lib, "SetFallbackChar",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::SetFallbackChar))
	->args({"self","c"})
;
using _IsGlyphRangeUnused_method_70 = DAS_CALL_MEMBER(ImFont::IsGlyphRangeUnused);
addExtern<DAS_CALL_METHOD(_IsGlyphRangeUnused_method_70)>(*this, lib, "IsGlyphRangeUnused",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFont::IsGlyphRangeUnused))
	->args({"self","c_begin","c_last"})
;
using _begin_method_71 = DAS_CALL_MEMBER(ImGuiTextBuffer::begin);
addExtern<DAS_CALL_METHOD(_begin_method_71)>(*this, lib, "begin",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextBuffer::begin))
	->args({"self",})
;
using _end_method_72 = DAS_CALL_MEMBER(ImGuiTextBuffer::end);
addExtern<DAS_CALL_METHOD(_end_method_72)>(*this, lib, "end",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextBuffer::end))
	->args({"self",})
;
using _size_method_73 = DAS_CALL_MEMBER(ImGuiTextBuffer::size);
addExtern<DAS_CALL_METHOD(_size_method_73)>(*this, lib, "size",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextBuffer::size))
	->args({"self",})
;
using _empty_method_74 = DAS_CALL_MEMBER(ImGuiTextBuffer::empty);
addExtern<DAS_CALL_METHOD(_empty_method_74)>(*this, lib, "empty",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextBuffer::empty))
	->args({"self",})
;
using _clear_method_75 = DAS_CALL_MEMBER(ImGuiTextBuffer::clear);
addExtern<DAS_CALL_METHOD(_clear_method_75)>(*this, lib, "clear",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextBuffer::clear))
	->args({"self",})
;
using _reserve_method_76 = DAS_CALL_MEMBER(ImGuiTextBuffer::reserve);
addExtern<DAS_CALL_METHOD(_reserve_method_76)>(*this, lib, "reserve",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextBuffer::reserve))
	->args({"self","capacity"})
;
using _c_str_method_77 = DAS_CALL_MEMBER(ImGuiTextBuffer::c_str);
addExtern<DAS_CALL_METHOD(_c_str_method_77)>(*this, lib, "c_str",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextBuffer::c_str))
	->args({"self",})
;
using _appendfv_method_78 = DAS_CALL_MEMBER(ImGuiTextBuffer::appendfv);
addExtern<DAS_CALL_METHOD(_appendfv_method_78)>(*this, lib, "appendfv",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextBuffer::appendfv))
	->args({"self","fmt","args"})
;
using _DeleteChars_method_79 = DAS_CALL_MEMBER(ImGuiInputTextCallbackData::DeleteChars);
addExtern<DAS_CALL_METHOD(_DeleteChars_method_79)>(*this, lib, "DeleteChars",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiInputTextCallbackData::DeleteChars))
	->args({"self","pos","bytes_count"})
;
using _InsertChars_method_80 = DAS_CALL_MEMBER(ImGuiInputTextCallbackData::InsertChars);
addExtern<DAS_CALL_METHOD(_InsertChars_method_80)>(*this, lib, "InsertChars",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiInputTextCallbackData::InsertChars))
	->args({"self","pos","text","text_end"})
		->arg_init(3,make_smart<ExprConstString>(""))
;
using _SelectAll_method_81 = DAS_CALL_MEMBER(ImGuiInputTextCallbackData::SelectAll);
addExtern<DAS_CALL_METHOD(_SelectAll_method_81)>(*this, lib, "SelectAll",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiInputTextCallbackData::SelectAll))
	->args({"self",})
;
using _ClearSelection_method_82 = DAS_CALL_MEMBER(ImGuiInputTextCallbackData::ClearSelection);
addExtern<DAS_CALL_METHOD(_ClearSelection_method_82)>(*this, lib, "ClearSelection",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiInputTextCallbackData::ClearSelection))
	->args({"self",})
;
using _HasSelection_method_83 = DAS_CALL_MEMBER(ImGuiInputTextCallbackData::HasSelection);
addExtern<DAS_CALL_METHOD(_HasSelection_method_83)>(*this, lib, "HasSelection",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiInputTextCallbackData::HasSelection))
	->args({"self",})
;
using _GetCenter_method_84 = DAS_CALL_MEMBER(ImGuiViewport::GetCenter);
addExtern<DAS_CALL_METHOD(_GetCenter_method_84), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetCenter",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiViewport::GetCenter))
	->args({"self",})
;
using _GetWorkCenter_method_85 = DAS_CALL_MEMBER(ImGuiViewport::GetWorkCenter);
addExtern<DAS_CALL_METHOD(_GetWorkCenter_method_85), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetWorkCenter",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiViewport::GetWorkCenter))
	->args({"self",})
;
using _IsPacked_method_86 = DAS_CALL_MEMBER(ImFontAtlasCustomRect::IsPacked);
addExtern<DAS_CALL_METHOD(_IsPacked_method_86)>(*this, lib, "IsPacked",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImFontAtlasCustomRect::IsPacked))
	->args({"self",})
;
using _ScaleAllSizes_method_87 = DAS_CALL_MEMBER(ImGuiStyle::ScaleAllSizes);
addExtern<DAS_CALL_METHOD(_ScaleAllSizes_method_87)>(*this, lib, "ScaleAllSizes",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStyle::ScaleAllSizes))
	->args({"self","scale_factor"})
;
using _SetHSV_method_88 = DAS_CALL_MEMBER(ImColor::SetHSV);
addExtern<DAS_CALL_METHOD(_SetHSV_method_88)>(*this, lib, "SetHSV",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImColor::SetHSV))
	->args({"self","h","s","v","a"})
		->arg_init(4,make_smart<ExprConstFloat>(1))
;
using _Clear_method_89 = DAS_CALL_MEMBER(ImDrawListSplitter::Clear);
addExtern<DAS_CALL_METHOD(_Clear_method_89)>(*this, lib, "Clear",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawListSplitter::Clear))
	->args({"self",})
;
using _ClearFreeMemory_method_90 = DAS_CALL_MEMBER(ImDrawListSplitter::ClearFreeMemory);
addExtern<DAS_CALL_METHOD(_ClearFreeMemory_method_90)>(*this, lib, "ClearFreeMemory",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawListSplitter::ClearFreeMemory))
	->args({"self",})
;
using _Split_method_91 = DAS_CALL_MEMBER(ImDrawListSplitter::Split);
addExtern<DAS_CALL_METHOD(_Split_method_91)>(*this, lib, "Split",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawListSplitter::Split))
	->args({"self","draw_list","count"})
;
using _Merge_method_92 = DAS_CALL_MEMBER(ImDrawListSplitter::Merge);
addExtern<DAS_CALL_METHOD(_Merge_method_92)>(*this, lib, "Merge",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawListSplitter::Merge))
	->args({"self","draw_list"})
;
using _SetCurrentChannel_method_93 = DAS_CALL_MEMBER(ImDrawListSplitter::SetCurrentChannel);
addExtern<DAS_CALL_METHOD(_SetCurrentChannel_method_93)>(*this, lib, "SetCurrentChannel",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawListSplitter::SetCurrentChannel))
	->args({"self","draw_list","channel_idx"})
;
using _Clear_method_94 = DAS_CALL_MEMBER(ImGuiStorage::Clear);
addExtern<DAS_CALL_METHOD(_Clear_method_94)>(*this, lib, "Clear",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::Clear))
	->args({"self",})
;
using _GetInt_method_95 = DAS_CALL_MEMBER(ImGuiStorage::GetInt);
addExtern<DAS_CALL_METHOD(_GetInt_method_95)>(*this, lib, "GetInt",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::GetInt))
	->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstInt>(0))
;
using _SetInt_method_96 = DAS_CALL_MEMBER(ImGuiStorage::SetInt);
addExtern<DAS_CALL_METHOD(_SetInt_method_96)>(*this, lib, "SetInt",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::SetInt))
	->args({"self","key","val"})
;
using _GetBool_method_97 = DAS_CALL_MEMBER(ImGuiStorage::GetBool);
addExtern<DAS_CALL_METHOD(_GetBool_method_97)>(*this, lib, "GetBool",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::GetBool))
	->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstBool>(false))
;
using _SetBool_method_98 = DAS_CALL_MEMBER(ImGuiStorage::SetBool);
addExtern<DAS_CALL_METHOD(_SetBool_method_98)>(*this, lib, "SetBool",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::SetBool))
	->args({"self","key","val"})
;
using _GetFloat_method_99 = DAS_CALL_MEMBER(ImGuiStorage::GetFloat);
addExtern<DAS_CALL_METHOD(_GetFloat_method_99)>(*this, lib, "GetFloat",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::GetFloat))
	->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstFloat>(0))
;
using _SetFloat_method_100 = DAS_CALL_MEMBER(ImGuiStorage::SetFloat);
addExtern<DAS_CALL_METHOD(_SetFloat_method_100)>(*this, lib, "SetFloat",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::SetFloat))
	->args({"self","key","val"})
;
using _GetVoidPtr_method_101 = DAS_CALL_MEMBER(ImGuiStorage::GetVoidPtr);
addExtern<DAS_CALL_METHOD(_GetVoidPtr_method_101)>(*this, lib, "GetVoidPtr",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::GetVoidPtr))
	->args({"self","key"})
;
using _SetVoidPtr_method_102 = DAS_CALL_MEMBER(ImGuiStorage::SetVoidPtr);
addExtern<DAS_CALL_METHOD(_SetVoidPtr_method_102)>(*this, lib, "SetVoidPtr",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::SetVoidPtr))
	->args({"self","key","val"})
;
using _GetIntRef_method_103 = DAS_CALL_MEMBER(ImGuiStorage::GetIntRef);
addExtern<DAS_CALL_METHOD(_GetIntRef_method_103)>(*this, lib, "GetIntRef",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::GetIntRef))
	->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstInt>(0))
;
using _GetBoolRef_method_104 = DAS_CALL_MEMBER(ImGuiStorage::GetBoolRef);
addExtern<DAS_CALL_METHOD(_GetBoolRef_method_104)>(*this, lib, "GetBoolRef",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::GetBoolRef))
	->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstBool>(false))
;
using _GetFloatRef_method_105 = DAS_CALL_MEMBER(ImGuiStorage::GetFloatRef);
addExtern<DAS_CALL_METHOD(_GetFloatRef_method_105)>(*this, lib, "GetFloatRef",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::GetFloatRef))
	->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstFloat>(0))
;
using _GetVoidPtrRef_method_106 = DAS_CALL_MEMBER(ImGuiStorage::GetVoidPtrRef);
addExtern<DAS_CALL_METHOD(_GetVoidPtrRef_method_106)>(*this, lib, "GetVoidPtrRef",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::GetVoidPtrRef))
	->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstPtr>())
;
using _SetAllInt_method_107 = DAS_CALL_MEMBER(ImGuiStorage::SetAllInt);
addExtern<DAS_CALL_METHOD(_SetAllInt_method_107)>(*this, lib, "SetAllInt",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::SetAllInt))
	->args({"self","val"})
;
using _BuildSortByKey_method_108 = DAS_CALL_MEMBER(ImGuiStorage::BuildSortByKey);
addExtern<DAS_CALL_METHOD(_BuildSortByKey_method_108)>(*this, lib, "BuildSortByKey",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiStorage::BuildSortByKey))
	->args({"self",})
;
using _empty_method_109 = DAS_CALL_MEMBER(ImGuiTextFilter::ImGuiTextRange::empty);
addExtern<DAS_CALL_METHOD(_empty_method_109)>(*this, lib, "empty",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextFilter::ImGuiTextRange::empty))
	->args({"self",})
;
using _split_method_110 = DAS_CALL_MEMBER(ImGuiTextFilter::ImGuiTextRange::split);
addExtern<DAS_CALL_METHOD(_split_method_110)>(*this, lib, "split",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImGuiTextFilter::ImGuiTextRange::split))
	->args({"self","separator","out"})
;
using _PushClipRect_method_111 = DAS_CALL_MEMBER(ImDrawList::PushClipRect);
addExtern<DAS_CALL_METHOD(_PushClipRect_method_111)>(*this, lib, "PushClipRect",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PushClipRect))
	->args({"self","clip_rect_min","clip_rect_max","intersect_with_current_clip_rect"})
		->arg_init(3,make_smart<ExprConstBool>(false))
;
using _PushClipRectFullScreen_method_112 = DAS_CALL_MEMBER(ImDrawList::PushClipRectFullScreen);
addExtern<DAS_CALL_METHOD(_PushClipRectFullScreen_method_112)>(*this, lib, "PushClipRectFullScreen",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PushClipRectFullScreen))
	->args({"self",})
;
using _PopClipRect_method_113 = DAS_CALL_MEMBER(ImDrawList::PopClipRect);
addExtern<DAS_CALL_METHOD(_PopClipRect_method_113)>(*this, lib, "PopClipRect",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PopClipRect))
	->args({"self",})
;
using _PushTextureID_method_114 = DAS_CALL_MEMBER(ImDrawList::PushTextureID);
addExtern<DAS_CALL_METHOD(_PushTextureID_method_114)>(*this, lib, "PushTextureID",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PushTextureID))
	->args({"self","texture_id"})
;
using _PopTextureID_method_115 = DAS_CALL_MEMBER(ImDrawList::PopTextureID);
addExtern<DAS_CALL_METHOD(_PopTextureID_method_115)>(*this, lib, "PopTextureID",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PopTextureID))
	->args({"self",})
;
using _GetClipRectMin_method_116 = DAS_CALL_MEMBER(ImDrawList::GetClipRectMin);
addExtern<DAS_CALL_METHOD(_GetClipRectMin_method_116), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetClipRectMin",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::GetClipRectMin))
	->args({"self",})
;
using _GetClipRectMax_method_117 = DAS_CALL_MEMBER(ImDrawList::GetClipRectMax);
addExtern<DAS_CALL_METHOD(_GetClipRectMax_method_117), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "GetClipRectMax",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::GetClipRectMax))
	->args({"self",})
;
using _AddLine_method_118 = DAS_CALL_MEMBER(ImDrawList::AddLine);
addExtern<DAS_CALL_METHOD(_AddLine_method_118)>(*this, lib, "AddLine",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddLine))
	->args({"self","p1","p2","col","thickness"})
		->arg_init(4,make_smart<ExprConstFloat>(1))
;
using _AddRect_method_119 = DAS_CALL_MEMBER(ImDrawList::AddRect);
addExtern<DAS_CALL_METHOD(_AddRect_method_119)>(*this, lib, "AddRect",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddRect))
	->args({"self","p_min","p_max","col","rounding","rounding_corners","thickness"})
		->arg_init(4,make_smart<ExprConstFloat>(0))
		->arg_type(5,makeType<ImDrawCornerFlags_>(lib))
		->arg_init(6,make_smart<ExprConstFloat>(1))
;
using _AddRectFilled_method_120 = DAS_CALL_MEMBER(ImDrawList::AddRectFilled);
addExtern<DAS_CALL_METHOD(_AddRectFilled_method_120)>(*this, lib, "AddRectFilled",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddRectFilled))
	->args({"self","p_min","p_max","col","rounding","rounding_corners"})
		->arg_init(4,make_smart<ExprConstFloat>(0))
		->arg_type(5,makeType<ImDrawCornerFlags_>(lib))
;
using _AddRectFilledMultiColor_method_121 = DAS_CALL_MEMBER(ImDrawList::AddRectFilledMultiColor);
addExtern<DAS_CALL_METHOD(_AddRectFilledMultiColor_method_121)>(*this, lib, "AddRectFilledMultiColor",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddRectFilledMultiColor))
	->args({"self","p_min","p_max","col_upr_left","col_upr_right","col_bot_right","col_bot_left"})
;
using _AddQuad_method_122 = DAS_CALL_MEMBER(ImDrawList::AddQuad);
addExtern<DAS_CALL_METHOD(_AddQuad_method_122)>(*this, lib, "AddQuad",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddQuad))
	->args({"self","p1","p2","p3","p4","col","thickness"})
		->arg_init(6,make_smart<ExprConstFloat>(1))
;
using _AddQuadFilled_method_123 = DAS_CALL_MEMBER(ImDrawList::AddQuadFilled);
addExtern<DAS_CALL_METHOD(_AddQuadFilled_method_123)>(*this, lib, "AddQuadFilled",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddQuadFilled))
	->args({"self","p1","p2","p3","p4","col"})
;
using _AddTriangle_method_124 = DAS_CALL_MEMBER(ImDrawList::AddTriangle);
addExtern<DAS_CALL_METHOD(_AddTriangle_method_124)>(*this, lib, "AddTriangle",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddTriangle))
	->args({"self","p1","p2","p3","col","thickness"})
		->arg_init(5,make_smart<ExprConstFloat>(1))
;
using _AddTriangleFilled_method_125 = DAS_CALL_MEMBER(ImDrawList::AddTriangleFilled);
addExtern<DAS_CALL_METHOD(_AddTriangleFilled_method_125)>(*this, lib, "AddTriangleFilled",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddTriangleFilled))
	->args({"self","p1","p2","p3","col"})
;
using _AddCircle_method_126 = DAS_CALL_MEMBER(ImDrawList::AddCircle);
addExtern<DAS_CALL_METHOD(_AddCircle_method_126)>(*this, lib, "AddCircle",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddCircle))
	->args({"self","center","radius","col","num_segments","thickness"})
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstFloat>(1))
;
using _AddCircleFilled_method_127 = DAS_CALL_MEMBER(ImDrawList::AddCircleFilled);
addExtern<DAS_CALL_METHOD(_AddCircleFilled_method_127)>(*this, lib, "AddCircleFilled",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddCircleFilled))
	->args({"self","center","radius","col","num_segments"})
		->arg_init(4,make_smart<ExprConstInt>(0))
;
using _AddNgon_method_128 = DAS_CALL_MEMBER(ImDrawList::AddNgon);
addExtern<DAS_CALL_METHOD(_AddNgon_method_128)>(*this, lib, "AddNgon",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddNgon))
	->args({"self","center","radius","col","num_segments","thickness"})
		->arg_init(5,make_smart<ExprConstFloat>(1))
;
using _AddNgonFilled_method_129 = DAS_CALL_MEMBER(ImDrawList::AddNgonFilled);
addExtern<DAS_CALL_METHOD(_AddNgonFilled_method_129)>(*this, lib, "AddNgonFilled",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddNgonFilled))
	->args({"self","center","radius","col","num_segments"})
;
using _AddPolyline_method_130 = DAS_CALL_MEMBER(ImDrawList::AddPolyline);
addExtern<DAS_CALL_METHOD(_AddPolyline_method_130)>(*this, lib, "AddPolyline",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddPolyline))
	->args({"self","points","num_points","col","closed","thickness"})
;
using _AddConvexPolyFilled_method_131 = DAS_CALL_MEMBER(ImDrawList::AddConvexPolyFilled);
addExtern<DAS_CALL_METHOD(_AddConvexPolyFilled_method_131)>(*this, lib, "AddConvexPolyFilled",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddConvexPolyFilled))
	->args({"self","points","num_points","col"})
;
using _AddBezierCubic_method_132 = DAS_CALL_MEMBER(ImDrawList::AddBezierCubic);
addExtern<DAS_CALL_METHOD(_AddBezierCubic_method_132)>(*this, lib, "AddBezierCubic",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddBezierCubic))
	->args({"self","p1","p2","p3","p4","col","thickness","num_segments"})
		->arg_init(7,make_smart<ExprConstInt>(0))
;
using _AddBezierQuadratic_method_133 = DAS_CALL_MEMBER(ImDrawList::AddBezierQuadratic);
addExtern<DAS_CALL_METHOD(_AddBezierQuadratic_method_133)>(*this, lib, "AddBezierQuadratic",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddBezierQuadratic))
	->args({"self","p1","p2","p3","col","thickness","num_segments"})
		->arg_init(6,make_smart<ExprConstInt>(0))
;
using _AddImage_method_134 = DAS_CALL_MEMBER(ImDrawList::AddImage);
addExtern<DAS_CALL_METHOD(_AddImage_method_134)>(*this, lib, "AddImage",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddImage))
	->args({"self","user_texture_id","p_min","p_max","uv_min","uv_max","col"})
;
using _AddImageQuad_method_135 = DAS_CALL_MEMBER(ImDrawList::AddImageQuad);
addExtern<DAS_CALL_METHOD(_AddImageQuad_method_135)>(*this, lib, "AddImageQuad",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddImageQuad))
	->args({"self","user_texture_id","p1","p2","p3","p4","uv1","uv2","uv3","uv4","col"})
;
using _AddImageRounded_method_136 = DAS_CALL_MEMBER(ImDrawList::AddImageRounded);
addExtern<DAS_CALL_METHOD(_AddImageRounded_method_136)>(*this, lib, "AddImageRounded",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddImageRounded))
	->args({"self","user_texture_id","p_min","p_max","uv_min","uv_max","col","rounding","rounding_corners"})
		->arg_type(8,makeType<ImDrawCornerFlags_>(lib))
;
using _PathClear_method_137 = DAS_CALL_MEMBER(ImDrawList::PathClear);
addExtern<DAS_CALL_METHOD(_PathClear_method_137)>(*this, lib, "PathClear",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PathClear))
	->args({"self",})
;
using _PathLineTo_method_138 = DAS_CALL_MEMBER(ImDrawList::PathLineTo);
addExtern<DAS_CALL_METHOD(_PathLineTo_method_138)>(*this, lib, "PathLineTo",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PathLineTo))
	->args({"self","pos"})
;
using _PathLineToMergeDuplicate_method_139 = DAS_CALL_MEMBER(ImDrawList::PathLineToMergeDuplicate);
addExtern<DAS_CALL_METHOD(_PathLineToMergeDuplicate_method_139)>(*this, lib, "PathLineToMergeDuplicate",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PathLineToMergeDuplicate))
	->args({"self","pos"})
;
using _PathFillConvex_method_140 = DAS_CALL_MEMBER(ImDrawList::PathFillConvex);
addExtern<DAS_CALL_METHOD(_PathFillConvex_method_140)>(*this, lib, "PathFillConvex",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PathFillConvex))
	->args({"self","col"})
;
using _PathStroke_method_141 = DAS_CALL_MEMBER(ImDrawList::PathStroke);
addExtern<DAS_CALL_METHOD(_PathStroke_method_141)>(*this, lib, "PathStroke",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PathStroke))
	->args({"self","col","closed","thickness"})
		->arg_init(3,make_smart<ExprConstFloat>(1))
;
using _PathArcTo_method_142 = DAS_CALL_MEMBER(ImDrawList::PathArcTo);
addExtern<DAS_CALL_METHOD(_PathArcTo_method_142)>(*this, lib, "PathArcTo",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PathArcTo))
	->args({"self","center","radius","a_min","a_max","num_segments"})
		->arg_init(5,make_smart<ExprConstInt>(10))
;
using _PathArcToFast_method_143 = DAS_CALL_MEMBER(ImDrawList::PathArcToFast);
addExtern<DAS_CALL_METHOD(_PathArcToFast_method_143)>(*this, lib, "PathArcToFast",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PathArcToFast))
	->args({"self","center","radius","a_min_of_12","a_max_of_12"})
;
using _PathBezierCubicCurveTo_method_144 = DAS_CALL_MEMBER(ImDrawList::PathBezierCubicCurveTo);
addExtern<DAS_CALL_METHOD(_PathBezierCubicCurveTo_method_144)>(*this, lib, "PathBezierCubicCurveTo",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PathBezierCubicCurveTo))
	->args({"self","p2","p3","p4","num_segments"})
		->arg_init(4,make_smart<ExprConstInt>(0))
;
using _PathBezierQuadraticCurveTo_method_145 = DAS_CALL_MEMBER(ImDrawList::PathBezierQuadraticCurveTo);
addExtern<DAS_CALL_METHOD(_PathBezierQuadraticCurveTo_method_145)>(*this, lib, "PathBezierQuadraticCurveTo",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PathBezierQuadraticCurveTo))
	->args({"self","p2","p3","num_segments"})
		->arg_init(3,make_smart<ExprConstInt>(0))
;
using _PathRect_method_146 = DAS_CALL_MEMBER(ImDrawList::PathRect);
addExtern<DAS_CALL_METHOD(_PathRect_method_146)>(*this, lib, "PathRect",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PathRect))
	->args({"self","rect_min","rect_max","rounding","rounding_corners"})
		->arg_init(3,make_smart<ExprConstFloat>(0))
		->arg_type(4,makeType<ImDrawCornerFlags_>(lib))
;
using _AddCallback_method_147 = DAS_CALL_MEMBER(ImDrawList::AddCallback);
addExtern<DAS_CALL_METHOD(_AddCallback_method_147)>(*this, lib, "AddCallback",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddCallback))
	->args({"self","callback","callback_data"})
;
using _AddDrawCmd_method_148 = DAS_CALL_MEMBER(ImDrawList::AddDrawCmd);
addExtern<DAS_CALL_METHOD(_AddDrawCmd_method_148)>(*this, lib, "AddDrawCmd",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddDrawCmd))
	->args({"self",})
;
using _CloneOutput_method_149 = DAS_CALL_MEMBER(ImDrawList::CloneOutput);
addExtern<DAS_CALL_METHOD(_CloneOutput_method_149)>(*this, lib, "CloneOutput",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::CloneOutput))
	->args({"self",})
;
using _ChannelsSplit_method_150 = DAS_CALL_MEMBER(ImDrawList::ChannelsSplit);
addExtern<DAS_CALL_METHOD(_ChannelsSplit_method_150)>(*this, lib, "ChannelsSplit",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::ChannelsSplit))
	->args({"self","count"})
;
using _ChannelsMerge_method_151 = DAS_CALL_MEMBER(ImDrawList::ChannelsMerge);
addExtern<DAS_CALL_METHOD(_ChannelsMerge_method_151)>(*this, lib, "ChannelsMerge",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::ChannelsMerge))
	->args({"self",})
;
using _ChannelsSetCurrent_method_152 = DAS_CALL_MEMBER(ImDrawList::ChannelsSetCurrent);
addExtern<DAS_CALL_METHOD(_ChannelsSetCurrent_method_152)>(*this, lib, "ChannelsSetCurrent",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::ChannelsSetCurrent))
	->args({"self","n"})
;
using _PrimReserve_method_153 = DAS_CALL_MEMBER(ImDrawList::PrimReserve);
addExtern<DAS_CALL_METHOD(_PrimReserve_method_153)>(*this, lib, "PrimReserve",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PrimReserve))
	->args({"self","idx_count","vtx_count"})
;
using _PrimUnreserve_method_154 = DAS_CALL_MEMBER(ImDrawList::PrimUnreserve);
addExtern<DAS_CALL_METHOD(_PrimUnreserve_method_154)>(*this, lib, "PrimUnreserve",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PrimUnreserve))
	->args({"self","idx_count","vtx_count"})
;
using _PrimRect_method_155 = DAS_CALL_MEMBER(ImDrawList::PrimRect);
addExtern<DAS_CALL_METHOD(_PrimRect_method_155)>(*this, lib, "PrimRect",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PrimRect))
	->args({"self","a","b","col"})
;
using _PrimRectUV_method_156 = DAS_CALL_MEMBER(ImDrawList::PrimRectUV);
addExtern<DAS_CALL_METHOD(_PrimRectUV_method_156)>(*this, lib, "PrimRectUV",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PrimRectUV))
	->args({"self","a","b","uv_a","uv_b","col"})
;
using _PrimQuadUV_method_157 = DAS_CALL_MEMBER(ImDrawList::PrimQuadUV);
addExtern<DAS_CALL_METHOD(_PrimQuadUV_method_157)>(*this, lib, "PrimQuadUV",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PrimQuadUV))
	->args({"self","a","b","c","d","uv_a","uv_b","uv_c","uv_d","col"})
;
using _PrimWriteVtx_method_158 = DAS_CALL_MEMBER(ImDrawList::PrimWriteVtx);
addExtern<DAS_CALL_METHOD(_PrimWriteVtx_method_158)>(*this, lib, "PrimWriteVtx",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PrimWriteVtx))
	->args({"self","pos","uv","col"})
;
using _PrimWriteIdx_method_159 = DAS_CALL_MEMBER(ImDrawList::PrimWriteIdx);
addExtern<DAS_CALL_METHOD(_PrimWriteIdx_method_159)>(*this, lib, "PrimWriteIdx",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PrimWriteIdx))
	->args({"self","idx"})
;
using _PrimVtx_method_160 = DAS_CALL_MEMBER(ImDrawList::PrimVtx);
addExtern<DAS_CALL_METHOD(_PrimVtx_method_160)>(*this, lib, "PrimVtx",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PrimVtx))
	->args({"self","pos","uv","col"})
;
using _AddBezierCurve_method_161 = DAS_CALL_MEMBER(ImDrawList::AddBezierCurve);
addExtern<DAS_CALL_METHOD(_AddBezierCurve_method_161)>(*this, lib, "AddBezierCurve",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::AddBezierCurve))
	->args({"self","p1","p2","p3","p4","col","thickness","num_segments"})
		->arg_init(7,make_smart<ExprConstInt>(0))
;
using _PathBezierCurveTo_method_162 = DAS_CALL_MEMBER(ImDrawList::PathBezierCurveTo);
addExtern<DAS_CALL_METHOD(_PathBezierCurveTo_method_162)>(*this, lib, "PathBezierCurveTo",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::PathBezierCurveTo))
	->args({"self","p2","p3","p4","num_segments"})
		->arg_init(4,make_smart<ExprConstInt>(0))
;
using __ResetForNewFrame_method_163 = DAS_CALL_MEMBER(ImDrawList::_ResetForNewFrame);
addExtern<DAS_CALL_METHOD(__ResetForNewFrame_method_163)>(*this, lib, "_ResetForNewFrame",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::_ResetForNewFrame))
	->args({"self",})
;
using __ClearFreeMemory_method_164 = DAS_CALL_MEMBER(ImDrawList::_ClearFreeMemory);
addExtern<DAS_CALL_METHOD(__ClearFreeMemory_method_164)>(*this, lib, "_ClearFreeMemory",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::_ClearFreeMemory))
	->args({"self",})
;
using __PopUnusedDrawCmd_method_165 = DAS_CALL_MEMBER(ImDrawList::_PopUnusedDrawCmd);
addExtern<DAS_CALL_METHOD(__PopUnusedDrawCmd_method_165)>(*this, lib, "_PopUnusedDrawCmd",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::_PopUnusedDrawCmd))
	->args({"self",})
;
using __OnChangedClipRect_method_166 = DAS_CALL_MEMBER(ImDrawList::_OnChangedClipRect);
addExtern<DAS_CALL_METHOD(__OnChangedClipRect_method_166)>(*this, lib, "_OnChangedClipRect",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::_OnChangedClipRect))
	->args({"self",})
;
using __OnChangedTextureID_method_167 = DAS_CALL_MEMBER(ImDrawList::_OnChangedTextureID);
addExtern<DAS_CALL_METHOD(__OnChangedTextureID_method_167)>(*this, lib, "_OnChangedTextureID",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::_OnChangedTextureID))
	->args({"self",})
;
using __OnChangedVtxOffset_method_168 = DAS_CALL_MEMBER(ImDrawList::_OnChangedVtxOffset);
addExtern<DAS_CALL_METHOD(__OnChangedVtxOffset_method_168)>(*this, lib, "_OnChangedVtxOffset",SideEffects::worstDefault, DAS_CALL_MEMBER_CPP(ImDrawList::_OnChangedVtxOffset))
	->args({"self",})
;
