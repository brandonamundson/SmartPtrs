/***************************************************************************/
/**
* @file
* @brief Learning about Smart Pointers
*
* @mainpage Smart Pointers: Crash Course
*
* @section course_section Course Information
*
* @authors Brandon Amundson
*
* @date March 21, 2021
*
* @par Instructor:
*         Professor Tony Hinton
*
* @par Course:
*         CSC 275 06:30 pm
*
* @par Location:
*         UAT Campus - Room 108
*
* @section program_section Program Information
*
* @details
* Smart Pointer introduction program
*
*
* @section compile_section Compiling and Usage
*
* @par Compiling Instructions:
*      None
*
* @par Usage:
  @verbatim
  Just run the program, no input needed
  @endverbatim
*
* @section todo_bugs_modification_section Todo, Bugs, and Modifications
*
* @bug
*
* @todo
*
*
* @par Modifications and Development Timeline:
  @verbatim
  Date          Modification
  --------------  -------------------------------------------------------------
  March 21, 2021  Wrote program
  @endverbatim
*
******************************************************************************/
#include <iostream> //used for standard i/o streams
#include <string>   //used for string manipulations
#include <memory>   //used to create smart pointers
#include <iomanip>  //used to manipulate i/o streams

// function templates
void uniquePtrs();
void sharedPtrs();
void weakPtrs();
char selectAgain();
void setPauseOutput();

/***************************************************************************/
/**
* @author Brandon Amundson
*
* @par Description:
* Function calls all other functions to welcome the user and set up the rest
* of the program.
* 
* @returns 0 - no errors
******************************************************************************/
int main()
{
	//output intro with bright green font, purple background.
	//set txt to default when done
	//special note: \033 is escape code, [ begins command, ; separates args
	//& m ends the command.
	std::cout <<
		"\033[1;32;40m\t\t*****Today we will learn about special pointers" <<
		" aka Smart Pointers!*****\n\n\033[0m";
	setPauseOutput();

	uniquePtrs();
	setPauseOutput();

	sharedPtrs();
	setPauseOutput();

	weakPtrs();
	setPauseOutput();

	//ask user if they wish to review any information before quitting.
	//continually ask until they wish to quit.
	char again = selectAgain();
	while (again != 'Q')
	{
		switch (again)
		{
		case 'U':
			uniquePtrs();
			break;
		case 'S':
			sharedPtrs();
			break;
		case 'W':
			weakPtrs();
			break;
		default:
			std::cout <<
				"Thank you for joining us!  Have fun with Smart Pointers!";
			break;
		}
		setPauseOutput();
		again = selectAgain();
	}

	return 0;
}

/***************************************************************************/
/**
* @author Brandon Amundson
*
* @par Description:
* Outputs details about Unique (Smart) Pointers
******************************************************************************/
void uniquePtrs()
{
	//sets console to output cyan txt with purple bg for this screen
	std::cout << "\033[1;36;45m";
	//clears the screen for a fresh UI
	system("cls");

	std::cout <<
		"\t\t\t\t\t***WELCOME TO UNIQUE POINTERS!***\n";

	//creates a unique string pointer called demo1
	std::unique_ptr<std::string> demo1 = std::make_unique<std::string>();

	//sets cout formatting to left justified
	std::cout.setf(std::ios::left);

	//output knowledge of unique ptrs
	std::cout <<
		"\n\tA unique pointer is one that can only hold one value and cannot be used by any other pointers.";
	std::cout <<
		" Unique pointers only exist within one scope/function and cannot be passed to another scope/function.\n";
	std::cout <<
		"Unique pointers are created with \"std::unique_ptr<dataType> name = std::make_unique<dataType>();\"\n";

	std::cout << "\n\nPlease enter a string for the unique pointer demo. ";
	std::cin >> *demo1;

	std::cout << "\nDemo pointer currently holds the following string: " << *
		demo1;
	std::cout << " at location: " << demo1;

	//create 2nd demo ptr
	std::unique_ptr<std::string> demo2 = std::make_unique<std::string>();

	//would try this to show an example, but doesn't compile!
	std::cout <<
		"\n\n\tAttempting to make another unique pointer and assigning a value with \"=\" results in: ";

	std::cout << "\"2nd demo pointer could not be assigned\".";

	std::cout <<
		"  The only way to assign 2nd demo pointer to 1st demo pointers value and address is ";
	std::cout <<
		"With \"2ndPtr = std::move(1stPtr);\", which then invalidates the first ptr.";

	//demonstrate std::move function on unique ptrs
	demo2 = std::move(demo1);
	std::cout << "\n\n\n1st demo ptr after move function is set to nullptr.\n";
	std::cout << "2nd demo ptr after move function = " << *demo2 <<
		", location = " << demo2;
	std::cout << "\n\n";
}

