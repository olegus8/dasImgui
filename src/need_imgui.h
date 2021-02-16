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


template <>
struct cast_arg<ImVec2> {
    static __forceinline ImVec2 to ( Context & ctx, SimNode * node ) {
        return * (ImVec2 *) node->evalPtr(ctx);
    }
};

MAKE_TYPE_FACTORY(ImGuiContext,ImGuiContext);
MAKE_TYPE_FACTORY(ImDrawListSharedData,ImDrawListSharedData);

/*
template <typename TT>
struct typeName<ImVector<TT>> {
    static string name() {
        return string("ImVector`") + typeName<TT>::name(); // TODO: compilation time concat
    }
};

// ImDrawListSharedData to void * TODO: make dummy type
template <>
struct typeFactory<const ImDrawListSharedData *> {
    static TypeDeclPtr make(const ModuleLibrary & library ) {
        return typeFactory<void *>::make(library);
    };
};

// ImFont
template <>
struct typeName<ImFont *> : das::typeName<void *> {
};

template <>
struct typeFactory<ImFont *> {
    static TypeDeclPtr make(const ModuleLibrary & library ) {
        return typeFactory<void *>::make(library);
    };
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
*/

