
// Copyright (c) 2018 brinkqiang (brink.qiang@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __DMLIMIT_H_INCLUDE__
#define __DMLIMIT_H_INCLUDE__

#ifdef WIN32
class CDMLimitInit
{
public:
    CDMLimitInit()
    {}
    ~CDMLimitInit() 
    {}
};
#else

#include <sys/resource.h>

#include <stdio.h>
#include <stdlib.h>
class CDMLimitInit
{
public:
    CDMLimitInit()
    {
        const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
        struct rlimit rl;
        int result;

        result = getrlimit(RLIMIT_STACK, &rl);
        if (result == 0)
        {
            if (rl.rlim_cur < kStackSize)
            {
#ifdef _DEBUG
                fprintf(stdout, "getrlimit stacksize = %d\n", rl.rlim_cur);
#endif
                rl.rlim_cur = kStackSize;

                result = setrlimit(RLIMIT_STACK, &rl);
#ifdef _DEBUG
                fprintf(stdout, "setrlimit stacksize = %d\n", kStackSize);
#endif
                if (result != 0)
                {
                    fprintf(stderr, "setrlimit returned result = %d\n", result);
                }
            }
        }
    }

    ~CDMLimitInit()
    {
        
    }
};
#endif

static CDMLimitInit gDMLimitInit;

#endif // __DMLIMIT_H_INCLUDE__