#

I made this project to compare the workflow & the Wasm binary output between Pascal and C++

I have another repository that is dedicated to Pascal with WebAssembly: [Posit-92 Wasm](https://github.com/Hevanafa/Posit-92_wasm)

## Building

Simply execute `compile.ps1` to build the WebAssembly binary

## Requirements

1. Emscripten (see the Setup section below to see how)
2. VSCode (or any text editor that supports editing C++ code)
3. Node.js to start the `http-server`
4. Optional: PowerShell 7 (VSCode already has this integrated)

I'm using a Windows 10 machine to compile & run this project

## Emscripten Setup

1. Install Emscripten

   ```powershell
   git clone https://github.com/emscripten-core/emsdk.git
   cd emsdk
   
   .\emsdk.ps1 install latest
   .\emsdk.ps1 activate latest
   
   .\emsdk_env.ps1
   ```

2. Test Emscripten

   ```powershell
   emcc --version
   ```

## Microsoft's C++ Extension Setup for VSCode

1. Install this one: [C/C++ by Microsoft](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
2. Add this in the `includePath`:

   ```powershell
   E:\emsdk\upstream\emscripten\cache\sysroot\include
   ```

   The path depends on where you installed `emsdk`
