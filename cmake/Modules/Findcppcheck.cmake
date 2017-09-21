# Tries to find cppcheck
# Variables:
# CPPCHECK_FOUND - If cppcheck was found
# CPPCHECK_BIN - cppcheck location

# find cppcheck
find_program (CPPCHECK_BIN NAMES cppcheck)

include (FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS (
  CPPCHECK
  DEFAULT_MSG
  CPPCHECK_BIN
)

# mark as advanced option in cmake GUI's
mark_as_advanced (
  CPPCHECK_BIN
)

# check if cppcheck wasn't found
if (NOT CPPCHECK_FOUND)
  # if it was required, give an error
  if (cppcheck_FIND_REQUIRED)
    message (FATAL_ERROR "cppcheck REQUIRED but not found")
  endif ()
else ()
  message (STATUS "cppcheck found in ${CPPCHECK_BIN}")
endif ()
