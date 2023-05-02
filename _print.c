#include "main.h"
#include <stdio.h>

/*print decimal binary*/

/**
 * print_bnr - prints decimal in binary.
 * @arguments: input string.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer.
 * Return: number of chars printed.
 */

int print_bnr(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, count, i, first_one, isnegative;
	char *binary;

	int_input = va_arg(arguments, int);
	isnegative = 0;

	if (int_input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}

	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}

	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 32);
	first_one = 0;

	for (count = i = 0; binary[i]; i++)
	{
		if (first_one == 0 && binary[i] == '1')
			first_one = 1;
		if (first_one == 1)
		{
			ibuf = handl_buf(buf, binary[i], ibuf);
			count++;
		}
	}

	free(binary);
	return (count);
}

/*write character c to stdout*/

/**
 * print_chr - writes the character c to stdout.
 * @arguments: input char.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer.
 * Return: On success 1.
 */

int print_chr(va_list arguments, char *buf, unsigned int ibuf)
{
	char c;

	c = va_arg(arguments, int);
	handl_buf(buf, c, ibuf);

	return (1);
}

/*prints decimal hexadecimal*/

/**
 * print_hex - prints a decimal in hexadecimal.
 * @arguments: input string.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer.
 * Return: number of chars printed.
 */

int print_hex(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, i, isnegative, count, first_digit;
	char *hexadecimal, *binary;

	int_input = va_arg(arguments, int);
	isnegative = 0;
	
	if (int_input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}
	
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 32);
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 8);
	
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handl_buf(buf, hexadecimal[i], ibuf);
			count++;
		}
	}
	
	free(binary);
	free(hexadecimal);
	return (count);
}

/*print an integer*/

/**
 * print_int - prints an integer.
 * @arguments: input string.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer.
 * Return: number of chars printed.
 */

int print_int(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input;
	unsigned int int_in, int_temp, i, div, isneg;

	int_input = va_arg(arguments, int);
	isneg = 0;
	
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = handl_buf(buf, '-', ibuf);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}

	int_temp = int_in;
	div = 1;

	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	
	return (i + isneg);
}

/*print decimal octal*/

/**
 * print_oct - prints decimal number in octal
 * @arguments: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */

int print_oct(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, i, isnegative, count, first_digit;
	char *octal, *binary;

	int_input = va_arg(arguments, int);
	isnegative = 0;

	if (int_input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}

	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}

	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = fill_oct_array(binary, octal);

	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handl_buf(buf, octal[i], ibuf);
			count++;
		}
	}

	free(binary);
	free(octal);
	return (count);
}

/*print character c to stdout*/

/**
 * print_prg - writes the character c to stdout.
 * @a: input char.
 * @buf: buffer pointer.
 * @i: index for buffer pointer.
 * Return: On success 1.
 */

int print_prg(va_list a __attribute__((unused)), char *buf, unsigned int i)
{
	handl_buf(buf, '%', i);

	return (1);
}

/*print the str in reverse*/

/**
 * print_rev - writes the str in reverse.
 * @arguments: input string.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer.
 * Return: number of chars printed.
 */

int print_rev(va_list arguments, char *buf, unsigned int ibuf)
{
	char *str;
	unsigned int i;
	int j = 0;
	char nill[] = "(llun)";

	str = va_arg(arguments, char *);

	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handl_buf(buf, nill[i], ibuf);
		return (6);
	}

	for (i = 0; str[i]; i++)
		;

	j = i - 1;

	for (; j >= 0; j--)
	{
		ibuf = handl_buf(buf, str[j], ibuf);
	}

	return (i);
}

/*the str in ROT13*/

/**
 * print_rot - writes the str in ROT13.
 * @arguments: input string.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer.
 * Return: number of chars printed.
 */