/***************************************************************************/
/**
* @author Brandon Amundson
*
* @par Description:
* Outputs details about Shared (Smart) Pointers
******************************************************************************/
void sharedPtrs()
{
	//sets console to output blue txt with white/gray bg for this screen
	std::cout << "\033[34;47m";

	//clears the screen for a fresh UI
	system("cls");

	//outputs section title in uppercase format
	std::cout <<
		"\t\t\t\t\t***WELCOME TO SHARED POINTERS!***\n";

	//output knowledge of shared ptrs
	std::cout <<
		"\n\tA shared pointer is one that can hold a value and can be passed into other "
		<< "functions, copied or used by other pointers.";
	std::cout <<
		" Shared pointers exist as long as there are references to it, once all references are removed, reset, "
		<< "or go out of scope, the pointer is deleted.\n\n";
	std::cout <<
		"\tShared pointers are created very similar to unique pointers but " <<
		" with \"std::shared_ptr<dataType> name = std::make_shared<dataType>();\"\n\n";
}

/***************************************************************************/
/**
* @author Brandon Amundson
*
* @par Description:
* Outputs details about Weak (Smart) Pointers
******************************************************************************/
void weakPtrs()
{
	//sets console to output red txt with yellow/brown bg for this screen
	std::cout << "\033[31;43m";

	//clears the screen for a fresh UI
	system("cls");

	//outputs section title in uppercase format
	std::cout <<
		"\t\t\t\t\t***WELCOME TO WEAK POINTERS!***\n";

	//output knowledge of weak ptrs
	std::cout <<
		"\n\tA weak pointer is one that can hold shared pointer and does not change "
		<< "the reference counter.  It also helps to avoid cyclic references of pointers.";
	std::cout <<
		" If a weak pointer can no longer access the memory of the shared pointer it "
		<< "was assigned, it will return a boolean value of false.\n\n";
	std::cout <<
		"\tWeak pointers are created very similarly to unique and shared pointers but "
		<<
		" with \"std::weak_ptr<dataType> name = someSharedPointer\"\n\n";
}

/***************************************************************************/
/**
* @author Brandon Amundson
*
* @par Description:
* Outputs asking the user which pointer they would like to read about again
* 
* @returns choice - can only return Q, S, U, or W for Quit, Shared, Unique, or
*					Weak
******************************************************************************/
char selectAgain()
{
	//initialize variable to avoid compiler issues & ensure loop runs
	//at least once
	char choice = 'a';

	//sets console to output black txt with cyan bg for this screen
	std::cout << "\033[30;46m";

	//clears the screen for a fresh UI
	system("cls");
	while (choice != 'Q' && choice != 'S' && choice != 'U' && choice != 'W')
	{
		std::cout << "Which pointers do you want to learn about again?";
		std::cout << "\n(U)nique\t(S)hared\t(W)eak\t(Q)uit\n";
		std::cin >> choice;

		//convert choice to uppercase letter to minimize error checking
		choice = std::toupper(choice);
		if (choice != 'Q' && choice != 'S' && choice != 'U' && choice != 'W')
			std::cout << "Please try again.";
	}
	return choice;
}

/***************************************************************************/
/**
* @author Brandon Amundson
*
* @par Description:
* Sets text formatting to a red, underlined font for the system(pause) command
* before resetting to default.  Used in between function calls
******************************************************************************/
void setPauseOutput()
{
	//underline & make txt red for system("pause") cmd
	std::cout << "\033[4;31m";
	//wait for user input before proceeding
	system("pause");
	//reset to defaults again
	std::cout << "\033[0m";
}
