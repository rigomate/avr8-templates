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

#include <stdint.h>
#include "port.hpp"

/* A Pin template which is used to declare the actual pin configuation, such as:
 * using LedPin = Pin<PortB, 1>;
*/

template <class TPort, uint8_t pin>
class Pin
{
public:
	void static setpin(){
		TPort{}.setpin(pin);
	}
	void static clearpin()
	{
		TPort{}.clearpin(pin);
	}
	
	void static togglepin()
	{
		TPort{}.togglepin(pin);
	}
	
	auto static readpin()
	{
		TPort{}.readpin(pin);
	}
	
	void static setasinput()
	{
		TPort{}.setasinput(pin);
	}
	
	void static setasoutput()
	{
		TPort{}.setasoutput(pin);
	}
private:
};