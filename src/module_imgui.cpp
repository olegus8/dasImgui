#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"

#include <imgui.h>

using namespace das;

#include "need_imgui.h"

#if USE_GENERATED

#include "module_imgui.h"

#endif

namespace das {
    void Text ( const char * txt ) {
        ImGui::Text(txt);
    }
    void LabelText ( const char * lab, const char * txt ) {
        ImGui::LabelText(lab, txt);
    }
    void TextWrapped ( const char * txt ) {
        ImGui::TextWrapped(txt);
    }
    void TextDisabled ( const char * txt ) {
        ImGui::TextDisabled(txt);
    }
    void TextColored ( const ImVec4 & col, const char * txt ) {
        ImGui::TextColored(col,txt);
    }
    void LogText ( const char * txt ) {
        ImGui::LogText(txt);
    }
    bool TreeNode ( const char * id, const char * txt ) {
        return ImGui::TreeNode(id,txt);
    }
    bool TreeNodeEx ( const char * id, ImGuiTreeNodeFlags_ flags, const char * txt ) {
        return ImGui::TreeNodeEx(id, flags, txt);
    }
    bool TreeNodeEx2 ( const void * id, ImGuiTreeNodeFlags_ flags, const char * txt ) {
        return ImGui::TreeNodeEx(id, flags, txt);
    }
    void TextUnformatted ( const char * txt ) {
        ImGui::TextUnformatted(txt, nullptr);
    }
    void BulletText ( const char * txt ) {
        ImGui::BulletText(txt);
    }
    void SetTooltip ( const char * txt ) {
        ImGui::SetTooltip(txt);
    }

    struct DasImguiInputText {
        Context *  context;
        TLambda<void,DasImguiInputText *,ImGuiInputTextCallbackData *>    callback;
        TArray<uint8_t> buffer;
        LineInfo        at;
    };

    int InputTextCallback (ImGuiInputTextCallbackData* data) {
        auto diit = (DasImguiInputText *) data->UserData;
        DAS_VERIFY(diit->context && "context is always specified");
        if ( !diit->callback.capture ) {
            diit->context->throw_error("ImguiTextCallback: missing capture");
        }
        return das_invoke_lambda<int>::invoke<DasImguiInputText *,ImGuiInputTextCallbackData *>(diit->context, diit->callback, diit, data);
    }

    bool InputTextMultiline(vec4f vdiit, const char* label, const ImVec2& size, ImGuiInputTextFlags_ flags, LineInfoArg * at, Context * context ) {
        auto diit = cast<DasImguiInputText *>::to(vdiit);
        if ( diit->buffer.size==0 ) {
            builtin_array_resize(diit->buffer, 256, 1, context);
        }
        if ( diit->callback.capture ) {
            diit->context = context;
            diit->at = *at;
            return ImGui::InputTextMultiline(
                label,
                diit->buffer.data,
                diit->buffer.size,
                size,
                flags,
                &InputTextCallback,
                diit
            );
        } else {
            return ImGui::InputTextMultiline(label, diit->buffer.data, diit->buffer.size, size, flags);
        }
    }

    bool InputText(vec4f vdiit, const char * label, ImGuiInputTextFlags_ flags, LineInfoArg * at, Context * context ) {
        auto diit = cast<DasImguiInputText *>::to(vdiit);
        if ( diit->buffer.size==0 ) {
            builtin_array_resize(diit->buffer, 256, 1, context);
        }
        if ( diit->callback.capture ) {
            diit->context = context;
            diit->at = *at;
            return ImGui::InputText(
                label,
                diit->buffer.data,
                diit->buffer.size,
                flags,
                &InputTextCallback,
                diit
            );
        } else {
            return ImGui::InputText(label, diit->buffer.data, diit->buffer.size, flags);
        }
    }

    bool InputTextWithHint(vec4f vdiit, const char * label, const char * hint, ImGuiInputTextFlags_ flags, LineInfoArg * at, Context * context ) {
        auto diit = cast<DasImguiInputText *>::to(vdiit);
        if ( diit->buffer.size==0 ) {
            builtin_array_resize(diit->buffer, 256, 1, context);
        }
        if ( diit->callback.capture ) {
            diit->context = context;
            diit->at = *at;
            return ImGui::InputTextWithHint(
                label,
                hint,
                diit->buffer.data,
                diit->buffer.size,
                flags,
                &InputTextCallback,
                diit
            );
        } else {
            return ImGui::InputTextWithHint(label, hint, diit->buffer.data, diit->buffer.size, flags);
        }
    }

