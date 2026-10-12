/**
 * @file        src/heap.h
 *
 * @brief       Native heap interface for guest virtual memory.
 *
 * @copyright   Copyright (c) 2026 Tom Clay <tomc@tctechstuff.com>
 *              All rights reserved.
 *
 * @license     BSD 3-Clause License
 *              Full license text: rexglue-sdk/LICENSE.
 */

#pragma once

#include <cstdint>

namespace lh {

// Initialize the native dlmalloc heap over guest virtual memory.
// Must be called after rex::Runtime::Setup() and before game module launch.
bool InitNativeHeap();

// Register hooks in the function dispatcher.
// Must be called after rex::Runtime::LoadXexImage() and before LaunchModule().
void RegisterHooks();

}  // namespace lh
