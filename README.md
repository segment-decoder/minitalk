# Minitalk

본 프로젝트는 UNIX 시그널(`SIGUSR1`, `SIGUSR2`)만을 사용하여 클라이언트가 서버에게 문자열을 전송하는 통신 프로그램을 구현하는 것을 목표로 합니다.

## Description

Minitalk은 소켓이나 파이프 같은 별도의 통신 수단 없이, 오직 **UNIX 시그널**만으로 클라이언트와 서버 간에 문자열을 주고받는 프로젝트입니다.

- 서버는 실행되면 자신의 PID를 출력하고, 클라이언트로부터 시그널을 통해 도착하는 비트를 하나씩 조립하여 문자열로 복원한 뒤 화면에 출력합니다.
- 클라이언트는 서버의 PID와 전송할 문자열을 인자로 받아, 문자열을 한 바이트씩 8개의 비트로 쪼갠 뒤 `SIGUSR1`(비트 0), `SIGUSR2`(비트 1)로 인코딩하여 순서대로 전송합니다.
- 서버는 재시작 없이 여러 클라이언트로부터 연속해서 메시지를 받을 수 있습니다.

### Detail

- 너무 빠른 전송으로 인한 오류를 방지하기 위해 usleep() 함수를 사용해 비트마다 전송 지연시간을 설정했습니다.
```
# define SEND_DELAY 400
```
- 1 바이트가 완성되지 못한 채 완결되는 것을 방지하기 위해 일정 시간 이후 버퍼를 비우는 로직을 추가하였습니다.
```
# define BYTE_TIMEOUT 10000
```
- 서버 측에서 `SIGUSR1`과 `SIGUSR2`를 동시에 받아 오류가 나는 것을 방지하기 위해 sigaction()을 응용한 함수를 사용했습니다.
```
static void	ft_init_sig(void (*handler)(int))
```

### Bonus

- **ACK 기반 신뢰성 및 전송 속도 확보**: 서버는 비트 하나를 수신할 때마다 클라이언트에게 확인 시그널(ACK)을 보내고, 클라이언트는 일정 시간 안에 ACK가 오지 않으면 동일한 비트를 재전송합니다 (Stop-and-Wait 방식). 앞서 사용한 `SEND_DELAY`는 삭제하였고, ACK를 기다리는 시간만이 소요되어 전송 속도가 획기적으로 상승하였습니다.
- **유니코드(UTF-8) 지원**: 비트/바이트 처리를 전부 `unsigned char` 기반으로 구현하여, ASCII뿐 아니라 한글을 포함한 UTF-8 멀티바이트 문자도 손상 없이 전송됩니다.

## Instructions

### Compile
```bash
make          # mandatory 버전 (client, server) 빌드
make bonus    # bonus 버전 (ACK + 유니코드 지원) 빌드
make clean    # 오브젝트 파일 삭제
make fclean   # 오브젝트 파일 + 실행 파일 삭제
make re       # fclean 후 mandatory 버전 재빌드
```

### Launch
먼저 서버를 실행해 PID를 확인합니다.
```
./server
# 출력 예:
Server is now running.
PID: 1234567
```
다른 터미널에서 클라이언트를 실행해 메시지를 전송합니다.
```
./client <server_PID> "보낼 메시지"
# 입력 예:
./client 1234567 "Hello, world!"
```
서버 쪽 터미널에 전송한 메시지가 출력됩니다.

## Resources

### References

- Linux man (3) page
- https://reakwon.tistory.com/46
- https://hihinote.tistory.com/68

### AI Usage

프로젝트 설계와 디버깅 과정에서 Claude(Anthropic)를 다음과 같은 용도로 활용했습니다. 모든 코드는 직접 작성했으며, AI는 개념 설명과 코드 리뷰 용도로만 사용했습니다.

- 개념 학습: UNIX 시그널의 전달 메커니즘, pause()/sigaction()의 정확한 동작, 시그널 마스크(sa_mask)의 역할, feature test macro(_POSIX_C_SOURCE, _DEFAULT_SOURCE)의 의미와 필요성 등을 질의응답 형식으로 학습했습니다.
- 설계 검토: ACK 기반 재전송 프로토콜을 설계하는 과정에서, "완벽한 ACK는 존재할 수 없다"는 이론적 한계(두 장군 문제)와 실제 절충안(타임아웃 기반 재전송), 비트 단위 vs 바이트 단위 ACK의 트레이드오프에 대해 논의했습니다.
- 코드 리뷰: 매 개발 단계마다 작성한 코드를 AI에게 검토받아 다음과 같은 버그를 스스로 찾고 수정했습니다 — PID 미검증으로 인한 kill(-1, ...) 오발신 위험, 시그널 핸들러 재진입으로 인한 데이터 경합, 클라이언트의 인덱스 이중 증가 버그, 컴파일 에러(void 함수의 잘못된 return), 클라이언트 하나의 연결 실패가 서버 전체를 종료시키는 문제 등.
