// Copyright 2018 The Cobalt Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "starboard/player.h"

#if SB_API_VERSION >= SB_MEDIA_ENHANCED_AUDIO_API_VERSION
void SbPlayerSeek(SbPlayer player, SbTime seek_to_timestamp, int ticket) {}
#else   // SB_API_VERSION >= SB_MEDIA_ENHANCED_AUDIO_API_VERSION
void SbPlayerSeek2(SbPlayer player, SbTime seek_to_timestamp, int ticket) {}
#endif  // SB_API_VERSION >= SB_MEDIA_ENHANCED_AUDIO_API_VERSION
