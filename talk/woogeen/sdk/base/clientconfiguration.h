/*
 * Copyright © 2015 Intel Corporation. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WOOGEEN_BASE_CLIENTCONFIGURATION_H_
#define WOOGEEN_BASE_CLIENTCONFIGURATION_H_

#include <vector>
#include <string>
#include "mediacodec.h"

#if defined(WEBRTC_WIN)
#include <windows.h>
#endif

namespace woogeen {

// Define ICE server
struct IceServer {
  // URLs for this group of ICE server
  std::vector<std::string> urls;
  // Username
  std::string username;
  // Password
  std::string password;
};

// Client configurations
struct ClientConfiguration {
  // List of ICE servers
  std::vector<IceServer> ice_servers;
  // Media codec preference
  MediaCodec media_codec;
#if defined(WEBRTC_WIN)
  bool hardware_acceleration_;
  HWND decoder_win_;
#endif
};
}

#endif  // WOOGEEN_BASE_CLIENTCONFIGURATION_H_