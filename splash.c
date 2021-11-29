// 수학과 2017115475 문경덕
#include <stdio.h>
#include <ncurses.h>  // cureses 함수들 사용하기 위해서
#include <locale.h>  // setlocale, LC_ALL
#include <unistd.h>  // sleep, usleep

void menu();  // menu 선택 화면
void background();  // 만들게 된 배경
void study();
void chap2();
void chap2_concept();
void chap2_goal();

int main()
{
	setlocale(LC_ALL, "ko_KR.utf8");  // curses 함수에서 한글과 특수문자를 출력하기 위해 utf8 설정으로 바꾸어줌

	// cureses 함수 사용
	initscr();
	clear();

	for(int time = 0 ; time < 5;time++)
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
	
	getch();
	endwin();

	// 메뉴 선택 화면
	menu();	

	return 0;	
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
		addstr("3. 참고 자료");	
		usleep(1000 * 700);
		refresh();
		
		move(8, 0);
		addstr("4. 크레딧");	
		usleep(1000 * 700);
		refresh();
		
		move(10, 0);
		addstr("0. 종료");	
		usleep(1000 * 700);
		refresh();

		move(12, 0);
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
	
			case '4':

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

#define mars(row, msg) {move(row, 0); addstr(msg); refresh(); sleep(7); }
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

	mars(24, "초심자 분들께도 도움을 드릴 수 있을 것이라고 생각하였습니다.");

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

		mar(2, "학습에 도움을 받은 챕터를 선택해주세요.");

		sleep(1);

		mar(4, "1. chap 1_OT");

		mar(6, "2. chap 2_who");

		mar(8, "3. chap 3_ls");

		mar(10, "4. chap 4_pwd");

		mar(12, "5. chap 5_stty");

		mar(14, "6. chap 6_signal");

		mar(16, "7. chap 7_event-driven");

		mar(18, "0. back to menu");

		mar(20, "번호를 입력해주세요 : ");

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

			case '4':

			case '5':

			case '6':

			case '7':

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

		mar(8, "3. 명령어 및 함수 정리");

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
}
















