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
auto build_array(Args&&... args)
    -> std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
  // NOTE: std::common_type<Args...>::type을 사용하여 모든 Args가 호환되는 공통 타입을 정의하세요.

  // TODO: 초기화 리스트와 std::forward를 사용하여 인자들을 std::array 형태로 반환하세요.
  // Tip: 가변 인자 팩 확장을 위해 '...' 연산자를 적절한 위치에 사용해야 합니다.
}
