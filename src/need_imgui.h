#pragma once

#define USE_GENERATED   1

class Module_imgui : public Module {
    ModuleLibrary lib;
public:
    Module_imgui();
    bool initialized = false;
    virtual bool initDependencies() override;
    virtual ModuleAotType aotRequire ( TextWriter & tw ) const override;
protected:
    void initEnums();
    void initAnnotations();
    void initFunctions();
    void initMethods();
};

namespace das {
    template <>
    struct cast_arg<ImVec2> {
        static __forceinline ImVec2 to ( Context & ctx, SimNode * node ) {
            return * (ImVec2 *) node->evalPtr(ctx);
        }
    };
}

MAKE_TYPE_FACTORY(ImGuiContext,ImGuiContext);
MAKE_TYPE_FACTORY(ImDrawListSharedData,ImDrawListSharedData);
MAKE_TYPE_FACTORY(ImFontBuilderIO,ImFontBuilderIO);

namespace das {

template <>
struct typeName<char> {
    static string name() {
        return string("char");
    }
};

template <>
struct cast <char> {
    static __forceinline char to ( vec4f x )             { return char(v_extract_xi(v_cast_vec4i(x))); }
    static __forceinline vec4f from ( char x )           { return v_cast_vec4f(v_splatsi(x)); }
};

template <typename TT>
struct typeName<TT *> {
    static string name() {
        return string("ptr`") + typeName<TT>::name();
    }
};

template <typename TT>
struct typeName<ImVector<TT>> {
    static string name() {
        return string("ImVector`") + typeName<TT>::name();
    }
};

template <typename TT>
struct typeFactory<ImVector<TT>> {
    using VT = ImVector<TT>;
    static TypeDeclPtr make(const ModuleLibrary & library ) {
        string declN = typeName<VT>::name();
        if ( library.findAnnotation(declN,nullptr).size()==0 ) {
            auto declT = makeType<TT>(library);
            auto ann = make_smart<ManagedVectorAnnotation<VT>>(declN,const_cast<ModuleLibrary &>(library));
            ann->cppName = "ImVector<" + describeCppType(declT) + ">";
            auto mod = library.front();
            mod->addAnnotation(ann);
            //registerVectorFunctions<TT>::init(mod,library,
                //declT->canCopy(),
                //declT->canMove()
            //);
        }
        return makeHandleType(library,declN.c_str());
    }
};

}
