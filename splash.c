// 수학과 2017115475 문경덕
#include <stdio.h>
#include <ncurses.h>  // cureses 함수들 사용
#include <locale.h>  // setlocale, LC_ALL
#include <unistd.h>  // sleep, usleep, fork
#include <signal.h>  // signal 함수들 사용
#include <stdlib.h>  // exit
#include <sys/wait.h>  // wait

// 기본 display
void drawing();
void menu();  // menu 선택 화면
void background();  // 만들게 된 배경
void study();
void credit();

// chap 2
void chap2();
void chap2_concept();
void chap2_goal();
void chap2_command();

// chap 3
void chap3();
void chap3_goal();
void chap3_concept();
void chap3_command();

// chap 4
void chap4();
void chap4_concept();
void chap4_goal();
void chap4_command();

// chap 5
void chap5();
void chap5_concept();
void chap5_goal();
void chap5_command();

// chap 6
void chap6();
void chap6_concept();
void chap6_goal();
void chap6_command();

int main()
{
	setlocale(LC_ALL, "ko_KR.utf8");  // curses 함수에서 한글과 특수문자를 출력하기 위해 utf8 설정으로 바꾸어줌

	// SIGINT 를 SIG_IGN 하여 프로그램 중간에 Ctrl + C 로 종료되지 않도록 설정
	signal(SIGINT, SIG_IGN);

	initscr();
	clear();

	move(0, 0);
	addstr("학습 도우미를 사용하는 동안에는 Ctrl + C가 무시됩니다.");
	refresh();

	void inform(int);  // SIGALRM 핸들러
	signal(SIGALRM, inform);
	alarm(2);
	pause();	

	endwin();

	int pid;

	pid = fork();

	if(pid == -1)
	{
		fprintf(stderr, "프로세스 분기에 실패하였습니다.");
		exit(1);
	}
	else if(pid == 0)
	{
		drawing();
	}
	else
	{
		// 메뉴 선택 화면
		wait(NULL);
		menu();	
	}

	return 0;	
}

void drawing()
{
	initscr();
        clear();

        for(int time = 0 ; time < 7;time++)
        {
                if(time % 2 == 1)
                        standout();

                // H
                for(int i = 20;i<40;i++)
                {
                        move(i, 19);
                        addstr("■");
                        move(i, 20);
                        addstr("■");
                        move(i, 41);
                        addstr("■");
                        move(i, 40);
                        addstr("■");
                }
                for(int i=22;i<39;i++)
                {
                        move(29, i);
                        addstr("■");
                        move(30, i);
                        addstr("■");
                }

                // E
                for(int i=20;i<40;i++)
                {
                        move(i, 59);
                        addstr("■");
                        move(i, 60);
                        addstr("■");
                }

                for(int i=61;i<79;i++)
                {
                        move(20, i);
                        addstr("■");
                        move(21, i);
                        addstr("■");
                        move(29, i);
                        addstr("■");
                        move(30, i);
                        addstr("■");
                        move(38, i);
                        addstr("■");
                        move(39, i);
                        addstr("■");
                }
		
		// L
                for(int i=20;i<40;i++)
                {
                        move(i, 94);
                        addstr("■");
                        move(i, 95);
                        addstr("■");
                }

                for(int i=96;i<115;i++)
                {
                        move(38, i);
                        addstr("■");
                        move(39, i);
                        addstr("■");
                }

                // L
                for(int i = 20;i<40;i++)
                {
                        move(i, 130);
                        addstr("■");
                        move(i, 131);
                        addstr("■");
                }

                for(int i = 132;i<150;i++)
                {
                        move(38, i);
                        addstr("■");
                        move(39, i);
                        addstr("■");
                }

                // O
                for(int i = 20;i<40;i++)
                {
                        move(i, 165);
                        addstr("■");
                        move(i, 166);
                        addstr("■");
                        move(i, 182);
                        addstr("■");
                        move(i, 183);
                        addstr("■");
                }

                for(int i = 167;i<182;i++)
                {
                        move(20, i);
                        addstr("■");
                        move(21, i);
                        addstr("■");
                        move(38, i);
                        addstr("■");
                        move(39, i);
                        addstr("■");
                }

                move(LINES-1, COLS-1);

                if(time % 2 == 1)
                        standend();

                refresh();
                usleep(1000 * 300);
        }
	
	move(50, 90);
        addstr("Made by 문 경 덕");
        move(LINES - 1, COLS - 1);
        refresh();
        usleep(1000 * 300);

        move(53, 90);
        addstr("Enter to start");
        move(LINES - 1, COLS - 1);
        refresh();
	
	char c;
	getnstr(&c, 1);	
		
        endwin();
}

void inform(int signum)
{
	move(2,0);
	addstr("3...");
	refresh();
	sleep(1);

	move(3,0);
	addstr("2...");
	refresh();
	sleep(1);

	move(4,0);
	addstr("1...");	
	refresh();
	sleep(1);

	move(5,0);
	addstr("0...");
	refresh();
	sleep(1);
}

void menu()
{
	char menu;

	initscr();
	
	while(1)
	{
		clear();	
		refresh();

		move(0, 0);
		addstr("실행하고 싶은 항목의 번호를 입력해주세요");
		usleep(1000 * 100);
		refresh();

		move(2, 0);
		addstr("1. 만들게 된 배경");
		usleep(1000 * 700);
		refresh();
	
		move(4, 0);	
		addstr("2. 학습하러 가기");	
		usleep(1000 * 700);
		refresh();
		
		move(6, 0);
		addstr("3. 크레딧");	
		usleep(1000 * 700);
		refresh();
		
		move(8, 0);
		addstr("0. 종료");	
		usleep(1000 * 700);
		refresh();

		move(10, 0);
		addstr("번호를 입력해주세요 : ");
		refresh();
		
		getnstr(&menu, 1);  // ncurses 내부의 문자열을 입력받는 함수	
	
		switch(menu)
		{
			case '1':
				clear();
				endwin();
				background();
				break;
	
			case '2':
				clear();
				endwin();	
				study();
				break;

			case '3':
				clear();
				endwin();
				credit();
				break;

			case '0':
				endwin();
				return;

			defalut :
				move(14, 0);
				addstr("올바른 형식으로 입력해주세요 ex) 1");	
				usleep(1000 * 0.5);
		}
	}
}

#define mars(row, msg) {move(row, 0); addstr(msg); refresh(); sleep(5); }
// 매크로 함수 정의 move_addstr_refresh_sleep

void background()
{
	initscr();

	mars(0, "안녕하세요. 정설영 교수님의 시스템 프로그래밍 수업을 들었던 수학과 17학번 문경덕 입니다.");
	
	mars(2, "유닉스, 리눅스에 관한 아무런 배경 지식도 가지고 있지 않은 상태로 교수님의 수업을 듣게 되었습니다.");

	mars(4, "약 4개월 가량의 시간을 교수님의 수업과 함께하였습니다.");
		
	mars(6, "수업이 마무리될 때쯤 돌아보니 유닉스와 리눅스의 각종 명령어뿐만 아니라"); 	

	mars(8, "디스크와 메모리, 디바이스와의 관계, kernel과 user_space의 상호 작용 등 컴퓨터 구조적인 부분에 대해서 정말 많이 배울 수 있었습니다.");

	mars(10, "아마 교수님께서 개념 정리와 코드 설명이 자세하게 되어 있는 좋은 강의 자료를 제공해주시고");

	mars(12, "수업 내내 친절하게 설명해주시면서 Q&A와 각종 의견에 대한 피드백을 활발하게 해주셔서 많은 걸 얻어갈 수 있었던 것 같습니다.");

	mars(14, "(개인적으로는 비대면 수업 중 가장 활발한 의사소통이 진행되었습니다. (^-^) )");

	mars(16, "전 진심으로 감사했기 때문에 이번 학기말 프로젝트에 최선을 다하고 또 잘하고 싶었습니다.");

	mars(18, "그렇게 고민하던 중 교수님과의 수업 내용을 담은 학습 도우미 프로그램을 만들면 어떨까 하고 생각하게 되었습니다.");

	mars(20, "학기를 마무리하며 그동안 공부하였던 내용들을 복습할 수 있으며, 필요에 따라 다시 유닉스, 리눅스를 공부하게 되었을 때 저에게 많은 도움이 될 것 같았습니다.");

	mars(22, "더 나아가 프로그램이 다듬어져서 어느 정도의 퀄리티를 갖추게 된다면 정설영 교수님의 수업을 듣게 될");

	mars(24, "제 주변의 초심자 분들께도 도움을 드릴 수 있을 것이라고 생각하였습니다.");

	mars(26, "공적으로나 개인적으로나 여러모로 도움이 된다고 생각했기 때문에 망설이지 않고 해당 프로젝트를 시작하게 되었습니다.");

	mars(28, "길지 않은 시간 동안 다른 과목들을 병행하면서 프로젝트를 진행하였기 때문에 부족한 부분도 있을 것이라고 생각합니다.");

	mars(30, "하지만, 주어진 시간과 환경에서 최선을 다해서 프로젝트를 완수해보겠습니다.");

	mars(32, "사담이지만 전 컴퓨터 학부 심화컴퓨터를 복수전공하고 있습니다.");

	mars(34, "그래서 앞으로도 컴퓨터 수업을 많이 듣게 될 텐데 좋은 기회가 된다면 교수님의 수업에 다시 찾아뵙겠습니다.");

	move(36, 0);
	addstr("감사합니다 !!!");
	refresh();
	sleep(1);

	move(44, 0);
	addstr("Enter to back to menu");
	refresh();

	getch();
	
	endwin();

}


#define mar(row, message) {move(row, 0); addstr(message); refresh();}
// move_addstr_refresh
void study()
{
	char chap;
	
	// curses 시작	
	initscr();

	while(1)
	{
	
		clear();

		mar(0, "학습을 시작합니다.");

		mar(2, "학습에 도움을 받을 챕터를 선택해주세요.");

		sleep(1);

		mar(4, "2. chap 2_who");

		mar(6, "3. chap 3_ls");

		mar(8, "4. chap 4_pwd");

		mar(10, "5. chap 5_stty");

		mar(12, "6. chap 6_signal");

		mar(14, "0. back to menu");

		mar(16, "번호를 입력해주세요 : ");

		getnstr(&chap, 1);
		
		switch(chap)
		{
			case '1':

			case '2':
				clear();
				endwin();
				chap2();
				break;			

			case '3':
				clear();
				endwin();
				chap3();
				break;

			case '4':
				clear();
				endwin();
				chap4();
				break;

			case '5':
				clear();
				endwin();
				chap5();
				break;

			case '6':
				clear();
				endwin();
				chap6();
				break;

			case '0':
				endwin();
				return ;

			defalut :
				move(24, 0);
				addstr("올바른 형식으로 입력해주세요.");
				usleep(1000 * 0.5);
		}				
	}
}

void chap2()
{
	initscr();

	while(1)
	{
		clear();

		char choice;

		mar(0, "챕터 2의 학습을 시작합니다.");

		mar(2, "학습하실 항목을 선택해주세요.");

		sleep(1);

		mar(4, "1. 학습 주제 및 목표");

		mar(6, "2. 개념 학습");

		mar(8, "3. C언어 함수 정리");

		mar(10, "0. 종료");

		mar(12, "번호를 입력해주세요 : ");

		getnstr(&choice, 1);

		switch(choice)
		{
			case '1':
				endwin();
				chap2_goal();
				break;

			case '2':		
				endwin();
				chap2_concept();
				break;	

			case '3':
				endwin();
				chap2_command();
				break;

			case '0':
				endwin();
				return ;

			defalut:
				mar(16, "올바른 형식으로 입력해주세요.");
				usleep(1000 * 0.5);
		}	
	}
}

void chap2_goal()
{
	initscr();
	char c;
	while(1)
	{
		clear();

		mar(0, "●  학습 주제 : who 명령어란? ");

		mar(2, "●  학습 목표 : ");

		mar(4, "  1. who 명령어의 개념을 정확하게 이해할 수 있다.");

		mar(6, "  2. C언어로 who 명령어를 작성해보며 who 명령어의 data-flow를 파악할 수 있다.");
	
		mar(8, "  3. User mode와 Kernel 모드를 정확하게 구분하고 System call에 발생하는 cost를 인지하여 효율적으로 관리할 수 있다."); 

		sleep(1);

		mar(12, " Enter to back to menu");
	
		getnstr(&c, 1);
		
		endwin();
		break;
	}


}

