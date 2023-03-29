#include &quot;main.h&quot;
/****************** PRINT POINTER ******************/
/**
 * * print_pointer - Prints the value of a pointer variable
 * * @types: List a of arguments
 * * @buffer: Buffer array to handle print
 * * @flags: Calculates active flags
 * * @width: get width
 * * @precision: Precision specification
 * * @size: Size specifier
 * * Return: Number of chars printed.
 * */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = &#39; &#39;;
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for &#39;0x&#39; */
	unsigned long num_addrs;
	char map_to[] = &quot;0123456789abcdef&quot;;
	void *addrs = va_arg(types, void *);
	UNUSED(width);
	UNUSED(size);
	if (addrs == NULL)
		return (write(1, &quot;(nil)&quot;, 5));
	buffer[BUFF_SIZE - 1] = &#39;\0&#39;;
	UNUSED(precision);
	num_addrs = (unsigned long)addrs;
	while (num_addrs &gt; 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags &amp; F_ZERO) &amp;&amp; !(flags &amp; F_MINUS))

		padd = &#39;0&#39;;
	if (flags &amp; F_PLUS)
		extra_c = &#39;+&#39;, length++;
	else if (flags &amp; F_SPACE)
		extra_c = &#39; &#39;, length++;
	ind++;
	/*return (write(1, &amp;buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
				width, flags, padd, extra_c, padd_start));

}
/************************* PRINT NON PRINTABLE *************************/
/**
 * * print_non_printable - Prints ascii codes in hexa of non printable chars
 * * @types: Lista of arguments
 * * @buffer: Buffer array to handle print
 * * @flags: Calculates active flags
 * * @width: get width
 * * @precision: Precision specification
 * * @size: Size specifier
 * * Return: Number of chars printed
 * */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		return (write(1, &quot;(null)&quot;, 6));
	while (str[i] != &#39;\0&#39;)
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}
	buffer[i + offset] = &#39;\0&#39;;
	return (write(1, buffer, i + offset));
}
/************************* PRINT REVERSE *************************/
/**
 * * print_reverse - Prints reverse string.
 * * @types: Lista of arguments
 * * @buffer: Buffer array to handle print
 * * @flags: Calculates active flags
 * * @width: get width
 * * @precision: Precision specification
 * * @size: Size specifier
 * * Return: Numbers of chars printed
 * */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	str = va_arg(types, char *);
	if (str == NULL)
	{
		UNUSED(precision);
		str = &quot;)Null(&quot;;
			}
			for (i = 0; str[i]; i++)
			;
			for (i = i - 1; i &gt;= 0; i--)

			{
			char z = str[i];
			write(1, &amp;z, 1);
			count++;
			}
			return (count);
			}
			/************************* PRINT A STRING IN ROT13 *************************/
			/**
			 * * print_rot13string - Print a string in rot13.
			 * * @types: Lista of arguments
			 * * @buffer: Buffer array to handle print
			 * * @flags: Calculates active flags
			 * * @width: get width
			 * * @precision: Precision specification
			 * * @size: Size specifier
			 * * Return: Numbers of chars printed
			 * */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = &quot;ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz&quot;;
	char out[] = &quot;NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm&quot;;
	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		str = &quot;(AHYY)&quot;;
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{

				x = out[j];
				write(1, &amp;x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &amp;x, 1);
			count++;
		}
	}
	return (count);
}
