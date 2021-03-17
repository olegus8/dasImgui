#include "daScript/daScript.h"
#include "daScript/simulate/fs_file_info.h"

using namespace das;

TextPrinter tout;

bool pauseAfterErrors = false;

void compile_and_run ( const string & fn, const string & mainFnName, bool outputProgramCode ) {
    auto access = make_smart<FsFileAccess>();
    ModuleGroup dummyGroup;
    if ( auto program = compileDaScript(fn,access,tout,dummyGroup) ) {
        if ( program->failed() ) {
            for ( auto & err : program->errors ) {
                tout << reportError(err.at, err.what, err.extra, err.fixme, err.cerr );
            }
            if ( pauseAfterErrors ) {
                getchar();
            }
        } else {
            if ( outputProgramCode )
                tout << *program << "\n";
            Context ctx(program->getContextStackSize());
            program->simulate(ctx, tout);
            AotLibrary aotLib;
            AotListBase::registerAot(aotLib);
            program->linkCppAot(ctx, aotLib, tout);
            if ( program->failed() ) {
                tout << "failed to link AOT\n";
                for ( auto & err : program->errors ) {
                    tout << reportError(err.at, err.what, err.extra, err.fixme, err.cerr );
                }
            }
            if ( auto fnTest = ctx.findFunction(mainFnName.c_str()) ) {
                ctx.restart();
                ctx.eval(fnTest, nullptr);
            } else {
                tout << "function '"  << mainFnName << " ' not found\n";
            }
        }
    }
}

int main(int argc, char * argv[]) {
    setCommandLineArguments(argc,argv);
    // register modules
    NEED_MODULE(Module_BuiltIn);
    NEED_MODULE(Module_Math);
    NEED_MODULE(Module_Strings);
    NEED_MODULE(Module_Random);
    NEED_MODULE(Module_Rtti);
    NEED_MODULE(Module_Ast);
    NEED_MODULE(Module_Debugger);
    NEED_MODULE(Module_Network);
    NEED_MODULE(Module_UriParser);
    NEED_MODULE(Module_JobQue);
    NEED_MODULE(Module_FIO);
    #include "modules/external_need.inc"
    Module::Initialize();
    // compile and run
    string demoName = getDasRoot() + "/modules/dasImgui/example/imgui_opengl2.das";
    compile_and_run(demoName, "main", false);
    // and done
    getchar();
    Module::Shutdown();
    return 0;
}


