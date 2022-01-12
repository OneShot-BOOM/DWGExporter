///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002, Industrial Light & Magic, a division of Lucas
// Digital Ltd. LLC
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// *       Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// *       Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// *       Neither the name of Industrial Light & Magic nor the names of
// its contributors may be used to endorse or promote products derived
// from this software without specific prior written permission. 
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////


#ifndef INCLUDED_IMF_ZIP_H
#define INCLUDED_IMF_ZIP_H

#include "ImfNamespace.h"

#if defined(__sun)
#include <stddef.h>
#else
#include <cstddef>
#endif

OPENEXR_IMF_INTERNAL_NAMESPACE_HEADER_ENTER

class Zip
{
    public:
        explicit Zip(size_t rawMaxSize);
        Zip(size_t maxScanlineSize, size_t numScanLines);
        ~Zip();

        size_t maxRawSize();
        size_t maxCompressedSize();

        //
        // Compress the raw data into the provided buffer.
        // Returns the amount of compressed data.
        //
        int compress(const char *raw, int rawSize, char *compressed);

        // 
        // Uncompress the compressed data into the provided
        // buffer. Returns the amount of raw data actually decoded.
        //
        int uncompress(const char *compressed, int compressedSize,
                                                 char *raw);

    private:
        size_t _maxRawSize;
        char  *_tmpBuffer;

        Zip();
        Zip(const Zip&);
};

OPENEXR_IMF_INTERNAL_NAMESPACE_HEADER_EXIT

#endif
