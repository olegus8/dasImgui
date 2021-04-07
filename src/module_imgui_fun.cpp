#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"

#include "imgui_stub.h"
#include "imnodes_stub.h"

using namespace das;

#include "need_imgui.h"

#if USE_GENERATED

#define GLOBAL_NAMESPACE    1

#include "module_imgui.h"

#endif

void Module_imgui::initFunctions() {
#if USE_GENERATED
#if !USE_GENERATED_SPLIT
#include "module_imgui.inc"
#endif
#endif
}
