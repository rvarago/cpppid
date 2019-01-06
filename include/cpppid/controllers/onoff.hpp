#ifndef ONOFF_HPP
#define ONOFF_HPP

#include <utility>

namespace cpppid {
    namespace controllers {

        template <typename InputLimit, typename OutputLimit>
        struct boundary {
            InputLimit input;
            OutputLimit output;
        };

        template <typename InputLimit = double, typename OutputLimit = double>
        class onoff {
            public:
                explicit onoff(boundary<InputLimit, OutputLimit> lower, boundary<InputLimit, OutputLimit> upper)
                    : m_lower{std::move(lower)},
                      m_upper{std::move(upper)} {}

                template <typename Error>
                auto operator()(Error const& current_error) {
                    if (current_error < m_lower.input) {
                        return m_lower.output;
                    } else if (current_error > m_upper.input) {
                        return m_upper.output;
                    }
                    return static_cast<OutputLimit>(current_error);
                }

            private:
                boundary<InputLimit, OutputLimit> const m_lower;
                boundary<InputLimit, OutputLimit> const m_upper;
        };
    }
}

#endif