void chap2_concept()
{
	initscr();
	char c;
	while(1)
	{
		clear();
		mar(0, "1. 명령어의 개념");
	
		sleep(1);

		mar(2, "컴퓨터를 공부하면서 누구나 윈도우나 맥 또는 기타 cmd 프로그램을 사용해 보신 적이 있을 것입니다.");	

		mar(4, "예를 들면, $ cd home 을 통해 home 디렉토리로 이동하거나 $ ls 를 통해 디렉토리 내부의 파일 정보를 뽑을 수 있습니다."); 

		mar(6, "우분투의 터미널에서도 비슷한 명령어들이 활용됩니다.");

		mar(8, "우분투의 대부분의 Unix 명령어들은 C언어로 쓰여진 간단한 프로그램입니다.");

		mar(10, "즉, 저희가 Unix 명령어를 사용한다는 것은 C언어를 기반으로 만들어진 프로그램을 실행하는 것과 같습니다.");

		mar(12, "위의 예로 돌아가보면 $ ls 라는 것은 ls라는 이름의 C언어 프로그램을 shell에게 실행하도록 요청하는 것입니다.");
		
		mar(14, "Unix/Linux 개발자들은 사용자들의 편의성을 위해 자주 활용되는 기능들을 미리 구현하여 담아두었습니다.");

		mar(16, "해당 프로그램들은 효율성이 증명된 깔끔한 프로그램이며, /bin, /usr/bin 디렉토리에 담겨있습니다.");

		mar(18, "이는 다시 말하면 누구나 C언어로 프로그램을 만들고 위의 디렉토리에 넣어서 shell에서 사용할 수 있음을 의미합니다.");

		mar(20, "이번 챕터에서는 who 명령어를 작성하는 방법에 대해서 공부하겠습니다.");

		mar(24, "Enter to continue (0 : 학습 종료)");

		getnstr(&c, 1);
		if( c == '0') {break;}

		clear();
		mar(0, "2. who 명령어가 하는 일");

		sleep(1);

		mar(2, "who 명령어는 현재 컴퓨터에 접속하고 있는 사용자들의 정보를 출력해주는 명령어 입니다.");

		mar(4, "사용자 이름 | 터미널 이름 | 로그인 시간 | 로그인 host 의 기본적인 형식을 맞추어 출력하여 줍니다.");

		mar(6, "예를 들면");

		mar(8, "gyoungdeok ttyp1 2021-11-29 11:23 (:0) 과 같이 출력될 수 있습니다." ); 

		mar(10, "순서대로 gyoungdeok 은 사용자 이름, ttyp1은 터미널 이름, 시간은 로그인 시간, (:0)은 로그인 host를 나타냅니다.");

		mar(12, "아마 대부분의 분들께서 실제로 who 명령어를 사용해보시면 한 줄 혹은 두 줄밖에 출력되지 않을 것입니다.");

		mar(14, "이는 지극히 자연스러운 현상이며 책과 다르다고 걱정하실 필요가 없습니다."); 
	
		mar(16, "앞으로 네트워크와 통신, socket, thread, stty 등을 학습하며 다른 사용자와 상호작용을 하는 방법을 배우면서");

		mar(18, "점차 여러 개의 줄로 만들 수 있을 것 입니다.");

		mar(22, "Enter to continue (0 : 학습 종료)");

		getnstr(&c, 1);	
		if( c == '0') {break;}

		clear();
		mar(0, "3. UTMP");

		sleep(1);

		mar(2, "UTMP 파일은 현재 로그인한 사용자의 로그인 기록에 대한 문서(로그 파일)라고 생각하시면 됩니다.");

		mar(4, "이전에 배웠던 who 명령어를 실행하였을 때 출력되는 결과들은 UTMP 파일의 내용이라고 생각하면 될 것 같습니다.");

		mar(6, "who 명령어를 C언어로 직접 구현해볼 때 UTMP 파일의 내용을 불러와서 활용할 것 입니다.");
		
		mar(8, "C언어로 구현할 때는 <utmp.h>라는 헤더파일을 불러와서 UTMP를 다루어 볼 것입니다.");

		mar(10, "조금만 더 말씀드리자면, <utmp.h>에서 UTMP 파일의 내용을 담을 수 있도록 구현되어 있는 UTMP 구조체를 사용할 것 입니다.");

		mar(12, "( UTMP 구조체 내부 : 사용자 이름, 디바이스 이름, 로그인 시간, host 정보 )");

		mar(14, "참고로 UTMP 파일과 비슷한 WTMP 파일이 있습니다.");

		mar(16, "UTMP 파일이 현재 로그인한 사용자의 정보를 담고 있다면, WTMP 파일은 그동안 성공했던 로그인 및 로그아웃에 대한 모든 히스토리를 담고 있습니다.");

		mar(18, "터미널에서 $ last 를 통해서 확인할 수 있으니 참고하는 것도 좋을 것 같습니다.");

		mar(22, "Enter to continue (0 : 학습 종료)");
		getnstr(&c, 1);
		if(c == '0') {break;}
		
		clear();
		mar(0, "4. who 명령어의 Data-Flow");
		
		sleep(1);

		mar(2, "저희는 다음과 같은 방식으로 who 명령어를 구현할 예정입니다.");

		mar(4, "  ①  UTMP 파일 open");
	
		mar(6, "  ②  UTMP 구조체를 통해 UTMP 파일 read");

		mar(8, "  ③  읽어온 정보들 출력");	

		mar(10, "  ④  읽을 내용이 없을 때까지 ②  ~ ③  반복");

		mar(12, "  ⑤  UTMP 파일 close");

		mar(16, "Enter to continue (0 : 학습 종료)");

		getnstr(&c, 1);
		if(c == '0') {break;}

		clear();
		mar(0, "5. cp 명령어란?");

		sleep(1);

		mar(2, "cp 명령어는 파일의 복사본을 만드는 명령어입니다.");

		mar(4, "$ cp original new 을 통해 original 파일의 내용을 그대로 복사한 new 파일을 생성할 수 있습니다.");

		mar(6, "C언어에서 copy를 구현하는 자세한 방법은 chap 2의 '명령어 및 함수 정리'에서 다루겠습니다.");

		mar(8, "다음 장이 개념 정리의 마지막 장입니다. 조금만 힘내세요 !");

		mar(12, "Enter to continue (0 : 학습 종료)");

		getnstr(&c, 1);
		if(c == '0') {break;}

		clear();
		mar(0, "6. ★  User Mode & Kernel Mode  ★");

		sleep(1);

		mar(2, "저희가 UNIX를 다룰 때 크게 2 가지의 Mode로 나누어져 사용하게 됩니다.");
	
		mar(4, "첫 번째가 User_mode이고 두 번째는 Kernel_mode 입니다.");

		mar(6, "User_mode는 사용자가 접근할 수 있는 제한된 영역에 있을 때 활성화되는 mode입니다.");

		mar(8, "이 mode에서 사용자는 코드를 작성하거나 프로세스를 실행하는 등의 행동을 수행할 수 있습니다.");

		mar(10, "Kernel_mode는 User_mode에서 요청이 발생하였을 때 활성화될 수 있는 mode입니다.");

		mar(12, "User_mode와는 다르게 디스크, 메모리, CPU 등의 모든 자원에 접근하여 데이터를 관리하고 교류하는 역할을 합니다.");

		mar(14, "이렇게 나누어져 있는 가장 큰 이유는 컴퓨터 내부의 Data를 안전하게 관리하기 위함입니다.");

		mar(16, "만약, 사용자가 임의로 데이터를 사용하고 가져갈 수 있다면 Data_Pollution이나 Data_Loss가 발생할 수 있을 것입니다.");

		mar(18, "Kernel은 이러한 일을 방지하도록 설계되었습니다. ( 참고로 Kernel은 다른 많은 일에도 관할하고 있습니다. )");		

		mar(20, "저희가 프로세스를 실행하는 동안 프로세스는 두 개의 mode를 번갈아가며 실행이 됩니다.");

		mar(22, "예를 들어 프로세스가 실행되는 동안에 open함수를 호출했다고 가정해보겠습니다.");

		mar(24, "그렇게 되면 system call 함수인 open 이 호출되면서 Kernel_mode로 넘어갑니다.");

		mar(26, "open에 대한 입력값들이 Kernel로 함께 전달이 되고 관련 업무들을 수행한 이후, Kernel에서는 적절한 값을 반환하여 줍니다.");

		mar(28, "아마 이 예시에서는 open을 할 파일의 이름을 전달하였고, open 함수가 성공하였다면 해당 파일 디스크립터를 반환하여 줄 것입니다.");

		mar(30, "이 때의 값 반환과 함께 User_mode로 돌아가게 됩니다.");

		mar(32, "실제 프로세스에서는 다양한 system call이 호출되기 때문에 위의 흐름이 수없이 반복됩니다.");

		mar(34, "따라서, 프로그램을 작성할 때에는 System call이 호출됨에 따라 Time_Cost가 발생함을 충분히 고려하여야 합니다.");

		mar(36, "다시 말해서 Mode의 변환이 최소화 될 수 있도록 프로그램을 작성하여 효율성을 높여야 합니다.");

		mar(38, "예를 들어 5MB의 데이터를 복사한다면, 버퍼 사이즈를 1로 했을 때보다 4096으로 설정하는 것이 좋습니다.");

		mar(40, "메모리는 조금 차지할지라도, 소모되는 시간을 약 278배 정도 빠르게 할 수 있기 때문입니다.");
			
		mar(42, "★  중요한 부분이니 충분히 이해하고 넘어가셨으면 좋을 것 같습니다.  ★");

		mar(46, "Enter to end");

		getnstr(&c, 1);
		break;

	}
	endwin();
}

void chap2_command()
{
	initscr();

	while(1)
	{
		clear();
		refresh();

		char c;
	
		mar(0, "챕터 2의 C언어 함수를 살펴봅니다.");

		sleep(1);

		mar(2, "1. open");

		mar(4, "2. read");

		mar(6, "3. close");

		mar(8, "4. creat");

		mar(10, "5. write");

		mar(12, "6. lseek");

		mar(14, "0. 종료");

		mar(16, "번호를 입력해주세요 : ");

		getnstr(&c, 1);

		switch(c)
		{
			case '1':
				clear();
				mar(0, "open 함수 정리");
				mar(2, "헤더 파일 : <fcntl.h>");
				mar(4, "용도 : 파일과의 연결을 형성하고자 할 때 사용. 즉, 파일의 내용을 읽거나 파일을 다루고 싶을 때 사용함"); 	
				mar(6, "사용 방법 : open(열고자 하는 파일 이름, int how)");
				mar(7, "파일을 여는 목적에 따라 how의 값이 달라짐");
				mar(8, "O_RDONLY : 읽기 전용, O_WRONLY : 쓰기 전용, O_RDWR : 읽고 쓰기 전용");
				mar(9, "예시) open(input.txt, O_RDONLY");
				mar(11, "return 값");
				mar(12, "실패시 -1 반환, 성공시 file_descriptor 반환");
				mar(13, "file_descriptor : 파일과의 연결을 형성하면 프로세스마다 커널의 배열에 파일과의 연결 번호를 저장하는데 그 값을 의미");
				mar(14, "좀 더 나아가자면 모든 프로세스들은 기본적으로 0, 1, 2의 파일 디스크립터를 가지고 있다.");
				mar(15, "0 : 표준 입력, 1 : 표준 출력, 2 : 표준 에러 출력 (자세한 내용은 다른 챕터에서 공부함)");
				mar(19, "Enter to end");
				getnstr(&c, 1);
				break;
				
			case '2':
				clear();
				mar(0, "read 함수 정리");
				mar(2, "헤더 파일 : <unistd.h>");
				mar(4, "용도 : 파일의 내용을 지정한 버퍼에 담기 위해 사용. 즉, 파일의 내용을 읽기 위해서 사용함");
				mar(6, "사용 방법 : read(열고자 하는 파일의 fd, 버퍼 포인터, 읽을 크기)");
				mar(7, "예시) read(3, &buffer, BUFSIZ)");
				mar(9, "실패시 -1 반환, 성공시 읽은 만큼의 수를 반환");
				mar(13, "Enter to end");
				getnstr(&c, 1);
				break;
	
			case '3':
				clear();
				mar(0, "close 함수 정리");
				mar(2, "헤더 파일 : <unistd.h>");
				mar(4, "용도 : 파일과의 연결을 해제하고자 할 때 사용.");
				mar(6, "사용 방법 : close(해제하고자 하는 파일의 fd)");
				mar(7, "예시) close(3)");		
				mar(9, "실패시 -1 반환, 성공시 0 반환");
				mar(13, "Enter to end");
				getnstr(&c, 1);	
				break;

			case '4':
				clear();
				mar(0, "creat 함수 정리");
				mar(2, "헤더 파일 : <fcntl.h>");
				mar(4, "용도 : 새로운 파일을 만들고자 할 때 사용");
				mar(6, "사용 방법 : creat(새로운 파일의 이름, mode_t mode)");
				mar(7, "mode는 rw-r--r--와 같은 파일 권한을 의미");
				mar(8, "mode 표현 방법은 파일의 권한을 이진법으로 표기한 후 8진법으로 작성한다");
				mar(9, "예를 들어 rw-r--r--가 파일 권한이라면 이진법으로는 110100100이 되고 이를 8진법으로 고치면 0644가 된다");
				mar(10, "컴퓨터마다 기본적으로 깔려 있는 계산기의 프로그래머 기능을 활용하면 편하니 꼭 사용해볼 것");
				mar(11, "예시) creat(filename, 0644)");
				mar(13, "실패시 -1 반환, 성공시 새로운 파일의 파일 디스크립터를 반환");
				mar(17, "Enter to end");
				getnstr(&c, 1);
				break;

			case '5':
				clear();
				mar(0, "write 함수 정리");
				mar(2, "헤더 파일 : <unistd.h>");
				mar(4, "용도 : 버퍼의 내용을 파일에 담기 위해 사용. 즉, 파일에 내용을 쓰고 싶을 때 사용함");
				mar(6, "사용 방법 : write(작성할 파일의 fd, 버퍼 포인터, 작성할 양");
				mar(7, "예시) write(1, &buffer, BUFSIZ)");
				mar(9, "실패시 -1을 반환, 성공시 작성한 만큼의 양을 반환");
				mar(13, "Enter to end");
				getnstr(&c, 1);
				break;

			case '6':
				clear();
				mar(0, "lseek 함수 정리");
				mar(2, "헤더 파일 : <sys/types.h> <unistd.h>");
				mar(4, "용도 : 간단하게 설명하면 파일 내부에서 커서의 위치를 옮기기 위해서 사용함");
				mar(6, "사용 방법 : lseek(파일의 fd, 옮길 만큼의 거리, 시작점)");
				mar(7, "예시) lseek(3, 10, SEEK_CUR) : 커서의 현재 위치에서 10만큼 이동한다");
				mar(8, "시작점에 대한 변수 3가지");
				mar(9, "SEEK_SET : 시작점, SEEK_CUR : 현재 위치, SEEK_END : 파일의 끝지점");
				mar(11, "실패시 -1을 반환하며 성공시 0을 반환");
				mar(15, "Enter to end");
				getnstr(&c, 1);
				break;	
				clear();
			
			case '0':
				endwin();
				return; 
	
			defalut:
				mar(20, "올바른 형식으로 입력해주세요.");	
				usleep(1000 * 0.5);


		}	

		
	}
}

