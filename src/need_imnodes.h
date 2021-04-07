
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

MAKE_TYPE_FACTORY(EditorContext,imnodes::EditorContext);
MAKE_TYPE_FACTORY(ImNodesContext,imnodes::Context);
