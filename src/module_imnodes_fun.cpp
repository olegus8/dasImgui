#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"

#include "imgui_stub.h"
#include "imnodes_stub.h"

using namespace das;

#include "need_imgui.h"
#include "need_imnodes.h"

#if USE_GENERATED

#define IMNODES_NAMESPACE    1

#include "module_imgui.h"

#endif

void Module_imnodes::initFunctions() {
#if USE_GENERATED
#include "module_imgui.inc"
#endif
}