void chap3()
{
        initscr();

        while(1)
        {
                clear();

                char choice;

                mar(0, "챕터 3의 학습을 시작합니다.");

                mar(2, "학습하실 항목을 선택해주세요.");

                sleep(1);

                mar(4, "1. 학습 주제 및 목표");

                mar(6, "2. 개념 학습");

                mar(8, "3. C언어 함수 정리");

                mar(10, "0. 종료");

                mar(12, "번호를 입력해주세요 : ");

                getnstr(&choice, 1);

                switch(choice)
                {
                        case '1':
                                endwin();
                                chap3_goal();
                                break;

                        case '2':
                                endwin();
                                chap3_concept();
                                break;

                        case '3':
                                endwin();
                                chap3_command();
                                break;

                        case '0':
                                endwin();
                                return ;

                        default:
                                mar(16, "올바른 형식으로 입력해주세요.");
                                usleep(1000 * 0.5);
                }
        }
}

void chap3_goal()
{
        initscr();
        char c;
        while(1)
        {
                clear();

                mar(0, "●  학습 주제 : ls 명령어란? ");

                mar(2, "●  학습 목표 : ");

                mar(4, "  1. ls 명령어의 개념을 정확하게 이해하고 여러 명령어들을 활용할 수 있다.");

                mar(6, "  2. 디렉토리의 정확한 의미와 내부 구조를 파악할 수 있다.");

                mar(8, "  3. File에 관한 특성 및 정보를 정확하게 이해할 수 있다.");

		mar(10, "  4. ls 명령어 프로그램을 작성할 수 있다."); 
 
                sleep(1);

                mar(14, " Enter to back to menu");

                getnstr(&c, 1);

                endwin();
                break;
        }


}

void chap3_concept()
{
	char c;
	
	while(1) {
	
	clear();
	mar(0, "1. ls 명령어가 하는 일");

	sleep(1);

	mar(2, "모든 프로세스는 자신이 위치하고 있는 디렉토리의 위치 정보를 포함하고 있습니다.");

	mar(4, "ls는 현재 프로세스가 위치하고 있는 디렉토리의 파일들과 하위 디렉토리의 정보를 출력해주는 명령어 입니다.");

	mar(6, "기본적은로 옵션 없이 $ ls  를 실행할 경우 파일의 이름만 출력되게 됩니다.");

	mar(8, "예시) $ ls");

	mar(10, "공개 음악 문서 다운로드 test input.txt");

	mar(12, "파일에 관한 좀 더 자세한 설명을 받고자 한다면 ls 뒤에 옵션을 주어서 실행하면 됩니다.");

	mar(14, "가장 많이 사용되는 옵션은 '-l' 입니다. $ ls -l 을 하게 되면 각 파일에 대한 세부적인 정보를 불러올 수 있습니다.");

	mar(16, "더 나아가 a를 붙이면 '-al'은 숨겨져 있던 파일의 내용도 출력해주며 (all)");

	mar(18, "i를 붙이게 되면 각 파일의 inode number도 추가적으로 파악할 수 있습니다. (추후에 배우게 됨)");

	mar(20, "하이픈 기호(-) 를 사용한 옵션 말고도 다른 디렉토리의 이름을 옵션으로 줄 수 있습니다.");

	mar(22, "예를 들어 루트 노드에 있는 tmp 디렉토리 파일의 정보를 불러오고 싶다면 $ ls /tmp 와 같이 사용하면 됩니다.");

	mar(24, "정리해서 ls 명령어는 크게 2가지 정도만 이해하면 될 것 같습니다.");

	mar(26, "1. ls 명령어는 디렉토리 내부의 파일 정보를 읽어온다.");	

	mar(28, "2. -a 옵션을 주었을 때 출력되는 '.'은 현재 디렉토리를 의미하며 '..'은 상위 디렉토리를 의미한다.");

	mar(32, "Enter to Continue (0 : 종료)");

	getnstr(&c, 1);
	if(c == '0') { break;}
	clear();

	mar(0, "2. ls 명령어의 구현");

	sleep(1);

	mar(2, "ls 명령어의 기본적인 logic은 다음과 같습니다.");

	mar(4, "①  open 디렉토리");

	mar(6, "②  디렉토리 내부의 항목들 읽어오기");

	mar(8, "③  파일 세부 정보 출력");

	mar(10, "④  디렉토리의 모든 항목들에 대해서 ②  ~ ③  반복 수행");

	mar(12, "⑤  close 디렉토리");

	mar(14, "그렇다면 ①  번에서 디렉토리를 open 하기 위해서 chapter 2에서 사용했었던 open 함수를 사용해도 될까요?");

	mar(16, "결론을 말씀드리자면, 디렉토리는 파일과 내부적인 구조가 다르게 구현되어 있기 때문에 다른 라이브러리를 불러와서 사용해야 합니다.");

	mar(18, "<sys/types.h>  :  디렉토리 구조체와 디렉토리 포인터의 자료형이 구현되어 있는 헤더 파일");

	mar(20, "<dirent.h> : 디렉토리와 관련된 함수들이 구현되어 있는 헤더 파일");

	mar(22, "기본적으로 <dirent.h>의 opendir(), readdir(), closedir()을 통해서 디렉토리를 다루게 되는데 자세한 함수 설명은 함수 정리 부분에서 다루겠습니다.");

	mar(26, "Enter to Continue (0 : 종료)");

	getnstr(&c, 1);
	if(c == '0') {break;}
	clear();

	mar(0, "3. ls -l 세부 사항");

	sleep(1);

	mar(2, "$ ls -l 명령어는 프로세스가 위치한 디렉토리의 각 파일의 세부적인 정보들을 출력해 준다고 배웠습니다.");

	mar(4, "구체적으로는 다음과 같이 출력됩니다.");

	mar(6, "File 모드 및 권한 | 링크 수 | 파일을 소유한 사용자 이름 | 파일을 소유한 그룹 이름 | 파일 크기 | 마지막 수정 시간 | 파일명");

	mar(8, "예시");

	mar(10, "합계 64");

	mar(12, "drwxrw-r-- 3 Moon knu 4096 12월 1일 17:19 temp_directoy");

	mar(14, "가장 위에 나열되는 합계는 디렉토리 내부의 Block size를 의미합니다.");

	mar(16, "Block은 쉽게 생각해서 모든 파일을 동등한 공간에 효율적으로 저장하고자 지정한 최소 크기입니다.");

	mar(18, "A라는 파일은 1칸에 10 byte씩 저장하고 B라는 파일은 1칸에 300byte식 저장한다고 하면 저장 공간 관리 차원에서 비효율적일 것입니다.");

	mar(18, "이를 예방하고자 나온 개념이 Block입니다. 기본적으로 Linux 계열 커널은 block 1개가 512 byte의 크기를 가집니다.");

	mar(20, "다음으로는 1줄씩 출력되는 파일의 정보를 상세하게 알아보도록 하겠습니다.");

	mar(22, "첫 번째로 나오는 파일 모드와 두 번째로 나오는 링크 수는 다음 페이지에서 상세하게 다루도록 하겠습니다.");
	
	mar(24, "그 다음 항목들로는 moon과 knu가 출력되었습니다. 모든 파일은 사용자 및 그룹에 속해있는데 순서대로 해당 파일의 사용자 이름(moon)과 그룹 이름(knu)을 나타냅니다.");

	mar(26, " 다음의 4096은 파일의 크기를 의미합니다. 기본적으로 파일 크기는 byte 단위로 나타내며 $ ls -lh 와 같이 h 옵션을 추가하여 사람이 보기 편한 형식으로 바꾸어 줄 수 있습니다.");

	mar(28, "참고로 리눅스 계열에서 디렉토리의 파일 크기는 거의 4096으로 출력됩니다. 이는, 디스크에서 디렉토리에 대한 메타 정보를 저장하는데 보통 4096(4kb)가 필요하기 때문입니다.");

	mar(30, "이후에 나오는 수정 시간과 파일명은 직관적으로 이해할 수 있으실 것입니다.");

	mar(32, "다음 페이지에서 파일 모드와 링크 수에 대해서 알아보겠습니다.");

	mar(36, "Enter to Continue (0 : 종료)");
	getnstr(&c, 1);
	if(c == '0') {break;}
	clear();

	mar(0, "3-1. File 모드와 권한");

	sleep(1);

	mar(2, "이전의 예시에서 drwxrw-r--과 같이 출력되었습니다.");

	mar(4, "이는 파일의 상태와 권한에 대해서 나타내는 정보인데 첫 번째 칸이 파일의 상태(File인지, Directory인지 등등)을 나타내고 뒤에 9칸이 권한을 나타냅니다.");

	mar(6, "해당 예시에서 첫 번째 칸이 d로 채워져있는 것은 directory임을 의미합니다.");

	mar(8, "그리고 순서대로 3칸씩 파일의 사용자에 대한 권한, 그룹에 대한 권한, 기타 사용자에 대한 권한을 나타냅니다.");

	mar(10, "즉, 2~4칸 : User 권한, 5~7칸 : Group 권한, 8~10칸 : Others 권한 입니다.");

	mar(12, "그리고 각 칸은 r, w, x의 순서로 채워지는데 각각 읽기, 쓰기, 실행 권한을 의미합니다.");

	mar(14, "해당 칸에 대한 권한이 없을 경우 - 로 표시합니다.");

	mar(16, "예시의 경우를 따져보면, User는 읽고 쓰고 실행하는 것이 가능하고, Gruop은 읽고 쓰는 것만, Others는 읽는 것만 가능한 디렉토리였습니다.");

	mar(18, "추가적으로, 파일 권한에 대해서 3가지의 Special bit가 존재합니다.");

	mar(20, "첫 번째로 suid bit입니다. 해당 비트가 활성화 되어 있는 파일의 경우 파일의 소유 권한이 없는 사용자라도 사용 권한이 있는 것처럼 실행할 수 있게 됩니다.");

	mar(22, "이를 조금 더 어렵게 말해서 user id를 effective한 user id로 설정하였다고 표현합니다.");
	
	mar(24, "suid bit가 활성화되면 4번째 칸인 User 권한 영역의 x자리가 s로 표기됩니다.");

	mar(26, "두 번째는 sgid bit입니다. sgid 비트는 suid와 비슷한 역할을 그룹에게 해준다고 생각하면 됩니다.");

	mar(28, "즉, group id를 effective한 gruop id로 바꾸어 사용 권한이 있는 그룹처럼 해당 파일을 실행할 수 있게 해줍니다.");

	mar(30, "sgid bit가 활성화되면 7번째 칸인 Group 영역의 x자리가 s로 표기됩니다.");

	mar(32, "마지막 special bit는 sticky bit입니다. sticky bit는 파일에 적용된 경우와 디렉토리에 적용이 된 경우에 따라 역할이 달라집니다.");

	mar(34, "우선 파일에 적용이 되었을 경우 해당 파일이 사용되지 않게 되었을 때 메모리에서 해제하지 않고 그대로 유지하게 됩니다.");

	mar(36, "다음에 사용하게 되었을 때 디스크에서 따로 파일을 불러와서 메모리에 할당할 필요없이 바로 사용하면 되는 것이죠.");

	mar(38, "디렉토리에 적용이 되었을 경우 해당 디렉토리를 공용 디렉토리처럼 모두가 사용할 수 있도록 합니다. 하지만 삭제나 이름 변경등은 실제 소유자나 슈퍼 유저만 할 수 있습니다.");

	mar(40, "리눅스 터미널에서 $ chmod g+x 와 같이 파일의 권한을 변경할 수 있으니 직접 실습해보며 익혀보는 것도 좋을 것 같습니다.");

	mar(44, "Enter to Continue (0: 종료)");

	getnstr(&c, 1);
	if(c == '0') {break;}
	clear();

	mar(0, "3-2. 링크");
	
	sleep(1);

	mar(2, "세부적인 내용은 이후의 챕터에서 다룰 것이니 간단하게만 설명을 드리겠습니다.");

	mar(4, "링크는 파일이 다른 것들과 연결된 포인터의 개수라고 생각하시면 됩니다.");

	mar(6, "A라는 파일이 2라는 링크를 가지고 있다면 디렉토리 또는 파일에 연결된 포인터가 2개가 있다고 생각하시면 됩니다.");

	mar(8, "저희가 파일을 디렉토리 내부에 새롭게 생성할 때도, 파일의 내용이 작성된 이후에 현재 디렉토리와의 연결 포인터를 하나 만듭니다. 따라서 링크 수가 1로 생성됩니다."); 

	mar(10, "기타 하드 링크나 심볼릭 링크를 통해서도 파일 간의 값을 공유하거나 참조할 수 있는데 자세한 방법들은 이후의 챕터에서 다룰 것이니");

	mar(12, "링크의 개념만 인지하시고 하드 링크나 심볼릭 링크라는 방법을 통해서 링크를 만들 수 있음을 이해하시면 될 것 같습니다.");

	mar(16, "Enter to Continue");

	getnstr(&c, 1);
	if(c == '0')
	{break;}
	clear();
	break;	
	}
	endwin();
}

