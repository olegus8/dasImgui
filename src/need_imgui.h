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

class Module_imnodes : public Module {
    ModuleLibrary lib;
public:
    Module_imnodes();
    bool initialized = false;
    virtual bool initDependencies() override;
    virtual ModuleAotType aotRequire ( TextWriter & tw ) const override;
protected:
    void initEnums();
    void initAnnotations();
    void initFunctions();
    void initMethods();
};

MAKE_TYPE_FACTORY(ImGuiContext,ImGuiContext);
MAKE_TYPE_FACTORY(ImDrawListSharedData,ImDrawListSharedData);
MAKE_TYPE_FACTORY(ImFontBuilderIO,ImFontBuilderIO);
MAKE_TYPE_FACTORY(EditorContext,imnodes::EditorContext);

namespace das {

template <> struct typeFactory<ImColor> {
	static TypeDeclPtr make(const ModuleLibrary &) {
		auto t = make_smart<TypeDecl>(Type::tFloat4);
		t->alias = "ImColor";
		t->aotAlias = true;
		return t;
	}
};
template <> struct typeName<ImColor> { constexpr static const char * name() { return "ImColor"; } };
template <>
struct cast_arg<const ImColor &> {
    static __forceinline ImColor to ( Context & ctx, SimNode * node ) {
        vec4f res = node->eval(ctx);
        ImColor col; memcpy(&col,&res,sizeof(ImColor));
        return col;
    }
};

template <> struct typeFactory<ImVec2> {
	static TypeDeclPtr make(const ModuleLibrary &) {
		auto t = make_smart<TypeDecl>(Type::tFloat2);
		t->alias = "ImVec2";
		t->aotAlias = true;
		return t;
	}
};
template <> struct typeName<ImVec2> { constexpr static const char * name() { return "ImVec2"; } };
template <> struct cast_arg<const ImVec2 &> {
    static __forceinline ImVec2 to ( Context & ctx, SimNode * node ) {
        vec4f res = node->eval(ctx);
        ImVec2 v2; memcpy(&v2,&res,sizeof(ImVec2));
        return v2;
    }
};

template <> struct typeFactory<ImVec4> {
	static TypeDeclPtr make(const ModuleLibrary &) {
		auto t = make_smart<TypeDecl>(Type::tFloat4);
		t->alias = "ImVec4";
		t->aotAlias = true;
		return t;
	}
};
template <> struct typeName<ImVec4> { constexpr static const char * name() { return "ImVec4"; } };
template <> struct cast_arg<const ImVec4 &> {
    static __forceinline ImVec4 to ( Context & ctx, SimNode * node ) {
        vec4f res = node->eval(ctx);
        ImVec4 v4; memcpy(&v4,&res,sizeof(ImVec4));
        return v4;
    }
};

template<> struct das::cast <ImVec2>  : cast_fVec_half<ImVec2> {};
template<> struct das::cast <ImVec4>  : cast_fVec<ImVec4> {};
template<> struct das::cast <ImColor> : cast_fVec<ImColor> {};

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
