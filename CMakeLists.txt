IF(NOT DAS_IMGUI_INCLUDED)
    SET(DAS_IMGUI_INCLUDED TRUE)
    MESSAGE(STATUS "dasImGui module included.")

	SET(DAS_IMGUI_DIR ${CMAKE_SOURCE_DIR}/modules/dasImGui)

    LIST(APPEND CMAKE_MODULE_PATH ${DAS_IMGUI_DIR})

    FIND_PACKAGE(glfw3)
    FIND_PACKAGE(Vulkan)

	# we are actually going to build it
	SET(imgui_INCLUDE_DIR ${DAS_IMGUI_DIR}/imgui-1.81)
	SET(DAS_IMGUI_SRC
		${imgui_INCLUDE_DIR}/imconfig.h
		${imgui_INCLUDE_DIR}/imgui.cpp
		${imgui_INCLUDE_DIR}/imgui.h
		${imgui_INCLUDE_DIR}/imgui_demo.cpp
		${imgui_INCLUDE_DIR}/imgui_draw.cpp
		${imgui_INCLUDE_DIR}/imgui_internal.h
		${imgui_INCLUDE_DIR}/imgui_tables.cpp
		${imgui_INCLUDE_DIR}/imgui_widgets.cpp
		${imgui_INCLUDE_DIR}/imstb_rectpack.h
		${imgui_INCLUDE_DIR}/imstb_textedit.h
		${imgui_INCLUDE_DIR}/imstb_truetype.h
	)

	# libDasModuleImGui
	SET(DAS_IMGUI_MODULE_SRC
		${DAS_IMGUI_DIR}/src/need_imgui.h
		${DAS_IMGUI_DIR}/src/module_imgui.cpp
		${DAS_IMGUI_DIR}/src/module_imgui_enums.cpp
		${DAS_IMGUI_DIR}/src/module_imgui_ann.cpp
		${DAS_IMGUI_DIR}/src/module_imgui_fun.cpp
		${DAS_IMGUI_DIR}/src/module_imgui_method.cpp
		${DAS_IMGUI_DIR}/src/module_imgui.h
		${DAS_IMGUI_DIR}/src/module_imgui.inc
		${DAS_IMGUI_DIR}/src/module_imgui.method.inc
		${DAS_IMGUI_DIR}/src/module_imgui.enum.inc
		${DAS_IMGUI_DIR}/src/module_imgui.enum.cpp_inc
	)
	ADD_MODULE_LIB(libDasModuleImGui)
	ADD_MODULE_CPP(imgui)
	ADD_MODULE_NATIVE(imgui_boost)
	ADD_LIBRARY(libDasModuleImGui ${DAS_IMGUI_MODULE_SRC} ${DAS_IMGUI_SRC})
	#TARGET_LINK_LIBRARIES(libDasModuleImGui ${imgui_LIBRARIES})
	ADD_DEPENDENCIES(libDasModuleImGui libDaScript)
	TARGET_INCLUDE_DIRECTORIES(libDasModuleImGui PUBLIC ${imgui_INCLUDE_DIR})
	SETUP_CPP11(libDasModuleImGui)
	# GENERATED IMGUI
	get_target_property(BIND_INCLUDE_DIRS libDasModuleImGui INCLUDE_DIRECTORIES)
	FIND_FILE(IMGUI_H "imgui.h" ${imgui_INCLUDE_DIR})

	CPP_BIND_AST(
		IMGUI_GENERATE
		generate_imgui.das
		${DAS_IMGUI_DIR}/src/imgui_headers.h
		${DAS_IMGUI_DIR}/src/module_imgui
		${DAS_IMGUI_DIR}/src
		${BIND_INCLUDE_DIRS}
		${IMGUI_H}
	)
	IF(NOT glfw3_FOUND)
		MESSAGE(STATUS "GLFW3 not found. Not building dasImGuiGLFW.")
	ELSE()
		# libDasModuleImGuiApp
		SET(DAS_IMGUI_APP_MODULE_SRC
			${DAS_IMGUI_DIR}/src/module_imgui_app.cpp
			${imgui_INCLUDE_DIR}/backends/imgui_impl_glfw.cpp
			${imgui_INCLUDE_DIR}/backends/imgui_impl_glfw.h
			${imgui_INCLUDE_DIR}/backends/imgui_impl_opengl2.cpp
			${imgui_INCLUDE_DIR}/backends/imgui_impl_opengl2.h
			${DAS_IMGUI_DIR}/example/imgui_demo.das
			${DAS_IMGUI_DIR}/example/imgui_opengl2.das
		)
		ADD_MODULE_LIB(libDasModuleImGuiApp)
		ADD_MODULE_CPP(imgui_app)
		ADD_LIBRARY(libDasModuleImGuiApp ${DAS_IMGUI_APP_MODULE_SRC})
		TARGET_LINK_LIBRARIES(libDasModuleImGuiApp ${glfw_LIBRARIES})
		ADD_DEPENDENCIES(libDasModuleImGuiApp libDaScript libDasModuleImGui)
		TARGET_INCLUDE_DIRECTORIES(libDasModuleImGuiApp PUBLIC
			${imgui_INCLUDE_DIR}
			${glfw_INCLUDE_DIR}
		)
		SETUP_CPP11(libDasModuleImGuiApp)
		IF(NOT Vulkan_FOUND)
			MESSAGE(STATUS "Vulkan not found. Not building dasImguiVulkan.")
		ELSE()
			# libDasModuleImGuiVulkan
			SET(DAS_IMGUI_VULKAN_MODULE_SRC
				${DAS_IMGUI_DIR}/src/module_imgui_vulkan.cpp
				${imgui_INCLUDE_DIR}/backends/imgui_impl_vulkan.cpp
				${imgui_INCLUDE_DIR}/backends/imgui_impl_vulkan.h
				${DAS_IMGUI_DIR}/example/imgui_demo.das
				${DAS_IMGUI_DIR}/example/imgui_vulkan.das
			)
			ADD_MODULE_LIB(libDasModuleImGuiVulkan)
			ADD_MODULE_CPP(imgui_vulkan)
			ADD_LIBRARY(libDasModuleImGuiVulkan ${DAS_IMGUI_VULKAN_MODULE_SRC})
			TARGET_LINK_LIBRARIES(libDasModuleImGuiVulkan ${glfw_LIBRARIES})
			ADD_DEPENDENCIES(libDasModuleImGuiVulkan libDaScript libDasModuleImGui)
			TARGET_INCLUDE_DIRECTORIES(libDasModuleImGuiVulkan PUBLIC
				${imgui_INCLUDE_DIR}
				${glfw_INCLUDE_DIR}
				${Vulkan_INCLUDE_DIR})
			SETUP_CPP11(libDasModuleImGuiVulkan)

			# GENERATED IMGUI VULKAN
			CPP_BIND_AST(
				IMGUI_GENERATE_VULKAN
				generate_vulkan.das
				${imgui_INCLUDE_DIR}/backends/imgui_impl_vulkan.h
				${DAS_IMGUI_DIR}/src/module_imgui_vulkan
				${DAS_IMGUI_DIR}/src
				"${Vulkan_INCLUDE_DIR};${imgui_INCLUDE_DIR}"
				""
			)
		ENDIF()
	ENDIF()
ENDIF()
