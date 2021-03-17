#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"

#include <imgui.h>
#include <imnodes.h>

using namespace das;

#include "need_imgui.h"

#if USE_GENERATED

#define GLOBAL_NAMESPACE    1

#include "module_imgui.h"

#endif


void Module_imgui::initMethods() {
#if USE_GENERATED
#include "module_imgui.method.inc"
#endif
}
