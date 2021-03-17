#include "daScript/daScript.h"

#include <imgui.h>
#include <GLFW/glfw3.h>

#include "..\imgui\backends\imgui_impl_opengl2.h"
#include "..\imgui\backends\imgui_impl_glfw.h"

using namespace das;

#define USE_GENERATED 1

#if USE_GENERATED

// NOTE: this module requires GLFW module
#include "../../dasGlfw/src/module_glfw_include.h"

MAKE_EXTERNAL_TYPE_FACTORY(ImDrawData,ImDrawData);

#endif

void glfw_error_callback(int error, const char* description) {
    printf("Glfw Error %d: %s\n", error, description);
}

// making custom builtin module
class Module_imgui_app : public Module {
    ModuleLibrary lib;
public:
    Module_imgui_app() : Module("imgui_app") {
    }
    bool initialized = false;
    virtual bool initDependencies() override {
        if ( initialized ) return true;
        // GLFW
        auto mod_glfw = Module::require("glfw");
        if ( !mod_glfw ) return false;
        if ( !mod_glfw->initDependencies() ) return false;
        // IMGUI
        auto mod_imgui = Module::require("imgui");
        if ( !mod_imgui ) return false;
        if ( !mod_imgui->initDependencies() ) return false;
        // time to initialize
        initialized = true;
        // error callback
        glfwSetErrorCallback(glfw_error_callback);
        // make basic module
        lib.addModule(this);
        lib.addBuiltInModule();
        lib.addModule(mod_glfw);
        lib.addModule(mod_imgui);
#if USE_GENERATED
        // GLFW
        addExtern<DAS_BIND_FUN(ImGui_ImplGlfw_InitForOpenGL)>(*this,lib,"ImGui_ImplGlfw_InitForOpenGL",
            SideEffects::worstDefault, "ImGui_ImplGlfw_InitForOpenGL");
        addExtern<DAS_BIND_FUN(ImGui_ImplGlfw_InitForVulkan)>(*this,lib,"ImGui_ImplGlfw_InitForVulkan",
            SideEffects::worstDefault, "ImGui_ImplGlfw_InitForVulkan");
        addExtern<DAS_BIND_FUN(ImGui_ImplGlfw_Shutdown)>(*this,lib,"ImGui_ImplGlfw_Shutdown",
            SideEffects::worstDefault, "ImGui_ImplGlfw_Shutdown");
        addExtern<DAS_BIND_FUN(ImGui_ImplGlfw_NewFrame)>(*this,lib,"ImGui_ImplGlfw_NewFrame",
            SideEffects::worstDefault, "ImGui_ImplGlfw_NewFrame");
        addExtern<DAS_BIND_FUN(ImGui_ImplGlfw_MouseButtonCallback)>(*this,lib,"ImGui_ImplGlfw_MouseButtonCallback",
            SideEffects::worstDefault, "ImGui_ImplGlfw_MouseButtonCallback");
        addExtern<DAS_BIND_FUN(ImGui_ImplGlfw_ScrollCallback)>(*this,lib,"ImGui_ImplGlfw_ScrollCallback",
            SideEffects::worstDefault, "ImGui_ImplGlfw_ScrollCallback");
        addExtern<DAS_BIND_FUN(ImGui_ImplGlfw_KeyCallback)>(*this,lib,"ImGui_ImplGlfw_KeyCallback",
            SideEffects::worstDefault, "ImGui_ImplGlfw_KeyCallback");
        addExtern<DAS_BIND_FUN(ImGui_ImplGlfw_CharCallback)>(*this,lib,"ImGui_ImplGlfw_CharCallback",
            SideEffects::worstDefault, "ImGui_ImplGlfw_CharCallback");
        // OpenGL2
        addExtern<DAS_BIND_FUN(ImGui_ImplOpenGL2_Init)>(*this,lib,"ImGui_ImplOpenGL2_Init",
            SideEffects::worstDefault, "ImGui_ImplOpenGL2_Init");
        addExtern<DAS_BIND_FUN(ImGui_ImplOpenGL2_Shutdown)>(*this,lib,"ImGui_ImplOpenGL2_Shutdown",
            SideEffects::worstDefault, "ImGui_ImplOpenGL2_Shutdown");
        addExtern<DAS_BIND_FUN(ImGui_ImplOpenGL2_NewFrame)>(*this,lib,"ImGui_ImplOpenGL2_NewFrame",
            SideEffects::worstDefault, "ImGui_ImplOpenGL2_NewFrame");
        addExtern<DAS_BIND_FUN(ImGui_ImplOpenGL2_RenderDrawData)>(*this,lib,"ImGui_ImplOpenGL2_RenderDrawData",
            SideEffects::worstDefault, "ImGui_ImplOpenGL2_RenderDrawData");
        addExtern<DAS_BIND_FUN(ImGui_ImplOpenGL2_CreateFontsTexture)>(*this,lib,"ImGui_ImplOpenGL2_CreateFontsTexture",
            SideEffects::worstDefault, "ImGui_ImplOpenGL2_CreateFontsTexture");
        addExtern<DAS_BIND_FUN(ImGui_ImplOpenGL2_DestroyFontsTexture)>(*this,lib,"ImGui_ImplOpenGL2_DestroyFontsTexture",
            SideEffects::worstDefault, "ImGui_ImplOpenGL2_DestroyFontsTexture");
        addExtern<DAS_BIND_FUN(ImGui_ImplOpenGL2_CreateDeviceObjects)>(*this,lib,"ImGui_ImplOpenGL2_CreateDeviceObjects",
            SideEffects::worstDefault, "ImGui_ImplOpenGL2_CreateDeviceObjects");
        addExtern<DAS_BIND_FUN(ImGui_ImplOpenGL2_DestroyDeviceObjects)>(*this,lib,"ImGui_ImplOpenGL2_DestroyDeviceObjects",
            SideEffects::worstDefault, "ImGui_ImplOpenGL2_DestroyDeviceObjects");
#endif
        // all good
        return true;
    }
    virtual ModuleAotType aotRequire ( TextWriter & tw ) const override {
        tw << "#include <imgui.h>\n";
        tw << "#include <backends/imgui_impl_glfw.h>\n";
        tw << "#include <backends/imgui_impl_opengl2.h>\n";
        return ModuleAotType::cpp;
    }
};

// registering module, so that its available via 'NEED_MODULE' macro
REGISTER_MODULE(Module_imgui_app);

