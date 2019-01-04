#ifndef TUPLE_HELPER_HPP
#define TUPLE_HELPER_HPP

#include <type_traits>
#include <tuple>

namespace cpppid {
    namespace utils {

        template <typename UnaryFunction, typename...Ts, std::size_t...Is>
        void each(std::tuple<Ts...> & tuple, UnaryFunction fn, std::index_sequence<Is...>){
            using expander = int[];
            (void)expander { 0, ((void)fn(std::get<Is>(tuple)), 0)... };
        }

        template<class UnaryFunction, class...Ts>
        void each(std::tuple<Ts...> & tuple, UnaryFunction fn){
            each(tuple, fn, std::make_index_sequence<sizeof...(Ts)>());
        }
    }
}

#endif