    // ImGui::ImGuiTextFilter::PassFilter

    bool PassFilter ( ImGuiTextFilter & filter, const char* text ) {
        return filter.PassFilter(text, nullptr);
    }

    void AddText( ImDrawList & drawList, const ImVec2& pos, ImU32 col, const char* text ) {
        drawList.AddText(pos, col, text);
    }

    void AddText2( ImDrawList & drawList, const ImFont* font, float font_size, const ImVec2& pos, ImU32 col,
        const char* text_begin, float wrap_width = 0.0f, const ImVec4* cpu_fine_clip_rect = nullptr) {
        drawList.AddText(font,font_size,pos,col,text_begin,nullptr,wrap_width,cpu_fine_clip_rect);
    }

    // ImColor

    ImColor HSV(float h, float s, float v, float a = 1.0f) {
        return ImColor::HSV(h,s,v,a);
    }

    // ImGuiTextBuffer

    void ImGTB_Append ( ImGuiTextBuffer & buf, const char * txt ) {
        buf.append(txt, nullptr);
    }

    int ImGTB_At ( ImGuiTextBuffer & buf, int32_t index ) {
        return buf[index];
    }

    void ImGTB_SetAt ( ImGuiTextBuffer & buf, int32_t index, int32_t value ) {
        buf.Buf[index] = (char) value;
    }

    char * ImGTB_Slice ( ImGuiTextBuffer & buf, int32_t head, int32_t tail, Context * context, LineInfoArg * at ) {
        if ( head>tail ) {
            context->throw_error_at(*at, "can't get slice of ImGuiTextBuffer, head > tail");
        }
        int32_t len = tail - head;
        if ( len>buf.size() ) {
            context->throw_error_at(*at, "can't get slice of ImGuiTextBuffer, slice too big");
        }
        return context->stringHeap->allocateString(buf.begin() + head,len+1);
    }

    // ImGuiInputTextCallbackData

    void InsertChars(ImGuiInputTextCallbackData & data, int pos, const char* text ) {
        data.InsertChars(pos, text);
    }

    // SetNextWindowSizeConstraints

    struct SNWSCC {
        Context *   context;
        Lambda      lambda;
        LineInfo    at;
    };

    void SetNextWindowSizeConstraintsCallback ( ImGuiSizeCallbackData* data ) {
        SNWSCC * temp = (SNWSCC *) data->UserData;
        if ( !temp->lambda.capture ) {
            temp->context->throw_error_at(temp->at, "expecting lambda");
        }
        das_invoke_lambda<void>::invoke<ImGuiSizeCallbackData*>(temp->context,temp->lambda,data);
    }

    void SetNextWindowSizeConstraints(vec4f snwscc, const ImVec2& size_min, const ImVec2& size_max, Context * context, LineInfoArg * at ) {
        SNWSCC * temp = cast<SNWSCC *>::to(snwscc);
        temp->context = context;
        temp->at = *at;
        ImGui::SetNextWindowSizeConstraints(size_min, size_max, &SetNextWindowSizeConstraintsCallback, temp);
    }

    ImGuiSortDirection_ SortDirection ( const ImGuiTableColumnSortSpecs & specs ) {
        return ImGuiSortDirection_(specs.SortDirection);
    }

    ImVec2 CalcTextSize(const char* text,bool hide_text_after_double_hash, float wrap_width) {
        return ImGui::CalcTextSize(text,nullptr,hide_text_after_double_hash,wrap_width);
    }

    // Combo with accessor
    struct ImGuiComboGetter {
        Context *   context;
        Lambda      lambda;
        LineInfo    at;
    };

    bool ComboGetterCallback ( void* data, int idx, const char** out_text ) {
        ImGuiComboGetter * getter = (ImGuiComboGetter *) data;
        if ( !getter->lambda.capture ) {
            getter->context->throw_error_at(getter->at, "expecting lambda");
        }
        *out_text = nullptr;
        auto res = das_invoke_lambda<bool>::invoke<int,char **>(getter->context,getter->lambda,idx,(char **)out_text);
        if ( *out_text==nullptr ) *out_text = "";
        return res;
    }

