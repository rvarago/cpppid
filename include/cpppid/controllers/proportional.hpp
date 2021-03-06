#ifndef PROPORTIONAL_HPP
#define PROPORTIONAL_HPP

#include <utility>

namespace cpppid::controllers {

    template <typename Kp = double>
    class proportional {
        public:
            explicit proportional(Kp factor) : m_factor{std::move(factor)} {}

            template <typename Error>
            auto operator()(Error const& current_error) {
                return m_factor * current_error;
            }

        private:
            Kp const m_factor;
    };
}

#endif