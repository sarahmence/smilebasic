/*
 * VariantTypeException.cpp
 * Implements an exception thrown when a value of the wrong type
 * is requested from a Variant
 * Created on 3/19/2020
 * Created by Andrew Davis
 *
 * Copyright (C) 2020  Andrew Davis
 *
 * This program is free software: you can redistribute it and/or modify   
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//includes
#include "VariantTypeException.h"
#include <sstream>

//constructor
VariantTypeException::VariantTypeException(const std::string& expected,
						const std::string& actual)
	: errMsg() //init the error message
{
	//assemble the error message
	std::stringstream ss;
	ss << "Wrong variant type requested (expected ";
	ss << expected;
	ss << ", found ";
	ss << actual;
	ss << ")";
	this->errMsg = ss.str();
}

//destructor
VariantTypeException::~VariantTypeException() {
	//no code needed	
}

//copy constructor
VariantTypeException::VariantTypeException(const VariantTypeException& vte)
	: errMsg(vte.errMsg) //copy the error message
{
	//no code needed 
}

//assignment operator
VariantTypeException& VariantTypeException::operator=(const VariantTypeException& src) {
	std::exception::operator=(src); //assign the superclass
	this->errMsg = src.errMsg; //assign the error message
	return *this; //and return the instance
}

//overridden what() method - called when the exception is thrown
const char* VariantTypeException::what() const throw() {
	return this->errMsg.c_str(); //return the error message 
}

//end of implementation
