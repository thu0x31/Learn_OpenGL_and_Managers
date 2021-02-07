CMake, make, clang, c++20, emscripten

make compile_commands.json
```
cd build
compiledb make
compdb -p ./ list > compile_commands_with_headers.json 2>/dev/null
rm compile_commands.json 
mv compile_commands_with_headers.json compile_commands.json
```