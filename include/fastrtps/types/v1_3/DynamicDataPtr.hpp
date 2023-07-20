// Copyright 2023 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef TYPES_1_3_DYNAMIC_DATA_PTR_HPP
#define TYPES_1_3_DYNAMIC_DATA_PTR_HPP

#include <fastrtps/types/v1_3/DynamicData.hpp>
#include <fastrtps/types/v1_3/DynamicDataFactory.hpp>

#include <initializer_list>
#include <type_traits>

namespace std
{

template<>
struct default_delete<eprosima::fastrtps::types::v1_3::DynamicData> {
    void operator()(const eprosima::fastrtps::types::v1_3::DynamicData* pA) const noexcept
    {
        auto& inst = eprosima::fastrtps::types::v1_3::DynamicDataFactory::get_instance();
        inst.delete_data(pA);
    }
};

template<>
class shared_ptr<const eprosima::fastrtps::types::v1_3::DynamicData>
    : public shared_ptr<const void>
{
public:

    using element_type = const eprosima::fastrtps::types::v1_3::DynamicData;
    using base = shared_ptr<const void>;

    using MemberId = eprosima::fastrtps::types::v1_3::MemberId;

    constexpr shared_ptr() = default;

    explicit shared_ptr(element_type* pA)
        : base(pA, default_delete<element_type>{}) {}

    template<class Deleter>
    shared_ptr(element_type* pA, Deleter d)
        : base(pA, d) {}

    shared_ptr(const shared_ptr& r) noexcept
        : base(r) {}

    shared_ptr(shared_ptr&& r) noexcept
        : base(move(r)) {}

    template< class Y >
    shared_ptr(const shared_ptr<Y>& r, element_type* ptr) noexcept
        : base(r, ptr) {}

    template <class T, typename enable_if<is_convertible<T*, element_type*>::value, int>::type = 0>
    explicit shared_ptr(const weak_ptr<T>& r)
        : base(r) {}

    shared_ptr& operator=(const shared_ptr& r) noexcept
    {
        return static_cast<shared_ptr&>(base::operator=(r));
    }

    shared_ptr& operator=(shared_ptr&& r) noexcept
    {
        return static_cast<shared_ptr&>(base::operator=(move(r)));
    }

    void reset() noexcept
    {
        base::reset();
    }

    void reset(element_type* pA)
    {
        base::reset(pA, default_delete<element_type>{});
    }

    template<class Deleter>
    void reset(element_type* pA, Deleter d)
    {
        base::reset(pA, d);
    }

    element_type* get() const noexcept
    {
        return static_cast<element_type*>(base::get());
    }

    element_type& operator*() const noexcept
    {
        return *get();
    }

    element_type* operator->() const noexcept
    {
        return get();
    }

    // ancillary extra methods

    // for stl collections
    template<typename C,
        typename T = typename C::value_type,
        typename = decltype(*std::declval<C>().data()),
        typename = typename std::enable_if<std::is_convertible<T, uint32_t>::value>::type>
    MemberId get_array_index(const C& pos) const noexcept
    {
        if(*this)
        {
            return get()->get_array_index(
                    pos.data(),
                    static_cast<uint32_t>(pos.size()));
        }

        return {};
    }

    //! for initializer lists arguments
    MemberId get_array_index(std::initializer_list<uint32_t> ini) const noexcept
    {
        std::vector<uint32_t> v(ini);
        return get_array_index(v);
    }

};

template<>
class shared_ptr<eprosima::fastrtps::types::v1_3::DynamicData>
    : public shared_ptr<const eprosima::fastrtps::types::v1_3::DynamicData>
{
    // Adapter because deleter methods are defined in the shared_ptr<const void> class
    template<typename Deleter>
    struct DeleterAdapter
    {
        Deleter d_;

        DeleterAdapter(Deleter d)
            : d_{d}
        {
        }

        void operator()(const void* p)
        {
            d_((eprosima::fastrtps::types::v1_3::DynamicData*)p);
        }
    };

public:

    using element_type = eprosima::fastrtps::types::v1_3::DynamicData;
    using base = shared_ptr<const eprosima::fastrtps::types::v1_3::DynamicData>;

    // deleter associated to loans
    struct LoanDeleter
    {
        eprosima::fastrtps::types::v1_3::DynamicData& lender_;

        LoanDeleter(eprosima::fastrtps::types::v1_3::DynamicData& lender)
            : lender_(lender)
        {
        }

        void operator()(eprosima::fastrtps::types::v1_3::DynamicData* p)
        {
            lender_.return_loaned_value(p);
        }
    };

    constexpr shared_ptr() = default;

    shared_ptr(const shared_ptr& r) noexcept
        : base(r) {}

    shared_ptr(shared_ptr&& r) noexcept
        : base(move(r)) {}

    explicit shared_ptr(element_type* pA)
        : base(pA) {}

    template<class Deleter>
    shared_ptr(element_type* pA, Deleter d)
        : base(pA, DeleterAdapter<Deleter>{d}) {}

    template< class Y >
    shared_ptr(const shared_ptr<Y>& r, element_type* ptr) noexcept
        : base(r, ptr) {}

    template <class T, typename enable_if<is_convertible<T*, element_type*>::value, int>::type = 0>
    explicit shared_ptr(const weak_ptr<T>& r)
        : base(r) {}

    using base::reset;

    template<class Deleter>
    void reset(element_type* pA, Deleter d)
    {
        base::reset(pA, DeleterAdapter<Deleter>{d});
    }

    shared_ptr& operator=(const shared_ptr& r) noexcept
    {
        return static_cast<shared_ptr&>(base::operator=(r));
    }

    shared_ptr& operator=(shared_ptr&& r) noexcept
    {
        return static_cast<shared_ptr&>(base::operator=(move(r)));
    }

    element_type* get() const noexcept
    {
        return const_cast<element_type*>(base::get());
    }

    element_type& operator*() const noexcept
    {
        return const_cast<element_type&>(*get());
    }

    element_type* operator->() const noexcept
    {
        return get();
    }

    // ancillary extra methods
    shared_ptr loan_value(MemberId id) noexcept
    {
        if (*this)
        {
            element_type* loan = get()->loan_value(id);
            if (nullptr != loan)
            {
                return { loan, LoanDeleter{*get()}};
            }
        }

        return {};
    }

};

template<>
class weak_ptr<const eprosima::fastrtps::types::v1_3::DynamicData>
    : public weak_ptr<const void>
{
public:

    using element_type = const eprosima::fastrtps::types::v1_3::DynamicData;
    using base = weak_ptr<const void>;

    constexpr weak_ptr() noexcept = default;

    weak_ptr(const weak_ptr& r) noexcept
        : base(r) {}

    weak_ptr(weak_ptr&& r) noexcept
        : base(move(r)) {}

    weak_ptr(const shared_ptr<element_type>& r) noexcept
        : base(r) {}

    weak_ptr& operator=(const weak_ptr& r) noexcept
    {
        base::operator=(r);
        return *this;
    }

    weak_ptr& operator=(weak_ptr&& r) noexcept
    {
        base::operator=(move(r));
        return *this;
    }

    shared_ptr<element_type> lock() const noexcept
    {
        return static_pointer_cast<element_type>(base::lock());
    }
};

template<>
class weak_ptr<eprosima::fastrtps::types::v1_3::DynamicData>
    : public weak_ptr<const eprosima::fastrtps::types::v1_3::DynamicData>
{
public:

    using element_type = eprosima::fastrtps::types::v1_3::DynamicData;
    using base = weak_ptr<const eprosima::fastrtps::types::v1_3::DynamicData>;

    constexpr weak_ptr() noexcept = default;

    weak_ptr(const weak_ptr& r) noexcept
        : base(r) {}

    weak_ptr(weak_ptr&& r) noexcept
        : base(move(r)) {}

    weak_ptr(const shared_ptr<element_type>& r) noexcept
        : base(r) {}

    weak_ptr& operator=(const weak_ptr& r) noexcept
    {
        base::operator=(r);
        return *this;
    }

    weak_ptr& operator=(weak_ptr&& r) noexcept
    {
        base::operator=(move(r));
        return *this;
    }

    shared_ptr<element_type> lock() const noexcept
    {
        return const_pointer_cast<element_type>(base::lock());
    }
};

} // std



#endif // TYPES_1_3_DYNAMIC_DATA_PTR_HPP
