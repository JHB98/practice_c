#include<stdio.h>
int main()
{
	char buf1 = ' ', buf2 = ' ';
	char ch = ' ';
	printf("string 을 입력하세요(!입력시 종료) : ");
	while (1)
	{
		buf1 = buf2;
		buf2 = ch;
		ch = getchar();
		if (ch == '!')
		{
			break;
		}

		if (ch == '-')
		{
			buf1 = buf2;
			buf2 = ch;
			ch = getchar();
			if ((buf1 == '-') || (buf1 == ' '))
			{
				putchar(buf2);
				putchar(ch);
			}

			else
			{
				if ((ch == '-') || (ch == ' '))
				{
					putchar(buf2);
					putchar(ch);
				}
				else
				{
					if (buf1 > ch)
					{
						putchar(buf2);
						putchar(ch);
					}
					else
					{
						for (int i = buf1 + 1;i <= ch;i++)
						{
							printf("%c", i);
						}
					}
				}
			}
		}

		else if (buf2 + 1 == ch)
		{
			while (buf2 + 1 == ch)
			{
				buf1 = buf2;
				buf2 = ch;
				ch = getchar();
			}
			putchar('-');
			putchar(buf2);
		}
		else
		{
			putchar(ch);
		}
	}

	return 0;
}