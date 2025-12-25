#pragma once
#include <array>
#include <iostream>
#include <type_traits>

/**
 * [실습 목표: 가변 인자 템플릿을 활용한 커스텀 배열 생성기 구현]
 * * 1. 가변 인자(Args&&... args)를 받아 모든 인자를 포함하는 std::array를 반환합니다.
 * 2. std::common_type을 활용하여 서로 다른 타입(ex: int, double)이 섞여도
 * 공통으로 변환 가능한 최적의 타입을 자동으로 추론합니다.
 * 3. std::forward를 사용하여 전달받은 인자의 값 카테고리(L-value/R-value)를 보존하며 생성합니다.
 */

template <typename... Args>
auto build_array(Args&&... args) -> std::array<std::common_type_t<Args...>, sizeof...(args)>
{
    /*
     * Note: C++11 이후부터 using은 단순한 '선언'을 넘어 **'Type Alias(타입 별칭)'**라는 강력한 기능을 수행
     * A. Using Directive (네임스페이스 열기)
     * - e.g. using namespace std;
     * B. Type Alias (타입 별칭)
     * - e.g. using commonType = typename std::common_type<Args...>::type;
     * - e.g. using commonType = std::common_type_t<Args...>;
     * - c++ 11 이전: typedef std::common_type_t<Args...> commonType;
     */
    using commonType = std::common_type_t<Args...>;
    return {std::forward<commonType>((Args&&)args)...};
}
