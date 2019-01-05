#ifndef ADDER_HPP
#define ADDER_HPP

#include <utility>
#include <tuple>

#include "cpppid/utils/tuple_helper.hpp"

namespace cpppid {
    namespace composers {

        template <typename... Controllers>
        class adder {
            using ControllersCollection = std::tuple<Controllers...>;

            public:
                adder(Controllers... controllers)
                    : m_controllers{std::make_tuple(controllers...)} {}

                template <typename Error>
                auto operator()(Error const& current_error) {
                    decltype(std::get<0>(m_controllers)(current_error)) total_output{};

                    utils::each(m_controllers, [&total_output, &current_error](auto & ctrl) {
                        total_output += ctrl(current_error);
                    });

                    return total_output;
                }

            private:
                ControllersCollection m_controllers;
        };
    }
}

#endif
