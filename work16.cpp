#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996);
int main()
{
	char word[100] = "\0";
	FILE *fp;
	fp = fopen("12345678.txt", "a+");//12345678 �� �й����� �ٲٽð� �������ּ���!
	
	while (1)
	{
		scanf("%s", word);//���ڿ��� �Է¹޾� word�� ����
		if (!strcmp(word ,"$"))//�� ���ڿ��� ������ 0
		{
			break;
		}
		fputs(word, fp); //���������� fp�� ���� ���������Ϳ� �ۼ�
		fputs("\n", fp);//fputs�� ���๮�ڰ� �ڵ����� �߰� �ȵǹǷ� ���๮�� �߰�
	}

	fseek(fp, 0, SEEK_SET);//������ ó������ �б����� ���������͸� ������ �������� �̵�

	while (1)
	{
		fgets(word, sizeof(word), fp);//���پ� �о��
		if (feof(fp))//�о�°� EOF ���� Ȯ��
		{
			break;
		}
		printf("%s", word);//EOF �� �ƴϸ� ���
	}
	printf("Bye\n");
	fclose(fp);
	return 0;

}