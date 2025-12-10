# emcc .\main.cpp -o main.js -s WASM=1 -s EXPORTED_RUNTIME_METHODS='["cwrap"]' -s ALLOW_MEMORY_GROWTH=1 --no-entry
# write-host "Compiled to main.wasm and main.js" -ForegroundColor green

# TODO: List all exported functions instead of injecting manually
emcc .\main.cpp -o main.wasm -s STANDALONE_WASM=1 -s EXPORTED_FUNCTIONS='["_getSurfacePtr", "_init", "_update", "_draw"]' -s ALLOW_MEMORY_GROWTH=1 --no-entry
write-host "Compiled to main.wasm" -ForegroundColor green
