#include <algorithm>
#include <iostream>
#include <sstream>

template <typename T>
class dynamic_array {
  T* data;
  size_t n;

public:
  // 1. 기본 생성자: 매개변수로 받은 크기만큼 메모리 할당
  dynamic_array(int n) {
    // TODO: n 초기화 및 data에 T 타입 배열 동적 할당
   
  }

  // 2. 복사 생성자: 깊은 복사(Deep Copy) 구현
  dynamic_array(const dynamic_array<T>& other) {
    // TODO: other의 크기를 복사하고 새로운 메모리 할당 후 내용 복사
   
  }

  // 3. 첨자 연산자 (L-value / R-value)
  T& operator[](int index) {
    // TODO: 해당 인덱스의 데이터 참조 반환
   
  }

  const T& operator[](int index) const {
    // TODO: 상수 객체를 위한 참조 반환
    
  }

  // 4. 범위 체크가 포함된 접근 함수
  T& at(int index) {
    // TODO: index가 n보다 작으면 반환, 아니면 예외 처리
    
  }

  size_t size() const {
    // TODO: 배열의 크기 반환
    return n;
  }

  // 5. 소멸자: 메모리 누수 방지
  ~dynamic_array() {
    // TODO: 동적 할당된 배열 해제
    
  }

  // 6. 반복자 (Iterator) 지원
  T* begin() {  }
  const T* begin() const {  }
  T* end() {  }
  const T* end() const { }

  // 7. 두 배열을 합치는 + 연산자 오버로딩 (Friend)
  friend dynamic_array<T> operator+(const dynamic_array<T>& arr1,
                                    const dynamic_array<T>& arr2) {
    // TODO: 두 배열의 크기를 합친 결과 객체 생성 후 std::copy 등으로 데이터

  }

  // 8. 출력을 위한 문자열 변환 함수
  std::string to_string(const std::string& sep = ", ") {
    // TODO: ostringstream을 사용하여 원소들을 sep으로 구분해 결합
    
  }
};

// 테스트를 위한 구조체
struct student {
  std::string name;
  int standard;
};

// student 구조체를 위한 출력 연산자 오버로딩
std::ostream& operator<<(std::ostream& os, const student& s) {
  // TODO: [이름, 학년] 형식으로 스트림에 삽입
  
}

int main() {

  return 0;
}