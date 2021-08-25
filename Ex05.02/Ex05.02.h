#ifndef EX05_02
#define EX05_02

/// @file Ex05.02.h

typedef struct complexNumber
{
	int real;
	int imaginary;
} complexNumber;

typedef union number_t
{
	double real;
	complexNumber complex;
} number_t;

typedef enum numberType
{
	Real,
	Complex
} numberType;

typedef struct number
{
	number_t number;
	numberType type;
} number;

/**
 * @brief Runs a Calculator. Asks for input and Prints the answer.
*/
void Calculator(void);

/**
 * @brief Asks user to input a number, real or complex
*/
number InputNumber(void);

/**
 * @brief Adds two numbers together
 * @param numA
 * @param numB 
 * @return 
*/
number Add(number numA, number numB);

/**
 * @brief Returns the difference between two numbers
 * @param numA 
 * @param numB 
 * @return 
*/
number Subtract(number numA, number numB);

/**
 * @brief Multiplies two numbers together
 * @param numA 
 * @param numB 
 * @return 
*/
number Multiply(number numA, number numB);

/**
 * @brief Returns the quotient of two numbers
 * @param numA 
 * @param numB 
 * @return 
*/
number Divide(number numA, number numB);

/**
 * @brief Prints a number to the console
 * @param num 
*/
void PrintNumber(number num);

#endif