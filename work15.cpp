#include<iostream>
#include<fstream>
#include<string.h>
#include<ctime>
#include<cctype>
#include<time.h>
#include<algorithm>
#include<thread>
using namespace std;
class fileFind //filefind classȭ
{
private :
	time_t time1;
	string ref;
	struct tm time2;
	int lineCount = 1;
public:
	fileFind()
	{
		time1 = time(NULL); //�ð��� �ޱ����� time_t�� null�� ����
		localtime_s(&time2, &time1); //�� �� struct tm time2(������Ͼȿ� ����) �ȿ� time1�������� local �ð����� �־��ش�.
	}
	void startTime()//�ð� ���
	{
		cout << "C:\CriticSectTest.cpp" << endl;
		cout << "Open file time : " << time2.tm_year + 1900 << "�� " << time2.tm_mon + 1 << "�� " << time2.tm_mday << "��" << time2.tm_hour << "�� " << time2.tm_min << "�� " << time2.tm_sec << "��" << endl;
	}
	string getter(string ref) //������ �ʿ���µ� ref ������ private���� ����ϴ� �κ�
	{
		return this->ref;
	}
	void setter(string line)//class ���� ref���� line���� �޾ƿ� �������� �־���. ����������
	{
		this->ref = line;//���ڿ�ó��
		transform((this->ref).begin(), (this->ref).end(), (this->ref).begin(), tolower);//ref���� ��� ���� �ҹ��ڷ� ����,Ư�����ڴ� ����,���ڿ� ó��
	}
	void setter(int num)//������ ����
	{
		(this->lineCount) += num;//���° ���ο� �������� Ȯ���ϱ����� while���� �������� +1�� set
	}
	void fileTime(clock_t begin, clock_t end) // �� �ɸ��ð� ���
	{
		double duration = (double)(end - begin) / CLOCKS_PER_SEC;
		cout << "Executed time: " << duration << "sec" << endl;
	}
	void locationPrint(char line[])//cs�� ���� �κ� ��ġ ����Ʈ, ref�� ����ϸ� ��� �ҹ��ڷ� ����� ���·� ��µǹǷ� ref�ȿ� �ִ����� Ȯ�� �� .find �Լ��� index��ȣ�� �޾ƿͼ� line�迭�� �� index�� �ְ� ���
	{
		cout << "CriticalSectTest.cpp: " << this->lineCount << "line" << "(" << line[this->ref.find("cs") - 1] << line[this->ref.find("cs")] << line[this->ref.find("cs") + 1] << ")" << endl;
	}

};
int main()
{
	try {//����ó��
		thread mythread2([]() {//��������
			fileFind filefind2;
			clock_t begin, end;//�ð�
			begin = clock();
		thread mythread1([]() { //��������
			char line[200];
			ifstream openFile("c://CriticSectTest.cpp");//����ó��
			fileFind filefind;
			filefind.startTime();
			while (!openFile.eof())//���� end of file ���� line�� ��� �޾ƿ�
			{
				openFile.getline(line, 200);// buffer �� ũ�⸦ 200���� ������ ������ ���� �� �ҷ��ͼ� line �迭�� ����
				filefind.setter(line);//filefind ���� line������ setting
				if (filefind.getter("ref").find("cs") != string::npos)//������ string::npos ����
				{
					filefind.locationPrint(line);//�޾ƿ� line�� cs�� �ִٰ� �����Ǿ����Ƿ� locationPrint �Լ�
				}
				filefind.setter(1);//line ++;
			}
			openFile.close();//���� ����
		});
			mythread1.join();//�ð��� ������� ������1�� �����Ҷ����� ��ٸ�
			end = clock();//������1�� ����Ǿ����� ����ð� ǥ��
			filefind2.fileTime(begin, end);//�ð� ���
		});
		mythread2.join();//������2 ����ɶ����� main�Լ� ������ ���������ʰ� ��ٸ�.
	}
	catch (exception e)//����ó��, try���� ��� �ڵ�鿡 ���Ͽ� ���� �߻��� ���⼭ ó����
	{
		cout << "���� �߻�!" << endl;
	}
	return 0;

}