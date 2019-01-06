#ifndef DERIVATIVE_HPP
#define DERIVATIVE_HPP

#include <utility>

namespace cpppid {
    namespace controllers {

        template <typename Kd = double, typename TimeInterval = int, typename PreviousError = double>
        class derivative {
            public:
                explicit derivative(Kd factor, TimeInterval interval, PreviousError initial_error = PreviousError{})
                    : m_factor{std::move(factor)},
                      m_interval{std::move(interval)},
                      m_previousError{std::move(initial_error)} {}

                template <typename Error>
                auto operator()(Error const& current_error) {
                    auto const delta_error = current_error - m_previousError;
                    m_previousError = current_error;
                    return m_factor * delta_error / m_interval;
                }

            private:
                Kd const m_factor;
                TimeInterval const m_interval;
                PreviousError m_previousError;
        };
    }
}

#endif