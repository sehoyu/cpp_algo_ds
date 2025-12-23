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
    this->n = n;
    data = new T[n];
    // ? data = new T(n); 뭐가 다르지?
    // ! data = new T(n);
  }

  // 2. 복사 생성자: 깊은 복사(Deep Copy) 구현
  dynamic_array(const dynamic_array<T>& other) {
    // TODO: other의 크기를 복사하고 새로운 메모리 할당 후 내용 복사
    n = other.size();
    // ? data = new T[n]; 초기화 안 하고 값을 할당하면 무슨 일이?
    for (int i = 0; i < n; i++) {
      data[i] = other[i];
    }
  }

  // 3. 첨자 연산자 (L-value / R-value)
  T& operator[](int index) {
    // TODO: 해당 인덱스의 데이터 참조 반환
    // ? 왜 인덱스 범위 검사를 안 하지?
    return data[index];
  }

  const T& operator[](int index) const {
    // TODO: 상수 객체를 위한 참조 반환
    return data[index];
  }

  // 4. 범위 체크가 포함된 접근 함수
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
    // TODO: 두 배열의 크기를 합친 결과 객체 생성 후 std::copy 등으로 데이터 복사
    dynamic_array<T> result(arr1.size() + arr2.size());
    // ! dynamic_array<T> result = new dynamic_array<T, arr1.size() + arr2.size()>;
    std::copy(arr1.begin(), arr1.end(), result.begin());
    std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());
    // ! std::copy(arr2.begin(), arr2.end(), result + arr1.size());

    return result;
  }

  // 8. 출력을 위한 문자열 변환 함수
  std::string to_string(const std::string& sep = ", ") {
    // TODO: ostringstream을 사용하여 원소들을 sep으로 구분해 결합
    // ! 배열 길이 체크
    if (n == 0) {
      return "";
    }

    std::ostringstream os; // ! 선언문
    os << data[0];
    for (int i = 1; i < n; i++) {
      os << sep << data[i];
    }

    return os.str(); // ! str함수 호출
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
  // ? 굳이 왜 괄호를?
  return (os << "[" << s.name << ", " << s.standard << "]");;
}

int main()
{
	int nStudents;
	std::cout << "1반 학생 수를 입력하세요: ";
	std::cin >> nStudents;

	dynamic_array<student> class1(nStudents);
	for (int i = 0; i < nStudents; i++)
	{
		std::string name;
		int standard;
		std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
		std::cin >> name >> standard;
		class1[i] = student{name, standard};
	}

	// 배열 크기보다 큰 인덱스의 학생에 접근
	try
	{
		// 아래 주석을 해제하면 프로그램이 비정상 종료합니다.
		// class1[nStudents] = student {"John", 8}; // 예상할 수 없는 동작

		class1.at(nStudents) = student{"John", 8}; // 예외 발생
	}
	catch (...)
	{
		std::cout << "예외 발생!" << std::endl;
	}

	// 깊은 복사
	auto class2 = class1;
	std::cout << "1반을 복사하여 2반 생성: " << class2.to_string() << std::endl;

	// 두 학급을 합쳐서 새로운 큰 학급을 생성
	auto class3 = class1 + class2;
	std::cout << "1반과 2반을 합쳐 3반 생성 : " << class3.to_string() << std::endl;

	return 0;
}