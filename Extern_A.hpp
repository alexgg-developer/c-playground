#pragma once
#ifndef _EXTERN_A_HPP_
#define _EXTERN_A_HPP_

#include <string>
#include <iostream>

static void printGA()
{
	extern int g_a;
	std::cout << "g_a::" << g_a << std::endl;
}

#endif