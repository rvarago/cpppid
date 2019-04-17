#ifndef INTEGRAL_HPP
#define INTEGRAL_HPP

#include <utility>

namespace cpppid::controllers {

    template <typename Ki = double, typename TimeInterval = int, typename AccumulatedError = double>
    class integral {
        public:
            explicit integral(Ki factor, TimeInterval interval)
                : m_factor{std::move(factor)},
                    m_interval{std::move(interval)},
                    m_accumulatedError{AccumulatedError{}} {}

            template <typename Error>
            auto operator()(Error const& current_error) {
                m_accumulatedError += current_error;
                return m_factor * m_accumulatedError * m_interval;
            }

        private:
            Ki const m_factor;
            TimeInterval const m_interval;
            AccumulatedError m_accumulatedError;
    };
}

#endif