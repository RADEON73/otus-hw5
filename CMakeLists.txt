cmake_minimum_required(VERSION 3.29)

project(vectorEditor VERSION 1.0.0)

add_executable(main 
main.cpp
Model.cpp Model.h
View.cpp View.h
Controller.cpp Controller.h
IDocument.h
Document.cpp Document.h
GrObject.h
GrCircle.h
GrLine.h
GrRectangle.h
)

set_target_properties(main PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(main PRIVATE /W4)
else ()
    target_compile_options(main PRIVATE -Wall -Wextra -pedantic) 
endif()

# install(TARGETS main RUNTIME DESTINATION bin)

# set(CPACK_GENERATOR DEB)
# set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
# set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
# set(CPACK_PACKAGE_CONTACT example@example.com)
# include(CPack)




