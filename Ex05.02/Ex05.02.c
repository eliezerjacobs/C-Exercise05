#include "Ex05.02.h"
#include <stdio.h>

int main(void)
{
    Calculator();
}

void Calculator(void)
{
    number numA = InputNumber();
    number numB;

    char exit = 'f';
    while (exit == 'f')
    {
        printf_s("Enter operation to perform ('a' = Add. 's' = Subtract. 'm' = Multiply. 'd' = Divide. 'e' or anything else = Exit): ");
        char inputChar;
        scanf_s(" %c", &inputChar, 1);

        if (inputChar == 'a' || inputChar == 's' || inputChar == 'm' || inputChar == 'd')
        {
            numB = InputNumber();
        }

        switch (inputChar)
        {
        case 'a':
            numA = Add(numA, numB);
            PrintNumber(numA);
            break;

        case 's':
            numA = Subtract(numA, numB);
            PrintNumber(numA);
            break;

        case 'm':
            numA = Multiply(numA, numB);
            PrintNumber(numA);
            break;

        case 'd':
            numA = Divide(numA, numB);
            PrintNumber(numA);
            break;

        default:
            exit = 't';
        }
    }
}

number InputNumber(void)
{
    printf_s("Enter number type ('c' = Complex Number. 'r' or anything else = Real Number): ");
    char inputChar;
    scanf_s(" %c", &inputChar, 1);

    number num;
    switch (inputChar)
    {
    case 'c':
        num.type = Complex;
        printf_s("Enter real part of number: ");
        scanf_s("%i", &num.number.complex.real);
        printf_s("Enter imaginary part of number: ");
        scanf_s("%i", &num.number.complex.imaginary);
        break;

    default:
        num.type = Real;
        printf_s("Enter number: ");
        scanf_s("%lf", &num.number.real);
    }

    return num;
}

number Add(number numA, number numB)
{
    number result;

    if (numA.type == Complex)
    {
        result = numA;
        if (numB.type == Complex)   // both numbers are complex
        {
            result.number.complex.real += numB.number.complex.real;
            result.number.complex.imaginary += numB.number.complex.imaginary;
        }
        else    // only numA is complex
        {
            result.number.complex.real += numB.number.real;
        }
    }
    else
    {
        result = numB;
        if (numB.type == Complex)   // only numB is complex
        {
            result.number.complex.real += numA.number.real;
        }
        else  // both numbers are real
        {
            result.number.real += numA.number.real;
        }
    }

    return result;
}

number Subtract(number numA, number numB)
{
    number result;

    if (numA.type == Complex)
    {
        result = numA;
        if (numB.type == Complex)   // both numbers are complex
        {
            result.number.complex.real -= numB.number.complex.real;
            result.number.complex.imaginary -= numB.number.complex.imaginary;
        }
        else    // only numA is complex
        {
            result.number.complex.real -= numB.number.real;
        }
    }
    else
    {
        if (numB.type == Complex)   // only numB is complex
        {
            result.type = Complex;
            result.number.complex.real = numA.number.real - numB.number.complex.real;
            result.number.complex.imaginary = -numB.number.real;
        }
        else  // both numbers are real
        {
            result = numA;
            result.number.real -= numA.number.real;
        }
    }

    return result;
}

number Multiply(number numA, number numB)
{
    number result;

    if (numA.type == Complex)
    {
        result = numA;
        if (numB.type == Complex)   // both numbers are complex
        {
            result.number.complex.real *= numB.number.complex.real;
            result.number.complex.real -= numA.number.complex.imaginary * numB.number.complex.imaginary;
            result.number.complex.imaginary *= numB.number.complex.real;
            result.number.complex.imaginary += numA.number.complex.real * numB.number.complex.imaginary;
        }
        else    // only numA is complex
        {
            result.number.complex.real *= numB.number.real;
        }
    }
    else
    {
        result = numB;
        if (numB.type == Complex)   // only numB is complex
        {
            result.number.complex.real *= numA.number.real;
        }
        else  // both numbers are real
        {
            result.number.real *= numA.number.real;
        }
    }

    return result;
}

number Divide(number numA, number numB)
{
    number result;

    if (numB.type == Complex)
    {
        number conjugate = numB;
        conjugate.number.complex.imaginary *= -1;
        result = Multiply(numA, conjugate);
        numB = Multiply(numB, conjugate);

        result.number.complex.real /= numB.number.complex.real;
        result.number.complex.imaginary /= numB.number.complex.real;
    }
    else
    {
        result = numA;
        if (numA.type == Complex)   // only numB is complex
        {
            result.number.complex.real /= numB.number.real;
            result.number.complex.imaginary /= numB.number.real;
        }
        else  // both numbers are real
        {
            result.number.real /= numB.number.real;
        }
    }

    return result;
}

void PrintNumber(number num)
{
    if (num.type == Real)
    {
        printf_s("Answer: %lf\n", num.number.real);
    }
    else
    {
        printf_s("Answer: %d%s%di\n\n", num.number.complex.real, num.number.complex.imaginary < 0 ? "" : "+", num.number.complex.imaginary);
    }
}