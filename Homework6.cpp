/*
 Tri Dang
 11/20/17
 Compiler used: VS2015 Community
 Homework6.cpp : This is a Magic 8 Ball, inputting a user's question and
 outputting a random answer. Everything is coded in C++, except the random
 number generator, which is coded with inline assembly.
*/


#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <string>

using namespace std;

#pragma comment(lib, "Winmm.lib")
#pragma warning(disable: 4996)

using namespace std::this_thread;
using namespace std::chrono;


int main()
{
	short randVal;
	string input;
	int num;
	time_t timer;
	char test[133];
	//creating a 2 dimensional array to store answer strings
	char *array[] = { 
		"C:\\Public\\Public Documents\\Hwk4\\AnythingIsPossible.wav", 
		"C:\\Public\\Public Documents\\Hwk4\\Definitely.wav", 
		"C:\\Public\\Public Documents\\Hwk4\\DefinitelyNot.wav", 
		"C:\\Public\\Public Documents\\Hwk4\\IThinkItIsLikeLy.wav", 
		"C:\\Public\\Public Documents\\Hwk4\\IThinkNot.wav",
		"C:\\Public\\Public Documents\\Hwk4\\IThinkThatTimeWillTell.wav", 
		"C:\\Public\\Public Documents\\Hwk4\\ItIsNotCertain.wav", 
		"C:\\Public\\Public Documents\\Hwk4\\ItIsTooSoonToTell.wav", 
		"C:\\Public\\Public Documents\\Hwk4\\MaybeNot.wav", 
		"C:\\Public\\Public Documents\\Hwk4\\WithoutADoubt.wav", 
		"C:\\Public\\Public Documents\\Hwk4\\YouMustBeJoking.wav" };

	num = time(&timer);

	cout << "What is your question? ";
	getline(cin, input);

	__asm {
	//; put asm code here
		mov eax, num
		mov edx, 0					//clears edx
		mov ebx, 11
		div ebx						//divides eax by 11 and get the remainder, or mod eax by 11
		movzx randVal, edx 
	}
	
	strcpy(test, array[randVal]);
	cout << test << "\n";
	PlaySounda(test, NULL, SND_FILENAME);
	return 0;
}

