# GTPS Server (Growtopia Private Server Emulation)

## Overview
This repository contains a C++ Growtopia private server (GTPS) implementation that emulates core Growtopia server behavior for local development and testing.

## Build prerequisites
- Windows 10/11
- Visual Studio 2019+ with the **Desktop development with C++** workload
- ENet library (already included in `enet/` and `include/` with `enet.lib`)
- WinSock (part of the Windows SDK)

## Build and run
1. Open `gtps3.sln` in Visual Studio.
2. Select the `x64` configuration.
3. Build the solution.
4. Run the produced server executable from Visual Studio or the build output directory.

## Configuration notes
- Default server port is defined in `Source.cpp` (search for the listen/bind call).
- World/data files are stored and loaded from the local working directory (see `World.h` and related load/save logic).
- Ensure required data files (e.g., item definitions) are present alongside the executable if your build expects them.

## Project layout
- `Source.cpp` — entry point and main server loop.
- `World.h` — world state and persistence logic.
- `Item.h` — item definitions and item-related helpers.
- `src/players/player.h` — player session structures.
- `src/packets/packet.h` — network packet helpers.