    bool Combo ( vec4f cg, const char * label, int * current_item, int items_count, int popup_max_height_in_items, Context * ctx, LineInfoArg * at ) {
        ImGuiComboGetter * getter = cast<ImGuiComboGetter *>::to(cg);
        getter->context = ctx;
        getter->at = *at;
        return ImGui::Combo(label,current_item,&ComboGetterCallback,getter,items_count,popup_max_height_in_items);
    }

    // Plot lines or historgrams

    struct ImGuiPlotGetter {
        Context *   context;
        Lambda      lambda;
        LineInfo    at;
    };

    float PlotLinesCallback ( void* data, int idx ) {
        ImGuiPlotGetter * getter = (ImGuiPlotGetter *) data;
        if ( !getter->lambda.capture ) {
            getter->context->throw_error_at(getter->at, "expecting lambda");
        }
        return  das_invoke_lambda<float>::invoke<int>(getter->context,getter->lambda,idx);
    }

    void PlotLines ( vec4f igpg, const char* label, int values_count, int values_offset, const char* overlay_text,
        float scale_min, float scale_max, ImVec2 graph_size, Context * ctx, LineInfoArg * at ) {
        ImGuiPlotGetter * getter = cast<ImGuiPlotGetter *>::to(igpg);
        getter->context = ctx;
        getter->at = *at;
        return ImGui::PlotLines(label, &PlotLinesCallback, getter, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size );
    }

    void PlotHistogram ( vec4f igpg, const char* label, int values_count, int values_offset, const char* overlay_text,
        float scale_min, float scale_max, ImVec2 graph_size, Context * ctx, LineInfoArg * at ) {
        ImGuiPlotGetter * getter = cast<ImGuiPlotGetter *>::to(igpg);
        getter->context = ctx;
        getter->at = *at;
        return ImGui::PlotHistogram(label, &PlotLinesCallback, getter, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size );
    }
}

Module_imgui::Module_imgui() : Module("imgui") {
    // check version
    IMGUI_CHECKVERSION();
    // make basic module
    lib.addModule(this);
    lib.addBuiltInModule();
    addAnnotation(make_smart<DummyTypeAnnotation>("ImGuiContext", "ImGuiContext",
        1, 1)); // sizeof(ImGuiContext), alignof(ImGuiContext)));
    addAnnotation(make_smart<DummyTypeAnnotation>("ImDrawListSharedData", "ImDrawListSharedData",
        1, 1)); // sizeof(ImGuiContext), alignof(ImGuiContext)));
    addAnnotation(make_smart<DummyTypeAnnotation>("ImFontBuilderIO", "ImFontBuilderIO",
        1, 1)); // sizeof(ImGuiContext), alignof(ImGuiContext)));
    // constants
    addConstant(*this,"IMGUI_VERSION", IMGUI_VERSION);
    addConstant(*this,"IMGUI_VERSION_NUM", IMGUI_VERSION_NUM);
}