void chap3_command()
{
	 initscr();

        while(1)
        {
                clear();
                refresh();

                char c;

                mar(0, "챕터 3의 C언어 함수를 살펴봅니다.");

                sleep(1);

                mar(2, "1. opendir");

                mar(4, "2. readdir");

                mar(6, "3. closedir");

                mar(8, "4. stat");

                mar(10, "5. chmod");

                mar(12, "6. chown");

                mar(14, "0. 종료");

                mar(16, "번호를 입력해주세요 : ");

                getnstr(&c, 1);

                switch(c)
                {
                        case '1':
                                clear();
                                mar(0, "opendir 함수 정리 (open directory)");
                                mar(2, "헤더 파일 : <sys/types.h> <dirent.h>");
                                mar(4, "용도 : 디렉토리를 열고자 할 때 사용");
                               	mar(6, "사용 방법 : DIR* opendir(const char* name)");
				mar(7, "name : 열고자 하는 디렉토리 이름"); 
                                mar(9, "예시) opendir('..')");
                               	mar(11, "실패 시 NULL 반환, 성공시 디렉토리 구조체 포인터 DIR* 반환"); 
				mar(13, "파일 디스크립터와 비슷하며 디렉토리 처리가 완료되면 닫아주는 것을 잊지 말 것!");
				mar(17, "Enter to end");
				getnstr(&c, 1);
				break;

                        case '2':
                                clear();
                                mar(0, "readdir 함수 정리 (read directory)");
                                mar(2, "헤더 파일 : <sys/types.h> <dirent.h>");
				mar(4, "용도 : 특정 디렉토리 내용을 읽기 위해서 사용");
				mar(6, "사용 방법 : struct dirent* readdir(DIR* dir)");
				mar(7, "opendir을 통해 반환받은 값을 인자로 넣어주면 됨.");
				mar(9, "예시) DIR* dir_ptr, struct dirent* entry로 선언되어 있을 때,");
				mar(10, "entry = readdir(dir_ptr) 과 같이 사용");
				mar(12, "실패 시 NULL qksghks, 성공 시 dirent 구조체에 대한 포인터(struct dirent*) 반환");                                
				mar(16, "Enter to end");
				getnstr(&c, 1);
				break;

                        case '3':
                                clear();
                                mar(0, "closedir 함수 정리 (close directory)");
                                mar(2, "헤더 파일 : <sys/types.h> <dirent.h>");
                                mar(4, "용도 : opendir() 호출로 반환 받았던 DIR과 연관된 디렉토리를 닫을 때 사용. 즉, 디렉토리를 닫을 때 사용");
				mar(6, "사용 방법 : int closedir(Dir* dirp)");	
				mar(8, "예시) closedir(dir_ptr)");
                                mar(10, "실패시 -1 반환, 성공시 0 반환");
				mar(14, "Enter to end");	
				getnstr(&c, 1);
				break;
	
			case '4':	
				clear();
				mar(0, "stat 함수 정리 (status)");
				mar(2, "헤더 파일 : <sys/stat.h>");
				mar(4, "용도 : 파일 크기, 권한, 생성 일자, 최종 변경일 등의 파일의 상태나 정보를 얻기 위해 사용");
				mar(6, "사용 방법 : stat(const char* pathname, struct stat* statbuf");
				mar(7, "pathname에는 현재 디렉토리 내부의 파일 이름이나 읽고자 하는 파일의 경로를 넘겨줘야 함");
				mar(8, "statbuf에는 비어 있는 stat 구조체 포인터를 넘겨주어야 함 (읽어온 정보를 저장할 공간으로 활용됨)");
				mar(10, "예시) char dirname = 'dir', struct stat* ptr 일때,");
				mar(11, "stat(dirname, ptr) 과 같이 사용");	
				mar(13, "실패 시 -1 반환, 성공 시 0 반환 (성공적으로 파일 정보를 조회하였음을 의미)");
				mar(17, "Enter to end");
				getnstr(&c, 1);
				break;
				
			case '5':
				clear();
				mar(0, "chomod 함수 정리 (change mode)");
				mar(2, "헤더 파일 : <sys/types.h> <sys/stat.h>");
				mar(4, "용도 : 파일의 권한을 바꾸거나 Special bit(suid, sgid, sticky)을 활성화하기 위해서 활용");
				mar(6, "사용 방법 : int chmod(char* path, mode_t mode)");
				mar(7, "path는 파일의 경로를 의미");
				mar(8, "mode는 파일 생성함수인 creat와 비슷하게 8진수 활용");
				mar(10, "예를 들어 mode에 0764를 넣어줬다면? ");
				mar(11, "0764 (8진수) -> 111 110 100 (2진수)");
				mar(12, "따라서 파일의 권한을 rwx rw- r-- 으로 재설정함");	
				mar(14, "예시) chmod('/tmp/myfile', 04764) ");
				mar(16, "실패 시 -1 반환, 성공 시 0 반환");
				mar(20, "Enter to end");	
				getnstr(&c, 1);
				break;

			case '6':
				clear();
				mar(0, "chown 함수 정리 (change owner)");
				mar(2, "헤더 파일 : <unistd.h>");
				mar(4, "용도 : 파일의 사용자나 그룹 아이디를 변경하기 위해서 사용. 즉, 파일의 소유 주체를 변경하기 위해서 사용");
				mar(6, "사용 방법 : int chown(char* path, uid_t owner, gid_t group)");
				mar(8, "예시) chown(filename, 100, 20) : 파일의 소유 주체가 uid가 100번인 사용자와 gid가 20번인 그룹으로 변경됨");	
				mar(10, "실제 사용 시에는 uid와 pid 인수 자리에");
				mar(11, "chmod(filename, user_info->pw_uid, group_info->gr_gid) 와 같이 다른 구조체의 값이 활용됨"); 
				mar(13, "실패 시 -1 반환, 성공 시 0 반환");
				mar(17, "Enter to end");
				getnstr(&c, 1);
				break;	

			case '0':
				endwin();
				return;

			default:
				mar(20, "올바른 형식으로 입력해주세요.");
				usleep(1000 * 0.5);
		}
	}
}

void chap4()
{
        initscr();

        while(1)
        {
                clear();

                char choice;

                mar(0, "챕터 4의 학습을 시작합니다.");

                mar(2, "학습하실 항목을 선택해주세요.");

                sleep(1);

                mar(4, "1. 학습 주제 및 목표");

                mar(6, "2. 개념 학습");

                mar(8, "3. C언어 함수 정리");

                mar(10, "0. 종료");

                mar(12, "번호를 입력해주세요 : ");

                getnstr(&choice, 1);

                switch(choice)
                {
                        case '1':
                                endwin();
                                chap4_goal();
                                break;

                        case '2':
                                endwin();
                                chap4_concept();
                                break;

                        case '3':
                                endwin();
                                chap4_command();
                                break;

                        case '0':
                                endwin();
                                return ;

                        default:
                                mar(16, "올바른 형식으로 입력해주세요.");
                                usleep(1000 * 0.5);
                }
        }
}

void chap4_goal()
{
        initscr();
        char c;
        while(1)
        {
                clear();

                mar(0, "●  학습 주제 : File System과 Unix 내부 구조 파헤치기");

                mar(2, "●  학습 목표 : ");

                mar(4, "  1. ★  File system의 개념과 Unix 내부 구조를 파악할 수 있다.  ★");

                mar(6, "  2. inode 개념을 이해하고 디렉토리 구조를 파악할 수 있다.");

                mar(8, "  3. C언어로 pwd 명령어를 구현해 볼 수 있다.");

                sleep(1);

		mar(10, "이전의 챕터들과는 다르게 학습 주제를 특정 명령어가 아닌 File System과 Unix 내부 구조로 설정하였습니다.");

		mar(12, "개인적으로 사용하는 환경의 기본적인 구조나 틀을 파악하는 것은 매우 중요하다고 생각했기 때문입니다.");
	
		mar(14, "그리고 저도 해당 부분을 통해서 많은 배움을 얻었기 때문에 4단원은 조금 더 집중해서 보시면 좋을 것 같습니다.");
	
		sleep(1);

                mar(18, " Enter to back to menu");

                getnstr(&c, 1);

                endwin();
                break;
        }
}