int print_rot(va_list arguments, char *buf, unsigned int ibuf)
{
	char alf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int i, j, k;
	char nill[] = "(avyy)";
	
	str = va_arg(arguments, char *);
	
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handl_buf(buf, nill[i], ibuf);
		return (6);
	}
	
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; alf[j]; j++)
		{
			if (str[i] == alf[j])
			{
				k = 1;
				ibuf = handl_buf(buf, rot[j], ibuf);
				break;
			}
		}
		if (k == 0)
			ibuf = handl_buf(buf, str[i], ibuf);
	}
	
	return (i);
}

/*print the string to stdout*/

/**
 * print_str - writes the string to stdout.
 * @arguments: input string.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer.
 * Return: On success 1.
 */

int print_str(va_list arguments, char *buf, unsigned int ibuf)
{
	char *str;
	unsigned int i;
	char nill[] = "(null)";

	str = va_arg(arguments, char *);
	
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handl_buf(buf, nill[i], ibuf);
		return (6);
	}
	
	for (i = 0; str[i]; i++)
		ibuf = handl_buf(buf, str[i], ibuf);

	return (i);
}

/*prints unsigned int*/

/**
 * print_unt - prints an unsigned int.
 * @arguments: number to print.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer.
 * Return: number of chars printed.
 */

int print_unt(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned int int_in, int_temp, i, div;

	int_in = va_arg(arguments, unsigned int);
	int_temp = int_in;
	div = 1;
	
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	
	return (i);
}

/*print decimal hexadecimal*/

/**
 * print_upx - prints a decimal in hexadecimal.
 * @arguments: The character to print.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer.
 * Return: number of chars printed.
 */

int print_upx(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, i, isnegative, count, first_digit;
	char *hexadecimal, *binary;

	int_input = va_arg(arguments, int);
	isnegative = 0;
	
	if (int_input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}
	
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 32);
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 1, 8);
	
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handl_buf(buf, hexadecimal[i], ibuf);
			count++;
		}
	}
	
	free(binary);
	free(hexadecimal);
	return (count);
}

/*prints string of non-printed chars*/

/**
 * print_usr - prints a string and values of
 * non-printed chars.
 * @arguments: input string.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer.
 * Return: number of chars printed.
 */

int print_usr(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned char *str;
	char *hexadecimal, *binary;
	unsigned int i, sum, op;

	str = va_arg(arguments, unsigned char *);
	binary = malloc(sizeof(char) * (32 + 1));
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			ibuf = handl_buf(buf, '\\', ibuf);
			ibuf = handl_buf(buf, 'x', ibuf);
			op = str[i];
			binary = fill_binary_array(binary, op, 0, 32);
			hexadecimal = fill_hex_array(binary, hexadecimal, 1, 8);
			ibuf = handl_buf(buf, hexadecimal[6], ibuf);
			ibuf = handl_buf(buf, hexadecimal[7], ibuf);
			sum += 3;
		}
		else
			ibuf = handl_buf(buf, str[i], ibuf);
	}
	
	free(binary);
	free(hexadecimal);
	return (i + sum);
}

/*print buffer*/

/**
 * print_buf - prints buffer.
 * @buf: buffer pointer.
 * @nbuf: number of bytes to print.
 * Return: number of bytes printed.
 */

int print_buf(char *buf, unsigned int nbuf)
{
	return (write(1, buf, nbuf));
}

/*print address of input variable*/

/**
 * print_add - prints the address of an input variable.
 * @arguments: input address.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer.
 * Return: number of chars printed.
 */

int print_add(va_list arguments, char *buf, unsigned int ibuf)
{
	void *add;
	long int int_input;
	int i, count, first_digit, isnegative;
	char *hexadecimal, *binary;
	char nill[] = "(nil)";

	add = (va_arg(arguments, void *));

	if (add == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handl_buf(buf, nill[i], ibuf);
		return (5);
	}

	int_input = (intptr_t)add;
	isnegative = 0;

	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}

	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 16);
	ibuf = handl_buf(buf, '0', ibuf);
	ibuf = handl_buf(buf, 'x', ibuf);

	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handl_buf(buf, hexadecimal[i], ibuf);
			count++;
		}
	}

	free(binary);
	free(hexadecimal);
	return (count + 2);
}
