#ifndef ADDER_HPP
#define ADDER_HPP

#include <type_traits>
#include <utility>
#include <tuple>

namespace cpppid::composers {

    template <typename TotalOutput = double, typename... Controllers>
    class adder {
        using ControllersCollection = std::tuple<Controllers...>;
        
        template <typename T>
        static constexpr bool is_expected_output = std::is_same_v<std::decay_t<T>, TotalOutput>;
        
        public:
            explicit adder(Controllers... controllers)
                : m_controllers{std::make_tuple(controllers...)} {}

            template <typename Error>
            auto operator()(Error const& current_error) {
                auto const total_output = std::apply([&current_error](auto &... ctrl) {return (ctrl(current_error) + ...);}, m_controllers);
                static_assert(is_expected_output<decltype(total_output)>, "type of the sum of outputs must be equal to TotalOutput");
                return total_output;
            }

        private:
            ControllersCollection m_controllers;
    };
}

#endif