void chap4_concept()
{
	initscr();
       
	 char c;
       
	 while(1)
        {
                clear();
	        mar(0, "1. Directory Commands");

                sleep(1);

                mar(2, "4단원은 여러 개의 명령어들이 등장합니다. 따라서, 4단원 개념 정리는 각 명령어들의 간단한 사용법과 의미를 파악하는 것부터 시작하겠습니다.");

		mar(6, "①  $ mkdir my_place : my_place라는 디렉토리를 만듭니다. mkdir은 make directory의 약자 입니다.");

		mar(8, "②  $ rmdir my_place : my_place라는 디렉토리를 삭제합니다. 단, my_place가 비어 있을 경우만 삭제할 수 있습니다.");
		mar(9, "  파일이 들어 있는 디렉토리를 삭제하고 싶은 경우?? -r 옵션을 주면 됩니다. ex) $ rmdir -r my_place");
		mar(10, "  -r 옵션을 주는 것은 매우 위험한 명령이니 신중한 사용이 필요합니다. 추가로, rmdir은 remove directory의 약자입니다.");

		mar(12, "③  $ mv old new :");

		mar(14, "  1. (이동) new라는 디렉토리가 있을 경우 old를 new로 이동시킵니다.");

		mar(15, "  2. (이름 변경) new라는 디렉토리가 없을 경우 old의 이름을 new로 바꿉니다."); 
		
		mar(17, "④  $ pwd : 현재 위치한 경로를 출력합니다.");
		
		mar(19, "⑤  $ cat input.txt : input.txt의 내용을 터미널에 출력합니다.");
	
		mar(21, "⑥  $ 임의의 명령어 > memo : "); 
		mar(22, "  1. memo라는 파일이 있을 경우 memo 파일의 내용을 명령어의 결과값으로 바꿉니다.");
		mar(23, "  2. memo라는 파일이 없을 경우 memo 파일을 생성 후 명령어의 결과값으로 내용을 채워줍니다.");
		mar(24, "  사용 예시) who > input.txt");

		mar(26, "⑦  $ ln from.txt target.txt : from.txt로부터 target.txt로의 하드 링크를 생성합니다.");
		
		mar(28, "⑧  $ ln -s from.txt target.txT : from.txt로부터 target.txt로의 심볼릭 링크를 생성합니다.");

		mar(30, "  하드 링크와 심볼릭 링크?? 둘의 기능과 차이점은 뒤에서 자세하게 다루도록 하겠습니다.");

		mar(32, "⑨  $ du : 해당 디렉토리로부터 하위 디렉토리 및 파일들에 대한 디스크 사용량을 출력합니다.");

		mar(36, "Enter to Continue (0 : 종료)");

                getnstr(&c, 1);
                if( c == '0') {break;}

                clear();
                mar(0, "★  2. 디스크 구조  ★");

                sleep(1);

		mar(2, "저희가 파일을 다룰 때 파일은 디스크에 저장되어 있다고 표현합니다. 디스크란 무엇일까요?? 그 구조를 알아보겠습니다.");

		mar(4, "디스크는 기본적으로 데이터를 저장하는 platter와 값을 읽고 쓸 수 있는 head로 구분되어 있습니다.");

		mar(6, "그리고 저장공간인 platter는 각각 sector, track, cylinder와 같이 분류할 수 있습니다.");

		mar(8, "조금 더 쉽게 표현해보겠습니다.");

		mar(10, "디스크는 platter라는 이름의 CD가 여러 개 쌓여있는 모양을 하고 있습니다.");	

		mar(12, "그리고 이 CD는 여러 개의 동심원으로 이루어져 있는데 이를 track이라고 부릅니다. (달리기 트랙을 연상하셔도 좋습니다.)");

		mar(14, "마지막으로, CD위의 이 track들은 여러 개의 블록으로 나누어져 있습니다. 이 때, 각각의 블록을 sector라고 부릅니다.");

		mar(16, "sector는 platter의 최소 단위이며 저장 공간으로서 512 byte의 크기를 가집니다.");

		mar(18, "저희가 파일을 생성한다는 것은 sector를 여러 개 배정받아 해당 칸에 내용을 작성한다고 생각하시면 될 것 같습니다.");

		mar(20, "정리하자면, 최소 단위인 sector가 모여 track을 이루고, track이 platter라는 하나의 CD를 구성하며 platter가 층층이 쌓여 head와 함께 디스크를 구성하고 있습니다.");	
		
		mar(22, "참고로, cylinder는 각 platter에서 동일한 구간에 있는 track의 집합을 의미합니다.");

		mar(24, "예를 들어, 설명의 편의성을 위해 디스크가 3개의 CD, 즉, 3개의 platter로 구성되어 있다고 하겠습니다.");

		mar(26, "그리고 각 CD는 안쪽 track과 바깥쪽 track으로 나누어져 있다고 가정하겠습니다.");

		mar(28, "그렇게 되면 해당 디스크에서는 2개의 cylinder가 존재합니다.");

		mar(30, "첫 번째 cylinder : {1번째 CD의 안쪽 track, 2번째 CD의 안쪽 track, 3번째 CD의 안쪽 track}");

		mar(32, "두 번째 cylinder : {1번째 CD의 바깥쪽 track, 2번째 CD의 바깥쪽 track, 3번째 CD의 바깥쪽 track}");

		mar(36, "Enter to Continue (0 : 종료)");

		getnstr(&c, 1);
		if(c == '0') {break;}
		
		clear();
		mar(0, "3. ★  파일 시스템  ★ ");
		
		sleep(1);

		mar(2, "다음으로는 파일 시스템에 대해서 알아보겠습니다.");

		mar(4, "파일 시스템이란 사용자가 파일에 쉽게 접근하고 발견할 수 있도록 운영체제가 디스크 상에서 일정한 규칙을 가지고 보관하는 방식을 의미합니다");

		mar(6, "이 때 디스크는 실제로는 하나이지만 논리적으로 여러 개의 단위로 나누어져 저장 공간으로서 활용되는데 각각의 공간을 파티션(partiton)이라고 부릅니다.");	

		mar(8, "디스크를 파티션으로 나누어 파일을 저장하는 이유는 파일 저장이 용이해지고, 파일의 검색과 관리를 효율적으로 할 수 있기 때문입니다.");

		mar(10, "그렇다면, 파일을 저장하고 관리하는 방식이 다른 시스템과는 교류할 수 없는 것일까요??");

		mar(12, "결론은 아닙니다! 유닉스에서는 파일 시스템의 계층을 크게 3가지로 나누어 외부 장치의 종류에 관계없이 데이터를 주고 받을 수 있도록 하고 있습니다."); 

		mar(14, "①  Super block :");
	
		mar(16, "파일 시스템에 대한 정보( 각 데이터 구역의 크기, 사용되지 않는 데이터 블록 등) 를 담고 있습니다.");
	
		mar(18, "Unix의 버전에 따라 구조에 차이는 있을 수 있습니다.");

		mar(20, "②  inode table");

		mar(22, "모든 파일은 inode라고 불리는 자신만의 고유한 번호를 가지고 있습니다.");

		mar(24, "inode에는 파일 소유자, 링크 수, 파일 크기 등의 파일에 관한 특성을 저장하고 있습니다. (파일에 대한 메타 정보)");

		mar(26, "inode table은 이러한 inode 구조체의 배열입니다.");

		mar(28, "③  data area");

		mar(30, "data area는 파일의 내용물이 저장되는 공간입니다.");

		mar(32, "데이터 블록 1칸은 4KB의 공간을 차지하며 12개의 블록을 배정 받을 경우 48KB의 용량을 가짐을 의미합니다.");

		mar(34, "파일의 크기에 따라 데이터 블록에 파일의 내용이 아닌 다른 데이터 블록에 대한 주소(포인터)를 가지고 있을 수도 있습니다.");

		mar(36, "이를 indirect block이라고 부르며 이러한 구조가 반복될 때마다 double indirect block, triple indirect block이라고 부릅니다.");

		mar(40, "Enter to Continue (0 : 종료)");

		getnstr(&c, 1);
		if(c == '0') {break;}

		clear();
		mar(0, "4. 디렉토리");

		sleep(1);		

		mar(2, "디렉토리 내부에 파일이 존재한다는 것은 정확하게 어떤 의미일까요?");

		mar(4, "예를 들어 x라는 파일이 D라는 디렉토리 안에 존재한다고 하겠습니다.");

		mar(6, "이는 x라는 파일과 D라는 디렉토리 사이에 링크가 존재함을 의미합니다.");

		mar(8, "링크는 두 매개체 사이를 이어주는 연결선 혹은 바로가기 라고 생각하시면 쉽습니다.");

		mar(10, "링크를 사용하는 이유는 크게 2가지 입니다.");

		mar(12, "우선, 디렉토리와 내부 파일 사이를 이어서 디렉토리 입장에서 하위 항목들을 관리하기 용이하게 만듭니다.");

		mar(14, "어떤 파일을 읽으려고 할 때마다 디렉토리가 매 번 디스크를 샅샅이 뒤지는 것은 비효율적이겠죠? 이러한 일을 방지하고자 링크로 연결하여 관리의 편의성을 높이는 것입니다.");

		mar(16, "두 번째로는 비슷한 맥락이지만 파일과 파일 사이의 링크를 형성하여 서로 다른 디렉토리의 파일 간의 값의 참조를 편리하게 하고자 할 때 사용합니다.");

		mar(18, "예를 들어 /dir1/subdir1/sub_subdir1/에 있는 파일 a와 /dir2/subdir2/sub_subdir2/에 있는 파일 b의 상호작용이 활발하다고 가정하겠습니다.");

		mar(20, "그렇다면 두 파일을 사용 할 때마다 계속 경로를 길게 불러주는 것은 비효율적일 것입니다.");

		mar(22, "따라서 두 파일 사이에 링크를 이어서 훨씬 더 간결하게 상호작용을 할 수 있도록 도와줍니다.");

		mar(24, "링크는 크게 두 가지가 있습니다. 아래에 정리해놓겠습니다.");

		mar(26, "①  하드 링크");

		mar(28, "  하드 링크를 두 파일 사이에 만들 경우 두 파일은 동일한 inode 번호를 가지게 됩니다.");

		mar(30, "  이는 메모리 상에서 동일한 저장 공간을 공유하는 것을 의미합니다.");

		mar(32, "  따라서 파일 내용의 변경이 일어날 경우 다른 파일의 내용도 똑같이 변하게 됩니다.");

		mar(34, "  하드 링크는 두 파일 중 하나의 삭제가 발생하여도 다른 파일의 내용은 그대로 유지됩니다. 즉, 하나의 파일이 실수로 지워져도 다른 파일이 내용을 가지고 있는 것이지요."); 

		mar(36, "  단, 하드 링크는 한계점이 하나 있습니다. 다른 파일 시스템과는 하드 링크를 형성할 수 없습니다.");

		mar(38, "  이를 보완하고자 등장한 것이 심볼릭 링크 입니다.");	   

		mar(40, "②  심볼릭 링크");

		mar(42, "  심볼릭 링크는 하드 링크와는 다르게 두 파일이 서로 다른 inode 번호를 가지게 됩니다.");

		mar(44, "  심볼릭 링크는 타깃이 되는 파일의 주소 값을 다른 공간에 저장하고 있기 때문입니다.");

		mar(46, "  따라서, 타깃이 되는 파일이 삭제가 될 경우 심볼릭 링크는 값을 읽어올 공간이 사라지게 되고 하드 링크와는 다르게 파일 내용을 유지하지 못합니다.");
	
		mar(48, "  즉, 원본 파일이 삭제가 될 경우 의미가 없는 파일이 되는 것이지요.");
	
		mar(50, "  단, 심볼릭 링크는 다른 파일 시스템과의 링크도 형성할 수 있어 하드 링크가 제어하지 못하는 부분에서 활용되고 있습니다.");

		mar(54, "Enter to Continue (0: 종료)");	
		getnstr(&c, 1);
		if(c == '0') {break;}
		
		clear();
		mar(0, "5. 기타");
		
		sleep(1);

		mar(2, "두 가지에 대해서만 마지막으로 정리하고 개념 정리를 마무리하려고 합니다.");

		mar(4, "우선 이전의 장에서 디렉토리의 구조에 대해서 파악해보았습니다.");

		mar(6, "inode가 100번인 파일 x와 inode가 200번인 디렉토리 D가 있다고 가정하겠습니다.");

		mar(8, "x가 D 내부에 존재한다는 것은 정확하게,");

		mar(10, "x라고 불리는 100번 inode와 D라고 불리는 200번 inode 사이에 링크가 존재함을 의미합니다.");

		mar(12, "파일 이름이 우선이 아닌 inode 가 주체임을 이해하시면 좋을 것 같습니다.");

		mar(14, "그리고 루트 디렉토리에서 '.' 과 '..'은 동일한 inode를 가지고 있습니다.");

		mar(16, "C언어로 pwd를 구현할 때 이 점을 활용하니 인지하고 계시면 좋을 것 같습니다.");

		mar(20, "Enter to end");
		
		getnstr(&c, 1);
		clear();	
		break;		
	}

	endwin();
}


