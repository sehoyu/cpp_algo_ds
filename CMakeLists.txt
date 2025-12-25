# 1. CMake 최소 버전 설정 (최신 기능 사용을 위해 3.10 이상 권장)
cmake_minimum_required(VERSION 3.10)

# 2. 프로젝트 이름 및 언어 설정
project(cpp_algo_ds LANGUAGES CXX)

# 3. C++ 표준 설정 (언리얼 엔진 및 최신 알고리즘 트렌드에 맞춰 17 또는 20 권장)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. 실행 파일 생성
# 'main_exec'는 실행 파일 이름, 'main.cpp'는 소스 파일입니다.
# 헤더 파일은 실행 파일 생성 대상(add_executable)에 넣지 않아도 됩니다.
# 하지만 IDE(CLion)에서 인덱싱이 잘 되게 하려면 포함하는 것이 좋습니다.
# headers 폴더 내의 모든 .h 파일을 찾아서 HEADER_FILES 변수에 저장
file(GLOB_RECURSE HEADER_FILES "exercises/*.h")
add_executable(main
        main.cpp
        ${HEADER_FILES} # 찾은 파일들을 자동으로 포함
)
# headers 폴더를 포함 경로에 추가 (include "파일명.h" 만으로 호출 가능하게 함)
target_include_directories(main PUBLIC Book Exercises Sources)
#헤더 파일을 개별적으로 추가할 때
#add_executable(main_exec
#        main.cpp
#        headers/ch01/dynamic_array_exercise.h # 구현체 헤더의 실제 경로를 정확히 명시
#        # 앞으로 추가될 파일들도 여기에 나열
#)

if (MSVC)
    # 윈도우 MSVC 컴파일러에게 소스코드가 UTF-8임을 명시
    add_compile_options(/utf-8)
endif ()
