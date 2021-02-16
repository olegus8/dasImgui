#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"

#include <imgui.h>

using namespace das;

#include "need_imgui.h"

#if USE_GENERATED

#include "module_imgui.h"

#endif

void Module_imgui::initFunctions() {
#if USE_GENERATED
#include "module_imgui.inc"
#endif
}
