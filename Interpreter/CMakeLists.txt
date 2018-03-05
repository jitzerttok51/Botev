project(Interpreter C)

set(CMAKE_C_STANDARD 99)

add_executable(Interpreter main.c src.c src.h token_stream.c token_stream.h)