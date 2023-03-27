#include <main.h>
/**
 * _printf - this funtion will return the output accord format
 * @*format - this is the pointer function that will be used
 *
 * Return: Number of outputed characters excluding null bytes to
 * the output in string
 */
int _prinf(const char *format, ...)
{
	va_list head;
	int i = 0;

	va_start(head, format);
	while (format[i] != '\0',i++)
	{
		if (format[i] != '%')
		{
		switch (format[i])
		{
			case 'c':
				{
					_putchar( " %c\n : ", format[i]);
					break;
				}
			case 's':
				{
					_putchar( "%s\n : ", format[i]);
					break;
				}
			case '%':
				{
					_putchar( "%%", format[i]);
					break;
				}
			default:
				//unsuported conversion speciefied
			break;
	}
		}
		else
		{
			_putchar("%c", format[i]);
		}
	va_end(head);
	return (i);
}