void chap4_command()
{
	initscr();

        while(1)
        {
                clear();
                refresh();

                char c;

                mar(0, "챕터 4의 C언어 함수를 살펴봅니다.");

                sleep(1);

                mar(2, "1. mkdir");

                mar(4, "2. rmdir");

                mar(6, "3. unlink");

                mar(8, "4. link");

                mar(10, "5. rename");

                mar(12, "6. chdir");

                mar(14, "0. 종료");

                mar(16, "번호를 입력해주세요 : ");

                getnstr(&c, 1);

                switch(c)
                {
                        case '1':
                                clear();
                                mar(0, "1. mkdir 함수 정리 (make directory)");
				sleep(1);

                                mar(2, "헤더 파일 : <sys/types.h> <sys/stat.h>");
                                mar(4, "용도 : 새로운 디렉토리를 만들 때 사용");
                                mar(6, "사용 방법 : int mkdir(char* pathname, mode_t mode)");
               			mar(7, "pathname : 새로운 디렉토리의 이름, mode : 디렉토리 권한");
				mar(8, "디렉토리 권한 설정 방법은 파일 생성할 때의 방법과 똑같음");
	                	mar(10, "예시) mkdir('my_dir', 764)");
				mar(12, "실패 시 -1 반환, 성공 시 0 반환");
				mar(14, "참고로, 디렉토리 생성이 성공하면 자동적으로 .(dot)과 ..(dotdot)을 설치하여 현재 디렉토리와 상위 디렉토리의 정보를 저장함");	
                               	 
				mar(18, "Enter to end");
                                getnstr(&c, 1);
                                break;

                        case '2':
                                clear();
                                mar(0, "2. rmdir 함수 정리 (remove directory)");
				sleep(1);

                                mar(2, "헤더 파일 : <unistd.h>");
                                mar(4, "용도 : 비어 있는 디렉토리를 삭제하기 위해서 사용");
				mar(6, "사용 방법 : int rmdir(const char* path)");
				mar(8, "예시) rmdir('./my_dir')");
				mar(10, "실패 시 -1 반환, 성공 시 0 반환");
				mar(12, "디렉토리를 삭제하게 되면 부모 디렉토리와의 링크가 해제가 됨. 링크 수가 0이 되면 데이터 블록에서 free 된다.");
				mar(14, "디렉토리의 기본 세트인 .(dot)과 ..(dotdot)을 제외하고는 어떠한 내용물도 가지고 있어서는 안됨. 즉, 비어 있는 상태여야 함.");
				mar(18, "Enter to end");
                                getnstr(&c, 1);
                                break;


			case '3':
                                clear();
                                mar(0, "3. unlink 함수 정리");
				sleep(1);

				mar(2, "헤더 파일 : <unistd.h>");
				mar(4, "용도 : 디렉토리 내부의 디렉토리가 아닌 entry를 제외하는데 사용 (파일, 소스 코드 등)");
				mar(6, "사용 방법 : int unlink(const char* path)");
				mar(8, "예시 : unlink('./old_file.txt')");
				mar(10, "실패 시 -1 반환, 성공 시 0 반환");
                               	mar(12, "unlink는 삭제하고자 하는 파일과 현재 디렉토리 사이의 연결을 해제하여 link 수를 하나 줄이는 것임");
				mar(14, "이 때, 해당 파일의 링크가 0이 될 경우, 데이터 블록에서도 해당 파일을 해제하게 됨. 즉, 모든 내용 free");
				mar(18, "Enter to end");
                                getnstr(&c, 1);
                                break;

                        case '4':      
                                clear();
                                mar(0, "4. link 함수 정리");
				sleep(1);

                                mar(2, "헤더 파일 : <unistd.h>");
                                mar(4, "용도 : 파일 간의 새로운 링크를 생성하기 위해 사용 (디렉토리에는 사용 불가)");
				mar(6, "사용 방법 : int link(const char* orig, const char* new)");
				mar(8, "예시) link('./origianl.txt', './new.txt')");
				mar(10, "해당 함수는 하드 링크를 형성하는 함수이기 때문에 다른 파일 시스템과는 사용 불가");
				mar(12, "심볼릭 링크를 형성하기 위해서는 symlink 함수를 사용해야 한다.");
				mar(14, "실패 시 -1 반환, 성공 시 0 반환");
                                mar(18, "Enter to end");
                                getnstr(&c, 1);
                                break;

                        case '5':
                                clear();
                                mar(0, "5. rename 함수 정리");
				sleep(1);

                                mar(2, "헤더 파일 : <unistd.h>");
                                mar(4, "용도 : 파일의 이름 변경, 파일 위치 이동, 디렉토리의 이름 변경에 활용");
				mar(6, "사용 방법 : int rename(const char* from, const char* to");
				mar(8, "예시 1) rename('before', 'after') : before 파일의 이름을 after로 변경");
				mar(9, "예시 2) rename('before', 'my_dir/after') : before 파일을 my_dir로 위치를 옮기고 이름을 after로 변경");
				mar(11, "실패 시 -1 반환, 성공 시 0 반환");
				mar(13, "참고로, 디렉토리를 하부 디렉토리로 이동시키는 것은 불가능");
				mar(15, "잘못 사용한 예시) rename('./dir', ./dir/sub_dir') : 불가능!");
                                mar(19, "Enter to end");
                                getnstr(&c, 1);
                                break;

                        case '6':
                                clear();
                                mar(0, "6. chdir 함수 정리 (change directory)");
				sleep(1);

                                mar(2, "헤더 파일 : <unistd.h>");
				mar(4, "용도 : 프로세스가 가지고 있는 현재 위치 정보를 변경하기 위해서 사용. 즉, 다른 디렉토리로 이동하기 위해서 사용");
				mar(6, "사용 방법 : int chdir(const char* path)");
				mar(8, "사용 예시) chdir('..') : 상위 디렉토리로 이동");
				mar(10, "프로세스마다 현재 자신이 위치한 디렉토리 정보를 데이터로 가지고 있음. 해당 정보를 바꾸는 것임");
				mar(12, "실패 시 -1 반환, 성공 시 0 반환");
				mar(16, "Enter to end");
                                getnstr(&c, 1);
                                break;

                        case '0':
                                endwin();
                                return;

                        default:
                                mar(20, "올바른 형식으로 입력해주세요.");
                                usleep(1000 * 0.5);

		}
	}
}

void chap5()
{
        initscr();

        while(1)
        {
                clear();

                char choice;

                mar(0, "챕터 5의 학습을 시작합니다.");

                mar(2, "학습하실 항목을 선택해주세요.");

                sleep(1);

                mar(4, "1. 학습 주제 및 목표");

                mar(6, "2. 개념 학습");

                mar(8, "3. C언어 함수 정리");

                mar(10, "0. 종료");

                mar(12, "번호를 입력해주세요 : ");

                getnstr(&choice, 1);

                switch(choice)
                {
                        case '1':
                                endwin();
                                chap5_goal();
                                break;

                        case '2':
                                endwin();
                                chap5_concept();
                                break;

                        case '3':
                                endwin();
                                chap5_command();
                                break;

                        case '0':
                                endwin();
                                return ;

                        defalut:
                                mar(16, "올바른 형식으로 입력해주세요.");
                                usleep(1000 * 0.5);
                }
        }
}

void chap5_goal()
{
        initscr();
        char c;
        while(1)
        {
                clear();

                mar(0, "●  학습 주제 : stty란 무엇인가");

                mar(2, "●  학습 목표 : ");
		
		mar(4, "  1. Unix에서 디바이스가 구현된 방식을 이해하고 다룰 수 있다.");

		mar(6, "  2. 디바이스와 파일의 공통점과 차이점을 정확하게 이해할 수 있다.");

                mar(8, "  3. ★  터미널 드라이버의 특성을 공부하고 세팅 값을 조정할 수 있다. ★");

		mar(10, "  (3번은 시험에서 거의 항상 나올 정도로 중요한 부분이니 꼼꼼하게 공부하시는 것을 추천드립니다.");

                sleep(1);

                mar(14, " Enter to back to menu");

                getnstr(&c, 1);

                endwin();
                break;
        }
}

void chap5_concept()
{
        initscr();

         char c;

         while(1)
        {
                clear();
                mar(0, "1. Unix에서 디바이스의 구현");

                sleep(1);

		mar(2, "Unix에서 사운드 카드, 터미널, 마우스, 스피커 등의 디바이스들은 모두 파일 형태로 구현되어 있습니다.");

		mar(4, "여기서 파일이라고 하면 저희가 이전 단원까지 다루었던 일반적인 파일들을 의미합니다.");

		mar(6, "관례적으로, 디바이스와 관련된 파일들은 /dev 디렉토리에 저장되어 있습니다.");

		mar(8, "해당 디렉토리로 이동해보면 각 디바이스들은 파일처럼 이름, inode 번호, 소유자 ID, permission bit 등을 가지고 있음을 확인할 수 있습니다.");	

		mar(10, "저희가 이전까지 파일을 다루었을 때, open, read, write, lseek, close, stat 등의 system call 함수를 활용하였습니다.");

		mar(12, "디바이스 또한 파일의 형태로 구현되었기 때문에 대다수의 작업들을 동일하게 적용할 수 있습니다.");

		mar(14, "[※ 예외※ ]");
		mar(15, "마우스 디바이스는 특성 상 write 함수가 적용되지 않습니다.");
		mar(16, "터미널은 파일의 위치라는 개념이 존재하지 않기 때문에 lseek 함수가 적용되지 않습니다.");
		mar(18, "위의 예시처럼 일부 예외적인 경우도 있지만 디바이스의 특성과 연관지어 생각해보시면 쉽게 이해하고 예외적으로 처리하실 수 있을 것입니다."); 

		mar(20, "디바이스 파일은 크게 디바이스 드라이버 정보, 주 번호(major number), 부 번호(minor number)를 포함하고 있습니다.");

		mar(22, "디바이스 파일은 일반 파일과는 다르게 inode 번호가 호출이 될 경우 디스크가 아닌 각 디바이스 별로 구분된 드라이버의 통제를 받습니다.");

		mar(24, "드라이버 정보는 해당 디바이스의 관할소 같은 역할을 하는 드라이버에 대한 정보를 포함합니다.");

		mar(26, "주 번호와 부 번호는 디바이스의 소속을 나타낸다고 생각하시면 될 것 같습니다.");
	
		mar(28, "간단하게 말씀을 드리자면 주 번호는 디바이스의 종류를 구분해주는 번호이고, 부 번호는 같은 종류의 디바이스 내부에서 각각의 기기들을 구분해주는 번호입니다.");

		mar(30, "예를 들어, USB가 3의 주 번호를 가진다고 하겠습니다. 여기서 USB-A와 USB-B가 있다면,");
		
		mar(32, "두 개의 USB는 여러 개의 주 번호 중에서 3의 주 번호를 할당받게 되고 그 중에서 1번과 2번의 부 번호를 각각 부여받음으로써 서로를 구분짓게 됩니다.");

		mar(34, "초등학생들이 학년에 따라 나뉘고 거기서 몇 반인지에 따라서 교실을 나누어 쓰게 됩니다.");

		mar(36, "이러한 상황에 비유적으로 주 번호가 학년, 부 번호가 반을 나타낸다고 이해하셔도 편할 것 같습니다.");

		mar(38, "저희와 같은 학생의 입장에서는 크게 활용할 일이 없으니 이러한 개념이 있음을 인지하고만 계시면 될 것 같습니다.");

		mar(42, "Enter to Continue ( 0 : 종료 )");

                getnstr(&c, 1);
                if( c == '0') {break;}

                clear();
                mar(0, "★  2. 디스크 연결의 특성  ★");

		mar(2, "이번 장에서 다룰 내용들은 모두 2021-2학기 중간고사에 출제되었던 내용들입니다. 눈 여겨서 보시면 도움이 될 것입니다.");

		mar(4, "디스크에 연결된 파일들은 크게 2가지의 특성을 가지고 있습니다. Buffering과 Auto-Append Mode가 바로 그것입니다.");

		mar(6, "해당 특성들은 파일마다 내부에서 bit단위로 통제 변수(Control Variables)로 조정할 수 있습니다.");

		mar(8, "파일을 다루는 Unix 헤더파일인 fcntl.h를 활용해서 파일의 통제 변수들을 가져와서(1), 수정하고(2), 해당 값들을 반환(3)해주면 됩니다.");

		mar(10, "하나씩 살펴보겠습니다.");

		mar(12, "파일의 통제 변수는 주로 fcntl함수를 통해서 다루어집니다. 첫 번째인 buffering 특성에서는 O_SYNC 비트를 다루게 됩니다.");

		mar(14, "원래는 쓰기 작업을 수행할 때 버퍼에서 작성이 완료되면 쓰기를 담당하는 함수(write 등)는 종료되고 버퍼의 내용을 파일로 옮겨적게 됩니다.");

		mar(16, "하지만 O_SYNC 비트가 설정되면 버퍼의 내용이 파일로 모두 옮겨질 때까지 쓰기 함수는 종료되지 않습니다. 확실한 파일의 작성을 보장해주는 것이지요.");

		mar(18, "이러한 과정을 입출력 동기화라고 합니다. O_SYNC 비트는 입출력 동기화를 담당하는 비트인 것입니다.");

		mar(20, "입출력 동기화는 확실한 파일의 작성을 보장해 줄 수 있다는 장점이 있지만,");

		mar(22, "커널과 사용자 영역에서의 소모시간을 늘리고 메모리 잔류가 일어나며 버퍼의 실질적인 장점이 사라지게 됩니다.");

		mar(24, "따라서 전문가들은 입출력 동기화는 정말 최후의 보루로만 사용하라고 권고하고 있습니다.");
 
		mar(26, "두 번째로 살펴볼 특성은 Auto-Append Mode 입니다. 해당 모드는 여러 개의 프로그램이 한 번에 실행이 될 필요가 있을 때 유용한 모드입니다.");

		mar(28, "예를 들어, A와 B라는 기기에서 만 원이 있는 계좌에 접속하였고, 두 기기 모두 천 원을 출금하려고 합니다."); 

		mar(30, "그러면 다음과 같은 일이 발생할 수 있습니다.");	

		mar(32, "00시 1초) A기기 잔액 확인 (10,000원)");
		mar(33, "00시 2초) B기기 잔액 확인 (10,000원)");
		mar(34, "00시 3초) A기기 천 원 출금 이후 확인했던 잔액에서 천 원 차감 (9,000원)");
		mar(35, "00시 4초) B기기 춴 원 출금 이후 확인했던 잔액에서 천 원 차감 (9,000원)");
		mar(36, "00시 5초) 해당 계좌의 최종 금액 : 9,000원 ?? ");

		mar(38, "위의 예시에서 작업 수행의 순서가 엇갈려 예상하지 못한 결과값을 가지게 되었습니다. 이러한 문제를 Race-Condition이라고 합니다.");

		mar(40, "Auto-Append Mode는 이러한 문제들을 극복하고자 여러 프로세스를 하나로 묶어서 수행하게 합니다.");

		mar(42, "위의 사례를 예로 들자면 잔액 확인과 출금을 동시에 수행하도록 하여 사용자간, 디바이스 간의 어긋남이 발생하지 않도록 도와주는 것입니다.");

		mar(44, "이렇게 하나로 묶어주는 작업을 Atomic-operation이라고 합니다.");

		mar(46, "기말고사에서도 다루어 질 중요한 내용이니 꼭 이해하고 넘어가셨으면 좋겠습니다.");

		mar(50, "Enter to Continue ( 0 : 종료 )");

		getnstr(&c, 1);
		if( c == '0') {break;}

		clear();
		mar(0, "★  3. 터미널 연결의 특성  ★");

		mar(2, "터미널은 상대적으로 더 복잡하고 훨씬 많은 특성들에 의해서 통제가 발생합니다. 그 중 주로 다루어지는 것들을 위주로 이야기해보겠습니다.");

		mar(4, "터미널 드라이버의 속성을 보고 싶다면 $ stty 혹은 $ stty -all 과 같은 Unix 명령어로 확인할 수 있습니다.");

		mar(6, "또한, stty 뒤에 여러 옵션을 주어서 터미널 드라이버의 속성을 변경할 수 있습니다.");

		mar(8, "예시) $ stty -echo : 터미널의 echo 속성을 끈다");

		mar(10, "터미널 드라이버의 작업은 크게 4가지로 나누어집니다. Input, Output, Control Settings, Local의 4가지 입니다.");
	
		mar(12, "이 중 저희는 Local processing의 echo mode와 canonical 모드에 대해서 공부하게 됩니다.");

		mar(14, "하나씩 배워보도록 하겠습니다.");

		mar(16, "첫 번째로 echo mode는 무엇일까요? 바로 사용자의 입력을 화면에 보여줄 수 있도록 설정된 상태를 echo mode라고 합니다.");

		mar(18, "반대로, echo mode를 끄게 된다면 사용자가 아무리 입력을 하더라도 화면에는 보여지지 않게 됩니다.");

		mar(20, "저희가 Unix 터미널을 사용하는 일반적인 상태가 echo mode입니다. 그렇다면 non-echo-mode는 언제 활용될 수 있을까요?");

		mar(22, "하나의 예를 들자면 게임에서 활용될 수 있을 것입니다. 사용자가 입력하는 키를 굳이 보여주지 않아도 된다면 echo mode를 해제함으로써 구현할 수 있는 것입니다.");

		mar(24, "터미널 드라이버의 속성을 변경하는 과정은 디스크 연결에서의 과정과 비슷합니다.");

		mar(26, "터미널 드라이버에서 속성들을 받아오고(1), 사용자가 원하는 대로 변경을 한 이후에(2), 드라이버로 다시 돌려주면(3) 설정이 완료가 됩니다.");

		mar(28, "다른 점이 있다면 터미널 드라이버는 추가적으로 터미널 드라이버의 속성 변경 시점을 결정할 수 있습니다.");

		mar(30, "TCSANOW : 드라이버 속성을 즉시 변경함");

		mar(32, "TCSADRAIN : 대기 중인 출력은 모두 기달렸다가 드라이버 속성을 변경함");

		mar(34, "TCSAFLUSH : 대기 중인 출력을 모두 기달렸다가 출력이 완료되면 input 데이터를 싹 비우고 드라이버 속성을 변경함");

		mar(36, "두 번째로 공부하게 될 canonical mode는 6장에서 다루도록 하겠습니다.");

		mar(40, "Enter to Continue ( 0 : 종료 )"); 

		getnstr(&c, 1);
		if( c == '0') {break;}

		break;
	}
	endwin();
}

