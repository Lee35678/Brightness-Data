# Brightness-Data

ESP32 ADC로 밝기 센서 값을 0.5초마다 읽어 시리얼로 출력하는 PlatformIO 예제

## 개요

아날로그 밝기 센서의 전압을 ESP32의 ADC로 읽고, 그 값을 시리얼 모니터에 한 줄씩 출력합니다. 주변 밝기에 따라 센서 값이 어느 범위에서 어떻게 변하는지 확인하는 용도로, 같은 센서 핀(GPIO 15)을 쓰는 Brightness_Controlled_Relay, Low_Pass_Filter 프로젝트의 기초가 됩니다. 작성 시기는 2024년 9월입니다(커밋 기록 기준).

## 하드웨어

- 보드: DOIT ESP32 DevKit V1 (`board = esp32doit-devkit-v1`)
- 입력: 아날로그 출력형 밝기 센서 1개

| 신호 | GPIO | 설정 |
|------|------|------|
| 밝기 센서 출력 | 15 | `analogRead(15)` |

## 동작 방식

1. `setup()`: 시리얼을 115200 bps로 엽니다.
2. `loop()`: 500 ms마다 다음을 반복합니다.
   - `analogRead(15)`로 ADC 값을 읽습니다(ESP32 Arduino 기본 설정에서 12비트, 0~4095).
   - 읽은 값을 `Serial.println()`으로 출력합니다.

## 개발 환경

| 항목 | 값 |
|------|----|
| 도구 | PlatformIO |
| 플랫폼 | `espressif32` |
| 프레임워크 | `arduino` |
| 외부 라이브러리 | 없음 |
| 모니터 설정 | `monitor_speed = 115200`, `monitor_filters = log2plot`, `monitor_plot = time,brightness` |

## 빌드 및 업로드

```bash
pio run -t upload
pio device monitor
```

모니터 속도는 `platformio.ini`의 `monitor_speed = 115200`이 자동으로 적용됩니다.

## 폴더 구조

```
Brightness-Data/
├── platformio.ini
└── src/
    └── main.cpp
```

## 참고

- `platformio.ini`가 `log2plot` 모니터 필터를 지정하지만, 이 필터는 PlatformIO 기본 필터가 아니고 필터 스크립트(`monitor/` 폴더 등)도 저장소에 들어 있지 않습니다. 필터가 없는 환경에서 `pio device monitor`가 오류를 내면 `monitor_filters`, `monitor_plot` 두 줄을 지우고 사용하면 됩니다.
