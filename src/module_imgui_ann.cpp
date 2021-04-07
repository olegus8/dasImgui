#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"

#include "imgui_stub.h"
#include "imnodes_stub.h"

using namespace das;

#include "need_imgui.h"

#if USE_GENERATED

#define GLOBAL_NAMESPACE    1

#include "module_imgui.h"

#include "module_imgui.ann.cpp_inc"

#endif


void Module_imgui::initAnnotations() {
#if USE_GENERATED
#include "module_imgui.ann.inc"
#endif
}