void chap5_command()
{
        initscr();

        while(1)
        {
                clear();
                refresh();

                char c;

                mar(0, "챕터 5의 C언어 함수를 살펴봅니다.");

                sleep(1);

                mar(2, "1. fcntl");

                mar(4, "2. tcgetattr");

                mar(6, "3. tcsetattr");

                mar(8, "4. ioctl");

                mar(10, "0. 종료");

                mar(12, "번호를 입력해주세요 : ");

                getnstr(&c, 1);

                switch(c)
                {
                        case '1':
                                clear();
                                mar(0, "1. fcntl 함수 정리 (file control)");
                                sleep(1);

				mar(2, "헤더 파일 : <fcntl.h> <unistd.h> <sys/types.h>");
				mar(4, "용도 : 파일 디스크립터를 다루고자 할 때 사용");
				mar(6, "사용 방법 : int result fcntl(int fd, int cmd) 혹은 int result fcntl(int fd, int cmd, long arg)");
				mar(7, "fd : 파일 디스크립터 번호");
				mar(8, "cmd : 수행할 작업 번호, 보통 F_GETFL 혹은 F_SETFL 를 인자로 넣어줌");
				mar(9, "arg : 파일 특성 변경 이후 변경된 특성을 해당 인자로 넣어줌");
				mar(11, "예시 1) s = fcntl(fd, F_GETFL) : 파일 특성을 담고 있는 bit를 s에 저장");
				mar(12, "예시 2) result = fcntl(fd, F_SETFL, s) : 변경한 파일 특성 s를 fd에 반영하고 해당 함수의 성공 여부를 result에 저장");
				mar(14, "실패 시 -1 반환, 성공 시 -1이 아닌 숫자를 반환");
				mar(18, "Enter to End");

                                getnstr(&c, 1);
                                break;

			case '2':
                                clear();
                                mar(0, "2. tcgetattr 함수 정리 (terminal control variables get attribute)");
                                sleep(1);
	
				mar(2, "헤더 파일 : <termios.h> <unistd.h>");
				mar(4, "용도 : 터미널 드라이버의 세팅 값들을 읽어오기 위해서 사용");
				mar(6, "사용 방법 : int result = tcgetattr(int fd, struct termios *info)");
				mar(7, "fd : 터미널 드라이버에 연결할 파일 디스크립터 번호");
				mar(8, "info : 해당 함수는 사용하기 전에 정보를 담아올 termios 구조체를 선언해주어야 한다. 선언이 완료되면 해당 구조체의 주소 값을 인자로 전달해주면 된다.");
				mar(10, "예시) struct termios info; int result; : termios 구조체로 info 선언, 결과 값 저장할 정수형 변수 result 선언");
				mar(11, "예시) result = tcgetattr(0, &info) : termios 구조체인 info를 활용하여 0번 파일 디스크립터에 터미널 연결, 성공 여부는 result에 저장");
				mar(13, "실패 시 -1 반환, 성공 시 0 반환");
				mar(17, "Enter to End");
                                
				getnstr(&c, 1);
                                break;


			case '3':
                                clear();
                                mar(0, "3. tcsetattr 함수 정리 (terminal control variables set attribute)");
                                sleep(1);

				mar(2, "헤더 파일 : <termios.h> <unistd.h>");
				mar(4, "용도 : 터미널 드라이버의 세팅 값들을 변경한 이후에 반영해주기 위해서 사용");
				mar(6, "사용 방법 : int result = tcsetattr(int fd, int when, struct termios* info)");
				mar(7, "fd : 터미널에 연결되어 있는 파일 디스크립터 번호");
				mar(8, "when : 터미널 변경 시점");
				mar(9, "  - TCSANOW : 드라이버의 설정 값을 즉시 변경");
				mar(10, "  - TCSADRAIN : 대기 중인 출력들은 기다려주었다가 드라이버의 설정 변경");
				mar(11, "  - TCSAFLUSH : 대기 중인 출력들은 기다려주었다가 출력이 완료되면 input 데이터를 싹 비우고 드라이버의 설정 변경");
				mar(12, "info : 터미널 구조체에 대한 주소값");
				mar(14, "예시) tcsetattr(0, TCSANOW, &info) : termios 구조체인 info와 0번 파일 디스크립터를 통해 연결된 드라이버의 설정을 즉시 변경");
				mar(16, "실패 시 -1 반환, 성공 시 0 반환");
				mar(20, "Enter to End");

                                mar(18, "Enter to end");
                                getnstr(&c, 1);
                                break;

			case '4':
                                clear();
                                mar(0, "4. ioctl 함수 정리");
                                sleep(1);

				mar(2, "헤더 파일 : <sys/ioctl.h>");
				mar(4, "용도 : 디바이스를 다루기 위해서 사용");
				mar(6, "사용 방법 : int result = ioctl(int fd, int operation, [, arg])");
				mar(7, "fd : 디바이스와 연결된 파일 디스크립터 번호");
				mar(8, "operation : 수행할 작업 번호");
				mar(9, "arg : 추가적인 옵션 정보");
				mar(11, "실패 시 -1 반환, 성공 시 -1이 아닌 다른 값을 반환");
				mar(15, "Enter to End");
                                
				getnstr(&c, 1);
                                break;

			 case '0':
                                endwin();
                                return;

       	                 default:
                                mar(20, "올바른 형식으로 입력해주세요.");
                                usleep(1000 * 0.5);
		}
	}
}

void chap6()
{
        initscr();

        while(1)
        {
                clear();

                char choice;

                mar(0, "챕터 6의 학습을 시작합니다.");

                mar(2, "학습하실 항목을 선택해주세요.");

                sleep(1);

                mar(4, "1. 학습 주제 및 목표");

                mar(6, "2. 개념 학습");

                mar(8, "3. C언어 함수 정리");

                mar(10, "0. 종료");

                mar(12, "번호를 입력해주세요 : ");

                getnstr(&choice, 1);

                switch(choice)
                {
                        case '1':
                                endwin();
                                chap6_goal();
                                break;

                        case '2':
                                endwin();
                                chap6_concept();
                                break;

                        case '3':
                                endwin();
                                chap6_command();
                                break;

                        case '0':
                                endwin();
                                return ;

                        defalut:
                                mar(16, "올바른 형식으로 입력해주세요.");
                                usleep(1000 * 0.5);
                }
        }
}

void chap6_goal()
{
        initscr();
        char c;
        while(1)
        {
                clear();

                mar(0, "●  학습 주제 : 터미널 드라이버의 모드와 시그널");

                mar(2, "●  학습 목표 : ");

                mar(4, "  1. ★  터미널 드라이버의 특성을 이해하고 변경할 수 있다 ★");
                
		mar(6, "  2. ★  Siganl 함수가 무엇인지 이해하고 handling하며 사용할 수 있다. ★");

                mar(8, "해당 단원은 시험에 항상 나올 정도로 중요하기 때문에 꼭 짚고 넘어가셔야 됩니다!!");

                sleep(1);

                mar(12, " Enter to back to menu");

                getnstr(&c, 1);

                endwin();
                break;
        }
}

