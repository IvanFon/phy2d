# Find cpplint
# Variables:
# CPPLINT_FOUND - If cpplint was found
# CPPLINT_BIN - cpplint location

# find cpplint
find_program(CPPLINT_BIN NAMES cpplint)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(
  CPPLINT
  DEFAULT_MSG
  CPPLINT_BIN
)

mark_as_advanced(CPPLINT_BIN)
