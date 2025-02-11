# CMakeList.txt: проект CMake для Matrix_Multiply; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Matrix_Multiply "Matrix_Multiply.cpp" "Matrix_Multiply.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Matrix_Multiply PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
