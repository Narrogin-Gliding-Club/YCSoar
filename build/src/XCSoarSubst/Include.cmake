set(XCSOAR_BIN_DIR ${XCSOAR_BIN}/${T})
add_library(xcsoarmain-subst-${T} ${XCSOARSUBST_SRC_DIR}/LogFile.cpp
                                  ${XCSOARSUBST_SRC_DIR}/Operation/VerboseOperationEnvironment.cpp
                                  ${XCSOARSUBST_SRC_DIR}/Screen/Canvas.cpp
                                  ${XCSOARSUBST_SRC_DIR}/Screen/Pen.cpp
                                  ${XCSOARSUBST_SRC_DIR}/Screen/Font.cpp
                                  ${XCSOARSUBST_SRC_DIR}/Screen/Brush.cpp
                                  ${XCSOARSUBST_SRC_DIR}/Screen/RenderObject.cpp
           )
target_link_libraries(xcsoarmain-subst-${T} Qt5::Widgets Qt5::Qml
                      -L${XCSOAR_BIN_DIR} XCSoar-static-${T}
                      pthread z)
include_directories(./
                    ${XCSOAR_SRC}
                    ${XCSOAR_SRC}/unix
                    ${XCSOAR_SRC}/Profile
                    ${XCSOAR_SRC}/Screen
                    ${XCSOAR_SRC}/Screen/Memory)

# Test harness
if(true)
set(TestRunner "${CMAKE_CURRENT_BINARY_DIR}/run-test.cpp")
add_custom_command(OUTPUT ${TestRunner}
                   COMMAND cxxtestgen -o ${TestRunner} --error-printer Suite.test.hpp
                   MAIN_DEPENDENCY ${XCSOARSUBST_SRC_DIR}/Screen/Suite.test.hpp
                   WORKING_DIRECTORY "${XCSOARSUBST_SRC_DIR}/Screen"
                  )
add_executable(run-test-${T} ${TestRunner})
target_link_libraries(run-test-${T} xcsoarmain-subst-${T} asan tsan lsan)
add_test(NAME xcsoarsubst-test COMMAND run-test-${T})
else(true)
add_custom_target(run-test-${T} COMMAND "/bin/true")
endif(true)

# Patch panel
add_custom_target(xcsoarsubst-${B}
                  DEPENDS xcsoarmain-subst-${T}
                          run-test-${T})
