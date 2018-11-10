#ifndef STRVEC_H
#define STRVEC_H

#include <memory>
#include <string>
#include <utility>
#include <algorithm>
#include <initializer_list>

namespace test
{
    class c_strvec
    {
    public:
        using iterator = std::string *;
        using const_iterator = std::string *;
        c_strvec() = default;
        c_strvec(const std::initializer_list<std::string> &i_l);
        c_strvec(const c_strvec &);
        c_strvec(c_strvec &&) noexcept;
        ~c_strvec() { free(); }
        size_t size() const { return end_of_elements - elements; }
        size_t  capacity() const { return end_container - elements; }
        iterator begin() { return elements; }
        iterator end() { return end_of_elements; }
        const_iterator begin() const { return elements; }
        const_iterator end() const { return end_of_elements; }
        void push_back(const std::string &);
        void push_back(std::string &&);
        //扩充空间
        void reserve(size_t new_size) { if (new_size > capacity()) realloc(new_size); }
        void resize(size_t, const std::string &t);
        void resize(size_t n) {  resize(n, std::string{}); }
        c_strvec &operator=(c_strvec);
        std::string &operator[](size_t);
        friend void swap(c_strvec &, c_strvec &) noexcept;

    private:
        std::allocator<std::string> alloc;	//内存分配器

        //将区间数据保存到另一个区间
        std::pair<std::string *, std::string *> copy_n_alloc
        (const std::string *, const std::string *);
        //释放容器资源
        void free();
        void free(std::nullptr_t);
        void chk_n_alloc()	//容量满则再分配空间
        {
            if (capacity() == size())
            {
                realloc();
            }
        }
        void realloc(size_t new_size = 1);
        std::string *elements{ nullptr };		//第一个元素
        std::string *end_of_elements{ nullptr };	//尾后元素
        std::string *end_container{ nullptr };	//容器尾部
    };

    std::pair<std::string *, std::string *> c_strvec::copy_n_alloc
    (const std::string *b, const std::string *e)
    {
        auto data = alloc.allocate(e - b);
        return { data, std::uninitialized_copy(b, e, data) };
    }

    void c_strvec::free()
    {
        if (nullptr != elements)
        {	//若容器不为空
            for (auto p = end_of_elements; p != elements;)
            {	//释放区间中所有元素
                alloc.destroy(--p);
            }
            alloc.deallocate(elements, end_container - elements);
        }
    }

    void c_strvec::free(std::nullptr_t)	//单纯激活重载
    {
        if (nullptr != elements)
        {	//若容器不为空
            std::for_each(begin(), end(), [&](std::string &p) { alloc.destroy(&p); });
            alloc.deallocate(elements, end_container - elements);
        }
    }
    void c_strvec::realloc(size_t new_size)
    {
        size_t newSize = new_size > capacity() ? new_size : capacity() * 2;
        auto newData = alloc.allocate(newSize);	//分配新空间
        //在新空间中构造元素
        decltype(elements) new_end_elements;
        //使用移动迭代器在解引用时返回右值 从而调用元素的移动构造函数进行构造
        new_end_elements = std::uninitialized_copy(std::make_move_iterator(begin
        ()), std::make_move_iterator(end()), newData);
        free();	//释放原资源
        elements = newData;
        end_of_elements = new_end_elements;
        end_container = elements + newSize;
    }

    c_strvec::c_strvec(const c_strvec &c_s)
    {
        auto new_alloc = copy_n_alloc(c_s.elements, c_s.end_of_elements);
        elements = new_alloc.first;
        end_of_elements = new_alloc.second;
        end_container = new_alloc.second;
    }

    inline
    void swap(c_strvec &c_s1, c_strvec &c_s2) noexcept
    {
        //交换句柄
        using std::swap;
        swap(c_s1.elements, c_s2.elements);
        swap(c_s1.end_of_elements, c_s2.end_of_elements);
        swap(c_s1.end_container, c_s2.end_container);
    }

    c_strvec &c_strvec::operator=(c_strvec c_s)
    {
        swap(*this, c_s);
        return *this;
    }

    void c_strvec::resize(size_t n, const std::string &t)
    {
        if (n > size())
        {	//若新num大于当前num则将剩余空间构造
            for (auto p = elements + n; end_of_elements != p;)
            {
                alloc.construct(end_of_elements++, t);
            }
        }
        else if (n < size())
        {	//若新num小于当前num
            for (auto p = elements + n; end_of_elements != p;)
            {
                alloc.destroy(--end_of_elements);
            }
        }
    }

    c_strvec::c_strvec(const std::initializer_list<std::string> &i_l)
    {
        auto data = copy_n_alloc(i_l.begin(), i_l.end());
        elements = data.first;
        end_of_elements = end_container = data.second;
    }

    inline
    void c_strvec::push_back(const std::string &str)
    {
        chk_n_alloc();	//判断容量是否足够
        alloc.construct(end_of_elements++, str);
    }

    inline
    void c_strvec::push_back(std::string &&str)
    {
        chk_n_alloc();	//判断容量是否足够
        alloc.construct(end_of_elements++, std::move(str));
    }

    c_strvec::c_strvec(c_strvec &&c_s) noexcept
    {
        swap(*this, c_s);
    }

    bool operator==(const c_strvec &c_s1, const c_strvec &c_s2)
    {
        if (c_s1.size() != c_s2.size())
        {       //
           return false;
        }
        for (auto p1 = c_s1.begin(), p2 = c_s2.begin();
             p1 != c_s1.end() && p2 != c_s2.end(); ++p1, ++p2)
        {
            if (*p1 != *p2)
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const c_strvec &c_s1, const c_strvec &c_s2)
    {
        return !(c_s1 == c_s2);
    }

    std::string &c_strvec::operator[](size_t n)
    {
        return *(elements + n);
    }
}
#endif // STRVEC_H