void chap6_concept()
{
        initscr();

         char c;

         while(1)
        {
                clear();
                mar(0, "1. Software Tool과 Device-Specific Program의 차이");

                sleep(1);

		mar(2, "①  Software Tool :");
	
		mar(4, "  Software Tool은 표준 입력이나 파일들에서 값을 읽어오고 표준 출력 디스크립터나 표준 에러 출력 디스크립터로 출력을 하는 프로그램들을 일컫습니다.");

		mar(6, "  Unix에는 저희와 친근한 ls, who, sort, grep 등의 수백개의 Software Tool이 존재합니다.");

		mar(8, "  해당 도구들은 stdin(0번)이라고 하는 입력 창이나 파일로부터 값을 읽어들이고 stdout(1)이나 stderr(2)라고 하는 출력 창을 통해 값을 출력한다는 공통점이 있습니다.");

		mar(10, "  대다수의 프로세스들은 생성과 동시에 stdin, stdout, stderr의 3개의 파일 디스크립터를 할당받습니다.");

		mar(12, "  즉, 사용자들은 open 명렁어를 통해 파일 디스크립터를 따로 만들지 않고 해당 프로그램들을 사용할 수 있는 것이지요.");

		mar(14, "②  Device-Specific Program : ");

		mar(16, "  그에 반해, Device-Specific Program들은 특정 기기와 상호작용하는 데에 초점이 맞추어져 있습니다.");

		mar(18, "  예를 들어 음량 조절, 음소거 등의 프로그램이 있다면 사운드 디바이스와 상호작용하기 위해 만들어져있다고 볼 수 있는 것입니다.");

		mar(20, "  해당 프로그램들은 각 디바이스를 관할하는 드라이버에서 setting 정보를 필요에 따라 변경하며 작업을 수행합니다.");

		mar(22, "  여러 디바이스 중에서 이번 챕터에서는 터미널을 다루는 방법에 대해서 공부하게 될 것입니다.");

		mar(26, "참고로, Software Tool을 다룰 때 pipe라는 함수를 통해서 파일들간의 정보를 교류하고 입출력의 방향을 바꿀 수 있습니다.");

		mar(28, "자세한 내용은 기말고사 범위에서 다루어지니 참고하시면 될 것 같습니다.");

		mar(32, "Enter to Continue ( 0 : 종료 )");	

                getnstr(&c, 1);
                if( c == '0') {break;}
	
		clear();
		mar(0, "★  2. 터미널 설정 값 조정 ★");

		sleep(1);

		mar(2, "지난 챕터에서는 터미널의 local 설정 값 중 echo bit를 다루어봤습니다.");

		mar(4, "이번 챕터에서는 터미널 드라이버의 속성인 ICANON 비트와 파일 속성인 O_NDELAY 비트를 공부하겠습니다.");

		mar(6, "ICANON bit는 입출력 버퍼의 버퍼링과 편집 기능에 대해서 관할하는 비트입니다.");

		mar(8, "해당 비트를 어떻게 설정하느냐에 따라서 터미널의 모드가 크게 3가지로 나누어집니다.");

		mar(10, " ①  canonical mode ( cooked mode ) ");

		mar(12, "   버퍼링과 편집 기능이 모두 설정되어 있는 모드입니다. 글자 하나 혹은 단어를 지우는 작업이 가능합니다.");

		mar(14, " ②  noncanonical mode ( cr mode ) ");

		mar(16, "   버퍼링과 편집 기능이 모두 꺼져있는 모드입니다. 글자를 입력하는 순간 바로 출력되어 글자의 편집이 불가능 합니다.");

		mar(18, "   따라서, 글자를 지우는 것을 의미하는 백 스페이스바를 입력할 경우 하나의 글자로 인식되어 출력됩니다.");

		mar(20, " ③  non-anthing mode ( raw mode ) ");
	
		mar(22, "   모든 프로그램이 각각 비트 단위로 쪼개져 통제를 받고 작업을 수행하게 됩니다. 또한, 프로그램이 입력을 받을 경우 버퍼를 거치지 않고 바로 프로그램으로 전달됩니다.");

		mar(25, "프로그래머는 작성하고 있는 프로그램의 용도에 맞게 터미널의 속성을 설정하는 것이 중요합니다.");

		mar(28, "두 번째로 다루게 될 비트는 O_NDELAY 비트 입니다.");

		mar(30, "해당 비트는 터미널 속성이 아닌 파일 속성이며 설정 값에 따라 파일을 읽을 때의 방식이 크게 2가지로 나뉘게 됩니다.");

		mar(32, " ①  설정되어 있지 않은 경우 ");

		mar(34, "   저희가 기존에 사용하는 대로 사용자나 파일로부터 입력이 들어올 때까지 프로세스가 block된 상태로 기다립니다.");

		mar(36, " ②  설정되어 있는 경우");

		mar(38, "   해당 비트가 설정되어 있는 파일에서 입력을 받아들일 때 아무 값도 입력이 되지 않는 경우 기다리지 않고 0을 반환하며 종료합니다.");

		mar(42, "Enter to Continue ( 0 : 종료 ) ");

		getnstr(&c, 1);
		if( c == '0' ) {break;}

		clear();
		mar(0, "3. Signal");

		sleep(1);

		mar(2, "시그널이란 커널로부터 프로세스에게 전달되는 메시지라고 생각하면 됩니다.");

		mar(4, "해당 메시지를 통해서 프로세스는 특정 프로그램을 종료하거나 타이머를 설정하는 등의 작업을 수행할 수 있습니다.");

		mar(6, "반대로, 특정 시그널을 수행하지 않도록 무시하라는 메시지를 보낼 수도 있습니다.");

		mar(8, "그렇다면 시그널은 어떻게 발생이 되는 것일까요? 바로 사용자나 다른 프로세스 혹은 커널 스스로에게서 발생하게 됩니다.");

		mar(10, "위에서 설명한 것처럼 시그널이 발생하게 된다면 프로세스에서 처리하는 방식에 대해서 정의를 내려주어야 합니다.");

		mar(12, "이 때 시그널 처리를 담당하는 방식은 크게 3가지로 나뉘게 됩니다.");

		mar(14, " ①  SIG_DFL : signal을 그대로 수행");

		mar(16, " ②  SIG_IGN : signal을 무시");

		mar(18, " ③  함수 호출");

		mar(20, "   시그널 처리를 담당하는 함수를 signal_handling 함수라고 합니다. signal_handling 함수는 signal이 발생하였을 경우 수행할 작업에 대해서 정리되어 있어야 합니다.");

		mar(22, "   또한, signal 함수를 호출하기 전에 int형 인자를 전달받을 수 있도록 정의되어 있어야 합니다.");

		mar(26, "예시) void signal-handler(int); : signal-handling 함수 등록");
		
		mar(28, "예시) signal(SIGINT, signal-handler); : SIGINT signal이 발생하면 signal-handler라는 함수를 호출");

		mar(30, "예시) signal-handler 함수의 인자가 int 형으로 선언되어 있으므로 정상적으로 수행 (그렇지 않은 경우 오류 발생) ");

		mar(32, "signal과 signal_handler 함수는 프로세스가 사용자, 다른 프로세스, 커널과 의사소통을 할 수 있는 하나의 방식으로 굉장히 중요한 개념입니다.");

		mar(36, " Enter to Continue ( 0 : 종료 ) ");

		getnstr(&c, 1);
		if( c == '0' ) {break;}

		break;
	}
	endwin();
}

void chap6_command()
{
        initscr();

        while(1)
        {
                clear();
                refresh();

                char c;

                mar(0, "챕터 6의 C언어 함수를 살펴봅니다.");

                sleep(1);

                mar(2, "1. fflush");

                mar(4, "2. sleep");

                mar(6, "3. tolower");

                mar(8, "4. signal");

                mar(10, "0. 종료");

                mar(12, "번호를 입력해주세요 : ");

                getnstr(&c, 1);

                switch(c)
                {
                        case '1':
                                clear();
                                mar(0, "1. fflush 함수 정리");
                                sleep(1);

				mar(2, "헤더 파일 : <stdio.h>");
		
				mar(4, "용도 : 주로 버퍼의 내용을 비우거나 버퍼에서 머무르고 있는 문자를 빼내기 위해서 사용");

				mar(6, "예시) fflush(stdout) : 버퍼의 내용을 바로 stdout으로 출력한다.");

				mar(8, "사용자의 입출력을 다룰 경우 버퍼링은 자주 발생하는 문제입니다. 문자가 버퍼에서 머무르면서 출력이 되지 않는 것입니다.");

				mar(10, "이럴 경우 fflush를 통해서 버퍼의 내용을 비워줍니다.");

				mar(14, "Enter to End");

				getnstr(&c, 1);
				break;

                        case '2':
                                clear();
                                mar(0, "2. sleep 함수 정리");
                                sleep(1);

				mar(2, "헤더 파일 : <unistd.h>");

				mar(4, "용도 : 초 단위로 프로그램을 block 시키기 위해서 사용");

				mar(6, "사용 방법 : sleep(3); : 3초간 프로그램 정지");

				mar(8, "해당 함수와 비슷한 함수로 첫 문자가 대문자로 시작하는 Sleep함수가 있습니다.");

				mar(10, "Sleep 함수는 window 환경에서 사용되는 함수로 Unix나 Linux를 사용할 경우에는 소문자로 시작하는 sleep 함수를 사용합니다.");

				mar(12, "두 함수를 헷갈리지 않도록 조심합니다 !!");

				mar(16, "Enter to End");

                                getnstr(&c, 1);
                                break;

			case '3':
                                clear();
                                mar(0, "3. tolower 함수 정리");
                                sleep(1);

				mar(2, "헤더 파일 : <ctype.h>");
					
				mar(4, "용도 : 영어 알파벳을 소문자로 바꾸어주기 위해서 사용");

				mar(6, "사용 방법 : int result = tolower(int c)");

				mar(8, "c : 바꾸어 줄 문자의 아스키 코드 값");

				mar(10, "tolower 함수의 인자로 'A'와 같이 문자를 전달해주어도 됩니다. 그렇게 전달하여도 결과 값은 똑같이 'a'의 아스키 코드 번호가 반환이 됩니다.");

				mar(12, "다른 문자가 들어올 경우? 해당 문자를 그대로 반환합니다.");

				mar(14, "비슷한 함수로 toupper 함수가 있습니다. 해당 함수는 전달받은 알파벳의 대문자 아스키 코드 값을 반홥합니다.");

				mar(16, "예시) toupper('b') = B의 아스키 코드 값인 66 반환");

				mar(20, "Enter to End");

                                getnstr(&c, 1);
                                break;

			case '4':
				clear();
				mar(0, "4. signal 함수 정리");
				sleep(1);

				mar(2, "헤더 파일 : <signal.h> ");

				mar(4, "용도 : signal handling을 위해서 사용");

				mar(6, "사용 방법 : int result = signal( int signum, void (*action) (int))");

				mar(8, "signum : 시그널 번호. 보통 SIGINT, SIGQUIT 등의 상수로 인자를 전달");		
			
				mar(10, "action : 1. SIGDFL : signal을 그대로 처리, 2. SIGIGN : signal 무시, 3. int를 인자로 가지는 signal_handling 함수 : 함수 내용 수행");

				mar(12, "예시) signal(SIGINT, SIGDFL) : SIGINT번의 시그널이 발생하였을 경우 그대로 처리");

				mar(13, "예시) signal(10, SIGINT) : 10번의 시그널은 발생하여도 무시");

				mar(15, "실패 시 -1 반환, 성공 시 -1이 아닌 값을 반환");

				mar(19, "Enter to End");
	
				getnstr(&c, 1);
				break;

			case '0':
                                endwin();
                                return;

                         default:
                                mar(20, "올바른 형식으로 입력해주세요.");
                                usleep(1000 * 0.5);
                }
        }
}

#define message(row, msg) {move(row, 0); addstr(msg); refresh(); sleep(2);} 

void credit()
{
	initscr();

	char c;

	char msg1[400] = "정설영 교수님의 수업을 수강하였던 수학과 17학번 문경덕 입니다.";

	char msg2[400] = "시스템 프로그래밍 기말고사 프로젝트로 해당 프로그램을 만들어 보게 되었습니다.";

	char msg3[400] = "한 학기를 공부하면서 학부생 수준에서 필요하다고 생각되는 기본적인 내용들을 위주로 작성해두었습니다.";

	char msg4[400] = "최대한 간결하고 이해하기 쉬우면서 내용들은 알차게 구성하고자 하였으나 프로젝트를 제출할 때가 되어 돌아보니 부족한 부분이 많은 것 같습니다.";

	char msg5[400] = "핑계를 대보자면 길지 않은 기말 고사 기간 동안에 7개의 전공 과목을 병행하면서 개인적인 시간을 내기가 쉽지가 않았던 것 같습니다..";

	char msg6[400] = "그래도 최대한 중간고사의 중요 범위인 signal까지는 프로젝트 내용으로 담고자 노력하였습니다.";

	char msg7[400] = "향후 제 프로그램을 사용하게 될 분들께서는 '같은 컴퓨터의 길을 걷는 학생으로서 열심히 노력했구나'라고 생각해주셨으면 감사할 것 같습니다.";

	char msg8[400] = "전 Unix와 Linux에 관한 아무런 배경 지식도 가지고 있지 않은 채로 (정말 아무것도 모르는 상태로) 해당 수업을 수강하게 되었습니다.";

	char msg9[400] = "그럼에도 정설영 교수님의 시스템 프로그래밍 수업을 들으며 정말 많은 내용을 머릿 속에 집어 넣고 제 것으로 만들 수 있었습니다.";

	char msg10[400] = "그렇다면 컴퓨터를 전공하는 여러분들은 훨씬 더 해당 수업에 잘 적응할 수 있으리라 믿습니다.";

	char msg11[400] = "혹시나 저와 같은 비전공자 분들이라면 '나와 같은 수준에 있는, 혹은 나보다 못한 사람도 잘 배워서 나갔구나.'라고 자신감을 얻으시면 좋을 것 같습니다.";

	char msg12[400] = "모든 분들이 열심히 하셔서 해당 수업 내용을 본인의 것으로 만들고 좋은 성적을 가져가시길 기원하겠습니다. (^-^) ";

	char msg13[400] = "감사합니다~~!! ";

	message(0, "후기");
	message(2, msg1);
	message(4, msg2);
	message(6, msg3);
	message(8, msg4);
	message(10, msg5);
	message(12, msg6);
	message(14, msg7);
	message(16, msg8);
	message(18, msg9);
	message(20, msg10);
	message(22, msg11);
	message(24, msg12);
	message(26, msg13);
	message(30, "Enter to End");

	getnstr(&c, 1);
	endwin();
}





















