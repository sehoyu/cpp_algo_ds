#include <algorithm>
#include <iostream>
#include <sstream>

template <typename T>
class dynamic_array {
  T* data; // T 타입 포인터 = 배열 이름 = 상수 포인터 = 다른 주소 할당 x
  size_t n;

public:
  // 1. 기본 생성자: 매개변수로 받은 크기만큼 메모리 할당
  dynamic_array(int n) {
    // TODO: n 초기화 및 data에 T 타입 배열 동적 할당
    this->n = n;
    data = new T[n];
  }

  // 2. 복사 생성자: 깊은 복사(Deep Copy) 구현
  dynamic_array(const dynamic_array<T>& other) {
    // TODO: other의 크기를 복사하고 새로운 메모리 할당 후 내용 복사
    this->n = other.size();
    data = new T[n]; // c++ '배열'은 공간 할당 후에 각 공간에 값을 할당
    for (int i = 0; i < n; ++i) {
      data[i] = other[i];
    }
  }

  // 3. 첨자 연산자 (L-value / R-value)
  T& operator[](int index) {
    // TODO: 해당 인덱스의 데이터 참조 반환
    /*
     * NOTE: 왜 인덱스 검사를 안 할까?
     * C++의 Zero-overhead 철학: 성능 최적화를 위해(e.g. 반복문) 호출자에게
     * 책임을 위임함. 필요하다면 assert()를 사용해 디버그 모드에서만 검사하는
     * 것이 관례.
     */
    return data[index];
  }

  const T& operator[](int index) const {
    // TODO: 상수 객체를 위한 참조 반환
    return data[index];
  }

  // 4. 범위 체크가 포함된 접근 함수
  // NOTE: 왜 인덱스 검사를 할까? []연산자 같은 최적화를 요구하지 않기 때문에
  T& at(int index) {
    // TODO: index가 n보다 작으면 반환, 아니면 예외 처리
    if (index < n) {
      return data[index];
    }

    throw "Index out of range";
  }

  size_t size() const {
    // TODO: 배열의 크기 반환
    return n;
  }

  // 5. 소멸자: 메모리 누수 방지
  ~dynamic_array() {
    // TODO: 동적 할당된 배열 해제
    delete[] data;
  }

  // 6. 반복자 (Iterator) 지원
  T* begin() { return data; }
  const T* begin() const { return data; }
  T* end() { return data + n; }
  const T* end() const { return data + n; }

  // 7. 두 배열을 합치는 + 연산자 오버로딩 (Friend)
  friend dynamic_array<T> operator+(const dynamic_array<T>& arr1,
                                    const dynamic_array<T>& arr2) {
    // TODO: 두 배열의 크기를 합친 결과 객체 생성 후 std::copy 등으로 데이터
    dynamic_array<T> result(arr1.size() + arr2.size());

    /* --- Error Case Recovery ---
     * FIXME: 아래 방식은 result 객체 자체를 넘기려 했으나,
     * std::copy는 '어디서부터 채울지' 주소값이 필요함.
     * std::copy(arr1.begin(), arr2.end(), result);
     * 정답: .begin()으로 시작 위치를 지정해야 함.
     * std::copy(arr1.begin(), arr1.end(), result.begin());
     */
    std::copy(arr1.begin(), arr1.end(), result);
    std::copy(arr2.begin(), arr2.end(), result + arr1.size());

    return result;
  }

  // 8. 출력을 위한 문자열 변환 함수
  std::string to_string(const std::string& sep = ", ") {
    // TODO: std::ostringstream을 사용하여 원소들을 sep으로 구분해 결합
    if (n == 0) {
      return "";
    }

    std::ostringstream os;
    os << data[0];

    for (int i = 1; i < n; ++i) {
      os << sep << data[i];
    }

    return os.str();
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
  os << s.name << s.standard;
  return os;
}

int main() { return 0; }
