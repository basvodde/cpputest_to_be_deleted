/*
 * Copyright (c) 2007, Michael Feathers, James Grenning and Bas Vodde
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE EARLIER MENTIONED AUTHORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "CppUTest/Extensions/SimpleStringFromStdint.h"
#include <stdio.h>

SimpleString StringFrom (uint64_t i)
{
//    char buffer [50];
//    sprintf(buffer, "%20lu (0x%016lx)", i, i);

//    return SimpleString(buffer);
    return "uint64_t not supported";
}

SimpleString StringFrom (int64_t i)
{
//    char buffer [50];
//    sprintf(buffer, "%20lu (0x%016lx)", i, i);

//    return SimpleString(buffer);
    return "int64_t not supported";
}


SimpleString StringFrom (uint32_t i)
{
    char buffer [10+1+1+2+8+1+1];
    sprintf(buffer, "%10u (0x%08x)", i, i);

    return SimpleString(buffer);
}

SimpleString StringFrom (uint16_t i)
{
    char buffer [5+1+1+2+4+1+1];
    sprintf(buffer, "%5u (0x%04x)", i, i);

    return SimpleString(buffer);
}

SimpleString StringFrom (uint8_t i)
{
    char buffer [3+1+1+2+2+1+1];
    sprintf(buffer, "%3u (0x%02x)", i, i);

    return SimpleString(buffer);
}

