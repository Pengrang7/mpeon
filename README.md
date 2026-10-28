# MPEON OBU IPC Prototype

리눅스 기반 OBU(On-Board Unit) 환경에서 LED, 온도, GPS 기능과 프로세스 간 통신을 실험한 C/C++ 프로젝트입니다.

## 주요 내용

- System V Message Queue를 이용한 송신·수신 프로세스 통신
- POSIX Thread 기반 입력 및 수신 처리
- LED 패턴, 온도 센서, GPS 기능 모듈화
- CMake 기반 다중 디렉터리 빌드 구성
- 단일 프로세스 예제(`complete_without_mq`)와 IPC 예제(`end_sue`) 분리

## 기술 스택

- C / C++
- Linux, POSIX Thread, System V IPC
- CMake
- GPSD 및 대상 장비용 GPIO·센서 인터페이스

## 디렉터리

```text
complete_without_mq/  메시지 큐를 사용하지 않는 통합 예제
end_sue/se/           명령 송신 프로세스
end_sue/re/           명령 수신 및 장치 제어 프로세스
```

## 빌드 예시

```bash
cmake -S end_sue/se -B build/se
cmake --build build/se

cmake -S end_sue/re -B build/re
cmake --build build/re
```

## 실행 환경

본 코드는 일반 PC용 완성 애플리케이션이 아니라 OBU 장비 연동을 위한 실습·프로토타입입니다. 실제 실행에는 Linux, 대상 장치 드라이버, GPSD와 센서/GPIO 환경이 필요합니다. 외부 문서 링크는 [LINK.md](LINK.md)에 정리되어 있습니다.
