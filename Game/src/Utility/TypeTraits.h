#ifndef SPACESHIPBP_TYPETRAITS_H
#define SPACESHIPBP_TYPETRAITS_H

#include <functional>
#include <tuple>

namespace Traits
{
    namespace MemberPtr
    {
        namespace Internal
        {
            template<class T, class OuterT>
            struct MemberPtrImpl
            {
                MemberPtrImpl(T OuterT::*)
                { }

                using OwningStruct = OuterT;
                using ObjectT = T;
            };

            template<auto memberPtr>
            struct MemberPtr
            : public decltype(MemberPtrImpl(memberPtr))
            { };
        }

        template<auto memberPtr>
        using OwningStruct = typename Internal::MemberPtr<memberPtr>::OwningStruct;

        template<auto memberPtr>
        using ObjectT = typename Internal::MemberPtr<memberPtr>::ObjectT;
    }

    namespace Lambda
    {
        namespace Internal
        {
            // For converting visitor function to lambda correctly
            template<class Return, class... Params>
            struct InspectorImpl
            {
                InspectorImpl(std::template function<Return(Params...)>)
                { }

                using ReturnType = Return;
                using ParamTypes = std::tuple<Params...>;

                template<size_t i>
                using ArgType = typename std::tuple_element<i, ParamTypes>::type;
            };

            template <class Lambda>
            struct LambdaInspector
            : public decltype(InspectorImpl(std::function{ std::declval<Lambda>() }))
            { };
        }

        template <class LambdaT>
        using RetType = typename Internal::LambdaInspector<LambdaT>::ReturnType;

        template <class LambdaT, size_t i>
        using ArgType = typename Internal::LambdaInspector<LambdaT>::template ArgType<i>;
    }

}

#endif //SPACESHIPBP_TYPETRAITS_H
