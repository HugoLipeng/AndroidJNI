#pragma once
#include <stdarg.h>

void my_sprintf(char *buffer, const char *fmt, ...) {
	//����va_list 
	va_list arg_list;
	va_start(arg_list, fmt);
	char* b = buffer;
	//
	int count = 0;
	// *fmt != '\0'
	while (*fmt)
	{
		if (*fmt != '%') {
			count++;
			// fmt D�ĵ�ַ
			*b++ = *fmt++;
			continue;
		}
		//��� % ����� d
		fmt++;
		switch (*fmt) {
		case  'd': {
			int i = va_arg(arg_list, int);
			int j = 0;
			char tmp[10];
			int sign = i < 0 ? 1 :0;
			do
			{
				//i = 888
				//ȡ�����һ������
				int r = i % 10;
				r = r < 0 ? -r : r;
				//ȥ�����һ������
				//��¼
				tmp[j++] = r + '0';
			} while (i /= 10);
			//tmp =  888  
			// i= -123 tmp = 321-
			if (sign) {
				tmp[j++] = '-';
			}
			while (j>0)
			{
				char a = tmp[--j];
				*b++ = a;
				count++;
			}
			
		}break;
		default:
			printf("xxxxxxx\n");
			break;
		}
		fmt++;
	}
	buffer[count] = '\0';
}


//char str[100];
//my_sprintf(str, "David ��ϲ�� %d �ż�ʦ. ÿ��Ҫ����%dԪ��ÿ������%d", 0, 888, -1000);