bool Module_imgui::initDependencies() {
    if ( initialized ) return true;
    initialized = true;
    initEnums();
    initAnnotations();
    initFunctions();
    initMethods();
#if USE_GENERATED
    // constants
    addConstant(*this,"IM_COL32_A_MASK",uint32_t(IM_COL32_A_MASK));
    addConstant(*this,"IM_COL32_R_SHIFT",uint32_t(IM_COL32_R_SHIFT));
    addConstant(*this,"IM_COL32_G_SHIFT",uint32_t(IM_COL32_G_SHIFT));
    addConstant(*this,"IM_COL32_B_SHIFT",uint32_t(IM_COL32_B_SHIFT));
    addConstant(*this,"IM_COL32_A_SHIFT",uint32_t(IM_COL32_A_SHIFT));
    // vector C-tors
    addCtor<ImVec2>(*this,lib,"ImVec2","ImVec2");
    addCtor<ImVec2,float,float>(*this,lib,"ImVec2","ImVec2");
    addCtor<ImVec4>(*this,lib,"ImVec4","ImVec4");
    addCtor<ImVec4,float,float,float,float>(*this,lib,"ImVec4","ImVec4");
    // imgui text filter
    addExtern<DAS_BIND_FUN(das::PassFilter)>(*this, lib, "PassFilter",
        SideEffects::worstDefault, "das::PassFilter");
    // imcolor
    addCtor<ImColor>(*this,lib,"ImColor","ImColor");
    addCtor<ImColor,const ImVec4 &>(*this,lib,"ImColor","ImColor");
    addExtern<DAS_BIND_FUN(das::HSV),SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "HSV",
        SideEffects::none, "das::HSV")
            ->args({"h","s","v","a"})
                ->arg_init(3,make_smart<ExprConstFloat>(1.0f));
    // imgui draw list
    addExtern<DAS_BIND_FUN(das::AddText)>(*this, lib, "AddText",
        SideEffects::worstDefault, "das::AddText");
    addExtern<DAS_BIND_FUN(das::AddText2)>(*this, lib, "AddText",
        SideEffects::worstDefault, "das::AddText2")
	        ->args({"drawList","font","font_size","pos","col","text","wrap_width","cpu_fine_clip_rect"})
		        ->arg_init(6,make_smart<ExprConstFloat>(0.0f))
		        ->arg_init(7,make_smart<ExprConstPtr>());
    // variadic functions
    addExtern<DAS_BIND_FUN(das::Text)>(*this,lib,"Text",
        SideEffects::worstDefault,"das::Text");
    addExtern<DAS_BIND_FUN(das::TextWrapped)>(*this,lib,"TextWrapped",
        SideEffects::worstDefault,"das::TextWrapped");
    addExtern<DAS_BIND_FUN(das::TextDisabled)>(*this,lib,"TextDisabled",
        SideEffects::worstDefault,"das::TextDisabled");
    addExtern<DAS_BIND_FUN(das::TextColored)>(*this,lib,"TextColored",
        SideEffects::worstDefault,"das::TextColored");
    addExtern<DAS_BIND_FUN(das::LabelText)>(*this,lib,"LabelText",
        SideEffects::worstDefault,"das::LabelText");
    addExtern<DAS_BIND_FUN(das::LogText)>(*this,lib,"LogText",
        SideEffects::worstDefault,"das::LogText");
    addExtern<DAS_BIND_FUN(das::TreeNode)>(*this,lib,"TreeNode",
        SideEffects::worstDefault,"das::TreeNode");
    addExtern<DAS_BIND_FUN(das::TreeNodeEx)>(*this,lib,"TreeNodeEx",
        SideEffects::worstDefault,"das::TreeNodeEx");
    addExtern<DAS_BIND_FUN(das::TreeNodeEx2)>(*this,lib,"TreeNodeEx",
        SideEffects::worstDefault,"das::TreeNodeEx2");
    addExtern<DAS_BIND_FUN(das::BulletText)>(*this,lib,"BulletText",
        SideEffects::worstDefault,"das::BulletText");
    addExtern<DAS_BIND_FUN(das::SetTooltip)>(*this,lib,"SetTooltip",
        SideEffects::worstDefault,"das::SetTooltip");
    // text unfromatted
    addExtern<DAS_BIND_FUN(das::TextUnformatted)>(*this, lib, "TextUnformatted",
        SideEffects::worstDefault, "das::TextUnformatted")
        ->arg("text");
    // input text
    addExtern<DAS_BIND_FUN(das::InputText)>(*this, lib, "_builtin_InputText",
        SideEffects::worstDefault, "das::InputText");
    addExtern<DAS_BIND_FUN(das::InputTextWithHint)>(*this, lib, "_builtin_InputTextWithHint",
        SideEffects::worstDefault, "das::InputTextWithHint");
    addExtern<DAS_BIND_FUN(das::InputTextMultiline)>(*this, lib, "_builtin_InputTextMultiline",
        SideEffects::worstDefault, "das::InputTextMultiline");
    // imgui text buffer
    addExtern<DAS_BIND_FUN(das::ImGTB_Append)>(*this,lib,"append",
        SideEffects::worstDefault,"das::ImGTB_Append");
    addExtern<DAS_BIND_FUN(das::ImGTB_At)>(*this,lib,"at",          // TODO: do we need to learn to map operator []?
        SideEffects::worstDefault,"das::ImGTB_At");
    addExtern<DAS_BIND_FUN(das::ImGTB_SetAt)>(*this,lib,"set_at",   // TODO: do we need to learn to map operator []?
        SideEffects::worstDefault,"das::ImGTB_SetAt");
    addExtern<DAS_BIND_FUN(das::ImGTB_Slice)>(*this,lib,"slice",
        SideEffects::worstDefault,"das::ImGTB_Slice");
    // ImGuiInputTextCallbackData
    addExtern<DAS_BIND_FUN(das::InsertChars)>(*this,lib,"InsertChars",
        SideEffects::worstDefault,"das::InsertChars");
    // clipper
    addUsing<ImGuiListClipper>(*this,lib,"ImGuiListClipper");
    // SetNextWindowSizeConstraints
    addExtern<DAS_BIND_FUN(das::SetNextWindowSizeConstraints)>(*this,lib,"_builtin_SetNextWindowSizeConstraints",
        SideEffects::worstDefault,"das::SetNextWindowSizeConstraints");
    // ImGuiTableColumnSortSpecs
    addExtern<DAS_BIND_FUN(das::SortDirection)>(*this,lib,"SortDirection",
        SideEffects::none,"das::SortDirection");
    // CalcTextSize
    addExtern<DAS_BIND_FUN(das::CalcTextSize), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "CalcTextSize",SideEffects::worstDefault, "ImGui::CalcTextSize")
	->args({"text","hide_text_after_double_hash","wrap_width"})
		->arg_init(1,make_smart<ExprConstBool>(false))
		->arg_init(2,make_smart<ExprConstFloat>(-1.0f));
    // combo
    addExtern<DAS_BIND_FUN(das::Combo)>(*this, lib, "_builtin_Combo",
        SideEffects::worstDefault, "das::Combo");
    // plot lines and historgram
    addExtern<DAS_BIND_FUN(das::PlotLines)>(*this, lib, "_builtin_PlotLines",
        SideEffects::worstDefault, "das::PlotLines");
    addExtern<DAS_BIND_FUN(das::PlotHistogram)>(*this, lib, "_builtin_PlotHistogram",
        SideEffects::worstDefault, "das::PlotHistogram");
    // additional default values
    findUniqueFunction("AddRect")
        ->arg_init(5, make_smart<ExprConstEnumeration>("All",makeType<ImDrawCornerFlags_>(lib)));
    findUniqueFunction("AddRectFilled")
        ->arg_init(5, make_smart<ExprConstEnumeration>("All",makeType<ImDrawCornerFlags_>(lib)));
    findUniqueFunction("BeginTable")
        ->arg_init(3, make_smart<ExprCall>(LineInfo(), "ImVec2"));
    for ( auto & fn : functionsByName["Selectable"] ) {
        fn->arg_init(3, make_smart<ExprCall>(LineInfo(), "ImVec2"));
    }
    findUniqueFunction("SetNextWindowPos")
        ->arg_init(2, make_smart<ExprCall>(LineInfo(), "ImVec2"));
    findUniqueFunction("Button")
        ->arg_init(1, make_smart<ExprCall>(LineInfo(), "ImVec2"));
    for ( auto & fn : functionsByName["PlotHistogram"] ) {
        if ( fn->arguments.size()==9 ) {
            fn->arg_init(7, make_smart<ExprCall>(LineInfo(), "ImVec2"));
            fn->arg_init(8, make_smart<ExprConstInt>(int32_t(sizeof(float))));
        }
    }
    findUniqueFunction("TableSetupColumn")
        ->arg_init(3, make_smart<ExprConstUInt>(uint32_t(0)));
    findUniqueFunction("BeginListBox")
        ->arg_init(1, make_smart<ExprCall>(LineInfo(), "ImVec2"));

#endif
    return true;
}

ModuleAotType Module_imgui::aotRequire ( TextWriter & tw ) const  {
    // add your stuff here
    tw << "#include <imgui.h>\n";
    // specifying AOT type, in this case direct cpp mode (and not hybrid mode)
    return ModuleAotType::cpp;
}

// registering module, so that its available via 'NEED_MODULE' macro
REGISTER_MODULE(Module_imgui);
