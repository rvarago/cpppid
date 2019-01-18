#ifndef ADDER_HPP
#define ADDER_HPP

#include <utility>
#include <tuple>

namespace cpppid {
    namespace composers {

        template <typename TotalOutput = double, typename... Controllers>
        class adder {
            using ControllersCollection = std::tuple<Controllers...>;

            public:
                explicit adder(Controllers... controllers)
                    : m_controllers{std::make_tuple(controllers...)} {}

                template <typename Error>
                auto operator()(Error const& current_error) {
                    return std::apply([&current_error](auto &... ctrl) {
                        return (static_cast<TotalOutput>(ctrl(current_error)) + ...);
                    }, m_controllers);
                }

            private:
                ControllersCollection m_controllers;
        };
    }
}

#endif
