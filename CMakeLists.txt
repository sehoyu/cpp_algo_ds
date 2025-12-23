# 1. CMake 최소 버전 설정 (최신 기능 사용을 위해 3.10 이상 권장)
cmake_minimum_required(VERSION 3.10)

# 2. 프로젝트 이름 및 언어 설정
project(cpp_algo_ds LANGUAGES CXX)

# 3. C++ 표준 설정 (언리얼 엔진 및 최신 알고리즘 트렌드에 맞춰 17 또는 20 권장)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. 실행 파일 생성
# 'main_exec'는 실행 파일 이름, 'main.cpp'는 소스 파일입니다.
# --- My Practice ---
add_executable(main main.cpp)

if (MSVC)
    # 윈도우 MSVC 컴파일러에게 소스코드가 UTF-8임을 명시
    add_compile_options(/utf-8)
endif ()
