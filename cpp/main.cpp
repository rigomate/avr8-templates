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


/* Be sure to use the -O3 optimization level to  become the most effective, and have the classes behave just like
 * the AVR bit fiddling
*/

#include <avr/io.h>

#include "port.hpp"
#include "pin.hpp"

/* Create a typedef c+11 style for a pin for later usage, do this in your config file */
using TestPin = Pin<PortB, 1>;

/* Behold, this is actually living in flash and taking up precious Flash space */
TestPin globaltestpin;

int main()
{	

	/* Showcase for the different modes compared against the usual ugly AVR style */
	
	/* Showcase for setting pin */
	{
		PORTB |= (1 << 1);

		TestPin testpin{};
		testpin.setpin();
		TestPin{}.setpin();
		TestPin::setpin();
		globaltestpin.setpin();
	}
	
	/* Showcase for setting toggling */
	{
		PORTB ^= (1 << 1);

		TestPin testpin{};
		testpin.togglepin();
		TestPin{}.togglepin();
		TestPin::togglepin();
		globaltestpin.togglepin();
	}
	
	/* Showcase for reading a pin, reading volatile will make this not get optimized away */
	{
		PINB & (1<< 1);

		TestPin testpin{};
		testpin.readpin();
		TestPin{}.readpin();
		TestPin::readpin();
		globaltestpin.readpin();
	}
	
	/* Showcase for setting output direction */
	{
		DDRB |= (1 << 1);
		
		TestPin testpin{};
		testpin.setasoutput();
		TestPin{}.setasoutput();
		TestPin::setasoutput();
		globaltestpin.setasoutput();
	}
	
	while(1)
	{
	
		
	}
	return 0;
}