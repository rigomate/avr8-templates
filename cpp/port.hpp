/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 by Mate Zoltan, Rigo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#pragma once 

/* Some Magic has to be done, so templates can be used for creating ports
 * These basically remove the volatile pointer and dereference qualifier from the addresses 
 * Thus enabling the addresses to be added into constexpr expressions such as template arguments
 * At the end of the file, these modifications are remade
*/
#undef _MMIO_BYTE
#define _MMIO_BYTE(mem_addr) (uint8_t)(mem_addr)
#undef _MMIO_WORD
#define _MMIO_WORD(mem_addr) (uint16_t)(mem_addr)
#undef _MMIO_DWORD
#define _MMIO_DWORD(mem_addr) (uint32_t)(mem_addr)
#include <avr/io.h>





using PortType = volatile uint8_t *;


/* Using the ports templatized will make them as effective as if you would use your regular AVR bit toggling, uggh*/
template <uint8_t portx, uint8_t pin>
class Port{
public:
	void static setpin()
	{
		*reinterpret_cast<PortType>(portx) |= (1 << pin);
	}
	
	void static clearpin()
	{
		*reinterpret_cast<PortType>(portx) |= (1 << pin);
	}
	
	void static togglepin()
	{
		*reinterpret_cast<PortType>(portx) |= (1 << pin);
	}
	
	auto static readpin()
	{
		return (*reinterpret_cast<PortType>(pinx) & (1 << pin));
	}
	
	void static setasinput()
	{
		*reinterpret_cast<PortType>(ddrx) &= ~(1 << pin);
	}
	
	void static setasoutput()
	{
		*reinterpret_cast<PortType>(ddrx) |= (1 << pin);
	}
private:
constexpr static uint8_t pinx{portx-2};
constexpr static uint8_t ddrx{portx-1};
};

/* Create your pin definitions here 
 * Remember, that PORTA, PORTB and etc here are only normal uint8_t, and hence can be used as template arguments
*/
using Mosfet = Port<PORTB, 1>;





/* The following magic makes sure that the modified macros get turned back, and everything is back to normal in
 * the other parts of the code
 * This is the cost you have to pay to use templates with the AVR headers.
*/
#undef _MMIO_BYTE
#undef _MMIO_WORD
#undef _MMIO_DWORD
#undef _AVR_SFR_DEFS_H_

#include <avr/sfr_defs.h>
#include <avr/io.h>