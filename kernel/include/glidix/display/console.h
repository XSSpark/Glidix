/*
	Glidix kernel

	Copyright (c) 2014-2017, Madd Games.
	All rights reserved.
	
	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
	
	* Redistributions of source code must retain the above copyright notice, this
	  list of conditions and the following disclaimer.
	
	* Redistributions in binary form must reproduce the above copyright notice,
	  this list of conditions and the following disclaimer in the documentation
	  and/or other materials provided with the distribution.
	
	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
	FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
	OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __glidix_console_h
#define __glidix_console_h

#include <glidix/util/common.h>
#include <stdarg.h>
#include <stddef.h>

void initConsole();
void kvprintf(const char *fmt, va_list ap);
FORMAT(printf, 1, 2) void kprintf(const char *fmt, ...);
void kputbuf(const char *buf, size_t size);
void kputbuf_debug(const char *buf, size_t size);
void kdumpregs(Regs *regs);
FORMAT(printf, 1, 2) void kprintf_debug(const char *fmt, ...);
void unlockConsole();
void clearScreen();
void setConsoleColor(uint8_t col);
void setCursorPos(uint8_t x, uint8_t y);
void setGfxTerm(int value);
void enableDebugTerm();
void disableConsole();
void enableConsole();
void getConsoleSize(unsigned short *width, unsigned short *height);

#define	DONE()						kprintf("Done\n")
#define	FAILED()					kprintf("Failed\n")

#define	PRINTFLAG(cond, c)	if (cond) {kprintf("%c", c);} else {kprintf("%c", c-'A'+'a');}

#endif