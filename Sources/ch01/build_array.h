#pragma once

#include <array>
#include <iostream>
#include <type_traits>
#include <utility>

// 0: 연습 모드 (직접 구현부 활성화)
// 1: 솔루션 모드 (모범 답안 및 상세 해설 활성화)
#define SOLVED 0

/**
 * @brief 가변 인자 기반 공통 타입 배열 생성
 * * [Note: Type Traits - std::common_type_t]
 * - 원형: typename std::common_type<Args...>::type (C++11)
 * - 축약: std::common_type_t<Args...> (C++14 이상 권장)
 * - 특징: 전달된 모든 Args...가 암시적으로 형변환 가능한 '최대 공통 타입'을 추론함.
 * * [Note: Type Alias - using]
 * - Using Directive: 네임스페이스 확장 (e.g., using namespace std;)
 * - Type Alias: 새로운 타입 별칭 생성 (e.g., using commonType = T;)
 * - 장점: typedef와 달리 템플릿 별칭(Template Alias)을 지원하며 가독성이 높음.
 */

#if SOLVED
// <editor-fold desc="모범 답안 및 상세 해설 보기">
template <typename... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
    using commonType = typename std::common_type<Args...>::type;

    // std::forward를 통해 Perfect Forwarding을 구현하여 불필요한 복사를 방지합니다.
    return {std::forward<commonType>((Args&&)args)...};
}
// </editor-fold>
#else
/**
 * [실습 목표: 가변 인자 템플릿을 활용한 커스텀 배열 생성기 구현]
 * 1. 가변 인자(Args&&... args) 정의
 * 2. std::common_type_t를 이용한 반환 타입 추론 (std::array 반환)
 * 3. std::forward를 이용한 Perfect Forwarding 구현
 */

/* 작성 시작 */

/* 작성 종료 */
#endif
