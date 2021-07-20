#include<iostream>
#include<fstream>
#include<string.h>
#include<ctime>
#include<cctype>
#include<time.h>
#include<algorithm>
#include<thread>
using namespace std;
class fileFind //filefind class화
{
private :
	time_t time1;
	string ref;
	struct tm time2;
	int lineCount = 1;
public:
	fileFind()
	{
		time1 = time(NULL); //시간을 받기위해 time_t를 null로 셋팅
		localtime_s(&time2, &time1); //그 후 struct tm time2(헤더파일안에 존재) 안에 time1기준으로 local 시간으로 넣어준다.
	}
	void startTime()//시간 출력
	{
		cout << "C:\CriticSectTest.cpp" << endl;
		cout << "Open file time : " << time2.tm_year + 1900 << "년 " << time2.tm_mon + 1 << "일 " << time2.tm_mday << "일" << time2.tm_hour << "시 " << time2.tm_min << "분 " << time2.tm_sec << "초" << endl;
	}
	string getter(string ref) //솔직히 필요없는데 ref 변수가 private여서 사용하는 부분
	{
		return this->ref;
	}
	void setter(string line)//class 안의 ref값에 line으로 받아온 변수값을 넣어줌. 다형성구현
	{
		this->ref = line;//문자열처리
		transform((this->ref).begin(), (this->ref).end(), (this->ref).begin(), tolower);//ref안을 모두 영어 소문자로 변경,특수문자는 냅둠,문자열 처리
	}
	void setter(int num)//다형성 구현
	{
		(this->lineCount) += num;//몇번째 라인에 나오는지 확인하기위해 while문이 돌때마다 +1씩 set
	}
	void fileTime(clock_t begin, clock_t end) // 총 걸린시간 계산
	{
		double duration = (double)(end - begin) / CLOCKS_PER_SEC;
		cout << "Executed time: " << duration << "sec" << endl;
	}
	void locationPrint(char line[])//cs가 나온 부분 위치 프린트, ref를 출력하면 모두 소문자로 변경된 상태로 출력되므로 ref안에 있는지만 확인 후 .find 함수로 index번호만 받아와서 line배열에 그 index를 넣고 출력
	{
		cout << "CriticalSectTest.cpp: " << this->lineCount << "line" << "(" << line[this->ref.find("cs") - 1] << line[this->ref.find("cs")] << line[this->ref.find("cs") + 1] << ")" << endl;
	}

};
int main()
{
	try {//예외처리
		thread mythread2([]() {//스레드사용
			fileFind filefind2;
			clock_t begin, end;//시간
			begin = clock();
		thread mythread1([]() { //스레드사용
			char line[200];
			ifstream openFile("c://CriticSectTest.cpp");//파일처리
			fileFind filefind;
			filefind.startTime();
			while (!openFile.eof())//파일 end of file 까지 line을 계속 받아옴
			{
				openFile.getline(line, 200);// buffer 의 크기를 200으로 정한후 파일을 한줄 씩 불러와서 line 배열에 저장
				filefind.setter(line);//filefind 안의 line변수에 setting
				if (filefind.getter("ref").find("cs") != string::npos)//없으면 string::npos 리턴
				{
					filefind.locationPrint(line);//받아온 line에 cs가 있다고 판정되었으므로 locationPrint 함수
				}
				filefind.setter(1);//line ++;
			}
			openFile.close();//파일 닫음
		});
			mythread1.join();//시간을 재기위해 스레드1이 종료할때까지 기다림
			end = clock();//스레드1이 종료되었으니 종료시간 표시
			filefind2.fileTime(begin, end);//시간 계산
		});
		mythread2.join();//스레드2 종료될때까지 main함수 스레드 종료하지않고 기다림.
	}
	catch (exception e)//예외처리, try안의 모든 코드들에 대하여 예외 발생시 여기서 처리됨
	{
		cout << "오류 발생!" << endl;
	}
	return 0;

}