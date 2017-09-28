# Target for cpplint
#
# Variables:
# CPPLINT_SOURCES - sources to check
# CPPLINT_ARGS - arguments to pass to cpplint

if(NOT CPPLINT_FOUND)
  message(FATAL_ERROR "Error: cpplint not found.")
endif()

set(CPPLINT_ARGS "")

add_custom_target(
  cpplint
  COMMAND ${CPPLINT_BIN}
  ${CPPLINT_ARGS}
  ${CPPLINT_SOURCES}
)
