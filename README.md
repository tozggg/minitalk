# minitalk
[subject](https://github.com/tozggg/minitalk/blob/master/subject.pdf)  
클라이언트와 서버의 통신 프로그램  
(인줄 알았지만 프로세스끼리의 시그널 전송 프로그램)
<br>
<br>
## Details
### server

- 서버가 먼저 실행
- 실행시 PID 출력?
- 서버의 PID에 맞는 클라이언트가 전송한 문자열을 출력

### client

- 실행시 서버의 PID와 전송할 문자열을 매개변수로 프로그램에 준다

### !

- 반드시 UNIX signal 통신으로만 사용
- 문자열 통신-출력 속도 주의
- 서버에서 연속으로 통신받을수 있게
- SIGUSR1 / SIGUSR2 만 사용

---

```c
// 사용가능함수

#include <unistd.h>
#include <stdlib.h>

write
malloc
free
exit

//------------------------------------------------------------

시그널?
=> 소프트웨어 인터럽트
=> 프로세스에 뭔가 발생했음을 간단한 메세지를 통해 비동기적으로 보내는것
ex)
- 예외적인 상황
- 인터럽트키 입력(ctrl + c)
- kill과 같은 함수를 사용해서 다른 프로세스에게 시그널 보내기

#include <signal.h>

// 시그널 보내기
int kill(pid, sig);
=> pid의 프로세스에 시그널보내기
=> 음수면(-1 제외) 그룹, 0이면 현재그룹

// 시그널 핸들러 관련 함수
// (보통은 시그널보내서 프로세스 종료, but 시그널보내서 해야할거 있을때)
void signal(sig, disp);
=> sig라는 시그널 받았을때 disp(함수)
+
void sigaction(signo, act, oact)
=> signo라는 시그널 받았을때 act라는 sigaction구조체에 따라 행동
=> oact는 이전 구조체 (NULL이어도 상관x)

// 시그널집합 관련 함수
// 시그널집합은 시그널들의 묶음 -> sigset_t구조체에서 비트마스크로 설정됬는지 표현 
int sigemptyset(set);
=> set을 빈 시그널집합으로 만들기
+
int sigaddset(set, signo);
=> set시그널집합에 signo시그널 추가

// 사용자 정의 시그널
SIGUSR1
SIGUSR2

//------------------------------------------------------------

#include <sys/types.h>
=> 타입들 (t_) 헤더

//------------------------------------------------------------

#include <unistd.h>

// 실행중인 프로세스ID 구하기
pid_t getpid(void);

// 시그널을 받을때까지 잠수 
int pause(void);

// 프로세스 지연 함수
sleep(int sec);
usleep(int micro_sec);

```

### ?

- SIGUSR1과 SIGUSR2는 정해진값을 임의로 내가 보내는걸로 인식하는거지?
    
    ⇒ o
    
- types.h에 SIGUSR1과 SIGUSR2 포함임? 아니면 어떤 t_쓰려고 이거 include?
    
    ⇒ SIGUSR1 과 SIGUSR2는 signal.h에 정의 
    
    ⇒ sys/types.h에서 쓸것 없음!
    
- 시그널 집합의 모양?
    
    ⇒ 위에 써놨음
    
- signal함수 써야되나 sigaction함수 써야되나? 그리고 어떻게 써야되나?
    
    ⇒ signal 함수와 sigaction 함수의 차이
    
    1. signal 함수 사용시 시그널을 블록하지 않음
        
        시그널 처리(=핸들러) 도중 다른 시그널 처리시 핸들러를 리셋할 가능성 ( 경쟁느낌 )
        
        sigaction 함수는 블록(lock)해서 시그널 처리가 끝난후 다음 시그널을 처리
        
    2. sigaction 함수의 다양한 기능
        
        예를들어 flag를 SA_SIGINFO로 설정시 강화된 핸들러에서 시그널의 많은 정보를 활용
        
- sigaction구조체 에서 건드려야 될것 (핸들러)
    
    ⇒ handler     기본 핸들러
    
    ⇒ sigaction  핸들러의 파라미터에 siginfo가 포함된 강화된 핸들러
    
    ⇒ sa_mask   블록할 시그널 지정 (시그널집합으로)
    
    ⇒ sa_flag     추가적인 기능 사용하기 
    

### 예외처리

- 서버는 종료하지 않을시 항시 돌아갈수있게
- 아주 큰 문자열 통신시 시간이 평가기준에 맞나 확인
- pid의 유효범위에 대한 예외처리
- 둘 이상의 client가 동시에 server에 메세지 보낼시 작동 확인
- pid 에 해당하는 서버가 없을때 / 서버에서 응답을 받지 못하는 상황 예외처리
- 메세지 무결성 테스트?

### 궁금한점

- sigaction mask에 핸들러만 써서 block하는 의미가 있나?
- sigaction 구조체 클러스터랑 형식 비교

---

signal함수와 usleep(100)으로 간단구현, 보내고 받는데에서는 비트shift연산과 pow함수 응용

m1 맥북에서 signal이 씹히는 현상 발생. gucamole에서는 현상 일어나지않음.
